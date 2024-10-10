#include<bits/stdc++.h>

using namespace std;

class canbo{
    private:
        string mcb, mdv, ten, ns;
    public:
        canbo(){
            mcb = mdv = ten = ns = "";
        }

        canbo(string mcb, string mdv, string ten, string ns){
            this->mcb = mcb;
            this->mdv = mdv;
            this->ten = ten;
            this->ns = ns;
        }

        void nhap();
        void xuat();
};

void canbo::nhap(){
    cout << "Nhap ma can bo: ";
    cin >> mcb;
    cout << "Nhap ma don vi: ";
    cin >> mdv;
    cin.ignore();
    cout << "Nhap ten: ";
    cin.ignore();
    getline(cin, ten);
    cout << "Nhap ngay sinh: ";
    getline(cin, ns);
}

void canbo::xuat(){
    cout << mcb << " " << mdv << " " << ten << " " << ns << " ";
}

class luong : public canbo{
    private:
        double phucap, hsl, baohiem;
    public:
        luong(){
            phucap = hsl = baohiem = 0.0;
        }

        luong(double phucap, double hsl, double baohiem){
            this->phucap = phucap;
            this->hsl = hsl;
            this->baohiem = baohiem;
        }
        
        void nhap();
        void xuat();

        friend double tong(luong); // tinh tong luong
        friend double cmp(luong, luong);  
};

void luong::nhap(){
    canbo::nhap();
    cout << "Phu cap: ";
    cin >> phucap;
    cout << "He so luong: ";
    cin >> hsl;
    cout << "Bao hiem: ";
    cin >> baohiem;
}

double tong(luong x){
    return x.phucap + x.hsl + x.baohiem;
}

double cmp(luong a, luong b){
    return tong(a) < tong(b);
}

void luong::xuat(){
    canbo::xuat();
    cout << phucap << " " << hsl << " " << baohiem << " " << tong(*this) << " " << endl;
    //tra ve luong cua doi tuong
}

int main(){
    cout << "Nhap so luong can bo: ";
    int n;
    cin >> n;
    cin.ignore();
    vector<luong> v(n);
    for(int i = 0; i < n; i++){
        v[i].nhap();
    }
    for(auto x : v){
        x.xuat();
    }
    //sort luong
    sort(v.begin(), v.end(), cmp);
    for(auto x : v){
        x.xuat();
    }
    return 0;
}


