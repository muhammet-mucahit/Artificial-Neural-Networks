#pragma once
class AnnPoint {
private:
	AnnPoint* next;
	double x;
	double y;
	int classId;
public:
	AnnPoint(double = 0, double = 0, int classId = 0);
	~AnnPoint();
	void setX(double x);
	double getX();
	void setY(double y);
	double getY();
	void setClassId(int classId);
	int getClassId();
	void setNext(AnnPoint* next);
	AnnPoint* getNext();
};