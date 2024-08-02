#include<bits/stdc++.h>
using namespace std;
const int MAXN=10000+7;
int Trie[MAXN*20][26],visx[MAXN];//visx[i]存足修改要求后的字符串末节点 
char s[22];
bool p[MAXN*20],vis[MAXN*20],word;//p表示p[rt]是否是单词节点，vis[rt]表示rt是否已经是满足修改要求后的字符串 
int n,m,u,len,tot,vistot;

void Insert(){
	u=0,len=strlen(s);
	for(register int i=0;i<len;++i){
		int c=s[i]-'a';
		if(!Trie[u][c]) Trie[u][c]=++tot;
		u=Trie[u][c];
	}
	p[u]=1;
}

void DFS(int rt,int l,bool f){
	if(l==len&&p[rt]&&!f){
		word=1;return;
	}//Trie树本来就存在的 
	if(l==len&&p[rt]&&f){
		if(!vis[rt]) vis[visx[++vistot]=rt]=1;
		return;
	}//经过修改而存在的标记下来，那句赋值没看懂的话就是vis标记一下，同时往visx里装 
	int c=s[l]-'a';
	if(!f){
		if(l<len) DFS(rt,l+1,1);//l=len无意义 
		for(register int i=0;i<26;++i)
			if(Trie[rt][i]){
				DFS(Trie[rt][i],l,1);
				if(i!=c) DFS(Trie[rt][i],l+1,1); 
			}//添加和替换可以合起来
	}
	if(l>=len) return;//长度到了但没单词，返回。注意到len长度是也是可以添加的。 
	if(Trie[rt][c]) DFS(Trie[rt][c],l+1,f);//直接查 
}

int main(){
	scanf("%d%d",&n,&m);
	for(register int i=1;i<=n;++i) scanf("%s",s),Insert();
	for(register int i=1;i<=m;++i){
		scanf("%s",s);len=strlen(s);
		DFS(0,0,0);
		if(word) printf("-1\n");
		else printf("%d\n",vistot);
		while(vistot) vis[visx[vistot--]]=0;//把记录都倒掉 
		word=0;
	}
}