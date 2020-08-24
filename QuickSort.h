#pragma once
#include "Algorithms.h"
class QuickSort : public Algorithms
{
public:
	int partition(sf::RenderWindow &window, int low, int high, float delay);
	void quickSort(sf::RenderWindow &window, int low, int high, float delay);
	bool sort(sf::RenderWindow &window, float delay);
	string getName();
	void quickSortIterative(sf::RenderWindow &window, int l, int h, float delay);
	int iterativePartition(sf::RenderWindow &window, int low, int high, float delay);

	bool iterative;
};

