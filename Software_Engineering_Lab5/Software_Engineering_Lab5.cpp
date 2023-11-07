#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;



int tsp(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<int> vertices;
    for (int i = 0; i < n; ++i) {
        if (i != start) {
            vertices.push_back(i);
        }
    }

    int minCost = INF;
    do {
        int cost = 0;
        int k = start;
        for (int i = 0; i < vertices.size(); ++i) {
            cost += graph[k][vertices[i]];
            k = vertices[i];
        }
        cost += graph[k][start];
        minCost = min(minCost, cost);
    } while (next_permutation(vertices.begin(), vertices.end()));

    return minCost;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n = 5; // Количество городов

    // Матрица стоимостей
    vector<vector<int>> graph = {
        {0, 2, 9, 10, 4},
        {1, 0, 6, 4, 3},
        {15, 7, 0, 8, 1},
        {6, 3, 12, 0, 2},
        {4, 10, 2, 1, 0}
    };

    int start = 0; // Начальный город (от 0 до n-1)

    int minCost = tsp(graph, start);

    cout << "Минимальная стоимость пути: " << minCost << endl;

    return 0;
}