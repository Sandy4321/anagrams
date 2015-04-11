#include <iostream>
#include <fstream>
#include <algorithm>
#include <unordered_map>
#include <set>

using namespace std;

int main(int argc, char *argv[]){
    char *fileName = argv[1];
    ifstream infile(fileName);
    // map from sorted anagram characters to strings containing characters
    unordered_map<string, vector<string>> wordMap;

    // list of characters corresponding to anagram
    set<string> anagramSet;
    string word;
    string sortedWord;
    while (infile >> word){
        string sortedWord = word;
        sort(sortedWord.begin(), sortedWord.end());
        vector<string>& wordVec = wordMap[sortedWord];
        wordVec.push_back(word);
        if (word.size() >= 4 && wordMap[sortedWord].size()> word.size()){
            anagramSet.insert(sortedWord);
        }

    }

    for (auto it = anagramSet.begin(); it != anagramSet.end(); ++it){
        string curAnagram = *it;
        vector<string>& wordVec = wordMap[curAnagram];
        for (auto curWord : wordVec){
            cout << curWord << " ";
        }
        cout << endl;
    }
    
    

}
