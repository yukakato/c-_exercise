#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

class Node {
private:
    vector<int> edges_from;
    vector<int> edges_cost;
    int node_t, node_s, node_cost, max_path;

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
    void setPath(int path) {
        max_path = path;
    }
    void addEdgesFrom(int n, int c) {
        edges_from.push_back(n);
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
    int getPath() {
        return max_path;
    }
    vector<int> getEdgesFrom() {
        return edges_from;
    }
    vector<int> getEdgesCost() {
        return edges_cost;
    }
    Node() {
        node_t = 0;
        node_s = 0;
        node_cost = 0;
        max_path = -1;
    }
    Node(int t, int s) {
        node_t = t;
        node_s = s;
        node_cost = 0;
        max_path = -1;
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

    node[1].addEdgesFrom(0, 5);
    node[2].addEdgesFrom(0, 0);
    node[3].addEdgesFrom(0, 3);
    node[4].addEdgesFrom(1, 0);
    node[4].addEdgesFrom(2, 4);
    node[5].addEdgesFrom(2, 0);
    node[5].addEdgesFrom(3, 0);
    node[6].addEdgesFrom(2, 3);
    node[7].addEdgesFrom(4, 0);
    node[7].addEdgesFrom(5, 3);
    node[8].addEdgesFrom(5, 0);
    node[8].addEdgesFrom(6, 0);
    node[9].addEdgesFrom(5, 3);
    node[10].addEdgesFrom(7, 0);
    node[10].addEdgesFrom(8, 2);
    node[11].addEdgesFrom(8, 0);
    node[11].addEdgesFrom(9, 0);
    node[12].addEdgesFrom(8, 3);
    node[13].addEdgesFrom(10, 0);
    node[13].addEdgesFrom(11, -5);
    node[13].addEdgesFrom(12, -5);

    int ft = 0, tmp_cost;
    vector<int> v1, v2;

    for (int i = 1; i < 14 ; ++i) {
        v1 = node[i].getEdgesFrom();
        v2 = node[i].getEdgesCost();
        ft = 0;
        for (int j = 0; j < v1.size(); ++j) {
            tmp_cost = node[v1[j]].getCost() + v2[j];
            if (ft < tmp_cost) {
                ft = tmp_cost;
                node[i].setPath(v1[j]);
            }
        }
        node[i].setCost(ft);
    }

    for (int i = 0; i < 14; ++i) cout << "Ft(" << i << ") = " << node[i].getCost() << endl;

    cout << 13;
    int k = 13;
    while(1){
        if (k <= 0) break;
        else {
            k = node[k].getPath();
            cout << "<--" << k; 
        }
    }
    cout << endl;
}
