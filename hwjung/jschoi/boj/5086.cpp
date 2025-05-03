#include <iostream>

using namespace std;

int main(){
    int n1 = 0, n2 = 0;

    while(1){
        cin >> n1 >> n2;
        if(cin.eof()) break;
        if(n1 == 0 || n2 == 0) break;
        if(n2 % n1 == 0) cout << "factor" << endl;
        else if(n1 % n2 == 0) cout << "multiple" << endl;
        else cout << "neither" << endl;
    }
    return 0;
}



/*
cpp 에서 EOF 처리
while(1){
    int n = 0;
    cin >> n;
    if(cin.eof()) break;
    ...
}
*/