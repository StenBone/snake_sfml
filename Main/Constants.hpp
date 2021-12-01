#pragma once
#include <string>
#include <SFML/Graphics.hpp>

const std::string  WINDOW_NAME{ "Conway's Game of Life" };
const unsigned int WINDOW_BOUNDS_X = 800;
const unsigned int WINDOW_BOUNDS_Y = 600;
constexpr float UNIT_SQUARE_IN_PX = WINDOW_BOUNDS_X / 24; // can fit 24 squares vertically
const sf::Time	   SNAKE_MOVEMENT_UPDATE_INTERVAL{ sf::seconds(1.f) };
