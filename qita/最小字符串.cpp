#include <bits/stdc++.h>
using namespace  std;
int N,M;
string S;
char ch;
map<char ,int> mp;

signed main(){
    cin>>N>>M>>S;
    getchar();
    for(int i=0;i<M;++i){
        cin>>ch;
        mp[ch]++;
    }
    auto it=mp.begin();
    for(char i : S){
        while(it != mp.end() && i > it->first){
            cout<<string(it->second,it->first);
            it++;
        }
        cout<<i;
    }
    while (it != mp.end()){
        cout<<string(it->second,it->first);
        it++;
    }
    return  0;
}
