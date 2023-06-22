#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

struct Node
{
    struct Node *children[26];                         // node storing other 26 node pointer
    char key;                                          // key will store characrer of string
    int word_count;                                    //  workd_count is frequency of string in dna genome
    vector<int> vec;                                   // vec is vector of index of string in dna genome
};

int leaf_node(struct Node *node)                      // leaf_node  function will check a node that it is leaf node or not
{
    struct Node *temp = node;
    for (int i = 0; i < 26; i++)
    {
        if (temp->children[i] != NULL)
        {
            return 0;
        }
    }
    return 1;
}

void insert(struct Node *root, string &s, int &index, int n)              // insert function is for inserting string in trie having main root root with increasing frequency n
{
    struct Node *current = root;
    for (auto c : s)                                // inserting string character in loop for string insertion
    {
        if (current->children[int(c) - 65] != NULL)
        {
            current = current->children[int(c) - 65];
        }
        else
        {
            struct Node *new_node = new Node();
            new_node->key = c;

            current->children[int(c) - 65] = new_node;
            current = new_node;
        }
    }
    (current->word_count) += n;
    (current->vec).push_back(index);
}

struct Node *search(struct Node *root, string &s)        // search function will search a string present in trie or not
{
    struct Node *current = root;
    for (auto c : s)
    {
        if (current->children[int(c) - 65] == NULL)
        {
            return current;
        }
        current = current->children[int(c) - 65];
    }
    if (leaf_node(current) == 0)
    {
        return NULL;
    }
    return current;                 // return leaf node for  string s
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int k, n, p, Ismutated;
    cin >> k >> n >> p >> Ismutated;
    struct Node *root = new Node();             //  root will be main root for trie  containing DNA genome strings
    struct Node *root2 = new Node();           // root2 will be main root for trie containing DNA genome strings

    string s;
    int index = 0;
    for (int i = 0; i < n; i++)                 // loop will insert all genome input strings in trie
    {
        cin >> s;
        insert(root, s, index, 1);
        index++;
    }
    int freq;
    int flag = 0;
    set<int> set;                         //  set will stores indexes of matched malignant to  dna genome string
    for (int i = 0; i < p; i++)
    {
        cin >> s;
        cin >> freq;
        insert(root2, s, freq, freq);           // calling insert function to insert s in trie
        if (search(root, s) == NULL)
        {
            flag = 1;
        }
        else
        {
            if (search(root, s)->word_count < freq)
            {
                flag = 1;
            }

            for (auto &it : search(root, s)->vec)
            {
                set.insert(it);
            }
        }
    }

    if (set.size() == 0)                                // no matcing occur for malignant
    {
        cout << "No match found";
    }
    else
    {
        for (auto it = set.begin(); it != set.end(); it++)
        {
            cout << *it << " ";
        }
    }
    cout << endl;
    if (flag == 0)                        // if disease infected
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    if (Ismutated == 1)
    {                                       // mutation occuring signal
        int m;
        cin >> m;
        string s1, s2;              //  s1 is prefix to check in malignant
        flag = 0;                   // s2 is maping string to replace prefix s1 by s2

        for (int i = 0; i < m; i++)
        {
            cin >> s1 >> s2;
            if (search(root2, s1) != NULL)
            {
                struct Node *ujjayan = new Node();
                ujjayan = search(root2, s1);
                int frequency = ujjayan->word_count;
                if (search(root2, s2) != NULL)
                {
                    frequency += search(root2, s2)->word_count;
                }

                if (search(root, s2) == NULL)
                {
                    flag = 1;
                }
                else
                {
                    if (search(root, s2)->word_count < frequency)
                    {
                        flag = 1;
                    }
                    for (auto &it : search(root, s1)->vec)
                    {
                        set.erase(it);
                    }
                    for (auto &it : search(root, s2)->vec)
                    {
                        set.insert(it);
                    }
                }

                // updating trie 2 after mutation

                struct Node *prefix = search(root2, s1);
                struct Node *prefix1 = search(root2, s2);

                insert(root2, s2, i, prefix->word_count);      // updating trie to after every mutation step
                prefix = NULL;
            }
        }

        if (set.size() == 0)

        {
            cout << "No match found";
        }
        else
        {
            for (auto it = set.begin(); it != set.end(); it++)
            {
                cout << *it << " ";
            }
        }
        cout << endl;
        if (flag == 0)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}
