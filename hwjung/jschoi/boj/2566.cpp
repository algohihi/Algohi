#include <iostream>

using namespace std;

int main(){
    int r = 9;
    int c = 9;

    int max = 0;
    int maxRow = 0;
    int maxCol = 0;

    for(int i = 0; i < r; i++){
        int temp = 0;
        for(int j  = 0; j < c; j++){
            cin >> temp;
            if(temp >= max){
                max = temp;
                maxRow = i;
                maxCol = j;
            }
        }
    }

    cout << max << endl << maxRow+1 << " " << maxCol+1;

    return 0;
}



