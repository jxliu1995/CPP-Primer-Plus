//divide.cpp -- integer and floating-point division

#include <iostream>

int main(void)
{
	using namespace std;

	cout.setf(ios_base::fixed, ios_base::floatfield); //fixed point

	cout << "Integer division: 9/5 = " << 9 / 5 << endl;
	cout << "Floating_point division 9.0/5.0 = " << 9.0 / 5.0 << endl;
	cout << "Mixed division: 9.0/5 = " << 9.0 / 5 << endl;
	cout << "Double constants: 1e7/9.0 = " << 1.0e7 / 9.0 << endl;
	cout << "Float constants: 1.0e7f/9.0f = " << 1.0e7f / 9.0f << endl;

	return 0;
}
