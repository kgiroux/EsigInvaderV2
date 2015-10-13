#include "../include/Bonus.h"



Bonus::Bonus()
{
}


Bonus::~Bonus()
{
}

string Bonus::getImage() {
	return this->s_imageUrl;
}

void Bonus::setImage(const string image) {
	this->s_imageUrl = image;
}