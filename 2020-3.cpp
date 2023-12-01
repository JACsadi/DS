#include <iostream>
#include <vector>
#include <ctype.h>
using namespace std;
vector <int> adj_list[8]; // a to h 8 nodes
int indegree[8], visited[8];
int dep_mat[8][8]; // matrix for dependency , using matrix for convenience , we can also use list instead 
void dfs(int node) {
      visited[node]  = 1;
      for(int i = 0; i < adj_list[node].size(); i++) {
        for(int j = 0; j < 8; j++)  if(dep_mat[node][j]) dep_mat[adj_list[node][i]][j] = 1; // if b is dependent on a, them b is dependent on everything a is dependent on , so we are copying a's dependency on b
        dep_mat[adj_list[node][i]][node] = 1; // since b is dependent on a , dep_mat[1][0] will be 1
       if()  dfs(adj_list[node][i]);
      }
}
int main() {
    int edges;
    scanf("%d", &edges);
    for(int i = 0; i < edges; i++) {
       char u , v;
       scanf("%c %c", &u, &v); // input will be between [a-]
       adj_list[u-'a'].push_back(v-'a'); // u is a character u - 'a' will return 0 for a 1 for b 2 for c etc 
       indegree[v-'a']++; //increasing the indegree of the dependent node, its directed so the indegree of u will not change
    }
    //now we will call dfs for every node who's indegree is zeroooo
    for(int i = 0; i < 8; i++) {
       if(indegree[i] == 0) dfs(0);
    }
    for(int i = 0; i <8;i++) {
        printf("%c is dependent on - ", (char)('a'+i));
        for(int j =0; j <8; j++) {
         if(dep_mat[i][j]) printf("%c ", (char)('a'+j) );
        }
        printf("\n")
    }
}