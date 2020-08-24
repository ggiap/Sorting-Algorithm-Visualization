#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include <string>

#include "BubbleSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "HeapSort.h"
#include "ShellSort.h"
#include "GnomeSort.h"
#include "CocktailSort.h"
#include "CountingSort.h"
#include "PancakeSort.h"
#include "CombSort.h"
#include "TimSort.h"
#include "RadixSort.h"
#include "IntroSort.h"
#include "Button.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML", sf::Style::Titlebar | sf::Style::Close);
	int numberOfRods = 0;
	float delayTime = 0.0f;

	sf::Font textFont;
	if (!textFont.loadFromFile("../Font/ARJULIAN.ttf"))
		cerr << "Can't load font!" << endl;

	sf::RectangleShape textFieldBorder(sf::Vector2f(43.0f, 20.0f));
	textFieldBorder.setPosition(sf::Vector2f(410.0f, 3.0f));
	textFieldBorder.setFillColor(sf::Color::Transparent);
	textFieldBorder.setOutlineColor(sf::Color(150, 150, 150));
	textFieldBorder.setOutlineThickness(1);
	sf::Text numberOfRodsText;
	numberOfRodsText.setCharacterSize(20);
	numberOfRodsText.setPosition(sf::Vector2f(413.5f, 0.0f));
	numberOfRodsText.setFont(textFont);
	numberOfRodsText.setString(to_string(numberOfRods));

	sf::Text prompt;
	prompt.setString("Choose the number of rods(up to 800):");
	prompt.setCharacterSize(20);
	prompt.setFont(textFont);

	//Up and Down arrows
	sf::Texture arrowTexture;
	arrowTexture.loadFromFile("../Images/upArrow.png");
	sf::Sprite upArrowImage(arrowTexture);
	upArrowImage.setPosition(sf::Vector2f(380.0f, 1.0f));
	sf::Sprite downArrowImage(arrowTexture);
	downArrowImage.setRotation(180);
	downArrowImage.setPosition(sf::Vector2f(483.0f, 27.0f));
	upArrowImage.setScale(0.05f,0.05f);
	downArrowImage.setScale(0.05f, 0.05f);

	sf::RectangleShape textFieldBorder2(sf::Vector2f(80.0f, 20.0f));
	textFieldBorder2.setPosition(sf::Vector2f(610.0f, 3.0f));
	textFieldBorder2.setFillColor(sf::Color::Transparent);
	textFieldBorder2.setOutlineColor(sf::Color(150, 150, 150));
	textFieldBorder2.setOutlineThickness(1);
	sf::Text delayTimeText;
	delayTimeText.setCharacterSize(20);
	delayTimeText.setPosition(sf::Vector2f(613.5f, 0.0f));
	delayTimeText.setFont(textFont);
	delayTimeText.setString(to_string(numberOfRods));

	sf::Text delayTimePrompt;
	delayTimePrompt.setString("Delay:");
	delayTimePrompt.setCharacterSize(20);
	delayTimePrompt.setFont(textFont);
	delayTimePrompt.setPosition(sf::Vector2f(540.0f, 0.0f));

	BubbleSort bubbleSort;
	InsertionSort insertionSort;
	SelectionSort selectionSort;
	MergeSort mergeSort;
	QuickSort quickSort;
	HeapSort heapSort;
	ShellSort shellSort;
	GnomeSort gnomeSort;
	CocktailSort cocktailSort;
	CountingSort countingSort;
	PancakeSort pancakeSort;
	CombSort combSort;
	TimSort timSort;
	RadixSort radixSort;
	IntroSort introSort;

	//Menu Buttons
	auto offsetX = window.getSize().x / 3;
	sf::Vector2f buttonSize((window.getSize().x / 3.0f) - 5, (window.getSize().y / 20.0f));
	auto buttonColor = sf::Color(150, 150, 150, 255);
	Button bubbleSortButton;
	Button insertionSortButton;
	Button selectionSortButton;
	Button mergeSortButton;
	Button quickSortButton;
	Button iterativeQuickSortButton;
	Button heapSortButton;
	Button shellSortButton;
	Button gnomeSortButton;
	Button cocktailSortButton;
	Button countingSortButton;
	Button pancakeSortButton;
	Button combSortButton;
	Button iterativeHeapSortButton;
	Button binaryInsertionSortButton;
	Button timSortButton;
	Button radixSortButton;
	Button introSortButton;
	bubbleSortButton.buttonConfig			(buttonSize, sf::Vector2f(offsetX * 0, 35.0f), buttonColor,"Bubble Sort");
	insertionSortButton.buttonConfig		(buttonSize, sf::Vector2f(offsetX * 1, 35.0f), buttonColor, "Insertion Sort");
	selectionSortButton.buttonConfig		(buttonSize, sf::Vector2f(offsetX * 2, 35.0f), buttonColor, "Selection Sort");
	mergeSortButton.buttonConfig			(buttonSize, sf::Vector2f(offsetX * 0, 70.0f), buttonColor, "Merge Sort");
	quickSortButton.buttonConfig			(buttonSize, sf::Vector2f(offsetX * 1, 70.0f), buttonColor, "Quick Sort");
	iterativeQuickSortButton.buttonConfig	(buttonSize, sf::Vector2f(offsetX * 2, 70.0f), buttonColor, "Iterative Quick Sort");
	heapSortButton.buttonConfig				(buttonSize, sf::Vector2f(offsetX * 0, 105.0f), buttonColor, "Heap Sort");
	shellSortButton.buttonConfig			(buttonSize, sf::Vector2f(offsetX * 1, 105.0f), buttonColor, "Shell Sort");
	gnomeSortButton.buttonConfig			(buttonSize, sf::Vector2f(offsetX * 2, 105.0f), buttonColor, "Gnome Sort");
	cocktailSortButton.buttonConfig			(buttonSize, sf::Vector2f(offsetX * 0, 140.0f), buttonColor, "Cocktail Sort");
	countingSortButton.buttonConfig			(buttonSize, sf::Vector2f(offsetX * 1, 140.0f), buttonColor, "Counting Sort");
	pancakeSortButton.buttonConfig			(buttonSize, sf::Vector2f(offsetX * 2, 140.0f), buttonColor, "Pancake Sort");
	combSortButton.buttonConfig				(buttonSize, sf::Vector2f(offsetX * 0, 175.0f), buttonColor, "Comb Sort");
	iterativeHeapSortButton.buttonConfig	(buttonSize, sf::Vector2f(offsetX * 1, 175.0f), buttonColor, "Iterative Heap Sort");
	binaryInsertionSortButton.buttonConfig	(buttonSize, sf::Vector2f(offsetX * 2, 175.0f), buttonColor, "Binary Insertion Sort");
	timSortButton.buttonConfig				(buttonSize, sf::Vector2f(offsetX * 0, 210.0f), buttonColor, "Tim Sort");
	radixSortButton.buttonConfig			(buttonSize, sf::Vector2f(offsetX * 1, 210.0f), buttonColor, "Radix Sort");
	introSortButton.buttonConfig			(buttonSize, sf::Vector2f(offsetX * 2, 210.0f), buttonColor, "Modified Introsort");


	bool delayFieldIsSelected = false;
	string stringBuffer1;
	string stringBuffer2;
	sf::Event event;
	//Main loop
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			// end the program
			if (event.type == sf::Event::Closed)
			{			
				window.close();
			}	
			//Track mouse movement
			if (event.type == sf::Event::MouseMoved)
			{
				sf::Vector2i mousePos = sf::Mouse::getPosition(window);
				sf::Vector2f mousePosf(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
				if (bubbleSortButton.getRect().getGlobalBounds().contains(mousePosf))
				{
					bubbleSortButton.getRect().setFillColor(sf::Color(150, 150, 150, 155));
				}
				else
				{
					bubbleSortButton.getRect().setFillColor(sf::Color(150, 150, 150, 255));
				}
				if (insertionSortButton.getRect().getGlobalBounds().contains(mousePosf))
				{
					insertionSortButton.getRect().setFillColor(sf::Color(150, 150, 150, 155));
				}
				else
				{
					insertionSortButton.getRect().setFillColor(sf::Color(150, 150, 150, 255));
				}
				if (selectionSortButton.getRect().getGlobalBounds().contains(mousePosf))
				{
					selectionSortButton.getRect().setFillColor(sf::Color(150, 150, 150, 155));
				}
				else
				{
					selectionSortButton.getRect().setFillColor(sf::Color(150, 150, 150, 255));
				}
				if (mergeSortButton.getRect().getGlobalBounds().contains(mousePosf))
				{
					mergeSortButton.getRect().setFillColor(sf::Color(150, 150, 150, 155));
				}
				else
				{
					mergeSortButton.getRect().setFillColor(sf::Color(150, 150, 150, 255));
				}
				if (quickSortButton.getRect().getGlobalBounds().contains(mousePosf))
				{
					quickSortButton.getRect().setFillColor(sf::Color(150, 150, 150, 155));
				}
				else
				{
					quickSortButton.getRect().setFillColor(sf::Color(150, 150, 150, 255));
				}
				if (iterativeQuickSortButton.getRect().getGlobalBounds().contains(mousePosf))
				{
					iterativeQuickSortButton.getRect().setFillColor(sf::Color(150, 150, 150, 155));
				}
				else
				{
					iterativeQuickSortButton.getRect().setFillColor(sf::Color(150, 150, 150, 255));
				}
				if (heapSortButton.getRect().getGlobalBounds().contains(mousePosf))
				{
					heapSortButton.getRect().setFillColor(sf::Color(150, 150, 150, 155));
				}
				else
				{
					heapSortButton.getRect().setFillColor(sf::Color(150, 150, 150, 255));
				}
				if (shellSortButton.getRect().getGlobalBounds().contains(mousePosf))
				{
					shellSortButton.getRect().setFillColor(sf::Color(150, 150, 150, 155));
				}
				else
				{
					shellSortButton.getRect().setFillColor(sf::Color(150, 150, 150, 255));
				}
				if (gnomeSortButton.getRect().getGlobalBounds().contains(mousePosf))
				{
					gnomeSortButton.getRect().setFillColor(sf::Color(150, 150, 150, 155));
				}
				else
				{
					gnomeSortButton.getRect().setFillColor(sf::Color(150, 150, 150, 255));
				}
				if (cocktailSortButton.getRect().getGlobalBounds().contains(mousePosf))
				{
					cocktailSortButton.getRect().setFillColor(sf::Color(150, 150, 150, 155));
				}
				else
				{
					cocktailSortButton.getRect().setFillColor(sf::Color(150, 150, 150, 255));
				}
				if (countingSortButton.getRect().getGlobalBounds().contains(mousePosf))
				{
					countingSortButton.getRect().setFillColor(sf::Color(150, 150, 150, 155));
				}
				else
				{
					countingSortButton.getRect().setFillColor(sf::Color(150, 150, 150, 255));
				}
				if (pancakeSortButton.getRect().getGlobalBounds().contains(mousePosf))
				{
					pancakeSortButton.getRect().setFillColor(sf::Color(150, 150, 150, 155));
				}
				else
				{
					pancakeSortButton.getRect().setFillColor(sf::Color(150, 150, 150, 255));
				}
				if (combSortButton.getRect().getGlobalBounds().contains(mousePosf))
				{
					combSortButton.getRect().setFillColor(sf::Color(150, 150, 150, 155));
				}
				else
				{
					combSortButton.getRect().setFillColor(sf::Color(150, 150, 150, 255));
				}
				if (iterativeHeapSortButton.getRect().getGlobalBounds().contains(mousePosf))
				{
					iterativeHeapSortButton.getRect().setFillColor(sf::Color(150, 150, 150, 155));
				}
				else
				{
					iterativeHeapSortButton.getRect().setFillColor(sf::Color(150, 150, 150, 255));
				}
				if (binaryInsertionSortButton.getRect().getGlobalBounds().contains(mousePosf))
				{
					binaryInsertionSortButton.getRect().setFillColor(sf::Color(150, 150, 150, 155));
				}
				else
				{
					binaryInsertionSortButton.getRect().setFillColor(sf::Color(150, 150, 150, 255));
				}
				if (timSortButton.getRect().getGlobalBounds().contains(mousePosf))
				{
					timSortButton.getRect().setFillColor(sf::Color(150, 150, 150, 155));
				}
				else
				{
					timSortButton.getRect().setFillColor(sf::Color(150, 150, 150, 255));
				}
				if (radixSortButton.getRect().getGlobalBounds().contains(mousePosf))
				{
					radixSortButton.getRect().setFillColor(sf::Color(150, 150, 150, 155));
				}
				else
				{
					radixSortButton.getRect().setFillColor(sf::Color(150, 150, 150, 255));
				}
				if (introSortButton.getRect().getGlobalBounds().contains(mousePosf))
				{
					introSortButton.getRect().setFillColor(sf::Color(150, 150, 150, 155));
				}
				else
				{
					introSortButton.getRect().setFillColor(sf::Color(150, 150, 150, 255));
				}
			}
			//Check mouse clicks
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					sf::Vector2i mousePos = sf::Mouse::getPosition(window);
					sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
					if (textFieldBorder2.getGlobalBounds().contains(mousePosF))
					{
						textFieldBorder.setOutlineColor(sf::Color(150,150,150));
						delayFieldIsSelected = true;
						textFieldBorder2.setOutlineColor(sf::Color::Green);
					}
					else if (textFieldBorder.getGlobalBounds().contains(mousePosF))
					{
						textFieldBorder2.setOutlineColor(sf::Color(150, 150, 150));
						delayFieldIsSelected = false;
						textFieldBorder.setOutlineColor(sf::Color::Green);
					}
					if (upArrowImage.getGlobalBounds().contains(mousePosF))
					{
						if (numberOfRods < 800)
						{
							++numberOfRods;
							numberOfRodsText.setString(to_string(numberOfRods));
						}
					}
					if (downArrowImage.getGlobalBounds().contains(mousePosF))
					{
						if (numberOfRods > 0)
						{
							--numberOfRods;
							numberOfRodsText.setString(to_string(numberOfRods));
						}
					}
					if (bubbleSortButton.getRect().getGlobalBounds().contains(mousePosF))
					{
						bubbleSort.createCanvas(window, numberOfRods);
						bubbleSort.sort(window, delayTime);
					}
					if (insertionSortButton.getRect().getGlobalBounds().contains(mousePosF))
					{
						insertionSort.createCanvas(window, numberOfRods);
						insertionSort.sort(window, delayTime);
					}
					if (selectionSortButton.getRect().getGlobalBounds().contains(mousePosF))
					{
						selectionSort.createCanvas(window, numberOfRods);
						selectionSort.sort(window, delayTime);
					}
					if (mergeSortButton.getRect().getGlobalBounds().contains(mousePosF))
					{
						mergeSort.createCanvas(window, numberOfRods);
						mergeSort.sort(window, delayTime);
					}
					if (quickSortButton.getRect().getGlobalBounds().contains(mousePosF))
					{
						quickSort.createCanvas(window, numberOfRods);
						quickSort.iterative = false;
						quickSort.sort(window, delayTime);
					}
					if (iterativeQuickSortButton.getRect().getGlobalBounds().contains(mousePosF))
					{
						quickSort.createCanvas(window, numberOfRods);
						quickSort.iterative = true;
						quickSort.sort(window, delayTime);
					}
					if (heapSortButton.getRect().getGlobalBounds().contains(mousePosF))
					{
						heapSort.createCanvas(window, numberOfRods);
						heapSort.sort(window, delayTime);
					}
					if (shellSortButton.getRect().getGlobalBounds().contains(mousePosF))
					{
						shellSort.createCanvas(window, numberOfRods);
						shellSort.sort(window, delayTime);
					}
					if (gnomeSortButton.getRect().getGlobalBounds().contains(mousePosF))
					{
						gnomeSort.createCanvas(window, numberOfRods);
						gnomeSort.sort(window, delayTime);
					}
					if (cocktailSortButton.getRect().getGlobalBounds().contains(mousePosF))
					{
						cocktailSort.createCanvas(window, numberOfRods);
						cocktailSort.sort(window, delayTime);
					}
					if (countingSortButton.getRect().getGlobalBounds().contains(mousePosF))
					{
						countingSort.createCanvas(window, numberOfRods);
						countingSort.sort(window, delayTime);
					}
					if (pancakeSortButton.getRect().getGlobalBounds().contains(mousePosF))
					{
						pancakeSort.createCanvas(window, numberOfRods);
						pancakeSort.sort(window, delayTime);
					}
					if (combSortButton.getRect().getGlobalBounds().contains(mousePosF))
					{
						combSort.createCanvas(window, numberOfRods);
						combSort.sort(window, delayTime);
					}
					if (iterativeHeapSortButton.getRect().getGlobalBounds().contains(mousePosF))
					{
						heapSort.createCanvas(window, numberOfRods);
						heapSort.iterativeHeapSort(window, delayTime);
					}
					if (binaryInsertionSortButton.getRect().getGlobalBounds().contains(mousePosF))
					{
						insertionSort.createCanvas(window, numberOfRods);
						insertionSort.binaryInsertionSort(window, delayTime);
					}
					if (timSortButton.getRect().getGlobalBounds().contains(mousePosF))
					{
						timSort.createCanvas(window, numberOfRods);
						timSort.sort(window, delayTime);
					}
					if (radixSortButton.getRect().getGlobalBounds().contains(mousePosF))
					{
						radixSort.createCanvas(window, numberOfRods);
						radixSort.sort(window, delayTime);
					}
					if (introSortButton.getRect().getGlobalBounds().contains(mousePosF))
					{
						introSort.createCanvas(window, numberOfRods);
						introSort.sort(window, delayTime);
					}
				}
			}
			//Receive keyboard input
			if (event.type == sf::Event::TextEntered)
			{
				if (delayFieldIsSelected == false)
				{
					if (event.text.unicode >= 48 && event.text.unicode <= 57)
					{
						stringBuffer1 += event.text.unicode;
						if (stoi(stringBuffer1) > 800)
							stringBuffer1 = "800";
						numberOfRodsText.setString(stringBuffer1);
					}

					if (stringBuffer1.length() > 3)
						stringBuffer1.clear();

					if (stringBuffer1.length() > 0 && event.text.unicode == 8)
					{
						stringBuffer1.pop_back();
						numberOfRodsText.setString(stringBuffer1);
					}
					if (!stringBuffer1.empty())
						numberOfRods = stoi(stringBuffer1);
					else
					{
						numberOfRods = 0;
						numberOfRodsText.setString("0");
					}
				}
				else
				{
					if ((event.text.unicode >= 48 && event.text.unicode <= 57) || event.text.unicode == 46)
					{
						stringBuffer2 += event.text.unicode;
						if (stoi(stringBuffer2) > 10000)
							stringBuffer2 = "10000";
						delayTimeText.setString(stringBuffer2 + "ms");
					}

					if (stringBuffer2.length() > 5)
						stringBuffer2.clear();

					if (stringBuffer2.length() > 0 && event.text.unicode == 8)
					{
						stringBuffer2.pop_back();
						delayTimeText.setString(stringBuffer2 + "ms");
					}

					if (!stringBuffer2.empty())
						delayTime = stof(stringBuffer2) / 1000.0f;
					else
					{
						delayTime = 0.0f;
						delayTimeText.setString("0ms");
					}
				}
			}
		}
		window.clear();
		window.draw(prompt);
		window.draw(textFieldBorder);
		window.draw(numberOfRodsText);
		window.draw(upArrowImage);
		window.draw(downArrowImage);
		window.draw(delayTimePrompt);
		window.draw(textFieldBorder2);
		window.draw(delayTimeText);
		bubbleSortButton.draw(window);
		insertionSortButton.draw(window);
		selectionSortButton.draw(window);
		mergeSortButton.draw(window);
		quickSortButton.draw(window);
		iterativeQuickSortButton.draw(window);
		heapSortButton.draw(window);
		shellSortButton.draw(window);
		gnomeSortButton.draw(window);
		cocktailSortButton.draw(window);
		countingSortButton.draw(window);
		pancakeSortButton.draw(window);
		combSortButton.draw(window);
		iterativeHeapSortButton.draw(window);
		binaryInsertionSortButton.draw(window);
		timSortButton.draw(window);
		radixSortButton.draw(window);
		introSortButton.draw(window);
		window.display();	
	}
	return 0;
}