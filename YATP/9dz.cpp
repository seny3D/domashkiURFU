#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int h;
    int m;
    std::cin >> h >> m;

    if (h > 12) {
        h %= 12;
    }   
    float hugol = h * 30;
    hugol += m*(0.5);
    float mugol = m * 6;

    float raznost = abs(hugol - mugol);

    if (raznost > 180 || raznost == 180) {
     cout << 360 - raznost << endl;
        return 0;
    }
    else {
       cout << raznost << endl;
       return 0;  
    }
}