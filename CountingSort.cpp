#include "CountingSort.h"

bool CountingSort::sort(sf::RenderWindow &window, float delay)
{
	if (rods.size() > 1)
	{
		if (!sorted)
		{
			//Find max
			int max = rods.at(0).getSize().y;
			++numberOfArrayAccesses;
			for (auto rect : rods)
			{
				checkEvents(window);
				if (backButtonPressed) return false;

				++numberOfComparisons;
				++numberOfArrayAccesses;
				if (rect.getSize().y > max)
				{
					++numberOfArrayAccesses;
					max = rect.getSize().y;
				}
			}

			vector<int> count(max + 1);
			vector<sf::RectangleShape> output(rods.size());

			for (int i = 0; i < rods.size(); ++i)
			{
				checkEvents(window);
				if (backButtonPressed) return false;

				++numberOfArrayAccesses;
				count.at((rods.at(i).getSize().y))++;
				rods.at(i).setFillColor(sf::Color::Red);
				draw(window);
				wait(window, delay);
				rods.at(i).setFillColor(sf::Color::White);
			}

			for (int i = 1; i < count.size(); ++i)
			{
				checkEvents(window);
				if (backButtonPressed) return false;

				numberOfArrayAccesses += 2;
				count.at(i) += count.at(i - 1);
				if (i < rods.size())
				{
					rods.at(i).setFillColor(sf::Color::Red);
					rods.at(i - 1).setFillColor(sf::Color::Red);
					draw(window);
					wait(window, delay);
				}

				if (i < rods.size())
				{
					rods.at(i).setFillColor(sf::Color::White);
					rods.at(i - 1).setFillColor(sf::Color::White);
				}
			}

			for (int i = rods.size() - 1; i >= 0; --i)
			{
				checkEvents(window);
				if (backButtonPressed) return false;

				numberOfArrayAccesses += 3;
				output.at(count.at(rods.at(i).getSize().y) - 1) = rods.at(i);
				output.at(count.at(rods.at(i).getSize().y) - 1).setPosition(rods.at(i).getPosition());
				count.at(rods.at(i).getSize().y)--;
				rods.at(i).setFillColor(sf::Color::Red);
				draw(window);
				wait(window, delay);
				rods.at(i).setFillColor(sf::Color::White);
			}

			for (int i = 0; i < rods.size(); ++i)
			{
				checkEvents(window);
				if (backButtonPressed) return false;

				numberOfArrayAccesses += 2;

				swap(rods.at(i), output.at(i));
				auto p1 = rods.at(i).getPosition();
				auto p2 = output.at(i).getPosition();
				rods.at(i).setPosition(p2);
				output.at(i).setPosition(p1);

				rods.at(i).setFillColor(sf::Color::Blue);
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

string CountingSort::getName()
{
	return "Counting Sort";
}
