#include <iostream>
#include <vector>
#include <string>
using namespace std;

int textFitting(int width, int height, const string& text) {
    // Split the text into words
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

    int n = words.size();
    vector<vector<int>> dp(width + 1, vector<int>(height + 1, -1));

    dp[0][0] = 0;  // Base case

    for (int i = 0; i < n; i++) {
        for (int w = 0; w <= width; w++) {
            for (int h = 0; h <= height; h++) {
                // If the word can fit in the remaining width
                if (w >= words[i].size()) {
                    // Calculate the remaining space after placing the word
                    int remainingWidth = w - words[i].size();
                    
                    // Check if it can fit in the next line
                    if (h + 1 <= height) {
                        dp[remainingWidth][h + 1] = max(dp[remainingWidth][h + 1], dp[w][h] + 1);
                    }
                }
            }
        }
    }

    int maxWords = 0;
    for (int w = 0; w <= width; w++) {
        for (int h = 0; h <= height; h++) {
            maxWords = max(maxWords, dp[w][h]);
        }
    }

    return maxWords;
}

int main() {
    int width, height;
    string text;
    
    cin >> width >> height;
    cin.ignore(); // Ignore newline character
    getline(cin, text);

    int result = textFitting(width, height, text);
    cout << "Output: " << result << endl;

    return 0;
}
