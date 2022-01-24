// KennySpaceJump.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>


struct point {
	int x, y;
};

int main()
{
	srand(time(0));

	sf::RenderWindow window(sf::VideoMode(400, 533), "Kenny Space Jump !");
	window.setFramerateLimit(60);

	//adding resources
	sf::Texture background_tex, platform_tex, kenny_tex;
	//points
	sf::Font font;
	sf::Text pointsText;

	background_tex.loadFromFile("Data/background2.jpg");
	platform_tex.loadFromFile("Data/platform.png");
	kenny_tex.loadFromFile("Data/kenny.png");

	font.loadFromFile("Data/SpaceMission-rgyw9.otf");
	pointsText.setPosition(270, 20.f);
	pointsText.setFont(font);
	pointsText.setCharacterSize(22);
	pointsText.setFillColor(sf::Color::White);

	sf::Sprite background(background_tex), platform(platform_tex), kenny(kenny_tex);

	point platforms[20];

	for (int i = 0; i < 10; i++) {
		platforms[i].x = rand() % 400;
		platforms[i].y = rand() % 533;
	}

	//coordinates
	int x = 100, y = 100, h = 200;
	float dx = 0, dy = 0;

	//points
	unsigned points = 0;


	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.Event::KeyPressed && event.Event::key.code == sf::Keyboard::Escape) {
				window.close();
			}
		}

		window.clear();
		
		//moving

		//side moves
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			x += 3;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			x -= 3;
		}

		// jump
		dy += 0.2;
		y += dy;
		if (y > 500) {
			dy = -10;
		}
		//screen progressing and making new platforms
		if (y < h) {
			for (int i = 0; i < 10; i++) {
				y = h;
				platforms[i].y = platforms[i].y - dy;
				if (platforms[i].y > 533) {
					platforms[i].y = 0;
					platforms[i].x = rand() % 400;
				}
			}
		}

		//collision with platforms
		for (int i = 0; i < 10; i++) {
			if ((x + 50 > platforms[i].x) && (x + 20 < platforms[i].x + 68) &&
				(y + 70 > platforms[i].y) && (y + 70 < platforms[i].y + 14)) {
				dy = -10;
				// adding points by 1 everytime Kenny jumps on platform
				points++;
			}
		}
		kenny.setPosition(x, y);
		// points part
		std::stringstream ss;
		ss << " Points: " << points;
		pointsText.setString(ss.str());
		//draw elements
		window.draw(background);
		window.draw(kenny);
		window.draw(pointsText);
		for (int i = 0; i < 10; i++) {
			platform.setPosition(platforms[i].x, platforms[i].y);
			window.draw(platform);
		}
		window.display();
	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
