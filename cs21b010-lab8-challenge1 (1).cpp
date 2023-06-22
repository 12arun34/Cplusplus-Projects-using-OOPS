#include <iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<limits.h>
#include<stack>

using namespace std;

class Paragraph {
    // design your data structure here
    private : 
      int max_words , maxWidth , total_words;                    // total_words is paragraph maximum word limit
       vector<string>para;                                       // para is vector of strings of words in paragraph
     stack<pair<string, vector<string>>>history_stack;           // history_stack will consist the list of actual operations performed on graph
    stack<pair<string, vector<string>>>undo_memory;             // undo_memory consist the recently performed undo operations
    // stack<pair<string, vector<string>>>redo_memory;
    
    
    public :
    
    class undo_problem {};
    class redo_problem {};
    class para_empty {};
    class no_delete {};
    class word_limit {};
    
    void main_input()
    {
        
        cin>>max_words>>maxWidth>>total_words;
        vector<string>vec;
        string s;
         for(int i=0;i<max_words;i++)
            {
              cin>>s;
            vec.push_back(s);
            }
        if(max_words > total_words)
        {
            throw word_limit();
        }
        else
        {
            for(int i=0;i<max_words;i++)
            {
                para.push_back(vec[i]);
            }
            pair<string,vector<string> >p;
            p=make_pair("paragraph" , vec);
            history_stack.push(p);
            
        }
    }
    
    // adding word in paragraph -----------------------
    
    void add_word()                                        // function to add a word in paragraph
    {
          string temp;cin>>temp;
        if(para.size() == total_words)
        {
            throw word_limit();
        }
        else
        {
        para.push_back(temp);
        pair<string,vector<string> >p;
        vector<string>v;
        v.push_back(temp);
        p=make_pair("add_word" , v);
        
        history_stack.push(p);
        }
    }
    
    //    adding  sentence in paragraph ------------------  
    
    void add_sentence()                                      // function to add sentence in paragraph
    {
        int n;
        cin>>n;
        vector<string>v;
        string temp;
        vector<string>vec;                                  // vec is temporary vector will store words of sentence
        for(int j=0;j<n;j++)
        {
            cin>>temp;
            vec.push_back(temp);
        }
        if(para.size() + n > total_words)
        {
            throw word_limit();
        }
        else
        {
            for(int i=0;i<n;i++)
            {

                para.push_back(vec[i]);
                v.push_back(vec[i]);

            }
             pair<string,vector<string>>p;
             p = make_pair("add_sentence" , v);
            history_stack.push(p);
        }
    }
    
    //  deleting last x words from paragraph -----------------
    
    void delete_words()                                           // deleting last words of paragraph 
    {
        int x;cin>>x;
        if(x > para.size() && x!=0)
        {
            throw no_delete();                                    // exception for error of deleting words from paragraph
        }    
        else
        {
            vector<string>v;
            for(int i=0;i<x;i++)
            {
                v.push_back(para.back());
                para.pop_back();
            }
             pair<string,vector<string>>p;
            p=make_pair("delete" , v);
            history_stack.push(p);
        }
        
    }
    
    //  undo the last step of operations -------------------
    
    void undo()
    {
        if(history_stack.empty())
        {
            throw undo_problem();
        }
        else
      {
            pair<string , vector<string> > p;
            p = history_stack.top();
            history_stack.pop();
             if(p.first == "add_word")
             {
                 para.pop_back();
                 undo_memory.push(p);
             }
            else if(p.first == "add_sentence")
            {
                
                for(int i=0;i<p.second.size();i++)
                {
                    para.pop_back();
                }
                undo_memory.push(p);
            }
            else if(p.first == "paragraph")
            {
                
                for(int i=0;i<p.second.size();i++)
                {
                    para.pop_back();
                }
                undo_memory.push(p);
            }
            else
            {
                
                string temp;
                vector<string>v=p.second;
                int n=v.size();
                // cout<<"ooo "<<v.size()<<endl;
                for(int i=n-1;i>=0;i--)
                {
                    // temp=v.back();
                    temp=v[i];
                    para.push_back(temp);
                    // v.pop_back();
                }
                // cout<<"arun "<<para.size()<<endl;
                undo_memory.push(p);
            }
        }
            
     }
    
    // redo the previous undo operation ------------------
    
    void redo()
    {
        // cout<<"help1"<<endl;
        if(undo_memory.empty())
        {
            throw redo_problem();
        }
        else
        {
             pair<string , vector<string> > p;
            p = undo_memory.top();
            history_stack.push(p);
            undo_memory.pop();
            // redo_memory.push(p);
            
            // vector<string>v=p.second;
            if(p.first=="add_word" || p.first=="add_sentence" || p.first=="paragraph")
            {
                string temp;
                vector<string>v=p.second;
                for(int i=0;i<v.size();i++)
                {
                    para.push_back(v[i]);
                }
            }
            else
            {
                // cout<<"help"<<endl;
                vector<string>v=p.second;
                // cout<<"size--- "<<v.size()<<" "<<para.size()<<endl;
                for(int i=0;i<v.size();i++)
                {
                    // cout<<i<<endl;
                    para.pop_back();
                }
                // cout<<"help2"<<endl;
            }
        }
    }
    
    
   //   calaculating cost of a line in random subset of line ---------- 
    
    int calculateCost( int start, int end) {
    int totalLength = 0;
    for (int i = start; i <= end; ++i) {
        totalLength += para[i].size();
    }
    int totalSpaces = end - start;
    int remainingSpaces = maxWidth - totalLength - totalSpaces;
    if (remainingSpaces < 0) {
        return numeric_limits<int>::max();
    }
    int cost = remainingSpaces * remainingSpaces * remainingSpaces;

    return cost;
}

    
    //   printing paragraph with center justification -------- 
    
     void print()                          // print function will print the paragraph after justification with lowest badness
     {
         if(para.empty())
         {
             throw para_empty();                           // exception of printing paragrapg if it is empty
         }
         else
         {
          int n = para.size();
        vector<int> dp(n+1, numeric_limits<int>::max());
        vector<int> breakPoints(n+1, n);
        dp[n] = 0;
        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < n; ++j) {
                int cost = calculateCost( i, j);
                if (cost == numeric_limits<int>::max()) {
                    break;
                }
                int newCost = cost + dp[j+1];
                if (newCost < dp[i]) {
                    dp[i] = newCost;
                    breakPoints[i] = j+1;
                }
            }
        }
          int i = 0;
    while (i < n) {
        int j = breakPoints[i];
        int c=0;
        for(int r=i ; r<j ;r++)
        {
            c+=para[r].size();
        }
        
        for (int k = i; k < j; ++k) {
            cout << para[k];
            if (k < j-1) {
                int spaces = (maxWidth -c) / (j-i-1);
                if (k - i < (maxWidth -c - (j-i-1)) % (j-i-1)) {
                    ++spaces;
                }
                if (j==para.size()){spaces = 1;}
                for (int s = 0; s < spaces; ++s) {
                    cout << " ";
                }
            }
        }
        cout << endl;
        i = j;
    }
         }
  }
    
    // reset the memory of undo and redo --------------
    
    void reset()                                              // clearing the stack of undo operation 
    {
                  for(int i=0;i<undo_memory.size();i++)
                   {
                       undo_memory.pop();
                   }
                 
    }
   
};

int main() {
      // your driver code here
    string command;
    
    
    Paragraph P ;
    
    
    
    while(1)
    {
        try{
        cin>>command;
        if(command=="paragraph")
        {
                        
             P.main_input();
        }
        else if(command=="add_word")
        {
                   
                   P.add_word();
                   P.reset();
        }
        else if(command=="add_sentence")
        {
                     P.add_sentence();
                     P.reset();
        }
        else if(command=="delete")
        {
                  P.delete_words();
                  P.reset();
        }
        else if(command=="undo")
        {
               P.undo();
        }
        else if(command=="redo")
        {
               P.redo();
        }
        else if(command=="print")
        {
            // cout<<"help"<<endl;
                  P.print();
        }
        else if(command=="end")
        {
            break;
        }
    
     }
    
    catch(Paragraph :: undo_problem )
        
    {
        
        cout<<"UndoNotPossibleExceptionRaised"<<endl;
    }
     catch(Paragraph :: redo_problem  )
    {
         
        cout<<"RedoNotPossibleExceptionRaised"<<endl;
    }
     catch(Paragraph :: word_limit )
    {
        
        cout<<"WordLimitExceededException"<<endl;
    }
    catch(Paragraph :: para_empty )
    {
        
        cout<<"EmptyParagraphException"<<endl;
    }
    catch(Paragraph :: no_delete )
    {
         // while(1){}
        cout<<"NothingToDeleteException"<<endl;
    }
    }
    
    return 0;
}