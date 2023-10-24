#include <iostream>
#include <vector>
#include <string>
using namespace std;

// int dpSolution(const std::vector<int> &wordLengths, int width, int height, int size, int count)
// {
//     std::vector<int> dpArray(width + 1, 0);
//     int index = 0;
//     int spaceTaken = 0;
//     int widthIndex = 0;
//     int textCounter = 0;

//     do
//     {
//         // Handle the case where height is larger than count
//         if (height >= count)
//         {
//             int linesFit = height / count; // To calculate linesFit, its height/count
//             textCounter += linesFit;
//             dpArray[widthIndex] = textCounter;      // Use = instead of +=
//             spaceTaken = height - (height % count); // Use = instead of +=
//         }
//         else
//             spaceTaken = 0; // Reset spaceTaken if height is not >= count

//         while (wordLengths[index] <= height - spaceTaken)
//         {
//             spaceTaken += wordLengths[index] + 1; // Add the length of the word and a space
//             index++;
//             if (index == size)
//             {
//                 // The entire input has been processed, increment textCounter

//                 textCounter++;
//                 index = 0;
//                 dpArray[widthIndex] = textCounter;
//             }
//         }

//         widthIndex++;
//     } while (index != 0 && widthIndex < width);

//     int temp = widthIndex;

//     while (widthIndex < width)
//     {
//         // Calculate the repeating pattern based on temp
//         dpArray[widthIndex] = textCounter + dpArray[widthIndex - temp];

//         widthIndex++;
//     }

//     return dpArray[width - 1];
// }

// 1st sol:
// int dpSolution(const std::vector<int> &wordLengths, int width, int height, int size, int count)
// {
//     std::vector<int> dpArray(width + 1, 0);
//     int index = 0;
//     int spaceTaken = 0;
//     int widthIndex = 0;
//     int textCounter = 0;

//     while (widthIndex < width)
//     {
//         if (height >= count)
//         {
//             int linesFit = height / count;
//             textCounter += linesFit;
//             dpArray[widthIndex] = textCounter;
//             spaceTaken = height - (height % count);
//         }
//         else
//             spaceTaken = 0;

//         while (wordLengths[index] <= height - spaceTaken)
//         {
//             spaceTaken += wordLengths[index] + 1;
//             index++;
//             if (index == size)
//             {
//                 textCounter++;
//                 index = 0;
//                 dpArray[widthIndex] = textCounter;
//             }
//         }

//         widthIndex++;
//     }

//     int temp = widthIndex;

//     while (widthIndex < width)
//     {
//         dpArray[widthIndex] = textCounter + dpArray[widthIndex - temp];
//         widthIndex++;
//     }

//     return dpArray[width - 1];
// }

//2nd sol:
int dpSolution(const std::vector<int> &wordLengths, int width, int height, int size, int count)
{
    std::vector<int> dpArray(width + 1, 0);
    int index = 0;
    int spaceTaken = 0;
    int textCounter = 0;

    for (int widthIndex = 0; widthIndex < width; ++widthIndex)
    {
        if (height >= count)
        {
            int linesFit = height / count;
            textCounter += linesFit;
            dpArray[widthIndex] = textCounter;
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
                dpArray[widthIndex] = textCounter;
            }
        }
    }

    return dpArray[width - 1];
}




int main()
{
    int width, height;
    string text;

    // Read input
    cin >> width;
    cin >> height;
    cin.ignore(); // Ignore the newline character
    getline(cin, text);
    int count = text.size() + 1;

    // Split the input text into word lengths
    vector<int> wordLengths;
    size_t pos = 0;
    while ((pos = text.find(' ')) != std::string::npos)
    {
        wordLengths.push_back(pos); // Store the position of the space
        text.erase(0, pos + 1);     // Erase the word and the space
    }
    wordLengths.push_back(text.size()); // Store the length of the last word
    // cout << "Word lengths:" << endl;
    // for (int length : wordLengths)
    // {
    //     cout << length << endl;
    // }

    int size = wordLengths.size();
    // cout << "size " << size << endl;
    // cout << "count " << count << endl;

    int result = dpSolution(wordLengths, width, height, size, count);
    cout << result << endl;

    return 0;
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