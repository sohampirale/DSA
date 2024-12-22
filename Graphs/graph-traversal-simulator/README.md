# Graph Traversal Simulator

This project simulates Depth-First Search (DFS) and Breadth-First Search (BFS) traversals using D3.js. It provides a visual representation of graph traversal algorithms, allowing users to interactively explore how these algorithms work.

## Project Structure

```
graph-traversal-simulator
├── src
│   ├── index.html         # Main HTML document
│   ├── styles.css         # Styles for the web page
│   ├── app.js             # Main JavaScript file for D3.js visualization
│   ├── algorithms
│   │   ├── dfs.js         # Depth-First Search algorithm implementation
│   │   └── bfs.js         # Breadth-First Search algorithm implementation
│   └── data
│       └── graph.json     # JSON representation of the graph structure
├── package.json            # npm configuration file
└── README.md               # Project documentation
```

## Getting Started

To run the simulation, follow these steps:

1. **Clone the repository**:
   ```
   git clone <repository-url>
   cd graph-traversal-simulator
   ```

2. **Install dependencies**:
   ```
   npm install
   ```

3. **Open the project**:
   Open `src/index.html` in your web browser to view the simulation.

## Algorithms

### Depth-First Search (DFS)

The DFS algorithm is implemented in `src/algorithms/dfs.js`. It explores as far as possible along each branch before backtracking. The function `depthFirstSearch(graph, startNode)` takes a graph and a starting node as parameters and returns the order of traversal.

### Breadth-First Search (BFS)

The BFS algorithm is implemented in `src/algorithms/bfs.js`. It explores all the neighbor nodes at the present depth prior to moving on to nodes at the next depth level. The function `breadthFirstSearch(graph, startNode)` takes a graph and a starting node as parameters and returns the order of traversal.

## Visualization

The graph visualization is created using D3.js, which allows for dynamic and interactive representations of the graph structure. Users can select starting nodes and observe the traversal process in real-time.

## License

This project is licensed under the MIT License. See the LICENSE file for more details.