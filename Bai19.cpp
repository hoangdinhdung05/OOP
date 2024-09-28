#include<bits/stdc++.h>

using namespace std;

class PS1{
    //protected lop cha la private lop con
    protected:
        int tu, mau;
    public:
        PS1(){
            tu = 0;
            mau = 1;
        }
        PS1(int tu, int mau){
            this->tu = tu;
            this->mau = mau;
        }

        void nhap();
        void in();
        void toigian();

};

//ham tim ucln
int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a % b);
}

void PS1::nhap(){
    cin >> tu;
    //kiem tra mau khac khong
    do
    {
        /* code */
        cin >> mau;
        if(mau == 0) cout << "Nhap lai gia tri khac khong\n";
    } while (mau == 0);
    //goi ham 
    toigian();
}

void PS1::toigian(){
    int uc = gcd(tu, mau);
    tu /= uc;
    mau /= uc;
}

void PS1::in(){
    cout << tu << "/" << mau << endl;
}

class PS2 : public PS1{
    public:
        PS2& operator = (PS2&);
        bool operator < (PS2);
        bool operator > (PS2);
        // friend bool cmp(PS2&, PS2&);
};

PS2& PS2::operator = (PS2& a){
    //tra ve doi tuong this
    tu = a.tu;
    mau = a.mau;
    return *this;
}

bool PS2::operator < (PS2 a){
    return (this->tu * a.mau < this->mau * a.tu);
}

bool PS2::operator > (PS2 a){
    return (this->tu * a.mau > this->mau * a.tu);
}

// void sx(vector<PS2>& v){
//     for(int i = 0; i < v.size()-1; i++){
//         int min = i;
//         for(int j = i + 1; j < v.size(); i++){
//             if(v[min] > v[j]){
//                 min = j;
//             }
//         }
//         PS2 tmp = v[i];
//         v[i] = v[min];
//         v[min] = tmp;
//     }
// }


int main(){
    int n; cin >> n;
    vector<PS2> v(n);
    for(int i = 0; i < n; i++){
        v[i].nhap();
    }
    PS2 _max = v[0], _min = v[0];
    for(auto x : v){
        if(x > _max){
            _max = x;
        }
        if(x < _min){
            _min = x;
        }
    }
    _max.in();
    cout << endl;
    _min.in();
    
    return 0;
}