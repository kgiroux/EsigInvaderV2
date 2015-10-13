#include "../include\DataCollector.h"



DataCollector::DataCollector()
{
		//openFiles();
}


DataCollector::~DataCollector()
{
}


void DataCollector::openFiles() {
	time_t timestamp = std::time(0);
	std::stringstream ss;
	ss << timestamp;
	//create result folder
	_mkdir("./result");
	std::string pathToFolder = "./result/exc" + ss.str();
	// create excution folder in result
	_mkdir(pathToFolder.c_str());

	// Init XML Element and reset Name file
	initFileName();

	// Define file name
	emgFileString << pathToFolder << "/" << "emg-" << timestamp << ".xml";
	gyroFileString << pathToFolder << "/" << "gyro-" << timestamp << ".xml";
	accelerometerFileString << pathToFolder << "/" << "accelerometer-" << timestamp << ".xml";
	orientationFileString << pathToFolder << "/" << "orientation-" << timestamp << ".xml";
	orientationEulerFileString << pathToFolder << "/" << "orientationEuler-" << timestamp << ".xml";

}

void DataCollector::initFileName() {
	emgFileString.str("");
	emgFileString.clear();
	gyroFileString.str("");
	gyroFileString.clear();
	accelerometerFileString.str("");
	accelerometerFileString.clear();
	orientationEulerFileString.str("");
	orientationEulerFileString.clear();
	orientationFileString.str("");
	orientationFileString.clear();
}


// onEmgData() is called whenever a paired Myo has provided new EMG data, and EMG streaming is enabled.
void DataCollector::onEmgData(myo::Myo* myo, uint64_t timestamp, const int8_t* emg)
{
	std::stringstream sstimestamp;
	sstimestamp << timestamp;
	for (size_t i = 0; i < 8; i++) {
		std::stringstream ss;
		ss << i;
		std::string nameElement = "emg" + ss.str();
		std::stringstream ssdata;
		ssdata << static_cast<int>(emg[i]);
	}
}
void DataCollector::checkOrientation(float x, float y, float z, float w) {

	std::cout << "rotation x :" << x << std::endl;
	std::cout << "rotation y :" << y << std::endl;
	std::cout << "rotation z :" << z << std::endl;
	std::cout << "rotation w :" << w << std::endl;

	if (previous_x < (x)) {
		std::cout << "left" << std::endl;
	}
	else {
		std::cout << "right" << std::endl;
	}

	previous_x = x;


	if (previous_y < (y)) {

	}
	else {

	}

	if (previous_z < (z)) {

	}
	else {

	}

	if (previous_w < (w)) {

	}
	else {

	}
}




// onOrientationData is called whenever new orientation data is provided
// Be warned: This will not make any distiction between data from other Myo armbands
void DataCollector::onOrientationData(myo::Myo *myo, uint64_t timestamp, const myo::Quaternion< float > &rotation) {

	checkOrientation(rotation.x(), rotation.y(), rotation.z(), rotation.w());

	using std::atan2;
	using std::asin;
	using std::sqrt;
	using std::max;
	using std::min;

	// Calculate Euler angles (roll, pitch, and yaw) from the unit quaternion.
	float roll = atan2(2.0f * (rotation.w() * rotation.x() + rotation.y() * rotation.z()),
		1.0f - 2.0f * (rotation.x() * rotation.x() + rotation.y() * rotation.y()));
	float pitch = asin(max(-1.0f, min(1.0f, 2.0f * (rotation.w() * rotation.y() - rotation.z() * rotation.x()))));
	float yaw = atan2(2.0f * (rotation.w() * rotation.z() + rotation.x() * rotation.y()),
		1.0f - 2.0f * (rotation.y() * rotation.y() + rotation.z() * rotation.z()));

}

// onAccelerometerData is called whenever new acceleromenter data is provided
// Be warned: This will not make any distiction between data from other Myo armbands
void DataCollector::onAccelerometerData(myo::Myo *myo, uint64_t timestamp, const myo::Vector3< float > &accel) {
	printVectorAcce(timestamp, accel);
	//printVector(accelerometerFile, timestamp, accel);

}

// onGyroscopeData is called whenever new gyroscope data is provided
// Be warned: This will not make any distiction between data from other Myo armbands
void DataCollector::onGyroscopeData(myo::Myo *myo, uint64_t timestamp, const myo::Vector3< float > &gyro) {
	printVectorGyro(timestamp, gyro);

	//printVector(gyroFile, timestamp, gyro);

}

void DataCollector::onConnect(myo::Myo *myo, uint64_t timestamp, myo::FirmwareVersion firmwareVersion) {
	//Reneable streaming
	myo->setStreamEmg(myo::Myo::streamEmgEnabled);
	//openFiles();
}

// Helper to print out accelerometer and gyroscope vectors
void DataCollector::printVector(std::ofstream &file, uint64_t timestamp, const myo::Vector3< float > &vector) {
	file << timestamp
		<< ',' << vector.x()
		<< ',' << vector.y()
		<< ',' << vector.z()
		<< std::endl;
}

void DataCollector::printVectorGyro(uint64_t timestamp, const myo::Vector3< float > &vector) {
}

void DataCollector::printVectorAcce(uint64_t timestamp, const myo::Vector3< float > &vector) {
}


void DataCollector::end () {
}
