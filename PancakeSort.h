#pragma once
#include "Algorithms.h"

class PancakeSort : public Algorithms
{
public:
	void flip(sf::RenderWindow &window, int maxIndex, float delay);
	bool sort(sf::RenderWindow &window, float delay);
	string getName();

	int curr_size;
};

