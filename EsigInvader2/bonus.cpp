#include "include/bonus.h"



bonus::bonus()
{
}


bonus::~bonus()
{
}

string bonus::getImage() {
	return this->s_imageUrl;
}

void bonus::setImage(const string image) {
	this->s_imageUrl = image;
}