#include <SFML/Graphics.hpp>
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
	// x, y position
};

class Snake {
	// vector of segments
};

class PlayArea {
	// data
	// list of actors
};

int main() {
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

	// main loop
	while (window.isOpen()) {

	}
}