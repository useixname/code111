#include<bits/stdc++.h>
using namespace std;
map<string,int>m;
int n;
int main()
{
	cout<<"������Ҫ��ӵ�Ԫ�ظ���:";
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		int id;
		cout<<"����";
		cin>>s;
		cout<<"ֵ��";
		cin>>id;
	    m[s]=id;
	}
	//��һ�ֱ������
	map<string,int>::iterator it;
	//����uuu
	int ii=m.count("uuu"),tt=m.count("kkk");
	if(ii==1){
		cout<<"���ҳɹ�"<<endl;
	}
	else{
		cout<<"����ʧ��"<<endl;
	}
	if(tt==1){
		cout<<"���ҳɹ�"<<endl;
	}
	else{
		cout<<"����ʧ��"<<endl;
	}
	cout<<"map�еļ�ֵ������ :"<<endl;
	for(it=m.begin();it!=m.end();it++){
		cout<<"��="<<it->first<<" ֵ="<<it->second<<endl;
	}
	return 0;
}