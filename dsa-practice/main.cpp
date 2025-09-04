#include<bits/stdc++.h>
using namespace std;

// At Uber, drivers are often required to complete multiple
// pickups or drop-offs in a specific sequence before reaching
// their final destination.
// The city is represented as an undirected road network
// graph, where intersections are nodes and roads are
// weighted edges representing travel times.
// • The driver always starts at node 1 (their initial location).
// • The final destination (the last rider drop-off) is always
// node r_ nodes.
// The driver must visit two required stops in order:
// • First stop at node * (e.g., rider pickup).
// • Second stop at node y (e.g., intermediate rider drop-off).
// You are given:
// • r_ nodes: the number of intersections in the city.
// • r_fromil and r_toli: the two intersections connected by
// the i-th road.
// • r_ weightil: the travel time along that road.
// Task
// Compute the minimum total travel time for the driver to go
// from:
// Start (node 1) → Stop * → Stop y → Final Destination (node
// r_nodes
// The driver may pass through intersections multiple times if
// necessary.
// Example
// r_nodes = 5
// r_ from = [1, 2, 3, 4, 5, 31
// _to = 12, 3, 4, 5, 1, 5]
// _weight = 19, 11, 6, 1, 4, 101
// HackerRank Confident
// x = 2


// implemet and add disjtra basically 1 to x x to y and y to r_node

#include <bits/stdc++.h>
using namespace std;

int dijkstra(int src, int dest, unordered_map<int, vector<pair<int,int>>>& adjList, int n) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(n+1, INT_MAX);

    dist[src] = 0;
    pq.push(make_pair(0, src));

    while (!pq.empty()) {
        int currDistance = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (node == dest) return currDistance;

        for (int i = 0; i < adjList[node].size(); i++) {
            int v = adjList[node][i].first;
            int wt = adjList[node][i].second;

            if (currDistance + wt < dist[v]) {
                dist[v] = currDistance + wt;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    return -1; // unreachable
}

int minTime(int x, int y, vector<int> r_from, vector<int> r_to, vector<int> wt, int r_nodes) {
    unordered_map<int, vector<pair<int,int>>> adjList;

    for (int i = 0; i < wt.size(); i++) {
        adjList[r_from[i]].push_back(make_pair(r_to[i], wt[i]));
        adjList[r_to[i]].push_back(make_pair(r_from[i], wt[i])); // undirected
    }

    int part1 = dijkstra(1, x, adjList, r_nodes);
    int part2 = dijkstra(x, y, adjList, r_nodes);
    int part3 = dijkstra(y, r_nodes, adjList, r_nodes);

    if (part1 == -1 || part2 == -1 || part3 == -1) return -1;

    return part1 + part2 + part3;
}

int main() {
    int x = 2;
    int y = 3;
    vector<int> r_from = {1,2,3,4,5,3};
    vector<int> r_to   = {2,3,4,5,1,5};
    vector<int> wt     = {9,11,6,1,4,10};
    int r_nodes = 5;

    cout << minTime(x, y, r_from, r_to, wt, r_nodes) << endl;
    return 0;
}
