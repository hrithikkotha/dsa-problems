// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

//     For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

// Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: [0,1]
// Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].

// Example 2:

// Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
// Output: [0,2,1,3]
// Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
// So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].



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
             unordered_set<Node*> a, vector<int>& k) {

        if (a.find(temp) != a.end()) {
            return false;
        }
        a.insert(temp);

        vector<Node*> curr = temp->ar;

        if (curr.size() == 0 || dp[temp->val] == true) {
            if (curr.size() == 0) {
                if (!dp[temp->val]) {
                    k.push_back(temp->val);
                }
                dp[temp->val] = true;
            }
            return true;
        }
        for (int i = 0; i < curr.size(); i++) {

            if (!dfs(mp, dp, curr[i], a, k)) {
                dp[curr[i]->val] = false;
                return dp[curr[i]->val];
            }
        }
        if (!dp[temp->val]) {
            k.push_back(temp->val);
        }
        dp[temp->val] = true;
        return dp[temp->val];
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>(numCourses, 0));
        vector<bool> dp(numCourses, false);
        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][0]][prerequisites[i][1]] = 1;
            dp[prerequisites[i][0]] = false;
        }

        unordered_map<int, Node*> mp;

        graph(adj, mp, numCourses);
        vector<int> k;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            unordered_set<Node*> a;
            Node* temp = it->second;
            if (!dfs(mp, dp, temp, a, k)) {
                vector<int> ans;
                return ans;
            }
        }

        return k;
    }
};
