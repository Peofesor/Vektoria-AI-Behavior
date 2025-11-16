#pragma once
#include <random>
#include <fstream> // Für Dateioperationen

class Random
{
public:
	static float gleichVerteilungFloat(float min, float max);
	static float normalVerteilungFloat(float average, float stdDeviation);

	static int gleichVerteilungInt(float average, float stdDeviation);
	static int normalVerteilungInt(float average, float stdDeviation);
};

