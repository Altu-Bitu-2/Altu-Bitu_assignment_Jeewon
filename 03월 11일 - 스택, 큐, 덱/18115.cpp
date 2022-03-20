#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void solution(int ins, int n, deque<int> &d) {
    int tmp;
    switch (ins) {
        case 1:
            d.push_front(n);
            break;
        case 2:
            tmp = d.front();
            d.pop_front();
            d.push_front(n);
            d.push_front(tmp);
            break;
        case 3:
            d.push_back(n);
            break;
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v1, t(n);
    deque<int> d;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    for (int i = n; i >= 1; i--) {
        v1.push_back(i);
    }

    for (int i = n - 1; i >= 0; i--) {
        solution(t[i], v1[i], d);
    }
    for (auto iter = d.begin(); iter != d.end(); iter++) {
        cout << *iter << ' ';
    }
    return 0;
}
