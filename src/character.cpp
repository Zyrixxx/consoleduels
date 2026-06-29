#include <print>
#include <algorithm>
#include "../include/character.hpp"

// Constructor
Character::Character(const std::string& name, int health, int maxHealth)
	: name_(name), health_(health), maxHealth_(maxHealth) {
}

const std::string& Character::getName() const {
	return name_;
}

int Character::getHealth() const {
	return health_;
}

void Character::Attack(Character& target, int amount) {
	if (amount <= 0 || isDead() || target.isDead()) return;

	target.TakeDamage(amount);
	std::println("{} attacks {} for {} damage.\n", name_, target.getName(), amount);
	std::println("{} now has {} health.\n", target.getName(), target.getHealth());
	if (target.isDead()) {
		std::println("{} has died.\n", target.getName());
	}
	
}

void Character::TakeDamage(int amount) {
	if (amount <= 0 || isDead()) return;

	health_ = std::clamp(health_ - amount, 0, maxHealth_);
}

void Character::Heal(int amount) {

	if (amount <= 0 || health_ >= maxHealth_) return;

	health_ = std::clamp(health_ + amount, 0, maxHealth_);
}


bool Character::isDead() const {
	return health_ <= 0;
}

void Character::resetStats() {
	health_ = maxHealth_;
}