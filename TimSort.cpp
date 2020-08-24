#include "TimSort.h"

void TimSort::insertionSort(sf::RenderWindow &window, int left, int right, float delay)
{
	for (int i = left + 1; i <= right; i++)
	{
		checkEvents(window);
		if (backButtonPressed) return;

		++numberOfArrayAccesses;
		sf::RectangleShape temp = rods.at(i);
		int j = i - 1;
		++numberOfComparisons;
		numberOfArrayAccesses += 2;
		while (j >= left && rods.at(j).getSize().y > temp.getSize().y)
		{
			checkEvents(window);
			if (backButtonPressed) return;

			rods.at(j).setFillColor(sf::Color::Red);

			draw(window);
			wait(window, delay);

			numberOfArrayAccesses += 2;
			rods.at(j + 1).setSize(rods.at(j).getSize());
			rods.at(j).setFillColor(sf::Color::White);
			--j;
		}
		++numberOfArrayAccesses;
		//Insert the key back to the vector
		swap(rods.at(j + 1), temp);
		auto p1 = temp.getPosition();
		auto p2 = rods.at(j + 1).getPosition();
		temp.setPosition(p2);
		rods.at(j + 1).setPosition(p1);

		draw(window);
		wait(window, delay);
	}
}

void TimSort::merge(sf::RenderWindow &window, int l, int m, int r, float delay)
{
	if (m >= rods.size() - 1) m = r - 1;
	size_t i, j, k;
	size_t n1 = m - l + 1;
	int n2 = r - m;

	/* create temp vectors */
	vector<sf::RectangleShape> L(n1), R(n2);

	/* Copy data to temp vectors L and R */
	i = 0;
	j = 0;
	for (;;)
	{
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

bool TimSort::sort(sf::RenderWindow &window, float delay)
{
	if (rods.size() > 1)
	{
		if (!sorted)
		{
			const int run = 32;
			// Sort individual subrods of size RUN 
			for (int i = 0; i < rods.size(); i += run)
				insertionSort(window, i, min((i + (run - 1)), (int)(rods.size() - 1)), delay);

			// start merging from size RUN. It will merge 
			// to form size rods.size() / 4,
			// then (rods.size() / 4) * 2,
			// (rods.size() / 4) * 3 and so on .... 
			for (int size = run; size < rods.size(); size = 2 * size)
			{
				// pick starting point of left sub rods. We 
				// are going to merge rods[left..left+size-1] 
				// and rods[left+size, left+2*size-1] 
				// After every merge, we increase left by 2*size 
				for (int left = 0; left < rods.size(); left += 2 * size)
				{
					// find ending point of left sub rods 
					// mid+1 is starting point of right sub rods 
					int mid = left + size - 1;
					int right = min((left + 2 * size - 1), (int)(rods.size() - 1));

					// merge sub rods rods[left.....mid] & 
					// rods[mid+1....right] 
					merge(window, left, mid, right, delay);
				}
			}
		}
		sorted = true;
		for (size_t i = 0; i < rods.size(); ++i)
			rods.at(i).setFillColor(sf::Color::Blue);
		printMessage(window, sf::Vector2f(20.0f, 10.0f), "Finished: " + getName());

		return sorted;
	}
	return sorted;
}

string TimSort::getName()
{
	return "Tim Sort";
}
