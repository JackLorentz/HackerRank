#include <bits/stdc++.h>

using namespace std;

// 沒解出來@@
// 問題: 有N種不同的箱子和球, 要透過不同箱子間等量交換的方式讓每個箱子只有單一種球, 並判斷測資狀況可不可能做到
// 思路: 假如某個箱子想要放所有的一號球, 那麼該箱子就必須有跟一號球一樣的多球才有可換得到
// 解法: 計算出每個箱子的球數量和每種球的數量, 將兩種數列排序, 若完全相同表示都可映射得到即表示可能做到
// Complete the organizingContainers function below.
string organizingContainers(vector<vector<int>> container) {
    int n = static_cast<int>(container.size());
    // 每種球的數量和每個箱子的球數量
    vector<long> type_num, container_num; 
    for(int i=0; i<n; i++){
        long sum1 = 0, sum2 = 0;
        for(int j=0; j<n; j++){
            sum1 += (long)container[j][i];
            sum2 += (long)container[i][j];
        }
        type_num.push_back(sum1);
        container_num.push_back(sum2);
    }
    sort(type_num.begin(), type_num.end());
    sort(container_num.begin(), container_num.end());
    for(int i=0; i<n; i++){
        if(type_num[i] != container_num[i]) return "Impossible";
    }
    return "Possible";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> container(n);
        for (int i = 0; i < n; i++) {
            container[i].resize(n);

            for (int j = 0; j < n; j++) {
                cin >> container[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string result = organizingContainers(container);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
