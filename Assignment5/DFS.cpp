#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 struct Edge{
    int src;
    int dest;
};
struct Graph{
    int V,E;
    vector<int> *adjlist;
};
struct Graph* createGraph(int V, int E)
{
    Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->adjlist = new vector<int>[V];
    return graph;
}

void DFSUtil(struct Graph*  graph,int v, bool visited[],int *count)
{
    int V = graph->V,E = graph->E;
 	vector<int>:: iterator i;
    visited[v] = true;
    (*count)++;
 
 	for(i=graph->adjlist[v].begin();i!=graph->adjlist[v].end();i++){
			if(!visited[*i]){
				DFSUtil(graph,*i, visited, count);		
			}
		}    
}
 
struct Graph* getTranspose(struct Graph*  graph)
{
    int V = graph->V,E = graph->E;
    struct Graph* tempG = createGraph(V, E);
    for(int v=0;v<V;v++)
	{
	vector<int>:: iterator i;
	    for(i=graph->adjlist[v].begin();i!=graph->adjlist[v].end();i++)
		{
		 tempG->adjlist[*i].push_back(v);
		}
		
	}
	
   
    return tempG;
}
 
void DFS(struct Graph* graph,int v, bool visited[], stack<int> &Stack)
{
 
    visited[v] = true;
    vector<int>:: iterator i;
   for(i=graph->adjlist[v].begin();i!=graph->adjlist[v].end();i++){
   	
			if(!visited[*i]){
				//cout<<"here"<<endl;  
				DFS(graph,*i, visited, Stack);		
			}
		}
       
    Stack.push(v);
}
 
void printSCCs(struct Graph* graph)
{
    stack<int> Stack;
    int count;
    int V = graph->V,E = graph->E;
    
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
	{
		visited[i] = false;
    	}	
    

    for(int i = 0; i < V; i++)
	{
	//	cout<<i<<endl;
		if(visited[i] == false)
		{
	
			DFS(graph,i, visited, Stack);
//			cout<<"done"<<endl;			
        	}
    	}
        
          

   
    struct Graph* gr =getTranspose(graph);
 
   for(int i = 0; i < V; i++)
        visited[i] = false;

vector<int> all; 
    while (Stack.empty() == false)
    {
     
        int v = Stack.top();
        Stack.pop();
 
        if (visited[v] == false)
        {
        	count=0;
            DFSUtil(gr,v, visited,&count);
     //       cout <<count<< endl;
	    all.push_back(count);
        }
    }

	while(all.size()<5)	all.push_back(0);

	sort(all.begin(),all.end());
	reverse(all.begin(),all.end());

	for(int i=0;i<5;++i)
		cout<<all[i]<<" ";
	cout<<endl;
}
 

int main()
{
    
   vector<vector<int> > adj;
	int no_of_vertex=875714;
	int no_of_edges=0;
	 int cntr=0;
	int data;
	string line;
  	ifstream myfile ("example4.txt");
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
        	no_of_edges++;
        	adj.push_back(v);
	
    	}
    	myfile.close();
  	}
 
	struct Graph* graph = createGraph(no_of_vertex, no_of_edges);

	 
	for(int i=0;i<adj.size();i++)
	{
		//cout<<adj[i][0]-1<<" "<<adj[i][1]-1<<endl;

			  graph->adjlist[adj[i][0]-1].push_back(adj[i][1]-1);
			        	
	}
 

    printSCCs(graph);
 
    return 0;
}
