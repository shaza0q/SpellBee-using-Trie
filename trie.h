#include <iostream>
using namespace std;


struct TrieNode{
    bool isComplete = false;
    TrieNode* children[26] = {NULL};
};

class Trie{
    TrieNode* root = NULL;
    public:
        // Trie(){
        //     root = new TrieNode();

        // }

        Trie();

        void insertWord(string word);
        bool searchWord(string word);
        bool deleteWord(string word);
        void updateWord(string oldWord, string newWord);
};