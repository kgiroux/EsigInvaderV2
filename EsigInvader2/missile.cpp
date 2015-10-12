#include "include/missile.h"



missile::missile()
{
}


missile::~missile()
{
}

string missile::getImage() {
	return this->s_imageUrl;
} 

void missile::setImage(const string image ) {
	this->s_imageUrl = image;
}