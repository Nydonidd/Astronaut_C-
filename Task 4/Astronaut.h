#pragma once
#include "Person.h"

class Astronaut : public Person
{
private:
	int m_number_of_flights;
	double m_hours_in_space;

public:
	Astronaut(void);
	Astronaut(int number_of_flights, double hours_in_space, string name, string gender, int height, float weight);

	int getNumFlights();
	double getHoursInSpace();
	void displayAttr();

};