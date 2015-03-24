#include  "stdafx.h"
#include "windowEvent.h"
using namespace WindowRender;

WindowEvent::WindowEvent()
{
	eventType = NONE;

}

WindowEvent::WindowEvent( const WIN_EVENEMENT & _eventType )
{
	eventType = QUIT;
}

WIN_EVENEMENT WindowEvent::getEventType() const
{
	return eventType;
}


