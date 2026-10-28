#include "SensorRegistry.h"

bool SensorRegistry::add(std::unique_ptr<ISensor> sensor)
{
	if (sensors_.find(sensor->name()) != sensors_.end())
	{
		sensors_.emplace(sensor->name(), sensor);
		return true;
	}
	else
		return false;
}

bool SensorRegistry::remove(const std::string& name)
{
	if (sensors_.find(name) != sensors_.end())
	{
		sensors_.erase(name);
		return true;
	}
	else
		return false;
}

ISensor* SensorRegistry::find(const std::string& name)
{
	auto it = sensors_.find(name);
	if (it != sensors_.end())
	{
		return it->second.get();
	}
	else
		return nullptr;
}

const ISensor* SensorRegistry::find(const std::string& name) const
{
		auto it = sensors_.find(name);
		if (it != sensors_.end())
		{
			return it->second.get();
		}
		else
			return nullptr;

}

std::vector<std::string> SensorRegistry::list_name() const
{
	std::vector<std::string> names;
	for (const auto& kv : sensors_)
	{
		names.push_back(kv.first);
	}
	return names;
}

size_t SensorRegistry::size() const
{
	return sensors_.size();
}