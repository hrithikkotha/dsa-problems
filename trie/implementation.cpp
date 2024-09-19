class Trie {
public:
    struct TrieNode {
        TrieNode* child[26];

        bool WordEnd=false;

        TrieNode() {
            for (int i = 0; i < 26; i++) {
                child[i] = NULL;
            }
        }
    };

    TrieNode *root;

    Trie() {
        root=new TrieNode();
    }

    void insert(string word) {
        TrieNode *temp=root;
        for(int i=0;i<word.size();i++){
            if(temp->child[word[i]-'a']==NULL){
                temp->child[word[i]-'a']=new TrieNode();
            }
            temp=temp->child[word[i]-'a'];
        }
        temp->WordEnd=true;
    }

    bool search(string word) {
        TrieNode *temp=root;
        for(int i=0;i<word.size();i++){
            if(temp->child[word[i]-'a']==NULL){
                return false;
            }
            temp=temp->child[word[i]-'a'];
        }
        
        return temp->WordEnd;
    }

    bool startsWith(string prefix) {

       TrieNode *temp=root;
        for(int i=0;i<prefix.size();i++){
            if(temp->child[prefix[i]-'a']==NULL){
                return false;
            }
            temp=temp->child[prefix[i]-'a'];
        }

        return true;
    }
};
