#include <iostream>
#include <set>

using namespace std;

//string class의 substr()으로 부분 문자열 추출 가능하다.
int make_sub(string str, set<string> &s) {
    int len = str.length();
    for (int k = 1; k <= len; k++) {
        string sub;
        for (int i = 0; i < len - k + 1; i++) {
            sub = str.substr(i, k);
            s.insert(sub);
        }
    }

    return s.size();
}

int main() {
    string str;
    set<string> s;
    cin >> str;
    cout << make_sub(str, s);

    return 0;
}

//main에 set을 만들었을 때는 시간초과 남.->따라서 부분 문자열 길이마다 set을 만듦.
