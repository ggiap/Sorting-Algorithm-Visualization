#include "IntroSort.h"
#include <cmath>

void IntroSort::swapValues(int a, int b)
{
	numberOfArrayAccesses += 2;
	swap(rods.at(a), rods.at(b));
	auto pos1 = rods.at(a).getPosition();
	auto pos2 = rods.at(b).getPosition();
	rods.at(a).setPosition(pos2);
	rods.at(b).setPosition(pos1);
}

void IntroSort::insertionsort(sf::RenderWindow &window, int begin, int end, float delay)
{
	for (size_t i = begin; i < end; i++)
	{
		++numberOfArrayAccesses;
		sf::RectangleShape key = rods.at(i);
		signed j = i - 1;

		++numberOfComparisons;
		numberOfArrayAccesses += 2;
		while (j >= 0 && (rods.at(j).getSize().y > key.getSize().y))
		{
			checkEvents(window);
			if (backButtonPressed) return;

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
		swap(rods.at(j + 1), key);
		auto p1 = key.getPosition();
		auto p2 = rods.at(j + 1).getPosition();
		key.setPosition(p2);
		rods.at(j + 1).setPosition(p1);

		if ((i == 1) && (key.getSize().y == rods.at(i).getSize().y))
			rods.at(0).setFillColor(sf::Color::Blue);

		draw(window);
		wait(window, delay);
	}
}

int IntroSort::partition(sf::RenderWindow &window, int begin, int end, float delay)
{
	++numberOfArrayAccesses;
	sf::RectangleShape pivot = rods.at(end);
	int i = (begin - 1);

	rods.at(end).setFillColor(sf::Color(255, 150, 0));

	for (int j = begin; j <= end - 1; j++)
	{
		checkEvents(window);
		if (backButtonPressed) return false;

		++numberOfComparisons;
		numberOfArrayAccesses += 2;
		if (rods.at(j).getSize().y <= pivot.getSize().y)
		{
			i++;
			rods.at(i).setFillColor(sf::Color::Red);
			rods.at(j).setFillColor(sf::Color::Red);
			swapValues(i, j);
			draw(window);
			wait(window, delay);
			if (i >= 0)
				rods.at(i).setFillColor(sf::Color::White);
			rods.at(j).setFillColor(sf::Color::White);
		}
	}
	rods.at(end).setFillColor(sf::Color::White);
	swapValues(i + 1, begin);

	return (i + 1);
}

void IntroSort::merge(sf::RenderWindow &window, size_t begin, size_t mid, size_t end, float delay)
{
	size_t i, j, k;
	size_t n1 = mid - begin + 1;
	size_t n2 = end - mid;

	vector<sf::RectangleShape> L(n1), R(n2);

	i = 0;
	j = 0;
	for (;;)
	{
		if (i < n1)
		{
			numberOfArrayAccesses += 2;
			rods.at(begin + i).setFillColor(sf::Color::Red);
			L.at(i) = rods.at(begin + i);
			L.at(i).setPosition(rods.at(begin + i).getPosition());
			++i;
		}
		if (j < n2)
		{
			numberOfArrayAccesses += 2;
			rods.at(mid + j + 1).setFillColor(sf::Color::Red);
			R.at(j) = rods.at(mid + 1 + j);
			R.at(j).setPosition(rods.at(mid + 1 + j).getPosition());
			++j;
		}
		rods.at(begin).setFillColor(sf::Color::Green);
		rods.at(mid + 1).setFillColor(sf::Color::Cyan);
		rods.at(end).setFillColor(sf::Color::Green);
		draw(window);
		wait(window, delay);
		rods.at(begin + i - 1).setFillColor(sf::Color::White);
		rods.at(mid + j).setFillColor(sf::Color::White);
		if (!(i < n1) && !(j < n2))
			break;
	}
	i = 0;
	j = 0; 
	k = begin;
	while (i < n1 && j < n2)
	{
		checkEvents(window);
		if (backButtonPressed) return;

		++numberOfComparisons;
		numberOfArrayAccesses += 2;
		if (L.at(i).getSize().y <= R.at(j).getSize().y)
		{
			numberOfArrayAccesses += 2;
			swap(rods.at(k), L.at(i));
			rods.at(k).setPosition(L.at(i).getPosition());
			i++;
		}
		else
		{
			numberOfArrayAccesses += 2;
			swap(rods.at(k), R.at(j));
			rods.at(k).setPosition(R.at(j).getPosition());
			j++;
		}
		rods.at(k).setFillColor(sf::Color::White);
		draw(window);
		wait(window, delay);
		k++;
	}

	while (i < n1)
	{
		numberOfArrayAccesses += 2;
		swap(rods.at(k), L.at(i));
		rods.at(k).setPosition(L.at(i).getPosition());
		rods.at(k).setFillColor(sf::Color::White);
		i++;
		k++;
	}

	while (j < n2)
	{
		numberOfArrayAccesses += 2;
		swap(rods.at(k), R.at(j));
		rods.at(k).setPosition(R.at(j).getPosition());
		rods.at(k).setFillColor(sf::Color::White);
		j++;
		k++;
	}
	rods.at(begin).setFillColor(sf::Color::White);
	rods.at(end).setFillColor(sf::Color::White);
}

void IntroSort::mergesort(sf::RenderWindow &window, int begin, int end, float delay)
{
	if (begin < end)
	{
		size_t m = (begin + end) / 2;

		checkEvents(window);
		if (backButtonPressed) return;

		mergesort(window, begin, m, delay);
		mergesort(window, m + 1, end, delay);

		merge(window, begin, m, end, delay);
	}
}

int IntroSort::MedianOfThree(int a, int b, int c)
{
	if (rods.at(a).getSize().y < rods.at(b).getSize().y && rods.at(b).getSize().y < rods.at(c).getSize().y)
	{
		numberOfArrayAccesses += 4;
		numberOfComparisons += 2;
		return (b);
	}
	else if (rods.at(a).getSize().y < rods.at(c).getSize().y && rods.at(c).getSize().y <= rods.at(b).getSize().y)
	{
		numberOfArrayAccesses += 8;
		numberOfComparisons += 4;
		return (c);
	}
	else if (rods.at(b).getSize().y <= rods.at(a).getSize().y && rods.at(a).getSize().y < rods.at(c).getSize().y)
	{
		numberOfArrayAccesses += 12;
		numberOfComparisons += 6;
		return (a);
	}
	else if (rods.at(b).getSize().y < rods.at(c).getSize().y && rods.at(c).getSize().y <= rods.at(a).getSize().y)
	{
		numberOfArrayAccesses += 16;
		numberOfComparisons += 8;
		return (c);
	}
	else if (rods.at(c).getSize().y <= rods.at(a).getSize().y && rods.at(a).getSize().y < rods.at(b).getSize().y)
	{
		numberOfArrayAccesses += 20;
		numberOfComparisons += 10;
		return (a);
	}
	else if (rods.at(c).getSize().y <= rods.at(b).getSize().y && rods.at(b).getSize().y <= rods.at(c).getSize().y)
	{
		numberOfArrayAccesses += 24;
		numberOfComparisons += 12;
		return (b);
	}
	numberOfArrayAccesses += 24;
	numberOfComparisons += 12;
	return b;
}

void IntroSort::introsort(sf::RenderWindow &window, int begin, int end, int depthLimit, float delay)
{
	int size = end - begin;

	if (size < 16)
	{
		insertionsort(window, begin, end + 1, delay);
		return;
	}

	if (depthLimit == 0)
	{
		mergesort(window, begin, end, delay);
		for (size_t i = begin; i < end + 1; ++i)
		{
			rods.at(i).setFillColor(sf::Color::Blue);
		}
		return;
	}

	int pivot = MedianOfThree(begin, begin + size / 2, end);

	rods.at(begin).setFillColor(sf::Color::White);

	swapValues(pivot, end);

	checkEvents(window);
	if (backButtonPressed) return;

	int partitionPoint = partition(window, begin, end, delay);
	introsort(window, begin, partitionPoint, depthLimit - 1, delay);
	introsort(window, partitionPoint, end, depthLimit - 1, delay);
	return;
}

bool IntroSort::sort(sf::RenderWindow &window, float delay)
{
	if (rods.size() > 1)
	{
		if (!sorted)
		{
			//int depthLimit = 1.2 * log(rods.size());
			int depthLimit =  floor(log2(rods.size() / log2(2)));

			// Perform a recursive Introsort 
			introsort(window, 0, rods.size() - 1, depthLimit, delay);

			sorted = true;
			printMessage(window, sf::Vector2f(20.0f, 10.0f), "Finished: " + getName());

			return sorted;
		}
	}
	return sorted;
}

string IntroSort::getName()
{
	return "Introsort";
}