#include <iostream>
#include <vector>

using namespace std;

bool isGroup(string s) {
    bool ans = true;
    int size = s.length();
    vector<bool> check(26, false);
    check[s[0] - 'a'] = true;
    for (int i = 1; i < size; i++) {
        if (s[i - 1] != s[i] && check[s[i] - 'a']) {
            ans = false;
            return ans;
        }
        check[s[i] - 'a'] = true;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, ans = 0;
    string s;
    cin >> n;
    while (n--) {
        cin >> s;
        if (isGroup(s)) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
