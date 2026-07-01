#include "components/healthcomponent.hpp"

#include <algorithm>

HealthComponent::HealthComponent(int health, int maxHealth)
    : health_(health), maxHealth_(maxHealth) {}

void HealthComponent::takeDamage(int amount)
{
    if (amount <= 0 || isDead()) {
        return;
    }

    health_ = std::clamp(health_ - amount, 0, maxHealth_);
}

void HealthComponent::heal(int amount)
{
    if (amount <= 0 || health_ >= maxHealth_) {
        return;
    }

    health_ = std::clamp(health_ + amount, 0, maxHealth_);
}

int HealthComponent::getHealth() const
{
    return health_;
}

bool HealthComponent::isDead() const
{
    return health_ <= 0;
}

void HealthComponent::resetHealth()
{
    health_ = maxHealth_;
}

void HealthComponent::setHealth(int health)
{
    health_ = std::clamp(health, 0, maxHealth_);
}

void HealthComponent::setMaxHealth(int maxHealth)
{
    maxHealth_ = maxHealth;
    health_ = std::clamp(health_, 0, maxHealth_);
}
