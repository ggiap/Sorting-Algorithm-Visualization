#include "GnomeSort.h"

bool GnomeSort::sort(sf::RenderWindow &window, float delay)
{
	if (rods.size() > 1)
	{
		if (!sorted)
		{
			int index = 0;

			while (index < rods.size()) 
			{
				checkEvents(window);
				if (backButtonPressed) return false;

				if (index == 0)
				{
					index++;

					rods.at(index).setFillColor(sf::Color::Blue);
					draw(window);
					wait(window, delay);
				}
				++numberOfComparisons;
				numberOfArrayAccesses += 2;
				if (rods.at(index).getSize().y >= rods.at(index - 1).getSize().y)
				{
					rods.at(index).setFillColor(sf::Color::Red);
					index++;

					draw(window);
					wait(window, delay);
					rods.at(index - 1).setFillColor(sf::Color::Blue);
				}
				else
				{
					rods.at(index).setFillColor(sf::Color(255,150,0));
					rods.at(index - 1).setFillColor(sf::Color::Blue);
					numberOfArrayAccesses += 2;
					swap(rods.at(index), rods.at(index - 1));
					auto pos1 = rods.at(index).getPosition();
					auto pos2 = rods.at(index - 1).getPosition();
					rods.at(index).setPosition(pos2);
					rods.at(index - 1).setPosition(pos1);
					index--;

					draw(window);
					wait(window, delay);
					rods.at(index).setFillColor(sf::Color::Blue);
				}	
			}
			sorted = true;
			printMessage(window, sf::Vector2f(20.0f, 10.0f), "Finished: " + getName());

			return sorted;
		}
	}
	return sorted;
}

string GnomeSort::getName()
{
	return "Gnome Sort";
}
