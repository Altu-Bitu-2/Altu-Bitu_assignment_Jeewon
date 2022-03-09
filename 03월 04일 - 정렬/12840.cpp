#include <bits/stdc++.h>

#define T first
#define c second
using namespace std;
pair<int, int> query;
int h, m, s, q;
const int DAY = 86400;

void calculate(int T, int c) {
    int cur = h * 3600 + m * 60 + s;
    if (c >= DAY) c = c % DAY;
    if (T == 1) {
        cur += c;
        if (cur >= DAY) cur = cur % DAY;

    } else {
        cur -= c;
        if (cur < 0) cur += DAY;
    }
    h = cur / 3600;
    m = (cur % 3600) / 60;
    s = (cur % 3600) % 60;
    return;

}

void timeFunc() {
    int t;
    for (int i = 0; i < q; i++) {
        cin >> query.T;
        if (query.T == 3) {
            cout << h << ' ' << m << ' ' << s << '\n';
            continue;
        }
        cin >> query.c;
        calculate(query.T, query.c);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> h >> m >> s;
    cin >> q;

    timeFunc();
}
