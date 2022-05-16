#include <iostream>

using namespace std;

const int COM = 10;

int lastCom(int a, int b) {
    int ans = 1;
    while (b--) {
        ans *= a;
        ans %= COM;
    }
    if (ans == 0) {
        ans = COM;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, a, b;
    cin >> T;
    while (T--) {
        cin >> a >> b;
        cout << lastCom(a, b) << '\n';
    }

    return 0;
}