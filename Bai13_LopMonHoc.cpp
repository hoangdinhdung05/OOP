#include<bits/stdc++.h>

using namespace std;

class monhoc{
    private:
        string tenmh;
        double diemcc, diemkt, diemth;
    public:
        monhoc(){
            tenmh = "";
            diemcc = diemkt = diemth = 0.0;
        }

        monhoc(string tenmh, double diemcc, double diemkt, double diemth){
            this->tenmh = tenmh;
            this->diemcc = diemcc;
            this->diemkt = diemkt;
            this->diemth = diemth;
        }

        void nhap();
        void xuat();

        double tongdiem(monhoc);

        double getDiemcc(){
            return diemcc;
        }

        double getDiemkt(){
            return diemkt;
        }

};

void monhoc::nhap(){
    cout << "Nhap ten mon hoc: "; cin >> tenmh;
    cout << "Nhap diem chuyen can: "; cin >> diemcc;
    cout << "Nhap diem kiem tra: "; cin >> diemkt;
    cout << "Nhap diem thuc hanh: "; cin >> diemth;
}

//tinh tong diem hoc phan
double monhoc::tongdiem(monhoc a){
    return a.diemcc*0.1 + a.diemkt*0.3 + a.diemth*0.6;
}

void monhoc::xuat(){
    cout << tenmh << " " << diemcc << " " << diemkt << " " << diemth << " " << tongdiem(*this) << endl;
}

class sinhvien : public monhoc{
    private:    
        string msv, ten;
    public:
        sinhvien(){
            msv = ten = "";
        }

        sinhvien(string msv, string ten){
            this->msv = msv;
            this->ten = ten;
        }

        void nhap();
        void xuat();
};

void sinhvien::nhap(){
    cout << "Nhap ma sinh vien: "; cin >> msv;
    cin.ignore();
    cout << "Nhap ten sinh vien: "; getline(cin, ten);
    monhoc::nhap();
}

void sinhvien::xuat(){
    cout << msv << " " << ten << " ";
    monhoc::xuat();
}

int main(){
    int n; cin >> n;
    vector<sinhvien> v(n);
    for(auto &x : v){
        x.nhap();
    }
    cout << "Xuat thong tin sinh vien:\n";
    for(auto x : v){
        x.xuat();
    }
    cout << endl;
    cout << "Danh sach sinh vien bi cam thi: \n";
    for(auto x : v){
        if(x.getDiemcc() < 5.0 || x.getDiemkt() == 0){
            x.xuat();
        }
    }
    cout << endl;
    cout << "Danh sach sinh vien phai thi lai: \n";
    for(auto x : v){
        if(x.tongdiem(x) < 4.0){
            x.xuat();
        }
    }
    return 0;
}