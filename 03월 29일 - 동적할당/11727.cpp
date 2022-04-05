#include <iostream>
#include <vector>

using namespace std;
const int D = 10007;

vector<int> d;

int fillRec(int n) {
    if(n==1){   //인덱스 에러x
        return 1;
    }

    d[1]=1;
    d[2]=3;
    for(int i=3;i<=n;i++){
        d[i]=d[i-1]+2*d[i-2];
        d[i]%=D;    //구하는 과정에서 int 범위를 초과할 수 있으므로 중간에 모듈러 연산
    }
    return d[n];
}
/*
 * 너비 1: 2x1 경우만 있음
 * 너비 2: 1x2 두개, 2x2 1개 총 2개의 경우 + 너비1에 2x1 더하기 ->3 경우
 *
 * 그래서 너비3부터 i-1과 i-2에서 너비가 1, 2인 타일을 더하는 경우
 * */
int main() {
    int n;
    cin >> n;
    d.assign(n+1, 0);
    cout << fillRec(n);
}
