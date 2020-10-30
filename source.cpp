#include <iostream>
#include "queue.h"

using namespace std;

/*Տրված են q1 և q2 հերթերը։Կառուցել q3 հերթը,
 որի մեջ մեկումեջ դասավորված են q1 և q2 հերթերի տարրերը,
  իսկ վերջում` չդատարկված հերթի տարրերը։*/

int main() {
    queue<int> q1, q2, q3;
    int n, m, k;
    cin>>n;
    for(int i=0;i<n;++i) {
        cin>>k;
        q1.insert(k);
    }
    cin>>m;
    for(int i=0;i<m;++i) {
        cin>>k;
        q2.insert(k);
    }

    while(!q1.empty() || !q2.empty()) {
        if(!q1.empty()) {
            q3.insert(q1.getFirst());
            q1.Delete();
        }
        if(!q2.empty()) {
            q3.insert(q2.getFirst());
            q2.Delete();
        }
    }
    q3.print();
    return 0;
}