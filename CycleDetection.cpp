#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// class Edge{

// public:
//     int u;
//     int v;

//     Edge(int v){
//      this->v = v;
//     }
// };

// bidirectional Graph
void addEdge(int u,int v,vector<vector<int>>&graph){

    graph[u].push_back(v);
    graph[v].push_back(u);
}

// Directed Graph
// Khan's Algorithm

void addEdgeDirectedGraph(int u,int v,vector<vector<int>>&graph){

    graph[u].push_back(v);
}

vector<int> KhansAlgo(vector<vector<int>>&graph){

   vector<int>incidentEdges(graph.size(),0);
   
   for(int i=0;i<graph.size();i++){
       for(int ele : graph[i]){
           incidentEdges[ele]++;
       }
   }
   
   queue<int> que; 
  
   for(int i=0;i<incidentEdges.size();i++){
       if(incidentEdges[i] == 0) que.push(incidentEdges[i]);
   }

    vector<int>ans; 
   while(!que.empty()){
       int rvtx = que.front();
       que.pop();
       ans.push_back(rvtx);

       for(int ele : graph[rvtx]){
           if(--incidentEdges[ele] == 0){
               que.push(ele);
           }
       }
   }  

   return ans;

}



void checkCycle(vector<vector<int>>&graph,int src,vector<bool>&vis){

queue<int> que;
que.push(src);

while(!que.empty()){

int size = que.size();

while(size--){
int top = que.front();
que.pop();

if(vis[top]){
    cout<<"Cycle Detected wrt "<<top<<endl;

}

vis[top] = true;

for(int ele : graph[top]){
      
          if(!vis[ele])
          {
              que.push(ele);
          }
}

}


}

}

//isGraphBipartite

bool isGraphBipartite(vector<vector<int>>&graph,int src){

if(graph.size() % 2 !=0) return false;

vector<int> verticesColor(graph.size(),-1);

verticesColor[src] = 0;

queue<pair<int,int>>que;

que.push({src,0});

while(!que.empty()){

    pair<int,int> rp = que.front();
    que.pop();
    int color = rp.second;
    int rvtx = rp.first;
    if(verticesColor[rvtx]!=-1){
    if(verticesColor[rvtx]!=color) return false;
     else continue;
    }
    verticesColor[rvtx] = color;
    for(int ele : graph[rvtx]){
        que.push({ele,(color+1)%2});
    }

}
return true;

}


int main(){

int v;
int e;

cin>>v>>e;

vector<vector<int>>graph(v,vector<int>());
vector<vector<int>>graphDirected(v,vector<int>());

for(int i=0;i<e;i++){
    int u,v;
    cin>>u>>v;
    addEdge(u,v,graph);
}

// for(int i=0;i<e;i++){
//     int u,v;
//     cin>>u>>v;
//     addEdgeDirectedGraph(u,v,graphDirected);
// }


// vector<bool>vis(v,false);

// checkCycle(graph,0,vis);

vector<int> ans = KhansAlgo(graphDirected);

for(int ele: ans) cout<<ele<<" ";
cout<<endl;
if(ans.size()!=graphDirected.size()) cout<< "Cycle Detected"; 
else cout<<"Cycle Not Detected"<<endl;

cout<<(boolalpha)<<isGraphBipartite(graph,0);


}

