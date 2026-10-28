#include "Sensors.h"

TemperatureSensor::TemperatureSensor(std::string name, double base) :
	name_(std::move(name)), base_(base),
	rng_(std::random_device{}()), dist_(-2.0, 2.0) {}

std::string TemperatureSensor::name() const
{
	return name_;
}

std::string TemperatureSensor::type() const
{
	return "Temperature";
}

double TemperatureSensor::read()
{
	return (base_ + dist_(rng_));
}

HumiditySensor::HumiditySensor(std::string name): name_(name), 
rng_(std::random_device{}()), dist_(0.0, 100.0)
{
}

std::string HumiditySensor::name(void) const
{
	return name_;
}

std::string HumiditySensor::type(void) const
{
	return "Humidity";
}

double HumiditySensor::read(void)
{
	return dist_(rng_);
}


PreasureSensor::PreasureSensor(std::string name) : name_(name),
rng_(std::random_device{}()), dist_(1008.0, 1018.0)
{
}

std::string PreasureSensor::name(void) const
{
	return name_;
}

std::string PreasureSensor::type(void) const
{
	return "Preasure";
}

double PreasureSensor::read(void)
{
	return dist_(rng_);
}