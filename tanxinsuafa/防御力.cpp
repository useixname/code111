//̰��  ���ڵ�ǰֵ��С������ϵһֱ���� �ɴ�һ���������Ӱ����һ�� ����Ӱ���������d������
//d = log2^A  =log3^B �ɴ˿��Ի�������ͼ������(1,+��)A�ı仯��dӰ��� ��������B ʹA���� �ﵽd���
//ֻ�е�֮ǰ�;�����С���ҵ�ǰ���ߵķ���ֵ�����ܴ�ʱ�ܷ������ܴﵽ��� �ɴ�ӦA��������B��������
//1.�����ó�A��С���� B�Ӵ�С����ʹ�÷���������� 
//2.ͨ���ֶ�ģ�����ݼ����������(AС���� BС����)(AС���� B��С)(A��С BС����)(A��С B��С)Ҳ�׵ó�
//0��ʾʹ��A 1��ʾʹ��B  ע�������������ͬ�����ֵ�������id
#include <bits/stdc++.h>
using namespace std;
struct node{
  int id;//���
  int w;//����������
};
vector<node> a;
vector<node> b;
string s;
int n1,n2;
bool cmp1(node q,node r){
  if(q.id != r.id) return q.w < r.w;
  else return q.id < r.id;
}
bool cmp2(node q,node r){
  if(q.id != r.id) return q.w > r.w;
  else return q.id < r.id;
}
int main()
{
  cin >> n1 >> n2;
  for(int i = 1; i <= n1; i++){
    node x;
    cin >> x.w;
    x.id = i;
    a.push_back(x);
  }
  for(int i = 1; i <= n2; i++){
    node x;
    cin >> x.w;
    x.id = i;
    b.push_back(x);
  }
  cin >> s;
  sort(a.begin(),a.end(),cmp1);
  sort(b.begin(),b.end(),cmp2);//����
  
  int c1 = 0,c2 = 0;
  //vector�����±��0��ʼ
  for(int i = 0; i < s.size(); i ++){
    if(s[i] == '1'){//�����Ӧ��Ų���ͨ��
      cout << 'B' << b[c1++].id << '\n';
    }else{
      cout << 'A' << a[c2++].id <<'\n';
    }
  }
  cout << 'E';
  return 0;
}