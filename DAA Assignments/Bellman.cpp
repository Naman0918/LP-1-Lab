#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge
{
    int src;
    int wt;
    int dst;
};
int V, E;

void sort(vector<edge> &Edge)
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V - 1; j++)
        {
            if (Edge[j].src > Edge[j + 1].src)
            {
                swap(Edge[j], Edge[j + 1]);
            }
        }
    }
}

void bellman(vector<edge> &Edge)
{
    int parent[V];
    vector<int> Values(V, INT_MAX);
    Values[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int src = Edge[j].src;
            int wt = Edge[j].wt;
            int dst = Edge[j].dst;
            if (Values[src] != INT_MAX && Values[src] + wt < Values[dst])
            {
                Values[dst] = Values[src] + wt;
                parent[dst] = src;
            }
        }
    }
    for (int j = 0; j < E; j++)
        {
            int src = Edge[j].src;
            int wt = Edge[j].wt;
            int dst = Edge[j].dst;
            if (Values[src] != INT_MAX && Values[src] + wt < Values[dst])
            {
                cout<<"Negative edge cycle found"<<endl;
            }
        }

    for(int i = 1; i<V; i++){
        vector<int> v;
        int a = i;
        while (parent[a] !=0)
        {
            v.push_back(a);
            a = parent[a];
        }
        v.push_back(a);
        cout<<"Flow from 0 to "<< i <<" is 0 ";
        for(int j = v.size()-1;j>=0; j-- ){
            cout<<v[j]<<" ";
        }
        cout<<endl;
        
    }
}

int main(){
    cout<<"Enter vertices : ";
    cin>>V;
    cout<<"Enter Edges : ";
    cin>>E;

    vector<edge> Edge(E);
    int src, dst, wt;
    for(int i = 0; i<E; i++){
        cout << "Enter src,dst,wt : " << endl;
        cin >> src >> dst >> wt;
        Edge[i].src = src;
        Edge[i].dst =dst;
        Edge[i].wt = wt;
    }
    sort(Edge);
    bellman(Edge);
    return 0;


}