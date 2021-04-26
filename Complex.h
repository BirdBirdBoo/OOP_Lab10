//
// Created by rudko on 26.04.2021.
//

#ifndef LAB10_COMPLEX_H
#define LAB10_COMPLEX_H

#include <string>
#include <sstream>

class Complex {

public:
    Complex() = default;

    Complex(double, double);

    bool operator<(const Complex &other) const;

    bool operator>(const Complex &other) const;

    Complex &operator+=(const Complex &other);

    Complex &operator*=(const Complex &other);

    explicit operator std::string() const { return toString(); }

    std::string toString() const;

private:
    double real = 0;
    double imaginary = 0;


};


#endif //LAB10_COMPLEX_H
