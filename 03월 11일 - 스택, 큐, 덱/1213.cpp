#include <iostream>
#include <vector>
using namespace std;
void print_new(vector<char> &v){
    for(int i=0;i<v.size();i++){
        cout<<v[i];
    }
    return;
}
void solution(string name){
    bool flag = false;
    int index=0, len = name.length();
    vector<char> new_str(len);
    vector<int> v(26,0);
    for(int i=0;i<len;i++){
        int alpha = name[i]-'A';
        v[alpha]++;
    }
    if(len%2==0){
        for(int i=0 ; i<26 ; i++){
            if(!v[i]) continue;
            if(v[i]%2){
                cout<<"I'm Sorry Hansoo";
                return;
            }
            while(v[i]){
                new_str[index]=(char)(i+'A');
                new_str[(len-1)-index]=(char)(i+'A');
                index++;
                v[i] -=2;
            }
        }
        print_new(new_str);
        return;
    }
    for(int i=0 ; i<26 ; i++){
        if(!v[i]) continue;
        if(!flag && v[i]%2){
            flag=true;
            new_str[len/2]=(char)(i+'A'); v[i]--;
            if(v[i]==0) continue;
            while(v[i]){
                new_str[index]=(char)(i+'A');
                new_str[(len-1)-index]=(char)(i+'A');
                index++;
                v[i] -=2;
            }
        }
        if(flag && v[i]%2){
            cout<<"I'm Sorry Hansoo";
            return;
        }
        while(v[i]){
            new_str[index]=(char)(i+'A');
            new_str[(len-1)-index]=(char)(i+'A');
            index++;
            v[i] -=2;
        }
    }
    print_new(new_str);
    return;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string name;
    cin >> name;
    solution(name);
    return 0;
}

