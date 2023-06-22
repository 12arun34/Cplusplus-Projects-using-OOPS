#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*Define your Wallet class here*/

class Wallet{
    private:
//     int * n2000,n500,n200,n100,n50,n20,n10,n5;
//     int * c20,c10,c5,c2,c1,c0_5,c0_25;
    // int * arr;
    // arr=int [2001];
    double* a;
    int* b;
    int count;
    public:
       // Wallet(){
       //     for(int i=0;i<`15;i++){
       //         b[i]=0;
       //     }
       // }
    Wallet ()
    {
    
       b = new int[15];
        for (int ii=0; ii<15; ii++)
        {
            b[ii]=0;
        }
        a = new double[15];
        //a[]={2000,500,200,100,50,20,10,5,20,10,5,2,1,0.5,0.25};
        a[0]=2000;
        a[1]=500;
        a[2]=200;
        a[3]=100;
        a[4]=50;
        a[5]=20;
        a[6]=10;
        a[7]=5;
        a[8]=20;
        a[9]=10;
        a[10]=5;
        a[11]=2;
        a[12]=1;
        a[13]=0.5;
        a[14]=0.25;
        
    }
    void write_place(int  index,int count){
        b[index]=count;
    }
    void write(int note,int count){
        int j;
        for(j=0;j<15;j++){
            if(a[j]==note){
                break;
            }
        }
        b[j]+=count;
    }
    int read_place(int  index){
        return b[index];
    }
    int read(int note){
        int index;
        for(int j=0;j<15;j++){
            if(a[j]==note){
                index=j;
                break;
            }
        }
       return b[index];
    }
        double read_place1(int  index){
        return a[index];
    }
    
  int & operator [] (double note_coin){
      count=0;
      for(int i=0;i<15;i++){
          if(a[i]==note_coin){
              count+=b[i];
          }
      }
      return count;
  }
    
    void operator + (Wallet w){
         for(int i=0;i<15;i++){
             b[i]+=w.read_place(i);}}
    
    void operator + (double d){ 
         for(int i=0;i<15;i++){
             if(i==13 || i==14){//cout<<d<<"help";
                 int t=d*100;
                 int n=t/(int)(100*a[i]);//cout<<t<<"help";cout<<n<<"help";
                 b[i]+=n;
                 //d=(double)((int)((t-n)/100));
             d = (double)(t - n*(50))/100;}
             
             else{
            
             int t=d;
             double f=d-(double)t;
             int n=t/(int)a[i];b[i]+=n;
             d=d - (double)n*a[i];
             }
         }
        
             
    }
        
     void operator - (Wallet w){
         for(int i=0;i<15;i++){
             b[i]-=w.read_place(i);}
    } 
         
     void operator * (Wallet w){
         
         //or(int write_place(int i,))
         double rr=0;
           for (int ik=0; ik<15; ik++)
           {
               rr+=a[ik]*b[ik];
           }
         double target_balance= rr*(double)w;
         for (int yi=0; yi<15; yi++)
         {
             b[yi]=0;
         }
         *this + target_balance;
     }    
         void operator * (double d)
         {
           double rr=0;
           for (int ik=0; ik<15; ik++)
           {
               rr+=a[ik]*b[ik];
           }
             double target_balance= rr*d;
         for (int yi=0; yi<15; yi++)
         {
             b[yi]=0;
         }
         *this + target_balance;
         }
    
    operator double () const{
        double balance=0;
    
        for(int jj=0;jj<15;jj++){ 
        balance=balance+(a[jj]*b[jj]);
      }
        return balance;
    }
};

//input overloading
istream & operator >> (istream & in, Wallet & w){
     for(int i=0;i<15;i++){
         int v;
        in >> v;
       w.write_place(i,v);
     }
    return in;
    }

//output overloading

 ostream & operator << (ostream & out, Wallet & w)
    {
        for(int jj=0;jj<5;jj++){ 
        out<<"("<<w.read_place1(jj)<<" "<<w.read_place(jj)<<") ";
      }
     int jj=5;
     out<<"("<<w.read_place1(jj)<<"n "<<w.read_place(jj)<<") ";jj++;
     out<<"("<<w.read_place1(jj)<<"n "<<w.read_place(jj)<<") ";jj++;
     out<<"("<<w.read_place1(jj)<<"n "<<w.read_place(jj)<<") ";jj++;
     out<<"("<<w.read_place1(jj)<<"c "<<w.read_place(jj)<<") ";jj++;
     out<<"("<<w.read_place1(jj)<<"c "<<w.read_place(jj)<<") ";jj++;
     out<<"("<<w.read_place1(jj)<<"c "<<w.read_place(jj)<<") ";
     
             for(int jj=11;jj<15;jj++){ 
        out<<"("<<w.read_place1(jj)<<" "<<w.read_place(jj)<<") ";
      }
     //cout<<endl;
     return out;
   }

// output operator overloading (double)
/*ostream & operator << (ostream & out,  Wallet & w)
    {
    double balance=0;
    
        for(int jj=0;jj<15;jj++){ 
        balance=balance+(a[jj]*b[jj]);
      }
     cout<<w<<endl;
     return out;
   }
*/

int main()
{
    int N;
    cin >> N;
    Wallet w,w1;
    int command;
    double d;
    for (int i = 0; i < N; i++)
    {
        cin >> command;
        switch (command)
        {
            case 1: /*initialize wallet*/
                cin >> w;
                break;
            
            case 2: /*print wallet*/
                cout << "Wallet contains: " << w << endl;
                break;
            
            case 3: /*wallet balance*/
                cout << "Wallet has balance: " << (double) w << endl;
                break;
            
            case 4: /*denomination query*/
                cin >> d;
                cout << "Wallet contains " << w[d] << " number of notes/coins of denomination " << d << endl;
                break;
            
            case 5: /*add two wallets*/
                cin >> w1;
                w + w1;
                break;
            
            case 6: /*add money to wallet*/
                cin >> d;
                w + d;
                break;

            case 7: /*subtract from wallet*/
                cin >> w1;
                w - w1;
                break;
            
            case 8: /*multiply wallets*/
                cin >> w1;
                w * w1;
                break;
            
            case 9: /*multiply wallet and double*/
                cin >> d;
                w * d;
                break;

            default:
                break;
        }
    }
}
