#pragma once
#include "Actor.h"

class Entity : public Actor
{
public:
    Entity();
    Entity(char icon, float Health, float AttackPower, float DefensePower, float Speed);

    float getIcon() { return m_icon; }
    float getHealth() { return m_health; }
    float getAttackPower() { return m_attackPower; }
    float getDefensePower() { return m_defensePower; }
    float getSpeed() { return m_speed; }

    float takeDamage(float damageAmount);
    float attack(Entity* entity);

    void printStats();
    void draw() override;
private:
    char m_icon;
    float m_health;
    float m_attackPower;
    float m_defensePower;
    float m_speed;
};