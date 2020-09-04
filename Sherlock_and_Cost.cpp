#include <vector>
#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the cost function below.
int cost(vector<int> B) {
    //動態規劃: 將問題分成多個子問題, 透過子問題最佳化來解決問題(跟Divide-and-Conquer差異在於子問題間的關係為獨立)
    int l = static_cast<int>(B.size());
    int low_cost = 0, high_cost = 0;
    int h2l_diff = 0, h2h_diff = 0, l2h_diff = 0;
    for(int i=1; i<l; i++){
        h2l_diff = abs(B[i-1] - 1);
        h2h_diff = abs(B[i-1] - B[i]);
        l2h_diff = abs(1 - B[i]);
        int low = max(low_cost, high_cost + h2l_diff);//有兩種以1結尾的情形, 上個數值為B[i-1]或1
        int high = max(high_cost+h2h_diff, low_cost+l2h_diff);//有兩種以B[i]結尾的情形, 上個數值為B[i-1]或1
        low_cost = low;
        high_cost = high;
    }

    return max(low_cost, high_cost);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string B_temp_temp;
        getline(cin, B_temp_temp);

        vector<string> B_temp = split_string(B_temp_temp);

        vector<int> B(n);

        for (int i = 0; i < n; i++) {
            int B_item = stoi(B_temp[i]);

            B[i] = B_item;
        }

        int result = cost(B);

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
