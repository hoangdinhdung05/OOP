#include<bits/stdc++.h>

using namespace std;
using ll = long long;

//Bai 10

class Nhansu{
    private:
        string mnv, ten, ns;
    public:
        Nhansu(){
            mnv = ten = ns = "";
        }
        void in();
        void out();
};

class Canbo : public Nhansu{
    private:
        ll luongcoban;
        int hesoluong;
    public:
        Canbo(){
            luongcoban = hesoluong = 0;
        }
        void in();
        void out();
        ll getLuong();
};

void Nhansu::in(){
    cin >> mnv;
    cin.ignore();
    getline(cin, ten);
    cin >> ns;
}

void Nhansu::out(){
    cout << mnv << " " << ten << " " << ns << " ";
}

void Canbo::in(){
    Nhansu::in();
    cin >> luongcoban >> hesoluong;
}


ll Canbo::getLuong(){
    return (luongcoban*hesoluong);
}

void Canbo::out(){
    Nhansu::out();
    cout << getLuong() << endl;
}

bool cmp(Canbo a, Canbo b){
    return a.getLuong() > b.getLuong();
}

int main(){
    int n; cin >> n;
    Canbo a[n];
    for(int i = 0; i < n; i++){
        cin.ignore();
        a[i].in();
    }
    cout << "Danh sach NV\n";
    for(int i = 0; i < n; i++){
        a[i].out();
    }
    cout << "Danh sach sx\n";
    sort(a, a+n, cmp);
    for(int i = 0; i < n; i++){
        a[i].out();
    }
    return 0;
}