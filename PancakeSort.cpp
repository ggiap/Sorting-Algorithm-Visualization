#include "PancakeSort.h"

/* Reverses rods[0..maxIndex] */
void PancakeSort::flip(sf::RenderWindow &window, int maxIndex, float delay)
{
	int start = 0;
	int temp = maxIndex;
	while (start < maxIndex)
	{
		checkEvents(window);
		if (backButtonPressed) return;

		if (maxIndex != curr_size - 1)
			rods.at(start).setFillColor(sf::Color::Red);
		if(start > 0 && maxIndex != curr_size - 1)
			rods.at(maxIndex).setFillColor(sf::Color::Red);
		
		numberOfArrayAccesses += 2;
		swap(rods.at(maxIndex), rods.at(start));
		auto p1 = rods.at(maxIndex).getPosition();
		auto p2 = rods.at(start).getPosition();
		rods.at(maxIndex).setPosition(p2);
		rods.at(start).setPosition(p1);

		if (start == 0 && maxIndex != curr_size - 1)
			rods.at(maxIndex).setFillColor(sf::Color::Green);
		draw(window);
		wait(window, delay);

		if (maxIndex != curr_size - 1 && start > 0)
			rods.at(maxIndex).setFillColor(sf::Color::White);
		if (start > 0)
			rods.at(start).setFillColor(sf::Color::White);

		start++;
		maxIndex--;
	}
	rods.at(temp).setFillColor(sf::Color::White);
}

bool PancakeSort::sort(sf::RenderWindow &window, float delay)
{
	if (rods.size() > 1)
	{
		if (!sorted)
		{
			// Start from the complete 
			// vector and reduce current
			// size by one 
			for (curr_size = rods.size(); curr_size > 0; --curr_size)
			{
				checkEvents(window);
				if (backButtonPressed) return false;

				// Find index of the  
				// maximum element in  
				// rods[0..curr_size-1] 
				auto maxIndex = 0;
				for (auto i = 0; i < curr_size; ++i)
				{
					++numberOfComparisons;
					numberOfArrayAccesses += 2;
					if (rods.at(i).getSize().y > rods.at(maxIndex).getSize().y)
						maxIndex = i;
				}
				rods.at(maxIndex).setFillColor(sf::Color(255, 150, 0));
				draw(window);
				wait(window, 4 * delay);
				// Move the maximum element to end of  
				// current array if it's not already 
				// at the end 
				if (maxIndex != curr_size - 1)
				{
					// To move at the end, 
					// first move maximum  
					// number to beginning  
					flip(window, maxIndex, delay);

					// Now move the maximum  
					// number to end by  
					// reversing current array 
					flip(window, curr_size - 1, delay);

				}

				rods.at(maxIndex).setFillColor(sf::Color::White);
				rods.at(curr_size - 1).setFillColor(sf::Color::Blue);
			}
			sorted = true;
			printMessage(window, sf::Vector2f(20.0f, 10.0f), "Finished: " + getName());

			return sorted;
		}		
	}
	return sorted;
}

string PancakeSort::getName()
{
	return "Pancake Sort";
}
