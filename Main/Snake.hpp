#pragma once
#include <vector>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include "Constants.hpp"

class Snake : public sf::Drawable {
private:
	sf::Vector2f tails_last_pos;
	std::vector<sf::RectangleShape&> segments; //probably rectangleshapes of a certain color

	sf::RectangleShape& make_segment(const int x_pos, const int y_pos, const sf::Color color = SNAKE_BODY_COLOR);
	sf::RectangleShape& make_segment(const sf::Vector2f& pos, const sf::Color color = SNAKE_BODY_COLOR);
public:
	const static enum class MOVEMENT_DIRECTIONS {
		N, E, S, W
	};

	Snake(const int x_pos, const int y_pos);
	const std::vector<sf::RectangleShape&>& get_segments() const {
		return segments;
	}
	void grow();
	void move(MOVEMENT_DIRECTIONS dir);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const;
};

