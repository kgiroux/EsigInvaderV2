#pragma once
#include<string>
using namespace std;
class armes
{
public:
	armes(int level,string urlImage);
	void downgrade(int level);
	void upgrade();
	armes();
	~armes();
private : 
		unsigned int level;
		string urlImage;
};

