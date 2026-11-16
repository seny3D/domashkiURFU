// На вход вашей программы в стандартном потоке ввода подаются действительные коэффициенты A, B и C уравнения Ax² + Bx + C = 0. 
// Выведите все его различные действительные корни в поток вывода в любом порядке, при этом разделяя корни пробелами. 
// Гарантируется, что хотя бы один из коэффициентов уравнения не равен нулю.	


#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float a,b,c;
    std::cin >> a >> b >> c;
    float d;
    if (a == 0) {
        if (b == 0) {
            return 0;
        }
        else {
            cout << -c/b;
            return 0;
        }
    }
    else {
        d = b*b - 4*a*c;

    }
    

    if (d < 0) {
        return 0;
    }
    else if (d == 0) {
        cout << (-b / (2*a));
    }

    else if (d > 0) {
        cout << ((-b + sqrt(d)) / (2*a)) << ((-b - sqrt(d)) / (2*a));
    }



}