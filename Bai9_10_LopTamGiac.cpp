#include<bits/stdc++.h>

using namespace std;

class diem{
    private:
        double x, y;
    public:
        diem(){
            x = y = 0;
        }
        diem(double a, double b){
            this->x = a;
            this->y = b;
        }
        void nhap();
        void xuat();
        friend double kc(diem, diem);
};

void diem::nhap(){
    cin >> x >> y;
}

void diem::xuat(){
    cout << "(" << x << ", " << y << ")";
}

double kc(diem a, diem b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

class tamgiac{
    private:
        diem a, b, c;
        double c1, c2, c3;
    public:
        tamgiac(){
            c1 = c2 = c3 = 0;
        }
        // Initialize sides to zero
        tamgiac(diem p1, diem p2, diem p3){
            a = p1;
            b = p2;
            c = p3;
            c1 = kc(a, b);
            c2 = kc(a, c);
            c3 = kc(b, c);
        }
        void nhap();
        void xuat();
        bool hopLe();
        void check();
        friend double chuvi(tamgiac);
        friend double dientich(tamgiac);
        friend bool sx(tamgiac, tamgiac);
};

void tamgiac::nhap(){
    a.nhap();
    b.nhap();
    c.nhap();
    c1 = kc(a, b);
    c2 = kc(a, c);
    c3 = kc(b, c);
}

void tamgiac::xuat(){
    a.xuat();
    cout << " ";
    b.xuat();
    cout << " ";
    c.xuat();
    cout << endl;
    cout << c1 << ' ' << c2 << ' ' << c3 << endl;
}

bool tamgiac::hopLe(){
    return (c1 > 0 && c2 > 0 && c3 > 0 && c1 + c2 > c3 && c1 + c3 > c2 && c2 + c3 > c1);
}

double chuvi(tamgiac t){
    if(t.hopLe()){
        return t.c1 + t.c2 + t.c3;
    }
    return 0;
}

double dientich(tamgiac t){
    if(t.hopLe()){
        double p = chuvi(t) / 2;
        return sqrt(p * (p - t.c1) * (p - t.c2) * (p - t.c3));
    }
    return 0;
}

bool sx(tamgiac a, tamgiac b){
    return dientich(a) < dientich(b);
}

void tamgiac::check(){
    if(hopLe()){
        if(c1 == c2 && c2 == c3){
            cout << "Tam giac deu" << endl;
        }else if(c1 == c2 || c1 == c3 || c2 == c3){
            cout << "Tam giac can" << endl;
        }else if(fabs(c1*c1 + c2*c2 - c3*c3) < 1e-6 || fabs(c1*c1 + c3*c3 - c2*c2) < 1e-6 || fabs(c2*c2 + c3*c3 - c1*c1) < 1e-6){
            cout << "Tam giac vuong" << endl;
        }else{
            cout << "Tam giac thuong" << endl;
        }
    }else{
        cout << "Khong hop le" << endl;
    }
}

int main(){
    tamgiac t;
    t.nhap();
    t.xuat();
    t.check();
    return 0;
}