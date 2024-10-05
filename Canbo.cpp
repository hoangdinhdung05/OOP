#include <bits/stdc++.h>

using namespace std;

class canbo {
private:
    string ten, ns, gt, dc;
public:
    canbo() {
        ten = ns = gt = dc = "";
    }
    canbo(string ten, string ns, string gt, string dc) {
        this->ten = ten;
        this->ns = ns;
        this->gt = gt;
        this->dc = dc;
    }

    virtual void xuat();

    virtual string getMa() = 0;  // Declare as pure virtual

    string getTen() {
        return ten;
    }

    void setTen(string ten) {
        this->ten = ten;
    }

    void setNs(string ns) {
        this->ns = ns;
    }

    void setGt(string gt) {
        this->gt = gt;
    }

    void setDc(string dc) {
        this->dc = dc;
    }
};

void canbo::xuat() {
    cout << ten << " " << ns << " " << gt << " " << dc;
}

class congnhan : public canbo {
private:
    string ma, bac;
public:
    congnhan() {
        ma = bac = "";
    }

    congnhan(string ma, string bac, string ten, string ns, string gt, string dc) : canbo(ten, ns, gt, dc) {
        this->ma = ma;
        this->bac = bac;
    }

    void xuat();

    string getMa() override {  // Override the getMa method
        return ma;
    }

    void setMaql(string ma) {
        this->ma = ma;
    }

    void setBac(string bac) {
        this->bac = bac;
    }
};

void congnhan::xuat() {
    cout << ma << " " << bac << " ";
    canbo::xuat();
    cout << endl;
}

class kysu : public canbo {
private:
    string ma, nganh;
public:
    kysu() {
        ma = nganh = "";
    }
    kysu(string ma, string nganh, string ten, string ns, string gt, string dc) : canbo(ten, ns, gt, dc) {
        this->ma = ma;
        this->nganh = nganh;
    }

    void xuat();

    string getMa() override {  // Override the getMa method
        return ma;
    }

    void setMaks(string ma) {
        this->ma = ma;
    }

    void setNganh(string nganh) {
        this->nganh = nganh;
    }
};

void kysu::xuat() {
    cout << ma << " ";
    canbo::xuat();
    cout << " " << nganh << endl;
}

class nhanvien : public canbo {
private:
    string ma, cv;
public:
    nhanvien() {
        ma = cv = "";
    }
    nhanvien(string ma, string cv, string ten, string ns, string gt, string dc) : canbo(ten, ns, gt, dc) {
        this->ma = ma;
        this->cv = cv;
    }

    void xuat();

    string getMa()  {  // Override the getMa method
        return ma;
    }

    void setManv(string ma) {
        this->ma = ma;
    }

    void setCv(string cv) {
        this->cv = cv;
    }
};

void nhanvien::xuat() {
    cout << ma << " ";
    canbo::xuat();
    cout << " " << cv << endl;
}

class qlcb {
    private:
        vector<canbo*> danhsach;
    public:
        // Them thong tin nhap vao vector 
        void themcanbo(canbo* cb) {
            danhsach.push_back(cb);
        }

        // Hien thi danh sach
        void hienthiDanhsach() {
            for (auto cb : danhsach) {
                cb->xuat();
            }
        }

        // Tim kiem theo ten
        void seachName(string ten) {
            bool check = false;
            for (auto& cb : danhsach) {
                if (cb->getTen().find(ten) != string::npos) {
                    cb->xuat();
                    check = true;
                }
            }
            if (!check) cout << "NOT FOUND\n";
        }

        void capnhatThongtin() {
            string ma;
            cout << "Nhap ma can bo: ";
            cin >> ma;
            bool found = false;

            for (auto& cb : danhsach) {
                if (cb->getMa() == ma) {
                    found = true;

                    string ten, ns, gt, dc;

                    cout << "Nhap ten: ";
                    cin.ignore();
                    getline(cin, ten);
                    cout << "Nhap ngay sinh: ";
                    getline(cin, ns);
                    cout << "Nhap gioi tinh: ";
                    getline(cin, gt);
                    cout << "Nhap dia chi: ";
                    getline(cin, dc);

                    cb->setTen(ten);
                    cb->setNs(ns);
                    cb->setGt(gt);
                    cb->setDc(dc);

                    break; // Dừng vòng lặp nếu đã tìm thấy cán bộ
                }
            }

            if (!found) {
                cout << "Ma can bo khong ton tai!" << endl;
            }
        }
};

int main() {
    qlcb ql;
    int n;

    cout << "Nhap so luong can bo: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string ma;
        cout << "Nhap ma can bo: ";
        cin >> ma;

        if (ma.substr(0, 2) == "CN") {
            string bac, ten, ns, gt, dc;
            cout << "Nhap Bac: ";
            cin.ignore();
            getline(cin, bac);
            cout << "Nhap ten: ";
            getline(cin, ten);
            cout << "Nhap ngay sinh: ";
            getline(cin, ns);
            cout << "Nhap gioi tinh: ";
            getline(cin, gt);
            cout << "Nhap dia chi: ";
            getline(cin, dc);
            congnhan* cn = new congnhan(ma, bac, ten, ns, gt, dc);
            ql.themcanbo(cn);
        } else if (ma.substr(0, 2) == "KS") {
            string nganh, ten, ns, gt, dc;
            cout << "Nhap nganh: ";
            cin.ignore();
            getline(cin, nganh);
            cout << "Nhap ten: ";
            getline(cin, ten);
            cout << "Nhap ngay sinh: ";
            getline(cin, ns);
            cout << "Nhap gioi tinh: ";
            getline(cin, gt);
            cout << "Nhap dia chi: ";
            getline(cin, dc);
            kysu* ks = new kysu(ma, nganh, ten, ns, gt, dc);
            ql.themcanbo(ks);
        } else {
            string cv, ten, ns, gt, dc;
            cout << "Nhap cong viec: ";
            cin.ignore();
            getline(cin, cv);
            cout << "Nhap ten: ";
            getline(cin, ten);
            cout << "Nhap ngay sinh: ";
            getline(cin, ns);
            cout << "Nhap gioi tinh: ";
            getline(cin, gt);
            cout << "Nhap dia chi: ";
            getline(cin, dc);
            nhanvien* nv = new nhanvien(ma, cv, ten, ns, gt, dc);
            ql.themcanbo(nv);
        }
    }

    cout << "Danh sach can bo:\n";
    ql.hienthiDanhsach();

    // Cập nhật thông tin
    ql.capnhatThongtin();

    cout << "Danh sach sau khi cap nhat:\n";
    ql.hienthiDanhsach();

    // Tìm kiếm theo tên
    string tenTimKiem;
    cout << "Nhap ten can tim: ";
    cin.ignore();
    getline(cin, tenTimKiem);
    ql.seachName(tenTimKiem);

    return 0;
}
