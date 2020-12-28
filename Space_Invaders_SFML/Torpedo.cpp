#include <iostream>
#include <stdlib.h>
#include <SFML/Graphics.hpp>

#include "Torpedo.h"
#include "resourcePath.h"

#define _CRT_SECURE_NO_WARNINGS

using namespace std;


Torpedo::Torpedo(float speed)
{
	//Load SFML texture
	texture.loadFromFile("torpedo.png");

	//Scale sprite and image to workable size
	sprite.scale(sf::Vector2f(0.1f, 0.1f));

	//Set speed from constructor parameter
	movement_speed = speed;

	//Activate ship
	status = false;
}

void Torpedo::set_torpedo_location(float x_pix, float y_pix)
{
	sprite.setPosition(x_pix, y_pix);
}


//SFML static member function window::draw is called to show alien on screen
void Torpedo::draw_torpedo(sf::RenderWindow& window)
{
	sprite.setTexture(texture);
	window.draw(sprite);
}