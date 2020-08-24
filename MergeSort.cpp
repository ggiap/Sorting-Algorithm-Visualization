#include "MergeSort.h"
#include <algorithm>

// Merges two subvectors of rods. 
// First subvector is rods[l..m] 
// Second subvector is rods[m+1..r] 
void MergeSort::merge(sf::RenderWindow &window, size_t l, size_t m, size_t r, float delay)
{
	size_t i, j, k;
	size_t n1 = m - l + 1;
	size_t n2 = r - m;

	/* create temp vectors */
	vector<sf::RectangleShape> L(n1), R(n2);
	
	/* Copy data to temp vectors L and R */
	i = 0;
	j = 0;
	for (;;)
	{
		checkEvents(window);
		if (backButtonPressed) return;

		if (i < n1)
		{
			numberOfArrayAccesses += 2;
			rods.at(l + i).setFillColor(sf::Color::Red);
			L.at(i) = rods.at(l + i);
			L.at(i).setPosition(rods.at(l + i).getPosition());		
			++i;
		}
		if (j < n2)
		{
			numberOfArrayAccesses += 2;
			rods.at(m + j + 1).setFillColor(sf::Color::Red);
			R.at(j) = rods.at(m + 1 + j);
			R.at(j).setPosition(rods.at(m + 1 + j).getPosition());		
			++j;
		}
		rods.at(l).setFillColor(sf::Color::Green);
		rods.at(m + 1).setFillColor(sf::Color::Cyan);
		rods.at(r).setFillColor(sf::Color::Green);
		draw(window);
		wait(window, delay);
		rods.at(l + i - 1).setFillColor(sf::Color::White);
		rods.at(m + j).setFillColor(sf::Color::White);
		if (!(i < n1) && !(j < n2))
			break;
	}
	/* Merge the temp vectors back into rods[l..r]*/
	i = 0; // Initial index of first subvector 
	j = 0; // Initial index of second subvector 
	k = l; // Initial index of merged subvector 
	while (i < n1 && j < n2)
	{
		checkEvents(window);
		if (backButtonPressed) return;
		//Wait
		//wait(window, 0.3f);
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

	/* Copy the remaining elements of vector L, if there
	   are any */
	while (i < n1)
	{
		checkEvents(window);
		if (backButtonPressed) return;

		numberOfArrayAccesses += 2;
		swap(rods.at(k), L.at(i));
		rods.at(k).setPosition(L.at(i).getPosition());
		rods.at(k).setFillColor(sf::Color::White);
		i++;
		k++;
	}

	/* Copy the remaining elements of vector R, if there
	   are any */
	while (j < n2)
	{
		checkEvents(window);
		if (backButtonPressed) return;

		numberOfArrayAccesses += 2;
		swap(rods.at(k), R.at(j));
		rods.at(k).setPosition(R.at(j).getPosition());
		rods.at(k).setFillColor(sf::Color::White);
		j++;
		k++;
	}
	rods.at(l).setFillColor(sf::Color::White);
	rods.at(r).setFillColor(sf::Color::White);
}

void MergeSort::mergeSort(sf::RenderWindow &window, size_t l, size_t r, float delay)
{
	/* l is for left index and r is right index of the
	   sub-subvector of rods to be sorted */
	if (l < r)
	{
		// Same as (l+r)/2, but avoids overflow for 
		// large l and r 
		size_t m = (l + r) / 2;

		checkEvents(window);
		if (backButtonPressed) return;

		// Sort first and second halves 
		mergeSort(window, l, m, delay);
		mergeSort(window, m + 1, r, delay);

		merge(window, l, m, r, delay);
	}
}

bool MergeSort::sort(sf::RenderWindow &window, float delay)
{
	if (rods.size() > 1)
	{
		if (!sorted)
		{
			mergeSort(window, 0, rods.size() - 1, delay);
			for (size_t i = 0; i < rods.size(); ++i)
			{
				rods.at(i).setFillColor(sf::Color::Blue);
			}
			sorted = true;
			printMessage(window, sf::Vector2f(20.0f, 10.0f), "Finished: " + getName());

			return sorted;
		}	
	}
	return sorted;
}


string MergeSort::getName()
{
	return "MergeSort";
}
