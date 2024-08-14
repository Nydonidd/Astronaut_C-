#include "Spacecraft.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

Spacecraft::Spacecraft(double weight)
	: m_weight(weight)
{
}

void Spacecraft::addAstronaut(Astronaut& astronaut)
{
	m_astronauts.push_back(astronaut);
}

void Spacecraft::addEngine( RocketEngine& engine)
{
	m_engines.push_back(engine);
}

bool Spacecraft::checkIfCanLaunch()
{
    if (m_astronauts.empty()) {
        cout << "No astronauts are present. Unable to start ship. \n";
        return false;
    }

    if (m_engines.empty()) {
        cout << "No engines are present. Unable to start ship. \n";
        return false;
    }

    for (const auto& engine : m_engines) {
        if (engine.returnFuelLeft() > 0) {
            return true;
        }
    }

    cout << "No fuel left. \n";
    return false;
}

void Spacecraft::launch()
{
    if (!checkIfCanLaunch()) {
        cout << "Unable to launch. \n";
        return;
    }

    cout << "Starting engines... \n";

    for (auto& engine : m_engines) {
        engine.start();
    }

    cout << "Engines started!\n";

    while (true) {
        bool fuel_left = false;

        for (auto& engine : m_engines) {
            if (engine.returnFuelLeft() > 0) {
                m_speed += engine.returnThrust() / m_weight;
                m_height += m_speed * 0.2;

                cout << "\nCurrent speed: " << m_speed << "\n";
                cout << "Current height: " << m_height << "\n";
                
                //this_thread::sleep_for(std::chrono::milliseconds(100));

                engine.useFuel(25);
                fuel_left = true;
            }
        }

        if (!fuel_left) {
            cout << "No fuel left. \n";
            break;
        }

        if (m_height >= 150000) {
            cout << "Ship has reached orbit. \n";
            m_num_orbits += 1;
            //break;
        }
    }

    if (m_height < 150000) {
        fall();
    }
    else {
        land();
    }


}

void Spacecraft::fall()
{
    cout << "Ship failed to reach orbit. \n";
    cout << "Highest height reached was: " << m_height << "\n";
}

void Spacecraft::land()
{
    cout << "Ship is beginning to land. \n";
    cout << "Ship successfully completed a total of " << m_num_orbits << " orbits.\n";
}
