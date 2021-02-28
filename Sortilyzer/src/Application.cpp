#include <cstdlib>
#include <string>


#include <SFML/Graphics.hpp>
#include <imgui.h>
#include <imgui-SFML.h>

#include "Test.hpp"
#include "BubbleSortTest.hpp"

int main() {
	srand(time(0));

	int _WIDTH = 1640;
	int _HEIGHT = 768;
	std::string windowTitle = "My Application Window";
	sf::RenderWindow window(sf::VideoMode(_WIDTH, _HEIGHT), windowTitle);
	
	window.setActive(true);

	bool isOpenWindow = true;
	ImGui::SFML::Init(window);
	sf::Clock deltaClock;

	Test* currentTest(nullptr);
	TestMenu* testMenu = new TestMenu(currentTest);
	currentTest = testMenu; 

	testMenu->RegisterTest<BubbleSortTest>("Bubble Sort", window);


	while (isOpenWindow) {
		sf::Event e;
		while (window.pollEvent(e)) {
			ImGui::SFML::ProcessEvent(e);
			if (e.type == sf::Event::Closed) {
				isOpenWindow = false;
			}
		}

		ImGui::SFML::Update(window, deltaClock.restart());
		// Render Imgui;

		window.clear();
		// Draw shape in window window.draw(shape)
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