#include "Astronaut.h"
#include <iostream>

Astronaut::Astronaut(void)
	: m_number_of_flights(0), m_hours_in_space(0)
{
}

Astronaut::Astronaut(int number_of_flights, double hours_in_space, string name, string gender, int height, float weight)
	: m_number_of_flights(0), m_hours_in_space(0), Person(name, gender, height, weight)
{
}

int Astronaut::getNumFlights(){return m_number_of_flights;}

double Astronaut::getHoursInSpace(){return m_hours_in_space;}

void Astronaut::displayAttr()
{
	cout << "Astronaut: " << m_name << "\n";
	cout << "Gender: " << m_gender << "\n";
	cout << "Flights: " << m_number_of_flights << "\n";
	cout << "Hours in Space: " << m_hours_in_space << "\n";
}
