#pragma once

class MyVector
{
	int* arr;
	int size;
public:
	MyVector();
	MyVector(int s);
	void Init();
	void Print();
	~MyVector();
	int GetSize()const;
	int& operator[](int index);
	MyVector(const MyVector& obj2);
	MyVector(MyVector&& obj2);
	MyVector& operator=(MyVector& obj2);
	MyVector operator++(int);
	MyVector operator--(int);

	operator int();
	void operator()();
	MyVector& operator+=(int b);
	MyVector& operator-=(int b);
	MyVector& operator*=(int b);
	MyVector& operator =(MyVector&& b);

	void SetSize(int s);
};

