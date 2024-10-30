/*
A graph can be called eulerian if 
(1)  all edges are present in one component only
(2) count odd degree of nodes
    -> if count == 0 => Eulerian Graph (start and end both same)
    -> if count == 2 => Semi-Eulerian Graph (start and end both not same)
    -> if count > 2  => not eulerian graph
*/

#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int> > g; // directed graph
vector<int> degree; // degree of the node

void DFS(int curr,vector<bool>& visited)
{
	visited[curr]=true;
	for(auto it: g[curr])
	{
		if(!visited[it])
			DFS(it,visited);
	}
}

bool allEdgesInOneComponent()
{
    int n = int(g.size());
	vector<bool> visited(n+1,false);
	int node = -1;	//Node to start DFS
	for(int i=0;i<V;++i)
		if(g[i].size()>0)
		{
			node = i;	//Found a node to start DFS
			break;
		}
	if(node == -1)	//No start node was found-->No edges are present in graph
		return true; //It's always Eulerian

	DFS(node,visited);
	//Check if all the non-zero vertices are visited
	for(int i=0;i<n;++i)
		if(visited[i]==false and g[i].size()>0)
			return false;	//We have edges in multi-component
	return true;
}

int findEuler(){
    if( !allEdgesInOneComponent() ){
        return 0;
    }

    // count of odd-degree vertices
    int cnt = 0;
    for( int i=0; i<int(g.size()); i++ ){
        if( g[i].size()%2 ){
            cnt++;
        }
    }

    if( cnt > 2 ){
        return 0;
    }

    return cnt == 0 ? 2:1;

}

void checkEulerGraph( ){
    int ret = findEuler();

    if( ret == 0 ){
        cout << "Graph is not a Euler Graph\n";
    }else if( ret == 1 ){
        cout << "Graph is a Semi-Euler Graph\n";
    }else{
        cout << "Graph is a Euler Graph\n";
    }


}


