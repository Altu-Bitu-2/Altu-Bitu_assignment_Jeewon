#include <iostream>
#include <vector>

using namespace std;
const int MAX = 11 + 1;

void init(vector<int> &dp) {
    dp[1] = 1, dp[2] = 2, dp[3] = 4;
    for (int i = 4; i < MAX; i++) {
        dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> dp(MAX, 0);
    init(dp);
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        cout << dp[n] << '\n';
    }
}



