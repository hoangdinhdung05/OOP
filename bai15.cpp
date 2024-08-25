#include<bits/stdc++.h>

using namespace std;
using ll = long long;


class Canbo{
    private:
        string mcb, mdv, ten, ns;
    public:
        Canbo(){
            mcb = mdv = ten = ns = "";
        }
        void in();
        void out();
};

class Luong : public Canbo{
    private:
        ll phucap, hesoluong, baohiem;
    public:
        Luong(){
            phucap = hesoluong = baohiem = 0;
        }
        void in();
        void out();
        ll getTongluong();
};

void Canbo::in(){
    cin >> mcb >> mdv;
    cin.ignore();
    getline(cin, ten);
    cin >> ns;
}

void Canbo::out(){
    cout << mcb << " " << mdv << " " << ten << " " << ns << " ";
}

void Luong::in(){
    Canbo::in();
    cin >> phucap >> hesoluong >> baohiem;
}

ll Luong::getTongluong(){
    return hesoluong*290+phucap-baohiem;
}

void Luong::out(){
    Canbo::in();
    cout << getTongluong() << endl;
}


int main(){
    int n; cin >> n;
    Luong a[n];
    for(int i = 0; i < n; i++){
        cin.ignore();
        a[i].in();
    }
    for(int i = 0; i < n; i++){
        a[i].out();
    }
    return 0;
}