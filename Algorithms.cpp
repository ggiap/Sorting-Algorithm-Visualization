#include "Algorithms.h"

void Algorithms::createCanvas(sf::RenderWindow &window, const int numOfRods)
{
	if (rods.size() > 0)
		rods.clear();
	srand(time(NULL));

	for (unsigned i = 0, xPos = window.getSize().x / numOfRods;
		 i < numOfRods;
		 ++i, xPos = xPos + window.getSize().x / numOfRods)
	{
		float rodWidth = (window.getSize().x / numOfRods);
		sf::Vector2f size(rodWidth - rodWidth / 10, rand() % 540 + 10);
		sf::RectangleShape rect(size);
		rect.setPosition(sf::Vector2f(xPos, rect.getPosition().y + (600 - rect.getPosition().y)));
		rect.setRotation(180.0f);
		rods.push_back(rect);
	}
	sorted = false;
	backButtonPressed = false;
	numberOfComparisons = 0;
	numberOfArrayAccesses = 0;

	sf::Vector2f buttonSize((window.getSize().x / 10.0f) - 5, (window.getSize().y / 20.0f));
	auto offsetX = window.getSize().x - buttonSize.x;
	auto buttonColor = sf::Color(150, 150, 150, 255);
	if (!(backButton.buttonConfigured))
	{
		backButton.buttonConfigured = true;
		backButton.buttonConfig(buttonSize, sf::Vector2f(offsetX, 0.0f), buttonColor, "Back");
		backButton.getButtonText().setCharacterSize(27);
		backButton.setPosition(
			sf::Vector2f(backButton.getRect().getPosition().x + 8,
						 backButton.getRect().getPosition().y - 2));
	}
}

void Algorithms::printMessage(sf::RenderWindow &window,const sf::Vector2f &point, const string &message)
{
	sf::Font font;
	font.loadFromFile("../Font/ARJULIAN.ttf");
	sf::Text algName;
	sf::Text comparisons;
	sf::Text arrayAccesses;
	sf::String temp = "Comparisons: " + to_string(numberOfComparisons);
	sf::String temp2 = "Array accesses: " + to_string(numberOfArrayAccesses);
	algName.setFont(font);
	algName.setCharacterSize(20);
	comparisons.setFont(font);
	comparisons.setCharacterSize(20);
	arrayAccesses.setFont(font);
	arrayAccesses.setCharacterSize(20);
	algName.setString(message);
	comparisons.setString(temp);
	arrayAccesses.setString(temp2);
	algName.setPosition(point);
	comparisons.setPosition(point + sf::Vector2f(0.0f, 30.0f));
	arrayAccesses.setPosition(point + sf::Vector2f(0.0f, 60.0f));

	// Draw the text and the button
	// along with the rods
	while (backButtonPressed == false)
	{
		checkEvents(window);

		window.clear();
		window.draw(algName);
		window.draw(comparisons);
		window.draw(arrayAccesses);
		backButton.draw(window);
		for (auto rect : rods)
			window.draw(rect);
		window.display();
	}
}

void Algorithms::draw(sf::RenderWindow &window)
{
	window.clear();
	backButton.draw(window);
	for (auto rect : rods)
		window.draw(rect);
	window.display();
}

void Algorithms::checkEvents(sf::RenderWindow &window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			// end the program
			window.close();
		}
		if (event.type == sf::Event::MouseMoved)
		{
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			sf::Vector2f mousePosf(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
			if (backButton.getRect().getGlobalBounds().contains(mousePosf))
			{
				backButton.getRect().setFillColor(sf::Color(150, 150, 150, 155));
			}
			else
			{
				backButton.getRect().setFillColor(sf::Color(150, 150, 150, 255));
			}
		}
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				sf::Vector2i mousePos = sf::Mouse::getPosition(window);
				sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
				if (backButton.getRect().getGlobalBounds().contains(mousePosF))
				{
					backButtonPressed = true;
				}
			}
		}
	}
}

void Algorithms::wait(sf::RenderWindow &window, float seconds)
{
	sf::Clock clock;
	sf::Time deltaTime = clock.restart();
	while (deltaTime.asSeconds() < seconds)
	{
		if (backButtonPressed == true) return;
		checkEvents(window);
		draw(window);
		deltaTime = clock.getElapsedTime();
	}
}

vector<sf::RectangleShape> Algorithms::getRods()
{
	return rods;
}
