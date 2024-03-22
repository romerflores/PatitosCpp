#include <iostream>
#include <math.h>
#include <iomanip>
#include <list>
#include <vector>
#include <stack>
using namespace std;

bool dfs(vector<vector<int>> grafo,int ini,int obj,int tamanio)
{
    stack<int> pila;
    int vis[tamanio];
    for(int i=0;i<tamanio;i++)
    {
        vis[i]=0;
    }
    pila.push(ini);
    vis[ini]=1;
    while(!pila.empty())
    {
        int bolita=pila.top();
        pila.pop();
        for(int i=0;i<grafo[bolita].size();i++)
        {
            if(vis[grafo[bolita][i]]==0)
            {
                pila.push(grafo[bolita][i]);
                vis[grafo[bolita][i]]=1;
            }
            if(grafo[bolita][i]==obj)
            {
                return true;
            }
        }
    }
    return false;
}

int main() {

    int t;
    cin>>t;
    while(t-->0)
    {
        int n,m;
        cin>>n>>m;
        m--;
        vector<vector<int>> grafo;
        //primero se debe inicializar las listas;
        for(int i=0;i<n;i++)
        {
            vector<int> nodo;
            grafo.push_back(nodo);
        }

        for (int i = 0; i <= m; i++) {
            int v,a;
            cin>>v>>a;
            v--;
            a--;
            grafo.at(v).push_back(a);
            //cout<<"hola"<<endl;
        }
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        if(dfs(grafo,x,y,n))
        {
            cout<<"SI"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }




}