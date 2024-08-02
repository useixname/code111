#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int ch[N][26],cnt[N],idx;

void insert(string s){
    int p=0;
    for(int i=0;i<s.length();i++){
        int x=s[i]-'a';
        if(!ch[p][x]) ch[p][x]=++idx;
        p=ch[p][x];
    }
    cnt[p]++;
}

int query(string s){
    int p=0;
    for(int i=0;i<s.length();i++){
        int x=s[i]-'a';
        if(!ch[p][x]) return 0;
        p=ch[p][x];
    }
    return cnt[p];
}