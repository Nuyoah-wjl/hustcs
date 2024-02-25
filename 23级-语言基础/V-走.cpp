//V
#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
#define maxm 2000005
#define inf 0x3f3f3f3f
template <typename Tp>
void read(Tp &x){
    char c=getchar();x=0;int f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}x*=f;
}//���ٶ��룬������ 
struct Edge{
    int f,t,w,nxt;
}edge[maxm];
int head[maxn],etot=1;//������һ��С���ɣ���ͼʱ������ֵ��Ϊһ������ 
void add_edge(int f,int t,int w){//������������λ����ɶԱ仯�ҵ������ 
    edge[++etot]=(Edge){f,t,w,head[f]};
    head[f]=etot;
}//��ʽǰ���Ǵ�ͼ 
//--------��������Ϊ zkw�߶���
//��Ҫ˼·�����߶���ά��dis
//dis1�����ʾ���߶����е�dis
//tr�����¼��ǰ��Сdis��Ӧ�Ľڵ��� 
//�й�zkw�߶��������Բο�����ձ��Ľ��⣬���ﲻ��˵ 
int tr[maxn<<2],dis1[maxn<<2],bt;
int n,m,S,T;
void build(){
    for(bt=1;bt<=n+1;bt<<=1);//bt��ʼ����zkw�߶����ĳ�ʼ���� 
    for(int i=1;i<=n;i++)tr[i+bt]=i;//tr�����ʼ�� 
    memset(dis1,0x3f,sizeof(dis1));//dis1�����ʼ�� 
    //��Ϊ����dis��ֵ����inf�����Կ�������ֱ�Ӹ�ֵ 
}
void modify(int x,int val){
    dis1[x]=val;x+=bt;//�����޸� 
    for(x>>=1;x;x>>=1){//������zkw�߶���������� 
        if(dis1[tr[x<<1]]<dis1[tr[(x<<1)|1]])tr[x]=tr[x<<1];
        else tr[x]=tr[(x<<1)|1];
    }
}//��ʵ��������ݲ����Ǻܳ���ֻ��ע�ͱȽ϶� 
int dis[maxn];
void dijkstra(){
    memset(dis,0x3f,sizeof(dis));
    build();//build()������ 
    dis[S]=0;modify(S,0);//Դ����� 
    int x,y,w;
    for(int j=1;j<=n;j++){//����tr[1]ά������[1,n]dis����Сֵ�Ľڵ��ţ�����ֱ�ӵ��� 
        x=tr[1];modify(x,inf);//���ｫx��Ϊ����ֵ����ȡ��ɾ������ 
        for(int i=head[x];i;i=edge[i].nxt){
            y=edge[i].t;w=edge[i].w;
            if(dis[y]>dis[x]+w){//dijkstra�ɳڲ��� 
                dis[y]=dis[x]+w;
                modify(y,dis[y]);//ֱ�Ӹ��� 
            }
        }
    }
}
int dx[]={0,1,0,-1,1,1,-1,-1,0,2,0,-2};//12����ħ������ 
int dy[]={1,0,-1,0,1,-1,1,-1,2,0,-2,0};
int dw[]={0,0,0,0,2,2,2,2,2,2,2,2};
int a[105][105],cnt[105][105];
struct node{
    int x,y,c;
}b[maxn];
//a�洢�����ϸ��ӵ���ɫ 
//cnt��ʾ�����ϵĸ��Ӷ�Ӧ�Ľڵ��� 
void preprocess(){//��ͼ 
    int x,y,c,xx,yy,ww;
    for(int i=1;i<=n;i++){
        x=b[i].x;y=b[i].y;c=b[i].c;
        for(int j=0;j<12;j++){
            xx=x+dx[j];yy=y+dy[j];ww=dw[j];
            if(a[xx][yy]){
                if(a[xx][yy]!=c)ww++;
                add_edge(i,cnt[xx][yy],ww);
            }
        }
    }//��һ������������н��ıȽ���ϸ�����ﲻ�ٶ�˵ 
    S=cnt[1][1];
}
int main(){
    int mm,x,y,c;
    read(mm);read(n);
    for(int i=1;i<=n;i++){
        read(x);read(y);read(c);
        a[x][y]=c+1;cnt[x][y]=i;
        b[i]=(node){x,y,c+1};
    }//����c+1��Ϊ�˷���������ɫ���� 
    preprocess();
    dijkstra();//��Ϊ��ͼ����m������ĺ����Ǳ��� 
    if(!a[mm][mm]){//������mmȡ��ԭ��Ŀ�е�m�������̴�С 
        int ans=min(dis[cnt[mm][mm-1]],dis[cnt[mm-1][mm]])+2;
        if(ans>=inf)puts("-1");
        else printf("%d\n",ans);
    }//(m,m)û����ɫ������ 
    else{
        if(dis[cnt[mm][mm]]==inf)puts("-1");
        else printf("%d\n",dis[cnt[mm][mm]]);
    }
    return 0;
}
