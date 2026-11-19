#include <iostream>

using namespace std;


int main() {

    int n,m;
    std::cin >> n >> m;

    int* A = new int[n+1]();
    int* B = new int[m+1]();

    for (int i = 0; i <= n; i++) {
        int k;
        std::cin >> k;
        A[i] = k;
    }

    for (int i = 0; i <= m; i++) {
        int k;
        std::cin >> k;
        B[i] = k;
    }

    int slen = std::max(n,m);

    int* sres = new int[slen + 1]();
    int* prres = new int[n+m+1]();

    for (int i = 0; i <= n; i++) {
        sres[i] = A[i];
    }
    for (int i = 0; i <= m; i++) {
        sres[i] += B[i];
    }


    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            prres[i + j] += A[i] * B[j];
        }
    }


    for (int i = 0; i <= slen; i++) {
        cout << sres[i] << " ";
    }
    cout << endl;
        for (int i = 0; i <= (m+n); i++) {
        cout << prres[i] << " ";
    }
    cout << endl;

    delete[] A;
    delete[] B;
    delete[] sres;
    delete[] prres;
    return 0;

}