#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main(){
    cout<<"hello world!"<<endl;
}
// int main(){
//     int n, k;
//     cin >> n;
//     vector<int> to_make;
//     for(int i=0;i<n;i++){
//         cin >> k;
//         to_make.push_back(k);
//     }

//     int now_num=1, idx = 0;
//     stack<int> stac;
//     vector<string> ans;
//     stac.push(now_num);
//     for(int i=0;i<n;i++){
//         while(stac.top()!=to_make[i]){
//             stac.push(now_num);
//             ans.push_back("+");
//             now_num++;
//         }
//         if(now_num>n){
//             now_num=-1;
//             cout<<"NO";
//             break;
//         }
//         if(stac.top()==to_make[i]){
//             stac.pop();
//             ans.push_back("-");
//         }
//     }

//     if(now_num!=-1)
//         for(int i=0;i<ans.size();i++)
//             cout<<ans[i]<<endl;
// }