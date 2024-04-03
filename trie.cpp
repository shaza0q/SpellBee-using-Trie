#include "trie.h"

Trie::Trie(){
    root = new TrieNode();
}



void Trie::insertWord(string word){
    TrieNode* curNode = root;
    for(char c: word){
        if(curNode->children[c-'a'] == NULL){
            curNode->children[c-'a'] = new TrieNode();
        }
        curNode = curNode->children[c-'a'];
    }

    curNode->isComplete = true;

}

bool Trie::searchWord(string word){
    TrieNode* curNode = root;
    for(char c: word){
        if(curNode->children[c-'a'] == NULL)return false;
        curNode = curNode->children[c-'a'];
    }

    return curNode->isComplete;
}

bool Trie::deleteWord(string word){
     TrieNode* curNode = root;
    for(char c: word){
        if(curNode->children[c-'a'] == NULL)return false;
        curNode = curNode->children[c-'a'];
    }

    curNode->isComplete = false;
    return true;
}

void Trie::updateWord(string oldWord, string newWord){
    this->deleteWord(oldWord);
    this->insertWord(newWord);
}