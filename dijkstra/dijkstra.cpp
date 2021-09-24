#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;
typedef vector <bool> vb;
typedef vector <vii> vvi;
typedef priority_queue <ii, vii, greater<ii>> pq;

pq pqueue;
vvi graph;
vi predecessor;
vi distances;
vi way;

int dijkstra() {
  ii source = make_pair(0, 1);
  distances[1] = 0;
  pqueue.push(source);  
    
  while(!pqueue.empty()) {
    source = pqueue.top();
    pqueue.pop();

    int source_cost = source.first, source_edge = source.second;

    for(auto edge: graph[source_edge]) {
      int current_cost = edge.first;
      int current_edge = edge.second;

      if(distances[current_edge] > current_cost + source_cost) {
        predecessor[current_edge] = source_edge;
        distances[current_edge] = current_cost + source_cost;
        pqueue.push(make_pair(distances[current_edge], current_edge));
      }
    }
  }
  return distances[graph.size() - 1];
}

int main() {
  int vertex, edges;
  cin >> vertex >> edges;

  distances.resize(vertex + 1, INT_MAX);
  predecessor.resize(vertex + 1);
  graph.resize(vertex + 1);

  int source, destiny, cost;

  for(int i = 0; i < edges; ++i) {
    cin >> source >> destiny >> cost;
    graph[source].push_back(make_pair(cost, destiny));
    graph[destiny].push_back(make_pair(cost, source));
  }

  cout << dijkstra() << endl;
  return 0;
}