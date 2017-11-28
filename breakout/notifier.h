#pragma once
#include "observer.h"
#include "event.h"

class Notifier {
	Observer *observers[2];
	int numObservers;
public:
	Notifier();
	void addObserver(Observer *observer);
	void notify(Event event);
	~Notifier();
};

