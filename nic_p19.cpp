#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int pointsCounter(vector<int> arr1, vector<int> arr2)
{
    int index = 0, score = 0, finalScore = 0;

    while (index < arr2.size())
    {
        while (score < arr1.size() and arr2[index] > arr1[score])
        {
            score++;
        }
        finalScore += score;
        index++;
    }
    return finalScore;
}

void merge(vector<int> &arr1, vector<int> &arr2, int left, int mid, int right, int &points1, int &points2)
{

    int mid1 = mid - left + 1, mid2 = right - mid, i1 = 0, i2 = 0, j1 = 0, j2 = 0, k1 = left, k2 = left;

    vector<int> leftArr1(mid1), rightArr1(mid2), leftArr2(mid1), rightArr2(mid2);

    for (int i = 0; i < mid1; i++)
    {
        leftArr1[i] = arr1[left + i];
        leftArr2[i] = arr2[left + i];
    }

    for (int j = 0; j < mid2; j++)
    {
        rightArr1[j] = arr1[mid + 1 + j];
        rightArr2[j] = arr2[mid + 1 + j];
    }

    points1 += pointsCounter(leftArr2, rightArr1);
    points2 += pointsCounter(leftArr1, rightArr2);

    while (i1 < mid1 && j1 < mid2)
    {
        if (leftArr1[i1] <= rightArr1[j1])
        {
            arr1[k1] = leftArr1[i1++];
        }
        else
        {
            arr1[k1] = rightArr1[j1++];
        }
        k1++;
    }

    while (i1 < mid1)
    {
        arr1[k1++] = leftArr1[i1++];
    }

    while (j1 < mid2)
    {
        arr1[k1++] = rightArr1[j1++];
    }

    while (i2 < mid1 && j2 < mid2)
    {
        if (leftArr2[i2] <= rightArr2[j2])
        {
            arr2[k2] = leftArr2[i2++];
        }
        else
        {
            arr2[k2] = rightArr2[j2++];
        }
        k2++;
    }

    while (i2 < mid1)
    {
        arr2[k2++] = leftArr2[i2++];
    }

    while (j2 < mid2)
    {
        arr2[k2++] = rightArr2[j2++];
    }
}

void mergeSort(vector<int> &arr1, vector<int> &arr2, int left, int right, int &points1, int &points2)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr1, arr2, left, mid, points1, points2);
        mergeSort(arr1, arr2, mid + 1, right, points1, points2);

        merge(arr1, arr2, left, mid, right, points1, points2);
    }
}

int main()
{
    vector<int> arr1, arr2;
    string tempS;
    int tempI, points1 = 0, points2 = 0;
    stringstream ss;

    getline(cin, tempS);
    ss << tempS;
    while (ss >> tempI)
    {
        arr1.push_back(tempI);
    }

    ss.clear();

    getline(cin, tempS);
    ss << tempS;
    while (ss >> tempI)
    {
        arr2.push_back(tempI);
    }


    
    mergeSort(arr1, arr2, 0, arr1.size() - 1, points1, points2);
    cout << points1 << " " << points2;
}