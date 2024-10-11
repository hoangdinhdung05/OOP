#include<bits/stdc++.h>

using namespace std;

class sinhvien{
    private:
        string ten, ns;
        double mon1, mon2, mon3, mon4, mon5;
    public:
        sinhvien(){
            ten = ns = "";
            mon1 = mon2 = mon3 = mon4 = mon5 = 0.0;
        }
        sinhvien(string ten, string ns, double mon1, double mon2, double mon3, double mon4, double mon5){
            this->ten = ten;
            this->ns = ns;
            this->mon1 = mon1;
            this->mon2 = mon2;
            this->mon3 = mon3;
            this->mon4 = mon4;
            this->mon5 = mon5;
        }

        void nhap();
        void xuat();

        friend double diemTB(sinhvien);
        friend double quyDoi(sinhvien);

        friend bool checkTN(sinhvien);
        friend bool checkDA(sinhvien);

};

void sinhvien::nhap(){
    cin.ignore();
    cout << "Nhap ten sinh vien: "; getline(cin, ten);
    cout << "Nhap ns: "; cin >> ns;
    cout << "Nhap diem mon 1: "; cin >> mon1;
    cout << "Nhap diem mon 2: "; cin >> mon2;
    cout << "Nhap diem mon 3: "; cin >> mon3;
    cout << "Nhap diem mon 4: "; cin >> mon4;
    cout << "Nhap diem mon 5: "; cin >> mon5;
}

void sinhvien::xuat(){
    cout << ten << " " << ns << " " << mon1 << " " << mon2 << " " << mon3 << " " << mon4 << " " << mon5 << endl;
    cout << "Diem trung binh: " << diemTB(*this) << endl;
    cout << "Diem quy doi: " << quyDoi(*this) << endl;
}

double diemTB(sinhvien a){
    return (a.mon1 + a.mon2 + a.mon3 + a.mon4 + a.mon5) / 5;
}

double quyDoi(sinhvien a){
    double dtb = diemTB(a);
    if (dtb >= 8.5) {
        return 4.0;
    } else if (dtb >= 7.0) {
        return 3.0;
    } else if (dtb >= 5.5) {
        return 2.0;
    } else if (dtb >= 4.0) {
        return 1.0;
    } else {
        return 0.0;
    }

}

bool checkTN(sinhvien a){
    if(diemTB(a) < 7 && a.mon1 > 5 && a.mon2 > 5 && a.mon3 > 5 && a.mon4 > 5 && a.mon5 > 5){
        return true;
    }
    return false;
}

bool checkDA(sinhvien a){
    if(diemTB(a) >= 7 && a.mon1 >= 5 && a.mon2 >= 5 && a.mon3 >= 5 && a.mon4 >= 5 && a.mon5 >= 5){
        return true;
    }
    return false;
}

int main(){
    int n; cin >> n;
    vector<sinhvien> v(n);
    for(auto &x : v){
        cin.ignore();
        x.nhap();
    }
    cout << "Danh sach sinh vien: \n";
    for(auto x : v){
        x.xuat();
    }
    cout << endl;
    cout << "Danh sach sinh vien phai thi tot nghiep: \n";
    for(auto x : v){
        if(checkTN(x)){
            x.xuat();
        }
    }
    cout << endl;
    cout << "Danh sach sinh vien lam do an: \n";
    for(auto x : v){
        if(checkDA(x)){
            x.xuat();
        }
    }
    return 0;
}