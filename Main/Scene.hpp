#pragma once
#include "Snake.hpp"
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <memory>

class Scene : public sf::Drawable
{
  private:
    std::unique_ptr<sf::RectangleShape> treat;

  public:
    const Snake &snake;

    static sf::Vector2f snap_point_to_unit_square(const int &x, const int &y);
    static sf::Vector2f snap_point_to_unit_square(const sf::Vector2f &point);
    Scene(const Snake &in_snake) : snake(in_snake)
    {
    }
    void place_treat_at_random_pos();
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    bool snake_intersects_itself_or_wall() const;
    bool snake_intersects_treat() const;
};
