#include "MyVector.h"
#include <iostream>
using namespace std;

MyVector::MyVector()
{
	arr = nullptr;
	size = 0;
}

MyVector::MyVector(int s)
{
	size = s;
	arr = new int[size];
}

void MyVector::Init()
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 50;
	}
}

void MyVector::Print()
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

MyVector::~MyVector()
{
	delete[] arr;
	size = 0;
}

int MyVector::GetSize() const
{
	return size;
}



int& MyVector::operator[](int index)
{
	if (index >= 0 && index < size)
	{
		return arr[index];
	}
}

MyVector::MyVector(const MyVector& obj2)
{
	size = obj2.size;
	arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = obj2.arr[i];
	}
}

MyVector::MyVector(MyVector&& obj2)
{
	size = obj2.size;
	obj2.size = 0;

	arr = obj2.arr;
	obj2.arr = nullptr;
}

MyVector& MyVector::operator=(MyVector& obj2)
{
	if (this == &obj2)
	{
		return *this;
	}

	if (arr != nullptr)
	{
		delete[] arr;
	}

	size = obj2.size;
	arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = obj2.arr[i];
	}

	return *this;
}

MyVector MyVector::operator++(int)
{
	MyVector temp = *this;

	int newSize = size + 1;
	int* newArr = new int[newSize];
	for (int i = 0; i < size; i++)
	{
		newArr[i] = arr[i];
	}
	newArr[size] = 0;

	delete[] arr;
	arr = newArr;
	size = newSize;

	return temp;
}

MyVector MyVector::operator--(int)
{
	MyVector temp = *this;

	int newSize = size - 1;
	int* newArr = new int[newSize];
	for (int i = 0; i < size - 1; i++)
	{
		newArr[i] = arr[i];
	}

	delete[] arr;
	arr = newArr;
	size = newSize;

	return temp;
}

MyVector::operator int()
{
	return size;
}

void MyVector::operator()()
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

MyVector& MyVector::operator+=(int b)
{
	int newSize = size + b;
	int* newArr = new int[newSize];
	for (int i = 0; i < size; i++)
	{
		newArr[i] = arr[i];
	}
	for (int i = size; i < newSize; i++)
	{
		newArr[i] = rand() % 50;
	}

	delete[] arr;
	arr = newArr;
	size = newSize;

	return *this;
}

MyVector& MyVector::operator-=(int b)
{
	if (b > size)
	{
		int newSize = 0;
		int* newArr = new int[newSize];
		for (int i = 0; i < size - b; i++)
		{
			newArr[i] = arr[i];
		}

		delete[] arr;
		arr = newArr;
		size = newSize;

		return *this;
	}
	else
	{
		int newSize = size - b;
		int* newArr = new int[newSize];
		for (int i = 0; i < size - b; i++)
		{
			newArr[i] = arr[i];
		}

		delete[] arr;
		arr = newArr;
		size = newSize;

		return *this;
	}
}

MyVector& MyVector::operator*=(int b)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] *= 5;
	}
	return *this;
}

MyVector& MyVector::operator=(MyVector&& b)
{
	size = b.size;
	arr = b.arr;
	b.size = 0;
	b.arr = nullptr;

	return *this;
}

void MyVector::SetSize(int s)
{
	size = s;
}

void MyVector::Add(int i, int a)
{
	arr[i] = a;
}

void MyVector::NewArr(int s)
{
	size = s;
	arr = new int[size];
}
