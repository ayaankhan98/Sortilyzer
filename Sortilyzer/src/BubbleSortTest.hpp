#pragma once
#include "Test/Test.hpp"

namespace sortilyzer {
namespace test {
class BubbleSortTest : public Test {
public:
  explicit BubbleSortTest(sf::RenderWindow *);
  ~BubbleSortTest() { std::cout << "Destroyed Bubble Sort Test\n"; }
  void OnUpdate() override;
  void OnRender() override;
  void OnImGuiRender() override;

private:
  sf::RenderWindow *m_Window;
  float m_StripColor[4] = {0.7, 0.9, 0.7, 1.0};
  int prevI, prevJ;
};
} // namespace test
} // namespace sortilyzer