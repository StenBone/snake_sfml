#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>
#include "Constants.hpp"
#include "Snake.hpp"
#include "Scene.h"

int main() {
	srand(time(NULL)); // seed random number generator
	sf::RenderWindow window(sf::VideoMode(800, 600), "danger noodle");
	Snake snake(WINDOW_BOUNDS_X / 2, WINDOW_BOUNDS_Y / 2);
	Scene scene(snake);
	scene.place_treat_at_random_pos()

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