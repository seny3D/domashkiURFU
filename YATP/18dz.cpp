// sum.png, там короче первый член равен 1

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x, eps;
    std::cin >> x >> eps;

    double sum = 0.0;
    double perv = x;
    int n = 1;

    while (abs(perv) >= eps) {
        sum += perv;

        perv *= - (x*x) / (12*n*n + 6*n);
        n++;
    }

    cout << "sum " << sum << endl;
    cout << n -1 << endl;
}
/*
0.5, 1e-7 -> 0.493... 3
5.0, 1e-6 -> 0.451... 8
10.0 1e-6 -> -0.722.. 12
2.0 1e-12 -> 1.583... 9
*/