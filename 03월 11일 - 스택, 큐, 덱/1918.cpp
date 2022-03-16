#include <iostream>
#include <stack>

using namespace std;

int cmp(char op) {
    switch (op) {
        case '(':
        case ')':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
    }
}

void solution(string math, int len) {
    stack<char> s;
    for (int i = 0; i < len; i++) {
        switch (math[i]) {
            case '+':
            case '-':
            case '*':
            case '/':
                while (!s.empty() && cmp(math[i]) <= cmp(s.top())) {
                    cout << s.top();
                    s.pop();
                }
                s.push(math[i]);
                break;
            case '(':
                s.push(math[i]);
                break;
            case ')':
                while(s.top()!='('){
                    cout<<s.top();
                    s.pop();
                }
                s.pop();
                break;
            default:
                cout<<math[i];
                break;
        }

    }
    while(s.size()){
        cout<<s.top();
        s.pop();
    }
}

int main() {

    string math;
    cin >> math;
    int len = math.length();
    solution(math, len);
}

