#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX_SIZE = 1e4 + 1;

string sum(string n1, string n2) {
    int n1_size = n1.length();
    int n2_size = n2.length();
    int temp = 0;
    string ans = "";

    if (n1_size == n2_size) {   //두 스트링의 길이가 같을 때
        for (int i = n1_size - 1; i > 0; i--) {
            int n = (n1[i] - '0') + (n2[i] - '0') + temp;
            ans = to_string(n % 10) + ans;
            temp = n / 10;
        }
        ans = to_string((n1[0] - '0') + (n2[0] - '0') + temp) + ans;
        return ans;
    }
    string big, small;
    int big_size, small_size;
    //더 긴 스트링 찾기
    if (n1_size > n2_size) {
        big = n1, small = n2;
        big_size = n1_size, small_size = n2_size;
    } else {
        big = n2, small = n1;
        big_size = n2_size, small_size = n1_size;
    }
    int diff = big_size - small_size;   //자릿수 차이
    for (int i = small_size - 1; i >= 0; i--) {
        int n = (small[i] - '0') + (big[i + diff] - '0') + temp;
        ans = to_string(n % 10) + ans;
        temp = n / 10;
    }
    for (int i = diff - 1; i > 0; i--) {
        int n = (big[i] - '0') + temp;
        ans = to_string(n % 10) + ans;
        temp = n / 10;
    }
    ans = to_string((big[0] - '0') + temp) + ans;
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string n1, n2;
    cin >> n1 >> n2;
    cout << sum(n1, n2);
}

