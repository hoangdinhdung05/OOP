#include<bits/stdc++.h>

using namespace std;

class thuvien{
    private:
        string IDtailieu, Namenhasanxuat, Sobanphathanh;
    public:
        thuvien(){
            IDtailieu = Namenhasanxuat = Sobanphathanh = "";
        }

        thuvien(string IDtailieu, string Namenhasanxuat, string Sobanphathanh){
            this->IDtailieu = IDtailieu;
            this->Namenhasanxuat = Namenhasanxuat;
            this->Sobanphathanh = Sobanphathanh;
        }

        void xuat();

        string getIDtailieu(){
            return IDtailieu;
        }

        string getLoai(){
            return "thuvien";
        }

        string getSobanphathanh(){
            return Sobanphathanh;
        }

        void setIDtailieu(string IDtailieu){
            this->IDtailieu = IDtailieu;
        }

        void setNamenhasanxuat(string Namenhasanxuat){
            this->Namenhasanxuat = Namenhasanxuat;
        }

        void setSobanphathanh(string Sobanphathanh){
            this->Sobanphathanh = Sobanphathanh;
        }

};

void thuvien::xuat(){
    cout << "ID: " << IDtailieu << "|" << "Ten nha san xuat: " << Namenhasanxuat << "|" << "So ban phat hanh: " << Sobanphathanh << "|";
}

//Sach: Nametg, Sotrang
class sach : public thuvien{
    private:
        string Nametg, Sotrang;
    public:
        sach(){
            Nametg = Sotrang = "";
        }

        sach(string Nametg, string Sotrang, string IDtailieu, string Namenhasanxuat, string Sobanphathanh) : thuvien(IDtailieu, Namenhasanxuat, Sobanphathanh){
            this->Nametg = Nametg;
            this->Sotrang = Sotrang;
        }

        void xuat(){
            thuvien::xuat();
            cout << "Ten tac gia: " << Nametg << "|" << "So trang: " << Sotrang << endl;
        }
};

//Tap chi: Sophathanh, Thangphathanh
class tapchi : public thuvien{
    private:
        string Sophathanh, Thangphathanh;
    public:
        tapchi(){
            Sophathanh = Thangphathanh = "";
        }
        tapchi(string Sophathanh, string Thangphathanh, string IDtailieu, string Namenhasanxuat, string Sobanphathanh) : thuvien(IDtailieu, Namenhasanxuat, Sobanphathanh){
            this->Sophathanh = Sophathanh;
            this->Thangphathanh = Thangphathanh;
        }

        void xuat(){
            thuvien::xuat();
            cout << "So phat hanh: " << Sophathanh << "|" << "Thang phat hanh: " << Thangphathanh << endl;
        }
};

//Bao: Ngayphathanh
class bao : public thuvien{
    private:
        string Ngayphathanh;
    public:
        bao(){
            Ngayphathanh = "";
        }
        bao(string Ngayphathanh, string IDtailieu, string Namenhasanxuat, string Sobanphathanh) : thuvien(IDtailieu, Namenhasanxuat, Sobanphathanh){
            this->Ngayphathanh = Ngayphathanh;
        }

        void xuat(){    
            thuvien::xuat();
            cout << "Ngay phat hanh: " << Ngayphathanh << endl; 
        }
};

//Xay dung class de quan li thu vien
//Sach, Tap chi, Bao    
class quanlithuvien{
    private:
        vector<thuvien*> ds;
    public:
        //them phan tu vao vector
        void them_thuvien(thuvien* t){
            ds.push_back(t);
        }

        //hien thi thong tin
        void hienthi_thuvien(){
            for(auto t : ds){
                t->xuat(); cout << endl;
            }
        }

        void tim_thuvien(string IDtailieu){
            for(auto t : ds){
                if(t->getIDtailieu() == IDtailieu){
                    t->xuat();
                }
            }
        }

        // friend bool cmp(thuvien*, thuvien*);
        void sapxep_thuvien(){ 
            sort(ds.begin(), ds.end());
        }

        void update_thuvien(){
            cout << "Nhap ma thong tin can sua: ";
            string IDsua; cin >> IDsua;
            for(auto t : ds){
                if(t->getIDtailieu() == IDsua){
                    string Namenhasanxuat, Sobanphathanh;
                    cout << "Nhap ten moi cho nha san xuat: ";
                    getline(cin, Namenhasanxuat);
                    cout << "Nhap so ban phat hanh moi: ";
                    cin >> Sobanphathanh;
                    t->setNamenhasanxuat(Namenhasanxuat);
                    t->setSobanphathanh(Sobanphathanh); 
                }
            }
        }
};


// bool cmp(thuvien* a, thuvien* b){
//     if(a->getSobanphathanh() == b->getSobanphathanh()){
//         return a->getIDtailieu() < b->getIDtailieu();
//     }
//     else return a->getSobanphathanh() < b->getSobanphathanh();
// }

int main(){
    quanlithuvien ql;
    cout << "Nhap so luong thong tin: ";
    int n; cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        cout << "Lua chon thong tin:\n1. Sach\n2. Tap chi\n3. Bao\n";
        int x; cin >> x;
        cin.ignore();
        string IDtailieu, Namenhasanxuat, Sobanphathanh;
        cout << "Nhap ma tai lieu: ";
        cin >> IDtailieu;
        cin.ignore();
        cout << "Nhap ten nha san xuat: ";
        getline(cin, Namenhasanxuat);
        cout << "Nhap so ban phat hanh: ";
        cin >> Sobanphathanh;
        cin.ignore();
        if(x == 1){
            string Nametg, Sotrang;
            cout << "Nhap ten tac gia: ";
            getline(cin, Nametg);
            cout << "Nhap so trang: ";
            cin >> Sotrang;
            cin.ignore();
            sach a(Nametg, Sotrang, IDtailieu, Namenhasanxuat, Sobanphathanh);
            ql.them_thuvien(&a);
        }
        else if(x == 2){
            string Sophathanh, Thangphathanh;
            cout << "Nhap so phat hanh: ";
            cin >> Sophathanh;
            cout << "Nhap thang phat hanh: ";
            cin >> Thangphathanh;
            cin.ignore();
            tapchi a(Sophathanh, Thangphathanh, IDtailieu, Namenhasanxuat, Sobanphathanh);
            ql.them_thuvien(&a);
        }
        else if(x == 3){
            string Ngayphathanh;
            cout << "Nhap ngay phat hanh: ";
            cin >> Ngayphathanh;
            cin.ignore();
            bao a(Ngayphathanh, IDtailieu, Namenhasanxuat, Sobanphathanh);
            ql.them_thuvien(&a);
        }
    }
    cout << "Danh sach quan li thong tin thu vien: \n";
    ql.hienthi_thuvien();

    //sap xep thu vien theo so ban phat hanh
    ql.sapxep_thuvien();
    cout << "Danh sach sau khi sap xep: \n";
    ql.hienthi_thuvien();
    //update thong tin
    ql.update_thuvien();
    cout << "Danh sach sau khi sua thong tin: \n";
    ql.hienthi_thuvien();
    return 0;
}