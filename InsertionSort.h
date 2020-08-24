#pragma once
#include "Algorithms.h"

class InsertionSort : public Algorithms
{
public:
	bool sort(sf::RenderWindow &window, float delay);
	bool binaryInsertionSort(sf::RenderWindow &window, float delay);
	string getName();
};

