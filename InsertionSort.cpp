#include "InsertionSort.h"


bool InsertionSort::sort(sf::RenderWindow &window, float delay)
{
	if (rods.size() > 1)
	{
		if (!sorted)
		{
			for (size_t i = 1; i < rods.size(); i++)
			{
				++numberOfArrayAccesses;
				sf::RectangleShape key = rods.at(i);
				signed j = i - 1;

				/* Move elements of rods[0..i-1], that are
				   greater than key, to one position ahead
				   of their current position */
				
				numberOfArrayAccesses += 2;
				while (j >= 0 && (rods.at(j).getSize().y > key.getSize().y))
				{
					checkEvents(window);
					if (backButtonPressed) return false;

					++numberOfComparisons;

					rods.at(j).setFillColor(sf::Color::Red);
					
					draw(window);
					wait(window, delay);

					numberOfArrayAccesses += 2;
					rods.at(j + 1).setSize(rods.at(j).getSize());

					if (i != 1)
						rods.at(j + 1).setFillColor(sf::Color::Blue);
					
					--j;
				}
				key.setFillColor(sf::Color::Blue);

				numberOfArrayAccesses += 2;
				//Insert the key back to the vector
				swap(rods.at(j + 1), key);
				auto p1 = key.getPosition();
				auto p2 = rods.at(j + 1).getPosition();
				key.setPosition(p2);
				rods.at(j + 1).setPosition(p1);

				/*If the first number is the shortest for the time being, paint it blue,
				  otherwise it will stay white */
				if((i == 1) && (key.getSize().y == rods.at(i).getSize().y))
					rods.at(0).setFillColor(sf::Color::Blue);

				draw(window);
				wait(window, delay);
			}
			sorted = true;
			printMessage(window, sf::Vector2f(20.0f, 10.0f), "Finished: " + getName());

			return sorted;
		}
	}
	return sorted;
}

bool InsertionSort::binaryInsertionSort(sf::RenderWindow &window, float delay)
{
	if (rods.size() > 1)
	{
		if (!sorted)
		{
			for (size_t i = 1; i < rods.size(); ++i)
			{
				++numberOfArrayAccesses;
				sf::RectangleShape key = rods.at(i);
				size_t left = 0;
				size_t right = i;
				rods.at(left).setFillColor(sf::Color::Green);
				while (left < right)
				{		
					checkEvents(window);
					if (backButtonPressed) return false;

					++numberOfComparisons;
					numberOfArrayAccesses += 2;
					size_t mid = (left + right) / 2;
					if (key.getSize().y > rods.at(mid).getSize().y)
					{
						rods.at(left).setFillColor(sf::Color::Blue);
						left = mid + 1;
						rods.at(left).setFillColor(sf::Color::Green);
					}
					else
						right = mid;		
				}
				draw(window);
				wait(window, delay);

				for (size_t j = i; j > left; --j)
				{
					checkEvents(window);
					if (backButtonPressed) return false;

					numberOfArrayAccesses += 2;
					rods.at(j).setFillColor(sf::Color::Red);
					rods.at(j - 1).setFillColor(sf::Color::Red);
					swap(rods.at(j - 1), rods.at(j));
					auto p1 = rods.at(j).getPosition();
					auto p2 = rods.at(j - 1).getPosition();
					rods.at(j).setPosition(p2);
					rods.at(j - 1).setPosition(p1);

					draw(window);
					wait(window, delay);
					rods.at(j).setFillColor(sf::Color::Blue);
					rods.at(j - 1).setFillColor(sf::Color::Blue);
				}
			}
			sorted = true;
			printMessage(window, sf::Vector2f(20.0f, 10.0f), "Finished: " + getName());

			return sorted;
		}
	}
	return sorted;
}

string InsertionSort::getName()
{
	return "InsertionSort";
}
