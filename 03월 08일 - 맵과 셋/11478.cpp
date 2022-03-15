#include <iostream>
#include <set>

using namespace std;

//string class�� substr()���� �κ� ���ڿ� ���� �����ϴ�.
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

//main�� set�� ������� ���� �ð��ʰ� ��.->���� �κ� ���ڿ� ���̸��� set�� ����.
