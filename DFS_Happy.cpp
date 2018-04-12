//
//  main.cpp
//  ADA
//
//  Created by Nikhil Panigrahi on 11/04/18.
//  Copyright © 2018 Nikhil Panigrahi. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int>graph[1000];
int visited[100000];
int child[10000];
int parent[10000];
void dfs(int s)
{
    int count = 0;
    visited[s] = 1;
    for(int i=0;i<graph[s].size();i++)
    {
        if(visited[graph[s][i]]==0)
        {
            parent[graph[s][i]] = s;
            count++;
            child[s] = count;
            dfs(graph[s][i]);

        }
    }

}
int main()
{

    int m,n,a,b,happy=0;
    cin>>m>>n;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=0;i<n;i++)
    {
        visited[i] = 0;
        child[i] = 0;
        parent[i] = 0;
    }
    for(int i = 1; i<=n ; i++)
    {
        if(visited[i] == 0)
        {
            //parent[i] = -1;
            dfs(i);
        }

    }
    for(int i=1;i<n;i++)
    {
        if(parent[i]!=0&&child[parent[i]]<child[i])
            happy++;
    }
    cout<<happy;

}
