#include <bits/stdc++.h>

using namespace std;

// Complete the timeInWords function below.
string timeInWords(int h, int m) {
    string dict[31];
    dict[0] = "tweleve";
    dict[1] = "one";
    dict[2] = "two";
    dict[3] = "three";
    dict[4] = "four";
    dict[5] = "five";
    dict[6] = "six";
    dict[7] = "seven";
    dict[8] = "eight";
    dict[9] = "nine";
    dict[10] = "ten";
    dict[11] = "eleven";
    dict[12] = "tweleve";
    dict[13] = "thirteen";
    dict[14] = "fourteen";
    dict[15] = "quarter";
    dict[20] = "twenty";
    dict[30] = "half";

    if(m == 0){
        return dict[h] + " o' clock";
    }
    else if(m == 1){
        return dict[m] + " minute past " + dict[h];
    }
    else if(1 <= m && m <= 30){
        if(m < 15 || m == 20){
            return dict[m] + " minutes past " + dict[h]; 
        }
        else if(m == 15 || m == 30){
            return dict[m] + " past " + dict[h]; 
        }
        else{
            if(15 < m && m < 20){
                return dict[m-10] + "teen minutes past " + dict[h];
            }
            else{
                return "twenty " + dict[m-20] + " minutes past " + dict[h];
            }
        }
    }
    else{
        if(m > 45 || m == 40){
            return dict[60-m] + " minutes to " + dict[(h+1)%12]; 
        }
        else if(m == 45){
            return dict[60-m] + " to " + dict[(h+1)%12]; 
        }
        else{
            if(40 < m && m < 45){
                return dict[60-m-10] + "teen minutes to " + dict[(h+1)%12];
            }
        }
    }
    return "twenty " + dict[60-m-20] + " minutes to " + dict[(h+1)%12];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int h;
    cin >> h;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = timeInWords(h, m);

    cout << result << "\n";
    fout << result << "\n";

    fout.close();

    return 0;
}
