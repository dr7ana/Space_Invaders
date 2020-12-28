/*
Class: Alien.h
Purpose: To define the methods for the function of the alien controlled ships
Detais: The member functions for human.h, alien.h, and torpedo.h are all mostly similar. Sprites, tectures, status, and movement speed
are stored as private member values, while the getters and setters are public. All have a draw function that references the address of the
SFML object produced by SF::renderWindow -- the function that produces the game window.
*/

#pragma once

#ifndef ALIEN_CLASS_H
#define ALIEN_CLASS_H

#include <iostream>
#include <stdlib.h>
#include <SFML/Graphics.hpp>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;


class Alien
{
private:
	sf::Sprite sprite;				//Stores image for alien ship

	sf::Texture texture;

	bool status;

	float movement_speed;

public:
	Alien() {};								//Default constructor (for enemy array)
	Alien(int array_id, int row_id, float speed);		//Overloaded constructor
	//~Alien();

	void set_alien_location(float x_pix, float y_pix);

	void destroy() { 
		status = false; }

	void explosion();

	bool is_alive() { 
		return status; }

	sf::Sprite& get_sprite() { 
		return sprite; }

	void draw_alien(sf::RenderWindow &window);

	void respawn() { 
		status = true; }

	float get_speed() { 
		return movement_speed; }
};


#endif