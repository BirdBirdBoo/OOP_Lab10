#ifndef ARRAY_H
#define ARRAY_H

#include <cstddef>
#include <iostream>
#include <stdexcept>

#include <string>
#include <sstream>

using std::size_t;
using std::cout;
using std::endl;

template<class T>
class Array {
public:
    Array();

    explicit Array(size_t initialSize);

    ~Array();

    Array &operator=(const Array &other) = delete;

    T operator[](size_t index) const;

    T &operator[](size_t index);

    void add(T newElement);

    T min() const;

    T sum() const;

    T product() const;

    void clear() {
        length = 0;
    }

    size_t getLength() const {
        return length;
    }

    std::string toString() const;

    Array<T> &operator+=(T element);

private:
    const static size_t DEFAULT_INITIAL_SIZE = 4;

    size_t length = 0;
    size_t capacity = 0;

    T *data = nullptr;

    void alloc(size_t count);

    void ensureCapacity(size_t requestedCapacity);

    void checkBounds(size_t index) const;

    std::string dataString(char leftBracket = '[', char rightBracket = ']') const;
};

template<class T>
Array<T>::Array(): Array(DEFAULT_INITIAL_SIZE) {
}

template<class T>
Array<T>::Array(size_t initialSize) {
    if (initialSize == 0)
        return;

    alloc(initialSize);
}

template<class T>
Array<T>::~Array() {
    if (data != nullptr) {
        free(data);
    }
}

template<class T>
void Array<T>::alloc(size_t count) {
    if (data == nullptr) {
        data = (T *) calloc(count, sizeof(T));
    } else {
        data = (T *) realloc(data, count * sizeof(T));
    }
    capacity = count;
}

template<class T>
void Array<T>::ensureCapacity(size_t requestedCapacity) {
    if (this->capacity < requestedCapacity) {
        alloc(requestedCapacity);
    }
}

template<class T>
void Array<T>::checkBounds(size_t index) const {
    if (index >= length) {
        throw std::invalid_argument("Index is bigger than length!");
    }
}

template<class T>
T Array<T>::operator[](size_t index) const {
    checkBounds(index);
    return data[index];
}

template<class T>
T &Array<T>::operator[](size_t index) {
    checkBounds(index);
    return data[index];
}

template<class T>
void Array<T>::add(T newElement) {
    ensureCapacity(length + 1);
    data[length] = newElement;
    ++length;
}

template<>
std::string Array<int>::dataString(char leftBracket, char rightBracket) const {
    std::stringstream builder;
    builder << "Data: " << leftBracket;

    if (getLength() > 0) {
        for (size_t i = 0; i < getLength() - 1; ++i) {
            builder << (*this)[i] << ", ";
        }
        builder << (*this)[getLength() - 1];
    }
    builder << rightBracket;

    return builder.str();
}

template<class T>
std::string Array<T>::dataString(char leftBracket, char rightBracket) const {
    std::stringstream builder;
    builder << "Data: " << leftBracket;

    if (getLength() > 0) {
        for (size_t i = 0; i < getLength() - 1; ++i) {
            builder << (std::string) (*this)[i] << ", ";
        }
        builder << (std::string) (*this)[getLength() - 1];
    }
    builder << rightBracket;

    return builder.str();
}

template<class T>
std::string Array<T>::toString() const {
    std::stringstream builder;
    builder << "Array of size " << getLength() << ": " << dataString();
    return builder.str();
}

template<class T>
Array<T> &Array<T>::operator+=(T element) {
    this->add(element);
    return *this;
}

template<class T>
T Array<T>::min() const {
    if (length == 0) {
        throw std::logic_error("Array is empty");
    }

    T min = data[0];
    for (int i = 1; i < length; ++i) {
        if (data[i] < min) {
            min = data[i];
        }
    }

    return min;
}

template<class T>
T Array<T>::sum() const {
    if (length == 0) {
        throw std::logic_error("Array is empty");
    }

    T sum = data[0];
    for (int i = 1; i < length; ++i) {
        sum += data[i];
    }
    return sum;
}

template<class T>
T Array<T>::product() const {
    if (length == 0) {
        throw std::logic_error("Array is empty");
    }

    T sum = data[0];
    for (int i = 1; i < length; ++i) {
        sum *= data[i];
    }
    return sum;
}

template<class T>
std::ostream &operator<<(std::ostream &output, const Array<T> &toWrite);

template<class T>
std::istream &operator>>(std::istream &input, Array<T> &toRead);

#endif // ARRAY_H
