#include<bits/stdc++.h>

using namespace std;

class sp1{
    protected:
        int thuc, ao;
    public:
        sp1(){
            thuc = ao = 0;
        }
        sp1(int thuc, int ao){
            this->thuc = thuc;
            this->ao = ao;
        }

        void nhap();
        void xuat();

        friend double modun (sp1);
};

void sp1::nhap(){
    cin >> thuc >> ao;
}

void sp1::xuat(){
    if(ao > 0){
        cout << thuc << "+" << ao << "i" << endl;
    }
    else cout << thuc << "-" << abs(ao) << "i" << endl;
}

double modun(sp1 a){
    return sqrt(a.thuc*a.thuc + a.ao*a.ao);
}

class sp2 : public sp1{
    public:
       //toan tu gan, be hon, so sanh bang
        sp2& operator = (sp2&);
        bool operator < (sp2);
        bool operator == (sp2);
};

sp2& sp2::operator = (sp2& a){
    this->thuc = a.thuc;
    this->ao = a.ao;
    return *this;
}

bool sp2::operator < (sp2 a){
    double md1 = modun(a);
    double md2 = modun(*this);
    return md2 < md1;
}

bool sp2::operator == (sp2 a){
    return a.thuc == this->thuc && a.ao == this->ao;
}

int main(){
    sp2 b, c;
    b.nhap();
    c.nhap();
    cout << "So phuc b:" << endl;
    b.xuat();
    cout << "So phuc c: " << endl;
    c.xuat();
    cout << "So sanh:\n";
    if(b < c){
        cout << "b nho hon c\n";
    }
    else cout << "b lon hon c\n";
    cout << "So sanh bang:\n";
    if(b == c){
        cout << "b bang c\n";
    }
    else cout << "b khong bang c\n";
    return 0;
}