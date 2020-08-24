#include "ShellSort.h"

bool ShellSort::sort(sf::RenderWindow &window, float delay)
{
	if (rods.size() > 1)
	{
		if (!sorted)
		{
			// Start with a big gap, then reduce the gap 
			for (int gap = rods.size() / 2; gap > 0; gap /= 2)
			{
				// Do a gapped insertion sort for this gap size. 
				// The first gap elements rods[0..gap-1] are already in gapped order 
				// keep adding one more element until the entire vector is 
				// gap sorted  
				for (int i = gap; i < rods.size(); i += 1)
				{
					checkEvents(window);
					if (backButtonPressed) return false;

					// add rods[i] to the elements that have been gap sorted 
					// save rods[i] in temp and make a hole at position i 
					rods.at(i).setFillColor(sf::Color::Red);
					sf::RectangleShape temp;
					numberOfArrayAccesses += 2;
					swap(temp, rods.at(i));
					auto p1 = temp.getPosition();
					auto p2 = rods.at(i).getPosition();
					temp.setPosition(p2);
					rods.at(i).setPosition(p1);
					// shift earlier gap-sorted elements up until the correct  
					// location for rods[i] is found 
					int j;
					++numberOfComparisons;
					++numberOfArrayAccesses;
					for (j = i; j >= gap && rods.at(j - gap).getSize().y > temp.getSize().y; j -= gap)
					{
						rods.at(j).setFillColor(sf::Color::Red);
						rods.at(j - gap).setFillColor(sf::Color::Red);
						numberOfArrayAccesses += 2;
						swap(rods.at(j), rods.at(j - gap));
						auto p1 = rods.at(j).getPosition();
						auto p2 = rods.at(j - gap).getPosition();
						rods.at(j).setPosition(p2);
						rods.at(j - gap).setPosition(p1);

						draw(window);
						wait(window, delay);
						rods.at(j).setFillColor(sf::Color::White);
						rods.at(j - gap).setFillColor(sf::Color::White);
					}

					//  put temp (the original rods[i]) in its correct location 
					numberOfArrayAccesses += 2;
					swap(temp, rods.at(j));
					p1 = temp.getPosition();
					p2 = rods.at(j).getPosition();
					temp.setPosition(p2);
					rods.at(j).setPosition(p1);

					draw(window);
					wait(window, delay);
					rods.at(j).setFillColor(sf::Color::White);
				}
			}
			sorted = true;

			for (size_t i = 0; i < rods.size(); ++i)
				rods.at(i).setFillColor(sf::Color::Blue);
			printMessage(window, sf::Vector2f(20.0f, 10.0f), "Finished: " + getName());

			return sorted;
		}
	}
	return sorted;
}

string ShellSort::getName()
{
	return "Shell Sort";
}
