struct Trie {
    struct TrieNode {
        unordered_map<char, TrieNode *> children;
        bool last = false;
    };
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    bool insert(string s) {
        TrieNode *tree = root;
        for(auto &i : s) {
            if(!tree->children.count(i)) tree->children[i] = new TrieNode();
            tree = tree->children[i];
        }
        tree->last = true;
        return true;
    }
    bool search(string s) {
        TrieNode *tree = root;
        for(auto &i : s) {
            if(!tree->children.count(i)) return false;
            tree = tree->children[i];
        }
        return tree->last;
    }
    bool prefix(string s) {
        TrieNode *tree = root;
        for(auto &i : s) {
            if(!tree->children.count(i)) return false;
            tree = tree->children[i];
        }
        return true;
    }

} trie;