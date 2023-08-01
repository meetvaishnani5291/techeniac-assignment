// Maximum area in histogram
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int histogram(vector<int>);

int main()
{
    vector<int> input{6, 2, 5, 4, 5, 1, 6};
    std::cout << "Maximum Rectangular Area in given histogram is " << histogram(input);
    return 0;
}

int histogram(vector<int> input)
{
    stack<int> s;
    int maxArea = INT_MIN;
    int i;
    for (i = 0; i < input.size();)
    {
        if (s.empty() || input[s.top()] < input[i])
        {
            s.push(i);
            i++;
        }
        else
        {
            int rightIndex = i - 1;
            int leftIndex = s.top();
            s.pop();
            int width = s.empty() ? i : rightIndex - s.top();
            maxArea = max(maxArea, width * input[leftIndex]);
        }
    }
    while (!s.empty())
    {
        int rightIndex = i - 1;
        int leftIndex = s.top();
        s.pop();
        int width = s.empty() ? i : rightIndex - s.top();
        maxArea = max(maxArea, width * input[leftIndex]);
    }
    return maxArea;
}