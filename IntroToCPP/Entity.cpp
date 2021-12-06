#include "Entity.h"
#include <iostream>

Entity::Entity()
{
	m_icon = '\0';
	m_health = 0;
	m_attackPower = 0;
	m_defensePower = 0;
	m_speed = 0;
}

Entity::Entity(char icon, float health, float attackPower, float defensePower, float speed)
{
	m_icon = icon;
	m_health = health;
	m_attackPower = attackPower;
	m_defensePower = defensePower;
	m_speed = speed;
}

float Entity::takeDamage(float damageAmount)
{
	float damageTaken = damageAmount - getDefensePower();

	if (damageTaken <= 0)
		damageTaken = 1;

	m_health -= damageTaken;

	if (m_health <= 0)
		m_health = 0;

	return damageTaken;
}

float Entity::attack(Entity* entity)
{
	return entity->takeDamage(getAttackPower());
}

void Entity::printStats()
{
	std::cout << m_icon << std::endl;
	std::cout << "Health: " << getHealth() << std::endl;
	std::cout << "Attack Power: " << getAttackPower() << std::endl;
	std::cout << "Defense Power: " << getDefensePower() << std::endl;
	std::cout << "Speed: " << getSpeed() << std::endl;
}

void Entity::draw()
{

}
