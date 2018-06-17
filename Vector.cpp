#include "Vector.h"
#include <assert.h>
#include <cmath>

Vector::Vector(int size)
{
	this->size = size;
	this->v = new double[size];
	for (int i = 0; i < size; i++)
		v[i] = 0;
}

Vector::Vector(const Vector& rhs)
{
	this->size = rhs.size;
	this->v = new double[size];
	for (int i = 0; i < size; i++)
		v[i] = rhs[i];
}

double Vector::Norm() const
{
	double ret = 0;
	for (int i = 0; i < size; i++)
		ret += v[i];
	ret = std::sqrt(ret);
	return ret;
}

int Vector::Size() const
{
	return int(size);
}

double &Vector::operator[](const int idx) const
{
	assert(idx >= 0 && idx < size);
	return v[idx];
}

double Vector::InnerProduct(const Vector & rhs) const
{
	assert(size == rhs.size);
	double ret = 0;
	for (int i = 0; i < size; i++)
		ret += v[i] * rhs[i];
	
	return ret;
}



Vector Vector::operator-(const Vector & rhs) const
{
	Vector ret = *this;
	for (int i = 0; i < size; i++)
		ret[i] -= rhs[i];
	return ret;
}

Vector Vector::operator+(const Vector & rhs) const
{
	Vector ret = *this;
	for (int i = 0; i < size; i++)
		ret[i] += rhs[i];
	return ret;
}

Vector Vector::operator*(const double & rhs) const
{
	Vector ret = *this;
	for (int i = 0; i < size; i++)
		ret[i] *= rhs;
	return ret;
}

Vector operator*(const double & d, const Vector & v)
{
	Vector ret = v;
	for (int i = 0; i < v.Size(); i++)
		ret[i] *= d;
	return ret;
}
