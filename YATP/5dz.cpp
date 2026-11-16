#include <iostream>
#include <cmath>
using namespace std;


int main() {

    float x1,y1,x2,y2,x,y; // х,у точка, остальное отрезок

    std::cin >> x1 >> y1 >> x2 >> y2 >> x >> y;

    float sp1 = (x - x1) * (x2 - x1) + (y-y1)*(y2 - y1); // скалярное произведение
    float sp2 = (x - x2) * (x1 - x2) + (y - y2)*(y1 -y2);

    if (sp1 <= 0) {

        float res = sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1));

        cout << res;
    }
    else if (sp2 <= 0) {

        float res = sqrt((x-x2)*(x-x2) + (y-y2)*(y-y2));
        cout << res;

    }
    else {

        float res;
        float chislitel = abs((y2-y1)*x - (x2-x1)*y + x2*y1 - y2*x1);
        float znamen = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
        res = chislitel / znamen;

        cout << res;


    }






}