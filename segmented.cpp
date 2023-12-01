#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <ctype.h>
using namespace std; 
 void build( int initial[], int tree[],int v,int l,int r)
{
    int m=(l+r)/2;
    if(l==r) tree[v]=initial[l];
     else{
        build(initial,tree,(2*v)+1,l,m);
        build(initial,tree,(2*v)+2,m+1,r);
        tree[v]=tree[1+(2*v)]+tree[1+(2*v)+1];
     }
}
void update(int tree[], int dif,  int index, int l, int r,int v ) {
    tree[v] += dif;
    int m=(l+r)/2;
    if(l != r) {
    if(index <= m) update(tree, dif, index, l, m, (v*2)+1);
    else update(tree, dif, index, m+1, r, (v*2)+2);
    }
}

int sum(int tree[],int v, int s,int e,int l, int r)
{
    if(l==s && r==e) return tree[v];
    if(s>e) return 0;
    int m=(l+r)/2;
    return sum(tree,(v*2)+1,s,min(m,e), l, m) + sum(tree,(v*2)+2,max(s,1+m),e , 1+(m),r); 
}

int main()

{

int n,ele;
scanf("%d", &n);
int init[n+1];
for(int i=1;i<=n;i++)
    scanf("%d",&init[i]);
int tree[2*n];
for(int i=0;i<2*n;i++)
    tree[i]=-1;
build(init,tree,0,1,n);

for(int i=0;i<=2*n;i++)
    printf("%d ",tree[i]);
    printf("\n");
while(1) {
     printf("0 to break, 1 update, 2 for sum from l to r\n");
     int k;
     scanf("%d", &k);
     if(!k) break;
     if(k == 1) {
    int ind , val;
    scanf("%d %d", &ind, &val);
    int dif = val - init[ind];
    update(tree, dif, ind, 1, n, 0 );
     } else if(k == 2) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", sum(tree,0,l,r,1,n));
     }
}
for(int i=0;i<=2*n;i++)
    printf("%d ",tree[i]);
return 0;
}