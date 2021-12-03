#include "Scene.hpp"

void Scene::place_treat_at_random_pos() {
	int rand_x = 0;
	int rand_y = 0;

	bool get_random_position = true;
	while (get_random_position) {
		rand_x = rand() % WINDOW_BOUNDS_X;
		rand_y = rand() % WINDOW_BOUNDS_Y;
		for (const auto& segment : snake.get_segments()) {
			if (!segment.getGlobalBounds().contains(static_cast<float>(rand_x), static_cast<float>(rand_y))) {
				get_random_position = false;
				break;
			}
		}
	}
	// snap treat to grid
	rand_x = rand_x - (rand_x % UNIT_SQUARE_IN_PX);
	rand_y = rand_y - (rand_y % UNIT_SQUARE_IN_PX);

	treat = std::make_unique<sf::RectangleShape>(UNIT_SQUARE_VEC2F);
	treat->setPosition(static_cast<float>(rand_x), static_cast<float>(rand_y));
	treat->setFillColor(TREAT_COLOR);
}

 void Scene::draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const {
	target.draw(*treat, states);
	target.draw(snake, states);
}

 bool Scene::snake_intersects_itself_or_wall() const
 {
	 bool snake_intersects_itself_or_wall = false;
	 auto snake_segments = snake.get_segments();
	 // grab head and tail
	 const auto head = snake_segments.front().getGlobalBounds();
	 const auto tail = snake_segments.back().getGlobalBounds();
	 // remove head and tail so that they will not be considered a part of the body
	 snake_segments.erase(snake_segments.begin());
	 snake_segments.erase(snake_segments.end());

	 if (head.intersects(tail)) {
		 return true;
	 }

	 for (const auto& segment : snake_segments) {
		 const auto& segment_bounds = segment.getGlobalBounds();
		 if (head.intersects(segment_bounds) || tail.intersects(segment_bounds) || segment_bounds.intersects(PLAY_FIELD_BOUNDS)) {
			 snake_intersects_itself_or_wall = true;
			 break;
		 }
	 }
	 return snake_intersects_itself_or_wall;
 }

 bool Scene::snake_intersects_treat() const
 {
	 auto snake_intersects_treat = false;
	 const auto& snake_segments = snake.get_segments();

	 if (treat) {
		 for (const auto& segment : snake_segments) {
			 if (segment.getGlobalBounds().intersects(treat->getGlobalBounds())) {
				 snake_intersects_treat = true;
				 break;
			 }
		 }
	 }
	 return snake_intersects_treat;
 }

 
