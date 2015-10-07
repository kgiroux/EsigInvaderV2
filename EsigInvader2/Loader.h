#pragma once

#include<list>
#include"niveau.h"
#include"joueur.h"
#include"control.h"

using namespace std;
class Loader
{
public:
	Loader();
	Loader(int hello);
	~Loader();

private :
	list<niveau> listLv;
	joueur player;
	static control ctrl;


};

