#pragma once

#include "event.h"

class Observer {
public:
	virtual void update(Event event) = 0;
};
