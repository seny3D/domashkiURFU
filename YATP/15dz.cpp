#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// 0 1 1 2 3 5 8 13 
int main() {
    long long a;
    std::cin >> a;
    if (a == 1) { std::cout << '0'; return 0;}
    if (a == 2) { std::cout << '1'; return 0;}
    if (a == 3) { std::cout << '1'; return 0;}

    long long cl = 3;

    long long pr2 = 1;
    long long pr = 1;

    while (true) {
        long long nw = pr + pr2;
        std::string nws = std::to_string(nw);
        long long len = nws.length();

        if (cl + len >= a) {
            long long indx = a - cl - 1;
            std::cout << nws[indx];
            return 0;
        } 
        cl += len;
        pr2 = pr;
        pr = nw;
    }
    return 0;
}