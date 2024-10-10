#include<bits/stdc++.h>

using namespace std;

class nhansu{
    private:
        string mnv, ten, ns;
    public:
        nhansu(){
            mnv = ten = ns = "";
        }

        nhansu(string mnv, string ten, string ns){
            this->mnv = mnv;
            this->ten = ten;
            this->ns = ns;
        }

        void nhap();
        void xuat();
};

void nhansu::nhap(){
    cin >> mnv;
    cin.ignore();
    getline(cin, ten);
    cin >> ns;
}

void nhansu::xuat(){
    cout << mnv << " " << ten << " " << ns << " ";
}

class canbo : public nhansu{
    private:
        double luongcoban, hesoluong;
    public:
        canbo(){
            luongcoban = hesoluong = 0.0;
        }

        canbo(double luongcoban, double hesoluong){
            this->luongcoban = luongcoban;
            this->hesoluong = hesoluong;
        }

        void nhap();
        void xuat();

        friend bool cmp(canbo, canbo);
        friend double tong(canbo);
};

void canbo::nhap(){
    nhansu::nhap();
    cin >> luongcoban >> hesoluong;
}

void canbo::xuat(){
    nhansu::xuat();
    cout << luongcoban << " " << hesoluong << " " << tong(*this) << endl;
}

double tong(canbo a){
    return a.luongcoban * a.hesoluong;
}

bool cmp(canbo a, canbo b){
    return tong(a) > tong(b);
}

int main(){
    int n; cin >> n;
    vector<canbo> v(n);
    for(int i = 0; i < n; i++){
        v[i].nhap();
    }
    sort(v.begin(), v.end(), cmp);
    for(auto x : v){
        x.xuat();
    }
    return 0;
}