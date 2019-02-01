#include "Matrix.h"
#include <stdlib.h>
#include <math.h>

Matrix::Matrix() {
	this->array = nullptr;
	this->row = 0;
	this->column = 0;
}

Matrix::Matrix(int row, int column) {
	this->row = row;
	this->column = column;

	array = new double*[row];

	for (int i = 0; i < row; i++) {
		array[i] = new double[column];
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			array[i][j] = 0;
		}
	}
}

Matrix::~Matrix() {
	for (int i = 0; i < this->row; i++) {
		delete[] this->array[i];
	}
	delete[] this->array;
}

Matrix^ Matrix::operator>=(int val)
{
	Matrix^ temp = gcnew Matrix(this->row, this->column);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (this->array[i][j] > val)
				temp->array[i][j] = 1;
			else
				temp->array[i][j] = -1;
		}
	}
	return temp;
}

Matrix^ Matrix::transpose() {
	Matrix^ temp = gcnew Matrix(this->column, this->row);
	for (int i = 0; i < temp->row; i++) {
		for (int j = 0; j < temp->column; j++) {
			temp->array[i][j] = this->array[j][i];
		}
	}
	return temp;
}

void Matrix::random() {
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->column; j++) {
			this->array[i][j] = (rand() % 2000) / 1000.0 - 1.0;
		}
	}
}

void Matrix::set(double val, int i, int j) {
	this->array[i][j] = val;
}

double Matrix::get(int i, int j) {
	return this->array[i][j];
}

System::String^ Matrix::toString()
{
	System::String^ s;
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->column; j++) {
			s += "" + this->array[i][j] + " ";
		}
		s += "\n";
	}
	return s;
}

Matrix^ Matrix::sigmoid(double lambda)
{
	Matrix^ temp = gcnew Matrix(this->row, this->column);

	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->column; j++) {
			temp->array[i][j] = (2 / (1 + exp(-lambda * this->array[i][j]))) - 1;
		}
	}

	return temp;
}

Matrix^ Matrix::dot(Matrix ^op)
{
	Matrix^ temp = gcnew Matrix(this->row, this->column);

	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->column; j++) {
			temp->array[i][j] = this->array[i][j] * op->array[i][j];
		}
	}

	return temp;
}

Matrix^ Matrix::operator-(Matrix^ op)
{
	Matrix^ temp = gcnew Matrix(this->row, this->column);
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->column; j++) {
			temp->array[i][j] = this->array[i][j] - op->array[i][j];
		}
	}
	return temp;
}

Matrix^ Matrix::operator*(Matrix^ op)
{
	Matrix^ temp = gcnew Matrix(this->row, op->column);
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < op->column; j++) {
			for (int n = 0; n < this->column; n++) {
				temp->array[i][j] = temp->array[i][j] + (op->array[n][j] * this->array[i][n]);
			}
		}
	}
	return temp;
}

Matrix^ Matrix::operator*(double val)
{
	Matrix^ temp = gcnew Matrix(this->row, this->column);
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->column; j++) {
			temp->array[i][j] = this->array[i][j] * val;
		}
	}
	return temp;
}

void Matrix::operator+=(Matrix ^op) {
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->column; j++) {
			this->array[i][j] += op->array[i][j];
		}
	}
}