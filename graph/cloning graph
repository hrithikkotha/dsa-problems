/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void clone(vector<vector<int>>& adj, Node* node, int& count) {
        // int count=0;

        queue<Node*> q;
        q.push(node);
        vector<int> visited(1000, 0);
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            visited[temp->val] = 1;
            count++;
            for (auto it : temp->neighbors) {
                if (visited[it->val] != 1) {
                    q.push(it);
                }
                adj[temp->val][it->val] = 1;
            }
        }
    }
    Node* create(vector<vector<int>>& adj, int& count) {
        vector<Node*> cloned(count + 2);

        for (int i = 1; i <= count; i++) {
            cloned[i] = new Node(i);
        }

        for (int j = 1; j <= count; j++) {
            Node* temp = cloned[j];
            vector<Node*> neighborsx;
            for (int i = 1; i <= count; i++) {
                if (adj[j][i] == 1) {
                    neighborsx.push_back(cloned[i]);
                }
            }
            temp->neighbors = neighborsx;
        }

        return cloned[1];
    }
    Node* cloneGraph(Node* node) {
        vector<Node*> main;
        if (!node) {
            return node;
        }
        vector<vector<int>> adj(1000, vector<int>(1000, 0));
        int count = 0;
        clone(adj, node, count);

        return create(adj, count);
    }
};
