#include <iostream>
#include <vector>
#include <string>


using namespace std;

int main(){
    vector<string> words;
    // int COUNT_WORDS = 8;
    string lineIn, wordFormed = "";
    
    getline(cin, lineIn);
    // char character;
    for(int idx = 0; idx < lineIn.size(); idx++){
        // cout<<lineIn[idx];
        // Loop for each character, when spaces or end of line found add that to the vector
        char character = lineIn[idx];
        wordFormed += character;
        if(character == ' '){
            // cout << wordFormed;
            words.push_back(wordFormed);
            wordFormed = "";

        }
    }
    words.push_back(wordFormed);

    string lineToPrint = "";
    for(int idx = 0; idx < words.size(); idx++){
        // cout << words[idx] << words.size() << endl;
        for (auto & c: words[idx]) c = toupper(c);
        lineToPrint += words[idx];
        // lineToPrint += putchar(toupper(words[idx]));

    }
    cout << lineToPrint;

}

