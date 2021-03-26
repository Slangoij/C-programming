#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// 8 4 3 6 8 7 5 2 1
// 5 1 2 5 3 4

#include <algorithm>


void solution(int n, vector<int> &vec){
    int now_num=1, idx = 0;
    stack<int> stac;
    vector<string> ans;
    for(int i=0;i<n;i++){
        while(stac.empty() || (now_num!=-1 && stac.top()!=vec[i] && now_num<=n+1)){ //} && stac.top()!=now_num){
            stac.push(now_num);
            ans.push_back("+");
            now_num++;
        }
        if(stac.top()==vec[i]){// && !stac.empty()){
            stac.pop();
            ans.push_back("-");
        }
        if(now_num>n+1){
            now_num=-1;
            break;
        }
    }

    if(now_num!=-1){
        for(int i=0;i<vec.size();i++)
            cout<<vec[i]<<" ";
        cout<<"ok"<<endl;
    }
    else{
        for(int i=0;i<vec.size();i++)
            cout<<vec[i]<<" ";
        cout<<"No"<<endl;
    }

    // if(now_num!=-1)
    //     for(int i=0;i<ans.size();i++)
    //         cout<<ans[i]<<endl;
    // else{
    //     cout<<"NO";
    // }
}

int main(){
    int n = 6;
    vector<int> nvec;
    for(int i=0;i<n;i++)
        nvec.push_back(i+1);
    solution(n, nvec);
    while(next_permutation(nvec.begin(), nvec.end()))
        solution(n, nvec);
}




// // 1st try: while문에서 걸리는 테케 존재 => 알고보니 endl로 인한 시간 초과였다
// int main(){
//     int n, k;
//     cin >> n;
//     vector<int> vec;
//     for(int i=0;i<n;i++){
//         cin >> k;
//         to_make.push_back(k);
//     }

//     int now_num=1, idx = 0;
//     stack<int> stac;
//     vector<string> ans;
//     for(int i=0;i<n;i++){
//         while(stac.empty() || (now_num!=-1 && stac.top()!=to_make[i])){ //} && stac.top()!=now_num){
//             stac.push(now_num);
//             ans.push_back("+");
//             now_num++;
//         }
//         if(stac.top()==to_make[i]){// && !stac.empty()){
//             stac.pop();
//             ans.push_back("-");
//         }
//         if(now_num>n+1){
//             now_num=-1;
//             break;
//         }
//         else{
//             now_num=-1;
//             break;
//         }
//     }

//     if(now_num!=-1)
//         for(int i=0;i<ans.size();i++)
//             cout<<ans[i]<<endl;
//     else{
//         cout<<"NO";
//     }
// }