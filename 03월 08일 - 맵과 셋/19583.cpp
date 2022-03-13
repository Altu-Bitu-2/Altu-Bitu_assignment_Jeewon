#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <set>

using namespace std;

int compare(set<string> &s1, set<string> &s2) {
    int ans = 0;
    for (auto iter = s1.begin(); iter != s1.end(); iter++) {
        if (s2.count(*iter)) ans++;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s, e, q;
    string time, ppl;
    set<string> s1, s2;
    //freopen("input.txt", "r", stdin);
    cin >> s >> e >> q;
    while (cin >> time) {
        cin >> ppl;
        if ((time > s && time < e) || (time > q)) continue;
        if (time <= s) s1.insert(ppl);
        if (time >= e && time <= q) s2.insert(ppl);
    }
    cout << compare(s1, s2);
    //fclose(stdin);
}

