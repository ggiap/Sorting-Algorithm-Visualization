#include "HeapSort.h"

// To heapify a subtree rooted with node i which is 
// an index in rods[]. n is size of heap 
void HeapSort::heapify(sf::RenderWindow &window, int n, int i, float delay)
{
	checkEvents(window);
	if (backButtonPressed) return;

	int largest = i; // Initialize largest as root 
	int l = 2 * i + 1; // left = 2*i + 1 
	int r = 2 * i + 2; // right = 2*i + 2 

	++numberOfComparisons;
	numberOfArrayAccesses += 2;
	// If left child is larger than root 
	if (l < n && rods.at(l).getSize().y > rods.at(largest).getSize().y)
	{
		largest = l;
	}

	++numberOfComparisons;
	numberOfArrayAccesses += 2;
	// If right child is larger than largest so far 
	if (r < n && rods.at(r).getSize().y > rods.at(largest).getSize().y)
	{
		largest = r;
	}
	rods.at(largest).setFillColor(sf::Color::White);
	draw(window);
	wait(window, delay);

	// If largest is not root 
	if (largest != i)
	{
		numberOfArrayAccesses += 2;
		rods.at(largest).setFillColor(sf::Color::Red);
		swap(rods.at(i), rods.at(largest));
		auto p1 = rods.at(largest).getPosition();
		auto p2 = rods.at(i).getPosition();
		rods.at(largest).setPosition(p2);
		rods.at(i).setPosition(p1);

		// Recursively heapify the affected sub-tree 
		heapify(window, n, largest, delay);
		rods.at(i).setFillColor(sf::Color::White);
	}
}

bool HeapSort::sort(sf::RenderWindow &window, float delay)
{
	if (rods.size() > 1)
	{
		if (!sorted)
		{
			// Build heap (rearrange array) 
			for (int i = rods.size() / 2 - 1; i >= 0; i--)
				heapify(window, rods.size(), i, delay);

			// One by one extract an element from heap 
			for (int i = rods.size() - 1; i >= 0; i--)
			{
				rods.at(0).setFillColor(sf::Color::Blue);
				numberOfArrayAccesses += 2;
				// Move current root to end 
				swap(rods.at(0), rods.at(i));
				auto p1 = rods.at(0).getPosition();
				auto p2 = rods.at(i).getPosition();
				rods.at(0).setPosition(p2);
				rods.at(i).setPosition(p1);

				// call max heapify on the reduced heap 
				heapify(window, i, 0, delay);
			}
			sorted = true;
			rods.at(0).setFillColor(sf::Color::Blue);
			printMessage(window, sf::Vector2f(20.0f, 10.0f), "Finished: " + getName());

			return sorted;
		}
	}
	return sorted;
}

void HeapSort::iterativeHeapSort(sf::RenderWindow &window, float delay)
{
	if (rods.size() > 1)
	{
		if (!sorted)
		{
			size_t n = rods.size(), i = n / 2, parent, child;
			sf::RectangleShape t;

			for (;;) /* Loops until rods is sorted */
			{
				checkEvents(window);
				if (backButtonPressed) return;

				if (i > 0)/* First stage - Sorting the heap */
				{
					++numberOfArrayAccesses;
					i--;				/* Save its index to i */
					t = rods.at(i);		/* Save parent value to t */	
					t.setPosition(rods.at(i).getPosition());
				}
				else /* Second stage - Extracting elements in-place */
				{
					rods.at(0).setFillColor(sf::Color::Blue);			
					n--;				/* Make the new heap smaller */	
					if (n == 0)/* When the heap is empty, we are done */
					{
						rods.at(n + 1).setFillColor(sf::Color::Blue);
						break; 
					}
					++numberOfArrayAccesses;
					t = rods.at(n);     /* Save last value (it will be overwritten) */
					t.setPosition(rods.at(n).getPosition());
					numberOfArrayAccesses += 2;
					swap(rods.at(n), rods.at(0)); /* Save largest value at the end of rods */
					auto p1 = rods.at(0).getPosition();
					auto p2 = rods.at(n).getPosition();
					rods.at(0).setPosition(p2);
					rods.at(n).setPosition(p1);
				}
				parent = i;			/* We will start pushing down t from parent */
				child = i * 2 + 1;	/* parent's left child */

				rods.at(parent).setFillColor(sf::Color::Red);
				rods.at(child).setFillColor(sf::Color::Red);

				draw(window);
				wait(window, delay);
				/* Sift operation - pushing the value of t down the heap */
				while (child < n)
				{
					checkEvents(window);
					if (backButtonPressed) return;

					/* Check if there are more than one children
					 * and choose the largest child
					 */
					++numberOfComparisons;
					numberOfArrayAccesses += 2;
					if (child + 1 < n  &&  rods.at(child + 1).getSize().y > rods.at(child).getSize().y)
					{
						rods.at(child).setFillColor(sf::Color::White);
						child++; /* Choose the largest child */
					}
					++numberOfComparisons;
					++numberOfArrayAccesses;
					if (rods.at(child).getSize().y > t.getSize().y) /* If any child is bigger than the parent */
					{
						numberOfArrayAccesses += 2;
						swap(rods.at(parent), rods.at(child)); /* Move the largest child up */
						auto p1 = rods.at(parent).getPosition();
						auto p2 = rods.at(child).getPosition();
						rods.at(parent).setPosition(p2);
						rods.at(child).setPosition(p1);			
						parent = child; /* Move parent pointer to this child */
						child = parent * 2 + 1; /* Find the next child */						
					}
					else
					{
						break; /* t's place is found */
					}
					draw(window);
					wait(window, delay);
					rods.at(i).setFillColor(sf::Color::White);	
				}
				if (child < n)
					rods.at(child).setFillColor(sf::Color::White);
				numberOfArrayAccesses += 2;
				swap(rods.at(parent), t); /* We save t in the heap */
				auto p1 = rods.at(parent).getPosition();
				auto p2 = t.getPosition();
				rods.at(parent).setPosition(p2);
				t.setPosition(p1);

				draw(window);
				wait(window, delay);
			}
			sorted = true;

			printMessage(window, sf::Vector2f(20.0f, 10.0f), "Finished: " + getName());
		}
	}
}


string HeapSort::getName()
{
	return "Heap Sort";
}
