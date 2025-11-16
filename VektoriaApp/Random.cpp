#include "Random.h"

float Random::normalVerteilungFloat(float average, float stdDeviation)
{
	std::random_device rd;
	std::mt19937 gen(rd());

	std::normal_distribution<float> dis(average, stdDeviation); // Normalverteilung mit Mittelwert und Standardabweichung
	
	return dis(gen);
}

float Random::gleichVerteilungFloat(float min, float max)
{
	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_real_distribution<float> dis(min, max); // Gleichverteilung zwischen min und max

    return dis(gen);
}

int Random::normalVerteilungInt(float average, float stdDeviation)
{
	std::random_device rd;
	std::mt19937 gen(rd());

	std::normal_distribution<float> dis(average, stdDeviation); // Normalverteilung mit Mittelwert und Standardabweichung

	return (int)dis(gen);
}

int Random::gleichVerteilungInt(float min, float max)
{
	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_real_distribution<float> dis(min, max); // Gleichverteilung zwischen min und max

	return (int)dis(gen);
}