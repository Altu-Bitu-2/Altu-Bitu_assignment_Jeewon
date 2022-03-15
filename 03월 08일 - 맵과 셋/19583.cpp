#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <set>

using namespace std;

/*int compare(set<string> &s1, set<string> &s2) {
    int ans = 0;
    for (auto iter = s1.begin(); iter != s1.end(); iter++) {
        if (s2.count(*iter)) ans++;
    }
    return ans;
}*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0;
    string s, e, q;
    string time, ppl;
    set<string> s1, s2;
    freopen("input.txt", "r", stdin);
    cin >> s >> e >> q;
    while (cin >> time) {
        cin >> ppl;
        if (time <= s) s1.insert(ppl);
        if (time >= e && time <= q) {
            if (s1.find(ppl) != s1.end()) {
                s2.insert(ppl); //처음에는 여기서 바로 ans++했으나 채팅을 여러번 칠 수 있는 경우의 수 때문에 set에 넣음
            }
        }
    }
    ans = s2.size();
    cout << ans;
    fclose(stdin);
}


