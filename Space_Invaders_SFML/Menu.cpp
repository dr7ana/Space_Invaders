#include <iostream>
#include <stdlib.h>
#include <SFML/Graphics.hpp>

#include "Menu.h"


#define _CRT_SECURE_NO_WARNINGS

using namespace std;


Menu::Menu(sf::RenderWindow& window)
{
	//Main title
	main_font.loadFromFile("Starjedi.ttf");
	main_text.setFont(main_font);
	main_text.setString("STAR WARS");
	main_text.setCharacterSize(48);
	main_text.setFillColor(sf::Color::Yellow);
	main_text.setPosition(20, 200);

	//Subtitle
	secondary_font.loadFromFile("lucon.ttf");
	secondary_text.setFont(secondary_font);
	secondary_text.setString("- L/R to move\n- Space to shoot\n- Enter to reset");
	secondary_text.setCharacterSize(20);
	secondary_text.setFillColor(sf::Color::White);
	secondary_text.setPosition(20, 300);

	window.clear();
	window.draw(main_text);
	window.draw(secondary_text);
	window.display();
}


sf::Text& Menu::get_text(int arg)
{
	if (arg == 1) { return main_text; }
	else { return secondary_text; }
}
