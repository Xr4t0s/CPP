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

int main() {

    /* ========= FLOOR MANAGEMENT ========= */
    AMateria* floor[100];
    int floorCount = 0;

    /* ========= SCENARIO 1 ========= */
    LOG(CYAN, "\n========== SCENARIO 1: BASIC FLOW ==========");

    MateriaSource* src = new MateriaSource();
    Character* hero = new Character("Hero");

    // create templates
    AMateria* iceTemplate = new Ice();
    AMateria* cureTemplate = new Cure();

    src->learnMateria(iceTemplate);
    src->learnMateria(cureTemplate);

    delete iceTemplate;
    delete cureTemplate;

    // create materias
    AMateria* m1 = src->createMateria("ice");
    AMateria* m2 = src->createMateria("cure");
    AMateria* m3 = src->createMateria("ice");
    AMateria* m4 = src->createMateria("cure");

    hero->equip(m1);
    hero->equip(m2);
    hero->equip(m3);
    hero->equip(m4);

    hero->use(0, *hero);
    hero->use(1, *hero);
    hero->use(2, *hero);
    hero->use(3, *hero);

    /* ========= SCENARIO 2: UNEQUIP ========= */
    LOG(CYAN, "\n========== SCENARIO 2: UNEQUIP ==========");

    // unequip slot 1 and 3 — ownership returns to main
    floor[floorCount++] = m2;
    hero->unequip(1);

    floor[floorCount++] = m4;
    hero->unequip(3);

    hero->use(1, *hero); // should do nothing
    hero->use(3, *hero); // should do nothing

    /* ========= SCENARIO 3: COPY ========= */
    LOG(CYAN, "\n========== SCENARIO 3: DEEP COPY ==========");

    Character copyHero(*hero);
    Character assignHero("Assign");
    assignHero = *hero;

    LOG(GREEN, "Destroying original hero");
    delete hero; // destroys m1 + m3

    LOG(GREEN, "Using copies after destruction");
    copyHero.use(0, copyHero);
    assignHero.use(0, assignHero);

    /* ========= SCENARIO 4: SOURCE COPY ========= */
    LOG(CYAN, "\n========== SCENARIO 4: SOURCE COPY ==========");

    MateriaSource srcCopy(*src);
    MateriaSource srcAssign;
    srcAssign = srcCopy;

    AMateria* tmp1 = srcCopy.createMateria("ice");
    AMateria* tmp2 = srcAssign.createMateria("cure");

    delete tmp1;
    delete tmp2;

    /* ========= SCENARIO 5: UNKNOWN ========= */
    LOG(CYAN, "\n========== SCENARIO 5: UNKNOWN ==========");

    AMateria* unknown = src->createMateria("fire");
    if (!unknown) {
        LOG(YELLOW, "Unknown materia correctly returned NULL");
	
	} else
		LOG(RED, "SHOULD HAVE RETURNED NULL");

    /* ========= CLEANUP ========= */
    LOG(CYAN, "\n========== CLEANUP ==========");

    delete src;

    // delete all dropped materias
    for (int i = 0; i < floorCount; i++) {
        delete floor[i];
    }

    LOG(GREEN, "End of main — destructors incoming");

    return 0;
}
