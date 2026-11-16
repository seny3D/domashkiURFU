#include <iostream>
using namespace std;


int main() {

    int a[10] = {3,1,3,2,3};


    
    int max1 = -2147483648;
    int max2 = max1;
    int max3 = max1;

    int lena = sizeof(a) / sizeof(a[0]);

    for (int i = 0; i < lena; i++){
        if (a[i] > max1) {
            max3 = max2;
            max2 = max1;
            max1 = a[i];
        }
        else if (a[i] > max2) {
            max3 = max2;
            max2 = a[i];
        }
        else if (a[i] > max3) {
            max3 = a[i];
        }
    }

    cout << max1 << " " << max2 << " " << max3 << endl;
}