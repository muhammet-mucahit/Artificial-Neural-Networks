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

	int getRow() {
		return row;
	}

	int getColumn() {
		return column;
	}

	Matrix^ operator * (Matrix^);
	Matrix^ operator * (double);
	void operator += (Matrix^);
	Matrix^ operator - (Matrix^);
	Matrix^ operator>=(int val);

	Matrix^ transpose();
	void random();
	void set(double, int, int);
	double get(int, int);
	System::String^ toString();
	Matrix^ sigmoid(double);
	Matrix^ dot(Matrix^);
};