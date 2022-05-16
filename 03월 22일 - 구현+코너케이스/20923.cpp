#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;
deque<int> dodo, su, dodo_ground, su_ground;

void check(int &m) {
    if ((!dodo_ground.empty() && !su_ground.empty()) && dodo_ground.front() + su_ground.front() == 5) {
        //수연 승
        reverse(dodo_ground.begin(), dodo_ground.end());
        reverse(su_ground.begin(), su_ground.end());
        su.insert(su.end(), dodo_ground.begin(), dodo_ground.end());
        dodo_ground.clear();
        su.insert(su.end(), su_ground.begin(), su_ground.end());
        su_ground.clear();

        return;
    }
    if ((!dodo_ground.empty() && !su_ground.empty()) && dodo_ground.front() == 5 || su_ground.front() == 5) {
        //도도 승
        reverse(su_ground.begin(), su_ground.end());
        reverse(dodo_ground.begin(), dodo_ground.end());
        dodo.insert(dodo.end(), su_ground.begin(), su_ground.end());
        su_ground.clear();
        dodo.insert(dodo.end(), dodo_ground.begin(), dodo_ground.end());
        dodo_ground.clear();

        return;
    }
    m--;
    return;
}

void game(int &m) {
    while (true) {
        dodo_ground.push_front(dodo.front());
        dodo.pop_front();
        check(m);
        if (dodo.empty() || m == 0) break;
        su_ground.push_front(su.front());
        su.pop_front();
        if (su.empty() || m==0) break;
        check(m);
        if (m == 0) break;
    }
    if (dodo.size() > su.size()) {
        cout << "do";
    } else if (su.size() > dodo.size()) {
        cout << "su";
    } else {
        cout << "dosu";
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    while (n--) {
        int do_card, su_card;
        cin >> do_card >> su_card;
        dodo.push_front(do_card);
        su.push_front(su_card);
    }
    game(m);
    return 0;
}