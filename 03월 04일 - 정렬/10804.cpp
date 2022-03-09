#include <bits/stdc++.h>

#define a first
#define b second
using namespace std;
int card[20];
pair<int, int> section[10];

void reverseCard() {
    for (int i = 0; i < 10; i++) {
        int a = section[i].a-1;
        int b = section[i].b-1;
        vector<int> v(b - a + 1, 0);
        for (int j = 0; j <= b - a; j++)
            v[j] = card[a + j];
        for (int j = 0; j <= b - a; j++)
            card[a + j] = v[b - a - j];

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
