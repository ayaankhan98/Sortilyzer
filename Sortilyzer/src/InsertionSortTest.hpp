#pragma once

#include "Test/Test.hpp"

namespace sortilyzer {
namespace test {

class InsertionSortTest : public Test {
public:
  explicit InsertionSortTest(sf::RenderWindow *);
  ~InsertionSortTest() { std::cout << "Destroyed Insertion Sort Test\n"; }

  void OnUpdate() override;
  void OnRender() override;
  void OnImGuiRender() override;

private:
  sf::RenderWindow *m_Window;
  float m_StripColor[4] = {0.7, 0.9, 0.7, 1.0};
  int prevI;
  int prevJ;
};

} // namespace test
} // namespace sortilyzer