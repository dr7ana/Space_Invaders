/*
Class: Human.h
Purpose: To define the methods for the function of the player controlled ship
Detais: The member functions for human.h, alien.h, and torpedo.h are all mostly similar. Sprites, tectures, status, and movement speed
are stored as private member values, while the getters and setters are public. All have a draw function that references the address of the
SFML object produced by SF::renderWindow -- the function that produces the game window.
*/

#pragma once

#ifndef HUMAN_CLASS_H
#define HUMAN_CLASS_H


#include <iostream>
#include <stdlib.h>
#include <SFML/Graphics.hpp>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;


class Ship
{
private:
	sf::Sprite sprite;

	sf::Texture texture;

	bool status;

	float movement_speed;

public:
	Ship() {};
	Ship(float speed);
	//~Ship();

	void set_human_location(float x_pix, float y_pix);

	sf::Sprite& get_sprite() { 
		return sprite; }

	void destroy() { 
		status = false; }

	bool is_alive() { 
		return status; }

	void respawn() { 
		status = true; }

	void draw_human(sf::RenderWindow& window);

};


#endif