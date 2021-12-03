#include <iostream>
#include "Entity.h"

Entity::Entity()
{
	m_icon = '0';
	m_health = 0;
	m_attackPower = 0;
	m_defensePower = 0;
	m_speed = 0;
};
Entity::Entity(char icon, float Health, float AttackPower, float DefensePower, float Speed)
{
	m_icon = icon;
	m_health = Health;
	m_attackPower = AttackPower;
	m_defensePower = DefensePower;
	m_speed = Speed;
};

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
	std::cout << "Attack: " << getAttackPower() << std::endl;
	std::cout << "Defense: " << getDefensePower() << std::endl;
	std::cout << "Speed: " << getDefensePower() << std::endl;
}
