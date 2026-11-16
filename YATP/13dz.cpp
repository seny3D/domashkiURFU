#include <iostream>
// #include <vector>
using namespace std;


int main() {

    int a;
    std::cin >> a;
    int temp = a;
    // std::vector<int> arr;
    bool vip = false;



    while (temp > 0) {
        int b = temp % 10;

        if (b != 0 && a % b == 0) {
            cout << "+";
            vip = true;
            break;
        }
        temp = temp / 10;
    }
    // for (int i = 0; i < arr.size(); i++) {
    //     if (arr[i] == 0) {
    //         continue;
    //     }
    //     if (a % arr[i] == 0) {


    //     }
    // }
    if (vip == false) {
        cout << "-";
    }
    return 0;
    
}