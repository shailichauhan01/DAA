#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> array, int start, int end, int key)
{
    if (start <= end)
    {
        int mid = (start + (end - start) / 2);
        if (array[mid] == key)
            return mid;
        if (array[mid] > key)
            return binarySearch(array, start, mid - 1, key);
        return binarySearch(array, mid + 1, end, key);
    }
    return -1;
}

int exponentialSearch(vector<int> array, int start, int end, int key)
{
    if(array[0]==key)
    return 0;
    if ((end - start) <= 0)
        return -1;
    int i = 1;
    while (i < (end - start))
    {
        if (array[i] < key)
            i *= 2;
        else
            break;
    }
    return binarySearch(array, i / 2, min(i,end-1), key);
}

int main()
{
    int n, data, loc, t, temp;
    vector<int> v;
    cin >> t;
    while (t)
    {
        loc = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            v.push_back(temp);
        }
        cin >> data;
        loc = exponentialSearch(v, 0, n, data);
        if (loc >= 0)
            cout << "\nPresent " << loc;
        else
            cout << "\nNot Present ";
        t--;
        v.clear();
    }
}