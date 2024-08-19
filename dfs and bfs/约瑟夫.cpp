#include<bits/stdc++.h>
using namespace std;
//用递归实现约瑟夫环问题
 
int ysfdg(int N,int M,int i)
{
    if(i==1)
    {
    	return (M-1+N)%N;
	}
    return (ysfdg(N-1,M,i-1)+M)%N;
}

int main()
{
	int N,M=1;
	cin>>N;
    while(M){
        bool flag=1;
        for(int i=1;i<=N;i++){
            int x=ysfdg(2*N,M,i);
            if(x>=0&&x<N){
                flag=0;
                break;
            }
        }
        if(flag){
            cout<<M;
            return 0;
        }
        M++;
    }
	return 0;
} 