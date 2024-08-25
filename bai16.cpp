#include<bits/stdc++.h>

using namespace std;
using ll = long long;

class diem{
    private:
        int x, y;
    public:
        diem(){
            x = y = 0;
        }  
        void nhap();
        void xuat();
        friend double kc(diem a, diem b);
};

class tamgiac{
    private:
        diem a, b, c;
        double c1, c2, c3;
    public:
        void nhap();
        void xuat();
        friend void check(tamgiac a);
};

void diem::nhap(){
    cin >> x >> y;
}

double kc(diem a, diem b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void diem::xuat(){
    cout << "(" << x << ", " << y << ")" << endl;
}

void tamgiac::nhap(){
    a.nhap();
    b.nhap();
    c.nhap();
    c1 = kc(a, b);
    c2 = kc(b, c);
    c3 = kc(c, a);
}

void tamgiac::xuat(){
    cout << c1 << " " << c2 << " " << c3 << endl;
}

void check(tamgiac a){
    if(a.c1 + a.c2 <= a.c3 || a.c1 + a.c3 <= a.c2 || a.c2 + a.c3 <= a.c1){
        cout << "Khong hop le\n";
    }
    else{
        if(a.c1 == a.c2 && a.c2 == a.c3){
            cout << "Tam giac deu\n";
        }
        else if(a.c1 == a.c2 || a.c1 == a.c3 || a.c2 == a.c3){
            cout << "Tam giac can\n";
        }
        else if((a.c1 == a.c2 || a.c1 == a.c3 || a.c2 == a.c3) && (a.c1 * a.c1 + a.c2 * a.c2 == a.c3 * a.c3 || a.c1 * a.c1 + a.c3 * a.c3 == a.c2 * a.c2 || a.c2 * a.c2 + a.c3 * a.c3 == a.c1 * a.c1)){
            cout << "Tam giac vuong can\n";
        }
        else if(a.c1 * a.c1 + a.c2 * a.c2 == a.c3 * a.c3 || a.c1 * a.c1 + a.c3 * a.c3 == a.c2 * a.c2 || a.c2 * a.c2 + a.c3 * a.c3 == a.c1 * a.c1){
            cout << "Tam giac vuong\n";
        }
        else cout << "Tam giac thuong\n";
    }
}

int main(){
    tamgiac a;
    a.nhap();
    a.xuat();
    check(a);
    return 0;
}