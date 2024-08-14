#pragma once

class RocketEngine
{
private:
	double m_fuel_level;
	double m_thrust;
	bool m_running;

public:
	RocketEngine(void);
	RocketEngine(double fuel, double thrust);

	void start();
	void stop();
	double returnFuelLeft() const;
	double returnThrust();
	void useFuel(double fuel);
};
