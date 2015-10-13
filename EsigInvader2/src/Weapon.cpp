#include "../include/Weapon.h"

Weapon::Weapon()
{

}

Weapon::Weapon(int level, string urlImage)
{
	this->level = level;
	this->urlImage = urlImage;
	this->damage = 5;
}


Weapon::~Weapon()
{

}

void Weapon::downgrade(int level) {
	this->level = level;
}

void Weapon::upgrade() {
	this->level += 1;
	this->damage *= 5;
}