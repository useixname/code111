#include<bits/stdc++.h>
using namespace std;
map<string,int>m;
int n;
int main()
{
	cout<<"请输入要添加的元素个数:";
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		int id;
		cout<<"键：";
		cin>>s;
		cout<<"值：";
		cin>>id;
	    m[s]=id;
	}
	//第一种遍历输出
	map<string,int>::iterator it;
	//查找uuu
	int ii=m.count("uuu"),tt=m.count("kkk");
	if(ii==1){
		cout<<"查找成功"<<endl;
	}
	else{
		cout<<"查找失败"<<endl;
	}
	if(tt==1){
		cout<<"查找成功"<<endl;
	}
	else{
		cout<<"查找失败"<<endl;
	}
	cout<<"map中的键值对如下 :"<<endl;
	for(it=m.begin();it!=m.end();it++){
		cout<<"键="<<it->first<<" 值="<<it->second<<endl;
	}
	return 0;
}