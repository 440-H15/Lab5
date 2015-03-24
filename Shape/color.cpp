#include "stdafx.h"
#include "color.h"
using namespace ShapeLibrary;

Color::Color()
	:color( Color::WHITE),      // couleur par defaut
	visibility(Color::VISIBLE)
{
}

Color::Color(const COLOR_TYPE & _color)
{
	 this->color =_color;
	 visibility = Color::VISIBLE;
}

Color::Color(const TRANSPARENCY & _visibility)
{
	color = Color::WHITE;  // couleur par defaut
	visibility = _visibility;
}

int Color::getColorAsInt() const
{
	return color; 
}

bool Color::isVisible() const
{
	return (visibility == Color::VISIBLE);
}
