#include "Snake.hpp"

void Snake::add_segment(const float x_pos, const float y_pos, const sf::Color color = SNAKE_BODY_COLOR)
{
    sf::RectangleShape segment(UNIT_SQUARE_VEC2F);
    segment.setPosition(x_pos, y_pos);
    segment.setFillColor(color);
    segments.push_back(segment);
}

void Snake::add_segment(const sf::Vector2f &pos, const sf::Color color = SNAKE_BODY_COLOR)
{
    return add_segment(pos.x, pos.y, color);
}

Snake::Snake(const float x_pos, const float y_pos)
{
    for (int i = 0; i < SNAKE_BODY_STARTING_SEGMENTS; i++)
    {
        add_segment(x_pos, y_pos + (i * UNIT_SQUARE_IN_PX));
    }
    auto &head = segments.front();
    head.setFillColor(SNAKE_HEAD_COLOR);
    tails_last_pos = segments.back().getPosition();
}

void Snake::move(Snake::MOVEMENT_DIRECTIONS dir)
{

    int x = 0;
    int y = 0;

    switch (dir)
    {
    case Snake::MOVEMENT_DIRECTIONS::N:
        y = -1;
        break;
    case Snake::MOVEMENT_DIRECTIONS::E:
        x = 1;
        break;
    case Snake::MOVEMENT_DIRECTIONS::S:
        y = 1;
        break;
    case Snake::MOVEMENT_DIRECTIONS::W:
        x = -1;
        break;
    }

    const auto &head_position = segments.front().getPosition();
    sf::Vector2f new_position(head_position.x + (x * UNIT_SQUARE_IN_PX), head_position.y + (y * UNIT_SQUARE_IN_PX));

    for (auto &segment : segments)
    {
        auto old_position = segment.getPosition();
        segment.setPosition(new_position); // position of the one before it
        new_position = old_position;
    }
    tails_last_pos = new_position;
}

void Snake::grow()
{
    add_segment(tails_last_pos);
}

void Snake::draw(sf::RenderTarget &target, sf::RenderStates states = sf::RenderStates::Default) const
{
    for (const auto &segment : segments)
    {
        target.draw(segment, states);
    }
}
