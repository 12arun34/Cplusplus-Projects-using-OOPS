#include <iostream>
#include <string>
#include <vector>

using namespace std;



template <class Key, class Value>
class Database {
public:
    class Record {
    private:
        Key k;
        Value v;

    public:
        Record(const Key &ik = Key(), const Value &iv = Value()) : k(ik), v(iv) {}
        Key &getKey() { return k; }
        Value &getValue() { return v; }
        bool operator ==(Record rhs)
        {
            return this->k == rhs.k;
        }
        friend class Database<Key, Value>;
    };

private:
template <class Object>
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
           // friend class Database<Key,Value>;
        };

        Iterator begin(){return Iterator(head->next);}    
        Iterator end(){return Iterator(rear);}
        void insert(Iterator itr, Object  o){/* Implement here */  // ????here i have removed & after object
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
              if((*it)==(*itr)){
                  return count;
              }
              count++;
          }
            
            return 0;
            
        }
    
       Iterator fun(Object  data){
         //  N* temp;
           //cout<<"Ujjayan"<<endl;
           
          Node* temp= new Node;
          temp->data = data;
          Iterator i(temp);
           int yy = indexOf(i);
           //cout<<yy<<" "<<endl;
           //cout<<(*atIndex(yy)).getKey()<<endl;
          return atIndex(yy);
      }
        void display(
        )
        {            
            for (auto it = begin(); it != end(); it++)
                cout << *it << " ";
            cout << endl;
        }    
      // int indexOf()
};
    DoublyLinkedList<Record> list;
    /*use the DoublyLinkedList class created in challenge 1*/

public:
    /*TODO: Implement the methods here*/
   Database(){}
   void insertRecord(Key & k, Value & v)
   {
       int ind=0;
       if(list.begin()==list.end()){
         list.insert(list.atIndex(ind),Record(k,v))  ;
       }
       else
           {

              int lo = 0, hi = list.indexOf(--list.end());
              // int mid;

              while (hi - lo > 1) {
                int mid = (hi + lo) / 2;
                if ((*(list.atIndex(mid))).getKey() < k) {
                    lo = mid + 1;
                }
                else {
                    hi = mid;
                }
             }
               if(k<(*(list.atIndex(lo))).getKey() )
               {
               list.insert(list.atIndex(lo),Record(k,v));
               }
               else if(k<(*(list.atIndex(hi))).getKey()){
               list.insert(list.atIndex(hi),Record(k,v));
               }
               else{
                   list.insert(list.atIndex(hi+1),Record(k,v));
               }

           }
           // cout<<(*(list.atIndex(0))).getKey()<<" ";
           // cout<<"help"<<endl;
           
      }
          
    bool isPresent(Key & k){
         // int ind=0;
       if(list.begin()==list.end()){
        // / list.insert(list.atIndex(ind),Record(k,v))  ;
           return false;
       }
       else{
      
        int lo = 0, hi = list.indexOf(--list.end());
        // int mid;
    
    while (hi - lo > 1) {
            int mid = (hi + lo) / 2;
            if ((*(list.atIndex(mid))).getKey() < k) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }
           if((*(list.atIndex(hi))).getKey() ==k)
           {
           return true;
           }
           else if((*(list.atIndex(lo))).getKey()==k){
          return true;
           }
           else{
               return false;
           }
      
       }
      }
    
    Record selectRecord(Key & k){
         int lo = 0, hi = list.indexOf(--list.end());
         // int mid;
    //cout<<"h"<<endl;
    while (hi - lo > 1) {
            int mid = (hi + lo) / 2;
            if ((*(list.atIndex(mid))).getKey() < k) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
    }
           if(k < (*(list.atIndex(hi))).getKey() )
           {
            //cout<<"arun"<<endl;
              return *(list.atIndex(lo));
           }
          
       else{
        //cout<<"arun1"<<endl;
           //cout<<(*(list.atIndex(hi))).getKey()<<endl;
           return *(list.atIndex(hi));
          }
          //cout<<"arun3"<<endl;
    }
    
    auto selectRangeRecord(Key & rangeStart, Key & rangeEnd){
    // cout<<"arun"<<endl;
         // cout<<(*(list.atIndex(0))).getKey()<<" ";
         // //  // cout<<"arun2"<<endl;
         // cout<<(*(list.atIndex(1))).getKey()<<" ";
         // cout<<(*(list.atIndex(2))).getKey()<<" ";
         // cout<<(*(list.atIndex(3))).getKey()<<" ";
         // cout<<(*(list.atIndex(4))).getKey()<<endl;
          // cout<<"arun2"<<endl;
         vector<Record>v;
         // cout<<"arun"<<endl;
         // int start;
         int lo = 0, hi = list.indexOf(--list.end()),mid;
         // int mid;
    // cout<<"arun"<<endl;
        while (hi - lo > 1) {
        // cout<<"arun1"<<endl;
            mid = (hi + lo) / 2;
            if ((*(list.atIndex(mid))).getKey()< rangeStart) {
                lo = mid + 1;
            }
            else {
                hi = mid;
             }
             
        }
        if(rangeStart < (*(list.atIndex(lo))).getKey() || rangeStart ==(*(list.atIndex(lo))).getKey() ){
           rangeStart= (*(list.atIndex(lo))).getKey();
        }
        else {
            rangeStart= (*(list.atIndex(hi))).getKey();
        }
//       finding last record  
        lo=0;hi=list.indexOf(--list.end());
         while (hi - lo > 1) {
                int mid = (hi + lo) / 2;
                if ((*(list.atIndex(mid))).getKey() < rangeEnd) {
                    lo = mid;
                }
                else {
                    hi = mid;
                }
         }
        if( rangeEnd <(*(list.atIndex(hi))).getKey() || rangeEnd ==(*(list.atIndex(lo))).getKey() ){
           rangeEnd= (*(list.atIndex(lo))).getKey();
        }
        else {
            rangeEnd= (*(list.atIndex(hi))).getKey();
        } 
        // cout<<rangeStart<<" "<<rangeEnd<<endl;
        //cout<<(selectRecord(rangeEnd)).getKey();
        //auto it = list.fun(selectRecord(rangeStart));
        //cout<<(*(list.fun(selectRecord(rangeStart)))).getKey()<<" "<<(*(list.fun(selectRecord(rangeEnd)))).getKey()<<endl;
        //++it;

        //cout<<(*it).getKey();//++it;
        //cout<<(*it).getKey();++it;*/
        // auto itt = list.fun(selectRecord(rangeStart));
        // cout<<(*itt).getKey();
        // ++itt;
        // cout<<(*itt).getKey();
        // auto z = list.fun(selectRecord(rangeEnd));
        // ++z;
        // cout<<"arun3"<<endl;
        // cout<<(*list.fun(selectRecord(rangeStart))).getKey()<<" "<<rangeEnd<<endl;
        for (auto it = list.fun(selectRecord(rangeStart)); (*it).getKey() < rangeEnd || (*it).getKey() == rangeEnd ; ++it){
        if(it==list.end()){
        break;
        }
        // cout<<"arunnn"<<endl;
        
        v.push_back(*it);
        //++it;
        // cout<<(*(it)).getKey()<<endl;
        }
        //auto itt = list.fun(selectRecord(rangeStart));
        //cout<<(*itt).getKey();++itt;
        //cout<<(*itt).getKey();++itt;
        
        
         // cout<<"arun4"<<endl;
        return v;
 
    }
    
    void updateRecord(Key & k, Value & v){
        if(isPresent(k)){
            Record r;
            r=selectRecord(k);
            (*(list.fun(r))).v=v;
        }
    }
    
    void updateRangeRecord(Key & rangeStart, Key & rangeEnd, Value & v)
    {
        vector<Record>vec;
        vec=selectRangeRecord(rangeStart,rangeEnd);
        for(auto itr :vec){
            (*(list.fun(itr))).v=v;
        }
    }
    
    void deleteRecord(Key & k){
    // cout<<"ujjayan"<<endl;
        if(isPresent(k)){
            
            list.erase(list.fun(selectRecord(k)));
        }
    }
    
    void deleteRangeRecord(Key & rangeStart, Key & rangeEnd){
        vector<Record>vec;
        vec=selectRangeRecord(rangeStart,rangeEnd);
        for(auto itr :vec){
            
            list.erase(list.fun(itr));
        }
    }
    
    Record getMinRecord(){
       return *list.begin(); 
    }
    
    Record getMaxRecord(){
       return *(--list.end()); 
    }
    
    vector<Record> getallRecords(){
        return selectRangeRecord((*list.begin()).getKey(),(*(--list.end())).getKey());
    }
    
};

class StudentsKey {
public:
    string rollNo;
    StudentsKey(const string &inp = "") : rollNo(inp) {}
    bool operator<(StudentsKey &rhs) { return rollNo < rhs.rollNo; }
    bool operator==(StudentsKey &rhs) { return rollNo == rhs.rollNo; }
    friend ostream & operator<<(ostream & out, StudentsKey &k);
};

ostream & operator<<(ostream & out, StudentsKey &k) { 
    out << k.rollNo;
      return out;
}

class StudentsValue {
public:
    string name;
    string hostel;
    float cgpa;
    StudentsValue(const string &n = "", const string &h = "", float c = 10.0) : name(n), hostel(h), cgpa(c) {}
    friend ostream & operator<<(ostream & out, StudentsValue &v);
};

ostream & operator<<(std::ostream & out, StudentsValue &v) {
    out << v.name << " " << v.hostel << " " << v.cgpa;
    return out;
}

class FacultyKey {
public:
    string empId;
    FacultyKey(const string &inp = "") : empId(inp) {}
    
    bool operator<(FacultyKey &rhs) { return empId < rhs.empId; }
     bool operator==(FacultyKey &rhs) { return empId == rhs.empId; }
    friend ostream & operator<<(ostream & out, FacultyKey &k);
};

ostream & operator<<(ostream & out, FacultyKey &k) { 
    out << k.empId;
     return out;
}

class FacultyValue {
public:
    string name;
    string designation;
    float salary;
    FacultyValue(const string &n = "", const string &d = "", float s = 10.0) : name(n), designation(d), salary(s) {}
    friend ostream & operator<<(ostream & out, FacultyValue &v);
};

ostream & operator<<(std::ostream & out, FacultyValue &v) {
    out << v.name << " " << v.designation << " " << v.salary;
    return out;
}

class CourseKey {
public:
    string courseId;
    CourseKey(const string &inp = "") : courseId(inp) {}
    bool operator<(CourseKey &rhs) { return courseId < rhs.courseId; }
    bool operator==(CourseKey &rhs) { return courseId == rhs.courseId;}
    friend ostream & operator<<(ostream & out, CourseKey &k);
};

ostream & operator<<(ostream & out, CourseKey &k) { 
    out << k.courseId;
    return out;
}

class CourseValue {
public:
    string name;
    string semester;
    string facultyName;
    CourseValue(const string &n = "", const string &s = "", const string &f = "") : name(n), semester(s), facultyName(f) {}
    friend ostream & operator<<(ostream & out, FacultyValue &v);
};

ostream & operator<<(std::ostream & out, CourseValue &v) {
    out << v.name << " " << v.semester << " " << v.facultyName;
    return out;
}

int main() {
    int command;
    bool b;
    int BREAKING_COMMAND = 50;

    Database<StudentsKey, StudentsValue> student_db;
    Database<FacultyKey, FacultyValue> faculty_db;
    Database<CourseKey, CourseValue> course_db;

    while (true) {
        cin >> command;
        if (command == BREAKING_COMMAND) {
            break;
        }

        if (command == 1) { /*insert record*/
            int numberOfRecords = 0; /*number of records to be inserted*/
            cin >> numberOfRecords;

            while (numberOfRecords--) {

                string database;
                cin >> database;

                if (database == "STUDENT") {
                    string rollNo, name, hostel;
                    float cgpa;
                    cin >> rollNo >> name >> hostel >> cgpa;

                    StudentsKey k(rollNo);
                    StudentsValue v(name, hostel, cgpa);
                    student_db.insertRecord(k, v);
                } else if (database == "FACULTY") {
                    string empId, name, designation;
                    float salary;
                    cin >> empId >> name >> designation >> salary;

                    FacultyKey k(empId);
                    FacultyValue v(name, designation, salary);
                    faculty_db.insertRecord(k, v);
                } else {
                    string courseId, name, semester, facultyName;
                    cin >> courseId >> name >> semester >> facultyName;

                    CourseKey k(courseId);
                    CourseValue v(name, semester, facultyName);
                    course_db.insertRecord(k, v);
                }
            }

        } else if (command == 2) { /*check whether the key is present*/
            string database;
            cin >> database;

            if (database == "STUDENT") {
                string rollNo;
                cin >> rollNo;

                StudentsKey k(rollNo);
                b = student_db.isPresent(k);
                cout << b << endl;
            } else if (database == "FACULTY") {
                string empId;
                cin >> empId;

                FacultyKey k(empId);
                b = faculty_db.isPresent(k);
                cout << b << endl;
            } else {
                string courseId;
                cin >> courseId;

                CourseKey k(courseId);
                b = course_db.isPresent(k);
                cout << b << endl;
            }

        } else if (command == 3) {
            string database; /*returns the record containing the key*/
            cin >> database;

            if (database == "STUDENT") {
                string rollNo;
                cin >> rollNo;

                StudentsKey k(rollNo);
                auto r = student_db.selectRecord(k);
                cout << r.getKey() << " " << r.getValue() << endl;
            } else if (database == "FACULTY") {
                string empId;
                cin >> empId;

                FacultyKey k(empId);
                auto r = faculty_db.selectRecord(k);
                cout << r.getKey() << " " << r.getValue() << endl;
            } else {
                string courseId;
                cin >> courseId;

                CourseKey k(courseId);
                auto r = course_db.selectRecord(k);
                cout << r.getKey() << " " << r.getValue() << endl;
            }

        } else if (command == 4) { /*returns a vector containing all the records in the database
                                     whose key lies between rangeStart and rangeEnd (inclusive).*/
            string database;
            cin >> database;
            if (database == "STUDENT") {
                string rangeStart, rangeEnd;
                cin >> rangeStart >> rangeEnd;

                StudentsKey rs(rangeStart);
                StudentsKey re(rangeEnd);
                auto lst = student_db.selectRangeRecord(rs, re);
                for (auto r : lst) {
                    cout << r.getKey() << " " << r.getValue() << endl;
                }
            } else if (database == "FACULTY") {
                string rangeStart, rangeEnd;
                cin >> rangeStart >> rangeEnd;

                FacultyKey rs(rangeStart);
                FacultyKey re(rangeEnd);
                auto lst = faculty_db.selectRangeRecord(rs, re);
                for (auto r : lst) {
                    cout << r.getKey() << " " << r.getValue() << endl;
                }
            } else {
                string rangeStart, rangeEnd;
                cin >> rangeStart >> rangeEnd;

                CourseKey rs(rangeStart);
                CourseKey re(rangeEnd);
                auto lst = course_db.selectRangeRecord(rs, re);
                for (auto r : lst) {
                    cout << r.getKey() << " " << r.getValue() << endl;
                }
            }

        } else if (command == 5) { /*updates the record in the database whose key is k with value v.
                                     If k is not present, there is no change in the database.*/
            string database;
            cin >> database;

            if (database == "STUDENT") {
                string rollNo, name, hostel;
                float cgpa;
                cin >> rollNo >> name >> hostel >> cgpa;

                StudentsKey k(rollNo);
                StudentsValue v(name, hostel, cgpa);
                student_db.updateRecord(k, v);
            } else if (database == "FACULTY") {
                string empId, name, designation;
                float salary;
                cin >> empId >> name >> designation >> salary;

                FacultyKey k(empId);
                FacultyValue v(name, designation, salary);
                faculty_db.updateRecord(k, v);
            } else {
                string courseId, name, semester, facultyName;
                cin >> courseId >> name >> semester >> facultyName;

                CourseKey k(courseId);
                CourseValue v(name, semester, facultyName);
                course_db.updateRecord(k, v);
            }

        } else if (command == 6) { /*updates all records in the database whose key lies between
                                     rangeStart and rangeEnd, with value v (inclusive).*/
            string database;
            cin >> database;

            if (database == "STUDENT") {
                string rangeStart, rangeEnd, name, hostel;
                float cgpa;
                cin >> rangeStart >> rangeEnd >> name >> hostel >> cgpa;

                StudentsKey rs(rangeStart);
                StudentsKey re(rangeEnd);
                StudentsValue v(name, hostel, cgpa);
                student_db.updateRangeRecord(rs, re, v);
            } else if (database == "FACULTY") {
                string rangeStart, rangeEnd, name, designation;
                float salary;
                cin >> rangeStart >> rangeEnd >> name >> designation >> salary;

                FacultyKey rs(rangeStart);
                FacultyKey re(rangeEnd);
                FacultyValue v(name, designation, salary);
                faculty_db.updateRangeRecord(rs, re, v);
            } else {
                string rangeStart, rangeEnd, name, semester, facultyName;
                cin >> rangeStart >> rangeEnd >> name >> semester >> facultyName;

                CourseKey rs(rangeStart);
                CourseKey re(rangeEnd);
                CourseValue v(name, semester, facultyName);
                course_db.updateRangeRecord(rs, re, v);
            }

        } else if (command == 7) { /*deletes the record with key k.*/
            string database;
            cin >> database;

            if (database == "STUDENT") {
                string rollNo;
                cin >> rollNo;

                StudentsKey k(rollNo);
                student_db.deleteRecord(k);
            } else if (database == "FACULTY") {
                string empId;
                cin >> empId;

                FacultyKey k(empId);
                faculty_db.deleteRecord(k);
            } else {
                string courseId;
                cin >> courseId;

                CourseKey k(courseId);
                course_db.deleteRecord(k);
            }

        } else if (command == 8) { /*deletes all records with key between rangeStart and rangeEnd (inclusive).*/
            string database;
            cin >> database;

            if (database == "STUDENT") {
                string rangeStart, rangeEnd;
                cin >> rangeStart >> rangeEnd;

                StudentsKey rs(rangeStart);
                StudentsKey re(rangeEnd);
                student_db.deleteRangeRecord(rs, re);
            } else if (database == "FACULTY") {
                string rangeStart, rangeEnd;
                cin >> rangeStart >> rangeEnd;

                FacultyKey rs(rangeStart);
                FacultyKey re(rangeEnd);
                faculty_db.deleteRangeRecord(rs, re);
            } else {
                string rangeStart, rangeEnd;
                cin >> rangeStart >> rangeEnd;

                CourseKey rs(rangeStart);
                CourseKey re(rangeEnd);
                course_db.deleteRangeRecord(rs, re);
            }

        } else if (command == 9) { /*return the minimum record*/
            string database;
            cin >> database;

            if (database == "STUDENT") {
                auto r = student_db.getMinRecord();
                cout << r.getKey() << " " << r.getValue() << endl;
            } else if (database == "FACULTY") {
                auto r = faculty_db.getMinRecord();
                cout << r.getKey() << " " << r.getValue() << endl;
            } else {
                auto r = course_db.getMinRecord();
                cout << r.getKey() << " " << r.getValue() << endl;
            }

        } else if (command == 10) { /*return the maximum record*/
            string database;
            cin >> database;

            if (database == "STUDENT") {
                auto r = student_db.getMaxRecord();
                cout << r.getKey() << " " << r.getValue() << endl;
            } else if (database == "FACULTY") {
                auto r = faculty_db.getMaxRecord();
                cout << r.getKey() << " " << r.getValue() << endl;
            } else {
                auto r = course_db.getMaxRecord();
                cout << r.getKey() << " " << r.getValue() << endl;
            }

        } else if (command == 11) { /*returns a vector containing all the records in the database.*/
            string database;
            cin >> database;

            if (database == "STUDENT") {
                auto lst = student_db.getallRecords();
                for (auto r : lst) {
                    cout << r.getKey() << " " << r.getValue() << endl;
                }
            } else if (database == "FACULTY") {
                auto lst = faculty_db.getallRecords();
                for (auto r : lst) {
                    cout << r.getKey() << " " << r.getValue() << endl;
                }
            } else {
                auto lst = course_db.getallRecords();
                for (auto r : lst) {
                    cout << r.getKey() << " " << r.getValue() << endl;
                }
            }

        } else {
            cout << "INVALID COMMAND!" << endl;
            break;
        }
    }
}
