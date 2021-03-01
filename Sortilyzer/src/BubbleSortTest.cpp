#include "BubbleSortTest.hpp"
#include "Core.hpp"

#include <imgui.h>

sortilyzer::test::BubbleSortTest::BubbleSortTest(sf::RenderWindow* window) {
	m_Window = window;
	std::cout << "Creating Bubble Sort Test\n";
}

void sortilyzer::test::BubbleSortTest::OnImGuiRender() {
	if (ImGui::Button("Restart Simulation")) {
		GenerateStipHeight();
	}
	ImGui::ColorPicker4("Strip Color", m_StripColor);
}

void sortilyzer::test::BubbleSortTest::OnRender() {
	sf::Color currentFillColor = sf::Color(
		static_cast<uint8_t>(m_StripColor[0] * 255), 
		static_cast<uint8_t>(m_StripColor[1] * 255),
		static_cast<uint8_t>(m_StripColor[2] * 255),
		static_cast<uint8_t>(m_StripColor[3] * 255)
	);
	for (int i = 0; i < sortilyzer::SIZE; i++) {
		sf::RectangleShape strip;
		strip.setFillColor(currentFillColor);
		strip.setPosition(m_StripCoordinate[i]);
		strip.setOutlineColor(sf::Color::Magenta);
		strip.setSize({ static_cast<float>(sortilyzer::_STRIP_WIDTH), static_cast<float>(m_StripHeight[i]) });
		strip.setOutlineThickness(1.0);
		m_Window->draw(strip);
	}
}

void sortilyzer::test::BubbleSortTest::OnUpdate() {
	bool swapped = false;
	for (int i = 0; i < sortilyzer::SIZE - 1; i++) {
		for (int j = 0; j < sortilyzer::SIZE - i - 1; j++) {
			if (m_StripHeight[j] > m_StripHeight[j + 1]) {
				std::swap(m_StripHeight[j], m_StripHeight[j + 1]);
				swapped = true;
				break;
			}
			if (swapped)
				break;
		}
	}

	for (int i = 0; i < sortilyzer::SIZE; i++) {
		m_StripCoordinate[i].y = static_cast<float>(sortilyzer::_HEIGHT - m_StripHeight[i] - sortilyzer::_Y_DOWN_OFFSET);
	}
}
