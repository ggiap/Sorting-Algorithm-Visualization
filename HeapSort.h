#pragma once
#include "Algorithms.h"

class HeapSort : public Algorithms
{
public:
	void heapify(sf::RenderWindow &window, int n, int i, float delay);
	bool sort(sf::RenderWindow &window, float delay);
	void iterativeHeapSort(sf::RenderWindow &window, float delay);
	string getName();
};

