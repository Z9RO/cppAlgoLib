#include"searchTree.h"
#include<iostream>
#include<vector>
using namespace std;

int main(){
    searchTree<int, int> st;
    
    int flag, key, val;
    cin >> flag;
    while(flag!=0){
        switch (flag){
        case 1:
            // put
            cin >> key >> val;
            st.put(key, val); 
            break;
        case 2:
            // get
            cin >> key;
            cout << st.get(key) << endl;
            break;
        case 3:
            // getMin
            cout << st.getMin() << endl;
            break;
        case 4:
            // getMax
            cout << st.getMax() << endl;
            break;
        default:
            break;
        }
        cin >> flag;
    }

    return 0;
}
