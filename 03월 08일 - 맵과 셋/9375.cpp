#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int combination(vector<pair<string,int>> &v) {
    int ans = 1;
    int len = v.size();
    /*
    for (int i = 1; i <= len; i++) {
        vector<bool> v2(len - i, false);
        v2.insert(v2.end(), i, true);
        do {
            int temp = 1;
            for (int k = 0; k < len; k++) {
                if (v2[k]) {
                    temp *= v[k].second;
                }
            }
            ans += temp;
        } while (next_permutation(v2.begin(), v2.end()));
    }
     */ //조합으로 너무 어렵게 접근함->시간초과
    for(int i=0;i<len;i++){
        ans*=v[i].second+1; //해당 옷종류 아예 안 입는 경우
    }
    return ans-1;   //다 벗은 경우 빼기
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n;


    string s, kind;
    cin >> t;
    while (t--) {
        map<string, int> m;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> s >> kind;
            if (m.count(kind)) {
                m[kind]++;
            } else {
                m[kind] = 1;
            }
        }
        vector<pair<string,int>> v(m.begin(), m.end());
        cout << combination(v) << '\n';
    }
    return 0;
}

