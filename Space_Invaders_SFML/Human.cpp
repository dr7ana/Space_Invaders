#include <iostream>
#include <stdlib.h>
#include <SFML/Graphics.hpp>

#include "Human.h"
#include "resourcePath.h"

#define _CRT_SECURE_NO_WARNINGS

using namespace std;


Ship::Ship(float speed)
{
	//Load SFML texture
	texture.loadFromFile("x_wing.png");

	//Scale sprite and image to workable size
	sprite.setTexture(texture);
	sprite.scale(sf::Vector2f(0.05, 0.05));

	//Set speed from constructor parameter
	movement_speed = speed;

	//Activate ship
	status = true;
}



//Set_location function places alien ship
void Ship::set_human_location(float x_pix, float y_pix)
{
	sprite.setPosition(x_pix, y_pix);						//Sprite library has built in method for placing objects
}



//SFML static member function window::draw is called to show alien on screen
void Ship::draw_human(sf::RenderWindow& window)
{
	sprite.setTexture(texture);
	window.draw(sprite);
}