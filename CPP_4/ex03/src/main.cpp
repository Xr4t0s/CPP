#include <iostream>
#include "materias/Ice.hpp"
#include "materias/Cure.hpp"
#include "character/Character.hpp"
#include "sources/MateriaSource.hpp"

/* ================= COLORS ================= */
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"

#define LOG(color, msg) std::cout << color << msg << RESET << std::endl;
/* ========================================== */

static void safeFloorDrop(AMateria** floor, int& floorCount, int cap, AMateria* m)
{
    if (!m) return;
    if (floorCount >= cap)
    {
        // if floor is full, we delete to avoid leaks in tests
        // (the subject lets you handle "floor" as you like)
        delete m;
        return;
    }
    floor[floorCount++] = m;
}

int main()
{
    /* ========= FLOOR MANAGEMENT ========= */
    const int FLOOR_CAP = 200;
    AMateria* floor[FLOOR_CAP];
    int floorCount = 0;
    for (int i = 0; i < FLOOR_CAP; i++) floor[i] = NULL;

    /* ========================================================= */

    LOG(CYAN, "\n========== SCENARIO 0: SUBJECT MAIN (MUST WORK) ==========");

    IMateriaSource* src0 = new MateriaSource();
	Ice* tmpIce = new Ice();
	Cure* tmpCure = new Cure();
    src0->learnMateria(tmpIce);
    src0->learnMateria(tmpCure);

	delete tmpIce;
	delete tmpCure;

    ICharacter* me0 = new Character("me");
    AMateria* tmp0;

    tmp0 = src0->createMateria("ice");
    me0->equip(tmp0);
    tmp0 = src0->createMateria("cure");
    me0->equip(tmp0);

    ICharacter* bob0 = new Character("bob");
    me0->use(0, *bob0);
    me0->use(1, *bob0);

    delete bob0;
    delete me0;
    delete src0;

    /* ========================================================= */

    LOG(CYAN, "\n========== SCENARIO 1: LEARN LIMIT + TEMPLATE OWNERSHIP ==========");

    MateriaSource* src = new MateriaSource();

    // Learn 4 templates (max). 5th should do nothing.
    AMateria* t1 = new Ice();
    AMateria* t2 = new Cure();
    AMateria* t3 = new Ice();
    AMateria* t4 = new Cure();
    AMateria* t5 = new Ice(); // should be ignored by learnMateria if full

    src->learnMateria(t1);
    src->learnMateria(t2);
    src->learnMateria(t3);
    src->learnMateria(t4);
    src->learnMateria(t5);

    // IMPORTANT:
    // learnMateria COPIES (clones) the passed materia per subject,
    // so main can delete the originals safely.
    delete t1; delete t2; delete t3; delete t4; delete t5;

    // Unknown type must return NULL/0
    AMateria* u = src->createMateria("fire");
    if (!u) { LOG(YELLOW, "createMateria(\"fire\") returned NULL (OK)"); }
    else { LOG(RED, "ERROR: createMateria(\"fire\") should be NULL"); delete u; }

    /* ========================================================= */

    LOG(CYAN, "\n========== SCENARIO 2: EQUIP ORDER + FULL INVENTORY ==========");

    Character* hero = new Character("Hero");

    // create 6 materias from src
    AMateria* m1 = src->createMateria("ice");
    AMateria* m2 = src->createMateria("cure");
    AMateria* m3 = src->createMateria("ice");
    AMateria* m4 = src->createMateria("cure");
    AMateria* m5 = src->createMateria("ice");  // will overflow inventory
    AMateria* m6 = src->createMateria("cure"); // will overflow inventory

    // equip 4 -> fills slots 0..3
    hero->equip(m1);
    hero->equip(m2);
    hero->equip(m3);
    hero->equip(m4);

    // try to equip when full: MUST NOT change inventory.
    // BUT then m5/m6 would leak if we don't handle them here.
    hero->equip(m5);
    hero->equip(m6);

    // Put overflow materias on the floor to avoid leaks during tests
    // (since equip should "do nothing", caller keeps ownership)
    safeFloorDrop(floor, floorCount, FLOOR_CAP, m5);
    safeFloorDrop(floor, floorCount, FLOOR_CAP, m6);

    // use all valid slots + invalid indexes
    hero->use(0, *hero);
    hero->use(1, *hero);
    hero->use(2, *hero);
    hero->use(3, *hero);
    hero->use(-1, *hero); // must do nothing
    hero->use(4, *hero);  // must do nothing

    /* ========================================================= */

    LOG(CYAN, "\n========== SCENARIO 3: UNEQUIP RULES + RE-EQUIP ==========");

    // unequip must NOT delete
    // we take ownership back in main (floor)
    safeFloorDrop(floor, floorCount, FLOOR_CAP, m2);
    hero->unequip(1);

    safeFloorDrop(floor, floorCount, FLOOR_CAP, m4);
    hero->unequip(3);

    // using unequipped slots should do nothing
    hero->use(1, *hero);
    hero->use(3, *hero);

    // re-equip should fill first empty slot (1 then 3)
    AMateria* x1 = src->createMateria("cure");
    AMateria* x2 = src->createMateria("ice");
    hero->equip(x1); // goes to slot 1
    hero->equip(x2); // goes to slot 3

    hero->use(1, *hero);
    hero->use(3, *hero);

    // invalid unequip should do nothing
    hero->unequip(-1);
    hero->unequip(4);

    /* ========================================================= */

    LOG(CYAN, "\n========== SCENARIO 4: DEEP COPY CHARACTER (COPY CTOR) ==========");

    Character copyHero(*hero);

    // Destroy original hero -> copy must still be valid and independent
    LOG(GREEN, "Deleting original hero (copy must survive)");
    delete hero;

    copyHero.use(0, copyHero);
    copyHero.use(1, copyHero);
    copyHero.use(2, copyHero);
    copyHero.use(3, copyHero);

    /* ========================================================= */

    LOG(CYAN, "\n========== SCENARIO 5: DEEP COPY CHARACTER (ASSIGNMENT) ==========");

    Character 	assignHero("AssignHero");
    assignHero = copyHero;

    assignHero.use(0, assignHero);
    assignHero.use(1, assignHero);

    // self-assignment must not break anything
    // assignHero = assignHero;
    assignHero.use(0, assignHero);

    /* ========================================================= */

    LOG(CYAN, "\n========== SCENARIO 6: DEEP COPY MATERIASOURCE ==========");

    MateriaSource srcCopy(*src);
    MateriaSource srcAssign;
    srcAssign = *src;

    // delete src and prove copies still create materias
    LOG(GREEN, "Deleting original MateriaSource (copies must still work)");
    delete src;

    AMateria* z1 = srcCopy.createMateria("ice");
    AMateria* z2 = srcAssign.createMateria("cure");
    AMateria* z3 = srcCopy.createMateria("cure");
    AMateria* z4 = srcAssign.createMateria("ice");

    Character tester("Tester");
    tester.equip(z1);
    tester.equip(z2);
    tester.equip(z3);
    tester.equip(z4);

    tester.use(0, tester);
    tester.use(1, tester);
    tester.use(2, tester);
    tester.use(3, tester);

    /* ========================================================= */

    LOG(CYAN, "\n========== SCENARIO 7: STRESS / MANY OBJECTS ==========");

    // Create/destroy lots of characters and materias to catch leaks/crashes
    for (int round = 0; round < 25; round++)
    {
        Character tmp("tmp");
        AMateria* a = srcCopy.createMateria("ice");
        AMateria* b = srcAssign.createMateria("cure");
        AMateria* c = srcCopy.createMateria("ice");
        AMateria* d = srcAssign.createMateria("cure");

        tmp.equip(a);
        tmp.equip(b);
        tmp.equip(c);
        tmp.equip(d);

        tmp.use(0, tmp);
        tmp.use(1, tmp);

        // unequip two -> must not delete; we manage
        safeFloorDrop(floor, floorCount, FLOOR_CAP, c);
        tmp.unequip(2);
        safeFloorDrop(floor, floorCount, FLOOR_CAP, d);
        tmp.unequip(3);

        // use after unequip -> nothing
        tmp.use(2, tmp);
        tmp.use(3, tmp);
        // tmp destroyed here -> deletes only what remains equipped (a,b)
    }

    /* ========================================================= */

    LOG(CYAN, "\n========== CLEANUP FLOOR ==========");

    for (int i = 0; i < floorCount; i++)
        delete floor[i];

    LOG(GREEN, "End of main — if no crash + valgrind clean => PERFECT ✅");
    return 0;
}
