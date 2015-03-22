#pragma once
#include "stdafx.h"


using namespace ShapeLibrary;

namespace UnitTests
{
	class FakeWindowAPI;

	void main()
	{
		UnitTests::FakeWindowAPI * fakeWindowAPI ;
		ShapeLibrary::OpenPolyline * openPolyLine;


		fakeWindowAPI = new UnitTests::FakeWindowAPI(640, 480, "Super beau dessin");
		openPolyLine = new ShapeLibrary::OpenPolyline(*fakeWindowAPI);
		//Arrange
		const int NOMBRE_DE_LIGNE_DESSINEES = 2;

		openPolyLine->add(ShapeLibrary::Point(200, 200));
		openPolyLine->add(ShapeLibrary::Point(250, 275));
		openPolyLine->add(ShapeLibrary::Point(375, 225));

		//Action
		openPolyLine->draw();
	}
}

