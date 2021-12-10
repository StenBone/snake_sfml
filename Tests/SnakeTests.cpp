#include "pch.h"

/**
"If a component is hard to test, it is not properly designed. 
If a component is easy to test, it is a good indication that it is properly designed.
If a component is properly designed, it is easy to test." - Oleg Rabaev on CppCast
https://cppcast.com/testing-oleg-rabaev/
*/


TEST(SnakeTestCase, SnakeStartingBodySegmentsTest) {
	Snake snake(0.f, 0.f);
	EXPECT_EQ(snake.get_segments().size(), SNAKE_BODY_STARTING_SEGMENTS);
}

TEST(SnakeTestCase, SnakeGrowthTest) {
	Snake snake(0.f, 0.f);
	snake.grow();
	snake.grow();
	snake.grow();
	EXPECT_EQ(snake.get_segments().size(), SNAKE_BODY_STARTING_SEGMENTS + 3);
}