#include <iostream>
#include <Windows.h>
#include <string>


class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	std::string Print() {
		return "(" + std::to_string(numerator_) + "/" + std::to_string(denominator_) + ")";
	}

	bool operator==(Fraction other) {
		return (numerator_ * other.denominator_ == other.numerator_ * denominator_);
	}

	bool operator!=(Fraction other) {
		return !(*this == other);
	}

	bool operator>(Fraction other) {
		return ((numerator_ * other.denominator_ > other.numerator_ * denominator_)
			* (denominator_ > 0) * (other.denominator_ > 0));
	}

	bool operator<=(Fraction other) {
		return !(*this > other);
	}

	bool operator<(Fraction other) {
		return (other > *this);
	}


	bool operator>=(Fraction other) {
		return !(*this < other);
	}

	Fraction operator+(Fraction other) {
		return Fraction(numerator_ * other.denominator_ + other.numerator_ * denominator_,
			denominator_ * other.denominator_);
	}

	Fraction operator-(Fraction other) {
		return Fraction(numerator_ * other.denominator_ - other.numerator_ * denominator_,
			denominator_ * other.denominator_);
	}

	Fraction operator*(Fraction other) {
		return Fraction(numerator_ * other.numerator_, denominator_ * other.denominator_);
	}

	Fraction operator/(Fraction other) {
		return Fraction(numerator_ * other.denominator_, denominator_ * other.numerator_);
	}

	Fraction operator-() {
		return Fraction(-numerator_, denominator_);
	}

	Fraction& operator++() {
		numerator_ += denominator_;
		return *this;
	}

	Fraction operator++(int) {
		Fraction temp = *this;
		++(*this);
		return temp;
	}

	Fraction& operator--() {
		numerator_ -= denominator_;
		return *this;
	}

	Fraction operator--(int) {
		Fraction temp = *this;
		--(*this);
		return temp;
	}

	Fraction& operator=(const Fraction& other) {
		numerator_ = other.numerator_;
		denominator_ = other.denominator_;
		return *this;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n1 = 0;
	int n2 = 0;
	int d1 = 1;
	int d2 = 1;
	std::cout << "Введите числитель дроби 1: ";
	std::cin >> n1;
	std::cout << "Введите знаменатель дроби 1: ";
	std::cin >> d1;
	std::cout << "Введите числитель дроби 2: ";
	std::cin >> n2;
	std::cout << "Введите знаменатель дроби 2: ";
	std::cin >> d2;

	Fraction f1(n1, d1);
	Fraction f2(n2, d2);

	Fraction f3 = f1 + f2;
	std::cout << f1.Print() << " + " << f2.Print() << " = " << f3.Print() << "\n";
	f3 = f1 - f2;
	std::cout << f1.Print() << " - " << f2.Print() << " = " << f3.Print() << "\n";
	f3 = f1 * f2;
	std::cout << f1.Print() << " * " << f2.Print() << " = " << f3.Print() << "\n";
	f3 = f1 / f2;
	std::cout << f1.Print() << " / " << f2.Print() << " = " << f3.Print() << "\n";
		
	std::cout << "++" << f1.Print() << " * " << f2.Print() << " = ";
    f3 = ++f1 * f2;
	std::cout << f3.Print() << "\n";
	std::cout << "Значение дроби 1 = " << f1.Print() << "\n";

	std::cout << f1.Print() << "--" << " * " << f2.Print() << " = ";
	f3 = f1-- * f2;
	std::cout << f3.Print() << "\n";
	std::cout << "Значение дроби 1 = " << f1.Print() << "\n";
}