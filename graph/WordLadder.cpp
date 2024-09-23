class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        unordered_set<string> mp;
        for (int i = 0; i < wordList.size(); i++) {
            mp.insert(wordList[i]);
        }

        queue<string> q;

        q.push(beginWord);
        int count = 1;
        while (!q.empty()) {

            for (int t = q.size()-1; t >= 0; t--) {
                string a = q.front();
                q.pop();
                if (a == endWord) {
                    return count;
                }
                for (int i = 0; i < a.size(); i++) {
                    string b = a;
                    for (int j = 0; j < 26; j++) {
                        b[i] = j + 'a';
                        if (b[i] != a[i] && mp.find(b) != mp.end()) {
                            q.push(b);
                            mp.erase(b);
                        }
                    }
                }
            }

            count++;
        }

        return 0;
    }
};
