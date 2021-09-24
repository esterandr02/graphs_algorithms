#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;
typedef vector <bool> vb;
typedef vector <vii> vvi;
typedef priority_queue <ii, vii, greater<ii>> pq;

vvi graph;
vb visited;
pq pqueue;

int prim() {
  int minimum_cost = 0;
  ii source = make_pair(0, 1);

  pqueue.push(source);

  while(!pqueue.empty()) {
    source = pqueue.top();
    pqueue.pop();

    int source_cost = source.first;
    int source_edge = source.second;

    if(!visited[source_edge]) {
      minimum_cost += source_cost;
      visited[source_edge] = true;
            
      for(auto edge: graph[source_edge]) {
        pqueue.push(edge);
      }   
    }
  }
  return minimum_cost;
}

int main() {
  int vertex, edges;
  cin >> vertex >> edges;

  graph.resize(vertex + 1);
  visited.resize(vertex + 1, false);

  int source, destiny, cost;

  for(int i = 0; i < edges; ++i) {
    cin >> source >> destiny >> cost;
    graph[source].push_back(make_pair(cost, destiny));
    graph[destiny].push_back(make_pair(cost, source));
  }

  cout << prim() << endl;
  return 0;
}