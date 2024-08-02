//贪心  由于当前值最小对数关系一直成立 由此一个的增大会影响另一个 进而影响防御性能d的增加
//d = log2^A  =log3^B 由此可以画出函数图看出在(1,+∞)A的变化对d影响大 于是牺牲B 使A升序 达到d最大
//只有当之前和尽可能小并且当前道具的防御值尽可能大时总防御性能达到最大 由此应A升序排列B降序排列
//1.分析得出A从小到大 B从大到小可以使得防御性能最大 
//2.通过手动模拟数据计算四种情况(A小到大 B小到大)(A小到大 B大到小)(A大到小 B小到大)(A大到小 B大到小)也易得出
//0表示使用A 1表示使用B  注意如果增加量相同按照字典序排序即id
#include <bits/stdc++.h>
using namespace std;
struct node{
  int id;//编号
  int w;//道具增加量
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
  sort(b.begin(),b.end(),cmp2);//降序
  
  int c1 = 0,c2 = 0;
  //vector数组下标从0开始
  for(int i = 0; i < s.size(); i ++){
    if(s[i] == '1'){//输出对应编号才能通过
      cout << 'B' << b[c1++].id << '\n';
    }else{
      cout << 'A' << a[c2++].id <<'\n';
    }
  }
  cout << 'E';
  return 0;
}