#include<bits/stdc++.h>

using namespace std;

class sinhvien{
    protected:
        string msv, ten, ns, gt;
        double gpa;
    public:
        sinhvien(){
            msv = ten = ns = gt = "";
            gpa = 0.0;
        }
        sinhvien(string msv, string ten, string ns, string gt, double gpa){
            this->msv = msv;
            this->ten = ten;
            this->ns = ns;
            this->gt = gt;
            this->gpa = gpa;
        }

        void nhap();
        void xuat();

        string getGt(){
            return gt;
        }
        double getGpa(){
            return gpa;
        }
};

void sinhvien::nhap(){
    cin >> msv;
    cin.ignore();
    getline(cin, ten);
    cin >> ns >> gt >> gpa;
}

void sinhvien::xuat(){
    cout << msv << " " << ten << " " << ns << " " << gt << " " << gpa << " ";
}


class sinhvienHTTT : public sinhvien{
    private:
        double hocphi;
    public:
        sinhvienHTTT(){
            hocphi = 0;
        }

        sinhvienHTTT(double hocphi){
            this->hocphi = hocphi;
        }

        void nhap();
        void xuat();

};

void sinhvienHTTT::nhap(){
    sinhvien::nhap();
    cin >> hocphi;
}

void sinhvienHTTT::xuat(){
    sinhvien::xuat();
    cout << hocphi << endl;
}

class sinhvienUTT : public sinhvien{
    private:
        string donvi;
        double luong;
    public:
        sinhvienUTT(){
            donvi = "";
            luong = 0;
        }
        sinhvienUTT(string donvi, double luong){
            this->donvi = donvi;
            this->luong = luong;
        }

        void nhap();
        void xuat();

};

void sinhvienUTT::nhap(){
    sinhvien::nhap();
    cin.ignore();
    getline(cin, donvi);
    cin >> luong;
}


void sinhvienUTT::xuat(){
    sinhvien::xuat();
    cout << donvi << " " << luong << endl;
}

int main(){
    int n; cin >> n;
    vector<sinhvienHTTT> v(n);
    for(auto &x : v){
        x.nhap();
    }
    for(auto x : v){
        if(x.getGt() == "Nu" && x.getGpa() >= 6.5){
            x.xuat();
        }
    }
    return 0;
}