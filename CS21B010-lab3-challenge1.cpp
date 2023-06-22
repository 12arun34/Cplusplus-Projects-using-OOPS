#include <iostream>
#include <stack>
#include<vector>
using namespace std;

class Vertex {
    private:
    int vertex;
    public:
    Vertex(int v):vertex(v){}
    int get_vertex(){
        return vertex;
    }
};

class Edge {
    private:
    int vertex1;
    int vertex2;
    public:
    Edge(){}
    Edge(Vertex v1,Vertex v2):vertex1(v1.get_vertex()),vertex2(v2.get_vertex()){}
    int get1(){
        return vertex1;
    }
     int get2(){
        return vertex2;
    }
};
class Graph
{
  public:
    int numVertices;
    int numEdges;
  
  Graph(){};
    Graph(int nv, int ne) : numVertices(nv), numEdges(ne) { }
    virtual void addEdge(Edge e)=0;
    virtual int outDegree(Vertex v)=0;
    virtual int inDegree(Vertex v)=0;
    virtual bool reach(Vertex v1, Vertex v2)=0;
    virtual bool detectCycle()=0;

        
    
    
    

  /* Define virtual functions here*/ 
};



class GraphUsingMatrix : public Graph{
    private:
       bool **matrix;
    int numVertices;
    int numEdges;
    public:
    
    GraphUsingMatrix(int nv,int  ne): numVertices(nv), numEdges(ne) {matrix = new bool*[numVertices];for (int i=0; i<numVertices; i++)
                                                                                        {matrix[i] = new bool[numVertices];
                                                                                        for (int j=0; j<numVertices; j++)
                                                                                        {
                                                                                            matrix[i][j] = false;
                                                                                        }}}
    
   
    
    void addEdge(Edge e){
        matrix[e.get1()][e.get2()]=true;
    }
    
    int dfs(Vertex v1, Vertex v2,int* arr){
           if(arr[v1.get_vertex()]!=1){
                arr[v1.get_vertex()]=1;
                 if(v1.get_vertex()==v2.get_vertex()){
                   return 1;
               }
                int flag=0;
                for(int k=0;k<numVertices;k++){
                      if(matrix[v1.get_vertex()][k]==1 ){
                       flag+=dfs(Vertex(k),v2,arr);
                      }
                }
             return flag;
           }
        return 0;
      }
    
     bool reach(Vertex v1, Vertex v2){
            int *arr;
            arr=new int[numVertices];
            for(int i=0;i<numVertices;i++){
                arr[i]=0;
            }
            if(dfs(v1,v2,arr)){
                return true;
            }
            return false;
    }
    
   
    
    bool detectCycle(){
      
        int arr[numVertices]={0};
       for(int i=0;i<numVertices;i++){
           stack<Vertex>s;  bool arun;
           s.push(Vertex(i));arr[i]=1;
           
           while(!s.empty()){
               //cout<<"help"<<endl;
               int top=s.top().get_vertex();
               // s.pop();
               arun = false;
                arr[top]=1;
               for(int j=0;j<numVertices;j++){
                   if(matrix[top][j]==1&&arr[j]!=2){
                       arun = true;
                       if(arr[j]==1){
                           return 1;
                       }
                       s.push(Vertex(j));
                   }
               }
               if(arun == false){
                   s.pop();arr[top]=2;
               }
               
           }
       }
        return 0;
    }
    

    
    int outDegree(Vertex v){
         int count=0;
         for(int i=0;i<numVertices;i++){
             if(matrix[v.get_vertex()][i]==1){
                 count++;
             }
         }
         return count;
     }
    
    int inDegree(Vertex v){
        int count=0;
         for(int i=0;i<numVertices;i++){
             if(matrix[i][v.get_vertex()]==1){
                 count++;
             }
         }
         return count;
    }
    
};



class GraphUsingList : public Graph{
     vector<vector<Vertex>>list;
    int numVertices;
    int numEdges;
    public:
    
    
    GraphUsingList(int  nv,int  ne) {numVertices=nv; numEdges=ne; //cout<<"a"<<endl;
        for(int i=0;i<numVertices;i++){
            vector<Vertex>temp;
            //cout<<"b"<<endl;
            list.push_back(temp);
            //cout<<"c"<<endl;
            
        }
    }
    
    
    
    void addEdge(Edge e){
        list[e.get1()].push_back(e.get2());
    }
    
    int dfs(Vertex v1, Vertex v2,int *arr){
            if(arr[v1.get_vertex()]!=1){
                 arr[v1.get_vertex()]=1;
                 if(v1.get_vertex()==v2.get_vertex()){
                 return 1;
               }
            int flag=0;
            for(auto i : list[v1.get_vertex()]){
                flag=flag+dfs(i,v2,arr);
            }
            return flag;
          }
           return 0;
    }
    
    bool reach(Vertex v1, Vertex v2){
             int *arr;
            arr=new int[numVertices];
            for(int i=0;i<numVertices;i++){
                arr[i]=0;
            }
            if(dfs(v1,v2,arr)){
                return true;
            }
            return false;
    }
    

    
      bool detectCycle(){
      
        int arr[numVertices]={0};
       for(int i=0;i<numVertices;i++){
           stack<Vertex>s;  bool arun;
           s.push(Vertex(i));arr[i]=1;
           
           while(!s.empty()){
               //cout<<"help"<<endl;
               int top=s.top().get_vertex();
               // s.pop();
               arun = false;
                arr[top]=1;
               for(auto j : list[top]){
                   if(arr[j.get_vertex()]!=2){
                       //cout<<list[1][0].get_vertex()<<endl;
                       arun = true;
                       if(arr[j.get_vertex()]==1){
                           return 1;
                       }
                       s.push(j);
                   }
               }
               if(arun == false){
                   s.pop();arr[top]=2;
               }
               
           }
       }
        return 0;
    } 
    
    
     
     int outDegree(Vertex v){
        return list[v.get_vertex()].size();
     }
    
    int inDegree(Vertex v){
        int count=0;
        for(int i=0;i<numVertices;i++){
            for(auto j : list[i]){
                if(j.get_vertex()==v.get_vertex()){
                count++;break;
                }
            }
        }
        return count;
    }
    
};

// /Define the derived classes here/


/* DO NOT CHANGE THE CODE BELOW */
int main()
{
  int N;
  cin >> N;
  Graph * g;
  int command;
    
  const int SPARSITYRATIO = 5;
  for (int i = 0; i < N; i++)
  {
    cin >> command;
    switch (command)
    {
      case 1: /* initialize number of vertices and edges */
      {
        int nv,ne;
        cin >> nv >> ne;
        if (ne/nv > SPARSITYRATIO)
          g = new GraphUsingMatrix(nv,ne);
        else
          g = new GraphUsingList(nv,ne);
        break;
      }
      
      case 2: /* Add edge */
      {
        int v,w;
        cin >> v >> w;
        g->addEdge(Edge(Vertex(v), Vertex(w)));
        break;
      }
      
      case 3: /* Reachability query */
      {
        int v,w;
        cin >> v >> w;
        cout << g->reach(Vertex(v), Vertex(w)) << endl;
        break;
      }

      case 4: /* Detect Cycle */
      {
        cout << g->detectCycle() << endl;
        break;
      }
        
      case 5: /* In-degree */
      {
        int v;
        cin >> v;
        cout << g->inDegree(Vertex(v)) << endl;
        break;
      }

      case 6: /* Out-degree */
      {
        int v;
        cin >> v;
        cout << g->outDegree(Vertex(v)) << endl;
        break;
      }
      
      default:
        break;
    }
  }
}
