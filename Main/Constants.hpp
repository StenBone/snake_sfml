#pragma once
#include <string>
#include <SFML/Graphics.hpp>

const std::string  WINDOW_NAME{ "Conway's Game of Life" };
const unsigned int WINDOW_BOUNDS_X = 800;
const unsigned int WINDOW_BOUNDS_Y = 600;
constexpr int UNIT_SQUARE_IN_PX = WINDOW_BOUNDS_X / 24; // can fit 24 squares vertically
const sf::Vector2f UNIT_SQUARE_VEC2F(UNIT_SQUARE_IN_PX, UNIT_SQUARE_IN_PX);
const sf::Time	   SNAKE_MOVEMENT_UPDATE_INTERVAL{ sf::seconds(1.f) };
const sf::Color SNAKE_BODY_COLOR = sf::Color::White;
const sf::Color SNAKE_HEAD_COLOR = sf::Color::Green;
const sf::Color TREAT_COLOR = sf::Color::Red;
const sf::Color BACKGROUND_COLOR = sf::Color::Black;
const int SNAKE_BODY_STARTING_SEGMENTS = 3;
