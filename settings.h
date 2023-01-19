#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "settings.h"
#include <ctime>


const float ay = 20.f;
const float ax = 80.f;

const float ball_r = 15.f;

const float fps = 60.f;

const float window_size = 800;

const float bat_ofset = 50.f;

const float bat_speed = 10.f;

const int char_size = 64;


const sf::Color bat_collor{ sf::Color::Magenta };
const sf::Color ball_color{ sf::Color::Yellow };

const sf::Vector2f bat_startpos(window_size / 2 - ax / 2, window_size - bat_ofset);
const sf::Vector2f ball_startpos(window_size / 2, 2 * ball_r);

const sf::Vector2f bat_size(ax, ay);

const sf::Vector2f text_start_pos{ 380.f, 200.f };

const float brick_width = 40.f;
const float brick_height = 20.f;

const int size_mass = 20;