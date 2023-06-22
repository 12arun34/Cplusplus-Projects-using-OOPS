#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
 * TODO: Implement function templates map and fold here.
 */

template <template <class, class> class Container, class ElemType, class Type, class functor_class>

auto &map(Container<ElemType, Type> &c, functor_class functor)
{
    transform(c.begin(), c.end(), c.begin(), functor); // map function using transform directly because of unary functor passing in its arguments

    return c;
                                    //    returning updated container as required
}

template <template <class, class> class Container, class ElemType, class Type, class ini_type, class functor_class>

auto fold(Container<ElemType, Type> &c, ini_type &ini, functor_class functor) // here fold funtion have binary functor in its arguments which will included unary functor inside it
{
    transform(c.begin(), c.end(), ini, functor);

    return ini;
}

// class binary_functor
// {

// };

// template<template <class, class> class Container, class ElemType, class Type , template <class, class> class Container2 ,class ini_type , class type2 , class functor_class>

// auto fold (Container<ElemType, Type> & c,ini_type ini , functor_class functor)
// {

//     transform (c.begin() , c.end() , ini.begin() , ini.begin() , functor);

//     return ini.end();
// }

class MapF0
{
public:
    int operator()(int elem)
    {
        return ++elem;
    }
};

class MapF1
{
public:
    string operator()(string elem)
    {
        return elem + "abc";
    }
};

class MapF2
{
public:
    vector<int> operator()(vector<int> elem)
    {
        elem.push_back(0);
        return elem;
    }
};

class FoldOp0
{
public:
    int operator()(int arg1, int arg2)
    {
        return arg1 * arg2;
    }
};

class FoldOp1
{
public:
    string operator()(string arg1, int arg2)
    {
        string arg3 = arg1;

        for (int i = 0; i < arg2; i++)
        {
            arg3 += arg1;
        }
        return arg3;
    }
};

class FoldOp2
{
public:
    vector<int> operator()(vector<int> arg1, vector<int> arg2)
    {
        vector<int> arg3;
        for (int i = 0; i < arg1.size(); i++)
        {
            arg3.push_back(arg1[i] + arg2[i]);
        }
        return arg3;
    }
};

class FoldOp3
{
public:
    int operator()(int arg1, int arg2)
    {
        return arg1 * arg2;
    }
};

class FoldOp4
{
public:
    int operator()(int arg1, int arg2)
    {
        return arg1 % arg2;
    }
};

int main()
{
    int choice;
    cin >> choice;
    if (choice == 0 || choice == 1)
    {
        int n;
        int typeOf;
        cin >> typeOf;

        switch (typeOf)
        {
        case 0:
        {
            int n;
            cin >> n;
            vector<int> arr(n);
            for (int i = 0; i < n; i++)
            {
                cin >> arr[i];
            }
            vector<int> &res = map(arr, MapF0());
            for (int i = 0; i < n; i++)
            {
                cout << res[i] << " ";
            }
            cout << endl;

            break;
        }

        case 1:
        {
            int n;
            cin >> n;
            vector<string> arr(n);
            for (int i = 0; i < n; i++)
            {
                cin >> arr[i];
            }
            vector<string> &res = map(arr, MapF1());
            for (int i = 0; i < n; i++)
            {
                cout << res[i] << " ";
            }
            cout << endl;

            break;
        }

        case 2:
        {
            int n;
            cin >> n;
            vector<vector<int>> arr(n, vector<int>(n));
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cin >> arr[i][j];
                }
            }
            vector<vector<int>> &res = map(arr, MapF2());
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j <= n; j++)
                {
                    cout << res[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
            break;
        }
        }
    }

    else
    {
        int typeOf;
        cin >> typeOf;

        switch (typeOf)
        {
        case 0:
        {
            int n;
            cin >> n;
            vector<int> arr(n);
            int ini;
            cin >> ini;
            for (int i = 0; i < n; i++)
            {
                cin >> arr[i];
            }

            // cout << fold(arr, ini, FoldOp0()) << endl;;
            break;
        }

        case 1:
        {
            int n;
            cin >> n;
            vector<int> arr(n);
            string ini;
            cin >> ini;
            for (int i = 0; i < n; i++)
            {
                cin >> arr[i];
            }
            // cout << fold(arr, ini, FoldOp1()) << endl;
            break;
        }

        case 2:
        {
            int n;
            cin >> n;
            vector<vector<int>> arr(n, vector<int>(n));

            vector<int> ini(n);
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cin >> arr[i][j];
                }
            }
            for (int i = 0; i < n; i++)
            {
                cin >> ini[i];
            }
            vector<int> res;

            for (int i = 0; i < res.size(); i++)
            {
                cout << res[i] << " ";
            }

            cout << endl;
        }
    }
  }
}