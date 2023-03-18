#include <bits/stdc++.h>
class node {
    vector<node*> links;
    int cntpre;
    int cntend;
    public:
    node(){
        cntpre = 0;
        cntend = 0;
        links.resize(26, NULL);
    }

    bool contains(char ch){
        return (links[ch - 'a'] != NULL);
    }
    void add(char ch, node* no){
        links[ch - 'a'] = no;
    }
    void increasePre(){
        cntpre++;
    }

    void increaseEnd(){
        cntend++;
    }
    int totalWords(){
        return cntend;
    }

    node* advanceAt(char ch){
        return links[ch - 'a'];
    }

    int totalPre(){
        return cntpre;
    }

    void decresePre(){
        cntpre--;
    }

    void decreseEnd(){
        cntend--;
    }
};

class Trie {
    node* root;
public:
  Trie() {
    // Write your code here.
    root = new node();
  }

  void insert(string &word) {
    // Write your code here.
    node* curr = root;
    for(int i=0;i<word.size();i++){
        if(!curr->contains(word[i])){
            curr->add(word[i], new node());
        }
        curr = curr->advanceAt(word[i]);
        curr->increasePre();
    }
    curr->increaseEnd();
  }

  int countWordsEqualTo(string &word) {
    // Write your code here.
    node* curr = root;
    for(int i=0;i<word[i];i++){
        if(!curr->contains(word[i])) return 0;
        curr = curr->advanceAt(word[i]);
    }
    return curr->totalWords();
  }

  int countWordsStartingWith(string &word) {
    // Write your code here.
    node* curr = root;
    for(int i=0;i<word[i];i++){
        if(!curr->contains(word[i])) return 0;
        curr = curr->advanceAt(word[i]);
    }
    return curr->totalPre();
  }

  void erase(string &word) {
    // Write your code here.
    node* curr = root;
    for(int i=0;i<word[i];i++){
        if(!curr->contains(word[i])) return;
        curr = curr->advanceAt(word[i]);
        curr->decresePre();
    }
    curr->decreseEnd();
  }
};
