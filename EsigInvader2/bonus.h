#pragma once
#include<iostream>
#include<string>
using namespace std;
class bonus
{
public:
	bonus();
	~bonus();
	void setImage(const string image);
	string getImage();

private:
	string s_imageUrl;
};

