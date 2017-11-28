#include "notifier.h"

Notifier::Notifier() {
	this->numObservers = 0;
}

void Notifier::addObserver(Observer *observer) {
	observers[numObservers++] = observer;
}

void Notifier::notify(Event event) {
	for (int i = 0; i < numObservers; i++) {
		observers[i]->update(event);
	}
}

Notifier::~Notifier() {
}
