#include <imgui.h>

#include "Core.hpp"
#include "QuickSortTest.hpp"

sortilyzer::test::QuickSortTest::QuickSortTest(sf::RenderWindow *window) {
  m_Window = window;
  N = m_StripHeight.size();
  if (N < 1) {
    return;
  }
  lower.push(0);
  upper.push(N - 1);
  loc = getPivotAsMiddle(0, N - 1);
  beg = end = left = right = -1;
  std::cout << "Creating Quick Sort Test\n";
}

void sortilyzer::test::QuickSortTest::OnImGuiRender() {
  if (ImGui::Button("Restart Simulation")) {
    GenerateStipHeight();
    N = m_StripHeight.size();
    if (N < 1) {
      return;
    }
    lower.push(0);
    upper.push(N - 1);
    loc = getPivotAsMiddle(0, N - 1);
    beg = end = left = right = -1;
    state = false;
  }
  ImGui::ColorPicker4("Strip Color", m_StripColor);
}

void sortilyzer::test::QuickSortTest::OnRender() {
  m_Window->clear();
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

void sortilyzer::test::QuickSortTest::quick() {
  if (left < right) {
    assert(left != -1);
    assert(right != -1);
    while (m_StripHeight[loc] <= m_StripHeight[right] && loc != right) {
      right -= 1;
    }
    if (m_StripHeight[loc] > m_StripHeight[right]) {
      std::swap(m_StripHeight[loc], m_StripHeight[right]);
      loc = right;
    }

    while (m_StripHeight[left] <= m_StripHeight[loc] && left != loc) {
      left += 1;
    }
    if (m_StripHeight[left] > m_StripHeight[loc]) {
      std::swap(m_StripHeight[left], m_StripHeight[loc]);
      loc = left;
    }
  }
}

int sortilyzer::test::QuickSortTest::getPivotAsMiddle(int start, int end) {
  return (start + end) / 2;
}

void sortilyzer::test::QuickSortTest::OnUpdate() {
  if (left < right) {
    quick();
    state = true;
  } else {
    if (state) {
      if (beg < loc - 1) {
        lower.push(beg);
        upper.push(loc - 1);
      }
      if (loc + 1 < end) {
        lower.push(loc + 1);
        upper.push(end);
      }
    }
    if (!lower.empty() && !upper.empty()) {
      beg = lower.top();
      lower.pop();
      end = upper.top();
      upper.pop();

      loc = getPivotAsMiddle(beg, end);
      left = beg;
      right = end;
      quick();
    }
  }
  for (int i = 0; i < sortilyzer::SIZE; i++) {
    m_StripCoordinate[i].y = static_cast<float>(
        sortilyzer::_HEIGHT - m_StripHeight[i] - sortilyzer::_Y_DOWN_OFFSET);
  }
}