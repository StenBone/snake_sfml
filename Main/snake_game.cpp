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

class Actor {
private:
	// x, y position
	int x = 0;
	int y = 0;
public:
	Actor() : x(0), y(0) {}
	Actor(int in_x, int in_y) : x(in_x), y(in_y) {}
};

class Snake : public Actor {
private:
	std::vector<_____> body; //probably rectangleshapes of a certain color
public:

	// vector of segments
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
	srand(time(NULL));
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
	}
} // what can this snake game do differently than others