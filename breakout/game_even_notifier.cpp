#include "game_event_notifier.h"
#include <iostream>
using namespace std;

// Rename to Subject?
GameEventNotifier::GameEventNotifier() {
	this->numObservers = 0;
}

void GameEventNotifier::addObserver(Observer *observer) {
	this->observers[numObservers++] = observer;
}

void GameEventNotifier::notify(EventName event) {
	for (int i = 0; i < numObservers; i++) {
		observers[i]->update(event);
	}
}

GameEventNotifier::~GameEventNotifier() {
}
