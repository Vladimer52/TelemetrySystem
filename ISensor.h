#pragma once
#include <string>
class ISensor
{
public:
	virtual ~ISensor() = default;
	virtual std::string name(void) const = 0;
	virtual std::string type(void) const = 0;
	virtual double read(void) = 0;
};

