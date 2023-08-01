// Longest Common Subsequence

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int lcs(string &, string &, int, int);

int main()
{
    string str1 = "ABCDGH", str2 = "AEDFHR";
    std::cout << "LCS is " << lcs(str1, str2, 0, 0);
    return 0;
}

int lcs(string &a, string &b, int i, int j)
{
    if (i >= a.length() || j >= b.length())
        return 0;

    if (a[i] == b[j])
        return 1 + lcs(a, b, i + 1, j + 1);

    return max(
        lcs(a, b, i + 1, j),
        lcs(a, b, i, j + 1));
}