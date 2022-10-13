
#include <iostream>
#include <vector>

using namespace std;

// void getDouble(int param){
//     // vector<int> vec(10, param);
//     // for(int &i = begin(vec); i < end(vec); i++){
//         cout >>"Hello";
//     // }



// }


int main(){
    // getDouble(3);
    cout << "Hello";
    vector<int> vec(10, 3);
    // for (auto it = begin(vec);
    // it != end(vec); ++it)
    vector<int> newVect(10);
    std::vector<int>::const_iterator it = begin(vec);
    while(it != end(vec))
    {
        // cout << typeof(it) << endl;
        // vec[*it] = 1;
        
        // vec[*it] = vec.at(*it)*2;
        newVect.push_back(vec[*it]* 2);
        // vec[*it] = 1;
        cout << ' ' << *it << " -> " << vec.at(it)  << " using [] "<< vec[it] << endl;
        it++;
    }
    for(auto eleme : newVect){
        cout<< eleme << endl;
    }
}







