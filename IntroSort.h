#pragma once
#include "Algorithms.h"

class IntroSort : public Algorithms
{
public:
	void swapValues(int a, int b);
	void insertionsort(sf::RenderWindow &window, int begin, int end, float delay);
	int partition(sf::RenderWindow &window, int begin, int end, float delay);
	void merge(sf::RenderWindow &window, size_t begin, size_t mid, size_t end, float delay);
	void mergesort(sf::RenderWindow &window, int begin, int end, float delay);
	int MedianOfThree(int a, int b, int c);
	void introsort(sf::RenderWindow &window, int begin, int end, int depthLimit, float delay);
	bool sort(sf::RenderWindow &window, float delay);
	string getName();
};

