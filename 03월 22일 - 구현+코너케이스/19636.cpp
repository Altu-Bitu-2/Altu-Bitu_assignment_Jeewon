#include <iostream>
#include <cmath>

using namespace std;

void noT(int w, int l0, int D, int l, int A) { //기초 대사량 변화 고려 x
    int sum_energy = l0 + A;
    int change_w = l - sum_energy;
    while (D--) {
        w += change_w;
        if (w <= 0) {
            cout << "Danger Diet\n";
            return;
        }
    }
    cout << w << " " << l0 << "\n";
}

void yesT(int w, int l0, int T, int D, int l, int A) {    //기초 대사량 변화 고려
    int tmp = l0;   //일일 기초 대사량 변수
    while (D--) {
        int sum_energy = tmp + A;
        int change_w = l - sum_energy;
        w += change_w;
        if (abs(change_w) > T) {    //체중 변화가 T 초과라면 일일 기초대사량 변화
            tmp += floor((double) change_w / (double) 2);
        }
        if (w <= 0 || tmp <= 0) {
            cout << "Danger Diet\n";
            return;
        }
    }
    cout << w << ' ' << tmp << ' ';
    if (l0 - tmp > 0) {
        cout << "YOYO";
    } else {
        cout << "NO";
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int w, l0, T, D, l, A;
    cin >> w >> l0 >> T >> D >> l >> A;
    noT(w, l0, D, l, A);
    yesT(w, l0, T, D, l, A);

    return 0;
}

