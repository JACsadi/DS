#include <stdlib.h>
#include <stdio.h>
typedef struct node
{
    int val; 
    struct node* prev;  
} node;
node* last = NULL;
int sz;
node* createnode(int x) {
    node* temp = (node*) malloc(sizeof(node));
    temp->val = x;
    temp->prev = NULL;
    return temp;
}
void push(int x) {
    node*  newnode = createnode(x);
    if(last == NULL) last = newnode;
    else {
        newnode->prev = last;
        last = newnode;
    } 
    sz++;
}
void pop() {
    if(!sz) printf("ERROR! UNDERFLOW");
    else {
        node* temp = last;
        last = last->prev;
        free(temp);
        sz--;
    }
}
bool empty() {
    if(sz) return 1;
     return 0;
}
int top() {
    if(!sz) return -1;
    return last->val;
}
void print() {
    node* currentnode = last;
    while (currentnode != NULL)
    {
        printf("%d ", currentnode->val);
        currentnode = currentnode->prev;
    }
    printf("\n");
}
int main() {
    while(1) {
        printf("1 to push, 2 to pop , 3 to top, 4 empty , 5 to print\n");
        int a; scanf("%d", &a);
        if(a == 1) {
            int x; scanf("%d", &x);
            push(x);
        }else if(a == 2) pop();
        else if(a == 3) printf("%d\n", top());
        else if(a == 5) print();
    }
}