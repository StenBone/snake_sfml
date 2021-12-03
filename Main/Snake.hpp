#pragma once
#include <vector>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include "Constants.hpp"

class Snake : public sf::Drawable {
private:
	sf::Vector2f tails_last_pos;
	std::vector<sf::RectangleShape> segments; //probably rectangleshapes of a certain color

	void add_segment(const float x_pos, const float y_pos, const sf::Color color);
	void add_segment(const sf::Vector2f& pos, const sf::Color color);
public:
	const enum class MOVEMENT_DIRECTIONS {
		N, E, S, W
	};

	Snake(const float x_pos, const float y_pos);
	const std::vector<sf::RectangleShape>& get_segments() const {
		return segments;
	}
	void grow();
	void move(MOVEMENT_DIRECTIONS dir);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

