#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    if (a.second != b.second) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int average(int n, vector<int> &v) {
    double ans = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        sum += v[i];
    }

    ans = (double) sum / n;   //cmath 헤더의 반올림 함수
    return (int) round(ans);

}

int mid(int n, vector<int> &v) {
    return v[n / 2];
}

int mode(int n, vector<int> &v) {
    int ans = 0;
    map<int, int> m;
    vector<pair<int, int>> t, a;
    for (int i = 0; i < n; i++)
        m[v[i]]++;
    t.assign(m.begin(), m.end());
    sort(t.begin(), t.end(), cmp);
    int max_int = t[0].second;
    for (int i = 0; i < t.size(); i++) {
        if (t[i].second == max_int) {
            a.push_back(t[i]);
        }
    }
    if (a.size() != 1) {
        ans = a[1].first;
    } else {
        ans = a[0].first;
    }
    return ans;
}

int range(vector<int> &v) {
    return v[v.size() - 1] - v[0];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    cout << average(n, v) << '\n';
    cout << mid(n, v) << '\n';
    cout << mode(n, v) << '\n';
    cout << range(v);
    return 0;
}

