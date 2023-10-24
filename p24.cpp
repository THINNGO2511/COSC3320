#include <iostream>
#include <vector>
#include <string>
using namespace std;

// PSID: 2053907
// Submission ID: ba951739-11a0-44e7-bc30-4cf0671addb8 

int textFitting(const vector<int> &wordLengths, int width, int height, int size, int count)
{
    vector<int> arr(width + 1, 0);
    int index = 0;
    int spaceTaken = 0;
    int textCounter = 0;

    for (int widthIndex = 0; widthIndex < width; ++widthIndex)
    {
        if (height >= count)
        {
            int linesFit = height / count;
            textCounter += linesFit;
            arr[widthIndex] = textCounter;
            spaceTaken = height - (height % count);
        }
        else
            spaceTaken = 0;

        while (wordLengths[index] <= height - spaceTaken)
        {
            spaceTaken += wordLengths[index] + 1;
            index = (index + 1) % size;
            if (index == 0)
            {
                textCounter++;
                arr[widthIndex] = textCounter;
            }
        }
    }

    return arr[width - 1];
}

int main() {
    int width, height;
    string text;
    
    cin >> width >> height;
    cin.ignore(); // Ignore newline character
    getline(cin, text);
    int count = text.size() + 1;

    vector<int> wordLengths;
    size_t pos = 0;
    while ((pos = text.find(' ')) != std::string::npos)
    {
        wordLengths.push_back(pos); 
        text.erase(0, pos + 1);     
    }
    wordLengths.push_back(text.size()); 

    int size = wordLengths.size();

    int result = textFitting(wordLengths, width, height, size, count);
    cout << result << endl;

    return 0;
}
