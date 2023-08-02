# Dijkstra
## The Theory
### What is it?
The Dijkstra algorithm is a graph traversal and shortest path-finding algorithm.
It is used to find the shortest path from a specified source node to all other nodes in a weighted graph, where the edges' weights represent the distances between nodes.
Dijkstra's algorithm guarantees the shortest path to each node in non-negative edge weight graphs.
### When should it be used?
Dijkstra's algorithm is suitable for finding the shortest path in graphs with non-negative edge weights.
It is commonly used in network routing, GPS navigation systems, and any application where finding the optimal path with minimal distance is crucial.
### When should it not be used?
Dijkstra's algorithm is not suitable for graphs with negative edge weights, as it can produce incorrect results in such cases.
If the graph contains negative edge weights, the Bellman-Ford algorithm is a more appropriate choice.
Additionally, Dijkstra's algorithm might not be the best option for very large graphs with millions of nodes, as its time complexity (O(V^2), where V is the number of vertices) can become inefficient.
In such cases, other algorithms like the A* algorithm can be more efficient.
### What are the common pitfalls of this approach?
Some common pitfalls of using the Dijkstra algorithm include:
* Negative Edge Weights: Dijkstra's algorithm does not handle graphs with negative edge weights. If the graph contains negative weights, the algorithm might produce incorrect results, leading to suboptimal or invalid paths.
* Time Complexity: For very large graphs, Dijkstra's algorithm can be computationally expensive, making it less practical in such cases.
* Memory Consumption: Dijkstra's algorithm requires storing distance values for all nodes, which can become memory-intensive in large graphs.
## The Practice
### Sample Project
