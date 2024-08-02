#include<bits/stdc++.h>
using namespace std;

#define lc p<<1
#define rc p<<1|1
const int N=1e5+10;
int a[N];

struct node
{
	int left;//������˵�
	int right;//�Ҷ˵�
	int w;//��ֵ
	int v;//���
}tree[N*4];

void Build_Tree(int index,int l,int r)//���潨������������������ô��ֱ�ӡ�����
{
	tree[index].left=l;
	tree[index].right=r;
	if(l==r) {
		tree[index].w=a[l];
		return;
	}
	int mid=(l+r)/2;
	Build_Tree(index*2,l,mid);
	Build_Tree(index*2+1,mid+1,r);
	tree[index].w=tree[index*2].w+tree[index*2+1].w;
}//�����ܼ򵥣���˵������

void Spread(int index)//�´�������
{
	if(tree[index].v) {
		tree[index*2].w=tree[index*2].right-tree[index*2].left+1-tree[index*2].w;//������˵�޸�
		tree[index*2+1].w=tree[index*2+1].right-tree[index*2+1].left+1-tree[index*2+1].w;
		tree[index*2].v^=1;//��Ǻܼ򵥣���ֱ��ȡ����������
		tree[index*2+1].v^=1;
		tree[index].v=0;//��������գ���
	}
}

int Query(int index,int l,int r)//����Ϊ�����Ĳ�ѯ������
{
	if(tree[index].left>=l&&tree[index].right<=r) return tree[index].w;//�����ȫ��������������
	int mid=(tree[index].left+tree[index].right)/2;
	int ans=0;
	Spread(index);//�´����
	if(l<=mid) ans+=Query(index*2,l,r);//��������
	if(r>mid) ans+=Query(index*2+1,l,r);
	return ans;
}

void Change(int index,int l,int r)//�޸�����ܼ򵥣���˵��������
{
	if(tree[index].left>=l&&tree[index].right<=r) {
		tree[index].w=tree[index].right-tree[index].left+1-tree[index].w;
		tree[index].v^=1;
		return;
	}
	int mid=(tree[index].left+tree[index].right)/2;
	Spread(index);
	if(l<=mid) Change(index*2,l,r);
	if(r>mid) Change(index*2+1,l,r);
	tree[index].w=tree[index*2].w+tree[index*2+1].w;
}

int main()
{
    int n,m,z,x,y;
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		scanf("%1d",&a[i]);
	Build_Tree(1,1,n);
	for(int i=1; i<=m; i++) {
		cin>>z;
		if(z==0) {
			cin>>x>>y;
			Change(1,x,y);	
		}
		else {
			cin>>x>>y;
			cout<<Query(1,x,y)<<endl;	
		}
	}
	return 0;
}