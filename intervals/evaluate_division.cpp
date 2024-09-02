class Node {
public:
    string val;
    vector<pair<Node*, double>> ar;
    Node(string a) {
        val = a;
        ar = vector<pair<Node*, double>>();
    }
};
class Solution {
public:
    void graph(unordered_map<string, Node*>& mp,
               vector<vector<string>>& equations, vector<double>& values) {
        int i = 0;
        for (auto it : equations) {
            Node *temp = mp[it[0]], *temp1 = mp[it[1]];
            temp->val = it[0];
            pair<Node*, double> a = make_pair(temp1, values[i]),
                                b = make_pair(temp, 1 / values[i]);
            temp->ar.push_back(a);
            temp1->ar.push_back(b);
            cout << a.first->val << a.second << endl;
            cout << b.first->val << b.second << endl;
            i++;
        }
    }

    double bfs(string a, string b, unordered_map<string, Node*>& mp, double ans,
               unordered_map<string, int>& visited) {
        cout << a << ans << b << endl;

        visited[a] = 1;
        if (a == b) {
            return ans;
        }
        vector<pair<Node*, double>> cr = mp[a]->ar;

        for (int i = 0; i < cr.size(); i++) {
            if (cr[i].first == mp[b]) {
                ans = ans * cr[i].second;
                return ans;
            } else if (visited[cr[i].first->val] != 1) {

                double k =
                    bfs(cr[i].first->val, b, mp, ans * cr[i].second, visited);
                if (k == -1) {
                    continue;
                } else {
                    return k;
                }
            }
        }
        return -1.00000;
    }
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {

        unordered_map<string, Node*> mp;
        unordered_map<string, int> visited;
        for (auto it : equations) {
            if (mp.find(it[0]) == mp.end()) {
                mp[it[0]] = new Node(it[0]);
            }
            if (mp.find(it[1]) == mp.end()) {
                mp[it[1]] = new Node(it[1]);
            }
            visited[it[0]] = 0;
            visited[it[1]] = 0;
        }

        graph(mp, equations, values);
        vector<double> ans;

        for (auto it : queries) {

            if (mp.find(it[0]) == mp.end() || mp.find(it[1]) == mp.end()) {
                ans.push_back(-1.00000);
                continue;
            }
            if (it[0] == it[1]) {
                ans.push_back(1.00000);
                continue;
            }
            string a = it[0], b = it[1];
            unordered_map<string, int> visited1 = visited;
            ans.push_back(bfs(a, b, mp, 1, visited1));
        }
        return ans;
    }
};
