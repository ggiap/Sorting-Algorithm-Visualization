#pragma once
#include "Algorithms.h"

class CombSort : public Algorithms
{
public:
	int getNextGap(int gap);
	bool sort(sf::RenderWindow &window, float delay);
	string getName();
};

