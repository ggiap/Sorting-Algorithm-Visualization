#include "CocktailSort.h"

bool CocktailSort::sort(sf::RenderWindow &window, float delay)
{
	if (rods.size() > 1)
	{
		if (!sorted)
		{
			bool swapped = true;
			int start = 0;
			int end = rods.size() - 1;

			while (swapped)
			{
				// reset the swapped flag on entering 
				// the loop, because it might be true from 
				// a previous iteration. 
				swapped = false;

				// loop from left to right same as 
				// the bubble sort 
				for (int i = start; i < end; ++i)
				{
					checkEvents(window);
					if (backButtonPressed) return false;

					rods.at(i).setFillColor(sf::Color::Red);
					rods.at(i + 1).setFillColor(sf::Color::Red);
					++numberOfComparisons;
					numberOfArrayAccesses += 2;
					if (rods.at(i).getSize().y > rods.at(i + 1).getSize().y) 
					{
						numberOfArrayAccesses += 2;
						swap(rods.at(i), rods.at(i + 1));
						auto pos1 = rods.at(i).getPosition();
						auto pos2 = rods.at(i + 1).getPosition();
						rods.at(i).setPosition(pos2);
						rods.at(i + 1).setPosition(pos1);
						swapped = true;		
					}
					draw(window);
					wait(window, delay);
					rods.at(i).setFillColor(sf::Color::White);
					rods.at(i + 1).setFillColor(sf::Color::White);
				}

				// if nothing moved, then array is sorted. 
				if (!swapped)
				{
					for (int i = start; i < end + 1; ++i)
						rods.at(i).setFillColor(sf::Color::Blue);
					sorted = true;
					break;
				}

				// otherwise, reset the swapped flag so that it 
				// can be used in the next stage 
				swapped = false;

				// move the end point back by one, because 
				// item at the end is in its rightful spot 
				rods.at(end).setFillColor(sf::Color::Blue);
				--end;

				// from right to left, doing the 
				// same comparison as in the previous stage 
				for (int i = end - 1; i >= start; --i)
				{
					checkEvents(window);
					if (backButtonPressed) return false;

					rods.at(i).setFillColor(sf::Color::Red);
					rods.at(i + 1).setFillColor(sf::Color::Red);
					++numberOfComparisons;
					numberOfArrayAccesses += 2;
					if (rods.at(i).getSize().y > rods.at(i + 1).getSize().y)
					{	
						numberOfArrayAccesses += 2;
						swap(rods.at(i), rods.at(i + 1));
						auto pos1 = rods.at(i).getPosition();
						auto pos2 = rods.at(i + 1).getPosition();
						rods.at(i).setPosition(pos2);
						rods.at(i + 1).setPosition(pos1);
						swapped = true;	
					}
					draw(window);
					wait(window, delay);
					rods.at(i).setFillColor(sf::Color::White);
					rods.at(i + 1).setFillColor(sf::Color::White);
				}

				// if nothing moved, then array is sorted. 
				if (!swapped)
				{
					for (int i = start; i < end + 1; ++i)
						rods.at(i).setFillColor(sf::Color::Blue);
					sorted = true;
					break;
				}

				// increase the starting point, because 
				// the last stage would have moved the next 
				// smallest number to its rightful spot. 
				rods.at(start).setFillColor(sf::Color::Blue);
				++start;
			}
			printMessage(window, sf::Vector2f(20.0f, 10.0f), "Finished: " + getName());

			return sorted;
		}
	}
	return sorted;
}

string CocktailSort::getName()
{
	return "Cocktail Sort";
}
