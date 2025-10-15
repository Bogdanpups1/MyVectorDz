#include <iostream>
#include "MyVector.h"
#include <time.h>
using namespace std;

MyVector operator+ (int a, MyVector& obj2)
{
	MyVector result = obj2;
	for (int i = 0; i < result.GetSize(); i++)
	{
		result[i] += a;
	}
	return result;
}

MyVector operator--(MyVector& obj2)
{
	MyVector temp(obj2.GetSize() - 1);
	for (int i = 1; i < obj2.GetSize(); i++)
	{
		temp[i - 1] = obj2[i];
	}
	obj2 = temp;
	return obj2;
}

ostream& operator<<(ostream& os, MyVector& obj)
{
	os << "Your arr:" << endl;
	for (int i = 0; i < obj.GetSize(); i++)
	{
		os << obj[i] << "\t";
	}
	os << endl;
	os << "Your size:" << endl;
	os << obj.GetSize() << endl;
	return os;
}

istream& operator>>(istream& is, MyVector& obj)
{
	if (obj.GetSize() == 0)
	{
		int s;
		cout << "Enter size of arr: " << endl;
		is >> s;
		obj.NewArr(s);
	}
	int a;
	for (int i = 0; i < obj.GetSize(); i++)
	{
		cout << "Enter: " << i + 1 << " element: " << endl;
		is >> a;
		obj.Add(i, a);
	}
	return is;
}

int main()
{
	srand(unsigned(time(0)));

	MyVector v(10);
	v.Init();
	v.Print();

	MyVector v2;
	cin >> v2;
	cout << v2 << endl;

	MyVector v3(10);
	cin >> v3;
	cout << v3 << endl;

	/*MyVector v2 = 5 + v;
	v2.Print();
	--v2;
	v2.Print();

	for (int i = 0; i < v.GetSize(); i++)
	{
		cout << v[i] << "\t";
	}
	cout << endl;

	MyVector v3 = v;
	v3.Print();

	MyVector v4 = move(v);
	v4.Print();
	v.Print();

	MyVector v5 = v2++;
	v5.Print();
	v2.Print();

	MyVector v6 = v3--;
	v6.Print();
	v3.Print();

	int size = v;
	cout << size << endl;

	v();

	v += 5;
	v();

	v2 -= 5;
	v2();

	v2 -= 6;
	v2();

	v2 += 2;
	v2();

	v *= 5;
	v();

	MyVector vec3;
	vec3 = move(v);
	vec3();
	cout << v.GetSize() << endl;*/
}
