#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <windows.h>

int main() {
	srand(time(0));
	const int WIDTH = 1680;
	const int HEIGHT = 768;
	const int N = 80;
	sf::RenderWindow window;
	window.create(sf::VideoMode(WIDTH, HEIGHT), "My Application Window");

	std::vector<int> stripHeight(N);
	auto generate = [&]() {
		for (int i = 0; i < stripHeight.size(); i++) {
			stripHeight[i] = 20 + rand() % 300;
		}
	};

	generate();

	std::vector<sf::Vector2f> stripCoordinate(N);
	int xPos = 0, stripWidth = 20;
	for (int i = 0; i < stripCoordinate.size(); i++) {
		stripCoordinate[i] = { static_cast<float>(xPos + stripWidth), static_cast<float>(HEIGHT - stripHeight[i] - 200) };
		xPos += stripWidth;
	}

	auto update = [&]() {
		bool swapped = false;
		for (int i = 0; i < N - 1; i++) {
			for (int j = 0; j < N - i - 1; j++) {
				if (stripHeight[j] > stripHeight[j + 1]) {
					std::swap(stripHeight[j], stripHeight[j + 1]);
					swapped = true;
					break;
				}
				if (swapped)
					break;
			}
		}

		for (int i = 0; i < stripCoordinate.size(); i++) {
			stripCoordinate[i].y = static_cast<float>(HEIGHT - stripHeight[i] - 200);
		}
	};

	auto draw = [&]() {
		for (int i = 0; i < stripCoordinate.size(); i++) {
			sf::RectangleShape strip;
			strip.setSize({ static_cast<float>(stripWidth), static_cast<float>(stripHeight[i]) });
			strip.setPosition(stripCoordinate[i]);
			strip.setOutlineColor(sf::Color::Red);
			strip.setOutlineThickness(1.0);
			strip.setFillColor(sf::Color::Green);
			window.draw(strip);
		}
	};

	bool isOpenWindow = true;
	while (isOpenWindow) {
		sf::Event e;
		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed) {
				isOpenWindow = false;
			}
		}
		window.clear(sf::Color(sf::Color::Black));
		draw();
		if (!std::is_sorted(stripHeight.begin(), stripHeight.end())) {
			Sleep(10);
			update();
		}
		if (e.type == sf::Event::MouseButtonPressed) {
			generate();
		}
		window.display();
	}
	return 0;
}