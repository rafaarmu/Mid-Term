#include <iostream>
#include <vector>
#include <queue>
#include <climits>

void dijkstra(const std::vector<std::vector<int> >& graph, int source) {
    int numVertices = graph.size();

    // Create a priority queue to store vertices and their distances
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > pq;

    // Create a vector to store distances. Initialize all distances to INT_MAX.
    std::vector<int> distance(numVertices, 20);

    // index 2 in distance = distance from vertex 0 to vertex 2

    pq.push(std::pair<int, int>(0, 0));;
    while (!pq.empty()) {
        std::pair<int, int> curVertex = pq.top();
        pq.pop();

        distance[curVertex.first] = curVertex.second;

        for (int i = 0; i < graph.size(); i++) {
            int tempDistance = std::min(curVertex.second + graph[curVertex.first][i], curVertex.second + graph[i][curVertex.first]);
            if (tempDistance < distance[i]) {
                distance[i] = tempDistance;
                pq.push(std::pair<int, int>(i, tempDistance));
            }
        }
    }

    for (int i = 0; i < distance.size(); i++) {
        std::cout << "Distance from vertex 0 to vertex " << i << " = " << distance[i] << std::endl;
    }
}

int main() {
    std::vector<std::vector<int> > graph(5, std::vector<int>(5, 20));

    // {
    //     {0, 2, INT_MAX, 4, INT_MAX},
    //     {INT_MAX, 0, 1, 3, INT_MAX},
    //     {INT_MAX, INT_MAX, 0, INT_MAX, 1},
    //     {INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX},
    //     {INT_MAX, INT_MAX, INT_MAX, 2, 0}
    // };

    graph[0][0] = 0;
    graph[0][1] = 2;
    graph[0][3] = 4;

    graph[1][1] = 0;
    graph[1][2] = 1;
    graph[1][3] = 3;

    graph[2][2] = 0;
    graph[2][4] = 1;

    graph[3][3] = 0;
    graph[3][4] = 2;

    graph[4][4] = 0;
    graph[4][3] = 2;

    dijkstra(graph, 0);

    return 0;
}