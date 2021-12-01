#pragma once

#include "Test/Test.hpp"
#include <stack>

namespace sortilyzer {
namespace test {
class QuickSortTest : public Test {
public:
  explicit QuickSortTest(sf::RenderWindow *);
  ~QuickSortTest() { std::cout << "Destroying QuickSort Test\n"; }

  void OnRender() override;
  void OnUpdate() override;
  void OnImGuiRender() override;

private:
  int getPivotAsMiddle(int start, int end);
  void quick();
  sf::RenderWindow *m_Window;
  float m_StripColor[4] = {0.7, 0.9, 0.7, 1.0};
  std::stack<int> lower, upper;
  int N, loc, beg, end, left, right;
  bool state = false;
};
} // namespace test
} // namespace sortilyzer