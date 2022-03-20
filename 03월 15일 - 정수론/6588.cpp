#include <iostream>
#include <vector>

using namespace std;

const int MAX_SIZE = 1e7 + 1;

vector<bool> findPrime() {
    vector<bool> v(MAX_SIZE, true);
    for (int i = 2; i * i < MAX_SIZE; i++) {
        if (!v[i]) continue;
        for (int j = i * i; j < MAX_SIZE; j += i) {
            v[j] = false;
        }
    }
    return v;
}

void solution(int n, vector<bool> &prime) {
    for (int i = 2; i < MAX_SIZE / 2; i++) {
        if (!prime[i]) continue;
        if (prime[n - i]) {
            cout << n << " = " << i << " + " << n - i << '\n';
            return;
        }
    }
    cout << "Goldbach's conjecture is wrong.\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<bool> prime = findPrime();
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        solution(n, prime);
    }
}

