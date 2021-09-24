_dijkstra:
	g++ dijkstra.cpp -o dijkstra && ./dijkstra <inputBD.txt

_bellman_ford:
	g++ bellman_ford.cpp -o bellman && ./bellman <inputBD.txt

_kruskal:
	g++ kruskal.cpp -o kruskal && ./kruskal <inputKP.txt

_prim:
	g++ prim.cpp -o prim && ./prim <inputKP.txt