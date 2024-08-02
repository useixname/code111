#include<cstdio>
#include<iostream>
#include<string>
#include<cmath> 
using namespace std;
int n;//������ 
string tr[30];//�洢�ַ��� 
int yc[30][30];//������ĸ����С�ص����� 
int vis[30];//�жϵ���ʹ��Ƶ��. 
int mt(int x, int y){//mt����������x���ʺ�����һ��y���ʵ���С�ص����� 
    bool pp=true; 
    int ky=0;
    for(int k=tr[x].size()-1;k>=0;k--){//��x����β����ǰ������С�ص������Ǵ����￪ʼ�ģ���Ϊ��Ϊ�ǵ����������Ա�֤����С�� 
        for(int kx=k;kx<tr[x].size();kx++){
            if(tr[x][kx]!=tr[y][ky++]){
                pp=false;
                break;
            }
        }
        if(pp==true){//���˵��ǰ��kΪ��ͷ��ǰһ�����ʺ�׺ ,�Ǻ��浥�ʵ�ǰ׺�������Ϸ����ص����֡���tr[x].size()-k���ҳ����Ĺ��ɣ�
            return tr[x].size()-k;        } 
        ky=0;
        pp=true;//���оͼ���
    }
    return 0;
}//���������е�����⡣�����ֶ�ģ��һ��

int mt1(int x,int y){
    bool flag=true;
    int ty=0;
    for(int i=tr[x].size()-1;i>=0;i--){
        for(int j=i;j<tr[x].size();j++){
            if(tr[x][j]!=tr[y][ty++]){
                flag=false;
                break;
            }
        }
        if(flag){
            return tr[x].size()-i;
        }
        ty=0;
        flag=true;
    }
    return 0;
}
char ch;//��ͷ��ĸ 
int ans=-1;//�� 
int an=0;//ÿ���ѵ��ĵ�ǰ��� 
void dfs(int p){//pΪβ�����ʱ��(p�ĺ�׺���ǡ������ĺ�׺����Ϊp�Ѿ����ӵ�������������)
    bool jx=false; 
    for(int j=1;j<=n;j++){
        if(vis[j]>=2) continue;//ʹ�������ξ����� 
        if(yc[p][j]==0) continue;//������֮��û���غϲ��־����� 
        if(yc[p][j]==tr[p].size() || yc[p][j]==tr[j].size()) continue;//���ߴ��ڰ�����ϵ������ 
        an+=tr[j].size()-yc[p][j];//�����ʺϲ��ټ�ȥ��С�غϲ��� 
        vis[j]++;//ʹ����һ��
        jx=true;//���һ�µ�ǰ�Ѿ��ɹ�ƥ�䵽һ���������ӵĲ��� 
        dfs(j); //����ȥ
        an-=tr[j].size()-yc[p][j];//���ݣ���Ҫ�ټ���ȥ��һ���ֳ��� 
        vis[j]--;//����,ʹ��-- 
    }
    if(jx==false){//jx==false˵���������ҵ��κ�һ�����ʿ��������� 
        ans=max(ans,an);//����ans 
    }
    return;
}

void dfs1(int u){
    bool flag=false;
    for(int i=1;i<=n;i++){
        if(vis[i]>=2) continue;
        if(yc[u][i]==0) continue;
        if(yc[u][i]==tr[i].size()||yc[u][i]==tr[u].size()) continue;
        flag=true;
        an+=tr[i].size()-yc[u][i];
        vis[i]++;
        dfs(i);
        vis[i]--;
        an-=tr[i].size()-yc[u][i];
    }
    if(!flag){
        ans=max(ans,an);
    }
    return;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        cin>>tr[i];
    cin>>ch; 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            yc[i][j]=mt(i,j); 
        }
    }//Ԥ����yc���顣yc[i][j]�ͱ�ʾ��i���ʺ�����һ��j���ʵ���С�ص����� 
    //���� i��ʾat,j��ʾatt. yc[i][j]��Ϊ2 ����yc[j][i]��Ϊ0.
    //Ԥ������һ���ؼ�
     
    for(int i=1;i<=n;i++){//��ͷ��β��һ����û����ָ����ͷ��ĸΪ��ͷ�ĵ��� 
        if(tr[i][0]==ch){//����У����Ե�ǰ����Ϊ��׼���������� 
            vis[i]++;//ʹ�ù�һ�� 
            an=tr[i].size();//���µ�ǰ������ 
            dfs(i);//����
            vis[i]=0;//����Ӱ�� 
        } 
    } 
    printf("%d",ans);
    return 0;
}
