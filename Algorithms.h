#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;
#include "Button.h"

class Algorithms
{
public:
	virtual void createCanvas(sf::RenderWindow &window, const int numOfRods);
	virtual void printMessage(sf::RenderWindow &window, const sf::Vector2f &point, const string &message = "Finished!");
	virtual void draw(sf::RenderWindow &window);
	virtual bool sort(sf::RenderWindow &window, const float delay) = 0;
	virtual string getName() = 0;
	virtual void checkEvents(sf::RenderWindow &window);
	virtual void wait(sf::RenderWindow &window, float seconds);
	vector<sf::RectangleShape> getRods();
protected:
	Button backButton;
	vector<sf::RectangleShape> rods;
	bool sorted;
	bool backButtonPressed;
	int numberOfComparisons;
	int numberOfArrayAccesses;
};

