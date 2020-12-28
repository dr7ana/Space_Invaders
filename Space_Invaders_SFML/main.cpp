#include <iostream>
#include <stdlib.h>
#include <SFML/Graphics.hpp>

#include "Alien.h"
#include "Human.h"
#include "Torpedo.h"
#include "Explosion.h"
#include "Menu.h"
#include "resourcePath.h"
#include "Object_Collision.h"


#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

using namespace std;


int main()
{
    //Variables
    bool game_active = true;
    bool is_winner = false;

    //SFML Window Settings
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    //Create main window
    sf::RenderWindow main_window(sf::VideoMode(800, 600), "SPACE INVADERS");
    main_window.setVerticalSyncEnabled(true);

    //Create background/load background image
    sf::Texture star;
    if (!star.loadFromFile("stars.png"))
        return 1;                               //Debug line
    sf::Sprite background(star);

    //Create class objects
    Ship _player_ship(400.f);
    Torpedo _torpedo(600.f);
    Explosion fireball;

    //Create/populate array of enemies
    Alien enemy_array[7][3];

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            Alien alien_ship(i, j, 800);
            if (j % 2)
            {
                alien_ship.set_alien_location(i * 100 + 50, (alien_ship.get_sprite().getGlobalBounds().height / 2) + (50 * j));

            }
            else
            {
                alien_ship.set_alien_location(i * 100 + 100, (alien_ship.get_sprite().getGlobalBounds().height / 2) + (50 * j));
            }

            enemy_array[i][j] = alien_ship;
        }
    }


    //Set player ship starting position
    _player_ship.set_human_location(400, 550 - _player_ship.get_sprite().getGlobalBounds().height);     //Orients the ship in the middle, and half the ships height 
                                                                                                        //off of the bottom window boundary

    //Start Clocks
    sf::Clock main_clock;
    sf::Clock torpedo_clock;
    torpedo_clock.restart().asSeconds();
    sf::Clock alien_clock;
    alien_clock.restart().asSeconds();


    while (main_window.isOpen())
    {
        float time_index = main_clock.restart().asSeconds();

        sf::Event event;

        //Clear window/display background
        main_window.clear();
        Menu info(main_window);
        main_window.draw(background);

        //Event processing loop
        while (main_window.pollEvent(event))
        {
            //Game switch/case
            switch (event.type)
            {
            case sf::Event::Closed:
                main_window.close();
                break;

            case sf::Event::KeyPressed:
                //Escape pressed
                if (event.key.code == sf::Keyboard::Escape) { main_window.close(); }

                //Enter pressed
                if (event.key.code == sf::Keyboard::Enter)
                {
                    //Reset variables for game parameters
                    game_active = true;
                    is_winner = false;
                    main_clock.restart();
                    alien_clock.restart().asSeconds();
                    torpedo_clock.restart().asSeconds();

                    //Reset alien array
                    for (int i = 0; i < 7; i++)
                    {
                        for (int j = 0; j < 3; j++)
                        {
                            if (j % 2)
                            {
                                enemy_array[i][j].set_alien_location(i * 100 + 50, (enemy_array[i][j].get_sprite().getGlobalBounds().height / 2) + (50 * j));
                                enemy_array[i][j].respawn();
                            }
                            else
                            {
                                enemy_array[i][j].set_alien_location(i * 100 + 100, (enemy_array[i][j].get_sprite().getGlobalBounds().height / 2) + (50 * j));
                                enemy_array[i][j].respawn();
                            }
                        }
                    }

                    //Respawn ship/reset location
                    _player_ship.set_human_location(400, 550 - _player_ship.get_sprite().getGlobalBounds().height);
                    _player_ship.respawn();
                }

                //Right pressed
                if (event.key.code == sf::Keyboard::Right)
                {
                    //Can only move right if ship position plus ship width is less than window width (if the ship is not at its right most point)
                    if (_player_ship.get_sprite().getPosition().x + _player_ship.get_sprite().getGlobalBounds().width < 800)
                    {
                        _player_ship.get_sprite().move(10.f, 0.f);
                    }
                }

                //Left pressed
                if (event.key.code == sf::Keyboard::Left)
                {
                    //Can only move left if ship position is greater than left bound (ship position is left indexed)
                    if (_player_ship.get_sprite().getPosition().x > 0.f)
                    {
                        _player_ship.get_sprite().move(-10.f, 0.f);
                    }
                }

                //Up pressed
                if (event.key.code == sf::Keyboard::Up)
                {
                    if (_player_ship.get_sprite().getPosition().y > 400)
                    {
                        _player_ship.get_sprite().move(0.f, -10.f);
                    }
                }

                //Down pressed
                if (event.key.code == sf::Keyboard::Down)
                {
                    if (_player_ship.get_sprite().getPosition().y < 600 - _player_ship.get_sprite().getGlobalBounds().height)
                    {
                        _player_ship.get_sprite().move(0.f, 10.f);
                    }
                }

                //Space pressed
                if (event.key.code == sf::Keyboard::Space)
                {
                    if (!_torpedo.is_alive() && game_active && _player_ship.is_alive())
                    {
                        _torpedo.activate(true);
                        _torpedo.set_torpedo_location(_player_ship.get_sprite().getPosition().x + 10, _player_ship.get_sprite().getPosition().y - 10);
                    }

                    if (_torpedo.get_sprite().getPosition().y < 20) { _torpedo.destroy(); }        //Destroys torpedo after it approaches top border of screen

                    cout << "Torpedo fired" << endl;
                }

                break;
            }
        }


        //Collision Manager -- Testing for collisions between aliens and torpedos
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if ((Collision::collision_between(_torpedo, enemy_array[i][j])) && (enemy_array[i][j].is_alive()))
                {
                    fireball.set_explosion_location(enemy_array[i][j].get_sprite().getPosition().x, enemy_array[i][j].get_sprite().getPosition().y);
                    fireball.draw_explosion(main_window);
                    enemy_array[i][j].destroy();

                    _torpedo.destroy();
                }
            }
        }



        //Collision Manager -- Testing for collisions between aliens and player
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if ((Collision::collision_between(_player_ship, enemy_array[i][j])) && (enemy_array[i][j].is_alive()))
                {
                    fireball.set_explosion_location(_player_ship.get_sprite().getPosition().x, _player_ship.get_sprite().getPosition().y);
                    fireball.draw_explosion(main_window);
                    enemy_array[i][j].destroy();
                    _player_ship.destroy();
                }
            }
        }





        //Clocks: I'm not sure if this is the best way to do this, but the documentation indicated this is the best way
        //to measure elapsed time through gameplay https://www.sfml-dev.org/tutorials/2.5/system-time.php
        //I tried using a delta-time measure (https://gafferongames.com/post/fix_your_timestep/), called "time_index" in
        //the code above, and that seemed to work well for managing movement and movement function





        //Alien Movement -- Controlled by alien_clock; alien movement executed every 1 second of program runtime
        sf::Time a_time = alien_clock.getElapsedTime();
        if (a_time.asSeconds() > 1.0)
        {
            for (int i = 0; i < 7; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    enemy_array[i][j].get_sprite().move(0.f, enemy_array[i][j].get_speed() * time_index);
                }
            }

            alien_clock.restart();
        }



        //Torpedo -- Controlled by torpedo clock; will become active and able to shoot after 1 second of program runtime
        sf::Time torp_time = torpedo_clock.getElapsedTime();
        if (torp_time.asSeconds() > 1.0)
        {
            if (_torpedo.is_alive() && game_active)
            {
                _torpedo.draw_torpedo(main_window);
                _torpedo.get_sprite().move(0.f, -40);
            }
        }



        //This next section apparently has to be at the very end. Anywhere else in the code, and it won't draw to window
        //correctly. This was indicated but not explained in the SFML documentation

        //Draw aliens on screen
        if (game_active)
        {
            //Draw aliens
            for (int i = 0; i < 7; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (enemy_array[i][j].is_alive()) { enemy_array[i][j].draw_alien(main_window); }
                }
            }

            //Draw player ship
            if (_player_ship.is_alive())
            {
                _player_ship.draw_human(main_window);
            }

            //Display to window
            main_window.display();
        }


    }



    return 0;
}


/*
* Notes for next time: I think that this project would be better done using state-specific classes for the aliens,
* player, and torpedo. For example, when firing, the torpedo would call upon a derived torpedo class tailored for
* movement in that state. This would require re-doing all of the current classes, but may improve game efficiency.
* Having enumerated states for classes would also make instituting a main menu much easier, as each object could be
* set to a "menu" state, where all movement and activity is ceased. When beginning the game, all game clocks would
* restart and all objects would move to "game start" state
*/