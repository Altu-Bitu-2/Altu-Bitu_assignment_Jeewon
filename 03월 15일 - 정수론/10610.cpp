#include <iostream>
#include <vector>

using namespace std;

string make_num(vector<int> &v) {
    string ans;
    if (v[0] == 0) {
        ans = "-1";
        return ans;
    }
    int sum = 0;
    for (int i = 1; i < 10; i++) {
        for (int j = 0; j < v[i]; j++) {
            sum += i;
        }
    }
    if (sum % 3 != 0) {
        ans = "-1";
        return ans;
    }
    for (int i = 9; i >= 0; i--) {
        for (int j = 0; j < v[i]; j++) {
            ans += (char)(i+'0');
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string num;
    cin >> num;
    int len = num.length();
    vector<int> v(10, 0);

    for (int i = 0; i < len; i++) {
        v[num[i] - '0']++;
    }
    cout << make_num(v);

    return 0;
}

