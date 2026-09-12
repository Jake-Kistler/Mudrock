#include<iostream>
#include"physics.h"

int main(){
    double res = next_pressure(3000,9000,3000,0.1);
    std::cout << "Pressure =" << res << std::endl;
}