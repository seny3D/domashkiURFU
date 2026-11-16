#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main() {
    int d,m,y;
    int mnt[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int res = 0;
    char t1,t2;
    
    if (std::cin >> d >> t1 >> m >> t2 >> y) {}
    if (d <= 31 && d > 0 && m > 0 && m <= 12 && y > 0) {

    if ((y % 4 == 0) && (y % 100 != 0 || y % 400 == 0)) 
        {mnt[2] = 29;}

    for (int i = 1; i < m; i++) 
        {res += mnt[i];}

    res += (d-1);
    cout << res;
    }

    else {cout << "Некорректно";}
    return 0;
}