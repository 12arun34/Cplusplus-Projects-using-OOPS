#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class IntCell {
    public:
        IntCell(int initialValue=0) {
            storedValue = new int;
            *storedValue = initialValue;
        }
    
       
  		/* You may need to define copy/move constructors and assignment operators*/
        int read() {return *storedValue;}
        void write(int x) {*storedValue = x;}
    private:
        int * storedValue;
};

class Collection {
  private:
  	IntCell * arr;
  	int size;
  	/* You may need to define more members */
    int index=0;
    
  public:
  	// Constructor which initializes arr with size inpSize

  	Collection(int inpSize=10) : size(inpSize)
    {
         //cout<<size<<endl;
        arr = new IntCell[size];
        // index=inpSize;
        // size=inpSize;
       
    }
    
    //below is copy constructor for class collection
    Collection(const Collection & variable){
         arr = new IntCell[variable.size];
        for(int i=0;i<variable.size;i++){
           this->arr[i].write(variable.arr[i].read());
          //  this->arr[i]=variable->arr[i];
        }
        index=variable.index;
        size=variable.size;
    }
    
    //below is copy assignment operator for class collection
    Collection & operator=(const Collection & variable){
        arr = new IntCell[variable.size];
          for(int i=0;i<variable.size;i++){
           this->arr[i].write(variable.arr[i].read());
          //  this->arr[i]=variable->arr[i];
        }
        index=variable.index;
        size=variable.size;
        return *this;
    }
    
    
  
  	~Collection()
    {
      	delete arr;
    }
      
    void insert(IntCell x){
        if(this->index < this->size){
         arr[index].write(x.read());
        index++;
        }
        else{
            size++;
            IntCell * b;
            b= new IntCell[size];
            for(int p=0;p<size-1;p++){
                b[p].write(arr[p].read());
            }
            b[size-1].write(x.read());
              arr=b;index++;              
        }
      }
    int isEmpty(){
        if(index == 0){
            return 1;
        }
        else{
            return 0;
        }
    }
    void makeEmpty(){
       if(!isEmpty()){
           this->arr=NULL;
           index=0;
           size=0;
       } 
    }
    void remove(IntCell x){
        if(index>0){
           
            IntCell* a;
            a = new IntCell[index];int j=0;
           // cout<<"first "<<arr[0].read()<<endl;
            //cout<<"cell "<<x.read()<<endl;
            for(int i=0;i<index;i++){
                if(x.read() != arr[i].read() ){
                   // cout<<"counting "<<endl;
                    a[j].write(arr[i].read());
                    j++;
                }
            }
               
           
                for(int k=0;k<j;k++){
                    
                    arr[k].write(a[k].read());
                }
           index=j;
          delete a;

        }
    }
    
    
    int contains(IntCell y){
        if(this->index>0){
        for(int j=0;j<index;j++){
            if( arr[j].read() == y.read()){
                return 1;
            }
        }
        }
        return 0;
    }
    //You may need to define copy,move constructors, and copy/move assignment operators
      
    //Define public functions isEmpty, makeEmpty, insert, remove, contains
    //Use call-by-constant-reference wherever applicable.
};


/*DO NOT MAKE ANY CHANGES TO THE CODE BELOW*/

int main() {
  int N;
  cin >> N;
  Collection c;
  int command;
  for (int i = 0; i < N; i++)
  {
    cin >> command;
    switch (command)
    {
      case 1 /*"initialize"*/:
        {
            int inpSize;
            cin >> inpSize;
            Collection c2(inpSize);
            c = c2;
        }
        break;

       case 2 /*"initializeWith"*/:
       {
            int size2;
            cin >> size2;
            Collection c2(size2);
            for (int j = 0; j < size2; j++)
            {
              int elem;
              cin >> elem;
              IntCell elemCell(elem);
              c2.insert(elemCell);
            }
            Collection c3 = c2;
            c = c3;
            break;
       }
      case 3 /*"insert"*/:
        {
            int elem;
            cin >> elem;
            IntCell elemCell(elem);
            c.insert(elemCell);
            break;
        }
      case 4 /*"remove"*/:
       {
            int elem;
            cin >> elem;
            IntCell elemCell(elem);
            c.remove(elemCell);
            break;
       } 
      case 5 /*"copy"*/:
       {
            int size2;
            cin >> size2;
            Collection c2(size2);
            for (int j = 0; j < size2; j++)
            {
              int elem;
              cin >> elem;
              IntCell elemCell(elem);
              c2.insert(elemCell);
            }
            c = c2;
            break;
       }
      case 6 /*"isEmpty"*/:
      {
            if (c.isEmpty())
            cout << "Collection is empty" << endl;
            else
            cout << "Collection is not empty" << endl;
            break;
      }
      case 7 /*"makeEmpty"*/:
            c.makeEmpty();
            break;
      case 8 /*"contains"*/:
      {
            int elem;
            cin >> elem;
            IntCell elemCell(elem);
            if (c.contains(elemCell))
            cout << "Collection contains " << elem << endl;
            else
            cout << "Collection does not contain " << elem << endl;
            break;
      }
      default:
            cout << "Invalid command!" << endl;
    }
  }
  return 0;
}