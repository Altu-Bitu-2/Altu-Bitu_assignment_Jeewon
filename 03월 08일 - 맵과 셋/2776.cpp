#include <iostream>
#include <set>

using namespace std;

void is_here(int input2, int m, set<int> &s) {
    if (s.find(input2) != s.end()) {
        cout << 1 << '\n';
        return;
    }
    cout << 0 << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n, m, input1, input2;

    cin >> t;
    while (t--) {
        cin >> n;
        set<int> s;
        for (int i = 0; i < n; i++) {
            cin >> input1;
            s.insert(input1);
        }
        cin >> m;
        for(int i=0 ; i<m ; i++){
            cin >> input2;
            is_here(input2, m, s);
        }

    }
}


