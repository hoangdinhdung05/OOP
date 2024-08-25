#include<bits/stdc++.h>

using namespace std;
using ll = long long;

//Bai 11
// 3
// CN001
// Nguyen Van A
// 1990-01-01
// 28
// CN002
// Tran Thi B
// 1991-02-02
// 25
// CN003
// Le Van C
// 1992-03-03
// 27


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

class Congnhan : public Nhansu{
    private:
        int ngaycong;
    public:
        Congnhan(){
            ngaycong = 0;
        }

        void in();
        void out();
        int getNgaycong(){
            return ngaycong;
        }
        int getThuong();
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

void Congnhan::in(){
    Nhansu::in();
    cin >> ngaycong;
}

int Congnhan::getThuong(){
    if(getNgaycong() >= 26) return (30-getNgaycong())*100;
    else return 0;
}

void Congnhan::out(){
    Nhansu::out();
    cout << ngaycong << " " << getThuong() << endl;
}

int main(){
    int n; cin >> n;
    Congnhan a[n];
    for(int i = 0; i < n; i++){
        cin.ignore();
        a[i].in();
    }
    for(int i = 0; i < n; i++){
        a[i].out();
    }
    return 0;
}