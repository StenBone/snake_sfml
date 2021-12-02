#pragma once
class Scene
{
};


class  Scene_ : sf::Drawable {
private:
	std::unique_ptr<sf::RectangleShape> treat;
public:
	const Snake& snake;

	Scene(const Snake& in_snake) : snake(in_snake) {}

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const {
		target.draw(*treat, states);
		target.draw(snake, states);
	}

	void place_treat_at_random_pos(Scene& scene) {

		int rand_x = 0;
		int rand_y = 0;

		bool get_random_position = true;
		while (get_random_position) {
			rand_x = rand() % WINDOW_BOUNDS_X;
			rand_y = rand() % WINDOW_BOUNDS_Y;
			for (const auto& segment : snake.get_segments()) {
				if (!segment.getGlobalBounds().contains(rand_x, rand_y)) {
					get_random_position = false;
					break;
				}
			}
		}
		// snap treat to grid
		rand_x = rand_x - (rand_x % UNIT_SQUARE_IN_PX);
		rand_y = rand_y - (rand_y % UNIT_SQUARE_IN_PX);

		treat.reset(new sf::RectangleShape());
		treat->setPosition(rand_x, rand_y);
		treat->setSize(UNIT_SQUARE_VEC2F);
		treat->setFillColor(TREAT_COLOR);
	}
};