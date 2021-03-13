#include <imgui.h>

#include "Core.hpp"
#include "InsertionSortTest.hpp"

sortilyzer::test::InsertionSortTest::InsertionSortTest(
    sf::RenderWindow *window) {
  m_Window = window;
  prevI = 1, prevJ = 0;
  std::cout << "Creating Insertion Sort Test\n";
}

void sortilyzer::test::InsertionSortTest::OnRender() {
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

void sortilyzer::test::InsertionSortTest::OnUpdate() {
  bool swapped = false;
  for (int i = 1; i < sortilyzer::SIZE; i++) {
    int currentElement = m_StripHeight[i];
    int j = i - 1;
    if (j >= 0 && m_StripHeight[j] > currentElement) {
      m_StripHeight[j + 1] = m_StripHeight[j];
      swapped = true;
      j--;
    }
    m_StripHeight[j + 1] = currentElement;
    prevI = i, prevJ = j;
    if (swapped)
      break;
  }
  for (int i = 0; i < sortilyzer::SIZE; i++) {
    m_StripCoordinate[i].y = static_cast<float>(
        sortilyzer::_HEIGHT - m_StripHeight[i] - sortilyzer::_Y_DOWN_OFFSET);
  }
}

void sortilyzer::test::InsertionSortTest::OnImGuiRender() {
  if (ImGui::Button("Restart Simulation")) {
    prevI = 1, prevJ = 0;
    GenerateStipHeight();
  }
  ImGui::ColorPicker4("Strip Color", m_StripColor);
}