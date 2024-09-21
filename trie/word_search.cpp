class TrieNode {
public:
    TrieNode* child[26];
    int WordEnd;
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
        WordEnd = 0;
    }
};
class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited,
             TrieNode* temp, int i, int j, string a, vector<string>& ans) {

        if (visited[i][j] == true) {
            return;
        }

        if (temp->child[board[i][j] - 'a'] == NULL) {
            return;
        }
        visited[i][j] = true;
        temp = temp->child[board[i][j] - 'a'];
        a += board[i][j];
        if (temp->WordEnd == 1) {
            ans.push_back(a);
            temp->WordEnd = 0;
        }

        if (i + 1 < board.size()) {
            dfs(board, visited, temp, i + 1, j, a, ans);
        }
        if (i - 1 >= 0) {
            dfs(board, visited, temp, i - 1, j, a, ans);
        }
        if (j + 1 < board[0].size()) {
            dfs(board, visited, temp, i, j + 1, a, ans);
        }
        if (j - 1 >= 0) {
            dfs(board, visited, temp, i, j - 1, a, ans);
        }

        visited[i][j] = false;
    }
    void createn(vector<string>& words, TrieNode* temp) {

        for (int i = 0; i < words.size(); i++) {
            string a = words[i];
            TrieNode* temp1 = temp;
            for (int j = 0; j < a.size(); j++) {
                if (temp1->child[a[j] - 'a'] == NULL) {
                    temp1->child[a[j] - 'a'] = new TrieNode();
                }
                temp1 = temp1->child[a[j] - 'a'];
            }
            temp1->WordEnd = 1;
        }
    }
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        TrieNode* root = new TrieNode();

        createn(words, root);

        vector<string> ans;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                vector<vector<bool>> visited(
                    board.size(), vector<bool>(board[0].size(), false));
                string a;
                dfs(board, visited, root, i, j, a, ans);
            }
        }

        return ans;
    }
};
