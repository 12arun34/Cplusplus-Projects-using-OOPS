#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,w,c;
    cin>>n>>w>>c;
    
    vector<pair<int,int>>v;
    pair<int,int>p;
    
    int min;                           // min is minimum weight among all itmes 
    for(int i=0;i<n;i++)
    {
       cin>>p.first>>p.second;
        if(i==0){min=p.second;}
        else{if(min>p.second){min=p.second;}}
        v.push_back(p);
    }
    
    // int dp[w+1][c+1]={0};
    
    if(c*min > w)                                        // all cases of printing -1
    {
        cout<<"-1"<<endl;
    }
    else                                         // cases other then -1
    {
   
        
      
        int **dp;                                    // defining 2d array pointer
        dp = new int* [w+1];  
                                                  // allocating size to array pointer
        for(int i=0;i<w+1;i++)
        {
            dp[i]=new int [w+1];
        }
        for(int i=0;i<w+1;i++)
        {
            for(int j=0;j<w+1;j++)
            {
                dp[i][j]=0;
            }
        }
        
        // int dp[w+1][c+1]={0};
        
         for (int i=0; i<=w; i++)
         {
              for (int j=1; j<=c; j++)
              {
                 dp[i][j]=-2;
              }
         }
        // int count[w+1]={0};
        
        for(int k=0;k<=c;k++)
        {
            if(k<0){
               for(int i=0;i<=w;i++)
               {
                   for(int j=0;j<n;j++)
                   {
                       if(v[j].second <= i)
                       {
                           dp[i][k] = max(dp[i][k], dp[i-v[j].second][0] + v[j].first);
                       }
                   }
               }
            }
            
            
             for (int i=0; i<=w; i++)
             {
                  for (int j=0; j<n; j++)
                  {
                     if (v[j].second <= i && dp[i-v[j].second][k==0 ? 0 : k-1]!= -2)
                     {

                         if(k==0)
                         {
                            dp[i][k] = max(dp[i][k], dp[i-v[j].second][0] + v[j].first); 
                         }
                         else{
                             dp[i][k] = max(dp[i][k], dp[i-v[j].second][k-1] + v[j].first);
                         }



                     }
                  }
             }
            
         }
//         int m=0;
//         for(int i=0;i<=w;i++)
//         {
//             if(count[i]>=c)
//             {
//                 m=max(m,dp[i]);
//             }
            
//         }
 
        
        // if (dp[w][c]==-2)
        // {
        //     cout<<-1;
        // }
        // else
        // {
        //     cout<<dp[w][c];
        // }
        cout<<dp[w][c]<<endl;
    }
    
    
    return 0;
}
