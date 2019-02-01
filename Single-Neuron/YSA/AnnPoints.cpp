#include "AnnPoints.h"
#include <iostream>

using namespace::std;

AnnPoints::AnnPoints()  {
	this->points = new AnnPoint();
}

AnnPoints::~AnnPoints() {
	AnnPoint* p = points;
	if (p != nullptr) {
		p->~AnnPoint();
	}
}

void AnnPoints::addPoint(int x, int y, int classId) {
	AnnPoint* p = points;

	while (p->getNext() != nullptr) {
		p = p->getNext();
	}

	p->setNext(new AnnPoint(x, y, classId));
}

AnnPoint* AnnPoints::getPoints() {
	return points;
}