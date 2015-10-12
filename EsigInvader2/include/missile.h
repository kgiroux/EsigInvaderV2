#pragma once
#include <iostream>
#include <string>
using namespace std;
class missile
{
public:
	missile();
	~missile();
	void setImage(const string image);
	string getImage();

private:
	string s_imageUrl;
};

