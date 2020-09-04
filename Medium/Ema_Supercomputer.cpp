#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int check(vector< vector<int> > mat, int size, int x, int y){
    int flag = 1;
    if(mat[x][y] == 0 || x-size < 0 || 
        x+size >= static_cast<int>(mat.size()) || y-size < 0 || 
        y+size >= static_cast<int>(mat[0].size())){
            return 0;
        }
    for(int i=x-size; i<=x+size; i++){
        flag *= mat[i][y];
    }
    for(int i=y-size; i<=y+size; i++){
        flag *= mat[x][i];
    }
    return flag;
}

// Complete the twoPluses function below.
int twoPluses(vector<string> grid) {
    vector< vector<int> > mat;
    vector< vector<int> > cands;
    int l = 0;
    for(int i=0; i<static_cast<int>(grid.size()); i++){
        l = grid[i].length();
        char tmp[l+1];
        strcpy(tmp, grid[i].c_str());
        vector<int> row;
        for(int j=0; j<l; j++){
            if(tmp[j] == 'G')
                row.push_back(1);
            else
                row.push_back(0);
            //cout << row[j];
        }
        //cout << "\n";
        mat.push_back(row);
    }
    int r = static_cast<int>(mat.size()), c = static_cast<int>(mat[0].size());
    int size = min(r, c);
    if(size % 2 == 0){
        size--;
    }
    size = (size-1)/2;
    for(int i=1; i<r-1; i++){
        for(int j=1; j<c-1; j++){
            int s = size;
            while(s >= 0){
                if(check(mat, s, i, j) == 1){
                    vector<int> cand;
                    cand.push_back(s);
                    cand.push_back(i);
                    cand.push_back(j);
                    cands.push_back(cand);
                }
                s--;
            }
        }
    }
    if(cands.empty())    return 0;
    int max_product = 1;
    for(int i=0; i<static_cast<int>(cands.size()); i++){
        vector< vector<int> > tmp_mat;
        int product = cands[i][0]*4+1;
        for(int j=0; j<r; j++){
            vector<int> tmp;
            for(int k=0; k<c; k++){
                tmp.push_back(mat[j][k]);
            }
            tmp_mat.push_back(tmp);
        }
        for(int j=cands[i][1]-cands[i][0]; j<=cands[i][1]+cands[i][0]; j++){
            tmp_mat[j][cands[i][2]] = 0;
        }
        for(int j=cands[i][2]-cands[i][0]; j<=cands[i][2]+cands[i][0]; j++){
            tmp_mat[cands[i][1]][j] = 0;
        }
        for(int j=1; j<r-1; j++){
            for(int k=1; k<c-1; k++){
                int s = size;
                while(s >= 0){
                    if(check(tmp_mat, s, j, k) == 1){    
                        if(product*(s*4+1) > max_product){
                            //cout << i << " " << j << endl;
                            max_product = product*(s*4+1);
                        }
                    }
                    s--;
                }
            }
        }
    }
    return max_product;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    int result = twoPluses(grid);

    fout << result << "\n";

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
