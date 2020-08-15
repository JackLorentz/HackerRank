#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// Complete the extraLongFactorials function below.
void extraLongFactorials(int n) {
    vector<int> result;
    int stack = n, p = 0;
    while(stack > 9){
        p = stack % 10;
        stack /= 10;
        result.push_back(p);
    }
    result.push_back(stack);
    for(int i=1; i<n; i++){
        for(int j=0; j<static_cast<int>(result.size()); j++){
            result[j] *= (n-i);
        }
        stack = 0;//進位
        for(int j=0; j<static_cast<int>(result.size()); j++){
            if(j > 0)
                result[j] += stack;
            
            if(result[j] > 9){
                stack = result[j] / 10;
                result[j] %= 10;
            }
            else
                stack = 0;
        }
        while(stack > 9){
            result.push_back(stack % 10);
            stack /= 10;
        }
        if(stack > 0)
            result.push_back(stack);
    }
    for(int i=static_cast<int>(result.size())-1; i>=0; i--){
        cout << result[i];
    }
    cout << "\n";
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    extraLongFactorials(n);

    return 0;
}
