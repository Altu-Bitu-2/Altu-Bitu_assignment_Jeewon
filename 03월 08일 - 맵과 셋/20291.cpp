#include <iostream>
#include <map>

#define name first
#define num second
using namespace std;

string split(string str, char delimiter) {
    //string의 내장함수인 find와 substr이용.
    //find는 해당 문자(열)이 위치한 주솟값 반환./substr(pos, len)
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

