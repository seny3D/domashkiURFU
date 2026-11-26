#include <iostream>

using namespace std;

int main() {

    int n;
    cin >> n;
    int a = (n-1);
    double* mt = new double[a * a];

    for (int i = 0; i < (n-1); i++) {
        for (int j = 0; j < (n-1); j++) {
            mt[i * a + j] = ((j - i + a) % a) + 1;
            cout << mt[i*a+j] << " ";
        }
        cout << '\n';
    }

    delete[] mt;
    return 0;
}