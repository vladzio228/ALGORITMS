#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

vector<int> CreateArray(const int& n) {

    std::random_device rd; // отримуємо випадкове число з компютера
    std::mt19937 gen(rd()); // сід генератора
    std::uniform_int_distribution<> distr(0, 1000); // границя випадкових чисел

    vector<int> arr;

    for (int i = 0; i < n; ++i) {
        arr.push_back(distr(gen));
    }
    return arr;
}

vector<vector<int>> CreateArray(const int& n1 /*рядки*/, const int& n2 /*стовбці*/) {

    std::random_device rd; // отримуємо випадкове число з компютера
    std::mt19937 gen(rd()); // сід генератора
    std::uniform_int_distribution<> distr(0, 1000); // границя випадкових чисел

    vector<vector<int>> arr(n1);

    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j)
            arr[i].push_back(distr(gen));
    }
    return arr;
}

vector<vector<vector<int>>>  CreateArray(int xn, int yn, int zn) {

    std::random_device rd; // отримуємо випадкове число з компютера
    std::mt19937 gen(rd()); // сід генератора
    std::uniform_int_distribution<> distr(0, 1000); // границя випадкових чисел

    vector<vector<vector<int>>> arr(zn);

    for (int i = 0; i < zn; ++i) {
        arr[i].resize(yn);
    }


    for (int i = 0; i < zn; ++i) {
        for (int j = 0; j < yn; ++j)
            for (int k = 0; k < xn; ++k) {
                arr[i][j].push_back(distr(gen));
            }
    }
    return arr;
}
vector<int> task1A(vector<int>& v) {
    vector<int> res;
    bool insertInBegin = false;
    for (int& i : v) {
        if (insertInBegin) {
            res.insert(res.begin(), i);
        }
        else {
            res.push_back(i);
        }
        insertInBegin = !insertInBegin;
    }
    return res;
}

vector<int> task1B(vector<int>& v) {
    vector<int> res;
    for (int i = 0; i < v.size() / 2 + 1 && res.size() < v.size(); ++i) {
        res.push_back(v[v.size() - i - 1]);
        if (res.size() < v.size()) {
            res.push_back(v[i]);
        }
    }
    return res;
}

vector<int> task1C(vector<int>& v) {
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

void printVector(const vector<int>& v) {
    for (const auto& elem : v) {
        cout << elem << " ";
    }
    cout << endl;
}

void printVector(const vector<vector<int>>& v) {
    for (const auto& raw : v) {
        for (const auto& el : raw) {
            cout << el << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printVector(const vector<vector<vector<int>>>& vvv) {
    for (const auto& z : vvv) {
        for (const auto& zy : z) {
            for (const auto& zyx : zy) {
                cout << zyx << " ";
            }
            cout << endl;
        }
        cout << endl << endl;
    }
}

void task2A(vector<vector<int>> vv, int n1, int n2) {
    vector<int> v;
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            v.push_back(vv[i][j]);
        }
    }
    sort(v.begin(), v.end());

    int count = 0;
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            vv[i][j] = v[count];
            count++;
        }
    }
    printVector(vv);
}

void task2B(vector<vector<int>> vv, int n1, int n2) {
    vector<int> v;
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            v.push_back(vv[i][j]);
        }
    }
    sort(v.begin(), v.end());
    int count = 0;
    for (int column = 0; column < n2; column++) {
        for (int raw = 0; raw < n1; raw++) {
            vv[raw][column] = v[count];
            count++;
        }
    }
    printVector(vv);
}
void task2C(vector<vector<int>> vv, int n1, int n2) {

    vector<int> v;
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            v.push_back(vv[i][j]);
        }
    }
    sort(v.begin(), v.end());

    int count = 0;
    int left = 0;
    int right = n2 - 1;
    int up = 0;
    int down = n1 - 1;
    int x = 0;
    int y = 0;
    while (left < right + 1 || up < down + 1) {
        if (y == up && x < right) {
            vv[up][x] = v[count];
            if (x < right) {
                x++;
            }
            if (x == right) {
                up++;
            }
        }
        else if (x == right && y < down) {
            vv[y][right] = v[count];
            if (y < down) {
                y++;
            }
            if (y == down) {
                right--;
            }
        }
        else if (y == down && x > left) {
            vv[down][x] = v[count];
            if (x > left) {
                x--;
            }
            if (x == left) {
                down--;
            }
        }
        else if (x == left && y > up) {
            vv[y][left] = v[count];
            if (y > up) {
                y--;
            }
            if (y == up) {
                left++;
            }
        }
        else
        {
            vv[y][x] = v[count];
            break;
        }
        count++;
    }
    printVector(vv);
}
void task2D(vector<vector<int>> vv, int n1, int n2) {
    vector<int> v;
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            v.push_back(vv[i][j]);
        }
    }
    sort(v.begin(), v.end(), greater<int>());
    int count = 0;
    int left = 0;
    int right = n2 - 1;
    int up = 0;
    int down = n1 - 1;
    int x = 0;
    int y = 0;
    vector<int> res;
    while (left < right + 1 || up < down + 1) {
        if (y == up && x > left) {
            vv[up][x] = v[count];
            if (x > left) {
                x--;
            }
            if (x == left) {
                up++;
            }
        }
        else if (x == right && y > up) {
            vv[y][right] = v[count];
            if (y > up) {
                y--;
            }
            if (y == up) {
                right--;
            }
        }
        else if (y == down && x < right) {
            vv[down][x] = v[count];
            if (x < right) {
                x++;
            }
            if (x == right) {
                down--;
            }
        }
        else if (x == left && y < down) {
            vv[y][left] = v[count];
            if (y < down) {
                y++;
            }
            if (y == down) {
                left++;
            }
        }
        else
        {
            vv[y][x] = v[count];
            break;
        }
        count++;
    }
    printVector(vv);
}

void task2E(vector<vector<int>> vv, int n1, int n2) {

    vector<int> v;
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            v.push_back(vv[i][j]);
        }
    }
    sort(v.begin(), v.end());

    int count = 0;

    bool printLeftToRight = true;
    for (int i = 0; i < n1; ++i) {
        if (printLeftToRight)
        {
            for (int j = 0; j < n2; j++) {
                vv[i][j] = v[count];
                count++;
            }
        }
        else {
            for (int j = n2 - 1; j >= 0; j--) {
                vv[i][j] = v[count];
                count++;
            }
        }
        printLeftToRight = !printLeftToRight;
    }
    printVector(vv);
}


void task2F(vector<vector<int>> vv, int n1, int n2) {

    vector<int> v;
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            v.push_back(vv[i][j]);
        }
    }
    sort(v.begin(), v.end());

    int count = 0;

    bool leftToRight = true;
    bool upToDown = true;
    for (int doubleColumn = 0; doubleColumn < n2 / 2; ++doubleColumn) {
        leftToRight = true;
        if (upToDown) {
            for (int raw = 0; raw < n1; raw++) {
                if (leftToRight) {
                    vv[raw][doubleColumn * 2] = v[count];
                    count++;
                    vv[raw][doubleColumn * 2 + 1] = v[count];
                    count++;
                }
                else {
                    vv[raw][doubleColumn + 1] = v[count];
                    count++;
                    vv[raw][doubleColumn * 2] = v[count];
                    count++;
                }
                leftToRight = !leftToRight;
            }
        }
        else {
            for (int raw = n1 - 1; raw >= 0; raw--) {
                if (leftToRight) {
                    vv[raw][doubleColumn * 2] = v[count];
                    count++;
                    vv[raw][doubleColumn * 2 + 1] = v[count];
                    count++;
                }
                else {
                    vv[raw][doubleColumn * 2 + 1] = v[count];
                    count++;
                    vv[raw][doubleColumn * 2] = v[count];
                    count++;
                }
                leftToRight = !leftToRight;
            }
        }
        upToDown = !upToDown;
    }
    if (n2 % 2 == 1) {
        if (upToDown) {
            for (int i = 0; i < n1; i++) {
                vv[i][n2 - 1] = v[count];
                count++;
            }
        }
        else {
            for (int i = n1 - 1; i >= 0; i--) {
                vv[i][n2 - 1] = v[count];
            }
        }
    }
    printVector(vv);
}
int Max(const vector<vector<int>>& vv, int xn, int yn) {
    int max = std::numeric_limits<int>::min();
    for (int x = 0; x < xn; x++) {
        for (int y = 0; y < yn; y++) {
            if (vv[x][y] > max) {
                max = vv[x][y];
            }
        }
    }
    return max;
}


int Min(const vector<vector<int>>& vv, int xn, int yn) {
    int min = std::numeric_limits<int>::max();
    for (int x = 0; x < xn; x++) {
        for (int y = 0; y < yn; y++) {
            if (vv[x][y] < min) {
                min = vv[x][y];
            }
        }
    }
    return min;
}
int Max(const vector<vector<vector<int>>>& vvv, int xn, int yn, int zn) {
    int max = std::numeric_limits<int>::min();
    for (int z = 0; z < zn; z++) {
        for (int y = 0; y < yn; y++) {
            for (int x = 0; x < xn; x++) {
                if (vvv[z][y][x] > max) {
                    max = vvv[z][y][x];
                }
            }
        }
    }
    return max;
}

int Min(const vector<vector<vector<int>>>& vvv, int xn, int yn, int zn) {
    int min = std::numeric_limits<int>::max();
    for (int z = 0; z < zn; z++) {
        for (int y = 0; y < yn; y++) {
            for (int x = 0; x < xn; x++) {
                if (vvv[z][y][x] < min) {
                    min = vvv[z][y][x];
                }
            }
        }
    }
    return min;
}

void Task3SortX(vector<vector<vector<int>>>& vvv, int xn, int yn, int zn) {
    for (int z = 0; z < zn; z++) {
        for (int y = 0; y < yn; ++y) {
            sort(vvv[z][y].begin(), vvv[z][y].end());
        }
    }
}

void Task3SortY(vector<vector<vector<int>>>& vvv, int xn, int yn, int zn) {
    vector<int> v;
    for (int z = 0; z < zn; z++) {
        for (int x = 0; x < xn; x++) {
            for (int y = 0; y < yn; y++) {
                v.push_back(vvv[z][y][x]);
            }
            sort(v.begin(), v.end());
            for (int y = 0; y < yn; y++) {
                vvv[z][y][x] = v[y];
            }
            v.clear();
        }
    }
}

void Task3SortZ(vector<vector<vector<int>>>& vvv, int xn, int yn, int zn) {
    vector<int> v;
    for (int y = 0; y < yn; y++) {
        for (int x = 0; x < xn; x++) {
            for (int z = 0; z < zn; z++) {
                v.push_back(vvv[z][y][x]);
            }
            sort(v.begin(), v.end());
            for (int z = 0; z < zn; z++) {
                vvv[z][y][x] = v[z];
            }
            v.clear();
        }
    }

}

vector<int> Task4Union(const vector<int>& v1, const vector<int>& v2) {
    vector<int> res = v1;
    vector<int> temp = v1;

    for (auto& el : v2) {
        auto it = find(temp.begin(), temp.end(), el);
        if (it != temp.end()) {
            temp.erase(it);
        }
        else {
            res.push_back(el);
        }
    }
    return res;
}

vector<int> Task4Cross(const vector<int>& v1, const vector<int>& v2) {
    vector<int> temp = v2;
    vector<int> res;
    for (const auto& el : v1) {
        auto it = find(temp.begin(), temp.end(), el);
        if (it != temp.end()) {
            res.push_back(el);
            temp.erase(it);
        }
    }
    return res;
}

vector<int> Task4Diff(const vector<int>& v1, const vector<int>& v2) {
    vector<int> cross = Task4Cross(v1, v2);
    vector<int> res;
    for (const auto& el : v1) {
        auto it = find(cross.begin(), cross.end(), el);
        if (it == cross.end()) {
            res.push_back(el);
        }
        else {
            cross.erase(it);
        }
    }
    return res;
}

vector<int> Task4DiffSym(const vector<int>& v1, const vector<int>& v2) {
    vector<int> union_ = Task4Union(v1, v2);
    vector<int> cross = Task4Cross(v1, v2);
    vector<int> res;

    for (const auto& el : union_) {
        auto it = find(cross.begin(), cross.end(), el);
        if (it == cross.end()) {
            res.push_back(el);
        }
        else {
            cross.erase(it);
        }
    }
    return res;
}

int main() {
    int amount = 0;

    cout << "Enter array length: ";

    cin >> amount;

    vector<int> v = CreateArray(amount);
    auto minNum = min_element(v.begin(), v.end());
    auto maxNum = max_element(v.begin(), v.end());

    cout << "Array: ";
    printVector(v);

    cout << endl;
    cout << "Min: " << *minNum << endl
        << "Max: " << *maxNum << endl << endl;

    /*Desc*/ sort(v.begin(), v.end(), greater<int>());
    cout << "Sorting by desc: ";
    printVector(v);

    cout << endl << endl;

    /*Asc*/  sort(v.begin(), v.end());
    cout << "Sorting by asc: ";
    printVector(v);

    cout << endl << endl;

    vector<int> va = task1A(v);
    cout << "Task A: ";
    printVector(va);

    cout << endl << endl;

    vector<int> vb = task1B(v);
    cout << "Task B: ";
    printVector(vb);


    cout << endl << endl;

    vector<int> vc = task1C(v);
    cout << "Task C: ";
    printVector(vc);

    cout << endl << endl;

    int n1;
    int n2;

    cout << "Enter num of raws: ";
    cin >> n1;

    cout << "Enter num of columns: ";
    cin >> n2;

    vector<vector<int>> vv = CreateArray(n1, n2);

    printVector(vv);

    cout << endl;
    cout << "Min: " << Min(vv, n1, n2) << endl
        << "Max: " << Max(vv, n1, n2) << endl << endl;


    cout << "Task 2 A: \n";
    task2A(vv, n1, n2);
    cout << endl << endl;

    cout << "Task 2 B: \n";
    task2B(vv, n1, n2);
    cout << endl << endl;

    cout << "Task 2 C: \n";
    task2C(vv, n1, n2);
    cout << endl << endl;

    cout << "Task 2 D: \n";
    task2D(vv, n1, n2);
    cout << endl << endl;

    cout << "Task 2 E: \n";
    task2E(vv, n1, n2);
    cout << endl << endl;

    cout << "Task 2 F: \n";
    task2F(vv, n1, n2);
    cout << endl << endl;

    int xn, yn, zn;
    cout << "Enter z:\n";
    cin >> zn;
    cout << "Enter y:\n";
    cin >> yn;
    cout << "Enter x:\n";
    cin >> xn;

    vector<vector<vector<int>>> vvv = CreateArray(xn, yn, zn);
    printVector(vvv);

    cout << "Task 3 Max: " << Max(vvv, xn, yn, zn) << endl;
    cout << "Task 3 Min: " << Min(vvv, xn, yn, zn) << endl;
    cout << endl;

    cout << "Task 3 Sort X: " << endl;
    Task3SortX(vvv, xn, yn, zn);
    printVector(vvv);

    cout << "Task 3 Sort Y: " << endl;
    Task3SortY(vvv, xn, yn, zn);
    printVector(vvv);


    cout << "Task 3 Sort Z: " << endl;
    Task3SortZ(vvv, xn, yn, zn);
    printVector(vvv);

    // Task 4
    int v1n;
    int v2n;
    cout << "Task 4" << endl;

    cout << "Enter v1 length: ";
    cin >> v1n;

    cout << endl;

    cout << "Enter v2 length: ";
    cin >> v2n;

    vector<int> v1 = CreateArray(v1n);
    vector<int> v2 = CreateArray(v2n);


    cout << "v1 : \n";
    printVector(v1);
    cout << "v2 : \n";
    printVector(v2);

    cout << "Task 4 Union" << endl;
    printVector(Task4Union(v1, v2));

    cout << "Task 4 Cross" << endl;
    printVector(Task4Cross(v1, v2));

    cout << "Task 4 Diff" << endl;
    printVector(Task4Diff(v1, v2));

    cout << "Task 4 Symmetric difference" << endl;
    printVector(Task4DiffSym(v1, v2));

    return 0;
}