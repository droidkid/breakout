#pragma once

#include "event_name.h"

class Observer {
public:
	virtual void update(EventName event) = 0; // Add a data parameter? Not needed now, but might be needed later.
};
