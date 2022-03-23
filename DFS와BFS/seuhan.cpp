#include <cstring>
#include <deque>
#include <iostream>

using namespace std;
int vertex, node, startVertex;
bool graph[1001][1001];
bool visited[1001];

void DFS(int vertex, int startVertex) {
    int target = startVertex;
    cout << target << " ";
    visited[target] = true;

    for (int i = 1; i < vertex + 1; i++) {
        if (i == target) {
            continue;
        }
        if (!visited[i] && (graph[target][i] || graph[i][target])) {
            DFS(vertex, i);
        }
    }
}

void BFS() {
    deque<int> queue;
    queue.push_back(startVertex);
    visited[startVertex] = true;

    int target;
    while (true) {
        if (queue.empty()) {
            break;
        }
        target = queue.front();
        cout << target << " ";
        queue.pop_front();
        for (int i = 0; i < vertex + 1; i++) {
            if (graph[target][i] || graph[i][target]) {
                if (visited[i] == false) {
                    queue.push_back(i);
                    visited[i] = true;
                }
            }
        }
    }
}

int main() {
    int row, col;
    cin >> vertex >> node >> startVertex;
    for (int i = 0; i < node; i++) {
        cin >> row >> col;
        graph[row][col] = true;
    }
    DFS(vertex, startVertex);
    memset(visited, 0, sizeof(visited));
    cout << endl;
    BFS();
}