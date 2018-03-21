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
    cout << n - 1 << node[n-1].getT() << node[n-1].getS() << endl;
    for (int i = 1; i < 5; ++i) {
        for (int j = 0; j < 3; j++) {
            node[n].setT(i);
            node[n].setS(j);
            cout << n << node[n].getT() << node[n].getS() << endl;
            ++n;
        }
    }
    node[n].setT(5);
    node[n].setS(1);
    cout << n << node[n].getT() << node[n].getS() << endl;

    node[0].addEdgesTo(1, 5);
    node[0].addEdgesTo(2, 0);
    node[0].addEdgesTo(3, 3);
    node[1].addEdgesTo(4, 0);
    node[2].addEdgesTo(4, 4);
    node[2].addEdgesTo(5, 0);
    node[2].addEdgesTo(6, 3);
    node[3].addEdgesTo(5, 0);

    vector<int> v;
    v = node[2].getEdgesCost();
    cout << v[0] << v[1] << v[2] << endl;
}
