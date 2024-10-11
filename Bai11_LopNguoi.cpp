#include<bits/stdc++.h>

using namespace std;

class People{
    private:
        string name, birth;
    public:
        People(){
            name = birth = "";
        }

        People(string name, string birth){
            this->name = name;
            this->birth = birth;
        }

        // void nhap();
        void xuat();
        // virtual string getId(){
        //     return "";
        // }
};

// void People::nhap(){
//     cout << "Ten: ";
//     getline(cin, name);
//     cout << "Ngay sinh: ";
//     getline(cin, birth);
// }

void People::xuat(){
    cout << name << " " << birth;
}

class Student : public People{
    private:
        string id;
        double gpa;
    public:
        Student() : People(){
            id = "";
            gpa = 0.0;
        }

        Student(string id, double gpa, string name, string birth) : People(name, birth){
            this->id = id;
            this->gpa = gpa;
        }

        void xuat();
        double getGpa(){
            return gpa;
        }

        string getId(){
            return id;
        }

        friend void searchStudent(vector<Student>, string);

        friend bool cmpStudent(Student, Student);
};

void Student::xuat(){
    cout << id << " ";
    People::xuat();
    cout << " " << gpa << endl;
}
//sort
bool cmpStudent(Student a, Student b){
    return a.getGpa() > b.getGpa();
}
//search
void searchStudent(vector<Student> v, string id){
    bool check = false;
    for(int i = 0; i < v.size(); i++){
        if(v[i].getId() == id){
            v[i].xuat();
            check = true;
        }
    }
    if(!check) cout << "NOT FOUND\n";
}

class Teacher : public People{
    private:
        string id, monct, monday;
        int sobai;
    public:
        Teacher() : People(){
            id = monct = monday = "";
            sobai = 0;
        }

        Teacher(string id, string monct, string monday, string name, string birth, int sobai) : People(name, birth){
            this->id = id;
            this->monct = monct;
            this->monday = monday;
            this->sobai = sobai;
        }

        void xuat();
        string getId(){
            return id;
        }
        friend void searchTeacher(vector<Teacher>, string);
        friend bool cmp1Teacher(Teacher, Teacher);
        friend bool cmp2Teacher(Teacher, Teacher);
};

void Teacher::xuat(){
    cout << id << " ";
    People::xuat();
    cout << " " << monct << " " << monday << " " << sobai << endl;
}

void searchTeacher(vector<Teacher> v, string id){
    bool check = false;
    for(int i = 0; i < v.size(); i++){
        if(v[i].getId() == id){
            v[i].xuat();
            check = true;
        }
    }
    if(!check) cout << "NOT FOUND\n";
}

//sort giam dan
bool cmp1Teacher(Teacher a, Teacher b){
    return a.sobai > b.sobai;
}
//sort tang dan
bool cmp2Teacher(Teacher a, Teacher b){
    return a.sobai < b.sobai;
}

vector<Student> v1;
vector<Teacher> v2;
int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        string id;
        cin >> id;
        if(id.substr(0, 2) == "GV"){
            string ten, ns, monct, monday;
            double sobai;
            cin.ignore();
            getline(cin, ten);
            cin >> ns >> monct >> monday >> sobai;
            Teacher t(id, monct, monday, ten, ns, sobai);
            v2.push_back(t);
        }
        else{
            string ten, ns, lop;
            double gpa;
            cin.ignore();
            getline(cin, ten);
            cin >> ns >> lop >> gpa;
            Student s(id, gpa, ten, ns);
            v1.push_back(s);
        }
    }
    cout << "Danh sach Teacher: \n";
    for(auto x : v2){
        x.xuat();
    }
    //tim kiem sao vien
    cout << "Nhap ID teacher: \n";
    string s; cin >> s;
    searchTeacher(v2, s);
    //sap xep giam dan
    cout << "Danh sach Teacher sap xep giam dan: \n";
    sort(v2.begin(), v2.end(), cmp1Teacher);
    for(auto x : v2){
        x.xuat();
    }
    //sap xep tang dan
    cout << "Danh sach Teacher sap xep tang dan: \n";
    sort(v2.begin(), v2.end(), cmp2Teacher);
    for(auto x : v2){
        x.xuat();
    }
    //
    cout << endl;
    cout << "Danh sach Student: \n";
    for(auto x : v1){
        x.xuat();
    }

    //tim kiem sinh vien
    cout << "Nhap ID student: \n";
    string s1; cin >> s1;
    searchStudent(v1, s1);
    //sap xep giam dan
    cout << "Danh sach Student sap xep giam dan: \n";
    sort(v1.begin(), v1.end(), cmpStudent);
    for(auto x : v1){
        x.xuat();
    }
    //sap xep tang dan
    cout << "Danh sach Student sap xep tang dan: \n";
    sort(v1.begin(), v1.end(), cmpStudent);
    for(auto x : v1){
        x.xuat();
    }
    return 0;
}