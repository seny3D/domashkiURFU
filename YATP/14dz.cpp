#include <iostream>
#include <array>
#include <algorithm>
// #include <vector>


int main() {
    long long a;
    std::cin >> a;
    
    int dgs[10] = {0,0,0,0,0,0,0,0,0,0};
    long long count = 0;
    long long temp = a;

    while (temp > 0) {
        int lst = temp % 10;
        // 9 -> dgs[0] += 1
        // 8 -> dgs[1] += 1
        dgs[abs(lst-9)] += 1;
        temp /= 10;
    }
    long long res = 0;
    for (int i = 0; i < 10; i++) {
        while (dgs[i] > 0) {
            int dig = 9 - i;
            res = res * 10 + dig;
            dgs[i]--;
        }
    }
    std::cout << res;
    return 0;
}


// [0,0,0,0,0,0,0,0] - массив в котором каждый индекс - КОЛИЧЕСТВО цифр в исходном числе (т.е колво 9, колво 8, ....), а после просто собираем число
