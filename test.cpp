#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<int, int> myMap;

    // Insert some key-value pairs into the unordered_map.
    myMap[42] = 7;
    myMap[7] = 3;
    myMap[42] = 7;

    // Find a key and see how many times it appears.
    int keyToFind = 42;
    if (myMap.find(keyToFind) != myMap.end()) {
        std::cout << "Key " << keyToFind << " exists, and its value is: " << myMap[keyToFind] << std::endl;
    } else {
        std::cout << "Key " << keyToFind << " does not exist in the unordered_map." << std::endl;
    }

    // Correctly count the number of occurrences of a key.
    int keyToCount = 42;
    int count = myMap.count(keyToCount);
    std::cout << "Key " << keyToCount << " appears " << count << " times." << std::endl;

    return 0;
}
