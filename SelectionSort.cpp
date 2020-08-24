#include "SelectionSort.h"

bool SelectionSort::sort(sf::RenderWindow &window, float delay)
{
	if (rods.size() > 1)
	{
		if (!sorted)
		{
			size_t i, j, min_idx;

			// One by one move boundary of unsorted subarray 
			for (i = 0; i < rods.size() - 1; i++)
			{
				// Find the minimum element in unsorted array 
				min_idx = i;
				rods.at(i).setFillColor(sf::Color::Red);
				for (j = i + 1; j < rods.size(); j++)
				{
					checkEvents(window);
					if (backButtonPressed) return false;

					numberOfArrayAccesses += 2;
					++numberOfComparisons;
					if (rods.at(j).getSize().y < rods.at(min_idx).getSize().y)
					{
						rods.at(j).setFillColor(sf::Color(255, 140, 0));
						rods.at(min_idx).setFillColor(sf::Color::White);

						min_idx = j;

						draw(window);
						wait(window, delay);
					}
					else
					{
						if(min_idx == i)
							rods.at(min_idx).setFillColor(sf::Color(255, 140, 0));
						rods.at(j).setFillColor(sf::Color::Red);
						draw(window);
						wait(window, delay);
						if (!(j == rods.size()))
							rods.at(j).setFillColor(sf::Color::White);
					}
				}
				if((min_idx == rods.size() - 1) && (i == rods.size() - 2))
					rods.at(i).setFillColor(sf::Color::Blue);
				if(i == rods.size() - 2)
					rods.at(i + 1).setFillColor(sf::Color::Blue);
				rods.at(min_idx).setFillColor(sf::Color::Blue);
								
				numberOfArrayAccesses += 2;
				// Swap the found minimum element with the first element 
				swap(rods.at(min_idx), rods.at(i));
				auto p1 = rods.at(i).getPosition();
				auto p2 = rods.at(min_idx).getPosition();
				rods.at(i).setPosition(p2);
				rods.at(min_idx).setPosition(p1);	

				draw(window);
				wait(window, delay);
			}
			sorted = true;
			printMessage(window,sf::Vector2f(20.0f,10.0f), "Finished: " + getName());

			return sorted;
		}
	}
	else
		return sorted;

	return true;
}

string SelectionSort::getName()
{
	return "SelectionSort";
}

