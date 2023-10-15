#include <iostream>
#include <vector>
#include <string>
using namespace std;

int textFitting(int width, int height, const string& text) {
    // Split the text into words (a vector stores all the words)
    vector<string> words;
    string word = "";
    for (char c : text) {
        if (c == ' ') {
            words.push_back(word);
            word = "";
        } else {
            word += c;
        }
    }
    words.push_back(word);

    vector<string> wordsStep;
    
    int n = words.size();

    //so now count how many words you can store in an array, use math, and store what words was used at that level
    //then count how many times they occur, and then return the least

    // for(int i = 0; i < width ; i++){//vertical steps
    //     int line_Width = 0 ; //to be used for managing line width with in a line
    //     while(line_Width <= width){
            
    //     }
    // }

    int text_size = 0;
    for(int i=0; i<n;i++){
        text_size += (words[i].length() + 1);
    }
    // cout<<text_size<<"this is text size"<<endl;

    int matrixSize = height*width;
    int result = matrixSize/text_size;

    return result;
}

int main() {
    int width, height;
    string text;
    
    cin >> width >> height;
    cin.ignore(); // Ignore newline character
    getline(cin, text);

    int result = textFitting(width, height, text);
    cout << result << endl;

    return 0;
}
