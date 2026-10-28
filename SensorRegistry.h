#pragma once
#include <map>
#include <string>
#include <memory>
#include <vector>
#include "ISensor.h"
class SensorRegistry
{
private:
	std::map < std::string, std::unique_ptr<ISensor>> sensors_;
public:
	bool add(std::unique_ptr<ISensor> sensor);
	bool remove(const std::string& name);
	ISensor* find(const std::string& name);
	const ISensor* find(const std::string& name) const;
	std::vector<std::string> list_name() const;
	size_t size() const;
};

