#include <bits/stdc++.h>

#define a first
#define b second
using namespace std;
int card[20];
pair<int, int> section[10];

void reverseCard() {
    for (int i = 0; i < 10; i++) {
        int a = section[i].a - 1;
        int b = section[i].b;
        reverse(card + a, card + b);    //algorithm 헤더의 reverse 함수, [)
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 20; i++) {
        card[i] = i + 1;
    }

    for (int i = 0; i < 10; i++) {
        cin >> section[i].a >> section[i].b;
    }
    reverseCard();

    for (int i = 0; i < 20; i++)
        cout << card[i] << ' ';

}

