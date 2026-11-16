#include <iostream>
#include <algorithm>


using namespace std;

int main() {
    
    int a[9] = {1,2,3,4,5,5,5,5,5}; 

    int c = 2;
    int mc = 2;

    // int mxl = 0;
    int lena = sizeof(a) / sizeof(a[0]);
    if (lena <= 2) {
        cout << lena;
        return 0;
    }
    // int mxr = lena;
    // cout << mxr;

    int flag = 0; // кароче 0 ищем, 1 нашли

    for (int i = 2; i < lena; i++) {
        if (a[i-2] - a[i-1] == a[i-1] - a[i]) {
            if (flag == 0) {
                c = 3;
                flag = 1;
            }
            else {
                c += 1;
            }
            // cout << a[i-2] << " " << a[i-1] << " " << a[i] << endl;
        }
        else {
            mc = max(c,mc);
            c = 0;
            flag = 0;
        }
    }
    mc = max(c,mc);
    cout << mc;


}