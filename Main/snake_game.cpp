#include <stdlib.h>
#include <time.h>

#include <SFML/Graphics.hpp>

#include "Constants.hpp"
#include "Scene.hpp"
#include "Snake.hpp"

class Game {
private:
    struct GameStats {
        unsigned int score = 0;
    } game_stats; // todo look this up

    enum class GameStates {
        RUNNING,
        PAUSED
    };

};

int main()
{
    srand(static_cast<unsigned int>(time(NULL))); // seed random number generator
    sf::Clock clock{};
    sf::Time delta_time{};
    sf::Time time_since_last_cell_simulation_update{};
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), WINDOW_NAME);
    Snake snake(Scene::snap_point_to_unit_square(SCREEN_CENTER));
    auto snake_direction = Snake::MOVEMENT_DIRECTIONS::N;
    Scene scene(snake);
    scene.place_treat_at_random_pos();

    sf::Font press_start_2p;
    if (!press_start_2p.loadFromFile("PressStart2P-Regular.ttf")) {
        return EXIT_FAILURE;
    }
    sf::Text pause_screen_message("Press 'space' to start game.", press_start_2p, 24);
    pause_screen_message.setPosition(SCREEN_CENTER);
    const auto& pause_screen_message_bounds = pause_screen_message.getLocalBounds();
    pause_screen_message.setOrigin(pause_screen_message_bounds.width/2, pause_screen_message_bounds.height/2);

    bool game_paused = true;

    // main loop
    while (window.isOpen())
    {
        // process input - get next direction snake is going
        // move snake
        // check if snake's head is on a treat, in it's body, outside bounds
        // if treat, then grow extra unit at tail
        // if body or outside bounds then game over

        // snake move - input
        // snake grow afterwards - update

        // movement then grow

        delta_time = clock.restart();

        // EVENTS AND INPUT
        sf::Event event{};
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;

                // KEY RELEASED
            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                case sf::Keyboard::Space:
                    break;
                case sf::Keyboard::Escape:
                    window.close();
                    break;
                }
                [[fallthrough]];
            case sf::Event::KeyPressed:
                switch (event.key.code)
                {
                case sf::Keyboard::W:
                    if (snake_direction != Snake::MOVEMENT_DIRECTIONS::S) {
                        snake_direction = Snake::MOVEMENT_DIRECTIONS::N;
                    }
                    break;
                case sf::Keyboard::D:
                    if (snake_direction != Snake::MOVEMENT_DIRECTIONS::W) {
                        snake_direction = Snake::MOVEMENT_DIRECTIONS::E;
                    }
                    break;
                case sf::Keyboard::S:
                    if (snake_direction != Snake::MOVEMENT_DIRECTIONS::N) {
                        snake_direction = Snake::MOVEMENT_DIRECTIONS::S;
                    }
                    break;
                case sf::Keyboard::A:
                    if (snake_direction != Snake::MOVEMENT_DIRECTIONS::E) {
                        snake_direction = Snake::MOVEMENT_DIRECTIONS::W;
                    }
                    break;
                }
            }
        }
        // UPDATE
        time_since_last_cell_simulation_update += delta_time;

        if (time_since_last_cell_simulation_update >= SNAKE_MOVEMENT_UPDATE_INTERVAL)
        {
            time_since_last_cell_simulation_update = sf::Time::Zero;
            snake.move(snake_direction);
            if (scene.snake_intersects_treat())
            {
                snake.grow();
                scene.place_treat_at_random_pos();
            }
            if (scene.snake_intersects_itself_or_wall())
            {
                return EXIT_SUCCESS;
            }
        }

        // RENDER
        window.clear(BACKGROUND_COLOR);
        window.draw(scene);
        if (game_paused) {
            window.draw(pause_screen_message);
        }
        window.display();
    }

    return EXIT_SUCCESS;
} // what can this snake game do differently than others
