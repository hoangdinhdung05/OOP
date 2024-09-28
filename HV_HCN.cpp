#include<bits/stdc++.h>

using namespace std;

class hv{
    protected:
        double a;
    public:
        hv(){
            a = 0.0;
        }
        hv(double a){
            this->a = a;
        }

        void nhap();
        void xuat();

        double chuvi();
        double dientich();
};

void hv::nhap(){
    cin >> a;
}

void hv::xuat(){
    cout << a;
}

double hv::chuvi(){
    return 4 * a;
}

double hv::dientich(){
    return a * a;
}

class hcn : public hv{
    private:
        double b;
    public:
        hcn(){
            b = 0.0;
        }
        hcn(double b, double a){
            this->b = b;
        }

        void nhap();
        void xuat();
        friend double chuvi(hcn);
        friend double dientich(hcn);
        
};

void hcn::nhap(){
    hv::nhap();
    cin >> b;
}

void hcn::xuat(){
    hv::xuat();
    cout << b;
}

double chuvi(hcn x){
    return (x.a + x.b)*2;
}

double dientich(hcn x){
    return x.a * x.b;
}


int main(){
    int n; cin >> n;
    vector<hcn> v(n);
    for(auto &x : v){
        x.nhap();
    }
    double _maxDt = 0, _maxCv = 0;
    for(auto x : v){
        _maxCv = max(_maxCv, chuvi(x));
        _maxDt = max(_maxDt, dientich(x));

    }
    cout << "Chu vi max: " << _maxCv << endl;
    cout << "Dien tich max: " << _maxDt;
    return 0;
}