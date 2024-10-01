#include <bits/stdc++.h>

using namespace std;

class nhansu {
    private:
        string mnv, ten, ns;
    public:
        nhansu() {
            mnv = ten = ns = "";
        }
        nhansu(string mnv, string ten, string ns) {
            this->mnv = mnv;
            this->ten = ten;
            this->ns = ns;
        }

        void nhap();
        void in();
};

class canbo : public nhansu {
    private:
        double luong, hsl;
    public:
        canbo() {
            luong = hsl = 0.0;
        }
        canbo(double luong, double hsl) {
            this->luong = luong;
            this->hsl = hsl;
        }

        void nhap();
        void in();

        friend double tong(canbo);
        friend bool cmp(canbo, canbo);
};

void nhansu::nhap() {
    cin >> mnv;
    cin.ignore();
    getline(cin, ten);
    cin >> ns;
}

void nhansu::in() {
    cout << mnv << " " << ten << " " << ns << " ";
}

void canbo::nhap() {
    nhansu::nhap();
    cin >> luong >> hsl;
}

void canbo::in() {
    nhansu::in();
    cout << luong << " " << hsl << " ";
}

double tong(canbo a) {
    return a.luong * a.hsl;
}

bool cmp(canbo a, canbo b) {
    return tong(a) > tong(b);
}

class congnhan : public nhansu {
    private:
        int ngay;
    public:
        congnhan() {
            ngay = 0;
        }
        congnhan(int ngay) {
            this->ngay = ngay;
        }

        void nhap();
        void in();

        int getNgay() {
            return ngay;
        }

        friend double thuong(congnhan);
};

void congnhan::nhap() {
    nhansu::nhap();
    cin >> ngay;
}

void congnhan::in() {
    nhansu::in();
    cout << ngay << " ";
}

double thuong(congnhan a) {
    return a.ngay * 100000;
}

int main() {
    int n;
    cin >> n;

    vector<canbo> a(n);
    vector<congnhan> b(n);

    cout << "Nhap danh sach can bo\n";
    for (auto &x : a) {
        x.nhap();
    }

    cout << "Danh sach can bo sau sap xep: \n";
    sort(a.begin(), a.end(), cmp);
    for (auto x : a) {
        x.in();
        cout << tong(x) << endl;
    }

    cout << "\nNhap danh sach cong nhan\n";
    for (auto &x : b) {
        x.nhap();
    }

    cout << "Danh sach cong nhan lam hon 26 ngay: \n";
    for (int i = 0; i < n; i++) {
        if (b[i].getNgay() > 26) {
            b[i].in();
            cout << thuong(b[i]) << endl;
        }
    }

    return 0;
}
