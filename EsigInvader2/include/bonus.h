#pragma once
#include<iostream>
#include<string>
using namespace std;
class Bonus
{
public:
	Bonus();
	~Bonus();
	void setImage(const string image);
	string getImage();

private:
	string s_imageUrl;
};

