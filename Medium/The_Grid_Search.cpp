#include <iostream>
#include <cstring>
#include <bits/stdc++.h>

using namespace std;

// C++的string可以當作字元陣列透過[]操作字元
// Complete the gridSearch function below.
string gridSearch(vector<string> G, vector<string> P) {
    int G_r = static_cast<int>(G.size()), G_c = G[0].length();
    int P_r = static_cast<int>(P.size()), P_c = P[0].length();
    for(int i=0; i<=(G_r-P_r); i++){
        int pos = G[i].find(P[0], 0);
        if(pos >= 0){
            for(int j=pos; j<=(G_c-P_c); j++){
                //這個block原本要用function操作, 但因為測資有個1000*1000的grid要搜尋, 用function操作會超時
                bool flag = true;
                for(int k=i; k<i+P_r; k++){
                    for(int l=j; l<j+P_c; l++){
                        if(G[k][l] != P[k-i][l-j]){
                            flag = false;
                            break;
                        }
                    }
                    if(!flag)    break;
                }
                if(flag)    return "YES";
            }
        }
    }
    return "NO";
}


int main()
{
    vector<string> G, P;
    G.push_back("7283455864");
    G.push_back("6731158619");
    G.push_back("8988242643");
    G.push_back("3830589324");
    G.push_back("2229505813");
    G.push_back("5633845374");
    G.push_back("6473530293");
    G.push_back("7053106601");
    G.push_back("7283455864");
    G.push_back("0834282956");
    G.push_back("4607924137");
    P.push_back("9505");
    P.push_back("3845");
    P.push_back("3530");
    string result = gridSearch(G, P);
    cout << result << "\n";

    return 0;
}

/*1
10 10
7283455864
6731158619
8988242643
3830589324
2229505813
5633845374
6473530293
7053106601
0834282956
4607924137
3 4
9505
3845
3530*/