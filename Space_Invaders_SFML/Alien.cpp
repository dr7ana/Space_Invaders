#include <iostream>
#include <stdlib.h>
#include <SFML/Graphics.hpp>

#include "Alien.h"
#include "resourcePath.h"


#define _CRT_SECURE_NO_WARNINGS

using namespace std;


Alien::Alien(int array_id, int row_id, float speed)
{
	//Load SFML texture
	texture.loadFromFile("tie_fighter.PNG");

	//Scale sprite and image to workable size
	sprite.setTexture(texture);
	sprite.scale(sf::Vector2f(0.05, 0.05));

	//Set speed from constructor parameter
	movement_speed = speed;

	//Activate ship
	status = true;
}


//Set_location function places alien ship
void Alien::set_alien_location(float x_pix, float y_pix)
{
	sprite.setPosition(x_pix, y_pix);						//Sprite library has built in method for placing objects
}


//Changes the image of the alien ship to an explosion
void Alien::explosion()
{
	//Load SFML tecture
	texture.loadFromFile("explosion.png");

	//Scale sprite and image to workable size
	sprite.setTexture(texture);
	//sprite.setScale(0.1, 0.1);

	movement_speed = 0;
}


//SFML static member function window::draw is called to show alien on screen
void Alien::draw_alien(sf::RenderWindow& window)
{
	sprite.setTexture(texture);
	window.draw(sprite);
}
