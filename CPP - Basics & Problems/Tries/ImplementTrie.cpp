//Leetcode Implement trie soln
class TrieNode{
    public:
        bool isEnd;
        TrieNode* children[26];
        TrieNode()
        {
            isEnd = false;
            for(int i=0; i<26; i++)
            {
                children[i] = NULL;
            }
        }
};
TrieNode* root;
class Trie {
public:
    /** Initialize your data structure here. */
    
    Trie() {
        
        root = new TrieNode();
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        
        int n = word.size();
        TrieNode* parent = root;
        for(int i=0; i<n; i++)
        {
            int val = word[i]-'a';
            if(parent->children[val]==NULL)
            {
                parent->children[val] = new TrieNode();
            }
            parent = parent->children[val];
        }
        parent->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        
        int n = word.size();
        TrieNode* parent = root;
        for(int i=0; i<n; i++)
        {
            int val = word[i]-'a';
            if(parent->children[val]==NULL)
            {
                return false;
            }
            parent = parent->children[val];
        }
        return parent->isEnd;
        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        
        int n = prefix.size();
        TrieNode* parent = root;
        for(int i=0; i<n; i++)
        {
            int val = prefix[i]-'a';
            if(parent->children[val]==NULL)
            {
                return false;
            }
            parent = parent->children[val];
        }
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */