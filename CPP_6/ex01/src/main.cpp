#include "Serializer.hpp"

int main() {
	Data* data = new Data(1, 2);

	uintptr_t raw = Serializer::serialize(data);
	std::cout << raw << std::endl;

	Data* other_data = Serializer::deserialize(raw);

	std::cout << other_data->a << std::endl;
	std::cout << other_data->b << std::endl;
	std::cout << other_data->name << std::endl;

	delete data;
}