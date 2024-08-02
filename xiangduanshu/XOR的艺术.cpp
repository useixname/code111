#include<bits/stdc++.h>
using namespace std;

#define lc p<<1
#define rc p<<1|1
const int N=1e5+10;
int a[N];

struct node
{
	int left;//区间左端点
	int right;//右端点
	int w;//初值
	int v;//标记
}tree[N*4];

void Build_Tree(int index,int l,int r)//神奇建树，连函数名都是那么的直接。。。
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
}//建树很简单，不说啦！！

void Spread(int index)//下传懒惰标记
{
	if(tree[index].v) {
		tree[index*2].w=tree[index*2].right-tree[index*2].left+1-tree[index*2].w;//如上所说修改
		tree[index*2+1].w=tree[index*2+1].right-tree[index*2+1].left+1-tree[index*2+1].w;
		tree[index*2].v^=1;//标记很简单，就直接取反好啦！！
		tree[index*2+1].v^=1;
		tree[index].v=0;//别忘记清空！！
	}
}

int Query(int index,int l,int r)//自认为好理解的查询。。。
{
	if(tree[index].left>=l&&tree[index].right<=r) return tree[index].w;//如果完全包含，返回区间
	int mid=(tree[index].left+tree[index].right)/2;
	int ans=0;
	Spread(index);//下传标记
	if(l<=mid) ans+=Query(index*2,l,r);//继续向下
	if(r>mid) ans+=Query(index*2+1,l,r);
	return ans;
}

void Change(int index,int l,int r)//修改区间很简单，不说啦！！！
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