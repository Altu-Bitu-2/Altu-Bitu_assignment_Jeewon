#include <bits/stdc++.h>

#define X first
#define Y second
using namespace std;
vector<pair<int, int>> point;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.Y != b.Y) {
        return a.Y < b.Y;
    }
    return a.X < b.X;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    point.assign(n, {});
    for (int i = 0; i < n; i++) {
        cin >> point[i].X >> point[i].Y;
    }
    sort(point.begin(), point.end(), cmp);
    for (int i = 0; i < n; i++) {
        cout << point[i].X << ' ' << point[i].Y << '\n';
    }
}
