#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, temp,key, comp = 0, shift = 0;
    vector<int> v;
    cin >> t;
    while (t)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> key;
            v.push_back(key);
        }
        comp = 0;
        shift = 0;
        for (int i = 1; i < n; i++)
        {
            temp = v[i];
            int j = i - 1;
            while (j >= 0 && v[j] > temp)
            {
                comp++;
                v[j + 1] = v[j];
                j = j - 1;
                shift++;
            }
            shift++;
            v[j + 1] = temp;
        }
        t--;
        for (int i = 0; i < n; i++)
            cout << v[i] << "  ";
        cout << endl
             << "Comparisions = " << comp;
        cout << endl
             << "Shifts = " << shift<<endl;
        v.clear();
    }
}