class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {

        unordered_map<string, int> vis;

        queue<string> q;

        q.push(startGene);

        int nmutes = 0;
        string g = "ACGT";
        vis[startGene] = 1;
        while (!q.empty()) {

            for (int t = q.size() - 1; t >= 0; t--) {
                string s = q.front();
                q.pop();

                if (s == endGene) {
                    return nmutes;
                }

                for (int i = 0; i < 8; i++) {
                    char a = s[i];
                    for (int j = 0; j < 4; j++) {

                        char a = g[j];

                        s[i] = a;
                        if (vis[s] != 1 &&
                            find(bank.begin(), bank.end(), s) != bank.end()) {

                            q.push(s);
                            vis[s] = 1;
                        }
                    }
                    s[i] = a;
                }
            }
            nmutes++;
        }

        return -1;
    }
};
