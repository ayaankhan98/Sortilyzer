#pragma once

#include "Test/Test.hpp"

namespace sortilyzer {
namespace test {
class SelectionSortTest : public Test {
public:
  explicit SelectionSortTest(sf::RenderWindow *);
  ~SelectionSortTest() { std::cout << "Destroying Selection Sort Test\n"; }

  void OnRender() override;
  void OnUpdate() override;
  void OnImGuiRender() override;

private:
  sf::RenderWindow *m_Window;
  float m_StripColor[4] = {0.7, 0.9, 0.7, 1.0};
  int prevI;
};
} // namespace test
} // namespace sortilyzer