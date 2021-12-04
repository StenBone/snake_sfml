#include "Scene.hpp"

sf::Vector2f Scene::snap_point_to_unit_square(const int& x, const int& y)
{
	sf::Vector2f result;
	result.x = x - static_cast<float>(x % UNIT_SQUARE_IN_PX);
	result.y = y - static_cast<float>(y % UNIT_SQUARE_IN_PX);
	return result;
}

sf::Vector2f Scene::snap_point_to_unit_square(const sf::Vector2f& point)
{
	return Scene::snap_point_to_unit_square(static_cast<int>(point.x), static_cast<int>(point.y));
}

void Scene::place_treat_at_random_pos() {
	int rand_x = 0;
	int rand_y = 0;

	bool keep_looking_for_valid_pos = false;
	do {
		keep_looking_for_valid_pos = false;
		rand_x = rand() % SCREEN_WIDTH;
		rand_y = rand() % SCREEN_HEIGHT;
		for (const auto& segment : snake.get_segments()) {
			if (segment.getGlobalBounds().contains(static_cast<float>(rand_x), static_cast<float>(rand_y))) {
				keep_looking_for_valid_pos = true;
				break;
			}
		} 
	} while(keep_looking_for_valid_pos);

	auto snapped_to_unit_square = Scene::snap_point_to_unit_square(rand_x, rand_y);
	treat = std::make_unique<sf::RectangleShape>(UNIT_SQUARE_VEC2F);
	treat->setPosition(snapped_to_unit_square);
	treat->setFillColor(TREAT_COLOR);
}

 void Scene::draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const {
	target.draw(*treat, states);
	target.draw(snake, states);
}

 bool Scene::snake_intersects_itself_or_wall() const
 {
	 bool snake_intersects_itself_or_wall = false;
	 const auto& snake_segments = snake.get_segments();
	 // grab head and tail
	 const auto head = snake_segments.front().getGlobalBounds();
	 const auto tail = snake_segments.back().getGlobalBounds();

	 if (head.intersects(tail) || !head.intersects(PLAY_FIELD_BOUNDS) || !tail.intersects(PLAY_FIELD_BOUNDS)) {
		 return true;
	 }

	 for (int i = 1; i < snake_segments.size() - 1; i++) {
		 const auto& segment_bounds = snake_segments[i].getGlobalBounds();
		 if (head.intersects(segment_bounds) || tail.intersects(segment_bounds) || !segment_bounds.intersects(PLAY_FIELD_BOUNDS)) {
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

 
