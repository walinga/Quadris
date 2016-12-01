#include "Subject.h"
#include "subscriptions.h"
#include <vector>
#include <iostream>
using namespace std;

Subject::~Subject() {
	
}

void Subject::attach(Observer* o) {
	observers.push_back(o);
}

void Subject::notifyObservers(SubscriptionType t) {
	for (auto i:observers) {
		if (i->subType() == t) i->notify(*this);
	}
}

