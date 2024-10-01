#include<iostream>

using namespace std;

int main() {
	/*
	// Khai báo biến a;
	int a = 5;
	// Khai báo con trỏ p
	int* p;
	// Cho con trỏ p trỏ tới biến a.
	p = &a;
	// In ra địa chỉ của biến a và giá trị của con trỏ p.
	cout << "Address of a: " << &a << endl;
	cout << "Value of p: " << p << endl;
	return 0;
	*/
	char ch = 'a';
	char* p = &ch;
	cout << "Size of p: " << sizeof(p);
	
}