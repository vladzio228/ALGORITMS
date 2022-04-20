#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> createArray(const int& lenght){
    vector<int> numbers;

    for (int i = 0; i < lenght; ++i) {
        numbers.push_back(rand());
    }
    return numbers;
}

vector<int> taskA(vector<int>& v){
    vector<int> toRes;
    for (int i = 0; i < v.size(); ++i) {
        toRes.push_back(v[i]);
        ++i;
        if (i < v.size()) {
            toRes.insert(toRes.begin(), v[i]);
        }
    }
    return toRes;
}

vector<int> taskB(vector<int>& v) {
    vector<int> toRes;
    for (int i = 0; i < v.size() / 2 + 1 && toRes.size() < v.size(); ++i) {
        toRes.push_back(v[v.size() - i - 1]);
        if (toRes.size() < v.size()) {
            toRes.push_back(v[i]);
        }
    }
    return toRes;
}

vector<int> taskC(vector<int>& v) {
    vector<int> desc, asc, res;
    asc = v;
    sort(v.begin(), v.end(), greater<int>());
    desc = v;
    for (int i = 0; i < desc.size(); ++i) {
        if (desc[i] % 2 == 0) {
            res.push_back(desc[i]);
        }
    }
    for (int i = 0; i < asc.size(); ++i) {
        if (asc[i] % 2 == 1) {
            res.push_back(asc[i]);
        }
    }
    return res;
}

int main(){
    int amount = 0;
    cin >> amount;

    vector<int> temp = createArray(amount);
    auto minNum = min_element(temp.begin(), temp.end());
    auto maxNum = max_element(temp.begin(), temp.end());
    
    cout << "Min: " << *minNum << endl
         << "Max: " << *maxNum << endl << endl;

/*Desc*/ sort(temp.begin(), temp.end(), greater<int>());
         cout << "Sorting by desc: ";
         for (auto elem : temp) {
             cout << elem << " ";
         }

         cout << endl << endl;

/*Asc*/  sort(temp.begin(), temp.end());
         cout << "Sorting by asc: ";
         for (auto elem : temp) {
             cout << elem << " ";
         } 
        
         cout << endl << endl;

         vector<int> vectA = taskA(temp);
         cout << "Task A: ";
         for (auto elem : vectA) {
             cout << elem << " ";
         }

         cout << endl << endl;

         vector<int> vectB = taskB(temp);
         cout << "Task B: ";
         for (auto elem : vectB) {
             cout << elem << " ";
         }

         cout << endl << endl;

         vector<int> vectC = taskC(temp);
         cout << "Task C: ";
         for (auto elem : vectC) {
             cout << elem << " ";
         }

         cout << endl << endl;

         return 0;
}