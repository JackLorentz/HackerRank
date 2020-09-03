#include <iostream>
#include <cstring>
#include <stdint.h>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

// Complete the biggerIsGreater function below.
string biggerIsGreater(string w) {
    int l = w.length();
    char s[l+1];//c_str()返回字串會以\0結尾, 所以要預留位置給\0
    strcpy(s, w.c_str());
    int swap_idx = -1;
    for(int i=l; i>0; i--){
        if(s[i] > s[i-1]){
            swap_idx = i-1;
            break;
        }
    }
    if(swap_idx == -1){
        printf("%s\n", "no answer");
        return "no answer";
    }
    int upper_bound_idx = 0, min_diff = INT32_MAX;
    for(int i=swap_idx+1; i<l; i++){
        if(s[i] > s[swap_idx] && s[i]-s[swap_idx] < min_diff){
            min_diff = s[i] - s[swap_idx];
            upper_bound_idx = i;
        }
    }
    char tmp = s[upper_bound_idx];
    s[upper_bound_idx] = s[swap_idx];
    s[swap_idx] = tmp;
    vector<char> part(s+swap_idx+1, s+l);
    sort(part.begin(), part.end());
    for(int i=0; i<static_cast<int>(part.size()); i++){
        s[swap_idx+1+i] = part[i];
    }
    printf("%s\n", s);

    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
