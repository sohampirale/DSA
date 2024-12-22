function breadthFirstSearch(graph, startNode) {
    let visited = new Set();
    let queue = [];
    let traversalOrder = [];

    queue.push(startNode);
    visited.add(startNode);

    while (queue.length > 0) {
        let currentNode = queue.shift();
        traversalOrder.push(currentNode);

        let neighbors = graph[currentNode] || [];
        for (let neighbor of neighbors) {
            if (!visited.has(neighbor)) {
                visited.add(neighbor);
                queue.push(neighbor);
            }
        }
    }

    return traversalOrder;
}

export default breadthFirstSearch;