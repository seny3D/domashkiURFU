#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int k;
    std::cin >> k;
    if (k > 4) {
        cout << "максимальное римское число 3999 так то";
        return 0;
    }

    int* a = new int[k+1]();
    int num = 0;
    int temp = k-1;

    for (int i = 0; i < k; i++) {
        int b;
        std::cin >> b;
        a[i] = b;
        num += b*pow(10,temp);
        temp--;
    }

    if (num > 3999 || num <= 0) {
        return 0;
    }

    string tus[] = {"", "M", "MM", "MMM"};
    string sot[]  = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string des[]  = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string ed[]  = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};


    cout << tus[num / 1000] + sot[(num % 1000)/100] + des[(num%100)/10] + ed[num%10] << endl;

    delete a;

    







}