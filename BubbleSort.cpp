#include "BubbleSort.h"

bool BubbleSort::sort(sf::RenderWindow &window, const float delay)
{
	if (rods.size() > 1)
	{
		if (!sorted)
		{
			//Sort
			size_t i, j;
			bool swapped;
			for (i = 0; i < rods.size() - 1; ++i)
			{
				swapped = false;
				for (j = 0; j < rods.size() - i - 1; ++j)
				{
					checkEvents(window);
					if (backButtonPressed) return false;

					rods.at(j).setFillColor(sf::Color::Red);
					rods.at(j + 1).setFillColor(sf::Color::Red);			

					++numberOfComparisons;
					numberOfArrayAccesses += 2;
					if (rods.at(j).getSize().y > rods.at(j + 1).getSize().y)
					{
						numberOfArrayAccesses += 2;
						swap(rods.at(j), rods.at(j + 1));
						auto p1 = rods.at(j).getPosition();
						auto p2 = rods.at(j + 1).getPosition();
						rods.at(j).setPosition(p2);
						rods.at(j + 1).setPosition(p1);
						swapped = true;
					}
					draw(window);
					wait(window, delay);

					if (j == rods.size() - i - 2)
						rods.at(j + 1).setFillColor(sf::Color::Blue);				
					rods.at(j).setFillColor(sf::Color::White);
				}

				// IF no two elements were swapped by inner loop, then break 
				if (swapped == false)
				{
					sorted = true;
					break; //Speeds up the algorithm
				}
			}
			for (int x = 0; x < rods.size(); ++x)
				rods.at(x).setFillColor(sf::Color::Blue);
			printMessage(window, sf::Vector2f(20.0f, 10.0f), "Finished: " + getName());

			return sorted;
		}
	}
	return sorted;
}

string BubbleSort::getName()
{
	return "BubbleSort";
}


