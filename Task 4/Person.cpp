#include "Person.h"

Person::Person(void)
	: m_name("None"), m_gender("None"), m_height(0), m_weight(0)
{
}

Person::Person(string name, string gender, int height, float weight)
	: m_name(name), m_gender(gender), m_height(height), m_weight(weight)
{
}

