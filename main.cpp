#include "ISensor.h"
#include "SensorRegistry.h"
#include "Sensors.h"
#include <iostream>
int main(void)
{
	auto kitchen_temp_ptr = std::make_unique<TemperatureSensor>("kitchen_temp", 22);
	auto outdoor_temp_ptr = std::make_unique<TemperatureSensor>("outdoor_temp", 5);
	auto living_hum_ptr = std::make_unique<HumiditySensor>("living_hum");
	auto outdoor_press_ptr = std::make_unique<PreasureSensor>("outdoor_press");
	SensorRegistry registrator;
	registrator.add(std::move(kitchen_temp_ptr));
	registrator.add(std::move(outdoor_temp_ptr));
	registrator.add(std::move(living_hum_ptr));
	registrator.add(std::move(outdoor_press_ptr));

	auto list_names = registrator.list_name();
	std::cout << "sensors: \n";
	for (const auto& name : list_names)
	{
		std::cout << name << '\n';
	}

	auto kitchen_ptr = registrator.find("kitchen_temp");
	std::cout << kitchen_ptr->name() << ' ' << kitchen_ptr->type() << ' ' << kitchen_ptr->read() << '\n';

	auto unknown_ptr = registrator.find("unknown");
	if (unknown_ptr == nullptr)
		std::cout << "not found unknown\n";

	registrator.remove("living_hum");

	list_names = registrator.list_name();
	std::cout << "sensors: \n";
	for (const auto& name : list_names)
	{
		std::cout << name << '\n';
	}
	std::cout << "size = " << registrator.size() << '\n';
}