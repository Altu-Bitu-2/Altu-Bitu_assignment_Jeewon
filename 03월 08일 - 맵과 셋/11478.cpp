#include <iostream>
#include <set>

using namespace std;

//string class의 substr()으로 부분 문자열 추출 가능하다.
void make_sub(int len, string str, int &ans) {
    string sub;
    set<string> s;
    for (int i = 0; i < str.length() - len + 1; i++) {
        sub = str.substr(i, len);
        if (s.count(sub)) {
            continue;
        }
        ans++;
        s.insert(sub);
    }
    return;
}

int main() {
    int ans = 0;
    string str;
    cin >> str;
    for (int i = 1; i <= str.length(); i++) {
        make_sub(i, str, ans);
    }
    cout << ans;
    return 0;
}

//main에 set을 만들었을 때는 시간초과 남.->따라서 부분 문자열 길이마다 set을 만듦.