#include "include/armes.h"



armes::armes()
{

}


armes::~armes()
{

}

void armes::downgrade(int level) {
	this->level = level;
}

void armes::upgrade() {
	this->level += 1;
}