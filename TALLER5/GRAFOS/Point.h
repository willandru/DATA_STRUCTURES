#ifndef __POINT__H__
#define __POINT__H__


template <class T>
class Point{

    protected:
        T x;
        T y;
        T z;
    public:
        Point();
        ~Point();
        void setX(T x);
        void setY(T y);
        void setZ(T z);
        T getX();
        T getY();
        T getZ();

        void imprimirPunto();

};

#endif