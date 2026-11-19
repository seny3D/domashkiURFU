#include <iostream>

using namespace std;

int main() {

    std::string a = "privet kak  dela  ya ne   znau";

    // string res = "";

    int j = 0;
    int flag = 0;

    for (int i = 0; i < a.length(); i++) {
        if (a[i] == ' ') {
            if (!flag) {
                a[j++] = a[i];
                flag = 1;
            }
        }
        else {
            a[j++] = a[i];
            flag = 0;
        }
    }
    a.resize(j);
    cout << a << endl;
}