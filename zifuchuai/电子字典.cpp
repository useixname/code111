#include<bits/stdc++.h>
using namespace std;
const int MAXN=10000+7;
int Trie[MAXN*20][26],visx[MAXN];//visx[i]�����޸�Ҫ�����ַ���ĩ�ڵ� 
char s[22];
bool p[MAXN*20],vis[MAXN*20],word;//p��ʾp[rt]�Ƿ��ǵ��ʽڵ㣬vis[rt]��ʾrt�Ƿ��Ѿ��������޸�Ҫ�����ַ��� 
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
	}//Trie�������ʹ��ڵ� 
	if(l==len&&p[rt]&&f){
		if(!vis[rt]) vis[visx[++vistot]=rt]=1;
		return;
	}//�����޸Ķ����ڵı���������Ǿ丳ֵû�����Ļ�����vis���һ�£�ͬʱ��visx��װ 
	int c=s[l]-'a';
	if(!f){
		if(l<len) DFS(rt,l+1,1);//l=len������ 
		for(register int i=0;i<26;++i)
			if(Trie[rt][i]){
				DFS(Trie[rt][i],l,1);
				if(i!=c) DFS(Trie[rt][i],l+1,1); 
			}//��Ӻ��滻���Ժ�����
	}
	if(l>=len) return;//���ȵ��˵�û���ʣ����ء�ע�⵽len������Ҳ�ǿ�����ӵġ� 
	if(Trie[rt][c]) DFS(Trie[rt][c],l+1,f);//ֱ�Ӳ� 
}

int main(){
	scanf("%d%d",&n,&m);
	for(register int i=1;i<=n;++i) scanf("%s",s),Insert();
	for(register int i=1;i<=m;++i){
		scanf("%s",s);len=strlen(s);
		DFS(0,0,0);
		if(word) printf("-1\n");
		else printf("%d\n",vistot);
		while(vistot) vis[visx[vistot--]]=0;//�Ѽ�¼������ 
		word=0;
	}
}