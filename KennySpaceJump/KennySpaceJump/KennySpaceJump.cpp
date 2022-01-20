// KennySpaceJump.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(400, 533), "Kenny Space Jump !");
	window.setFramerateLimit(60);

	//adding resources
	sf::Texture background_tex, platform_tex, kenny_tex;

	background_tex.loadFromFile("Data/background.png");
	platform_tex.loadFromFile("Data/platform.png");
	kenny_tex.loadFromFile("Data/kenny.png");


	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {


		}

		window.clear();
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
