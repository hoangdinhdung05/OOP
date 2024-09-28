#include<bits/stdc++.h>

using namespace std;

class ps1 {
protected:
    int tu, mau; // tử và mẫu số
public:
    ps1() {
        tu = 0;
        mau = 1;
    }

    ps1(int tu, int mau) {
        this->tu = tu;
        this->mau = mau;
    }

    void nhap();
    void xuat();
    void toigian();
};

// Hàm tìm UCLN
int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b); // Sửa cú pháp gọi đệ quy
}

// Hàm nhập phân số
void ps1::nhap() {
    cin >> tu;
    do {
        cin >> mau;
        if (mau == 0) cout << "Nhap lai mau (khac 0)\n";
    } while (mau == 0);
    toigian(); // Gọi hàm tối giản sau khi nhập phân số
}

// Hàm tối giản phân số
void ps1::toigian() {
    int uc = gcd(tu, mau);
    tu /= uc;
    mau /= uc;
}

// Hàm xuất phân số
void ps1::xuat() {
    cout << tu << "/" << mau << endl;
}

// Lớp ps2 kế thừa từ ps1
class ps2 : public ps1 {
public:
    ps2& operator= (const ps2&); // Thay bool thành ps2&
    bool operator> (ps2);
    bool operator< (ps2);
};

// Nạp chồng toán tử gán
ps2& ps2::operator= (const ps2& a) { 
    this->tu = a.tu;
    this->mau = a.mau;
    return *this; // Trả về tham chiếu đến đối tượng hiện tại
}

// Nạp chồng toán tử >
bool ps2::operator> (ps2 a) {
    return (this->tu * a.mau > this->mau * a.tu); // So sánh phân số bằng cách nhân chéo
}

// Nạp chồng toán tử <
bool ps2::operator< (ps2 a) {
    return (this->tu * a.mau < this->mau * a.tu); // So sánh phân số bằng cách nhân chéo
}

int main() {
    int n;
    cout << "Nhap so luong phan so: ";
    cin >> n;
    ps2 a[n];

    // Nhập các phân số
    for (int i = 0; i < n; i++) {
        cout << "Nhap phan so thu " << i+1 << ": ";
        a[i].nhap();
    }

    // Tìm phân số lớn nhất và nhỏ nhất
    ps2 max = a[0], min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) { // Sửa điều kiện so sánh để tìm lớn nhất
            max = a[i];
        }
        if (a[i] < min) { // Sửa điều kiện so sánh để tìm nhỏ nhất
            min = a[i];
        }
    }

    cout << "Phan so lon nhat: ";
    max.xuat();
    cout << "Phan so nho nhat: ";
    min.xuat();

    return 0;
}
