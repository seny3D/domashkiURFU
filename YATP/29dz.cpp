#include <iostream>

using namespace std;

int main() {

    int c1, st1;
    std::cin >> c1 >> st1;

    int c2, st2;
    std::cin >> c2 >> st2;

    int* mt1 = new int[c1*st1]{};

    int* mt2 = new int[c2*st2]{};


    if (c1 == c2 && st1 == st2) {
        for (int i = 0; i < c1; i++) {
            for (int j = 0; j < st1; j++) {
                cin >> mt1[i*st1 + j];
            }
        }

        for (int i = 0; i < c2; i++) {
            for (int j = 0; j < st2; j++) {
                cin >> mt2[i*st2 + j];
            }
        }
        

        // for (int i = 0; i < c1; ++i) {
        //     for (int j = 0; j < st1; ++j) {
        //         cout << mt1[i * st1 + j] << ' ';  // 1 2 3
        //     }                                     // 4 5 6
        //     cout << '\n';                         // при 2 3
        // }

        for (int i = 0; i < c1; i++) {
            for (int j = 0; j < st1; j++) {
                cout << mt1[i * st1 + j] + mt2[i * st2 + j] << ' ';
            }
            cout << '\n';
        }

    }
    else {
        cout << "такие матрицы не суммируютсч" << endl;
        return 0;
    }

    delete[] mt1;
    delete[] mt2;

}