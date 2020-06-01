#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<vector<int> > gp;
vector<vector<int> > go;
vector<int> color;
vector<int> order;
vector<int> component;

void dfs1(int v){
    color[v] = 1;
    for (int i = 0; i < gp[v].size(); i++)
        if (!color[gp[v][i]])
            dfs1(gp[v][i]);
    order.push_back(v);
}

void dfs2(int v){
    color[v] = 1;
    component.push_back(v);
    for (int i = 0; i < go[v].size(); i++)
        if (!color[go[v][i]])
            dfs2(go[v][i]);
}

int main(){
    cin >> n;
     gp.resize(n + 1);
      go.resize(n + 1);
     color.resize(n + 1);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            int q;
             cin >> q;
            if(q == 1){
                gp[i].push_back(j);
                 go[j].push_back(i);
            }
        }
    if(n == 1 || n == 0){
        cout << "YES";
        return 0;
    }
    int count = 0;
     for (int i = 0; i < n; i++)
        if (!color[i])
            dfs1(i);
     color.clear();
    color.resize(n + 1);
    for (int i = 0; i < n; i++){
        int v = order[n-1-i];
         if (!color[v]){
            dfs2(v);
             count++;
              component.clear();
        }
    }
    if(count == 1)
        cout << "YES";
     else
        cout << "NO";
}

