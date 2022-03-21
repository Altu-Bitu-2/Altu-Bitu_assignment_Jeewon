#include <iostream>
#include <vector>

using namespace std;

vector<int> split(string s) {
    vector<int> v(2, 0);
    int idx = s.find(':');
    v[0] = stoi(s.substr(0, idx));
    v[1] = stoi(s.substr(idx + 1));
    return v;
}

int gcdIter(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcdIter(b, a % b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    vector<int> num = split(s);
    int gcd = gcdIter(max(num[0], num[1]), min(num[0], num[1]));
    cout << num[0] / gcd << ':' << num[1] / gcd;
}

