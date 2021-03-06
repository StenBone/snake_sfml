#pragma once
#include <SFML/Graphics.hpp>
#include <string>

const std::string WINDOW_NAME{"danger noodle"};
const unsigned int SCREEN_WIDTH = 800;
const unsigned int SCREEN_HEIGHT = 600;
const sf::Vector2f SCREEN_CENTER(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
const sf::FloatRect PLAY_FIELD_BOUNDS(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
constexpr int UNIT_SQUARE_IN_PX = 25; // experimental value
const sf::Vector2f UNIT_SQUARE_VEC2F(UNIT_SQUARE_IN_PX, UNIT_SQUARE_IN_PX);
const sf::Time SNAKE_MOVEMENT_UPDATE_INTERVAL{sf::seconds(.5f)};
const sf::Color SNAKE_BODY_COLOR = sf::Color::White;
const sf::Color SNAKE_HEAD_COLOR = sf::Color::Green;
const sf::Color TREAT_COLOR = sf::Color::Red;
const sf::Color BACKGROUND_COLOR = sf::Color::Black;
const int SNAKE_BODY_STARTING_SEGMENTS = 3;
