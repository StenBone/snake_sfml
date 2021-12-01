#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>
#include "Constants.hpp"

void place_treat_in_random_location() {

}

void process_input() {

}

void load_textures() {
	// fill texture manager
}

class TextureManager {

};

class Game {
	// holds texture manager, member variables across the game
};

class Player {
	// process player related input
	// reference to snake actor
};

class Actor : public sf::Transformable, public sf::Drawable {
	//input handler
};

class Snake : public sf::Drawable {
private:
	sf::Vector2f tails_last_pos;
	std::vector<sf::RectangleShape&> segments; //probably rectangleshapes of a certain color

	sf::RectangleShape& make_segment(const int x_pos, const int y_pos, const sf::Color color = SNAKE_BODY_COLOR) {
		sf::RectangleShape segment(UNIT_SQUARE_VEC2F);
		segment.setPosition(x_pos, y_pos);
		segment.setSize(UNIT_SQUARE_VEC2F);
		segment.setFillColor(color);
		segments.push_back(segment);
	}
	sf::RectangleShape& make_segment(const sf::Vector2f& pos, const sf::Color color = SNAKE_BODY_COLOR) {
		return make_segment(pos.x, pos.y, color);
	}
public:

	const static enum class MOVEMENT_DIRECTIONS {
		N, E, S, W
	};

	Snake(const int x_pos, const int y_pos) {
		for (int i = 0; i < SNAKE_BODY_STARTING_SEGMENTS; i++) {
			make_segment(x_pos, y_pos - (i * UNIT_SQUARE_IN_PX));
		}
		auto& head = segments.front();
		head.setFillColor(SNAKE_HEAD_COLOR);
	}

	void move(MOVEMENT_DIRECTIONS dir) {
		
		int x = 0;
		int y = 0;

		switch (dir)
		{
		case Snake::MOVEMENT_DIRECTIONS::N:
			y = 1;
			break;
		case Snake::MOVEMENT_DIRECTIONS::E:
			x = 1;
			break;
		case Snake::MOVEMENT_DIRECTIONS::S:
			y = -1;
			break;
		case Snake::MOVEMENT_DIRECTIONS::W:
			x = -1;
			break;
		default:
			break;
		}

		auto head_position = segments.front().getPosition();
		auto old_position = head_position;
		sf::Vector2f new_position(head_position.x + (x * UNIT_SQUARE_IN_PX), head_position.x + (y * UNIT_SQUARE_IN_PX));
		
		for (auto& segment : segments) {
			old_position = segment.getPosition();
			segment.setPosition(new_position); // position of the one before it
			new_position = old_position;
		}
		tails_last_pos = old_position;
	}

	void grow() {
		sf::RectangleShape segment(UNIT_SQUARE_VEC2F);
		make_segment(tails_last_pos);
	}

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const {
		for (const auto& segment : segments) {
			target.draw(segment, states);
		}
	}
};

class Scene {
private:

public: 
	// data
	// list of actors
};

void place_treat_at_random_pos() {
	
	int rand_x = rand() % WINDOW_BOUNDS_X;
	int rand_y = rand() % WINDOW_BOUNDS_Y;

	while (scene.at(rand_x, rand_y) == false) {
		rand_x = rand() % WINDOW_BOUNDS_X;
		rand_y = rand() % WINDOW_BOUNDS_Y;
	}
	Treat treat(rand_x, rand_y);
	scene.add(treat);
}

int main() {
	srand(time(NULL)); // seed random number generator
	sf::RenderWindow window(sf::VideoMode(800, 600), "danger noodle");

	/**
	game.loadscene("snake_level.json")
		renderer.init
		snake.init
		input.init
		assetmanager.load(snake.assets)
		assetmananger.load(treat.assets)
		assetmananger.close
	game.begin_loop()
	game.end()
	*/

	// load assests: sound, font, textures

	// setup game - place first treat, place snake in center
	place_treat_at_random_pos();
	Snake snake(WINDOW_BOUNDS_X / 2, WINDOW_BOUNDS_Y / 2);

	// main loop
	while (window.isOpen()) {
		//process input - get next direction snake is going
		//move snake
		//check if snake's head is on a treat, in it's body, outside bounds
		//if treat, then grow extra unit at tail
		//if body or outside bounds then game over


		//movement then grow
	}
} // what can this snake game do differently than others