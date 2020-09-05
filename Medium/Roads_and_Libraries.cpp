#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// 測資數字可能會超大, 所以計算成本時要用long long型態
// 少用遞迴函數和adjacent matrix計算會超時
// Complete the roadsAndLibraries function below.
long long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    int m = static_cast<int>(cities.size());
    if(m == 0 || c_lib <= c_road)  return (long long)c_lib*(long long)n;
    vector< vector<int> > adj_list;
    for(int i=0; i<n; i++){
        vector<int> tmp;
        adj_list.push_back(tmp);
    }
    for(int i=0; i<m; i++){
        adj_list[cities[i][0]-1].push_back(cities[i][1]-1);
        adj_list[cities[i][1]-1].push_back(cities[i][0]-1);
    }
    long long connected_graph_num = 0;
    bool visited[n];
    stack<int> s;
    for(int i=0; i<n; i++)  visited[i] = false;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            s.push(i);
            while(!s.empty()){
                int v = s.top();
                s.pop();
                if(!visited[v]) visited[v] = true;
                for(auto j=adj_list[v].begin(); j!=adj_list[v].end(); ++j){
                    if (!visited[*j])   s.push(*j);
                } 
            }
            connected_graph_num++;
        }
    }
    //cout << connected_graph_num << endl; 
    long long tmp1 = connected_graph_num*(long long)c_lib;
    long long tmp2 = (long long)(n-connected_graph_num)*(long long)c_road;
    return tmp1+tmp2;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nmC_libC_road_temp;
        getline(cin, nmC_libC_road_temp);

        vector<string> nmC_libC_road = split_string(nmC_libC_road_temp);

        int n = stoi(nmC_libC_road[0]);

        int m = stoi(nmC_libC_road[1]);

        int c_lib = stoi(nmC_libC_road[2]);

        int c_road = stoi(nmC_libC_road[3]);

        vector<vector<int>> cities(m);
        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> cities[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        long long result = roadsAndLibraries(n, c_lib, c_road, cities);

        fout << result << "\n";
    }

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
