#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
typedef struct node
{
    int val;
    struct node* next = NULL;    
} node;
node* root = NULL;
void insert( int val) {
    node* newnode = (node*) malloc(sizeof(node));
    newnode->val = val;
    newnode->next = NULL;
    if(root == NULL) root = newnode;
    else {
         node* currentnode = root;
         while(currentnode->next != NULL) currentnode = currentnode->next;
         currentnode->next = newnode;
    }

}
void print() {
    node* currentnode = root;
    while(currentnode != NULL) {
        printf("%d ", currentnode->val);
        currentnode= currentnode->next ;
    }
    printf("\n");
}
bool find(int val) {
  int flag = 0;
  node* currentnode = root;
    while(currentnode != NULL) {
        if(currentnode->val == val) {
            flag = 1;
            break;
        }
        currentnode= currentnode->next ;
    }
    return flag;
}
void del(int val) {
  int flag = 0;
  node* currentnode = root;
  if(root->val == val) {
      root = root->next;
      free(currentnode);
      flag = 1;
  } else {
    while(currentnode->next != NULL) {
        if(currentnode->next->val == val) {
            node* temp = currentnode->next;
            currentnode->next = currentnode->next->next;
            free(temp);
            flag = 1;
            break;
        }
        currentnode= currentnode->next ;
    }
  }
  if(flag) printf("DELETEDxd\n");
}
int main() {
    node* root = NULL;
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
        else if(k==3) {
            int a; scanf("%d", &a);
            if(find(a)) printf("yabadaba\n");
            else printf("brentwoodmarket\n");
        }
        else if(k==4) print();

    }
    
}
 