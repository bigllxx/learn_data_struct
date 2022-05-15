#include <iostream>
using namespace std;

int main() {
    int num_input;
    cin >> num_input;
    int i=0;
    int x;
    for(int j=1; j<num_input+1; j++){
        i = i+j;
        if(num_input<=i){
            x=j;
            break;
        }
    }
    int fen_mu = i - num_input + 1;
    int fen_zi = x - (i - num_input);
    if(x%2 == 0) cout << fen_zi << "/" << fen_mu << endl;
    else cout << fen_mu << "/" << fen_zi << endl;
    return 0;
}