#include "Test.hpp"
#include "imgui.h"

TestMenu::TestMenu(Test*& currentTestPointer)
	:m_currentTest(currentTestPointer) {}

void TestMenu::OnImGuiRender() {
	for (auto& test : m_Tests) {
		if (ImGui::Button(test.first.c_str())) {
			m_currentTest = test.second();
		}
	}
}