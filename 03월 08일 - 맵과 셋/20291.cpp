#include <iostream>
#include <sstream>
#include <vector>
#include <map>

#define name first
#define num second
using namespace std;

string split(string str, char delimiter) {
    istringstream ss(str);
    string buffer;
    vector<string> result;
    while (getline(ss, buffer, delimiter)) {
        result.push_back(buffer);
    }
    return result[1];
}

void find_ext(string ext, map<string, int> &m) {
    if(m.count(ext)){
        m[ext]++;
        return;
    }
    m[ext]=1;
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
