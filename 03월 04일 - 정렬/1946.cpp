#include <bits/stdc++.h>

using namespace std;

struct ppl {
    int paper, interview;
    bool pass = true;
};

bool cmp(const ppl &a, const ppl &b) {
    return a.paper < b.paper;
}

vector<ppl> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, N, passed = 0;
    cin >> T;
    while (T--) {
        passed=1;
        cin >> N;
        v.assign(N,{});
        for (int i = 0; i < N; i++) {
            cin >> v[i].paper >> v[i].interview;
        }
        sort(v.begin(), v.end(), cmp);
        int min_inter = v[0].interview;
        for (int i = 1; i < N; i++) {
            if (min_inter <= v[i].interview) {
                continue;
            }
            min_inter = v[i].interview;
            passed++;
        }
        cout << passed << '\n';
    }

}

