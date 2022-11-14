#include<bits/stdc++.h>
using namespace std;

int number_of_nodes;
vector<int> v[100000];
int visited[100000];


void DFS(int p)
{
    

    if(visited[p]==1)
      return;

   visited[p]=1;
   number_of_nodes++;

   for(int child : v[p])
   {
      DFS(child);
   }


}
int main(){

   int n, i;
   cin >> n;
   set<int> nodes_list;

   int x, y;

   for(i = 0; i<n; i++)
   {
      cin>>x>>y;
      v[x].push_back(y);
      v[y].push_back(x);
   }
   for(i=1; i<=n; i++)
   {
      number_of_nodes=0;
      DFS(i);
      nodes_list.insert(number_of_nodes);
   }
  for (auto it = nodes_list.begin(); it != nodes_list.end(); ++it)
  if(*it!=1 && *it!=0)
  {
        cout <<*it<<endl;
        break;
  }
  cout<<*nodes_list.end()<<endl;
}