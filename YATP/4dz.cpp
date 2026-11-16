#include <iostream>

using namespace std;

int main() {

    float x1,y1,x2,y2,x3,y3,x4,y4;

    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    if ((max(x1,x3) <= min(x2,x4)) && (max(y1,y3) <= min(y2,y4))) {
        

        float xp1 = max(x1,x3);
        float xp2 = min(x2,x4);
        float yp1 = max(y1,y3);
        float yp2 = min(y2,y4);

        float s = abs(xp1-xp2) * abs(yp1-yp2);

        cout << "+" << " " << s;


    }
    else {
        cout << "-" << " " << 0;
    }


}


/*
0.0 0.0 3.0 4.0 3.0 1.0 6.0 3.0 / +, 0
0.5 0.5 2.5 2.5 2.0 2.0 4.0 4.0 / +, 0,25
1.0 3.0 9.0 5.0 4.0 1.0 6.0 7.0 / +, 4
-2.5 -2.5 2.5 2.5 -1.0 -1.0 4.0 4.0 / +, 12.25
-8.5 -8.5 -2.5 -2.5 -6.5 -6.5 -4.5 -4.5 / +, 4
0.0 0.0 1.0 1.0 1.0001 0.0 2.0 1.0 / -, 0




*/