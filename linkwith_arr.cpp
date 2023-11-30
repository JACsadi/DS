#include <stdlib.h>
#include <stdio.h>
int linklist[1000][2]; // first one will hold value , second will hold prev node index
int size;
int last ;
void insert(int val) {   
    int index = last;
    while(linklist[index][0]) index = linklist[index][1];
    linklist[index][0] = val;
    linklist[index][1] = ++size;
}
void del(int a) {
   int index = last;
   if(linklist[last][0] == a) last = linklist[last][1];
    while(linklist[linklist[index][1]][0]) {
        if(linklist[linklist[index][1]][0] == a) {
         linklist[index][1] = linklist[linklist[index][1]][1]; 
         break;
        }
        index = linklist[index][1];
    }
}
void print() {
      int index = last;
    while(linklist[index][0]){
    printf("%d ", linklist[index][0]);
    index = linklist[index][1];
    }
    printf("\n");
}
int main() {
      while (1)
    {
        printf("1 to insert, 2 to delete, 3 find, 4 to print\n");
        int k; scanf("%d", &k);
        if(k ==1) {
            int a; scanf("%d", &a);
            insert(a);
        }
        else if(k==2) {
            int a; scanf("%d", &a);
            del(a);
        }
        // else if(k==3) {
        //     int a; scanf("%d", &a);
        //     if(find(a)) printf("yabadaba\n");
        //     else printf("brentwoodmarket\n");
        // }
        else if(k==4) print();

    }
}