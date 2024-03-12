#include <iostream>

int main(){

    //prueba 1
    int x=9;
    int * px = &x;
    int y= *px;
    std::cout << y<< std::endl;

    //prueba 2
    int a=2;
    std::cout << a;
    int c= 0;
    int b=a=c;

    std::cout << a;

    
    return 0;
}