/**
  *@filename:�ȵ�����
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-12 11:23
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int l,r,k,b;
int f[35][35];
//����������Ԥ����f���顣����f[i][j]��ʾʣ�»���i��û���Ҫ��дj��1�ķ�������
void init(){
    for(int i=0;i<35;i++){
        for(int j=0;j<=i;j++){
            if(!j)f[i][j]=1;
            else{
                f[i][j]=f[i-1][j]+f[i-1][j-1];
            }
        }
    }
}
int dp(int n){
    //���f(n)��������Ҫ����nΪ0�������������Ҫ���С�
    if(!n)return 0;
    vector<int> nums;//��n�ָ�洢λ����
    while(n){
        nums.push_back(n%b);
        n/=b;
    }
    int ans=0;//�𰸡�
    int last=0;//ǰ�����Ϣ������������ǰ���֧ѡȡ�˶��ٸ�1.
    for(int i=nums.size()-1;i>=0;i--){
        int x=nums[i];
        if(x){
            //˵��x>0�����ǿ���ѡ����߷�֧��0.
            ans+=f[i][k-last];
            if(x>1){
                //��x>1���ǲſ���ö����߷�֧��1.
                if(k-last-1>=0){
                    //�����������1�Ļ���
                    ans+=f[i][k-last-1];
                }
                break;//��Ϊ�ұ߷�ֻ֧��Ϊ0��1�����Բ�����������break��
            }
            else{
                //��x=1�Ϳ��Խ����ұߵķ�֧�������ۡ�
                last++;
                if(last>k)break;
            }
        }
        //���ǵ����һλ���������������ôĩλ��0Ҳ��һ�ַ�����
        if(!i&&last==k)ans++;
    }
    return ans;
}
void solve(){
}
int main(){
    cin>>l>>r>>k>>b;
    init();
    cout<<dp(r)-dp(l-1)<<endl;
    solve();
    return 0;
}
