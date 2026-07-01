#pragma once

#include "utility/event.hpp"
#include "utility/gameevents.hpp"

class HealthComponent {
public:
    HealthComponent(int health, int maxHealth);
    
    Event<HealthChangedEvent> onHealthChanged_;
    Event<DeathEvent> onDeath_;

    void takeDamage(int amount);
    void heal(int amount);
    int getHealth() const;
    bool isDead() const;
    void handleDeath();
    void resetHealth();

    void setHealth(int health);
    void setMaxHealth(int maxHealth);

private:
    int health_;
    int maxHealth_;
    
};
