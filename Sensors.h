#pragma once
#include "ISensor.h"
#include <random>
class TemperatureSensor : public ISensor
{
private:
	std::string name_;
	double base_;
	std::mt19937 rng_;
	std::uniform_real_distribution<double> dist_;
	
public:
	explicit TemperatureSensor(std::string name, double base);
	std::string name(void) const override;
	std::string type(void) const override;

	double read(void) override;
};

class HumiditySensor : public ISensor
{
private:
	std::string name_;
	std::mt19937 rng_;
	std::uniform_real_distribution<double> dist_;

public:
	explicit HumiditySensor(std::string name);
	std::string name(void) const override;
	std::string type(void) const override;

	double read(void) override;
};

class PreasureSensor : public ISensor
{
private:
	std::string name_;
	std::mt19937 rng_;
	std::uniform_real_distribution<double> dist_;

public:
	explicit PreasureSensor(std::string name);
	std::string name(void) const override;
	std::string type(void) const override;

	double read(void) override;
};

