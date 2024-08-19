#include<bits/stdc++.h>
using namespace std;
const int maxn=3e4+10;
int n,m;
int c1[maxn],c2[maxn];//double_tree_arr
int A[maxn],_A[maxn];//discrete_arr
int Lef[maxn],Rit[maxn];//Counter

inline int _Q(int val){//��ѯA[i]��Ӧ��ӳ��ֵ 
	return lower_bound(_A+1,_A+m+1,val)-_A;
}

inline int lowbit(int i){
	return i&(-i);
}

void add(int *C,int pos,int val){
	while(pos<=n){
		C[pos]+=val;
		pos+=lowbit(pos);
	}
}

int sum(int *C,int pos){
	int res=0;
	while(pos){
		res+=C[pos];
		pos-=lowbit(pos);
	}
	return res;
}

//��������״����ģ�壬�ں�����������ָ�������� 
int main(){
    ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		scanf("%d",&A[i]);
		_A[i]=A[i];
	}
	sort(_A+1,_A+n+1);
	m=unique(_A+1,_A+n+1)-(_A+1);
	//Сϸ�ڣ�����ϣ��ӳ��ֵ��i...3e4֮�䣬������Ҫ��ȥ_A+1 
	//discrete
	for(int i=1;i<=n;++i){
        add(c1,_Q(A[i]),1);
		Lef[i]=sum(c1,_Q(A[i])-1);
        //����ȥA[i]���ָ���������ʽ���֣���������ֻ���㡰A[i]-1��ӳ�������ϣ����ĳ��ָ��� 
	}
	for(int i=n;i>=1;--i){
        add(c2,_Q(A[i]),1);
		Rit[i]=n-i-(sum(c2,_Q(A[i]))-1); 
		//����ʱ,sum(i)�������i+1��n֮��С�ڵ���a[i].val�ĸ���;
		//����ʱ,sum(i)�������1��i֮����ڵ���a[i].val�ĸ���;
	}
	long long ans=0;
	for(int i=2;i<n;++i) ans+=Lef[i]*Rit[i];
	//���˷�ԭ������ʽ���� 
	cout<<ans;
	return 0;
}