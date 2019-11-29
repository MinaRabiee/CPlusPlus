#include <cstdio>
#include <iostream>
using namespace std;

class FractionNum {
	int _n = 0;
	int _d = 1;
public:
	FractionNum(int numerator = 0, int denominator = 1) : _n(numerator), _d(denominator) {};
	FractionNum(const FractionNum& rhs) : _n(rhs._n), _d(rhs._d) {};    // copy constructor
	~FractionNum();
	int numerator() const { return _n; };
	int denominator() const { return _d; };
	FractionNum& operator = (const FractionNum&);
};

FractionNum& FractionNum::operator = (const FractionNum& rhs) {
	if (this != &rhs) {
		_n = rhs.numerator();
		_d = rhs.denominator();
	}
	return *this;
}

FractionNum operator + (const FractionNum& lhs, const FractionNum& rhs) {
	return FractionNum((lhs.numerator() * rhs.denominator()) + (lhs.denominator() * rhs.numerator()), lhs.denominator() * rhs.denominator());
}

FractionNum operator - (const FractionNum& lhs, const FractionNum& rhs) {
	return FractionNum((lhs.numerator() * rhs.denominator()) - (lhs.denominator() * rhs.numerator()), lhs.denominator() * rhs.denominator());
}

FractionNum operator * (const FractionNum& lhs, const FractionNum& rhs) {
	return FractionNum(lhs.numerator() * rhs.numerator(), lhs.denominator() * rhs.denominator());
}

FractionNum operator / (const FractionNum& lhs, const FractionNum& rhs) {
	return FractionNum(lhs.numerator() * rhs.denominator(), lhs.denominator() * rhs.numerator());
}

FractionNum::~FractionNum() {
	_n = 0; _d = 1;
}

// std::cout
std::ostream& operator << (std::ostream& o, const FractionNum& r) {
	if (r.denominator() == 1) return o << r.numerator();
	else return o << r.numerator() << '/' << r.denominator();
}

int main() {

	FractionNum a = 7;        // 7/1
	cout << "a is: " << a << endl;
	FractionNum b(5, 3);    // 5/3
	cout << "b is: " << b << endl;
	FractionNum c = b;        // copy constructor
	cout << "c is: " << c << endl;
	FractionNum d;            // default constructor
	cout << "d is: " << d << endl;
	d = c;                // assignment operator
	cout << "d is: " << d << endl;
	FractionNum& e = d;    // reference
	d = e;                // assignment to self!
	cout << "e is: " << e << endl;

	cout << a << " + " << b << " = " << a + b << endl;
	cout << a << " - " << b << " = " << a - b << endl;
	cout << a << " * " << b << " = " << a * b << endl;
	cout << a << " / " << b << " = " << a / b << endl;

	// converting by implicit constructor:
	cout << a << " + " << 12 << " = " << a + 12 << endl;	
	cout << 12 << " + " << b << " = " << 12 + b << endl;	
	return 0;
}
