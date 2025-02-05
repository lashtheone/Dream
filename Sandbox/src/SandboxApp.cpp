#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <stack>
#include <Dream.h>

class Sandbox :public Dream::Application {
public:
	Sandbox() {

	}
	~Sandbox() {

	}
};

Dream::Application* Dream::CreateApplication() {
	return new Sandbox();
}