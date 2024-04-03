#include <bits/stdc++.h>
#include "trie.h"
#include <iomanip>
#define UNDERLINE_ON "\033[4m"
#define UNDERLINE_OFF "\033[0m"
#define RED_ON "[41m"
#define RED_OFF "[0m"
#define GREEN_ON "[32m"
#define GREEN_OFF "[0m"
#define YELLOW "[33m"
#define BLUE "[34m"
#define CYAN "[36m"
#define MAGENTA "[35m"
#define REDBG "[41m"
#define CLEAR "\033[2J"
#define FONT24 "\033[18;24m"
#define OFF "\033[0m"

// g++ spell-checker.cpp trie.cpp -o spell-checker
// .\spell-checker

using namespace std;


int main(){

    Trie oTrie;
    vector<string> words;

    ifstream inputFile("dictionary.txt");

    string word;
    while(inputFile>>word){
        words.push_back(word);
    }

    inputFile.close();

    for(string word: words){
        oTrie.insertWord(word);
    }

    vector<string> nword = {"poornima", "ganguly", "mohd", "arslaan", "pooja"};

    for(string word: nword){
        oTrie.insertWord(word);
    }   

    cout<<CLEAR;

    cout<<"\t\t\t\t\t\t"<<YELLOW<<"Spell bee game"<<OFF<<"\n\n\n";

    int i=0;
    int score = 0;

    vector<string> strArr={};

    while(i<5){
        cout<<"\t\t\t\t"<<setw(20)<<"Enter the word "<<i+1<<": ";

        string s="";
        cin>>s;

        strArr.push_back(s);
        
        // while(char c=getchar()){
        //     if(c == '\n'){
        //         oTrie.searchWord(s)?cout<<GREEN_ON<<s<<GREEN_OFF : cout<<RED_ON<<s<<RED_OFF;
        //         break;
        //     }else if(c == ' '){
        //         oTrie.searchWord(s)?cout<<GREEN_ON<<s<<GREEN_OFF : cout<<RED_ON<<s<<RED_OFF;
        //         s = "";
        //         cout << c;
        //     }else{
        //         s += c;
        //     }
        // }

        i++;
    }

    for(auto i: strArr){
        if(oTrie.searchWord(i) == true){
            score+=2;
            cout<<"\t\t\t\t\t\t"<<GREEN_ON<<i<<GREEN_OFF<<endl;
        }
        else{
            cout<<"\t\t\t\t\t\t"<<RED_ON<<i<<RED_OFF<<endl;
        }
    }

    cout<<"\n\t\t\t\t\tFinal score: "<<score<<endl;
    if(score > 4)cout<<BLUE<<"\n\n\t\t\t\t\tExcellent work !!"<<OFF;
    else if(score < 3)cout<<CYAN<<"\n\n\t\t\t\t\tBetter Luck next time"<<OFF;
    else{
        cout<<MAGENTA<<"\n\n\t\t\t\t\tWork harder"<<OFF;
    }
    // slightly_smiling_face:
    // :sign_of_the_horns:
    return 0;
}
