#include <iostream>
#include <string>

using namespace std;

int main(){
    string word = "";
    getline(cin, word);

    bool result = true;
    int len = word.length()-1; 
    int pivot = word.length()/2;

    for(int i = 0; i < pivot; i++){
        int end = len - i;
        if(word[i] == word[end]){
            continue;
        }
        result = false;
        break;
    }

    if(result) cout << 1;
    else cout << 0;

    return 0;
}