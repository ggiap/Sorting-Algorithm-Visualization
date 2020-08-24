#pragma once
#include "Algorithms.h"

class RadixSort : public Algorithms
{
public:
	void countSort(sf::RenderWindow &window, int n, int exp, float delay);
	bool sort(sf::RenderWindow &window, float delay);
	string getName();
};

