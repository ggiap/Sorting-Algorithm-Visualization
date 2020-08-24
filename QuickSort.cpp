#include "QuickSort.h"

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
   vector, and places all smaller (smaller than pivot)
   elements to the left of pivot and all greater elements
   to the right of pivot */
int QuickSort::partition(sf::RenderWindow &window, int left, int right, float delay)
{
	++numberOfArrayAccesses;
	auto pivot = rods.at(right);    // pivot element
	int i = (left - 1);  // Index of smaller element

	rods.at(right).setFillColor(sf::Color(255, 150, 0));

	for (int j = left; j <= right - 1; j++)
	{
		checkEvents(window);
		if (backButtonPressed) return false;

		/* If current element is smaller than or 
		   equal to pivot */
		++numberOfComparisons;
		numberOfArrayAccesses += 2;
		if (rods.at(j).getSize().y <= pivot.getSize().y)
		{
			i++;    // increment index of smaller element 
			rods.at(i).setFillColor(sf::Color::Red);
			rods.at(j).setFillColor(sf::Color::Red);
			numberOfArrayAccesses += 2;
			swap(rods.at(i), rods.at(j));	
			auto pos1 = rods.at(i).getPosition();
			auto pos2 = rods.at(j).getPosition();
			rods.at(i).setPosition(pos2);
			rods.at(j).setPosition(pos1);
		}
		draw(window);
		wait(window, delay);
		if (i >= 0)
			rods.at(i).setFillColor(sf::Color::White);
		rods.at(j).setFillColor(sf::Color::White);
	}
	rods.at(right).setFillColor(sf::Color::White);

	numberOfArrayAccesses += 2;
	swap(rods.at(i + 1), rods.at(right));
	auto pos1 = rods.at(i + 1).getPosition();
	auto pos2 = rods.at(right).getPosition();
	rods.at(i + 1).setPosition(pos2);
	rods.at(right).setPosition(pos1);

	return (i + 1);
}

/* The main function that implements QuickSort
  left  --> Starting index,
  right  --> Ending index */
void QuickSort::quickSort(sf::RenderWindow &window, int left, int right, float delay)
{
	if (backButtonPressed) return;

	if (left < right)
	{
		/* pi is partitioning index*/
		int pi = partition(window, left, right, delay);

		/* Separately sort elements before 
		   partition and after partition */
		quickSort(window, left, pi - 1, delay);
		for (size_t i = 0; i < pi; ++i)
		{
			rods.at(i).setFillColor(sf::Color::Blue);
		}
		quickSort(window, pi + 1, right, delay);
	}

}

bool QuickSort::sort(sf::RenderWindow &window, float delay)
{
	if (rods.size() > 1)
	{
		if (!sorted)
		{
			if (!iterative)
				quickSort(window, 0, rods.size() - 1, delay);
			else
				quickSortIterative(window, 0, rods.size() - 1, delay);

			for (size_t i = 0; i < rods.size(); ++i)
				rods.at(i).setFillColor(sf::Color::Blue);
		}
		sorted = true;

		printMessage(window, sf::Vector2f(20.0f, 10.0f), "Finished: " + getName());

		return sorted;
	}
	else
		return sorted;
}

string QuickSort::getName()
{
	return "Quick Sort";
}

/*	l-- > Starting index,
	h-- > Ending index */
void QuickSort::quickSortIterative(sf::RenderWindow &window, int l, int h, float delay)
{
	// Create an auxiliary stack 
	vector<sf::RectangleShape> stack(h - l + 1);

	// initialize top of stack 
	int top = -1;

	numberOfArrayAccesses += 4;
	// push initial values of l and h to stack 
	stack.at(++top).setSize(sf::Vector2f(rods.at(top).getSize().x, l));
	stack.at(++top).setSize(sf::Vector2f(rods.at(top).getSize().x, h));

	// Keep popping from stack while is not empty 
	while (top >= 0)
	{
		if (backButtonPressed) return;

		numberOfArrayAccesses += 2;
		// Pop h and l 
		h = stack.at(top--).getSize().y;
		l = stack.at(top--).getSize().y;
		
		// Set pivot element at its correct position 
		// in sorted array 
		int p = iterativePartition(window, l, h, delay);
		
		// If there are elements on left side of pivot, 
		// then push left side to stack 
		if (p - 1 > l)
		{
			numberOfArrayAccesses += 4;
			stack.at(++top).setSize(sf::Vector2f(rods.at(top).getSize().x, l));
			stack.at(++top).setSize(sf::Vector2f(rods.at(top).getSize().x, p - 1));
		}

		// If there are elements on right side of pivot, 
		// then push right side to stack 
		if (p + 1 < h)
		{
			numberOfArrayAccesses += 4;
			stack.at(++top).setSize(sf::Vector2f(rods.at(top).getSize().x, p + 1));
			stack.at(++top).setSize(sf::Vector2f(rods.at(top).getSize().x, h));
		}

		draw(window);
		wait(window, delay);
	}
}

int QuickSort::iterativePartition(sf::RenderWindow &window, int left, int right, float delay)
{
	++numberOfArrayAccesses;
	auto pivot = rods.at(right);    // pivot element
	int i = (left - 1);  // Index of smaller element

	if (right != rods.size() - 1)
		for (int x = right; x < rods.size(); ++x)
			rods.at(x).setFillColor(sf::Color::Blue);

	if (i >= 0)
		rods.at(i).setFillColor(sf::Color::Green);
	rods.at(right).setFillColor(sf::Color::Green);
	for (int j = left; j <= right - 1; j++)
	{
		checkEvents(window);
		if (backButtonPressed) return false;
		
		/* If current element is smaller than or
		   equal to pivot */
		++numberOfComparisons;
		numberOfArrayAccesses += 2;
		if (rods.at(j).getSize().y <= pivot.getSize().y)
		{
			i++;    // increment index of smaller element 
			rods.at(i).setFillColor(sf::Color::Red);
			rods.at(j).setFillColor(sf::Color::Red);
			numberOfArrayAccesses += 2;
			swap(rods.at(i), rods.at(j));
			auto pos1 = rods.at(i).getPosition();
			auto pos2 = rods.at(j).getPosition();
			rods.at(i).setPosition(pos2);
			rods.at(j).setPosition(pos1);
		}
		draw(window);
		wait(window, delay);
		if (i >= 0)
			rods.at(i).setFillColor(sf::Color::White);
		rods.at(j).setFillColor(sf::Color::White);
	}
	rods.at(right).setFillColor(sf::Color::White);

	numberOfArrayAccesses += 2;
	swap(rods.at(i + 1), rods.at(right));
	auto pos1 = rods.at(i + 1).getPosition();
	auto pos2 = rods.at(right).getPosition();
	rods.at(i + 1).setPosition(pos2);
	rods.at(right).setPosition(pos1);

	return (i + 1);
}
