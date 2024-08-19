#include<bits/stdc++.h>
using namespace std;
//用链表实现约瑟夫环问题 （循环链表） 
 
typedef struct node  //typedef用来重命名struct node这种数据类型，将其命名为Node 
{
	int data;
	struct node* next;
}Node;
 
void ysflb(int N,int M)  //总共有N个人，报到数字为M的人出局 
{
	//初始化循环链表
	Node *head = NULL,*p=NULL,*r=NULL;   //head为头指针，指向链表的第一个结点，一开始赋值为NULL,代表不指向任何结点 
	head = (Node*)malloc(sizeof(Node));  //让head指向一个实际的空间
	if(NULL==head)  //内存空间可能会申请失败,大多数情况不会申请失败 
	{
			cout<<"Memory Failed!";
			return;
	} 
	head->data=1;       //从1开始编号 
	head->next=NULL;    //一开始整个链表只有一个Node(结点)，这个Node有两个域，分别是data和next
	                    //data从1开始，next指向NULL，总共需要N个结点，现在创建了一个，还需要N-1个 
    p=head;             //head要保持不能改变，才能够找到链表的起始位置，一开始p也指向第一个结点
	                    //p等一下会被使用，用它可以便于创建剩下的N-1个结点 
						 
	//尾插法创建链表,已经有一个1号结点了，还需要创建剩下的n-1个结点 
	for(int i=2;i<=N;i++)
	{
		r=(Node*)malloc(sizeof(Node)); 
		r->data=i;
		r->next=NULL;
		//插入结点 
		p->next=r;
		p=r;
		
	}
	//创建循环链表
	p->next=head;   //最后一个结点的next指向头结点
	p=head;         //为后续方便，将p指向头结点
	
	//约瑟夫环的模拟
	while(p->next!= p)  //如果p的next=p，说明目前只有一个元素 
	{
		for(int i=1;i<M;i++)  //报到数字为M的时候出局 
		{
			  r=p;   //保留出局的前一个结点 
			  p=p->next; //p指向的是要出局的这个结点，需要保留前一个结点
		}
		// 输出
		cout<<p->data<<" ";
		r->next=p->next;    //删除p的目的，此时p指向哪里？  ：  
		p=p->next;  //更新p重新进行报数 
	} 
	cout<<p->data; 
}
 
int main()
{
	ysflb(10,3);
	return 0;
} 