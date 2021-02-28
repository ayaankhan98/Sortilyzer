#include "BubbleSortTest.hpp"
#include <imgui.h>

BubbleSortTest::BubbleSortTest(sf::RenderWindow* window):
	m_N(20), m_Window(window) {
	m_StripCoordinate.resize(m_N);
	m_StripHeight.resize(m_N);
	generateStripHeigt();
	generateStripCoordinate();
}

void BubbleSortTest::generateStripHeigt() {
	for (int i = 0; i < m_N; i++) {
		m_StripHeight[i] = 20 + (rand() % 300);
	}
}

void BubbleSortTest::generateStripCoordinate() {
	float xPos = 0;
	for (int i = 0; i < m_N; i++) {
		m_StripCoordinate[i] = sf::Vector2f(xPos + 10, static_cast<float>(768 - m_StripHeight[i] - 200));
		xPos += 20;
	}
}

void BubbleSortTest::OnImGuiRender() {
}

void BubbleSortTest::OnRender() {
	float stripWidth = 20;
	for (int i = 0; i < m_N; i++) {
		sf::RectangleShape strip;
		strip.setFillColor(sf::Color::Green);
		strip.setPosition(m_StripCoordinate[i]);
		strip.setOutlineColor(sf::Color::Magenta);
		strip.setSize({ static_cast<float>(stripWidth), static_cast<float>(m_StripHeight[i]) });
		strip.setOutlineThickness(1.0);
		std::cout << "Drawing strip\n";
		m_Window->draw(strip);
	}
}

void BubbleSortTest::OnUpdate() {
	bool swapped = false;
	for (int i = 0; i < m_N - 1; i++) {
		for (int j = 0; j < m_N - i - 1; j++) {
			if (m_StripHeight[j] > m_StripHeight[j + 1]) {
				std::swap(m_StripHeight[j], m_StripHeight[j + 1]);
				swapped = true;
				break;
			}
			if (swapped)
				break;
		}
	}

	for (int i = 0; i < m_StripCoordinate.size(); i++) {
		m_StripCoordinate[i].y = static_cast<float>(768 - m_StripHeight[i] - 200);
	}
}
