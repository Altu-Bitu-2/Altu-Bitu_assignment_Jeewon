#include <iostream>
#include <vector>

using namespace std;
vector<bool> v(21, false);

void all() {
    for (int i = 1; i <= 20; i++) {
        v[i] = true;
    }
    return;
}

void empty() {
    for (int i = 1; i <= 20; i++) {
        v[i] = false;
    }
    return;
}

void command(string cmd, int n) {
    if (cmd == "add") {
        v[n] = true;
        return;
    }
    if (cmd == "remove") {
        v[n] = false;
        return;
    }
    if (cmd == "check") {
        if (v[n]) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
        return;
    }
    if (cmd == "toggle") {
        v[n] = !v[n];
        return;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string cmd;
    cin >> n;
    while (n--) {
        cin >> cmd;
        if (cmd == "all") {
            all();
        } else if (cmd == "empty") {
            empty();
        } else {
            int num;
            cin >> num;
            command(cmd, num);
        }
    }
    return 0;
}
/*
 * set과 map으로 구현했을 때, 시간초과 남.
 * */