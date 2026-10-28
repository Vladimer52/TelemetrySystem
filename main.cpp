#include "ISensor.h"
#include "SensorRegistry.h"
#include "Sensors.h"
#include <iostream>
int main(void)
{
	TemperatureSensor kitchen_temp("kitchen_temp", 22);
	TemperatureSensor outdoor_temp("outdoor_temp", 5);
	HumiditySensor living_hum("living_hum");
	PreasureSensor outdoor_press("outdoor_press");
	std::unique_ptr<ISensor> kitchen_temp_ptr = std::make_unique<ISensor>(kitchen_temp);
	std::unique_ptr<ISensor> outdoor_temp_ptr = std::make_unique<ISensor>(outdoor_temp);
	std::unique_ptr<ISensor> living_hum_ptr = std::make_unique<ISensor>(living_hum);
	std::unique_ptr<ISensor> outdoor_press_ptr = std::make_unique<ISensor>(outdoor_press);
	SensorRegistry registrator;
	registrator.add(std::move(kitchen_temp_ptr));
	registrator.add(std::move(outdoor_temp_ptr));
	registrator.add(std::move(living_hum_ptr));
	registrator.add(std::move(outdoor_press_ptr));

	auto list_names = registrator.list_name();

	for (const auto& name : list_names)
	{
		std::cout<< "sensors: \n" << name << '\n';
	}

	auto kitchen_ptr = registrator.find(kitchen_temp.name());
	std::cout << kitchen_ptr->name() << ' ' << kitchen_ptr->type() << ' ' << kitchen_ptr->read() << '\n';

	auto unknown_ptr = registrator.find("unknown");
	if (unknown_ptr == nullptr)
		std::cout << "not found unknown\n";

	registrator.remove("living_hum");

	list_names = registrator.list_name();
	for (const auto& name : list_names)
	{
		std::cout << "sensors: \n" << name << '\n';
	}
	std::cout << "size = " << registrator.size() << '\n';
}