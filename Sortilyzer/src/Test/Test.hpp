#pragma once

#include <SFML/Graphics.hpp>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

namespace sortilyzer {
class Test {
public:
  Test();
  virtual ~Test() { std::cout << "Destroying Current Test\n"; }
  virtual void OnUpdate() {}
  virtual void OnRender() {}
  virtual void OnImGuiRender() {}

  void GenerateStipHeight();
  void GenerateStripCoordinate();

  std::vector<int> m_StripHeight;
  std::vector<sf::Vector2f> m_StripCoordinate;
};

class TestMenu : public Test {
public:
  explicit TestMenu(Test *&currentTestPointer);

  void OnImGuiRender() override;

  template <typename T>
  void RegisterTest(const std::string &name, sf::RenderWindow &window) {
    std::cout << "Registering test: " << name << "\n";
    m_Tests.push_back(std::make_pair(name, [&]() { return new T(&window); }));
  }

private:
  Test *&m_currentTest;
  std::vector<std::pair<std::string, std::function<Test *()>>> m_Tests;
};
} // namespace sortilyzer
