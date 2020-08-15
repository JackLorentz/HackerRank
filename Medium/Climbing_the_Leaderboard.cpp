#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Complete the climbingLeaderboard function below.
vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
    vector<int> leaderboard, result;
    for(int i=0; i<static_cast<int>(scores.size()); i++){
        if((i-1 >= 0 && scores[i] != scores[i-1]) || i == 0){
            leaderboard.push_back(scores[i]);
        }
    }
    for(int i=0; i<static_cast<int>(alice.size()); i++){
        int u = static_cast<int>(leaderboard.size())-1, l = 0, m = (l+u)/2;
        while(l < u){
            if(alice[i] > leaderboard[m]){
                u = m-1;
            }
            else if(alice[i] < leaderboard[m]){
                l = m+1;
            }
            else{
                break;
            }
            m = (l+u)/2;
        }
        if(alice[i] < leaderboard[m]){
            m += 1;
        }
        result.push_back(m+1);
    }
    return result;
}

int main()
{
    vector<int> inputs;
    inputs.push_back(100);
    inputs.push_back(90);
    inputs.push_back(90);
    inputs.push_back(80);
    inputs.push_back(75);
    inputs.push_back(60);

    vector<int> alice;
    alice.push_back(50);
    alice.push_back(65);
    alice.push_back(77);
    alice.push_back(90);
    alice.push_back(102);

    vector<int> results = climbingLeaderboard(inputs, alice);

    for(int i=0; i<static_cast<int>(results.size()); i++){
        cout << results[i] << endl;
    }

    return 0;
}