#include "Test.hpp"

#include "Core.hpp"
#include "imgui.h"

namespace sortilyzer {

Test::Test() {
  m_StripHeight.resize(SIZE);
  m_StripCoordinate.resize(SIZE);
  GenerateStipHeight();
  GenerateStripCoordinate();
}

void Test::GenerateStipHeight() {
  std::cout << "Generating New Test Data\n";
  for (int i = 0; i < SIZE; i++) {
    m_StripHeight[i] = _MIN_STRIP_HEIGHT + (rand() % _MAX_STRIP_HEIGHT);
  }
}

void Test::GenerateStripCoordinate() {
  float xPos = _XPOS;
  for (int i = 0; i < SIZE; i++) {
    m_StripCoordinate[i] = sf::Vector2f(
        xPos + 10, static_cast<float>(768 - m_StripHeight[i] - 200));
    xPos += _STRIP_WIDTH;
  }
}

TestMenu::TestMenu(Test *&currentTestPointer)
    : m_currentTest(currentTestPointer) {}

void TestMenu::OnImGuiRender() {
  for (auto &test : m_Tests) {
    if (ImGui::Button(test.first.c_str())) {
      m_currentTest = test.second();
    }
  }
}
} // namespace sortilyzer