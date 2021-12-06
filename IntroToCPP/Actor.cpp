#include "Actor.h"

Actor::~Actor()
{
	delete m_name;
	delete this;
}
