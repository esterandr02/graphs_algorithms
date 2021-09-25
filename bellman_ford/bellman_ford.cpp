#include <bits/stdc++.h>
#include <string.h>
#include <fstream>
#include <iostream>
using namespace std;

typedef long long int lli;
typedef pair<lli, lli> ii;
typedef vector<lli> vi;
typedef vector<ii> vii;
typedef vector<vii> vvi;

vvi graph;
vi distances;
bool hasNegativeCycle = false;

lli MAX_INT = 99999999;

lli bellman_ford(int source)
{
  distances[source] = 0;
  lli vertex = graph.size();
  lli edge, cost;

  for (int i = 0; i < vertex; i++)
  {
    for (int j = 0; j < vertex; j++)
    {
      for (int k = 0; k < graph[j].size(); k++)
      {
        cost = graph[j][k].first;
        edge = graph[j][k].second;

        if (i == vertex && distances[edge] > distances[j] + cost)
          hasNegativeCycle = true;
        else
          distances[edge] = min(distances[edge], distances[j] + cost);
      }
    }
  }
  return distances[vertex - 1];
}

int main(int argc, char const *argv[])
{

  // MENU

  int i;
  for (i = 0; i < argc; i++)
  {
    if (strcmp(argv[i], "-h") == 0)
    {
      printf("Opções de execução:\n\n-h --- help\n-o --- redirecionamento de saída\n");
      printf("-f --- indicar arquivo de entrada\n-s --- saída ordenada crescente\n");
      printf("-i --- indicar o vértice inicial\n-l --- indicar o vértice final\n");
    }

    if (strcmp(argv[i], "-o") == 0)
    {
      printf("%s\n", argv[i]);
    }

    if (strcmp(argv[i], "-f") == 0)
    {
      ifstream input_file("input.txt", ios::in);

      lli vertex, edges;
      cin >> vertex >> edges;

      distances.resize(vertex + 1, MAX_INT);
      graph.resize(vertex + 1);

      lli source, destiny, cost;

      while (!input_file.eof())
      {
        for (int i = 0; i < edges; i++)
        {
          cin >> source >> destiny >> cost;
          graph[source].push_back(make_pair(cost, destiny));
          graph[destiny].push_back(make_pair(cost, source));
        }
      }
      input_file.close();
    }

    if (strcmp(argv[i], "-s") == 0)
    {
      printf("%s\n", argv[i]);
    }

    if (strcmp(argv[i], "-i") == 0)
    {
      printf("%s\n", argv[i]);
    }

    if (strcmp(argv[i], "-l") == 0)
    {
      printf("%s\n", argv[i]);
    }
  }

  // END

  cout << bellman_ford(1) << endl;
  return 0;
}