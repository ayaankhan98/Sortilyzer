#include <imgui-SFML.h>
#include <imgui.h>

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <string>

#include "BubbleSortTest.hpp"
#include "InsertionSortTest.hpp"
#include "Core.hpp"
#include "Test/Test.hpp"

int main() {
  srand(time(0));

  sf::RenderWindow window(
      sf::VideoMode(sortilyzer::_WIDTH, sortilyzer::_HEIGHT),
      sortilyzer::windowTitle);

  window.setActive(true);
  window.setFramerateLimit(sortilyzer::_FRAME_RATE);

  bool isOpenWindow = true;
  ImGui::SFML::Init(window);
  sf::Clock deltaClock;

  sortilyzer::Test *currentTest(nullptr);
  sortilyzer::TestMenu *testMenu = new sortilyzer::TestMenu(currentTest);
  currentTest = testMenu;

  testMenu->RegisterTest<sortilyzer::test::BubbleSortTest>("Bubble Sort",
                                                           window);
  testMenu->RegisterTest<sortilyzer::test::InsertionSortTest>("Insertion Sort",
                                                              window);

  while (isOpenWindow) {
    sf::Event e;
    while (window.pollEvent(e)) {
      ImGui::SFML::ProcessEvent(e);
      if (e.type == sf::Event::Closed) {
        isOpenWindow = false;
      }
    }

    ImGui::SFML::Update(window, deltaClock.restart());

    window.clear();
    if (currentTest) {
      currentTest->OnRender();
      currentTest->OnUpdate();
      ImGui::Begin("Test Menu");

      if (currentTest != testMenu && ImGui::Button("<-")) {
        delete currentTest;
        currentTest = testMenu;
      }
      currentTest->OnImGuiRender();

      ImGui::End();
    }

    ImGui::SFML::Render(window);
    window.display();
  }
  ImGui::SFML::Shutdown();
}