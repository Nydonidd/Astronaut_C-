#pragma once
#include <vector>
#include "Astronaut.h"
#include "RocketEngine.h"
using namespace std;

class Spacecraft
{
private:
	vector<Astronaut> m_astronauts;
	vector<RocketEngine> m_engines;
	
	double m_weight;
	double m_speed;
	double m_height;
	int m_num_orbits;

public:
	Spacecraft(double weight);

	void addAstronaut(Astronaut& astronaut);
	void addEngine(RocketEngine& engine);
	bool checkIfCanLaunch();
	void launch();
	void fall();
	void land();

};