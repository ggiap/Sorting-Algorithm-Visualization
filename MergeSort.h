#pragma once
#include "Algorithms.h"

class MergeSort : public Algorithms
{
public:
	void merge(sf::RenderWindow &window, size_t l, size_t m, size_t r, float delay);
	void mergeSort(sf::RenderWindow &window, size_t l, size_t r, float delay);
	bool sort(sf::RenderWindow &window, float delay);
	string getName();
};

