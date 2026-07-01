#pragma once

class HealthComponent {
public:
    HealthComponent(int health, int maxHealth);

    void takeDamage(int amount);
    void heal(int amount);
    int getHealth() const;
    bool isDead() const;
    void resetHealth();

    void setHealth(int health);
    void setMaxHealth(int maxHealth);

private:
    int health_;
    int maxHealth_;
};
