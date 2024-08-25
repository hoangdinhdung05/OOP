#include<bits/stdc++.h>

using namespace std;

//Bai 12:

class Monhoc{
    private:
        string monhoc;
        int diemcc, diemkt, dt;
    public:
        Monhoc(){
            monhoc = "";
            diemcc = diemkt = dt = 0;
        }
        void in();
        void out();
        double getTongdiem();
};

class Sinhvien : public Monhoc{
    private:
        string ten, lop, msv;
    public:
        Sinhvien(){
            ten = lop = msv = "";
        }
        void in();
        void out();
};

void Monhoc::in(){
    cin >> monhoc >> diemcc >> diemkt >> dt;
}

double Monhoc::getTongdiem(){
    return diemcc*0.1+diemkt*0.3+dt*0.6;
}

void Monhoc::out(){
    if(diemcc >= 5){
        cout << monhoc << " " << diemcc << " " << diemkt << " " << getTongdiem() << endl;
    }
}

void Sinhvien::in(){
    cin.ignore();
    getline(cin, ten);
    cin >> lop >> msv;
    Monhoc::in();
}

void Sinhvien::out(){
    cout << ten << " " << lop << " " << msv << " ";
    Monhoc::out();
}


int main(){
    int n; cin >> n;
    Sinhvien a[n];
    for(int i = 0; i < n; i++){
        cin.ignore();
        a[i].in();
    }
    for(int i = 0; i < n; i++){
        a[i].out();
    }
    return 0;
}