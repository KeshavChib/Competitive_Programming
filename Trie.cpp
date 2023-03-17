
class node{
    public:
    vector<node*> link;
    bool flag = false;
    node(){
        link.resize(26);
        for(int i=0;i<26;i++) link[i] = NULL;
    }

    bool contains(char ch){
        return (link[ch - 'a'] != NULL);
    }

    node* getword(char ch){
        return link[ch - 'a'];
    }

    void addNode(char ch, node* n){
        link[ch - 'a'] = n;
    }

};

class Trie {
    node* root;
public:
    Trie() {
        root = new node();
    }
    
    void insert(string word) {
        node* curr = root;
        for(int i=0;i<word.size();i++){
            if(!curr->contains(word[i])){
                curr->addNode(word[i], new node());
            }
            curr = curr->getword(word[i]);
        }
        curr->flag = true;
    }
    
    bool search(string word) {
        node* curr = root;
        for(int i=0;i<word.size();i++){
            if(!curr->contains(word[i])){
                return false;
            }
            curr = curr->getword(word[i]);
        }
        return curr->flag;
    }
    
    bool startsWith(string prefix) {
        node* curr = root;
        for(int i=0;i<prefix.size();i++){
            if(!curr->contains(prefix[i])){
                return false;
            }
            curr = curr->getword(prefix[i]);
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
