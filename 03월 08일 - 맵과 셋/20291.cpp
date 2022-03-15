#include <iostream>
#include <map>

#define name first
#define num second
using namespace std;

string split(string str, char delimiter) {
    //string�� �����Լ��� find�� substr�̿�.
    //find�� �ش� ����(��)�� ��ġ�� �ּڰ� ��ȯ./substr(pos, len)
    string ext;
    ext = str.substr(str.find(delimiter)+1);
    return ext;
}

void find_ext(string ext, map<string, int> &m) {
    m[ext]++;
    return;
}

int main() {
    int n;
    string str, str1, str2;
    map<string, int> m;
    cin >> n;
    while (n--) {
        cin >> str;
        string ext = split(str, '.');
        find_ext(ext, m);
    }
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        cout << iter->name << ' ' << iter->num << '\n';
    }
}

