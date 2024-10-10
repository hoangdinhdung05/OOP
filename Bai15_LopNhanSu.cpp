#include<bits/stdc++.h>

using namespace std;

class nhansu{
    private:
        string mnv, ten, ns;
    public:
        nhansu(){
            mnv = ten = ns = "";
        }

        nhansu(string mnv, string ten, string ns){
            this->mnv = mnv;
            this->ten = ten;
            this->ns = ns;
        }

        // void nhap();
        void xuat();

        string getMnv(){
            return mnv;
        }
};

// void nhansu::nhap(){
//     cin >> mnv;
//     cin.ignore();
//     getline(cin, ten);
//     cin >> ns;
// }

void nhansu::xuat(){
    cout << mnv << " " << ten << " " << ns << " ";
}

class canbo : public nhansu{
    private:
        double luongcoban, hesoluong;
    public:
        canbo() : nhansu(){
            luongcoban = hesoluong = 0.0;
        }

        canbo(double luongcoban, double hesoluong, string mnv, string ten, string ns) : nhansu(mnv, ten, ns){
            this->luongcoban = luongcoban;
            this->hesoluong = hesoluong;
        }

        // void nhap();
        void xuat();

        friend bool cmp(canbo, canbo);
        friend double tong(canbo);
};

// void canbo::nhap(){
//     nhansu::nhap();
//     cin >> luongcoban >> hesoluong;
// }

void canbo::xuat(){
    nhansu::xuat();
    cout << luongcoban << " " << hesoluong << " " << tong(*this) << endl;
}

double tong(canbo a){
    return a.luongcoban * a.hesoluong;
}

bool cmp1(canbo a, canbo b){
    return tong(a) > tong(b);
}

class congnhan : public nhansu{
    private:    
        int ngaylamviec;
    public:
        congnhan() : nhansu(){
            ngaylamviec = 0;
        }

        congnhan(int ngaylamviec, string mnv, string ten, string ns) : nhansu(mnv, ten, ns){
            this->ngaylamviec = ngaylamviec;
        }

        // void nhap();
        void xuat();

        friend double tong(congnhan);
        friend bool cmp(congnhan, congnhan);
        friend double thuong(congnhan);
};

// void congnhan::nhap(){
//     nhansu::nhap();
//     cin >> ngaylamviec;
// }    

void congnhan::xuat(){    
    nhansu::xuat();
    cout << ngaylamviec << endl;
}    

double tong(congnhan a){    
    return a.ngaylamviec * 100000;
}

bool cmp2(congnhan a, congnhan b){
    return tong(a) > tong(b);
}

double thuong(congnhan a){
    return a.ngaylamviec * 100000;
}

vector<canbo> vcb;
vector<congnhan> vcn;

int main(){
    int n; cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        string mnv;
        cin >> mnv;
        if(mnv.substr(0, 2) == "CB"){
            string ten, ns;
            double luongcoban, hesoluong;
            cin.ignore();
            getline(cin, ten);
            cin >> ns >> luongcoban >> hesoluong;
            canbo cb(luongcoban, hesoluong, mnv, ten, ns);
            vcb.push_back(cb);
        }
        else if(mnv.substr(0, 2) == "CN"){
            string ten, ns;
            int ngaylamviec;
            cin.ignore();
            getline(cin, ten);
            cin >> ns >> ngaylamviec;
            congnhan cn(ngaylamviec, mnv, ten, ns);
            vcn.push_back(cn);
        }
    }

    cout << "Danh sach can bo: " << endl;
    sort(vcb.begin(), vcb.end(), cmp1);
    for(auto x : vcb){
        x.xuat();
    }
    cout << endl;
    cout << "Danh sach cong nhan: " << endl;
    sort(vcn.begin(), vcn.end(), cmp2);
    for(auto x : vcn){
        x.xuat();
    }
    return 0;
}