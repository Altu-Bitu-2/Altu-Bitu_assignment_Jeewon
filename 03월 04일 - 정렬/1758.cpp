#include <bits/stdc++.h>

using namespace std;

long long add(vector<int> &v, int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] - i < 0) continue;
        sum += v[i] - i;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<int>());
    cout << add(v, n);
}
