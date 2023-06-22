#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

struct Node            //creating node for character and its frequency in given text
{

    char ch;
    int freq;
    Node *left;
    Node *right;
    Node *parent;
    int clock;                     // clock represent time 
    Node() {}
                                      //constructor for node assigning default values to its data member
    Node(char c, int f, int time) : ch(c), freq(f), clock(time) {left=NULL; right=NULL; parent = NULL;}
};

class Comparecells                     //comparecell class use by priority queue to sort elements according to priorities
{
public:
    bool operator()(Node *n2, Node *n1)          //n2 node is second node pointer insert in priority queue after n1
    {
        if (n2->freq > n1->freq)                // sorting two external nodes according to frequency
        {
            return true;
        }
        if (n2->freq == n1->freq)
        {
            if (n2->left == NULL && n2->right == NULL && n1->left == NULL && n1->right == NULL)  //sorting two external nodes having same frequency according to ascii value order
            {
                if (int(n2->ch) > int(n1->ch))
                {
                    return true;
                }
                return false;
            }
            else if (n1->left == NULL && n1->right == NULL)        //giving more priority to external node than internal node
            {
                return true;
            }
            else if (n2->left == NULL && n2->right == NULL)       //giving more priority to external node than internal node
            {
                return false;
            }
            else                                               //giving more priority to first inserted internal node among two internal node  using time
            {
                return n2->clock>n1->clock;
            }
        }
        else
        {
            return false;
        }
    }
};

int main()
{

    int n, m;
    cin >> n >> m;
    string text;
    cin >> text;
    int low = 0;
    int time=0;
    while (n > 0)                   //run for all windows 
    {
        time = 0;
        if (n >= m)                   //when window have full length 
        {

            map<char, int> map;

            for (int i = 0; i < low + m; i++)
            {
                map[text[i]]++;                            //map of key as char and value for its frequency
            }

            priority_queue<Node *, vector<Node *>, Comparecells> pq;   //declaring priority queue of Node pointer 
            vector<Node *> vec;                                      //vector of all distinct CHAR Node of window 
            for (auto itr : map)
            {

                Node *temp = new Node(itr.first, itr.second, time);
                pq.push(temp);                                        //inserting Node pointer from map in priority queue
                vec.push_back(temp);                          //inserting Node pointer from map in vector in same order
                time++;
            }

            while (pq.size() > 1)                          //do till oen element left in pq 
            {
                Node *first_node = pq.top();
                pq.pop();
                Node *second_node = pq.top();
                pq.pop();

                Node *internal = new Node((char)(255), first_node->freq + second_node->freq, time);  //generative new internal node for two least prior node pointer of priority queue which will parent of these two node 

                internal->left = first_node;
                internal->right = second_node;

                first_node->parent = internal;
                second_node->parent = internal;
                pq.push(internal);                         //inserting newly internal node in priority queue 
                time++;
            }

            Node *root = pq.top();                          //one element left in pq will we root of huffman tree
            pq.pop();

            for (int i = low; i < low + m; i++)              //searching char of new window in previous commulative text substring
            {
                Node *char_node = new Node();
                for (auto itr : vec)
                {

                    if (itr->ch == text[i])
                    {
                        char_node = itr;

                        break;
                    }
                }
                string s = "";                      //string  s will store huffman encoding for char but in reverse order 

                while (char_node->freq != root->freq)
                {

                    if (char_node->parent->left == char_node)
                    {

                        s = s + '0';
                    }
                    else
                    {

                        s = s + '1';
                    }
                    char_node = char_node->parent;
                }
                reverse(s.begin(), s.end());
                cout << s;                           //printing huffman encoded word for char 
            }
            low = low + m;

            n = n - m;
        }
        else                                    //this case of last window which will be of lesser length less than m
        {
            map<char, int> map;

            for (int i = 0; i < low + n; i++)
            {
                map[text[i]]++;                         //map of key as char and value for its frequency
            }

            priority_queue<Node *, vector<Node *>, Comparecells> pq;     //declaring priority queue of Node pointer 
            vector<Node *> vec;                                      //vector of all distinct CHAR Node of window 
            
            for (auto itr : map)
            {

                Node *temp = new Node(itr.first, itr.second, time);
                pq.push(temp);                                 //inserting Node pointer from map in priority
                vec.push_back(temp);                          //inserting Node pointer from map in vector in same order
                time++;
            }
            while (pq.size() > 1)                              //do till oen element left in pq 
            {
                Node *first_node = pq.top();
                pq.pop();
                Node *second_node = pq.top();
                pq.pop();

                Node *internal = new Node((char)(255), first_node->freq + second_node->freq, time);  //generative new internal node for two least prior node pointer of priority queue which will parent of these two node 
                internal->left = first_node;
                internal->right = second_node;

                first_node->parent = internal;
                second_node->parent = internal;
                pq.push(internal);                                    //inserting newly internal node in priority queue
                time++;
            }

            Node *root = pq.top();                            //one element left in pq will we root of huffman tree
            pq.pop();

            for (int i = low; i < low + n; i++)               //searching char of lastwindow in previous commulative text substring
            {
                Node *char_node;
                for (auto itr : vec)
                {
                    if (itr->ch == text[i])
                    {
                        char_node = itr;
                        break;
                    }
                }
                string s;                                            //string  s will store huffman encoding for char but in reverse 
                while (char_node != root)
                {
                    if (char_node->parent->left == char_node)
                    {
                        s = s + '0';
                    }
                    else
                    {
                        s = s + '1';
                    }
                    char_node = char_node->parent;
                }
                reverse(s.begin(), s.end());
                cout << s;                                       //printing huffman encoded word for char 
            }
            break;
        }
    }

    return 0;
}
