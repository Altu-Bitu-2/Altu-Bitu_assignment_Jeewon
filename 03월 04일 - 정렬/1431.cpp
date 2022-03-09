#include <bits/stdc++.h>

using namespace std;

bool cmp(const string &a, const string &b) {
    if (a.length() != b.length()) {
        return a.length() < b.length();
    }
    int a_sum = 0, b_sum = 0;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] < '0' || a[i] > '9') continue;
        a_sum += a[i] - '0';
    }
    for (int i = 0; i < b.length(); i++) {
        if (b[i] < '0' || b[i] > '9') continue;
        b_sum += b[i] - '0';
    }
    if (a_sum != b_sum) {
        return a_sum < b_sum;
    }
    return a < b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> v(n, "");
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < n; i++)
        cout << v[i] << '\n';
}

