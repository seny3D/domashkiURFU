#include <iostream>
#include <numeric>
using namespace std;


int main() {

    int a,b;
    std::cin >> a >> b;
    int olda = a;
    int oldb = b;
    int nod = std::gcd(a,b);
    // out << nod;
    b /= nod;
    while (b % 2 == 0) {
        b /= 2;
    }
    while (b % 5 == 0) {
        b /= 5;
    }
    // cout << b;

    bool flag = (b!=1); // не - конечная дробь, иначе периодичная

    if (!flag) {
        cout << (double)olda / oldb;
    }
    else {
        std::string res = "";
        int cel = olda / oldb;
        int ost = olda % oldb;
        int osts[2000];
        cout << cel << ".";
        int count = 0;
        int indx = -1; //  ищем период

        while (true) {
            indx = -1;
            for (int j = 0; j < count; j++) {
                if (osts[j] == ost) { // повторения типа короче в 1/3 это 0.33333 - 3
                     indx = j;
                    // cout << j << endl;
                    break;
                }
            }
            if (indx != -1) {
                break;
            }
            osts[count] = ost;
            res += (ost*10/oldb) + '0'; // добавляем следующю цифру в строку
            ost = (ost*10) % oldb;
            count += 1;
        }
        for (int i = 0; i < indx; i++) {
            cout << res[i];
        }
        cout << "(";
        for (int i = indx; i < count; i++) {
            cout << res[i];
        }
        cout << ")";
    }


}