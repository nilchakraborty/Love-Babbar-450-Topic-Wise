/*// Create a Graph, print it
#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printGraph(vector<int> adj[], int V)
{
    for (int v = 0; v < V; ++v)
    {
        cout << "\n Adjacency list of vertex " << v << "\n head ";
        for (auto x : adj[v])
            cout << "-> " << x;
        cout << "\n";
    }
}
int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    printGraph(adj, V);
    return 0;
}*/
/*// Implement BFS algorithm
// class Solution {
// public:
// 	vector<int>bfsOfGraph(int V, vector<int> adj[]){
// 	    vector<int> bfs; 
// 	    vector<int> vis(V, 0); //we set 0 for false
// 	    queue<int> q; 
// 	    q.push(0); //take first input as 0
// 	    vis[0] = 1; //make sure that this is marked as visited
// 	    while(!q.empty()) {
// 	        int node = q.front();
// 	        q.pop(); 
// 	        bfs.push_back(node); 
	        
// 	        for(auto it : adj[node]) { //we made sure that all the adjacent node is put into the queue
// 	            if(!vis[it]) { //if its not visited that means it marked as 0
// 	                q.push(it); 
// 	                vis[it] = 1; //so push it in queue and marked as visited
// 	            }
// 	        }
// 	    }
	    
// 	    return bfs; 
// 	}
// };
#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    list<int> *adj;

public:
    Graph(int V);
    void addEdge(int v, int w);
    void BFS(int s);
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
void Graph::BFS(int s)
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    list<int> queue;
    visited[s] = true;
    queue.push_back(s);
    list<int>::iterator i;
    while (!queue.empty())
    {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}
int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
    return 0;
}*/
/*// Implement DFS Algo
// class Solution {
//     void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs) {
//         storeDfs.push_back(node); 
//         vis[node] = 1; 
//         for(auto it : adj[node]) {
//             if(!vis[it]) {
//                 dfs(it, vis, adj, storeDfs); 
//             }
//         }
//     }
// public:
// 	vector<int>dfsOfGraph(int V, vector<int> adj[]){
// 	    vector<int> storeDfs; 
// 	    vector<int> vis(V+1, 0); 
//       for(int i = 1;i<=V;i++) {
//         if(!vis[i]) dfs(i, vis, adj, storeDfs); 
//       }
// 	    return storeDfs; 
// 	}
// };
#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
    map<int, bool> visited;
    map<int, list<int>> adj;
    void addEdge(int v, int w);
    void DFS(int v);
};
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
void Graph::DFS(int v)
{
    visited[v] = true;
    cout << v << " ";
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}
int main()
{
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    g.DFS(2);
    return 0;
}*/
/*// Detect Cycle in Directed Graph using BFS/DFS Algo

// class Solution { //code is same as topo sort
// public:
// 	bool isCyclic(int N, vector<int> adj[]) {
//         queue<int> q; 
// 	    vector<int> indegree(N, 0); 
// 	    for(int i = 0;i<N;i++) {
// 	        for(auto it: adj[i]) {
// 	            indegree[it]++; 
// 	        }
// 	    }
	    
// 	    for(int i = 0;i<N;i++) {
// 	        if(indegree[i] == 0) {
// 	            q.push(i); 
// 	        }
// 	    }
// 	    int cnt = 0;
// 	    while(!q.empty()) {
// 	        int node = q.front(); 
// 	        q.pop(); 
// 	        cnt++; 
// 	        for(auto it : adj[node]) {
// 	            indegree[it]--;
// 	            if(indegree[it] == 0) {
// 	                q.push(it); 
// 	            }
// 	        }
// 	    }
// 	    if(cnt == N) return false; //if cnt=N that means their is no cycle
// 	    return true; 
// 	}
// };

// class Solution {
//   private:
//     bool checkCycle(int node, vector < int > adj[], int vis[], int dfsVis[]) {
//       vis[node] = 1;
//       dfsVis[node] = 1;
//       for (auto it: adj[node]) {
//         if (!vis[it]) {
//           if (checkCycle(it, adj, vis, dfsVis)) return true;
//         } else if (dfsVis[it]) {
//           return true;
//         }
//       }
//       dfsVis[node] = 0;
//       return false;
//     }
//   public:
//     bool isCyclic(int N, vector < int > adj[]) {
//       int vis[N], dfsVis[N];
//       memset(vis, 0, sizeof vis);
//       memset(dfsVis, 0, sizeof dfsVis);

//       for (int i = 0; i < N; i++) {
//         if (!vis[i]) {
//           // cout << i << endl; 
//           if (checkCycle(i, adj, vis, dfsVis)) {
//             return true;
//           }
//         }
//       }
//       return false;
//     }
// };

#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    list<int> *adj;
    bool isCyclicUtil(int v, bool visited[], bool *rs);

public:
    Graph(int V);
    void addEdge(int v, int w);
    bool isCyclic();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack)
{
    if (visited[v] == false)
    {
        visited[v] = true;
        recStack[v] = true;
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if (!visited[*i] && isCyclicUtil(*i, visited, recStack))
                return true;
            else if (recStack[*i])
                return true;
        }
    }
    recStack[v] = false;
    return false;
}
bool Graph::isCyclic()
{
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }

    for (int i = 0; i < V; i++)
        if (isCyclicUtil(i, visited, recStack))
            return true;

    return false;
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    if (g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}*/
/*// Detect Cycle in UnDirected Graph using BFS/DFS Algo

// class Solution {
// public:
//     bool checkForCycle(int s, int V, vector<int> adj[], vector<int>& visited)
//     {
//         vector<int> parent(V, -1);      
//         // Create a queue for BFS
//         queue<pair<int,int>> q;
//         visited[s] = true;
//         q.push({s, -1});   
//         while (!q.empty()) {      
//             int node = q.front().first;
//             int par = q.front().second;
//             q.pop();    
//             for (auto it : adj[node]) {
//                 if (!visited[it]) {
//                     visited[it] = true;
//                     q.push({it, node});
//                 }
//                 else if (par != it)
//                     return true;
//             }
//         }
//         return false;
//     }
// public:
// 	bool isCycle(int V, vector<int>adj[]){
// 	    vector<int> vis(V, 0); 
// 	    for(int i = 0;i<V;i++) {
// 	        if(!vis[i]) {
// 	            if(checkForCycle(i, V, adj, vis)) return true; 
// 	        }
// 	    }	    
// 	    return false; 
// 	}
// };

// class Solution {
// public:
//     bool checkForCycle(int node, int parent, vector<int> &vis, vector<int> adj[]) {
//         vis[node] = 1; 
//         for(auto it: adj[node]) {
//             if(!vis[it]) {
//                 if(checkForCycle(it, node, vis, adj)) 
//                     return true; 
//             }
//             else if(it!=parent) 
//                 return true; 
//         }
//         return false; 
//     }
// public:
// 	bool isCycle(int V, vector<int>adj[]){
// 	    vector<int> vis(V+1, 0); 
// 	    for(int i = 0;i<V;i++) {
// 	        if(!vis[i]) {
// 	            if(checkForCycle(i, -1, vis, adj)) return true; 
// 	        }
// 	    }  
// 	    return false; 
// 	}
// };

#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    list<int> *adj;
    bool isCyclicUtil(int v, bool visited[], int parent);

public:
    Graph(int V);
    void addEdge(int v, int w);
    bool isCyclic();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}
bool Graph::isCyclicUtil(int v, bool visited[], int parent)
{
    visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if (!visited[*i])
        {
            if (isCyclicUtil(*i, visited, v))
                return true;
        }
        else if (*i != parent)
            return true;
    }
    return false;
}
bool Graph::isCyclic()
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    for (int u = 0; u < V; u++)
    {
        if (!visited[u])
            if (isCyclicUtil(u, visited, -1))
                return true;
    }
    return false;
}
int main()
{
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isCyclic() ? cout << "Graph contains cycle\n":
    cout << "Graph doesn't contain cycle\n";

    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.isCyclic() ? cout << "Graph contains cycle\n":
    cout << "Graph doesn't contain cycle\n";
    return 0;
}*/
/*// Search in a Maze
Backtracking 1*/
/*// Minimum Step by Knight
#include <bits/stdc++.h>
using namespace std;

struct cell
{
    int x, y;
    int dis;
    cell() {}
    cell(int x, int y, int dis)
        : x(x), y(y), dis(dis)
    {
    }
};
bool isInside(int x, int y, int N)
{
    if (x >= 1 && x <= N && y >= 1 && y <= N)
        return true;
    return false;
}
int minStepToReachTarget(
    int knightPos[], int targetPos[],
    int N)
{
    int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
    int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
    queue<cell> q;
    q.push(cell(knightPos[0], knightPos[1], 0));

    cell t;
    int x, y;
    bool visit[N + 1][N + 1];
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            visit[i][j] = false;
    visit[knightPos[0]][knightPos[1]] = true;
    while (!q.empty())
    {
        t = q.front();
        q.pop();

        if (t.x == targetPos[0] && t.y == targetPos[1])
            return t.dis;

        for (int i = 0; i < 8; i++)
        {
            x = t.x + dx[i];
            y = t.y + dy[i];

            if (isInside(x, y, N) && !visit[x][y])
            {
                visit[x][y] = true;
                q.push(cell(x, y, t.dis + 1));
            }
        }
    }
}
int main()
{
    int N = 30;
    int knightPos[] = {1, 1};
    int targetPos[] = {30, 30};
    cout << minStepToReachTarget(knightPos, targetPos, N);
    return 0;
}*/
/*// flood fill algo
#include <bits/stdc++.h>
using namespace std;
#define M 8
#define N 8
void floodFillUtil(int screen[][N], int x, int y, int prevC, int newC)
{
    if (x < 0 || x >= M || y < 0 || y >= N)
        return;
    if (screen[x][y] != prevC)
        return;
    if (screen[x][y] == newC)
        return;
    screen[x][y] = newC;
    floodFillUtil(screen, x + 1, y, prevC, newC);
    floodFillUtil(screen, x - 1, y, prevC, newC);
    floodFillUtil(screen, x, y + 1, prevC, newC);
    floodFillUtil(screen, x, y - 1, prevC, newC);
}
void floodFill(int screen[][N], int x, int y, int newC)
{
    int prevC = screen[x][y];
    if (prevC == newC)
        return;
    floodFillUtil(screen, x, y, prevC, newC);
}
int main()
{
    int screen[M][N] = {
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 0, 0},
        {1, 0, 0, 1, 1, 0, 1, 1},
        {1, 2, 2, 2, 2, 0, 1, 0},
        {1, 1, 1, 2, 2, 0, 1, 0},
        {1, 1, 1, 2, 2, 2, 2, 0},
        {1, 1, 1, 1, 1, 2, 1, 1},
        {1, 1, 1, 1, 1, 2, 2, 1},
    };
    int x = 4, y = 4, newC = 3;
    floodFill(screen, x, y, newC);

    cout << "Updated screen after call to floodFill: \n";
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            cout << screen[i][j] << " ";
        cout << endl;
    }
}*/
/*// Clone a graph
// class Solution {
// public:
//     unordered_map<Node*, Node*> copies;
//     Node* cloneGraph(Node* node) {
//         if (!node)  return NULL;
//         if (copies.find(node) == copies.end()) {
//             copies[node] = new Node(node -> val, {});
//             for (Node* neighbor : node -> neighbors) {
//                 copies[node] -> neighbors.push_back(cloneGraph(neighbor));
//             }
//         }
//         return copies[node];
//     }
// };
#include <bits/stdc++.h>
using namespace std;
struct GraphNode
{
    int val;
    vector<GraphNode *> neighbours;
};

GraphNode *cloneGraph(GraphNode *src)
{
    map<GraphNode *, GraphNode *> m;
    queue<GraphNode *> q;

    q.push(src);
    GraphNode *node;

    node = new GraphNode();
    node->val = src->val;

    m[src] = node;
    while (!q.empty())
    {
        GraphNode *u = q.front();
        q.pop();
        vector<GraphNode *> v = u->neighbours;
        int n = v.size();
        for (int i = 0; i < n; i++)
        {
            if (m[v[i]] == NULL)
            {
                node = new GraphNode();
                node->val = v[i]->val;
                m[v[i]] = node;
                q.push(v[i]);
            }
            m[u]->neighbours.push_back(m[v[i]]);
        }
    }
    return m[src];
}
GraphNode *buildGraph()
{
    GraphNode *node1 = new GraphNode();
    node1->val = 1;
    GraphNode *node2 = new GraphNode();
    node2->val = 2;
    GraphNode *node3 = new GraphNode();
    node3->val = 3;
    GraphNode *node4 = new GraphNode();
    node4->val = 4;
    vector<GraphNode *> v;
    v.push_back(node2);
    v.push_back(node4);
    node1->neighbours = v;
    v.clear();
    v.push_back(node1);
    v.push_back(node3);
    node2->neighbours = v;
    v.clear();
    v.push_back(node2);
    v.push_back(node4);
    node3->neighbours = v;
    v.clear();
    v.push_back(node3);
    v.push_back(node1);
    node4->neighbours = v;
    return node1;
}
void bfs(GraphNode *src)
{
    map<GraphNode *, bool> visit;
    queue<GraphNode *> q;
    q.push(src);
    visit[src] = true;
    while (!q.empty())
    {
        GraphNode *u = q.front();
        cout << "Value of Node " << u->val << "\n";
        cout << "Address of Node " << u << "\n";
        q.pop();
        vector<GraphNode *> v = u->neighbours;
        int n = v.size();
        for (int i = 0; i < n; i++)
        {
            if (!visit[v[i]])
            {
                visit[v[i]] = true;
                q.push(v[i]);
            }
        }
    }
    cout << endl;
}
int main()
{
    GraphNode *src = buildGraph();
    cout << "BFS Traversal before cloning\n";
    bfs(src);
    GraphNode *newsrc = cloneGraph(src);
    cout << "BFS Traversal after cloning\n";
    bfs(newsrc);
    return 0;
}*/
/*// Making wired Connections
#include <bits/stdc++.h>
using namespace std;
void DFS(unordered_map<int, vector<int>> &adj,
         int node, vector<bool> &visited)
{
    if (visited[node])
        return;
    visited[node] = true;
    for (auto x : adj[node])
    {
        if (visited[x] == false)
            DFS(adj, x, visited);
    }
}
int makeConnectedUtil(int N,
                      int connections[][2],
                      int M)
{
    vector<bool> visited(N, false);
    unordered_map<int, vector<int>> adj;
    int edges = 0;
    for (int i = 0; i < M; ++i)
    {
        adj[connections[i][0]].push_back(
            connections[i][1]);
        adj[connections[i][1]].push_back(
            connections[i][0]);
        edges += 1;
    }
    int components = 0;

    for (int i = 0; i < N; ++i)
    {
        if (visited[i] == false)
        {
            components += 1;
            DFS(adj, i, visited);
        }
    }
    if (edges < N - 1)
        return -1;
    int redundant = edges - ((N - 1) - (components - 1));
    if (redundant >= (components - 1))
        return components - 1;

    return -1;
}
void makeConnected(int N, int connections[][2], int M)
{
    int minOps = makeConnectedUtil(
        N, connections, M);
    cout << minOps;
}

int main()
{
    int N = 4;
    int connections[][2] = {
        {0, 1}, {0, 2}, {1, 2}};
    int M = sizeof(connections) / sizeof(connections[0]);
    makeConnected(N, connections, M);
    return 0;
}*/
/*// word Ladder
#include <bits/stdc++.h>
using namespace std;
int shortestChainLen(string start, string target, set<string> &D)
{
    if (start == target)
        return 0;
    if (D.find(target) == D.end())
        return 0;
    int level = 0, wordlength = start.size();
    queue<string> Q;
    Q.push(start);
    while (!Q.empty())
    {
        ++level;
        int sizeofQ = Q.size();
        for (int i = 0; i < sizeofQ; ++i)
        {
            string word = Q.front();
            Q.pop();
            for (int pos = 0; pos < wordlength; ++pos)
            {
                char orig_char = word[pos];
                for (char c = 'a'; c <= 'z'; ++c)
                {
                    word[pos] = c;
                    if (word == target)
                        return level + 1;
                    if (D.find(word) == D.end())
                        continue;
                    D.erase(word);
                    Q.push(word);
                }
                word[pos] = orig_char;
            }
        }
    }
    return 0;
}

int main()
{
    set<string> D;
    D.insert("poon");
    D.insert("plee");
    D.insert("same");
    D.insert("poie");
    D.insert("plie");
    D.insert("poin");
    D.insert("plea");
    string start = "toon";
    string target = "plea";
    cout << "Length of shortest chain is: "
         << shortestChainLen(start, target, D);
    return 0;
}*/
/*// Dijkstra algo
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,source;
    cin>>n>>m;
    vector<pair<int,int>> g[n+1];
    
    int a,b,wt;
    for(int i=0;i<m;i++){
        cin>>a>>b>>wt;
        g[a].push_back(make_pair(b,wt));
        g[b].push_back(make_pair(a,wt));
    }
    cin>>source;
    
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
    vector<int> distTo(n+1,INT_MAX);
    
    distTo[source]=0;
    pq.push(make_pair(0,source));

    while(!pq.empty()){
        int dist=pq.top().first;
        int prev=pq.top().second;
        pq.pop();

        vector<pair<int,int>>::iterator it;
        for(it=g[prev].begin();it!= g[prev].end();it++){
            int next=it->first;
            int nextDist =it->second;
            if( distTo[next] > distTo[prev]+nextDist){
                distTo[next] = distTo[prev]+nextDist;
                pq.push(make_pair(distTo[next],next));
            }
        }
    }
    cout << "The distances from source, " << source << ", are : \n";
	for(int i = 1 ; i<=n ; i++)	cout << distTo[i] << " ";
	cout << "\n";
	
	return 0;
}*/
/*// Implement Topological Sort

// class Solution {
// public:
// 	vector<int> topo(int N, vector<int> adj[]) {
//         queue<int> q; 
// 	    vector<int> indegree(N, 0); 
// 	    for(int i = 0;i<N;i++) {
// 	        for(auto it: adj[i]) {
// 	            indegree[it]++; 
// 	        }
// 	    }
// 	    for(int i = 0;i<N;i++) {
// 	        if(indegree[i] == 0) {
// 	            q.push(i); 
// 	        }
// 	    }
// 	    vector<int> topo
// 	    while(!q.empty()) {
// 	        int node = q.front(); 
// 	        q.pop(); 
// 	        topo.push_back(node)
// 	        for(auto it : adj[node]) {
// 	            indegree[it]--;
// 	            if(indegree[it] == 0) {
// 	                q.push(it); 
// 	            }
// 	        }
// 	    }
// 	    return topo;
// 	}
// };

// class Solution{
//     void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<int> adj[]) {
//         vis[node] = 1; 
//         for(auto it : adj[node]) {
//             if(!vis[it]) {
//                 findTopoSort(it, vis, st, adj); 
//             }
//         }
//         st.push(node); 
//     }
// 	public:
// 	vector<int> topoSort(int N, vector<int> adj[]) {
// 	    stack<int> st; 
// 	    vector<int> vis(N, 0); 
// 	    for(int i = 0;i<N;i++) {
// 	        if(vis[i] == 0) {
// 	            findTopoSort(i, vis, st, adj); 
// 	        }
// 	    }
// 	    vector<int> topo;
// 	    while(!st.empty()) {
// 	        topo.push_back(st.top()); 
// 	        st.pop(); 
// 	    }
// 	    return topo; 
// 	}
// };

#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    list<int> *adj;
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);

public:
    Graph(int V);
    void addEdge(int v, int w);
    void topologicalSort();
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack)
{
    visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);

    Stack.push(v);
}
void Graph::topologicalSort()
{
    stack<int> Stack;
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);

    while (Stack.empty() == false)
    {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}
int main()
{
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Following is a Topological Sort of the given graph \n";
    g.topologicalSort();
    return 0;
}*/
/*// Minimum time taken by each job to be completed given by a Directed Acyclic Graph
#include <bits/stdc++.h>
using namespace std;
#define maxN 100000
vector<int> graph[maxN];
int indegree[maxN];
int job[maxN];
void addEdge(int u, int v)
{
    graph[u].push_back(v);
    indegree[v]++;
}
void printOrder(int n, int m)
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            job[i] = 1;
        }
    }
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int adj : graph[cur])
        {
            indegree[adj]--;
            if (indegree[adj] == 0)
            {
                job[adj] = job[cur] + 1;
                q.push(adj);
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << job[i] << " ";
    cout << "\n";
}
int main()
{
    int n, m;
    n = 10;
    m = 13;

    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(1, 5);
    addEdge(2, 3);
    addEdge(2, 8);
    addEdge(2, 9);
    addEdge(3, 6);
    addEdge(4, 6);
    addEdge(4, 8);
    addEdge(5, 8);
    addEdge(6, 7);
    addEdge(7, 8);
    addEdge(8, 10);

    printOrder(n, m);
    return 0;
}*/
/*// Find whether it is possible to finish all tasks or not from given dependencies
#include <bits/stdc++.h>
using namespace std;
vector<unordered_set<int>> make_graph(int numTasks,
                                      vector<pair<int, int>> &prerequisites)
{
    vector<unordered_set<int>> graph(numTasks);
    for (auto pre : prerequisites)
        graph[pre.second].insert(pre.first);
    return graph;
}
bool dfs_cycle(vector<unordered_set<int>> &graph, int node,
               vector<bool> &onpath, vector<bool> &visited)
{
    if (visited[node])
        return false;
    onpath[node] = visited[node] = true;
    for (int neigh : graph[node])
        if (onpath[neigh] || dfs_cycle(graph, neigh, onpath, visited))
            return true;
    return onpath[node] = false;
}
bool canFinish(int numTasks, vector<pair<int, int>> &prerequisites)
{
    vector<unordered_set<int>> graph = make_graph(numTasks, prerequisites);
    vector<bool> onpath(numTasks, false), visited(numTasks, false);
    for (int i = 0; i < numTasks; i++)
        if (!visited[i] && dfs_cycle(graph, i, onpath, visited))
            return false;
    return true;
}
int main()
{
    int numTasks = 4;

    vector<pair<int, int>> prerequisites;

    prerequisites.push_back(make_pair(1, 0));
    prerequisites.push_back(make_pair(2, 1));
    prerequisites.push_back(make_pair(3, 2));
    if (canFinish(numTasks, prerequisites))
    {
        cout << "Possible to finish all tasks";
    }
    else
    {
        cout << "Impossible to finish all tasks";
    }
    return 0;
}*/
/*// Find the no. of Isalnds
#include <bits/stdc++.h>
using namespace std;
void DFS(vector<vector<int>> &M, int i, int j, int ROW, int COL)
{
    if (i < 0 || j < 0 || i > (ROW - 1) || j > (COL - 1) || M[i][j] != 1)
        return;
    if (M[i][j] == 1)
    {
        M[i][j] = 0;
        DFS(M, i + 1, j, ROW, COL);
        DFS(M, i - 1, j, ROW, COL);
        DFS(M, i, j + 1, ROW, COL);
        DFS(M, i, j - 1, ROW, COL);
        DFS(M, i + 1, j + 1, ROW, COL);
        DFS(M, i - 1, j - 1, ROW, COL);
        DFS(M, i + 1, j - 1, ROW, COL);
        DFS(M, i - 1, j + 1, ROW, COL);
    }
}
int countIslands(vector<vector<int>> &M)
{
    int ROW = M.size();
    int COL = M[0].size();
    int count = 0;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (M[i][j] == 1)
            {
                M[i][j] = 0;
                count++;
                DFS(M, i + 1, j, ROW, COL);
                DFS(M, i - 1, j, ROW, COL);
                DFS(M, i, j + 1, ROW, COL);
                DFS(M, i, j - 1, ROW, COL);
                DFS(M, i + 1, j + 1, ROW, COL);
                DFS(M, i - 1, j - 1, ROW, COL);
                DFS(M, i + 1, j - 1, ROW, COL);
                DFS(M, i - 1, j + 1, ROW, COL);
            }
        }
    }
    return count;
}
int main()
{
    vector<vector<int>> M = {{1, 1, 0, 0, 0},
                             {0, 1, 0, 0, 1},
                             {1, 0, 0, 1, 1},
                             {0, 0, 0, 0, 0},
                             {1, 0, 1, 0, 1}};

    cout << "Number of islands is: " << countIslands(M);
    return 0;
}*/
/*// Given a sorted Dictionary of an Alien Language, find order of characters
#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    list<int> *adj;
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);

public:
    Graph(int V);
    void addEdge(int v, int w);
    void topologicalSort();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack)
{
    visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);
    Stack.push(v);
}
void Graph::topologicalSort()
{
    stack<int> Stack;
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);

    while (Stack.empty() == false)
    {
        cout << (char)('a' + Stack.top()) << " ";
        Stack.pop();
    }
}

int min(int x, int y)
{
    return (x < y) ? x : y;
}

void printOrder(string words[], int n, int alpha)
{
    Graph g(alpha);
    for (int i = 0; i < n - 1; i++)
    {
        string word1 = words[i], word2 = words[i + 1];
        for (int j = 0; j < min(word1.length(), word2.length()); j++)
        {
            if (word1[j] != word2[j])
            {
                g.addEdge(word1[j] - 'a', word2[j] - 'a');
                break;
            }
        }
    }
    g.topologicalSort();
}
int main()
{
    string words[] = {"caa", "aaa", "aab"};
    printOrder(words, 3, 3);
    return 0;
}*/
/*// Implement Kruksal’s Algorithm
#include<bits/stdc++.h>
using namespace std;
struct node {
    int u;
    int v;
    int wt; 
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(node a, node b) {
    return a.wt < b.wt; 
}

int findPar(int u, vector<int> &parent) {
    if(u == parent[u]) return u; 
    return parent[u] = findPar(parent[u], parent); 
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findPar(u, parent);
    v = findPar(v, parent);
    if(rank[u] < rank[v]) {
    	parent[u] = v;
    }
    else if(rank[v] < rank[u]) {
    	parent[v] = u; 
    }
    else {
    	parent[v] = u;
    	rank[u]++; 
    }
}
int main(){
	int N=5,m=6;
	vector<node> edges; 
	edges.push_back(node(0,1,2));
	edges.push_back(node(0,3,6));
	edges.push_back(node(1,0,2));
	edges.push_back(node(1,2,3));
	edges.push_back(node(1,3,8));
	edges.push_back(node(1,4,5));
	edges.push_back(node(2,1,3));
	edges.push_back(node(2,4,7));
	edges.push_back(node(3,0,6));
	edges.push_back(node(3,1,8));
	edges.push_back(node(4,1,5));
	edges.push_back(node(4,2,7));
	sort(edges.begin(), edges.end(), comp); 
	
	vector<int> parent(N);
	for(int i = 0;i<N;i++) 
	    parent[i] = i; 
	vector<int> rank(N, 0); 
	
	int cost = 0;
	vector<pair<int,int>> mst; 
	for(auto it : edges) {
	    if(findPar(it.v, parent) != findPar(it.u, parent)) {
	        cost += it.wt; 
	        mst.push_back({it.u, it.v}); 
	        unionn(it.u, it.v, parent, rank); 
	    }
	}
	cout << cost << endl;
	for(auto it : mst) cout << it.first << " - " << it.second << endl; 
	return 0;
}*/
/*// Implement Prim’s Algorithm
#include<bits/stdc++.h>
using namespace std;

int main(){
	int N,m;
	cin >> N >> m;
	vector<pair<int,int> > adj[N]; 

	int a,b,wt;
	for(int i = 0; i<m ; i++){
		cin >> a >> b >> wt;
		adj[a].push_back(make_pair(b,wt));
		adj[b].push_back(make_pair(a,wt));
	}	
	
	int parent[N]; 
      
    int key[N]; 
      
    bool mstSet[N]; 
  
    for (int i = 0; i < N; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
    
    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;

    key[0] = 0; 
    parent[0] = -1; 
    pq.push({0, 0});
    
    while(!pq.empty())
    { 
        int u = pq.top().second; 
        pq.pop(); 
        
        mstSet[u] = true; 
        
        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) {
                parent[v] = u;
                pq.push({key[v], v});    
		        key[v] = weight; 
            }
        }
            
    } 
    
    for (int i = 1; i < N; i++) 
        cout << parent[i] << " - " << i <<" \n"; 
	return 0;
}*/
// Total no. of Spanning tree in a graph
/*// Implement Bellman Ford Algorithm
#include <bits/stdc++.h>
using namespace std;
struct node {
    int u;
    int v;
    int wt; 
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

int main(){
    int N,m;
    cin >> N >> m;
    vector<node> edges; 
    for(int i = 0;i<m;i++) {
        int u, v, wt;
        cin >> u >> v >> wt; 
        edges.push_back(node(u, v, wt)); 
    }

    int src;
    cin >> src; 


    int inf = 10000000; 
    vector<int> dist(N, inf); 

    dist[src] = 0; 

    for(int i = 1;i<=N-1;i++) {
        for(auto it: edges) {
            if(dist[it.u] + it.wt < dist[it.v]) {
                dist[it.v] = dist[it.u] + it.wt; 
            }
        }
    }

    int fl = 0; 
    for(auto it: edges) {
        if(dist[it.u] + it.wt < dist[it.v]) {
            cout << "Negative Cycle"; 
            fl = 1; 
            break; 
        }
    }

    if(!fl) { //if fl counter not set then we can say shortest distance
        for(int i = 0;i<N;i++) {
            cout << i << " " << dist[i] << endl;
        }
    }

    return 0;
}*/
/*// Implement Floyd warshallAlgorithm
#include <bits/stdc++.h>
using namespace std;
#define V 4
#define INF 99999
void printSolution(int dist[][V]);
void floydWarshall(int graph[][V])
{
    int dist[V][V], i, j, k;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INF && dist[i][k] != INF))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    printSolution(dist);
}
void printSolution(int dist[][V])
{
    cout << "The following matrix shows the shortest "
            "distances"
            " between every pair of vertices \n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                cout << "INF"
                     << "	 ";
            else
                cout << dist[i][j] << "	 ";
        }
        cout << endl;
    }
}
int main()
{
    int graph[V][V] = {{0, 5, INF, 10},
                       {INF, 0, 3, INF},
                       {INF, INF, 0, 1},
                       {INF, INF, INF, 0}};

    floydWarshall(graph);
    return 0;
}*/
// Travelling Salesman Problem
// Graph ColouringProblem
/*// Snake and Ladders Problem
#include <iostream>
#include <queue>
using namespace std;
struct queueEntry
{
    int v;
    int dist;
};
int getMinDiceThrows(int move[], int N)
{
    bool *visited = new bool[N];
    for (int i = 0; i < N; i++)
        visited[i] = false;

    queue<queueEntry> q;

    visited[0] = true;
    queueEntry s = {0, 0};
    q.push(s);

    queueEntry qe;
    while (!q.empty())
    {
        qe = q.front();
        int v = qe.v;
        if (v == N - 1)
            break;

        q.pop();
        for (int j = v + 1; j <= (v + 6) && j < N; ++j)
        {
            if (!visited[j])
            {
                queueEntry a;
                a.dist = (qe.dist + 1);
                visited[j] = true;

                if (move[j] != -1)
                    a.v = move[j];
                else
                    a.v = j;
                q.push(a);
            }
        }
    }
    return qe.dist;
}

int main()
{
    int N = 30;
    int moves[N];
    for (int i = 0; i < N; i++)
        moves[i] = -1;

    // Ladders
    moves[2] = 21;
    moves[4] = 7;
    moves[10] = 25;
    moves[19] = 28;

    // Snakes
    moves[26] = 0;
    moves[20] = 8;
    moves[16] = 3;
    moves[18] = 6;

    cout << "Min Dice throws required is " << getMinDiceThrows(moves, N);
    return 0;
}*/
/*// Find bridge in a graph
#include <bits/stdc++.h>
#define NIL -1
using namespace std;
class Graph
{
    int V;
    list<int> *adj;
    void bridgeUtil(int v, bool visited[], int disc[], int low[],
                    int parent[]);

public:
    Graph(int V);
    void addEdge(int v, int w);
    void bridge();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}
void Graph::bridgeUtil(int u, bool visited[], int disc[],
                       int low[], int parent[])
{

    static int time = 0;
    visited[u] = true;
    disc[u] = low[u] = ++time;
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        int v = *i;
        if (!visited[v])
        {
            parent[v] = u;
            bridgeUtil(v, visited, disc, low, parent);
            low[u] = min(low[u], low[v]);
            if (low[v] > disc[u])
                cout << u << " " << v << endl;
        }
        else if (v != parent[u])
            low[u] = min(low[u], disc[v]);
    }
}
void Graph::bridge()
{
    bool *visited = new bool[V];
    int *disc = new int[V];
    int *low = new int[V];
    int *parent = new int[V];

    for (int i = 0; i < V; i++)
    {
        parent[i] = NIL;
        visited[i] = false;
    }
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            bridgeUtil(i, visited, disc, low, parent);
}

int main()
{
    cout << "\nBridges in first graph \n";
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.bridge();

    cout << "\nBridges in second graph \n";
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.bridge();

    cout << "\nBridges in third graph \n";
    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);
    g3.bridge();

    return 0;
}*/
/*// Count Strongly connected Components(Kosaraju Algo)
#include <bits/stdc++.h>
using namespace std;
void dfs(int node, stack<int> &st, vector<int> &vis, vector<int> adj[]) {
    vis[node] = 1; 
    for(auto it: adj[node]) {
        if(!vis[it]) {
            dfs(it, st, vis, adj); 
        }
    }
    
    st.push(node); 
}
void revDfs(int node, vector<int> &vis, vector<int> transpose[]) {
    cout << node << " "; 
    vis[node] = 1; 
    for(auto it: transpose[node]) {
        if(!vis[it]) {
            revDfs(it, vis, transpose); 
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m; 
	vector<int> adj[n]; 
	for(int i = 0;i<m;i++) {
	    int u, v;
	    cin >> u >> v; 
	    adj[u].push_back(v);
	}
	
	stack<int> st;
	vector<int> vis(n, 0); 
	for(int i = 0;i<n;i++) {
	    if(!vis[i]) {
	        dfs(i, st, vis, adj); 
	    }
	} 
	
	vector<int> transpose[n]; 
	
	for(int i = 0;i<n;i++) {
	    vis[i] = 0; 
	    for(auto it: adj[i]) {
	        transpose[it].push_back(i); 
	    }
	}
		
	while(!st.empty()) {
	    int node = st.top();
	    st.pop(); 
	    if(!vis[node]) {
	        cout << "SCC: "; 
	        revDfs(node, vis, transpose); 
	        cout << endl; 
	    }
	}
		
	return 0;
}*/
/*// Check whether a graph is Bipartite or Not

// bool bipartiteBfs(int src, vector<int> adj[], int color[]) {
//     queue<int>q;
//     q.push(src); 
//     color[src] = 1; 
//     while(!q.empty()) {
//         int node = q.front(); 
//         q.pop();
        
//         for(auto it : adj[node]) {
//             if(color[it] == -1) {
//                 color[it] = 1 - color[node]; 
//                 q.push(it); 
//             } else if(color[it] == color[node]) {
//                 return false; 
//             }
//         }
//     }
//     return true; 
// }
// bool checkBipartite(vector<int> adj[], int n) {
//     int color[n];
//     memset(color, -1, sizeof color); 
//     for(int i = 0;i<n;i++) {
//         if(color[i] == -1) {
//             if(!bipartiteBfs(i, adj, color)) {
//                 return false;
//             }
//         }
//     }
//     return true; 
// }

// bool bipartiteDfs(int node, vector<int> adj[], int color[]) {
//     for(auto it : adj[node]) {
//         if(color[it] == -1) {
//             color[it] = 1 - color[node];
//             if(!bipartiteDfs(it, adj, color)) {
//                 return false; 
//             }
//         } else if(color[it] == color[node]) return false; 
//     }
//     return true; 
// }
// bool checkBipartite(vector<int> adj[], int n) {
//     int color[n];
//     memset(color, -1, sizeof color); 
//     for(int i = 0;i<n;i++) {
//         if(color[i] == -1) {
//             color[i] = 1;
//             if(!bipartiteDfs(i, adj, color)) {
//                 return false;
//             }
//         } 
//     }
//     return true; 
// }

#include <iostream>
using namespace std;
#define V 4
bool colorGraph(int G[][V], int color[], int pos, int c)
{

    if (color[pos] != -1 && color[pos] != c)
        return false;

    color[pos] = c;
    bool ans = true;
    for (int i = 0; i < V; i++)
    {
        if (G[pos][i])
        {
            if (color[i] == -1)
                ans &= colorGraph(G, color, i, 1 - c);

            if (color[i] != -1 && color[i] != 1 - c)
                return false;
        }
        if (!ans)
            return false;
    }
    return true;
}
bool isBipartite(int G[][V])
{
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = -1;

    int pos = 0;
    return colorGraph(G, color, pos, 1);
}

int main()
{
    int G[][V] = {{0, 1, 0, 1},
                  {1, 0, 1, 0},
                  {0, 1, 0, 1},
                  {1, 0, 1, 0}};
    isBipartite(G) ? cout << "Yes" : cout << "No";
    return 0;
}*/
/*// Detect Negative cycle in a graph
//same as Bellman Ford
#include <bits/stdc++.h>
using namespace std;
struct Edge
{
    int src, dest, weight;
};
struct Graph
{
    int V, E;
    struct Edge *edge;
};
struct Graph *createGraph(int V, int E)
{
    struct Graph *graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[graph->E];
    return graph;
}
bool isNegCycleBellmanFord(struct Graph *graph,
                           int src)
{
    int V = graph->V;
    int E = graph->E;
    int dist[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    for (int i = 0; i < E; i++)
    {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            return true;
    }

    return false;
}
int main()
{
    int V = 5;
    int E = 8;
    struct Graph *graph = createGraph(V, E);

    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = -1;

    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 4;

    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 3;

    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 2;

    graph->edge[4].src = 1;
    graph->edge[4].dest = 4;
    graph->edge[4].weight = 2;

    graph->edge[5].src = 3;
    graph->edge[5].dest = 2;
    graph->edge[5].weight = 5;

    graph->edge[6].src = 3;
    graph->edge[6].dest = 1;
    graph->edge[6].weight = 1;

    graph->edge[7].src = 4;
    graph->edge[7].dest = 3;
    graph->edge[7].weight = -3;

    if (isNegCycleBellmanFord(graph, 0))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}*/
/*// Longest path in a Directed Acyclic Graph
#include <bits/stdc++.h>
#define NINF INT_MIN
using namespace std;
class AdjListNode
{
    int v;
    int weight;

public:
    AdjListNode(int _v, int _w)
    {
        v = _v;
        weight = _w;
    }
    int getV() { return v; }
    int getWeight() { return weight; }
};

class Graph
{
    int V;
    list<AdjListNode> *adj;
    void topologicalSortUtil(int v, bool visited[],
                             stack<int> &Stack);

public:
    Graph(int V);
    ~Graph();
    void addEdge(int u, int v, int weight);
    void longestPath(int s);
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<AdjListNode>[V];
}
Graph::~Graph()
{
    delete[] adj;
}
void Graph::addEdge(int u, int v, int weight)
{
    AdjListNode node(v, weight);
    adj[u].push_back(node);
}

void Graph::topologicalSortUtil(int v, bool visited[],
                                stack<int> &Stack)
{
    visited[v] = true;
    list<AdjListNode>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        AdjListNode node = *i;
        if (!visited[node.getV()])
            topologicalSortUtil(node.getV(), visited, Stack);
    }
    Stack.push(v);
}
void Graph::longestPath(int s)
{
    stack<int> Stack;
    int dist[V];
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);
    for (int i = 0; i < V; i++)
        dist[i] = NINF;
    dist[s] = 0;
    while (Stack.empty() == false)
    {
        int u = Stack.top();
        Stack.pop();
        list<AdjListNode>::iterator i;
        if (dist[u] != NINF)
        {
            for (i = adj[u].begin(); i != adj[u].end(); ++i)
            {

                if (dist[i->getV()] < dist[u] + i->getWeight())
                    dist[i->getV()] = dist[u] + i->getWeight();
            }
        }
    }
    for (int i = 0; i < V; i++)
        (dist[i] == NINF) ? cout << "INF " : cout << dist[i] << " ";

    delete[] visited;
}
int main()
{
    Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 5, 1);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    int s = 1;
    cout << "Following are longest distances from "
            "source vertex "
         << s << " \n";
    g.longestPath(s);
    return 0;
}*/
// Journey to the Moon
// Cheapest Flights Within K Stops
// Oliver and the Game
/*// Water Jug problem using BFS
#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
using namespace std;
void BFS(int a, int b, int target)
{
    map<pii, int> m;
    bool isSolvable = false;
    vector<pii> path;

    queue<pii> q;
    q.push({0, 0});

    while (!q.empty())
    {

        pii u = q.front();

        q.pop();
        if (m[{u.first, u.second}] == 1)
            continue;
        if ((u.first > a || u.second > b ||
             u.first < 0 || u.second < 0))
            continue;
        path.push_back({u.first, u.second});
        m[{u.first, u.second}] = 1;
        if (u.first == target || u.second == target)
        {
            isSolvable = true;
            if (u.first == target)
            {
                if (u.second != 0)
                    path.push_back({u.first, 0});
            }
            else
            {
                if (u.first != 0)

                    path.push_back({0, u.second});
            }
            int sz = path.size();
            for (int i = 0; i < sz; i++)
                cout << "(" << path[i].first
                     << ", " << path[i].second << ")";
            break;
        }
        q.push({u.first, b});
        q.push({a, u.second});

        for (int ap = 0; ap <= max(a, b); ap++)
        {
            int c = u.first + ap;
            int d = u.second - ap;
            if (c == a || (d == 0 && d >= 0))
                q.push({c, d});
            c = u.first - ap;
            d = u.second + ap;
            if ((c == 0 && c >= 0) || d == b)
                q.push({c, d});
        }

        q.push({a, 0});
        q.push({0, b});
    }
    if (!isSolvable)
        cout << "No solution";
}
int main()
{
    int Jug1 = 4, Jug2 = 3, target = 2;
    cout << "Path from initial state "
            "to solution state : ";
    BFS(Jug1, Jug2, target);
    return 0;
}*/
/*// Find if there is a path of more thank length from a source
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> iPair;
class Graph
{
    int V;
    list<pair<int, int>> *adj;
    bool pathMoreThanKUtil(int src, int k, vector<bool> &path);

public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    bool pathMoreThanK(int src, int k);
};
bool Graph::pathMoreThanK(int src, int k)
{
    vector<bool> path(V, false);
    path[src] = 1;
    return pathMoreThanKUtil(src, k, path);
}
bool Graph::pathMoreThanKUtil(int src, int k, vector<bool> &path)
{
    if (k <= 0)
        return true;
    list<iPair>::iterator i;
    for (i = adj[src].begin(); i != adj[src].end(); ++i)
    {
        int v = (*i).first;
        int w = (*i).second;
        if (path[v] == true)
            continue;
        if (w >= k)
            return true;
        path[v] = true;
        if (pathMoreThanKUtil(v, k - w, path))
            return true;
        path[v] = false;
    }
    return false;
}
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<iPair>[V];
}
void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}
int main()
{
    int V = 9;
    Graph g(V);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    int src = 0;
    int k = 62;
    g.pathMoreThanK(src, k) ? cout << "Yes\n" : cout << "No\n";

    k = 60;
    g.pathMoreThanK(src, k) ? cout << "Yes\n" : cout << "No\n";
    return 0;
}*/
/*// M-ColouringProblem
#include <iostream>
using namespace std;
#define V 4

void printSolution(int color[]);
bool isSafe(int v, bool graph[V][V],
            int color[], int c)
{
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;

    return true;
}
bool graphColoringUtil(bool graph[V][V], int m,
                       int color[], int v)
{
    if (v == V)
        return true;
    for (int c = 1; c <= m; c++)
    {
        if (isSafe(v, graph, color, c))
        {
            color[v] = c;
            if (graphColoringUtil(
                    graph, m, color, v + 1) == true)
                return true;
            color[v] = 0;
        }
    }
    return false;
}
bool graphColoring(bool graph[V][V], int m)
{
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;
    if (graphColoringUtil(graph, m, color, 0) == false)
    {
        cout << "Solution does not exist";
        return false;
    }
    printSolution(color);
    return true;
}
void printSolution(int color[])
{
    cout << "Solution Exists:"
         << " Following are the assigned colors"
         << "\n";
    for (int i = 0; i < V; i++)
        cout << " " << color[i] << " ";

    cout << "\n";
}
int main()
{
    bool graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };

    int m = 3;
    graphColoring(graph, m);
    return 0;
}*/
/*// Minimum edges to reverse o make path from source to destination
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
class Graph
{
    int V;
    list< pair > *adj;

public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    vector shortestPath(int s);
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<pair>[V];
}
void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
}
vector Graph::shortestPath(int src)
{
    set<pair> setds;
    vector dist(V, INF);
    setds.insert(make_pair(0, src));
    dist[src] = 0;
    while (!setds.empty())
    {
        pair tmp = *(setds.begin());
        setds.erase(setds.begin());
        int u = tmp.second;

        list<pair>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;

            if (dist[v] > dist[u] + weight)
            {
                if (dist[v] != INF)
                    setds.erase(setds.find(make_pair(dist[v], v)));
                dist[v] = dist[u] + weight;
                setds.insert(make_pair(dist[v], v));
            }
        }
    }
    return dist;
}
Graph modelGraphWithEdgeWeight(int edge[][2], int E, int V)
{
    Graph g(V);
    for (int i = 0; i < E; i++)
    {
        g.addEdge(edge[i][0], edge[i][1], 0);
        g.addEdge(edge[i][1], edge[i][0], 1);
    }
    return g;
}
int getMinEdgeReversal(int edge[][2], int E, int V,
                       int src, int dest)
{
    Graph g = modelGraphWithEdgeWeight(edge, E, V);
    vector dist = g.shortestPath(src);
    if (dist[dest] == INF)
        return -1;
    else
        return dist[dest];
}
int main()
{
    int V = 7;
    int edge[][2] = {{0, 1}, {2, 1}, {2, 3}, {5, 1}, {4, 5}, {6, 4}, {6, 3}};
    int E = sizeof(edge) / sizeof(edge[0]);

    int minEdgeToReverse =
        getMinEdgeReversal(edge, E, V, 0, 6);
    if (minEdgeToReverse != -1)
        cout << minEdgeToReverse << endl;
    else
        cout << "Not possible" << endl;
    return 0;
}*/
/*// Paths to travel each nodes using each edge(Seven Bridges)
#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    list<int> *adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }
    ~Graph()
    {
        delete[] adj;
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void rmvEdge(int u, int v);
    void printEulerTour();
    void printEulerUtil(int s);
    int DFSCount(int v, bool visited[]);
    bool isValidNextEdge(int u, int v);
};
void Graph::printEulerTour()
{
    int u = 0;

    for (int i = 0; i < V; i++)
        if (adj[i].size() & 1)
        {
            u = i;
            break;
        }
    // Print tour starting from oddv
    printEulerUtil(u);
    cout << endl;
}
void Graph::printEulerUtil(int u)
{
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        int v = *i;
        if (v != -1 && isValidNextEdge(u, v))
        {
            cout << u << "-" << v << " ";
            rmvEdge(u, v);
            printEulerUtil(v);
        }
    }
}
bool Graph::isValidNextEdge(int u, int v)
{
    int count = 0;
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
        if (*i != -1)
            count++;
    if (count == 1)
        return true;
    bool visited[V];
    memset(visited, false, V);
    int count1 = DFSCount(u, visited);
    rmvEdge(u, v);
    memset(visited, false, V);
    int count2 = DFSCount(u, visited);
    addEdge(u, v);
    return (count1 > count2) ? false : true;
}
void Graph::rmvEdge(int u, int v)
{
    list<int>::iterator iv = find(adj[u].begin(),
                                  adj[u].end(), v);
    *iv = -1;
    list<int>::iterator iu = find(adj[v].begin(),
                                  adj[v].end(), u);
    *iu = -1;
}
int Graph::DFSCount(int v, bool visited[])
{
    visited[v] = true;
    int count = 1;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (*i != -1 && !visited[*i])
            count += DFSCount(*i, visited);

    return count;
}
int main()
{
    Graph g1(4);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);
    g1.printEulerTour();

    Graph g3(4);
    g3.addEdge(0, 1);
    g3.addEdge(1, 0);
    g3.addEdge(0, 2);
    g3.addEdge(2, 0);
    g3.addEdge(2, 3);
    g3.addEdge(3, 1);

    g3.printEulerTour();
    return 0;
}*/
/*// Vertex Cover Problem
#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    list<int> *adj;

public:
    Graph(int V);
    void addEdge(int v, int w);
    void printVertexCover();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}
void Graph::printVertexCover()
{
    bool visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    list<int>::iterator i;
    for (int u = 0; u < V; u++)
    {
        if (visited[u] == false)
        {
            for (i = adj[u].begin(); i != adj[u].end(); ++i)
            {
                int v = *i;
                if (visited[v] == false)
                {
                    visited[v] = true;
                    visited[u] = true;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < V; i++)
    {
        if (visited[i])
            cout << i << " ";
    }
}
int main()
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);

    g.printVertexCover();
    return 0;
}*/
/*// Chinese Postman or Route Inspection
this is a variation of Eulerian circuit problem*/
/*// Number of Triangles in a Directed and Undirected Graph
#include <bits/stdc++.h>
using namespace std;
#define V 4
int countTriangle(int graph[V][V], bool isDirected)
{
    int count_Triangle = 0;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            for (int k = 0; k < V; k++)
            {
                if (graph[i][j] && graph[j][k] && graph[k][i])
                    count_Triangle++;
            }
        }
    }
    isDirected ? count_Triangle /= 3:
    count_Triangle /= 6;
    return count_Triangle;
}
int main()
{
    int graph[][V] = {{0, 1, 1, 0},
                      {1, 0, 1, 1},
                      {1, 1, 0, 1},
                      {0, 1, 1, 0}};
    int digraph[][V] = {{0, 0, 1, 0},
                        {1, 0, 0, 1},
                        {0, 1, 0, 0},
                        {0, 0, 1, 0}};

    cout << "The Number of triangles in undirected graph : "
         << countTriangle(graph, false);
    cout << "\n\nThe Number of triangles in directed graph : "
         << countTriangle(digraph, true);
    return 0;
}*/
/*// Minimise the cashflow among a given set of friends who have borrowed money from each other
Greedy 447*/
/*// Two Clique Problem
#include <bits/stdc++.h>
using namespace std;

const int V = 5;
bool isBipartiteUtil(int G[][V], int src, int colorArr[])
{
    colorArr[src] = 1;
    queue<int> q;
    q.push(src);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 0; v < V; ++v)
        {
            if (G[u][v] && colorArr[v] == -1)
            {
                colorArr[v] = 1 - colorArr[u];
                q.push(v);
            }
            else if (G[u][v] && colorArr[v] == colorArr[u])
                return false;
        }
    }
    return true;
}
bool isBipartite(int G[][V])
{
    int colorArr[V];
    for (int i = 0; i < V; ++i)
        colorArr[i] = -1;
    for (int i = 0; i < V; i++)
        if (colorArr[i] == -1)
            if (isBipartiteUtil(G, i, colorArr) == false)
                return false;

    return true;
}
bool canBeDividedinTwoCliques(int G[][V])
{
    int GC[V][V];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            GC[i][j] = (i != j) ? !G[i][j] : 0;
    return isBipartite(GC);
}
int main()
{
    int G[][V] = {{0, 1, 1, 1, 0},
                  {1, 0, 1, 0, 0},
                  {1, 1, 0, 0, 0},
                  {0, 1, 0, 0, 1},
                  {0, 0, 0, 1, 0}};

    canBeDividedinTwoCliques(G) ? cout << "Yes" : cout << "No";
    return 0;
}*/