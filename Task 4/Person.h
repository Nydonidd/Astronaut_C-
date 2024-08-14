#pragma once
#include <string>

using namespace std;

class Person {
protected:
	string m_name;
	string m_gender;
	int m_height;
	float m_weight;

public:
	Person(void);
	Person(string name, string gender, int height, float weight);
};