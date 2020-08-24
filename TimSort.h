#pragma once
#include "Algorithms.h"

// Merge sort + Insertion Sort = Tim Sort
class TimSort : public Algorithms
{
public:
	void insertionSort(sf::RenderWindow &window, int left, int right, float delay);
	void merge(sf::RenderWindow &window, int l, int m, int r, float delay);
	bool sort(sf::RenderWindow &window, float delay);
	string getName();
};

