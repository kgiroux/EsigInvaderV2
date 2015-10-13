#pragma once
#include<string>
using namespace std;
class armes
{
public:
	armes(int level,string urlImage);
	armes();
	~armes();
private : 
		unsigned int level;
		string urlImage;
};

