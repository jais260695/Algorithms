#include <iostream>
#include <bits/stdc++.h>
#include<time.h>
using namespace std;
struct Edge{
    int src;
    int dest;
};
struct Graph{
    int V,E;
    struct Edge *edge; 
};
int findSet(int a,int parent[]){
    if(parent[a]==a){
        return a;
    }
    return findSet(parent[a],parent);
}
void unionSet(int x,int y,int parent[]){
    int a=findSet(x,parent);
    int b=findSet(y,parent);
    parent[a]=b;
}
 
int KargerAlgo(struct Graph* graph)
{
   
    int V = graph->V, E = graph->E;
    Edge *edge = graph->edge;
    
    int *parent=(int *)malloc(((graph->V)+1)*sizeof(int));
    for(int i=0;i<=V;i++){
    	parent[i]=i;
    }
   
 
   
    while (V > 2)
    {
     
       int i = rand() % E;
 
      
        int x=findSet(graph->edge[i].src,parent);
        int y=findSet(graph->edge[i].dest,parent);
 		if(x==y){
            continue;
        }
        else
        {
        
        	 unionSet(x,y,parent);
          V--;
        
        }
    }
 
    
    int cutedges = 0;
    for (int i=0; i<E; i++)
    {
         int x=findSet(graph->edge[i].src,parent);
        int y=findSet(graph->edge[i].dest,parent);
        if (x != y)
          cutedges++;
    }
 
    return cutedges;
}
 


struct Graph* createGraph(int V, int E)
{
    Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}
 

 
int main() {
	
	vector<vector<int> > adj;
	int no_of_vertex=0;
	int no_of_edges=0;;
	int data;
	string line;
  	ifstream myfile ("example3.txt");
  	if (myfile.is_open())
  	{
    	while ( getline (myfile,line) )
    	{
    		vector<int> v;
        	istringstream streamA(line);
        	while(streamA >>data)
			{
        		v.push_back(data);
        	}
        	no_of_edges+=(v.size()-1);
        	adj.push_back(v);
	
    	}
    	myfile.close();
  	}
  	no_of_edges/=2;
  	no_of_vertex=adj.size();
	struct Graph* graph = createGraph(no_of_vertex, no_of_edges);
	 int cntr=0;
	 
	for(int i=0;i<adj.size();i++)
	{
		for(int j=0;j<adj[i].size()-1;j++)
		{
			if(adj[i][0]<adj[i][j+1]) continue;
				graph->edge[cntr].src=adj[i][0];
           		graph->edge[cntr++].dest=adj[i][j+1];
		}
           	
		//cout<<endl;
	}

	srand(time(NULL));
      int m=1000;
      for(int i=0;i<1000;i++)
          m=min(m,KargerAlgo(graph));
           cout<<m<<endl;
	return 0;
}
