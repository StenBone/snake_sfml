#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>
#include "Constants.hpp"
#include "Snake.hpp"
#include "Scene.hpp"

int main() {
	srand(time(NULL)); // seed random number generator
	sf::Clock clock{};
	sf::Time delta_time{};
	sf::Time time_since_last_cell_simulation_update{};
	sf::RenderWindow window(sf::VideoMode(800, 600), "danger noodle");
	Snake snake(WINDOW_BOUNDS_X / 2, WINDOW_BOUNDS_Y / 2);
	Snake::MOVEMENT_DIRECTIONS snake_direction;
	Scene scene(snake);
	scene.place_treat_at_random_pos();

	// main loop
	while (window.isOpen()) {
		//process input - get next direction snake is going
		//move snake
		//check if snake's head is on a treat, in it's body, outside bounds
		//if treat, then grow extra unit at tail
		//if body or outside bounds then game over

		// snake move - input
		// snake grow afterwards - update

		//movement then grow

		delta_time = clock.restart();

		// EVENTS AND INPUT
		sf::Event event{};
		while (window.pollEvent(event)) {

			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;


				// KEY RELEASED
			case sf::Event::KeyReleased: {
				switch (event.key.code)
				{
				case sf::Keyboard::Space:
					break;
				}
			}
									   // KEY RELEASED
			case sf::Event::KeyPressed: {
				switch (event.key.code)
				{
				case sf::Keyboard::W:
					snake_direction = Snake::MOVEMENT_DIRECTIONS::N;
					break;
				case sf::Keyboard::D:
					snake_direction = Snake::MOVEMENT_DIRECTIONS::E;
					break;
				case sf::Keyboard::S:
					snake_direction = Snake::MOVEMENT_DIRECTIONS::S;
					break;
				case sf::Keyboard::A:
					snake_direction = Snake::MOVEMENT_DIRECTIONS::W;
					break;
				}
			}
			}
		}
		// UPDATE
		time_since_last_cell_simulation_update += delta_time;

		if (time_since_last_cell_simulation_update >= SNAKE_MOVEMENT_UPDATE_INTERVAL) {
			time_since_last_cell_simulation_update = sf::Time::Zero;
			snake.move(snake_direction);
			if (scene.snake_intersects_treat()) {
				snake.grow();
			}
			if (scene.snake_intersects_itself_or_wall()) {
				return EXIT_SUCCESS;
			}
		}

		// RENDER
		window.clear(BACKGROUND_COLOR);
		window.draw(scene);
		window.display();
	}

	return EXIT_SUCCESS;
} // what can this snake game do differently than others