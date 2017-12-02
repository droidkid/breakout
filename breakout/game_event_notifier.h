#pragma once
#include "observer.h"
#include "event_name.h"

class GameEventNotifier {
	Observer *observers[5];
	int numObservers;
public:
	GameEventNotifier();
	void addObserver(Observer *observer);
	void notify(EventName eventName);
	~GameEventNotifier();
};

