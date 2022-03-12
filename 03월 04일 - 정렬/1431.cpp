#include <bits/stdc++.h>

using namespace std;

int sum_num(const string &s) {
    int sum = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] < '0' || s[i] > '9') continue;
        sum += s[i] - '0';
    }
    return sum;
}

bool cmp(const string &a, const string &b) {
    if (a.length() != b.length()) {
        return a.length() < b.length();
    }

    int a_sum = sum_num(a);
    int b_sum = sum_num(b);
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


