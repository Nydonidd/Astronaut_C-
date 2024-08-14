#include <iostream>
#include "Astronaut.h"
#include "Spacecraft.h"
#include "RocketEngine.h"
#include <string>

int main() {
	Astronaut astronaut1(7, 453.20, "Dimo", "Male", 210, 150);
	Astronaut astronaut2(2, 233.20, "Riley", "Female", 150, 60);

	RocketEngine engine_1(150000, 700000);
	RocketEngine engine_2(75000, 50000);

	Spacecraft ISS(700000);
	ISS.addAstronaut(astronaut1);
	ISS.addAstronaut(astronaut2);
	ISS.addEngine(engine_1);
	ISS.addEngine(engine_2);

	ISS.launch();

	return 0;
}