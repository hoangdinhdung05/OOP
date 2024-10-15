#include <bits/stdc++.h>
using namespace std;

class phanso {
protected:
    int tu, mau;
public:
    phanso() {
        this->tu = 0;
        this->mau = 1;
    }

    phanso(int a, int b) {
        this->tu = a;
        this->mau = b;
    }

    void nhap();
    void xuat();
    void toigian();

    phanso operator + (phanso);
    phanso operator - (phanso);
    phanso operator * (phanso);
    phanso operator / (phanso);
};

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

void phanso::toigian() {
    int uc = gcd(tu, mau);
    tu /= uc;
    mau /= uc;
}

void phanso::nhap() {
    cin >> tu;
    do {
        cin >> mau;
        if (mau == 0) {
            cout << "Mau so khong hop le, vui long nhap lai:\n";
        }
    } while (mau == 0);
    toigian();
}

void phanso::xuat() {
    if (this->tu == this->mau) cout << 1 << endl;
    else if (this->tu == 0) cout << 0 << endl;
    else cout << this->tu << "/" << this->mau << endl;
}

phanso phanso::operator + (phanso a) {
    phanso b;
    b.tu = this->tu * a.mau + this->mau * a.tu;
    b.mau = this->mau * a.mau;
    return b;
}

phanso phanso::operator - (phanso a) {
    phanso b;
    b.tu = this->tu * a.mau - this->mau * a.tu;
    b.mau = this->mau * a.mau;
    return b;
}

phanso phanso::operator * (phanso a) {
    phanso b;
    b.tu = this->tu * a.tu;
    b.mau = this->mau * a.mau;
    return b;
}

phanso phanso::operator / (phanso a) {
    phanso b;
    b.tu = this->tu * a.mau;
    b.mau = this->mau * a.tu;
    return b;
}

class phanso2 : public phanso {
public:
    phanso2& operator= (phanso2&); // gan bang
    bool operator< (phanso2); // so sanh tra ve true false
    bool operator> (phanso2); // so sanh tra ve true false

    friend void phansoMax(vector<phanso2>&);
    friend void phansoMin(vector<phanso2>&);
    friend void sortTang(vector<phanso2>&);
    friend void sortGiam(vector<phanso2>&);

    int getMau() {
        return mau;
    }
};

phanso2& phanso2::operator= (phanso2& a) {
    this->tu = a.tu;
    this->mau = a.mau;
    return *this; // trả về con trỏ this của đối tượng
}

bool phanso2::operator < (phanso2 a) {
    return (this->tu * a.mau < this->mau * a.tu);
}

bool phanso2::operator > (phanso2 a) {
    return (this->tu * a.mau > this->mau * a.tu);
}

void phansoMax(vector<phanso2>& v) {
    if (v.empty()) {
        cout << "Khong co phan so hop le de xu ly.\n";
        return;
    }
    else {
        phanso2 _max = v[0];
        for (auto x : v) {
            if (x > _max) {
                _max = x;
            }
        }
        cout << "Phan so lon nhat: ";
        _max.xuat();
    }
}

void phansoMin(vector<phanso2>& v) {
    if (v.empty()) {
        cout << "Khong co phan so hop le de xu ly.\n";
        return;
    }
    else {
        phanso2 _min = v[0];
        for (auto x : v) {
            if (x < _min) {
                _min = x;
            }
        }
        cout << "Phan so nho nhat: ";
        _min.xuat();
    }
}

void sortTang(vector<phanso2>& v) {
    if(v.empty()) {
        cout << "Khong co phan so hop le de xu ly.\n";
        return;
    }
    else {
        for(int i = 0; i < v.size() - 1; i++) {
            int minIndex = i;
            for(int j = i + 1; j < v.size(); j++) {
                if(v[minIndex] > v[j]) {
                    minIndex = j;
                }
            }
            phanso2 tmp = v[i];
            v[i] = v[minIndex];
            v[minIndex] = tmp;
        }
    }
}

void sortGiam(vector<phanso2>& v) {
    if(v.empty()) {
        cout << "Khong co phan so hop le de xu ly.\n";
        return;
    }
    else {
        for(int i = 0; i < v.size() - 1; i++) {
            int maxIndex = i;
            for(int j = i + 1; j < v.size(); j++) {
                if(v[maxIndex] < v[j]) {
                    maxIndex = j;
                }
            }
            phanso2 tmp = v[i];
            v[i] = v[maxIndex];
            v[maxIndex] = tmp;
        }
    }
}

int main() {
    cout << "Nhap so luong phan so 2: ";
    int n; cin >> n;
    vector<phanso2> v;

    for (int i = 0; i < n; i++) {
        phanso2 x;
        x.nhap();
        // Kiểm tra mẫu số trước khi thêm vào danh sách
        if (x.getMau() != 0) {
            v.push_back(x);
        }
    }

    // Kiểm tra nếu không có phân số hợp lệ
    if (v.empty()) {
        cout << "Khong co phan so hop le de xu ly.\n";
        return 0;
    }

    cout << "Danh sach phan so 2 sau khi nhap: \n";
    for (auto x : v) {
        x.xuat();
    }

    cout << endl;
    phansoMax(v);
    cout << endl;
    phansoMin(v);
    cout << endl;

    cout << "Sap xep tang dan: \n";
    sortTang(v);
    for (auto x : v) {
        x.xuat();
    }
    cout << endl;

    cout << "Sap xep giam dan: \n";
    sortGiam(v);
    for (auto x : v) {
        x.xuat();
    }
    return 0;
}
