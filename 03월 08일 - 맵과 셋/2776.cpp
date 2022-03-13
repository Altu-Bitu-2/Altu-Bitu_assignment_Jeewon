#include <iostream>
#include <set>

using namespace std;

void is_here(int m, set<int> &s) {
    int input;
    for (int i = 0; i < m; i++) {
        cin >> input;
        if (s.find(input) != s.end()) {
            cout << 1 << '\n';
            continue;
        }
        cout << 0 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n, m, input;

    cin >> t;
    while (t--) {
        cin >> n;
        set<int> s;
        for (int i = 0; i < n; i++) {
            cin >> input;
            s.insert(input);
        }
        cin >> m;
        is_here(m, s);
    }
}

