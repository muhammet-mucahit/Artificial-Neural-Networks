#include "AnnPoint.h"

AnnPoint::AnnPoint(double x, double y, int classId)
{
	this->next = nullptr;
	this->x = x;
	this->y = y;
	this->classId = classId;
}

AnnPoint::~AnnPoint()
{
	if (this->next != nullptr)
	{
		next->~AnnPoint();
	}
}

void AnnPoint::setX(double x) {
	this->x = x;
}

double AnnPoint::getX() {
	return x;
}

void AnnPoint::setY(double y) {
	this->y = y;
}

double AnnPoint::getY() {
	return y;
}

void AnnPoint::setClassId(int classId) {
	this->classId = classId;
}

int AnnPoint::getClassId() {
	return classId;
}

void AnnPoint::setNext(AnnPoint* next) {
	this->next = next;
}

AnnPoint* AnnPoint::getNext() {
	return this->next;
}