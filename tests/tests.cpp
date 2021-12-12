#include "pch.h"
#include "CppUnitTest.h"

/**
"If a component is hard to test, it is not properly designed.
If a component is easy to test, it is a good indication that it is properly designed.
If a component is properly designed, it is easy to test." - Oleg Rabaev on CppCast
https://cppcast.com/testing-oleg-rabaev/
*/

/*
Documentation:
https://docs.microsoft.com/en-us/visualstudio/test/writing-unit-tests-for-c-cpp?view=vs-2022
https://docs.microsoft.com/en-us/visualstudio/test/how-to-use-microsoft-test-framework-for-cpp?view=vs-2022#object_files
*/
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace tests
{
	TEST_CLASS(snake_tests)
	{
	public:
		
		TEST_METHOD(SnakeStartingBodySegmentsTest)
		{
			Snake snake(0.f, 0.f);
			Assert::AreEqual(static_cast<int>(snake.get_segments().size()), SNAKE_BODY_STARTING_SEGMENTS);
		}
		TEST_METHOD(SnakeGrowthTest)
		{
			Snake snake(0.f, 0.f);
			snake.grow();
			snake.grow();
			snake.grow();
			Assert::AreEqual(static_cast<int>(snake.get_segments().size()), SNAKE_BODY_STARTING_SEGMENTS + 3);
		}
	};
}
