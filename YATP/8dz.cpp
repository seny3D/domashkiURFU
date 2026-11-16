#include <iostream>
#include <cmath>

using namespace std;

int main() {
    
    float x,y;
    std::cin >> x >> y;
    if (abs(sin(x)) < 1e-6) {
        cout << "некорректно";
        return 0;
    }
    if (abs(cos(x)) < 1e-6) {
        cout << "некорректно";
        return 0;
    }

    float ctg = cos(x) / sin(x);
    float rs1 = (1 - tan(x));

    if (abs(rs1) < 0 && ctg <= 0) {
        cout << "некорректно";
        return 0;
    }
    float res = std::pow(rs1,ctg) + cos(x-y);
    cout << res;


}