// Check if the subarray with zero sum exists
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> input{4, 2, 0, 1, 6};

    int sum = 0;
    bool result = false;
    unordered_set<int> uSet;

    for (int i = 0; i < input.size(); i++)
    {
        sum += input[i];
        input[i] = sum;
        if (uSet.find(sum) != uSet.end())
        {
            result = true;
            break;
        }
        uSet.insert(sum);
    }
    if (result)
    {
        cout << "Subarray with zero sum exists";
    }
    else
    {
        cout << "Subarray with zero sum not exists";
    }
    return 0;
}