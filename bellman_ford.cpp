#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair <lli, lli> ii;
typedef vector <lli> vi;
typedef vector <ii> vii;
typedef vector <vii> vvi;

vvi graph;
vi distances;
bool hasNegativeCycle = false;

lli MAX_INT = 99999999;

lli bellman_ford(int source) {
  distances[source] = 0;
  lli vertex = graph.size();
  lli edge, cost;

  for(int i=0; i <  vertex; i++) {
    for(int j=0; j < vertex; j++) {
      for(int k = 0; k < graph[j].size(); k++) {
        cost = graph[j][k].first;
        edge = graph[j][k].second;

        if(i == vertex && distances[edge] > distances[j] + cost) hasNegativeCycle = true;
        else distances[edge] = min(distances[edge], distances[j] + cost);
      }
    }
  }
  return distances[vertex - 1];
}

int main() {
  lli vertex, edges;
  cin >> vertex >> edges;

  distances.resize(vertex + 1, MAX_INT);
  graph.resize(vertex + 1);

  lli source, destiny, cost;

  for(int i=0; i < edges; i++) {
    cin >> source >> destiny >> cost;
    graph[source].push_back(make_pair(cost, destiny));
    graph[destiny].push_back(make_pair(cost, source));
  }

  cout << bellman_ford(1) << endl;
  return 0;
}