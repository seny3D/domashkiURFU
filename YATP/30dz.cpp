#include <iostream>

using namespace std;

int main() {
    int c, st;

    cin >> c >> st;

    // int cntz = 0;
    int vsego = 0;
    double* mt = new double[c*st];

    for (int i = 0; i < c; i++) {
        int cntz = 0;
        for (int j = 0; j < st; j++) {
            // cntz =0;
            cin >> mt[i* st + j];
            if (mt[i*st + j] == 0) {
                cntz++;
            }
        }
        // cout << cntz << " " << st << endl; 
        if (cntz == st) {
            vsego++;
            // cout << "vsego +1" << endl;
        }
    }

    cout << "otvet " << vsego << endl;
    delete[] mt;
    return 0;

}