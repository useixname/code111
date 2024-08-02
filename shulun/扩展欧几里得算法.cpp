#include <bits/stdc++.h>
using namespace std;

int x,y;
int ex_gcd(int a, int b, int &x, int &y)
{
    if (b==0)
    {
        x = 1, y = 0;
        return a;
    }

    int d = ex_gcd(b, a % b, y, x);
    y -= a / b * x;

    return d;
    // int ans=ext_gcd(b,a%b,x,y);
    // int temp=x;
    // x=y;
    // y=temp-a/b*y;
    // return ans;
}

void cal(int a,int b,int c){
    int res = ex_gcd(a,b,x,y);
    if(c%res) printf("Impossible\n");
    else{
        int x0 = x * c/res;//求第二个特解
        //int y0 = y * c/res;
        int L = b/res;
        if(L<0) L = -L;
        int X = (x0%L + L)%L;//求x通解里的最小正整数
        int Y = (c - a*X)/b;
        printf("when x have the bestmin solution x = %d,y = %d\n",X,Y);
        int c1=a*X+b*Y;
        if(c1==c){
            printf("%d x %d + %d x %d = %d",a,X,b,Y,c);
        }
        else{
            printf("%d x %d + %d x %d != %d",a,X,b,Y,c);
        }
    }
}
int main()
{
    int a, b,c,t;
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        cal(a,b,c);
    }
    return 0;
}