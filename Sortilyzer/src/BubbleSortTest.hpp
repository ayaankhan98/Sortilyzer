//#pragma once

#include "Test.hpp"

class BubbleSortTest : public Test {
public:
	BubbleSortTest(sf::RenderWindow*);
	~BubbleSortTest() {
		std::cout << "Destroyed Bubble sort test\n";
	}
	void OnUpdate() override;
	void OnRender() override;
	void OnImGuiRender() override;

	void generateStripHeigt();
	void generateStripCoordinate();
private:
	int m_N;
	std::vector<int> m_StripHeight;
	std::vector<sf::Vector2f> m_StripCoordinate;
	sf::RenderWindow* m_Window;
};
