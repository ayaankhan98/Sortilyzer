//#pragma once
#include "Test/Test.hpp"

namespace sortilyzer {
	namespace test {
		class BubbleSortTest : public Test {
		public:
			BubbleSortTest(sf::RenderWindow*);
			~BubbleSortTest() {
				std::cout << "Destroyed Bubble Sort Test\n";
			}
			void OnUpdate() override;
			void OnRender() override;
			void OnImGuiRender() override;

		private:
			sf::RenderWindow* m_Window;
			float m_StripColor[4] = {0.0, 0.9, 0.0, 1.0};
		};
	}
}