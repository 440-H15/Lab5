#include  "stdafx.h"

using namespace WindowRender;
using namespace ShapeLibrary;



WindowsRender::WindowsRender(IWindowAPI & _windowsApi){
	windowsApi = &_windowsApi;
}

WindowsRender::~WindowsRender(){
	for (int i = 0; i < shapes.size(); i++){
		delete shapes[i];
	}
	shapes.clear();
}

void WindowsRender::render(){
	bool quit = false;

	while (quit == false){

		while (windowsApi->hasEvent()){
			WIN_EVENEMENT evenement = windowsApi->getEvent().getEventType();
			if (evenement == QUIT){
				quit = true;
			}
		}

		windowsApi->clearScreen();

		for (int i = 0; i < shapes.size(); i++){
			shapes[i]->draw();
		}

		windowsApi->displayScreen();
		windowsApi->wait(1000 / 30);
	}
}

void WindowsRender::attach(Shape &_shape){
	shapes.push_back(&_shape);
}

void WindowsRender::putOnTop(Shape &_shape){
	for (int i = 0; i < shapes.size(); i++){
		if (*shapes[i] == _shape){
			shapes.erase(shapes.begin() + i);
			shapes.push_back(&_shape);
		}
	}
}