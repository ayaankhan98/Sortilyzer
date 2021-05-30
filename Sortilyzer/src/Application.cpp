#include <SFML/Graphics.hpp>
#include <imgui-SFML.h>
#include <imgui.h>

#include <cstdlib>
#include <string>

#include "BubbleSortTest.hpp"
#include "Core.hpp"
#include "InsertionSortTest.hpp"
#include "QuickSortTest.hpp"
#include "SelectionSortTest.hpp"
#include "Test/Test.hpp"

int main() {
  srand(time(0));

  sf::RenderWindow window(
      sf::VideoMode(sortilyzer::_WIDTH, sortilyzer::_HEIGHT),
      sortilyzer::windowTitle, sf::Style::Default);
  int *_FRAME_RATE = new int(30);
  window.setActive(true);

  bool isOpenWindow = true;
  ImGui::SFML::Init(window);
  sf::Clock deltaClock;

  sf::Texture logo;
  if (!logo.loadFromFile("./assets/trans.png")) {
    std::cout << "Unable to load logo\n";
  }
  sf::Sprite sp;
  sp.setTexture(logo);
  sp.setPosition({20.0f, 150.0f});
  sp.setScale({0.2, 0.2});

  sortilyzer::Test *currentTest(nullptr);
  sortilyzer::TestMenu *testMenu = new sortilyzer::TestMenu(currentTest);
  currentTest = testMenu;

  testMenu->RegisterTest<sortilyzer::test::BubbleSortTest>("Bubble Sort",
                                                           window);
  testMenu->RegisterTest<sortilyzer::test::InsertionSortTest>("Insertion Sort",
                                                              window);
  testMenu->RegisterTest<sortilyzer::test::SelectionSortTest>("Selection Sort",
                                                              window);
  testMenu->RegisterTest<sortilyzer::test::QuickSortTest>("Quick Sort", window);
  while (isOpenWindow) {
    window.setFramerateLimit(*_FRAME_RATE);
    sf::Event e;
    while (window.pollEvent(e)) {
      ImGui::SFML::ProcessEvent(e);
      if (e.type == sf::Event::Closed) {
        isOpenWindow = false;
      }
    }

    ImGui::SFML::Update(window, deltaClock.restart());

    window.clear();
    if (currentTest == testMenu) {
      window.draw(sp);
    }
    if (currentTest) {
      currentTest->OnRender();
      currentTest->OnUpdate();
      ImGui::Begin("Test Menu");
      ImGui::SliderInt("FPS", _FRAME_RATE, 1, 100);

      if (ImGui::Button("Exit App")) {
        isOpenWindow = false;
      }

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