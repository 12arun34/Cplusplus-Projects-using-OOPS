#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int n;
    cin >> n;
    unordered_map<string, int> m1;
    map<string, int> m;

    string s;
    string s2;
    int max = 0;      // max is maximum frequency if all given string will sort
    string str;       // str string will store sorted string with maximum frequency if all given string will sort
    string str1 = ""; // str1 string will store actual input string with maximum frequency if all given string will sort
    for (int i = 0; i < n; i++)
    {

        cin >> s;
        string input_string = s;
        if (i == 0)
        { // s2 is lexicographically most prior in given set of string
            s2 = s;
        }
        else
        {
            if (s < s2)
            {
                s2 = s;
            }
        }
        m1[s]++; // m1 is unorderd map which will store all elements of actual given strings with their frequency
        sort(s.begin(), s.end());
        m[s]++; // m is map which is storing all sorted strings of input string and their frequency

        if (m[s] > max)
        {
            max = m[s];
            str = s;
            str1 = input_string;
        }
        else if (m[s] == max)
        {
            if (input_string < str1)
            {
                str = s;
                str1 = input_string;
            }
        }
    }

    if (max == 1)
    {
        cout << s2 << endl; // printing most prior string according to lexicograhically order if no pair match after rearrangement
        return 0;
    }

    string st;
    string most_prior;
    int flag = 0; // most_prior is favourable string to print
    for (auto itr : m1)
    {

        st = itr.first;

        string k = itr.first;
        sort(k.begin(), k.end());
        if (k == str && flag == 0)
        { // flag used for checking first element in map
            flag = 1;
            most_prior = st;
        }
        if (k == str)
        {
            if (most_prior > st)
            {
                most_prior = st;
            }
        }
    }
    cout << most_prior << endl;
    return 0;
}
