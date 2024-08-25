#include<bits/stdc++.h>

using namespace std;

//Bai 7:

class mtv{
    private:
        int capMT;
        int heSo[100][100];
    public:
        void nhap();
        void xuat();
        int tongDCC();
        int tongDCP();
        int tongDV();
};

void mtv::nhap(){
    cout << "Nhap cap ma tran: ";
    cin >> capMT;
    for(int i = 0; i < capMT; i++){
        for(int j = 0; j < capMT; j++){
            cout << "Nhap he so thu " << i << " " << j << " ";
            cin >> heSo[i][j];
        }
    }
}

void mtv::xuat(){
    for(int i = 0; i < capMT; i++){
        for(int j =0; j < capMT; j++){
            cout << heSo[i][j] << " ";
        }
        cout << endl;
    }
}

int mtv::tongDCC(){
    int tong = 0;
    for(int i = 0; i < capMT; i++){
        tong += heSo[i][i];
    }
    return tong;
}

int mtv::tongDCP(){
    int tong = 0;
    for(int i = 0; i < capMT; i++){
        tong += heSo[i][capMT-i-1];
    }
    return tong;
}

int mtv::tongDV(){
    int tong = 0;
    for(int i = 0; i < capMT; i++){
        for(int j = 0; j < capMT; j++){
            if(i == 0 || j == 0 || i == capMT - 1 || j == capMT - 1){
                tong += heSo[i][j];
            }
        }
    }
    return tong;
}

int main(){
    mtv a;
    cout << "Nhap MTV: \n";
    a.nhap();
    a.xuat();
    cout << "Tong DCC la: " << a.tongDCC() << endl;
    cout << "Tong DCC la: " << a.tongDCP() << endl;
    cout << "Tong DV la: " << a.tongDV() << endl;
    return 0;
}