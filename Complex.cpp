#include "Complex.h"

Complex::Complex(double r, double im) :
        real(r),
        imaginary(im) {
}

bool Complex::operator<(const Complex &other) const {
    return real < other.real;
}

bool Complex::operator>(const Complex &other) const {
    return real > other.real;
}

Complex &Complex::operator+=(const Complex &other) {
    real += other.real;
    imaginary += other.imaginary;
    return *this;
}

Complex &Complex::operator*=(const Complex &other) {
    double newReal = real * other.real - imaginary * other.imaginary;
    double newImaginary = real * other.imaginary + imaginary * other.real;

    real = newReal;
    imaginary = newImaginary;

    return *this;
}

std::string Complex::toString() const {
    std::stringstream builder;
    builder << real << (imaginary >= 0 ? " + " : " - ")
            << abs(imaginary) << 'i';
    return builder.str();
}
