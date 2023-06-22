#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Currency{
    private:
    string name;
    int n;
    float * deno;
    public:
    Currency(){}
    Currency(string s,int n,float de[]={0}):name(s),n(n){
        deno =new float[n];
        for(int i=0;i<n;i++){
            deno[i]=de[i];
        }
    }
    
    int get_size(){
        return  n;
    }
    
    string get_name(){
        return name;
    }
    
   void fun(float amount){
       // vector<int>v;
       int it=0;
       // cout<<s<<" ";
       cout<<name<<" ";
       while(it<n){
          int count=0;
           while(amount>=deno[it]){
               amount=amount-deno[it];
               count++;
           }
           // v.push_back(count);
           cout<<"("<<deno[it]<<" "<<count<<")"<<" ";
           it++;
       }
       // return v;
   }
    
    float amount(int a[]){
        float f=0;
        for(int i=0;i<n;i++){
            f=f+(a[i]*deno[i]);
        }
        return f;
    }
    
};


    


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    int num_currency;
    cin>>num_currency;
    Currency array[num_currency];
    
    for(int j=0;j<num_currency;j++){
        string s;
        cin>>s;
        int n;
        cin>>n;
     float* a;a=new float[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        Currency c(s,n,a);
        array[j]=c;
        
    }
    
    int num_rate;
    num_rate=((num_currency)*(num_currency-1))/2;
     vector <pair<int,int>> vec;
     vector<float>vec1;
    int index1;
    int index2;
    float r;
    for(int p=0;p<num_rate;p++){
    cin>>index1;
    cin>>index2;
    cin>>r;
       vec.push_back(make_pair(index1,index2));
        vec1.push_back(r);
    }
    
    int command;
    cin>>command;
    if(command==1){
      int w;
        cin>>w;
        for(int q=0;q<w;q++){
            string curr;
            cin>>curr;int t;
            for(t=0;t<num_currency;t++){
                if(array[t].get_name()==curr){
                    break;
                }
            }
            int ss=array[t].get_size();
            int * arp;
            arp =new int[ss];
            for(int rr=0;rr<ss;rr++){
                
                cin>>arp[rr];
            }
            
            // wallet w1;
            // int w1.input();
            float amount=array[t].amount(arp);
            string s2;
            cin>>s2;int t1;
            for(t1=0;t1<num_currency;t1++){
                if(array[t1].get_name()==s2){
                    break;
                }
            }
            float rat;int flag=0;
            for(int jj=0;jj<vec.size();jj++){
                if(vec[jj].first==t+1 && vec[jj].second==t1+1){
                   rat=vec1[jj];
                    break;
                }
                else if(vec[jj].first==t1+1 && vec[jj].second==t+1){
                    flag=1;
                    rat=vec1[jj];break;
                }
            }
            
            // cout<<amount<<"help "<<rat<<endl;
            if(flag==0){
            array[t1].fun(rat*amount);
            }
            else{
                array[t1].fun(amount/rat);
            }
            
            cout<<endl;
            
        }
    }
    
    else{
        cout<<"No"<<endl;
    }
    
    
    return 0;
}

