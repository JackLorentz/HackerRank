#include <iostream>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the queensAttack function below.
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    int attack = 2*(n-1);
    attack += min(abs(c_q-1), abs(r_q-1));
    attack += min(abs(c_q-n), abs(r_q-1));
    attack += min(abs(c_q-1), abs(r_q-n));
    attack += min(abs(c_q-n), abs(r_q-n));

    if(k == 0)
        return attack;

    vector<vector<int>> obs;
    int minimun, idx;
    for(int i=0; i<8; i++){
        minimun = INT32_MAX;
        idx = 0;
        switch(i){
            case 0:
                for(int j=0; j<k; j++){
                    if(obstacles[j][1] < c_q && obstacles[j][0] < r_q && (abs(obstacles[j][1] - c_q) == abs(obstacles[j][0] - r_q))){
                        if(minimun > c_q - obstacles[j][1]){
                            minimun = c_q - obstacles[j][1];
                            idx = j;
                        }
                    }
                }
                break;
            case 1:
                for(int j=0; j<k; j++){
                    if(obstacles[j][1] == c_q && obstacles[j][0] < r_q){
                        if(minimun > r_q - obstacles[j][0]){
                            minimun = r_q - obstacles[j][0];
                            idx = j;
                        }
                    }
                }
                break;
            case 2:
                for(int j=0; j<k; j++){
                    if(obstacles[j][1] > c_q && obstacles[j][0] < r_q && (abs(obstacles[j][1] - c_q) == abs(obstacles[j][0] - r_q))){
                        if(minimun > obstacles[j][1] - c_q){
                            minimun = obstacles[j][1] - c_q;
                            idx = j;
                        }
                    }
                }
                break;
            case 3:
                for(int j=0; j<k; j++){
                    if(obstacles[j][1] > c_q && obstacles[j][0] == r_q){
                        if(minimun > obstacles[j][1] - c_q){
                            minimun = obstacles[j][1] - c_q;
                            idx = j;
                        }
                    }
                }
                break;
            case 4:
                for(int j=0; j<k; j++){
                    if(obstacles[j][1] > c_q && obstacles[j][0] > r_q && (abs(obstacles[j][1] - c_q) == abs(obstacles[j][0] - r_q))){
                        if(minimun > obstacles[j][1] - c_q){
                            minimun = obstacles[j][1] - c_q;
                            idx = j;
                        }
                    }
                }
                break;
            case 5:
                for(int j=0; j<k; j++){
                   if(obstacles[j][1] == c_q && obstacles[j][0] > r_q){
                        if(minimun > obstacles[j][0] - r_q){
                            minimun = obstacles[j][0] - r_q;
                            idx = j;
                        }
                    }
                }
                break;
            case 6:
                for(int j=0; j<k; j++){
                    if(obstacles[j][1] < c_q && obstacles[j][0] > r_q && (abs(obstacles[j][1] - c_q) == abs(obstacles[j][0] - r_q))){
                        if(minimun > c_q - obstacles[j][1]){
                            minimun = c_q - obstacles[j][1];
                            idx = j;
                        }
                    }
                }
                break;
            case 7:
                for(int j=0; j<k; j++){
                    if(obstacles[j][1] < c_q && obstacles[j][0] == r_q){
                        if(minimun > c_q - obstacles[j][1]){
                            minimun = c_q - obstacles[j][1];
                            idx = j;
                        }
                    }
                }
                break;
            default: break;
        }
        if(minimun != INT32_MAX){
            obs.push_back(obstacles[idx]);
        }
    }
    
    for(int i=0; i<static_cast<int>(obs.size()); i++){
        if(abs(obs[i][1] - c_q) == abs(obs[i][0] - r_q)){
            if(obs[i][1] < c_q && obs[i][0] < r_q){
                attack -= (1 + min(abs(obs[i][1]-1), abs(obs[i][0]-1)));
            }
            else if(obs[i][1] > c_q && obs[i][0] < r_q){
                attack -= (1 + min(abs(obs[i][1]-n), abs(obs[i][0]-1)));
            }
            else if(obs[i][1] < c_q && obs[i][0] > r_q){
                attack -= (1 + min(abs(obs[i][1]-1), abs(obs[i][0]-n)));
            }
            else{
                attack -= (1 + min(abs(obs[i][1]-n), abs(obs[i][0]-n)));
            }
        }
        else if(obs[i][1] == c_q){
            if(obs[i][0] > r_q){
                attack -= (1 + n - obs[i][0]);
            }
            else{
                attack -= obs[i][0];
            }
        }
        else if(obs[i][0] == r_q){
            if(obs[i][1] > c_q){
                attack -= (1 + n - obs[i][1]);
            }
            else{
                attack -= obs[i][1];
            }
        }
        //cout << "(" << obs[i][0] << ", " << obs[i][1] << "), " << attack << "\n";
    }
    return attack;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string r_qC_q_temp;
    getline(cin, r_qC_q_temp);

    vector<string> r_qC_q = split_string(r_qC_q_temp);

    int r_q = stoi(r_qC_q[0]);

    int c_q = stoi(r_qC_q[1]);

    vector<vector<int>> obstacles(k);
    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> obstacles[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

    fout << result << "\n";
    cout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
