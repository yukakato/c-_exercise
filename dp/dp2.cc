#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

class Node {
private:
    vector<int> edges_to;
    vector<int> edges_cost;
    int node_t, node_s, node_cost;

public:
    void setT(int t) {
        node_t = t;
    }
    void setS(int s) {
        node_s = s;
    }
    void setCost(int cost) {
        node_cost = cost;
    }
    void addEdgesTo(int n, int c) {
        edges_to.push_back(n);
        edges_cost.push_back(c);
    }
    int getT() {
        return node_t;
    }
    int getS() {
        return node_s;
    }
    int getCost() {
        return node_cost;
    }
    vector<int> getEdgesTo() {
        return edges_to;
    }
    vector<int> getEdgesCost() {
        return edges_cost;
    }
    Node() {
        node_t = 0;
        node_s = 0;
        node_cost = 0;
    }
    Node(int t, int s) {
        node_t = t;
        node_s = s;
        node_cost = 0;
    }
};

int main() {
    Node node[14];
    int n = 1;
    for (int i = 1; i < 5; ++i) {
        for (int j = 0; j < 3; j++) {
            node[n].setT(i);
            node[n].setS(j);
            ++n;
        }
    }
    node[n].setT(5);
    node[n].setS(1);

    node[0].addEdgesTo(1, 5);
    node[0].addEdgesTo(2, 0);
    node[0].addEdgesTo(3, 3);
    node[1].addEdgesTo(4, 0);
    node[2].addEdgesTo(4, 4);
    node[2].addEdgesTo(5, 0);
    node[2].addEdgesTo(6, 3);
    node[3].addEdgesTo(5, 0);
    node[4].addEdgesTo(7, 0);
    node[5].addEdgesTo(7, 3);
    node[5].addEdgesTo(8, 0);
    node[5].addEdgesTo(9, 3);
    node[6].addEdgesTo(8, 0);
    node[7].addEdgesTo(10, 0);
    node[8].addEdgesTo(10, 2);
    node[8].addEdgesTo(11, 0);
    node[8].addEdgesTo(12, 3);
    node[9].addEdgesTo(11, 0);
    node[10].addEdgesTo(13, 0);
    node[11].addEdgesTo(13, -5);
    node[12].addEdgesTo(13, -5);

    vector<int> v1, v2;
    v1 = node[0].getEdgesTo();
    v2 = node[0].getEdgesCost();
    for (int i = 0; i < v1.size(); ++i) {
        node[v1[i]].setCost(v2[i]);
    }
}
