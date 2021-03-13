#include "SelectionSortTest.hpp"

#include <imgui.h>

#include "Core.hpp"

sortilyzer::test::SelectionSortTest::SelectionSortTest(
    sf::RenderWindow *window) {
  m_Window = window;
  prevI = 0;
  std::cout << "Creating Bubble Sort Test\n";
}

void sortilyzer::test::SelectionSortTest::OnImGuiRender() {
  if (ImGui::Button("Restart Simulation")) {
    prevI = 0;
    GenerateStipHeight();
  }
  ImGui::ColorPicker4("Strip Color", m_StripColor);
}

void sortilyzer::test::SelectionSortTest::OnRender() {
  sf::Color currentFillColor =
      sf::Color(static_cast<uint8_t>(m_StripColor[0] * 255),
                static_cast<uint8_t>(m_StripColor[1] * 255),
                static_cast<uint8_t>(m_StripColor[2] * 255),
                static_cast<uint8_t>(m_StripColor[3] * 255));
  for (int i = 0; i < sortilyzer::SIZE; i++) {
    sf::RectangleShape strip;
    strip.setFillColor(currentFillColor);
    strip.setPosition(m_StripCoordinate[i]);
    strip.setOutlineColor(sf::Color::Black);
    strip.setSize({static_cast<float>(sortilyzer::_STRIP_WIDTH),
                   static_cast<float>(m_StripHeight[i])});
    strip.setOutlineThickness(1.0);
    m_Window->draw(strip);
  }
}

void sortilyzer::test::SelectionSortTest::OnUpdate() {
  int min_idx;
  for (int i = prevI; i < sortilyzer::SIZE - 1; i++) {
    min_idx = i;
    for (int j = i + 1; j < sortilyzer::SIZE; j++) {
      if (m_StripHeight[j] < m_StripHeight[min_idx]) {
        min_idx = j;
      }
    }
    std::swap(m_StripHeight[min_idx], m_StripHeight[i]);
    prevI = ++i;
    break;
  }

  for (int i = 0; i < sortilyzer::SIZE; i++) {
    m_StripCoordinate[i].y = static_cast<float>(
        sortilyzer::_HEIGHT - m_StripHeight[i] - sortilyzer::_Y_DOWN_OFFSET);
  }
}
