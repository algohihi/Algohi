#include <iostream>
#include <vector>

using namespace std;

int main(){
    int r = 0;
    int c = 0;

    vector<vector<int>> arr;
    vector<vector<int>> res;

    cin >> r >> c;


    for(int i = 0; i < r; i++){
        int temp = 0;
        vector<int> row;
        for(int j = 0; j < c; j++){
            cin >> temp;
            row.push_back(temp);
        }
        arr.push_back(row);
    }
    for(int i = 0; i < r; i++){
        int temp = 0;
        vector<int> row;
        for(int j = 0; j < c; j++){
            cin >> temp;
            temp += arr[i][j];
            row.push_back(temp);
        }
        res.push_back(row);
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}



