#include "RocketEngine.h"
#include <iostream>

using namespace std;

RocketEngine::RocketEngine(void)
	: m_fuel_level(0), m_thrust(0)
{
}

RocketEngine::RocketEngine(double fuel, double thrust)
	: m_fuel_level(fuel), m_thrust(thrust)
{
}

void RocketEngine::start()
{
	if (m_fuel_level > 0) {
		m_running = true;
		cout << "The rocket is running.\n";
	}
	else {
		cout << "No fuel left. Unable to start rocket.\n";
	}
}

void RocketEngine::stop()
{
	m_running = false;
	cout << "The engine is stopped.\n";
}

double RocketEngine::returnFuelLeft() const 
{
	if (m_running) {
		return m_thrust;
	}
	else {
		return 0;
	}
}

double RocketEngine::returnThrust(){return m_thrust;}

void RocketEngine::useFuel(double fuel)
{
	if (m_fuel_level >= fuel) {
		m_fuel_level -= fuel;
	}
	else {
		cout << "Out of fuel.. stopping engine. \n";
		stop();
	}
}
