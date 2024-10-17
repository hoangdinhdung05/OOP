#include<bits/stdc++.h>

using namespace std;

class sophuc1{
    protected:
        int thuc, ao;
    public:
        sophuc1(){
            thuc = ao = 0;
        }
        sophuc1(int thuc, int ao){
            this->thuc = thuc;
            this->ao = ao;
        }
        void nhap(){
            cin >> thuc >> ao;
        }
        void xuat(){
            if(ao > 0){
                cout << thuc << "+" << ao << "i" << endl;
            }
            else if(ao == 0) cout << thuc << endl;
            else cout << thuc << "-" << abs(ao) << "i" << endl;
        }
        
        sophuc1 operator + (sophuc1 a){
            return sophuc1(thuc + a.thuc, ao + a.ao);
        }

        sophuc1 operator - (sophuc1 a){
            return sophuc1(thuc - a.thuc, ao - a.ao);
        }

        sophuc1 operator * (sophuc1 a){
            return sophuc1(thuc * a.thuc - ao * a.ao, thuc * a.ao + ao * a.thuc);
        }

        sophuc1 operator / (sophuc1 a){
            return sophuc1((thuc * a.thuc + ao * a.ao) / (a.thuc * a.thuc + a.ao * a.ao), (ao * a.thuc - thuc * a.ao) / (a.thuc * a.thuc + a.ao * a.ao));
        }
};

class sophuc2 : public sophuc1{
    public:
        sophuc2 operator= (sophuc2 a);
        bool operator < (sophuc2 a);
        bool operator > (sophuc2 a);
        bool operator == (sophuc2 a);

        friend void sx1(sophuc2 a[], int n);
        friend void sx2(sophuc2 a[], int n);

        friend void sophucMax(sophuc2 a[], int n);
        friend void sophucMin(sophuc2 a[], int n);

        double modun(){
            return sqrt(thuc * thuc + ao * ao);
        }
};

sophuc2 sophuc2::operator= (sophuc2 a){
    this->thuc = a.thuc;
    this->ao = a.ao;
    return *this;
}

bool sophuc2::operator < (sophuc2 a){
    return modun() < a.modun();
}

bool sophuc2::operator > (sophuc2 a){
    return modun() > a.modun();
}

bool sophuc2::operator == (sophuc2 a){
    if(modun() == a.modun()) return 1;
    else return 0;
}

void sx1(sophuc2 a[], int n){
    for(int i = 0; i < n; i++){
        int min = i;
        for(int j = i + 1; j < n; j++){
            if(a[j].modun() < a[min].modun()){
                min = j;
            }
        }
        sophuc2 tmp = a[i];
        a[i] = a[min];
        a[min] = tmp;
    }
}

void sx2(sophuc2 a[], int n){
    for(int i = 0; i < n; i++){
        int max = i;
        for(int j = i + 1; j < n; j++){
            if(a[j].modun() > a[max].modun()){
                max = j;
            }
        }
        sophuc2 tmp = a[i];
        a[i] = a[max];
        a[max] = tmp;
    }
}

void sophucMax(sophuc2 a[], int n){
    cout << "Phan so lon nhat: ";
    a[n - 1].xuat();
}

void sophucMin(sophuc2 a[], int n){
    cout << "Phan so nho nhat: ";
    a[0].xuat();
}

int main(){ 
    // sophuc1 a, b, c, d, e, f;
    // a.nhap();
    // b.nhap();
    // c = a + b;
    // d = a - b;
    // e = a * b;
    // f = a / b;
    // c.xuat();
    // d.xuat();
    // e.xuat();
    // f.xuat();

    int n;
    cin >> n;
    sophuc2 a[n];
    for(int i = 0; i < n; i++){
        a[i].nhap();
    }

    cout << "Danh sach so phuc sau khi nhap: \n";
    for(int i = 0; i < n; i++){
        a[i].xuat();
    }

    cout << "\nDanh sach so phuc sau khi sap xep tang dan: \n";
    sx1(a, n);
    for(int i = 0; i < n; i++){
        a[i].xuat();
    }
    cout << "Phan tu lon nhat: ";
    sophucMax(a, n);

    cout << "\nDanh sach so phuc sau khi sap xep giam dan: \n";
    sx2(a, n);
    for(int i = 0; i < n; i++){
        a[i].xuat();
    }
    cout << "Phan tu nho nhat: ";
    sophucMin(a, n);
    return 0;
}