#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<string, int> &a, const pair<string, int> &b) {
    if (a.second != b.second) {
        return a.second > b.second;
    }
    if (a.first.length() != b.first.length()) {
        return a.first.length() > b.first.length();
    }
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    string s;
    map<string, int> map;
    cin >> n >> m;

    while (n--) {
        cin >> s;
        if (s.length() < m) continue;
        if (map.count(s)) {
            map[s]++;
        } else {
            map[s] = 1;
        }
    }
    vector<pair<string, int>> v(map.begin(), map.end());
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].first << '\n';
    }

}

