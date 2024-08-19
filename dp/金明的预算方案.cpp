#include<iostream>  
using namespace std;  
int m,n,mw[33333],mv[33333],fw[33333][3],fv[33333][3],f[33333],v,p,q,cnt[65];  
//mw主件重量，mv主件价值，fw主件对应的附件重量，fv主副价值，n总重量，m总个数   
int main()  
{  
    cin>>n>>m;  
    for(int i=1;i<=m;i++){  
    cin>>v>>p>>q;  
    if(!q){//如果是主件   
        mw[i]=v;//主件重量   
        mv[i]=v*p;//主件价值与重量乘积
    }  
    else{//如果是附件
        cnt[q]++;//记录主件的附件个数
        fw[q][cnt[q]]=v;//主件的个数是用来确定该附件应该填在第一个还是第二个格子里   
        fv[q][cnt[q]]=v*p;//（是第一个还是第二个附件）   
    }  
    }
    for(int i=1;i<=m;i++)
    for(int j=n;j>=mw[i];j--){//01背包模板   
    //每一个if的前提是背包能不能装下该物品   
        //情况1：只要主件 和啥都不要比较   
        f[j]=max(f[j],f[j-mw[i]]+mv[i]);  
        //情况2：主件和附件1 和上面选出的较大值比较   
        if(j>=mw[i]+fw[i][1])f[j]=max(f[j],f[j-mw[i]-fw[i][1]]+mv[i]+fv[i][1]);  
        //情况3：主件和附件2 和上面选出的较大值比较   
        if(j>=mw[i]+fw[i][2])f[j]=max(f[j],f[j-mw[i]-fw[i][2]]+mv[i]+fv[i][2]);  
        //情况4：都要   
        if(j>=mw[i]+fw[i][1]+fw[i][2])
        f[j]=max(f[j],f[j-mw[i]-fw[i][1]-fw[i][2]]+mv[i]+fv[i][1]+fv[i][2]);  
    }  
    //输出在价值为n时能得到的最大值   
    cout<<f[n]<<endl;  
    return 0;  
}