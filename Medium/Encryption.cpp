#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// Complete the encryption function below.
string encryption(string s) {
    char input[100];
    char* token;
    char delim[] = " ";
    strcpy(input, s.c_str());

    char* no_space = new char[100];
    memset(no_space, '\0', sizeof(char)*100);
    token = strtok(input, delim);
    while(token){
        //printf("%s\n", token);
        strcat(no_space, token);
        token = strtok(NULL, delim);
    }
    //printf("%s\n", no_space);
    //sizeof真正意義是用來計算編譯器實際分配的byte數, 所以計算字元陣列長度用strlen較好
    int L = static_cast<int>(strlen(no_space));
    //printf("%d\n", L);
    int row = floor(sqrt(L)), col = ceil(sqrt(L));
    if(row*col < L){
        row = col;
    }
    char matrix[row][col];
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            matrix[i][j] = no_space[i*col+j];
        }
    }
    int k = 0;
    char result[(row+1)*col];
    memset(result, '\0', sizeof(char)*(row+1)*col);
    for(int i=0; i<col; i++){
        for(int j=0; j<row; j++){
            if(j*col+i < L){
                result[k] = matrix[j][i];
                k++;
                if(j == row-1 && i != col-1){
                    result[k] = ' ';
                    k++;
                }
            }
            else{
                result[k] = ' ';
                k++;
            }
        }
    }
    //printf("%s\n", result);

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
