#include <iostream>
#include <string>

using namespace std;

void findMaximumNum(string str, int k,string& max, int ctr)
{
    if (k == 0)
        return;
 
    int n = str.length();
 
    char maxm = str[ctr];
    for (int j = ctr + 1; j < n; j++) {
        if (maxm < str[j])
            maxm = str[j];
    }
 
    if (maxm != str[ctr])
        --k;
 
    for (int j = n-1; j >=ctr; j--) {

        if (str[j] == maxm) {
            swap(str[ctr], str[j]);

            if (str.compare(max) > 0)
                max = str;

            findMaximumNum(str, k, max, ctr + 1);
 
            swap(str[ctr], str[j]);
        }
    }
}

int main()
{
    string num;
    int k;
    cin >> num;
    cin >> k;
 
    string max = num;
    int ctr = 0;
    findMaximumNum(num, k, max, ctr);
 
    cout << max << endl;
    // cout<< ctr << endl;
 
    return 0;
}