#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class matrix{
  private :
    int n;                                 // size of matrix
    int ** mat;                            // 2d matrix pointer
    public :
    
    void input()                         // input function will take initial matrix input from user
    {
       cin>>n;
        mat=new int*[n];
        for(int i=0;i<n;i++)
        {
            mat[i]=new int[n];
        }
        for(int i=0;i<n;i++)          // shifting left column in clockwise manner  
        {
            for(int j=0;j<n;j++)
            {
                cin>>mat[i][j];
            }
        }
    }
    
    void rotate_clockwise(int grid)          // rotate_clockwise function will rotate the matrix grid in clockwise direction by one unit
    {
        if(grid+grid != n -1)
        {
            int x=mat[grid][grid];

            for(int j=grid;j<n-1-grid;j++)        // shifting upper row of index grid in  clockwise manner
            {
                int y=mat[grid][j+1];
                mat[grid][j+1]=x;
               x=y;
            }
            for(int i=grid ; i<n-1-grid;i++)            // shifting   right columns in clockwise manner
            {
                int y=mat[i+1][n-1-grid];
                mat[i+1][n-1-grid]=x;
                x=y;
            }
            for(int j=n-1-grid;j>grid;j--)               // shifting bottom row in clockwise manner 
            {
                int y=mat[n-1-grid][j-1];
                mat[n-1-grid][j-1]=x;
               x=y;
            }
            for(int i=n-1-grid ; i>grid;i--)            // shifting left column in clockwise manner     
            {
                int y=mat[i-1][grid];
                mat[i-1][grid]=x;
                x=y;
            }
            
        }
    }
    
    void rotate_anticlockwise(int grid)                  // rotate_anticlockwise function will rotate the matrix grid in clockwise direction by one unit
    {
        if(grid+grid != n -1)
        {
            int x=mat[grid][grid];
            
             for(int i=grid ; i<n-1-grid;i++)                  // shifting   left columns in anticlockwise manner
            {
                int y=mat[i+1][grid];
                mat[i+1][grid]=x;
                x=y;
            }

            for(int j=grid;j<n-1-grid;j++)                // shifting bottom row in anticlockwise manner
            {
                int y=mat[n-1-grid][j+1];
                mat[n-1-grid][j+1]=x;
               x=y;
            }
            
            
             for(int i=n-1-grid ; i>grid;i--)        // shifting right column in anticlockwise manner 
            {
                int y=mat[i-1][n-1-grid];
                mat[i-1][n-1-grid]=x;
                x=y;
            }
            
            for(int j=n-1-grid;j>grid;j--)           // shifting upper row of index grid in  anticlockwise manner
            {
                int y=mat[grid][j-1];
                mat[grid][j-1]=x;
               x=y;
            }
            
            
        }
    }
    
    void print()                    // print will display the updated matrix
    {
       for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<mat[i][j]<<" ";
            }
           cout<<endl;
        } 
    }
    
    
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    matrix m;
    m.input();
    int q;cin>>q;
    int gridindex,direction,k;
    for(int i=0;i<q;i++)
    {
        cin>>gridindex>>direction>>k;
        if(direction==0)                              // clockwise direction 
        {
            for(int i=0;i<k;i++)
            {
              m.rotate_clockwise(gridindex);
            }
        }
        else                                            // anticlockwise direction
        {
            for(int i=0;i<k;i++)
            {
              m.rotate_anticlockwise(gridindex);
            }
        }
    }
    
    m.print();
    
    
    return 0;
}
