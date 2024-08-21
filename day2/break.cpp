#include <iostream>
using namespace std;
int main(){
    int n=10;
    for(int i=0;i<n;i++){
        if(i < 4){
            cout<<"after if"<<endl;
            break;
            cout<<"after endl"<<endl;
        }
        cout<<"after loop"<<endl;
    }
    cout<<"outside the code"<<endl;

return 0;
}