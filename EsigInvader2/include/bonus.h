#pragma once
#include<iostream>
#include"Motion.h"
#include<string>
using namespace std;
class Bonus : public Motion
{
public:
	Bonus();
	~Bonus();
	void setImage(const string image);
	string getImage();

private:
	string s_imageUrl;
};

