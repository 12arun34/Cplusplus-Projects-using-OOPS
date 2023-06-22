#include<iostream>
using namespace std;

template<class Object>
class DoublyLinkedList
{
	private:
		struct Node
		{
			Object data;
			 Node *next;
			 Node *prev;
            
           // Node(): prev(NULL),next(NULL){}
            
          	Node(const Object & d = Object{ }, Node * p = nullptr, Node * n = nullptr) 
              : data(d), prev(p), next(n) {}
		};
  		
  	Node *head; //sentinel node at the beginning
	Node *rear; //sentinel node at the end
	
	public:
  
		/*TODO: Define a constructor for DoublyLinkedList here, allocating the sentinel nodes*/
    DoublyLinkedList(){
        head= new Node;
        
       rear= new Node;
      //  rear=new Node();
        head->next=rear;
        
        rear->prev=head;
    }
      
  
		class Iterator
		{
			private:
				Node *current;		
			public:
				Iterator(Node *inp) : current(inp) {}
				Object & operator*() {return current->data;}
               
				/*TODO: You can add more methods here */
            Iterator & operator++ ( )
            {
             this->current = this->current->next;
             return *this;
            }
            
            Iterator operator++(int){
                Iterator old=*this;
                ++(*this);
                return old;
            }
            
             Iterator & operator--( )
            {
             this->current = this->current->prev;
             return *this;
            }
            
            bool operator== ( const Iterator & rhs ) const
        {
             return current == rhs.current; 
        }

        bool operator!= ( const Iterator & rhs ) const
        { 
            return !( *this == rhs ); 
        }

            // Node* & read(){
            //     return current;
            // }
          
			friend class DoublyLinkedList<Object>;
		};

		Iterator begin(){return Iterator(head->next);}	
		Iterator end(){return Iterator(rear);}
		void insert(Iterator itr, Object & o){/* Implement here */
       struct Node *nod;
            nod = new Node(o);
            nod->prev=itr.current->prev;
            nod->next=itr.current;
            itr.current->prev=nod;
            nod->prev->next=nod;
            
            
        }
		void erase(Iterator itr){/* Implement here */
           itr.current->prev->next=itr.current->next;
            itr.current->next->prev=itr.current->prev;
        }
		Iterator atIndex(int p){/* Implement here */
            Iterator temp(head);
            // temp.read()=head;
             for(int i=0;i<=p;i++){
                 temp++;
             }
            // return Iterator(temp.read());
            return temp;
        }
		int indexOf(Iterator itr){/* Implement here */
          int count=0;
          for (auto it = begin(); it != end(); it++){
              if(it==itr){
                  return count;
              }
              count++;
          }
            return 0;
            
        }	
		void display()
		{			
			for (auto it = begin(); it != end(); it++)
				cout << *it << " ";
			cout << endl;
		}	
      // int indexOf()
};

int main()
{
	int N;
	cin >> N;
	DoublyLinkedList<int> dl;
	int n;
	int index;
	int command;
	for (int i = 0; i < N; i++)
	{
		cin >> command;
		switch (command)
		{
			case 1: /*insert the element at an index*/
				cin >> index;
				cin >> n;
				dl.insert(dl.atIndex(index), n);
				break;
			
			case 2: /*erase the element at an index*/
				cin >> index;
				dl.erase(dl.atIndex(index));
				break;

			case 3: /*print the head element*/
				cout << *(dl.begin()) << endl;
				break;

			case 4: /*print the rear element*/
				cout << *(--dl.end()) << endl;
				break;

			case 5: /*print the element at an index*/
				cin >> index;
				cout << *(dl.atIndex(index)) << endl;
				break;

			case 6: /*display the list*/
				dl.display();
				break;
             case 7: /*print the index of the iterator*/
                       cin >> index;
                       cout << dl.indexOf(dl.atIndex(index)) << endl;
                         break;
		}
	}
}
