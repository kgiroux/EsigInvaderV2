#pragma once
#include<string>
using namespace std;
class Weapon
{
public:
	Weapon(int level,string urlImage);
	void downgrade(int level);
	void upgrade();
	Weapon();
	~Weapon();
private : 
		unsigned int level;
		string urlImage;
		unsigned int damage;
		const int speed = 15;
};

