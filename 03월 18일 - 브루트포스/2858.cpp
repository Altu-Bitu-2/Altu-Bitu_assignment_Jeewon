#include <iostream>

using namespace std;

int findB(int L, int W) {
    return (L-2)*(W-2);
}

void findArea(int r, int b, int &l, int &w) {
    int sum = r + b;
    for(int L=3;L<3e4;L++){
        for(int W=3;W<=L;W++){
            if(L*W!=sum) continue;
            if(findB(L, W)==b){
                l=L, w=W;
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int r, b, l = 0, w = 0;
    cin >> r >> b;
    findArea(r, b, l, w);
    cout << l << ' ' << w;
    return 0;
}
