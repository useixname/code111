#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
double n,w,m;

double f(double mid){
    double sum=0;
    for(int i=1;i<=m;i++){
        sum+=(w/pow(1+mid,i));
    }
    return sum;
}
int main(){
    cin>>n>>w>>m;
    double l=0,r=301;
    while(r-l>=0.0001){
        double mid=(l+r)/2;
        if(f(mid)<=n){
            r=mid;
        }
        else{
            l=mid;
        }
    }
    printf("%.1lf",l*100);
    return 0;
}