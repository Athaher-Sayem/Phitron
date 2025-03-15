#include <bits/stdc++.h>
using namespace std;

class Edge{

    public:
        int a,b,c;
        Edge(int a, int b, int c){
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

int dis[1005];
vector<Edge> edge_list;
int n,e;
bool flag=false;
void bellman_ford(int source)
{
    for (int i=0;i<=n;i++){
        dis[i]=INT_MAX;
    }
   
        dis[source]=0;
    
    for (int i=1;i<=n-1;i++)
    {
        for (auto ed : edge_list)
        {
            int a,b,c;
            a =ed.a;
            b =ed.b;
            c =ed.c;
            if (dis[a]!=INT_MAX && dis[a]+c<dis[b])
                dis[b]=dis[a]+c;
        }
    }

    for(auto ed :edge_list)
    {
        int a,b,c;
        a=ed.a;
        b=ed.b;
        c=ed.c;
        if(dis[a]!=INT_MAX && dis[a]+c<dis[b])
        {
            flag = true;
            return;
        }
    }
}

int main()
{
    cin>>n>>e;
    while(e--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edge_list.push_back(Edge(a,b,c));
    }
    
    int source;
    cin>>source;
    
    bellman_ford(source);
    
    int t;
    cin>>t;
    if(flag==true) {
        cout<<"Negative Cycle Detected"<<endl;
        return 0;
    }

    while(t--)
    {
        int dest;
        cin>>dest;
        if (dis[dest] == INT_MAX)
            cout<<"Not Possible"<<endl;
        else
            cout<<dis[dest]<<endl;
    }
    
    return 0;
}
