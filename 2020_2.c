// 2.2 for MST - Kruskal's Algorithm for MST:
//     BFS DFS - visited array
//     dijkstra - priority queue
    
// 2.3 AVL porayni
// 2.4 RADIX SORT sir porayni

// 2.5 so here head means root and tail mean last element in the  link list ;
// lets say the link list would be something like 
// i) 61 
ii) 61 50
iii) 61 43 50
iv) 54 61 43 50
v) 54 41 61 43 50
vI) 54 41 43 50
vIi) 54 41 43 50 21
viii) 54 41 43 21
ix)21 43 42 54
x) 21 43 42 
// some implemantation for the hell of it
typedef struct node
{
    int val;
    struct node* next;
    struct node* prev;
} node;
//  we will have to variable node* head and tail , initially both will be null
 node* head = NULL, tail = NULL;
 // insert will work like any insert function we have seen, traverse from root till we find a emptty
 // currentnode->next, then we will insert it there ,but since we have last node saved as tail we dont need travers
 void insert(int x) {
    node* newnnode; // we will  create a node here with malloc , skipping that step
    if(head == NULL) {
       head = newnnode;
       tail = newnnode;
    } else tail->next = newnnode, newnnode-prev = tail , tail = newnnode;
 }  
 //insert at tail would be exactly similar to normal insert
 // insert at head , here we insert the element at the start 
 void inserthead(int x) {
     node* newnnode; // we will  create a node here with malloc , skipping that step
     newnnode->next = head;
     head->prev = newnnode;
     head = newnnode;
 }
 //anyway the implementation is not needed 
 2.6 disjoint set sir poray ni i think
