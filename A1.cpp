#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
        map<int,bool> visited;
        map<int,list<int> > adjList;
        queue<int> q;

        void addEdge(int v,int w){
            adjList[v].push_back(w);
        }

        //recursive DFS
        void DFSR(int v){
            visited[v]=true;
            cout<<v<<" ";
            list<int> l=adjList[v];
            for(auto ele: l){
                if(!visited[ele]){
                    DFSR(ele);
                }
            }
        }


        //recursive BFS
        void BFSR_helper(){
            if(q.empty()){
                return;
            }
            int v=q.front();
            q.pop();
            cout<<v<<" ";
            for(int u:adjList[v]){
                if(!visited[u]){
                    visited[u]=true;
                    q.push(u);
                }
            }
            BFSR_helper();
        }
        void BFSR(){
            for(int i=0;i<adjList.size();i++){
                if(!visited[i]){
                    visited[i]=true;
                    q.push(i);
                    BFSR_helper();
                }
            }
        }

        //iterative BFS
        void BFS(int v){
            queue<int> q;
            q.push(v);
            visited[v]=true;

            while(q.size()){
                int ele=q.front();
                cout<<ele<<" ";
                q.pop();

                list<int> l=adjList[ele];
                for(int a: l){
                    if(!visited[a]){
                        q.push(a);
                        visited[a]=true;
                    }
                }
            }
        }

        //iterative DFS
        void DFS(int v){
            stack<int> st;
            st.push(v);

            while(!st.empty()){
                int v=st.top();
                st.pop();
                if(!visited[v]){
                    cout<<v<<" ";
                    visited[v]=true;
                }
                list<int> l=adjList[v];
                for(int a:l){
                    if(!visited[a]){
                        st.push(a);
                    }
                }
            }
        }

};

int main(){
    Graph g;
    int v,e;
    cout<<"Enter total number of vertices and edges: ";
    cin>>v>>e;
    for(int i=0;i<e;i++){
        int u,v;
        cout<<"Enter edges between the vertices(u,v): ";
        cin>>u>>v;
        g.addEdge(u,v);
        g.addEdge(v,u);
    }
    
    while(true){
        int choice;
        cout<<"********MENU*******\n";
        cout<<" 1.BFS Iterative\n 2.BFS Recursive\n 3.DFS Recursive\n 4.DFS Iterative\n 5.Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        if(choice==1){
            int start;
            cout<<"Enter starting vertex: ";
            cin>>start;
            cout<<"BFS iterative traversal of graph: ";
            g.BFS(start);
            cout<<endl;
            g.visited.clear();
        }
        else if(choice==2){
            int start;
            cout<<"BFS recursive traversal of graph: ";
            g.BFSR();
            cout<<endl;
            g.visited.clear();
        }
        else if(choice==3){
            int start;
            cout<<"Enter starting vertex: ";
            cin>>start;
            cout<<"DFS recursive traversal of graph: ";
            g.DFSR(start);
            cout<<endl;
            g.visited.clear();
        }
        else if(choice==4){
            int start;
            cout<<"Enter starting vertex: ";
            cin>>start;
            cout<<"DFS iterative traversal of graph: ";
            g.DFS(start);
            cout<<endl;
            g.visited.clear();
        }
        else if(choice==5){
            break;
        }
        else{
            cout<<"Please enter valid choice!";
        }
    }
    
    return 0;
}