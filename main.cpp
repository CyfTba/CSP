#include<bits/stdc++.h>
using namespace std;

//22.1
void histogram() {
    int n;
    int m;
    int L;
    cin >> n >> m >> L;
    int array[256]{0};
    for (int i = 0; i < n; i++) {
        int temp;
        for (int j = 0; j < m; j++) {
            cin >> temp;
            array[temp]++;
        }
    }
    for (int i = 0; i < L; i++) {
        cout << array[i] << " ";
    }
}

//22.2
void dark_count() {
    int n;
    int L;
    int r;
    int t;
    cin >> n >> L >> r >> t;
    vector<vector<int>> metrix(n, vector<int>(n));

    int i = n;
    const int Length = 101;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> metrix[i][j];
        }
    }

    int a[Length][Length] = {0};//前缀和数组，前缀和的定义是从(i,j)到(x,y)的和0<=i<=x,0<=j<=y
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = metrix[i - 1][j - 1] + a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1];
        }

    }
    int count = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int sum1;
            int m;
            int x1;//计算该点的左上角坐标和右下角坐标
            int y1;
            int x2;
            int y2;
            x1 = max(1, i - r);
            y1 = max(1, j - r);
            x2 = min(n, i + r);
            y2 = min(n, j + r);
            sum1 = a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1];
            m = (x2 - x1 + 1) * (y2 - y1 + 1);
            if (sum1 <= t * m) {
                count++;
            }


        }
    }
    cout << count;
}

////22.3太复杂不会
//class DH {
//public:
//    DH(int i, string F_user, string S_user, string type, int ip, int Over_time) :i(i), F_user(F_user), S_user(S_user), type(type), ip(ip), Over_time(Over_time) {};
//    DH() = default;
//    int i;
//    string F_user;
//    string S_user;
//    string type;
//    int ip;
//    int Over_time;
//
//private:
//
//};
//void DHCP() {
//    int N;
//    int Tdef;
//    int Tmax;
//    int Tmin;
//    string H;
//    int n; 
//    cin >> N >> Tdef >> Tmax >> Tmin >> H >> n;
//    DH array[10000];
//
//    for (int i = 0; i < n; i++) {
//        int num,p,over;
//        string fuser, suser, ty;
//        array[i].i = num;
//        array[i].F_user = fuser;
//        array[i].S_user = suser;
//        array[i].type = ty;
//        array[i].ip = p;
//        array[i].Over_time = over;
//    }
//    for (int i = 0; i < n; i++) {
//        if (array[i].S_user==H || array[i].S_user == "*") {
//            if (array[i].type != "DIS" || array[i].type != "REQ")
//                continue;
//            if (array[i].S_user == "*" && array[i].type != "DIS")
//                continue;
//            if (array[i].S_user==H && array[i].type != "DIS")
//                continue;
//            if (array[i].type == "DIS") {
//
//            }
//            if (array[i].type == "REQ") {
//
//            }
//
//        }
//        else if (array[i].type != "REQ")
//            continue;
//
//    }
//}
//
////22.4
//void school_tree(){
//    int n;
//    int array[1000]{0};
//    for (int i = 0; i < n; i++) {
//        cin >> array[i];
//    }
//    int min = array[0];
//    int max = array[n - 1];
//
//
//
//}


//23.1
void Array_to_Sum() {
    vector<int>B(100, 0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }
    int sum_min=0;
    int sum_max=0;
    int min = 0;
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            if (B[i] == B[i - 1]) {
                sum_min += min;
                sum_max += B[i];
            }
            else {
                sum_min += B[i];
                sum_max += B[i];
            }
        }
        else {
            max = B[i];
            min = std::min(B[i], 0);
            sum_min += B[i];
            sum_max += B[i];
        }
    }
    cout << sum_max << endl;
    cout << sum_min << endl;
}

//23.2
int no_0() {
    int n;
    cin >> n;
    vector<int> array(n+1,0);
    int max = 0;
    int flag = false;
    set<int> s;
    int size = 0;
    for (int i = 1; i <= n; i++) {
        cin >> array[i];
        s.insert(array[i]);
        if (array[i] != 0)
            flag = true;
        max = std::max(max, array[i]);
    }
    if (flag == false) {
        cout << 0;
        return 0;
    }
    for (auto temp:s) {
        int pos=0;
        for (int j = 1; j <= n; j++) {
            if (array[j] == temp)
                array[j] = 0;
            if (array[j - 1] == 0 && array[j] != 0) {
                pos++;
            }
        }
        size = std::max(size, pos);
    }
    cout << size;
    return 0;
}

//23.2
int b[500001]{ 0 };
int a[500001]{ 0 };
//差分
void add(int l, int r) {
    b[l]++;
    b[r + 1]--;
}
int no_0_2() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        if (a[i - 1] < a[i]) {
            add(a[i - 1] + 1, a[i]);
        }
    }
    int sum = 0;
    int Max = 0;
    for (int i = 0; i <= 10000; i++) {
        sum = sum + b[i];
        Max = std::max(Max, sum);
    }
    cout << Max;
    return 0;
}

//24.1
int F_24_1() {
    int n, N;
    cin >> n >> N;
    vector<int>V (n + 1, 0);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> V[i];
    }
    for (int i = 0; i < N; i++) {
        if (i >= V[n]) {
            sum +=n;
            continue;
        }
        int j = 0;
        while (V[j] < i&&j<=n) {
            j++;
        }
        if (j > n) {
            sum +=(j-1);
            continue;
        }
        if (V[j] == i)
            sum += j;
        else if (V[j] > i)
            sum += (j-1);
    }
    cout << sum;
    return 0;

}

int F_24_2() {
    int n, N;
    cin >> n >> N;
    vector<int> V(n + 2, 0);
    V[n + 1] = N;
    for (int i = 1; i <= n; i++) {
        cin >> V[i];
    }
    int error = 0;
    int r = N / (n + 1);
    int gx;
    for (int i = 0; i < N; i++) {
        gx = i / r;
        int pos;
        pos= lower_bound(V.begin(), V.end(), i) - V.begin();
        if (V[pos] > i)
            pos--;
        error += abs(gx - pos);
    }
    cout << error;
    return 0;

}

//未处理校验码
int F_24_3() {
    int w, s;
    int model = 1;//1=大写，2=小写，3=数字
    cin >> w >> s;
    string str;
    cin >> str;
    int ss= str.size();
    vector<int> vec;
    for (int i = 0; i < ss; i++) {
        char temp = str[i];
        int m;
        if (isalpha(temp) != 0) {
            if (islower(temp) != 0)
                m = 2;
            else
                m = 1;
        }
        else
            m = 3;
        if (model == m) {
            switch (m)
            {
            case 1:
                vec.push_back(temp-65);
                break;
            case 2:
                vec.push_back(temp-97);
                break;
            case 3:
                vec.push_back(temp-48);
                break;
            default:
                break;
            }

        }
        else {
            switch (m)
            {
            case 1:
                if (model == 2) {
                    vec.push_back(28);
                    vec.push_back(28);
                    model = 1;
                }

                else if (model == 3) {
                    vec.push_back(28);
                    model = 1;
                }
                break;
                
            case 2:
                if (model == 1) {
                    vec.push_back(27);
                    model = 2;
                }
                else if (model == 3) {
                    vec.push_back(28);
                    vec.push_back(27);
                    model = 2;
                }
                break;
            case 3:
                if (model == 1) {
                    vec.push_back(28);
                    model = 3;
                }
                else if (model == 2) {
                    vec.push_back(28);
                    model = 3;
                }
                break;
            default:
                break;
            }
        }


    }
    if (vec.size() % 2 == 1)
        vec.push_back(29);
    vector<int> v;
    for (int i = 0; i < vec.size(); i=i + 2) {
        v.push_back(30 * vec[i] + vec[i + 1]);
    }
    int size = v.size();
    int k = pow(2, s + 1);
    while ((size + 1+k) % w != 0) {
        cout << size + 1 % w;
        v.push_back(900);
        size++;
    }
    cout << size + 1<<endl;
    for (auto& i : v)
        cout << i << endl;
    return 0;
}

int F_25_1() {
    int n, k;
    cin >> n >> k;
    int x;
    int y;
    set<int> s;
    s.insert(0);
    int count = 0;
    for (int i = 1; i <= k; i++) {
        cin >> x >> y;
        if (s.find(y) == s.end())
            count++;
        s.insert(x);
    }
    cout << count;
    return 0;
}

int F_25_2() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> p;
    int temp1, temp2;
    for (int i = 0; i < n; i++) {
        cin >> temp1 >> temp2;
        p.push_back({ temp1, temp2 });
    }

    for (int i = 0; i < m; i++) {
        
        int count = 0;
        cin >> temp1;
        int left = k+temp1;
        for (int i = 0; i < n; i++) {
            int right = left + p[i].second - 1;
            if (left <= p[i].first && p[i].first <= right)
                count++;
        }
        cout << count<<endl;
    }
    return 0;
}

//*******
//差分优化O(n)
int F_25_2_() {
    int n, m, k;
    cin >> n >> m >> k;
    int array[200010]{0};
    int temp1, temp2;
    for (int i = 0; i < n; i++) {
        cin >> temp1 >> temp2;
        int left = temp1 - k - temp2 + 1;
        int right = temp1 - k;//计算每个地方允许的核酸检测区间，区间中数组元素加1，用差分数组存储只需左边界+1，右边界-1，再将差分数组求前缀和，对应下标即为符合要求的地方
        if (right > 0) {
            array[max(left, 1)]++;
            array[right + 1]--;
        }
    }
    for (int i = 1; i < 200010; i++) {
        array[i] = array[i] + array[i - 1];
    }
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        cout << array[x]<<endl;
    }

    return 0;
}

//50分，未处理任务亲和性、任务反亲和性
int F_25_3() {
    int n, m;
    cin >> n >> m;
    vector<int> v;
    vector<int> v_(1010,0);
    unordered_map<int, int> hash;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        hash[temp]++;
        v.push_back(temp);
    }
    int g;
    cin >> g;
    for (int i = 0; i < g; i++) {
        int f, a, na, pa, paa, paar;
        cin >> f >> a >> na >> pa >> paa >> paar;
        auto li= find(v.begin(), v.end(), a);
        if (li == v.end()) {
            for (int i = 0; i < f; i++) {
                cout << 0 << " ";
            }
            cout << endl;
            continue;
        }
        int left = li - v.begin();
        int right = left + hash[a];//[ )
        int min;
        if (v_[left]== v_[right - 1])
            min = left;
        else {
            for (int i = left; i < right; i++) {
                if (v_[i] == v_[right - 1]) {
                    min = i;
                    break;
                }
                   
            }
        }
        for (int i = 0; i < f; i++) {
            cout << min + 1<<" ";
            v_[min]++;
            min++;
            if (min == right)
                min = left;

        }
        cout << endl;

    }
    return 0;
}

int F_26_1() {
    double n;
    cin >> n;
    vector<double> v(n,0);
    double sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    double p = sum / n;
    cout << "p:" << p << endl;
    double da=double(0.0);
    for (int i = 0; i < n; i++) {
        da += pow((v[i] - p), 2)/n;
    }
    cout << "da:" << da << endl;
    cout << sqrt(da)<< endl;
    for (int i = 0; i < n; i++) {
        cout << setprecision(16) << (v[i] - p) / sqrt(da) << endl;
    }
    return 0;
}

//很nice
int F_26_2() {
    int n, l, s;
    cin >> n >> l >> s;
    vector<pair<int, int>> a;
    set <pair<int,int>> se;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        se.insert({ x,y });
        a.push_back({ x,y });
    }
    vector<vector<int>>B(s+1,vector<int>(s+1,0));
    for (int i = s; i>=0; i--) {
        for (int j = 0; j <= s; j++) {
            cin >> B[i][j];
        }
    }
    int count = 0;
    for (int i = 0; i <a.size(); i++) {
        int x = a[i].first;
        int y = a[i].second;
        if (x + s >l || y + s >l)
            continue;
        bool flag = true;
        for (int j = 0; j <= s; j++) {
            if (flag == false)
                break;
            for (int k = 0; k <= s; k++) {
                auto li = se.find({x+j,y+k});
                int temp;
                if (li == se.end())
                    temp = 0;
                else
                    temp = 1;
                if (temp != B[j][k])
                    flag = false;
            }
        }
        if (flag == true)
            count++;
    }
    cout << count;
    return 0;
}


//20分
int F_26_3() {
    int n, m, q;
    cin >> n >> m >> q;
    string name_;
    int nv_;
    string cz_;
    int no_;
    string lei_;
    int nn_;
    cin >> name_ >> nv_ >> cz_ >> no_ >> lei_ >> nn_;
    string name;
    int ns;
    string ug;
    string ug_name;
    cin >> name >> ns >> ug >> ug_name;
    for (int i = 0; i < q; i++) {
        string user;
        int ng;
        string z_name;
        string cha;
        string z;
        string t;
        cin >> user >> ng >> z_name >> cha >> z >> t;
        if (user == ug_name) {
            if (name == name_) {
                if (cha == cz_ && z == lei_)
                    cout << 1 << endl;
                else
                    cout << 0 << endl;
            }
            else
                cout << 0 << endl;
        }
        else if (z_name == ug_name) {
            if (name == name_) {
                if (cha == cz_ && z == lei_)
                    cout << 1 << endl;
                else
                    cout << 0 << endl;
            }
            else
                cout << 0 << endl;
        }
        else
            cout << 0 << endl;
    }
    return 0;
}

int F_27_1() {
    int n, m;
    cin >> n >> m;
    vector<int> c;
    c.push_back(1);
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        temp = temp * c[i];
        c.push_back(temp);

    }
    vector<int> b(n, 0);
    int temp = m;
    for (int i = n-1; i>=0; i--) {
        b[i] = temp / c[i];
        temp = temp % c[i];
    }
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    return 0;
}

//////////////
int n;
int m = 99999999;
vector<int> v(n, 0);
int x;
void dfs(int sum,int i) {
    if (i >= n)
        return;
    if (sum >= x) {
        m = std::min(m, sum);
        return;
    }
    else {
        dfs(sum + v[i], i + 1);
        dfs(sum, i + 1);
    }

}
int F_27_2() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    dfs(0, 0);
    cout << m;
    return 0;
}

//DP,反向背包问题，如包邮价为x，买的书价格>=x的前提下最小，
//先计算总购物车书价sum，sum-x为背包容量，背包中装的是不买的书在<=sum-x的前提下装的越多越好，最后sum-背包中书价即为最优解******
int F_27_2_() {
    int n, x;
    cin >> n >> x;
    int sum=0;
    vector<int> v(n + 1, 0);
    for (int i = 1; i <=n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    int m = sum - x;
    vector < vector<int>> DP(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (v[i] <= j) {
                DP[i][j] = max(DP[i - 1][j], v[i] + DP[i - 1][j - v[i]]);
            }
            else {
                DP[i][j] = DP[i - 1][j];
            }
        }
    }
    cout << sum - DP[n][m];
    return 0;
}

int F_28_1() {
    int n;
    double i;
    cin >> n >> i;
    vector<int> v(n + 1, 0);
    double sum = 0;
    int pos = -1;
    int c;
    cin >> c;//第0年，以第0年为基准，将之后的钱的价值换算成第0年的钱的价值。
    sum += c;
    for (int j = 1; j <= n; j++) {
        int temp;
        cin >> temp;
        sum = sum + temp * pow((1 + i), -(j));
    }
    cout << sum;
    return 0;
}

int F_28_2() {
    int n, m;
    cin >> n >> m;
    vector<int> p(m, 0);
    vector<int> t(m, 0);
    vector<int> l(m, 0);
    vector<int> r(m, 9999999);
    bool flag = true;
    for (int i = 0; i < m; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> t[i];
    }
    for (int i = 0; i < m; i++) {
        if (p[i] == 0)
            l[i] = 1;
        else {
            l[i] = l[p[i] - 1] + t[p[i] - 1];
            if (l[i] + t[i] - 1 > n)
                flag = false;
        }
        cout << l[i] << " ";
    }
    cout << endl;
    if (flag == true) {
        for (int i = m - 1; i >= 0; i--) {
            if (r[i] == 9999999) {
                r[i] = n - t[i] + 1;
            }
            if (p[i] != 0) {
                r[p[i] - 1] = min(r[i] - t[p[i] - 1], r[p[i] - 1]);//防止有多个后继
            }
        }
    }
    if (flag == true) {
        for (int i = 0; i< m; i++) 
            cout << r[i] << " ";
    }

    return 0;

}

int F_28_3() {
    int Q[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> Q[i][j];
        }
    }
    int n, t;
    cin >> n >> t;
    int M[8][8]{ 0 };
    int zigzag[64][2] = {
    {0,0},{0,1},{1,0},{2,0},{1,1},{0,2},{0,3},{1,2},
    {2,1},{3,0},{4,0},{3,1},{2,2},{1,3},{0,4},{0,5},
    {1,4},{2,3},{3,2},{4,1},{5,0},{6,0},{5,1},{4,2},
    {3,3},{2,4},{1,5},{0,6},{0,7},{1,6},{2,5},{3,4},
    {4,3},{5,2},{6,1},{7,0},{7,1},{6,2},{5,3},{4,4},
    {3,5},{2,6},{1,7},{2,7},{3,6},{4,5},{5,4},{6,3},
    {7,2},{7,3},{6,4},{5,5},{4,6},{3,7},{4,7},{5,6},
    {6,5},{7,4},{7,5},{6,6},{5,7},{6,7},{7,6},{7,7}
    };

    for (int i = 0; i < n; i++) {
        cin >> M[zigzag[i][0]][zigzag[i][1]];
    }
    if (t == 0) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cout << M[i][j] << " ";
            }
            cout << endl;
        }
    }
    if (t == 1) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cout << M[i][j] * Q[i][j] << " ";

            }
            cout << endl;
        }
    }
 
    if (t == 2) {
        // 先反量化
        double A[8][8];
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                A[i][j] = M[i][j] * Q[i][j];
        for (int i = 0; i < 8; i++) {
            for(int j=0;j<8;j++){
                double sum=0;
                for (int u = 0; u < 8; u++) {
                    for (int v = 0; v < 8; v++) {
                        double au = u == 0 ? sqrt(0.5) : 1;
                        double av = v == 0 ? sqrt(0.5) : 1;
                        sum+=A[u][v] * au* av* cos(acos(-1) / 8 * (i + 0.5) * u)* cos(acos(-1) / 8 * (j + 0.5) * v);
                    }
                }
                sum = round(0.25 * sum + 128);
                if (sum > 255)
                    sum = 255;
                if (sum < 0)
                    sum = 0;
                cout << int(sum)<<" ";

            }
            cout << endl;
        }
    }
    return 0;
}

int F_29_1() {
    int n, a, b;
    cin >> n >> a >> b;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > a || y1 > b) {
            continue;
        }
        if (x2 < 0 || y2 < 0)
            continue;
        if (x1 < 0)
            x1 = 0;
        if (y1 < 0)
            y1 = 0;
  
        if (x2 > a)
            x2 = a;
        if (y2 > b)
            y2 = b;
        sum = sum + (y2 - y1) * (x2 - x1);

    }
    cout << sum;
    return 0;
}

int F_29_2() {
    int n, m, k;
    cin >> n >> m >> k;
    priority_queue<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int t, c;
        cin >> t >> c;
        v.push({ t,c });
    }
    while (m != 0) {
        auto p = v.top();
        v.pop();
        if (p.first <= k)
            break;
        m = m - p.first;
        v.push({ p.first - 1,p.second });
    }
    if (v.top().first < k)
        cout << k;
    else
        cout << v.top().first;
    return 0;
}

//二分****二分性
int F_29_2_() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> v;
    int right = 0;
    int left = k;
    for (int i = 0; i < n; i++) {
        int t, c;
        cin >> t >> c;
        right = max(right, t);
        v.push_back({ t,c });
    }
    int pos = 0;
    while (left < right) {
        int mid = (right - left) / 2 + left;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            if (sum > m)
                break;
            if(v[i].first>mid)
                sum = sum + v[i].second * (v[i].first - mid);
        }
        if (sum > m) {
            left = mid + 1;
        }
        else {
            pos = mid;//pos应该取sum<=m时的
            right = mid - 1;
        }
    }
    cout << pos;
    return 0;
}

int F_30_1() {
    int n;
    cin >> n;
    vector<vector<vector<char>>> m(n,vector<vector<char>>(8, vector<char>(8, '*')));
    vector<int>array(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                cin >> m[i][j][k];
            }
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = i-1; j>=0; j--) {
            if (m[i] == m[j]) {
                array[i] = array[j];
                break;
            }
        }
    }
    for (auto p : array)
        cout << p;
    return 0;
}

//哈希法
int F_30_1_() {
    unordered_map<string, int> m;
    for (int i = 0; i < n; i++) {
        string s;
        //每行输入字符串
        for (int j = 0; j < 8; j++) {
            string p;
            cin >> p;
            s += p;
        }
        m[s]++;
        cout << m[s] << endl;
    }  
    return 0;
}

//超出内存
int F_30_2() {
    int n, d;
    cin >> n >> d;
    int Q[10010][21];
    int K[10010][21];
    int V[10010][21];


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            cin >> Q[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            cin >> K[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            cin >> V[i][j];
        }
    }
    int W[10010];
    for (int i = 0; i < n; i++) {
        cin >> W[i];
    }

    long long WQKT[10001][10001];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            long long sum = 0;
            for (int u = 0; u < d; u++) {
                sum = sum + Q[i][u] * K[j][u];
            }
            WQKT[i][j] = sum * W[i];
        }

    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            long long sum = 0;
            for (int u = 0; u < n; u++) {
                sum = sum + WQKT[i][u] * V[u][j];
            }
            cout << sum << " ";
        }
        cout << endl;
    }

    return 0;
}
//(W.(Q*K^T))*V=W.(Q*(K^T*V))
int F_30_2_() {
    int n, d;
    cin >> n >> d;
    int Q[10010][21];
    int K[10010][21];
    int V[10010][21];
    int W[10010];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            cin >> Q[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            cin >> K[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            cin >> V[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> W[i];
    }
   
    long long KTV[21][21];
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {
            long long sum = 0;
            for (int z = 0; z < n; z++) {
                sum = sum + K[z][i] * V[z][j];
            }
            KTV[i][j]=sum;
        }
    }

    long long QKTV[10010][21];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            long long sum = 0;
            for (int z = 0; z < d; z++) {
                sum = sum + Q[i][z] * KTV[z][j];
            }
            QKTV[i][j]=sum;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
           cout<< W[i] * QKTV[i][j]<<" ";
        }
        cout << endl;
    }
    return 0;
}

int F_31_1() {
    int n, m;

    int xsum = 0;
    int ysum = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        int y;
        cin >> x>> y;
        xsum += x;
        ysum += y;
    }
    for (int j = 0; j < m; j++) {
        int x, y;
        cin >> x >> y;
        cout << x + xsum << " " << y + ysum << endl;
    }
    return 0;


}

//前缀和，注意***前缀和缩放是用相乘，旋转是相加，，x*s1*s2*s3=x*(s1*s2*s3)
int F_31_2() {
    int n, m;
    cin >> n >> m;
    vector<pair<double, double>> sum;//前缀和
    sum.push_back({ 1,0 });
    for (int i = 0; i < n; i++) {
        int tag; double p;
        cin >> tag >> p;
        if (tag == 1) {
            sum.push_back({ p * sum[i].first,sum[i].second });
        }
        else {
            sum.push_back({ sum[i].first,sum[i].second + p });
        }
    }
    for (int i = 1; i <= m; i++) {
        int f, l;
        cin >> f >> l;
        double x, y;
        cin >> x >> y;

        x = x * (sum[l].first / sum[f - 1].first);//先缩放
        y = y * (sum[l].first / sum[f - 1].first);
        double xtemp = x;
        double ytemp = y;
        x = xtemp * cos(sum[l].second - sum[f - 1].second) - ytemp * sin(sum[l].second - sum[f - 1].second);//后旋转
        y = xtemp * sin(sum[l].second - sum[f - 1].second) + ytemp * cos(sum[l].second - sum[f - 1].second);
        cout << setprecision(16) << x << " " << y << endl;
    }
    return 0;
}



int F_32_1() {
    int n, m;
    cin >> n >> m;
    int v[1001][11];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        int pos = 0;
        bool flag = true;
        for (int j = 1; j <= n; j++) {
            flag = true;
            if (i == j)
                continue;
            for (int k = 0; k < m; k++) {
                if (flag == false)
                    break;
                if (v[i][k] >= v[j][k])
                    flag = false;
            }
            if (flag == true) {
                pos = j;
                break;
            }
        }
        cout << pos << endl;
    }
    return 0;
}


void F(long long p,unordered_map<int,int>& h) {
    if (p == 2) {
        h[2]++;
        return;
    }
    long long i = 2;
    long long j;
    while (i != p) {
        if (p % i == 0) {
            j = p / i;
            break;
        }
        i++;
    }
    if (i == p) {
        h[i]++;
    }
    if (i != p) {
        F(i,h);
        F(j,h);
    }

}

void F_(long long n, unordered_map<int, int>& h) {
    while (n % 2 == 0) {
        h[2]++;
        n = n / 2;
    }
    for (int i = 3; i <= n; i+=2) {
        while (n % i == 0) {
            h[i]++;
            n = n / i;
        }
    }
}

void F__(long long n, unordered_map<int, int>& h) {
    for (int i = 2; i*i <= n; i++) {//只需要遍历到√n就好 ，例如81：1，3，9，9，27只需要遍历到9就好
        while (n % i == 0) {
            h[i]++;
            n = n / i;
        }
    }
    if (n > 1)
        h[n]++;//处理最后省的
}
int F_32_2() {
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        long long n;int k;
        cin >> n >> k;
        unordered_map<int, int> h;
        F_(n,h);
        long long sum = 1;
        for (auto p:h) {
            if (p.second < k)
                continue;
            sum = sum * pow(p.first, p.second);
        }
            cout << sum << endl;
    }
    return 0;
}

int F_33_1() {
    int n, m;
    cin >> n >> m;
    unordered_map<int, int> ma;
    vector<int>v(m+1, 0);
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        unordered_set<int> s;
        for (int j = 0; j < p; j++) {
            int temp;
            cin >> temp;
            ma[temp]++;
            s.insert(temp);
        }
        for (auto t : s) {
            v[t]++;
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << v[i] << " " << ma[i]<<endl;
    }
    return 0;
}

int F_33_2() {
    int n,m;
    cin >> n >> m;
    unordered_set<string> se;
    unordered_map<string, int>ma;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (auto& p : s) {
            p = tolower(p);
        }
        se.insert(s);
        if (ma[s] == 0)
            ma[s]++;
    }
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        for (auto& p : s) {
            p = tolower(p);
        }
        se.insert(s);
        if (ma[s] == 1) {
            ma[s]++;
            sum++;
        }

    }
    cout << sum << endl;
    cout << se.size() << endl;
    return 0;
}

int F_34_1(){
    int n,m,p,q;
    cin>>n>>m>>p>>q;
    queue<int> que;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int temp;
            cin>>temp;
            que.push(temp);
        }
    }
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            cout<<que.front()<<" ";
            que.pop();
        }
        cout<<endl;
    }

    return 0;
}

int F_34_2(){
    int n,m,t;
    cin>>n>>m>>t;
    vector<int> vec;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int temp;
            cin>>temp;
            vec.push_back(temp); 
        }
    }
    int x=n;
    int y=m;
    for(int i=0;i<t;i++){
        int temp1,temp2,temp3;
        cin>>temp1>>temp2>>temp3;
        if(temp1==1){
            x=temp2;
            y=temp3;
        }
        if(temp1==2){
            vector<int>v;
            for(int j=0;j<y;j++){
                for(int z=0;z<x;z++){
                    v.push_back(vec[j+z*y]);
                }
            }
            vec=v;
            swap(x,y);
        }
        if(temp1==3){
            cout<<vec[temp2*y+temp3]<<endl;
        }
    }
    return 0;
}

int F_35_1(){
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        unordered_map<char,int> ma;
        bool h=true;
        bool m_1=false;
        bool m_2=false;
        bool m_3=false;
        string s;
        cin>>s;
        for(auto c:s){
            ma[c]++;
            if(ma[c]>2)
                h=false;
            if(isalpha(c)){//为字母
                m_1=true;
            }
            else if(isdigit(c))//为数字
                m_2=true;
            else{
                m_3=true;
            }
        }
        if(h&&m_1&&m_2&&m_3)
            cout<<2<<endl;
        else if(m_1&&m_2&&m_3)
            cout<<1<<endl;
        else
            cout<<0<<endl;
            
    }
    return 0;
}

int F_35_2(){
    string s;
    getline(cin,s);
    int n;
    cin>>n;//注意cin会忽略后面的换行符，因此getline会读取到换行符，因此要清理缓冲区
    cin.ignore();
    unordered_map<char,char>ma;
    for(int i=0;i<n;i++){
        string pa;
        getline(cin,pa);
        ma[pa[1]]=pa[2];
    }
    int k;
    cin>>k;
    while(k--){
        for(auto& c:s){
            if(ma.find(c)!=ma.end()){
                c=ma[c];
            }
        }
        cout<<s<<endl;
    }
    return 0;
}

int F_36_1(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        string s;
        cin>>s;
        for(auto c:s){
            if(c=='f'){
                if(y<n){
                    y++;
                }
            }
            if(c=='r'){
                if(x<n){
                    x++;
                }
            }
            if(c=='b'){
                if(y>1){
                    y--;
                }
            }
            if(c=='l'){
                if(x>1){
                    x--;
                }
            }
        }
        cout<<x<<" "<<y<<endl;
    }
    return 0;
}

///////没想明白
int F_36_2(){
    int n;
    cin>>n;
    int a[100010]{0};
    int b[100010]{0};
    for(int i=0;i<n+1;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    int a_sum[100010]{0};
    int b_sum[100010]{0};
    for(int i=1;i<n+1;i++){
        a_sum[i]=a_sum[i-1]+a[i];
        b_sum[i]=b_sum[i-1]+b[i];
    }
    for(int i=1;i<n+1;i++){
        int w=0;
        for(int j=1;j<=n;j++){
            if(j<i){
                w=max(w,a_sum[j]-b_sum[j]+a[0]);
            }
            if(j>=i){   
                w=max(w,a_sum[j]-b_sum[j]+b[i]+a[0]);
            }
        }
        cout<<max(w,a[0])<<" ";
    }
    return 0;
}

int F_37_1(){
    int b,c,l,r;
    cin>>b>>c>>l>>r;
    long long sum=0;
    if(l%2!=0){
        l++;
    }
    while(l<=r){
        sum=sum+pow(l,2)+b*l+c;
        l+=2;
    }
    cout<<2*sum<<endl;
    return 0;
}

//背包问题，不过每个物品可以重复拿
int F_37_2(){
    int n,m;
    cin>>n>>m;
    vector<int>v;
    for(int i=0;i<m;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    vector<int>w;
    for(int i=1;i<=m;i++){
        w.push_back(i);
    }
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(w[i-1]<=j){
                int temp=j/w[i-1];
                dp[i][j]=max(max(dp[i-1][j],dp[i-1][j-w[i-1]]+v[i-1]),v[i-1]*temp+dp[i-1][j-temp*w[i-1]]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[m][n]<<endl;
    return 0;
}

class node{
    public:
    string name;
    string val;
};
int F_37_3(){
    int n;
    cin>>n;
    unordered_map<string,string> ma;
    for(int i=0;i<n;i++){
        int p;
        string name;
        string val;
        cin>>p;
        if(p==1||p==2){
            cin>>name;
            getline(cin,val);
            if(val[0]==' '){
                val=val.substr(1);//去掉前面的空格
            }
        }
        else{
            cin>>name;
        }
        vector<string> v;
        string temp;
        stringstream ss(val);
        while(ss>>temp){
            v.push_back(temp);
        }

        if(p==1){
            string temp;
            for(auto val:v){
                if(val[0]=='$'){
                    temp+=ma[val.substr(1)];
                }
                else{
                    temp+=val;
                }
            }
            ma[name]=temp;
        }
        if(p==2){

        }
        if(p==3){
            cout<<ma[name].size()%1000000007<<endl;
        }
    }
    return 0;
}
int main(){ 
    F_37_3();
    return 0;
}