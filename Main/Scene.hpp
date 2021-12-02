#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "Snake.hpp"

class Scene : sf::Drawable {
private:
	std::unique_ptr<sf::RectangleShape> treat;
public:
	const Snake& snake;

	Scene(const Snake& in_snake) : snake(in_snake) {}
	void place_treat_at_random_pos();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const;
};