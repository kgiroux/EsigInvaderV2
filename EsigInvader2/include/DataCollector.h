#pragma once
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <array>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <fstream>
#include <time.h>
#include <direct.h>
#include "myo\myo.hpp"
class DataCollector
{
public:
	DataCollector();
	~DataCollector();
	void end();
private : 
	void openFiles();
	void initFileName();
	void onEmgData(myo::Myo* myo, uint64_t timestamp, const int8_t* emg);
	void checkOrientation(float x, float y, float z, float w);
	void onOrientationData(myo::Myo *myo, uint64_t timestamp, const myo::Quaternion< float > &rotation);
	void onAccelerometerData(myo::Myo *myo, uint64_t timestamp, const myo::Vector3< float > &accel);
	void onGyroscopeData(myo::Myo *myo, uint64_t timestamp, const myo::Vector3< float > &gyro);
	void onConnect(myo::Myo *myo, uint64_t timestamp, myo::FirmwareVersion firmwareVersion);
	void printVector(std::ofstream &file, uint64_t timestamp, const myo::Vector3< float > &vector);
	void printVectorGyro(uint64_t timestamp, const myo::Vector3< float > &vector);
	void printVectorAcce(uint64_t timestamp, const myo::Vector3< float > &vector);

	std::ostringstream emgFileString;
	std::ostringstream gyroFileString;
	std::ostringstream accelerometerFileString;
	std::ostringstream orientationFileString;
	std::ostringstream orientationEulerFileString;

	int previous_x;
	int previous_y;
	int previous_z;
	int previous_w;

	std::ofstream emgFile;
	std::ofstream gyroFile;
	std::ofstream orientationFile;
	std::ofstream orientationEulerFile;
	std::ofstream accelerometerFile;
};

