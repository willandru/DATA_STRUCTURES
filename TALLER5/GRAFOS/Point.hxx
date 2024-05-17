#include "Point.h"
#include <iostream>

template<class T>
Point<T>::Point() {
    // Constructor: initialize coordinates to default values
    x = T();
    y = T();
    z = T();
}

template<class T>
Point<T>::~Point() {
    // Destructor: nothing to clean up
}

template<class T>
void Point<T>::setX(T x) {
    // Set the x-coordinate
    this->x = x;
}

template<class T>
void Point<T>::setY(T y) {
    // Set the y-coordinate
    this->y = y;
}

template<class T>
void Point<T>::setZ(T z) {
    // Set the z-coordinate
    this->z = z;
}

template<class T>
T Point<T>::getX() {
    // Get the x-coordinate
    return x;
}

template<class T>
T Point<T>::getY() {
    // Get the y-coordinate
    return y;
}

template<class T>
T Point<T>::getZ() {
    // Get the z-coordinate
    return z;
}


template<class T>
void Point<T>::imprimirPunto() {
    std::cout << "Point coordinates: (" << x << ", " << y << ", " << z << ")" << std::endl;
}