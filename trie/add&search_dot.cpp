class WordDictionary {
public:
    struct TrieNode {
        TrieNode* child[26];

        bool WordEnd = false;

        TrieNode() {
            for (int i = 0; i < 26; i++) {
                child[i] = NULL;
            }
        }
    };

    TrieNode* root;

    WordDictionary() { root = new TrieNode(); }

    void addWord(string word) {
        TrieNode* temp = root;
        for (int i = 0; i < word.size(); i++) {
            if (temp->child[word[i] - 'a'] == NULL) {
                temp->child[word[i] - 'a'] = new TrieNode();
            }
            temp = temp->child[word[i] - 'a'];
        }
        temp->WordEnd = true;
    }

    bool search1(string word, TrieNode* temp, int i) {
        for (int k = i; k < word.size() && temp; k++) {
            if (word[k] != '.') {
                temp = temp->child[word[k] - 'a'];

            } else {
                TrieNode* temp2;
                
                for (int j = 0; j < 26; j++) {
                    temp2 = temp->child[j];
                    if (search1(word, temp2, k+ 1)) {
                        return true;
                    }
                }
                return false;
            }
        }
        
        return temp&&temp->WordEnd;
    }
    bool search(string word) {
        return search1(word, root, 0); 
    }
};
