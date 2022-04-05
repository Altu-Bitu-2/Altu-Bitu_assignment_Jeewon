#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> combination(int n, int m, vector<int> &v) {
    vector<bool> tmp(n, true);
    vector<int> sum;
    for (int i = 0; i < n - 3; i++) {
        tmp[i] = false;
    }
    //next_permutation은 반드시 오름차순 정렬을 먼저 수행해야 함!
    do {
        int add = 0;
        for (int i = 0; i < n; i++) {
            if (tmp[i]) {
                add += v[i];
            }
        }
        if (add <= m) {
            sum.push_back(add);
        }

    } while (next_permutation(tmp.begin(), tmp.end()));
    return sum;
}

int near_sum(int n, int m, vector<int> &v) {
    int ans = 0;
    vector<int> sum = combination(n, m, v);
    int min = 0;
    int sum_size = sum.size();
    for (int i = 1; i < sum_size; i++) {
        if (m - sum[min] > m - sum[i]) {
            min = i;
        }
    }
    ans = sum[min];
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << near_sum(n, m, v);
    return 0;
}

