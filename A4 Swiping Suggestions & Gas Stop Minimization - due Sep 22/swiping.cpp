#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const int NUMCHARS = 26;
string options[NUMCHARS];

string *words;
int numWords = 0;

// Function to check if a word exists in the dictionary
bool isWordInDictionary(const string &word) {
    int left = 0;
    int right = numWords - 1;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (words[middle] == word) {
            return true;
        }
        else if (words[middle] < word) {
            left = middle + 1;
            
        } else {
            right = middle - 1;
        }
    }
    return false;
}


// Recursive function to generate alternative words
void generateAlternativeWords(string inputWord, int index, string currentWord, vector<string> &result) {
    if (index == inputWord.length()) {
        // Check if the generated word is in the dictionary
        if (isWordInDictionary(currentWord)) {
            result.push_back(currentWord);
        }
        return;
    }

    char currentChar = inputWord[index];
    int charIndex = currentChar - 'a';

    // Consider the current character and its alternatives from options.txt
    string alternativeOptions = options[charIndex];
    for (char altChar : alternativeOptions) {
        generateAlternativeWords(inputWord, index + 1, currentWord + altChar, result);
    }
}

int main() {
    ifstream fdictionary("words.txt");

    string line;
    while (fdictionary >> line)
        numWords++;
    fdictionary.close();

    words = new string[numWords];
    fdictionary = ifstream("words.txt");
    for (int i = 0; i < numWords; i++)
        fdictionary >> words[i];
    fdictionary.close();

    ifstream foptions("options.txt");
    for (int i = 0; i < NUMCHARS; i++)
        foptions >> options[i];
    foptions.close();

    string inputWord;
    cin >> inputWord;

    vector<string> result;
    generateAlternativeWords(inputWord, 0, "", result);

    if(result.empty()) {
        cout << "None";
    } else {
        for (const string &word : result) {
            cout << word << " ";
        }
    }
    cout << endl;



    return 0;
}
