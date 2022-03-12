#include <bits/stdc++.h>

#define paper first
#define interview second
using namespace std;
typedef pair<int, int> ppl;

vector<ppl> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, N, passed = 0;
    cin >> T;
    while (T--) {
        passed = 1;
        cin >> N;
        v.assign(N, {});
        for (int i = 0; i < N; i++) {
            cin >> v[i].paper >> v[i].interview;
        }
        sort(v.begin(), v.end());   //pair의 첫번째 원소 기준으로 오름차순 정렬됨
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


