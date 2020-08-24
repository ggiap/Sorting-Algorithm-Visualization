#include "RadixSort.h"

void RadixSort::countSort(sf::RenderWindow &window, int n, int exp, float delay)
{
	vector<sf::RectangleShape> output(n); 
	vector<int> count(10,0);
	int i;

	// Store count of occurrences in count[] 
	for (i = 0; i < n; i++)
	{
		checkEvents(window);
		if (backButtonPressed) return;

		numberOfArrayAccesses += 2;
		count.at((int)(rods.at(i).getSize().y / exp) % 10)++;
		rods.at(i).setFillColor(sf::Color::Red);
		draw(window);
		wait(window, delay);
		rods.at(i).setFillColor(sf::Color::White);
	}

	// Change count[i] so that count[i] now contains actual 
	//  position of this digit in output[] 
	for (i = 1; i < 10; i++)
	{
		numberOfArrayAccesses += 2;
		count.at(i) += count.at(i - 1);
	}

	// Build the output vector 
	for (i = n - 1; i >= 0; i--)
	{
		checkEvents(window);
		if (backButtonPressed) return;

		numberOfArrayAccesses += 4;
		output.at(count.at((int)(rods.at(i).getSize().y / exp) % 10) - 1) = rods.at(i);
		output.at(count.at((int)(rods.at(i).getSize().y / exp) % 10) - 1).setPosition(rods.at(i).getPosition());
		count.at((int)(rods.at(i).getSize().y / exp) % 10)--;
		rods.at(i).setFillColor(sf::Color::Red);
		draw(window);
		wait(window, delay);
		rods.at(i).setFillColor(sf::Color::White);
	}

	// Copy the output vector to rods[], so that rods[] now 
	// contains sorted numbers according to current digit 
	for (i = 0; i < n; i++)
	{
		checkEvents(window);
		if (backButtonPressed) return;

		numberOfArrayAccesses += 2;
		output.at(i).setFillColor(sf::Color::Red);
		swap(rods.at(i), output.at(i));
		auto pos2 = output.at(i).getPosition();
		rods.at(i).setPosition(pos2);
		draw(window);
		wait(window, delay);
		rods.at(i).setFillColor(sf::Color::White);
	}
}

bool RadixSort::sort(sf::RenderWindow &window, float delay)
{
	if (rods.size() > 1)
	{
		if (!sorted)
		{
			// Find the maximum number to know number of digits 
			++numberOfArrayAccesses;
			int max = rods.at(0).getSize().y;
			for (auto rect : rods)
			{
				checkEvents(window);
				if (backButtonPressed) return false;

				++numberOfArrayAccesses;
				if (rect.getSize().y > max)		
					max = rect.getSize().y;
			}

			// Do counting sort for every digit. Note that instead 
			// of passing digit number, exp is passed. exp is 10^i 
			// where i is current digit number 
			for (int exp = 1; max / exp > 0; exp *= 10)
				countSort(window, rods.size(), exp, delay);

			sorted = true;
			for (size_t i = 0; i < rods.size(); ++i)
				rods.at(i).setFillColor(sf::Color::Blue);
			printMessage(window, sf::Vector2f(20.0f, 10.0f), "Finished: " + getName());

			return sorted;
		}
	}
	return sorted;
}

string RadixSort::getName()
{
	return "Radix Sort";
}
