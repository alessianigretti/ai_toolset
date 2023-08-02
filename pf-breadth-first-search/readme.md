# Breadth-First Search
## The Theory
### What is it?
The Breadth-First Search (BFS) algorithm is a graph traversal technique used to explore a graph or tree data structure layer by layer.
It starts from a specified source node and explores all its neighbors (adjacent nodes) before moving to their neighbors, and so on, until all reachable nodes have been visited.
BFS guarantees the shortest path from the source node to any other reachable node in an unweighted graph.
### When should it be used?
BFS is an excellent choice when you need to find the shortest path or explore all reachable nodes in an unweighted graph or tree.
It is commonly used for searching, finding connected components, shortest path algorithms, and solving puzzles with single-step moves, like solving the Rubik's cube.
### When should it not be used?
BFS might not be the best option for graphs with a large number of nodes or with significant branching factors.
Its memory and time complexity (O(V + E), where V is the number of vertices and E is the number of edges) can become a significant drawback in such cases.
For large graphs with weights, Dijkstra's algorithm or A* algorithm might be more suitable to find the shortest path.
### What are the common pitfalls of this approach?
Some common pitfalls of using the Breadth-First Search algorithm include:
* Memory Consumption: BFS requires storing all the nodes in the current layer before moving to the next layer, making it memory-intensive, especially for graphs with a large number of nodes.
* Inefficient for Weighted Graphs: BFS is not directly applicable to graphs with weighted edges, as it assumes all edges have the same weight, and it cannot guarantee the shortest path in such cases.
* Lack of Direction: BFS is a blind search algorithm that does not consider the direction or weight of edges, so it may not be optimal for specific applications like finding the minimum cost path.
## The Practice
### Sample Project
