#include<bits/stdc++.h>

using namespace std;

class Person{
    private:
        string id, ten, ns;
    public:
        Person(){
            id = ten = ns = "";
        }

        Person(string id, string ten, string ns){
            this->id = id;
            this->ten = ten;
            this->ns = ns;
        }

        // void nhap(){
        //     cout << "Nhap ID: ";
        //     cin >> id;
        //     cin.ignore();
        //     cout << "Nhap ten: ";
        //     getline(cin, ten);
        //     cout << "Nhap ngay sinh: ";
        //     getline(cin, ns);
        // }

        void xuat(){
            cout << "ID: " << id << "|" << "Ten: " << ten << "|" << "Ngay sinh: " << ns << " ";
        }

        string getMa(){
            return id;
        }

        virtual int getSobai(){
            return 0;
        }

        virtual double getGpa(){
            return 0.0;
        }
};

class Student : public Person{
    private:
        string lop;
        double gpa;
    public:
        Student() : Person(){
            lop = "";
            gpa = 0.0;
        }

        Student(string lop, double gpa, string id, string ten, string ns) : Person(id, ten, ns){
            this->lop = lop;
            this->gpa = gpa;
        }

        // void nhap(){
        //     Person::nhap();
        //     cout << "Nhap lop: ";
        //     getline(cin, lop);
        //     cout << "Nhap diem trung binh: ";
        //     cin >> gpa;
        //     cin.ignore();
        // }

        void xuat(){
            Person::xuat();
            cout << "Lop: " << lop << "|" << "Diem trung binh: " << gpa << " ";
        }

        double getGpa(){
            return gpa;
        }

};

class Teacher : public Person{
    private:
        int sobai;
    public:
        Teacher() : Person(){
            sobai = 0;
        }

        Teacher(int sobai, string id, string ten, string ns) : Person(id, ten, ns){
            this->sobai = sobai;
        }

        // void nhap(){
        //     Person::nhap();
        //     cout << "Nhap so bai: ";
        //     cin >> sobai;
        // }
        
        void xuat(){
            Person::xuat();
            cout << "So bai: " << sobai << " ";
        }

        int getSobai(){
            return sobai;
        }
};

class Thuong{
    private:
        vector<Person*> ds;
    public:
        //them phan tu vao vector
        void them(Person* p){
            ds.push_back(p);
        }
        //hien thi thong tin
        void hienthi(){
            for(auto p : ds){
                if(p->getGpa() >= 8.0){
                    cout << "Danh sach sinh vien nhan thuong: " << endl;
                    p->xuat();
                    cout << endl;
                }
                cout << endl;
                if(p->getSobai() >= 1){
                    cout << "Danh sach giang vien nhan thuong: " << endl;
                    p->xuat();
                    cout << endl;
                }
            }
        }

        void chBirth(string& s){
            if(s[2] != '/') s.insert(0, "0");
            if(s[5] != '/') s.insert(3, "0");
        }

        string chName(string s){
            stringstream ss(s);
            string token;
            string res = "";
            while(ss >> token){
                token[0] = toupper(token[0]);
                for(int i = 1; i < token.size(); i++){
                    token[i] = tolower(token[i]);
                }
                res += token + " ";
            }
            res.pop_back();
            token.erase();
            return res;
        }
};



int main(){
    Thuong t;
    cout << "Nhap so luong khen thuong: ";
    int n; cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        cout << "Nhap ID: ";
        string id;
        cin >> id;
        cin.ignore();
        if(id.substr(0, 2) == "GV"){
            string ten, ns;
            double sobai;
            cout << "Nhap ten: ";
            getline(cin, ten);
            ten = t.chName(ten);
            cout << "Nhap ngay sinh: ";
            getline(cin, ns);
            t.chBirth(ns);
            cout << "Nhap so bai: ";
            cin >> sobai;
            cin.ignore();
            Teacher* gv = new Teacher(sobai, id, ten, ns);
            t.them(gv);
        }
        else if(id.substr(0, 2) == "SV"){
            string ten, ns, lop;
            double gpa;
            cout << "Nhap ten: ";
            getline(cin, ten);
            ten = t.chName(ten);
            cout << "Nhap ngay sinh: ";
            getline(cin, ns);
            t.chBirth(ns);
            cout << "Nhap lop: ";
            getline(cin, lop);
            cout << "Nhap diem trung binh: ";
            cin >> gpa;
            cin.ignore();
            Student* sv = new Student(lop, gpa, id, ten, ns);
            t.them(sv);
        }
    }
    cout << "\nDanh sach khen thuong: \n";
    t.hienthi();
    return 0;
}