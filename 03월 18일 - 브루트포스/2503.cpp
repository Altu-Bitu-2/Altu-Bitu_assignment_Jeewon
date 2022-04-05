#include <iostream>
#include <vector>
#include <map>

using namespace std;
const int MAX_NUM = 999 + 1;

int countNum(vector<bool> &table) {
    int ans = 0;
    for (int i = 111; i < MAX_NUM; i++) {
        if (table[i]) ans++;
    }
    return ans;
}

bool isStrike(int i, int num, int strike, vector<int> &str_idx) {
    int cnt = 0;
    string i_str = to_string(i), num_str = to_string(num);
    for (int i = 0; i < 3; i++) {
        if (i_str[i] == num_str[i]) {
            cnt++;
            str_idx.push_back(i);
        }
    }
    return cnt == strike;
}

bool isBall(int i, int num, int ball, vector<int> &str_idx) {
    int cnt = 0;
    string i_str = to_string(i), num_str = to_string(num);
    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {
            if (i == j) continue;
            if (i_str[i] == num_str[j]) cnt++;
        }
    }
    return ball == cnt;
}

void numBaseball(int num, int strike, int ball, vector<bool> &table) {
    vector<int> str_idx(0);
    for (int i = 111; i < MAX_NUM; i++) {
        if (!table[i]) continue;
        if (!isStrike(i, num, strike, str_idx) || !isBall(i, num, ball, str_idx)) {  //스트라이크 개수가 같지 않음
            table[i] = false;
        }

    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, num, strike, ball;
    cin >> n;
    vector<bool> table(MAX_NUM, true);
    for (int i = 0; i < n; i++) {
        cin >> num >> strike >> ball;
        numBaseball(num, strike, ball, table);
    }
    cout << countNum(table);
    return 0;
}