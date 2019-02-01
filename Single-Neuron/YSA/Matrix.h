#pragma once

ref class Matrix {
private:
	double **array;
	int row;
	int column;

public:
	Matrix();
	Matrix(int row, int column);
	~Matrix();

	Matrix^ operator * (Matrix^);
	Matrix^ operator * (double);
	void operator += (Matrix^);

	Matrix^ transpose();
	void random();
	void set(double, int, int);
	double get(int, int);
};