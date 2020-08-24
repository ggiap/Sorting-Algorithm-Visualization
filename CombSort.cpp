#include "CombSort.h"

int CombSort::getNextGap(int gap)
{
	// Shrink gap by Shrink factor 
	gap = (gap * 10) / 13;

	if (gap < 1)
		return 1;
	return gap;
}

bool CombSort::sort(sf::RenderWindow &window, float delay)
{
	if (rods.size() > 1)
	{
		if (!sorted)
		{
			// Initialize gap 
			int gap = rods.size();

			// Initialize swapped as true to make sure that 
			// loop runs 
			bool swapped = true;

			// Keep running while gap is more than 1 and last 
			// iteration caused a swap 
			while (gap != 1 || swapped == true)
			{
				checkEvents(window);
				if (backButtonPressed) return false;

				// Find next gap 
				gap = getNextGap(gap);

				draw(window);
				wait(window, delay);
				// Initialize swapped as false so that we can 
				// check if swap happened or not 
				swapped = false;

				// Compare all elements with current gap 
				for (size_t i = 0; i < rods.size() - gap; i++)
				{
					checkEvents(window);
					if (backButtonPressed) return false;

					rods.at(i).setFillColor(sf::Color::Red);
					rods.at(i + gap).setFillColor(sf::Color::Red);
					++numberOfComparisons;
					numberOfArrayAccesses += 2;
					if (rods.at(i).getSize().y > rods.at(i + gap).getSize().y)
					{
						numberOfArrayAccesses += 2;
						swap(rods.at(i), rods.at(i + gap));
						auto p1 = rods.at(i).getPosition();
						auto p2 = rods.at(i + gap).getPosition();
						rods.at(i).setPosition(p2);
						rods.at(i + gap).setPosition(p1);
						swapped = true;
					}
					draw(window);
					wait(window, delay);
					rods.at(i).setFillColor(sf::Color::White);
					rods.at(i + gap).setFillColor(sf::Color::White);
				}
			}
			sorted = true;
			for (int i = 0; i < rods.size(); ++i)
				rods.at(i).setFillColor(sf::Color::Blue);
			printMessage(window, sf::Vector2f(20.0f, 10.0f), "Finished: " + getName());

			return sorted;
		}
	}
	return sorted;
}

string CombSort::getName()
{
	return "Comb Sort";
}
