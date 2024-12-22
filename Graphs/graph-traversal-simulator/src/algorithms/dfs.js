function depthFirstSearch(graph, startNode) {
    const visited = new Set();
    const traversalOrder = [];

    function dfs(node) {
        if (!node || visited.has(node)) return;
        visited.add(node);
        traversalOrder.push(node);

        const neighbors = graph[node] || [];
        for (const neighbor of neighbors) {
            dfs(neighbor);
        }
    }

    dfs(startNode);
    return traversalOrder;
}

export default depthFirstSearch;