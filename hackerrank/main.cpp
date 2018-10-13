#include <iostream>
#include <vector>

using namespace std;

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

#include <bits/stdc++.h>
#include <algorithm> 
using namespace std;

vector<string> split_string(string);


// int findElement(vector<int> arr, int start){
//     int m = arr.size();
//     for(int j = min(start, m); j < arr.size(); j++){
//         if(start == arr[j]){
//             return j;
//         }
//     }
//     return -1;
// }

int getMin(vector<int> arr, int start){
    int min_index = start;
    for(int i = start; i < arr.size(); i++){
        if(arr[min_index] > arr[i]){
            min_index = i;
        }
    }
    return min_index;
}
// Complete the minimumSwaps function below.
int minimumSwaps(vector<int> arr) {
    int count = 0;
    int min = arr[0];

    for(int i = 0; i < arr.size(); i++){
        int min_index = getMin(arr, i);
        // cout << "------------" << endl;
        // cout << "index i " << i << endl;
        // cout << "min_index " << min_index << endl;
        // cout << "MIN " << min << endl;
        // if(min > arr[min_index]){
        if(i != min_index){
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
            count ++;
        }
        min = arr[i];
    }
    // for (int i = 0; i < arr.size(); i++){
    //     cout << arr[i] << endl;
    // }
    return count;
}

int main()
{
    vector<int> foo;
    foo.push_back(1);
    foo.push_back(3);
    foo.push_back(5);
    foo.push_back(2);
    foo.push_back(4);
    foo.push_back(6);
    foo.push_back(8);

    cout << minimumSwaps(foo) << endl;
    return 0;
}

// int main()
// {
//     int t;
//     cin >> t;
//     cin.ignore(numeric_limits<streamsize>::max(), '\n');

//     for (int t_itr = 0; t_itr < t; t_itr++) {
//         int n;
//         cin >> n;
//         cin.ignore(numeric_limits<streamsize>::max(), '\n');

//         string q_temp_temp;
//         getline(cin, q_temp_temp);

//         vector<string> q_temp = split_string(q_temp_temp);

//         vector<int> q(n);

//         for (int i = 0; i < n; i++) {
//             int q_item = stoi(q_temp[i]);

//             q[i] = q_item;
//         }

//         minimumBribes(q);
//     }

//     return 0;
// }


// vector<string> split_string(string);

// // Complete the minimumBribes function below.
// void minimumBribes(vector<int> q) {
//     int bribe_count = 0;

//     int check_int = 1;
//     // cout << "q.begin() " << *q.begin() << endl;
//     for(int i = 0; i < q.size(); i++){
//         if(q[i] != check_int){
//             cout << "q[i] " << q[i] << endl;
//             cout << "check_int " << check_int << endl;
//             int temp = q[i];
//             q[i] = q[i+1];
//             q[i+1] = temp;
//             if(q[i] != check_int){
//                 cout << "Too chaotic" << endl;
//                 return;
//             }
//             bribe_count ++;
//         }
//         check_int ++;
//     }
    
//     cout << bribe_count << endl;
    
// }


// int main()
// {
//     vector<int> foo;
//     foo.push_back(1);
//     foo.push_back(2);
//     foo.push_back(3);
//     minimumBribes(foo);
//     return 0;
// }
