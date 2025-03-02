#include <iostream>

class Rational {
private:
    int num;    
    int den;   
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a < 0 ? -a : a; //НОЗ
    }

public:
    Rational(int n = 0, int d = 1) { //Конструктор
        if (d == 0) throw "Error. Знаменатель не может быть равен 0";
        if (d < 0) {
            n = -n;
            d = -d;
        } //Деление на -1, чтоб знаки Ч и З поменялись
        int gcd_value = gcd(n, d);
        num = n / gcd_value;
        den = d / gcd_value;
    }
    int getNum() const { return num; }
    int getDen() const { return den; }
};

Rational operator+(const Rational& a, const Rational& b) {
    int result_num = a.getNum() * b.getDen() + b.getNum() * a.getDen();
    int result_den = a.getDen() * b.getDen();
    return Rational(result_num, result_den); 
} //Сложение

Rational operator-(const Rational& a, const Rational& b) {
    int result_num = a.getNum() * b.getDen() - b.getNum() * a.getDen();
    int result_den = a.getDen() * b.getDen();
    return Rational(result_num, result_den);
} //Вычитание

bool operator==(const Rational& a, const Rational& b) {
    return a.getNum() == b.getNum() && a.getDen() == b.getDen();
} //Сравнение

bool operator!=(const Rational& a, const Rational& b) {
    return !(a == b);
}

std::ostream& operator<<(std::ostream& out, const Rational& r) {
    out << r.getNum() << "/" << r.getDen();
    return out;
} //Вывод
                                                                                                                //25.02
std::istream& operator>>(std::istream& in, Rational& r) {
    int n, d;
    char c;
    in >> n >> c >> d;
    if (c != '/' || d == 0) throw "Неверный ввод";
    r = Rational(n, d);
    return in;
} //Ввод
//02.03
Rational operator-(const Rational& r) {
    return Rational(-r.getNum(), r.getDen());
} //Унарный минус

Rational& operator+=(Rational& a, const Rational& b) {
    a = a + b;
    return a;
}

Rational& operator-=(Rational& a, const Rational& b) {
    a = a - b;
    return a;
} //Составные операторы
