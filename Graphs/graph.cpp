#include <iostream>
#include <list>
#include <queue>
using namespace std;

class graph
{
	public:
	int v; //vertices
	list<int> *arr;

	graph(int v)
	{
		this->v = v;
		arr = new list<int>[this->v];
	}

	void addEdge(int u, int v, bool bidir=true)
	{
		this->arr[u].push_back(v); //edge from u to v
		if(bidir==true)
			this->arr[v].push_back(u);  //edge from u to v if it's bidirectional
	}

	void display()
	{
		for (int i = 0; i < this->v ; ++i)
		{
			cout<<i<<" --> ";
			for(int el:this->arr[i])
				cout<<el<<" ";
			cout<<endl;
		}
	}

	void bfs(int src)
	{
		queue<int> qu;
		bool *visited = new bool [this->v]();
		qu.push(src);
		visited[src] = true;
		while(!qu.empty())
		{
			int to_be_removed = qu.front();
			qu.pop();
			cout<<to_be_removed<<" ";
			for(int neighbours: this->arr[to_be_removed])
			{
				if(visited[neighbours]==false)
				{
					qu.push(neighbours);
					visited[neighbours] = true;
				}
			}
		}
        delete [] visited; 
	}

	void dfshelper(int src, bool *visited)
	{
		visited[src] = true;
		cout<<src<<" ";
		for(int neighbours: this->arr[src])
		{
			if(visited[neighbours]==false)
				dfshelper(neighbours,visited);
		}
	}

	void dfs(int src)
	{
		bool*visited = new bool [this->v];
		dfshelper(src,visited);
        delete [] visited;
	}

	void dfshelper1(int src, bool *visited)
	{
		visited[src] = true;
		for(int neighbours: this->arr[src])
		{
			if(visited[neighbours]==false)
				dfshelper1(neighbours,visited);
		}
	}

	int connectedComponents()
	{
		int result = 0;
		bool *visited = new bool[this->v];
		for (int i = 0; i < this->v; ++i)
		{
			if(visited[i]==false)
			{
				dfshelper1(i,visited);
				result++;
			}
		}
		return result;
	}

};

int main(int argc, char const *argv[])
{
	graph *g = new graph(7);
	g->addEdge(0,1,true);
	g->addEdge(0,2,true);
	g->addEdge(1,3,true);
	g->addEdge(2,3,true);
	g->addEdge(1,4,true);
	g->addEdge(4,5,true);
	g->addEdge(4,6,true);
	g->addEdge(5,6,true);
	//g->display();
	//->bfs(0);
	//cout<<endl;
	//g->dfs(0);
	cout<<g->connectedComponents();
	return 0;
}
