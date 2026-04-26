#include <fstream>
#include <iostream>
#include <string>
#include <limits>

using namespace std;

template<typename type>
type inputNumber() {
    type value;
    while (!(cin >> value)) {
        cout << "Ошибка! Введите число: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    return value;
}


struct Student{
    string name;
    int age;
    double grade;
};

void reading_file(){
    cout<<"чтение всех данных из файла:"<<endl;
    ifstream fin("students.txt");
    if (!fin.is_open()){
        cout<<"Failed opening file for reading!"<<endl;
    }
    else{
        Student student;
        while(fin >> student.name >> student.age >> student.grade){
            cout<<"имя: "<<student.name<<", возраст: "<<student.age<<", оценка: "<<student.grade<<endl;
        }
        fin.close();
    }
}

void writing_file(Student& student){
    ofstream fout("students.txt", ios::app);
    if (!fout.is_open()){
        cout<<"Failed opening file! "<<endl;
    }
    else{
        fout<<student.name<<" "<<student.age<<" "<<student.grade<<endl;
        fout.close();
        cout<<"данные о студенте успешно внесены в файл"<<endl;
    }
}

int main(){
    Student student;
    cout<<"введите данные для студента"<<endl;
    cout<<"имя: ";
    cin>>student.name;
    cout<<"возраст: ";
    student.age=inputNumber<int>();
    cout<<"оценка: ";
    student.grade=inputNumber<double>();
   
    writing_file(student);
    reading_file();
    
    
    return 0;
}