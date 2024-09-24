class Solution {
public:
    int count = 0;
    void find(vector<int> row, vector<int> col, vector<int> dia,
              vector<int> andia, int i, int n) {
        if (i == n) {
            count++;
            return;
        }

        for (int j = 0; j < n; j++) {
            if (!col[j] && !row[i] && !dia[i + j] && !andia[i + n - 1 - j]) {
                col[j] = true;
                row[i] = true;
                dia[i + j] = true;
                andia[i + n - 1 - j] = true;
                find(row, col, dia, andia, i + 1, n);
                col[j] = false;
                row[i] = false;
                dia[i + j] = false;
                andia[i + n - 1 - j] = false;
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<int>> a(n, vector<int>(n, 0));
        vector<int> row(n, false);
        vector<int> col(n, false);
        vector<int> dia(2 * n - 1, false);
        vector<int> andia(2 * n - 1, false);
        find(row, col, dia, andia, 0, n);

        return count;
    }
};
