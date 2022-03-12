#include <bits/stdc++.h>

using namespace std;
vector<int> a, b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, sum = 0;
    cin >> n;
    a.assign(n, 0);
    b.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    sort(a.begin(), a.end(), greater<int>());
    for (int i = 0; i < n; i++) {
        sum += a[i] * b[i];
    }
    cout << sum;
}
