#include<bits/stdc++.h>
using namespace std;
//������ʵ��Լɪ������ ��ѭ������ 
 
typedef struct node  //typedef����������struct node�����������ͣ���������ΪNode 
{
	int data;
	struct node* next;
}Node;
 
void ysflb(int N,int M)  //�ܹ���N���ˣ���������ΪM���˳��� 
{
	//��ʼ��ѭ������
	Node *head = NULL,*p=NULL,*r=NULL;   //headΪͷָ�룬ָ������ĵ�һ����㣬һ��ʼ��ֵΪNULL,����ָ���κν�� 
	head = (Node*)malloc(sizeof(Node));  //��headָ��һ��ʵ�ʵĿռ�
	if(NULL==head)  //�ڴ�ռ���ܻ�����ʧ��,����������������ʧ�� 
	{
			cout<<"Memory Failed!";
			return;
	} 
	head->data=1;       //��1��ʼ��� 
	head->next=NULL;    //һ��ʼ��������ֻ��һ��Node(���)�����Node�������򣬷ֱ���data��next
	                    //data��1��ʼ��nextָ��NULL���ܹ���ҪN����㣬���ڴ�����һ��������ҪN-1�� 
    p=head;             //headҪ���ֲ��ܸı䣬���ܹ��ҵ��������ʼλ�ã�һ��ʼpҲָ���һ�����
	                    //p��һ�»ᱻʹ�ã��������Ա��ڴ���ʣ�µ�N-1����� 
						 
	//β�巨��������,�Ѿ���һ��1�Ž���ˣ�����Ҫ����ʣ�µ�n-1����� 
	for(int i=2;i<=N;i++)
	{
		r=(Node*)malloc(sizeof(Node)); 
		r->data=i;
		r->next=NULL;
		//������ 
		p->next=r;
		p=r;
		
	}
	//����ѭ������
	p->next=head;   //���һ������nextָ��ͷ���
	p=head;         //Ϊ�������㣬��pָ��ͷ���
	
	//Լɪ�򻷵�ģ��
	while(p->next!= p)  //���p��next=p��˵��Ŀǰֻ��һ��Ԫ�� 
	{
		for(int i=1;i<M;i++)  //��������ΪM��ʱ����� 
		{
			  r=p;   //�������ֵ�ǰһ����� 
			  p=p->next; //pָ�����Ҫ���ֵ������㣬��Ҫ����ǰһ�����
		}
		// ���
		cout<<p->data<<" ";
		r->next=p->next;    //ɾ��p��Ŀ�ģ���ʱpָ�����  ��  
		p=p->next;  //����p���½��б��� 
	} 
	cout<<p->data; 
}
 
int main()
{
	ysflb(10,3);
	return 0;
} 