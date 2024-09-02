// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

//     For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

// Return true if you can finish all courses. Otherwise, return false.

 

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0. So it is possible.

// Example 2:

// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.





class Node {
public:
    int val;
    vector<Node*> ar;
    Node(int a) {
        val = a;
        ar = vector<Node*>();
    }
};
class Solution {
public:
    void graph(vector<vector<int>> adj, unordered_map<int, Node*>& mp,
               int numCourses) {
        for (int i = 0; i < numCourses; i++) {
            mp[i] = new Node(i);
        }

        for (int i = 0; i < adj.size(); i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                if (adj[i][j] == 1) {
                    Node* temp = mp[i];
                    temp->ar.push_back(mp[j]);
                }
            }
        }
    }
    bool dfs(unordered_map<int, Node*>& mp, vector<bool>& dp, Node* temp,
             unordered_set<Node*> a) {

        if (a.find(temp) != a.end()) {
            return false;
        }
        a.insert(temp);

        vector<Node*> curr = temp->ar;

        if (curr.size() == 0 || dp[temp->val] == true) {
            if (curr.size() == 0) {
                dp[temp->val] = true;
            }
            return true;
        }
        for (int i = 0; i < curr.size(); i++) {

            if (!dfs(mp, dp, curr[i], a)) {
                dp[curr[i]->val] = false;
                return dp[curr[i]->val];
            }
        }
        dp[temp->val] = true;
        return dp[temp->val];
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>(numCourses, 0));
        vector<bool> dp(numCourses, false);
        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][0]][prerequisites[i][1]] = 1;
            dp[prerequisites[i][0]] = false;
        }

        unordered_map<int, Node*> mp;

        graph(adj, mp, numCourses);

        for (auto it = mp.begin(); it != mp.end(); it++) {
            unordered_set<Node*> a;
            Node* temp = it->second;
            if (!dfs(mp, dp, temp, a)) {
                return false;
            }
        }

        return true;
    }
};
