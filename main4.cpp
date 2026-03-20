
#include <iostream>
#include <string>
using namespace std;

struct Address {
    string street;
    int house;
    int flat;
};

struct Person {
    string fio;
    int age;
    Address address;
};

int get_number() {
    int number;
    while (!(cin >> number)) {
        cout << "введено не число. введите еще раз: ";
        cin.clear(); 
        cin.ignore(10000, '\n'); 
    }
    cin.ignore(10000, '\n');
    return number;
}

void input_people(Person people[]) {
    for (int i = 0; i < 3; i++) {
        cout << "введите данные для человека " << endl;
        cout << "ФИО: ";
        getline(cin, people[i].fio);
        cout << "возраст: ";
        people[i].age = get_number();
        cout << "улица: ";
        getline(cin, people[i].address.street); 
        cout << "дом: ";
        people[i].address.house = get_number();   
        cout << "квартира: ";
        people[i].address.flat = get_number();  
    }
}

void print_people(Person people[]) {
    cout << "список людей:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ". " << people[i].fio << ", " << people[i].age 
             << " лет   адрес: ул. " << people[i].address.street << ", д. " 
             << people[i].address.house << ", кв. " << people[i].address.flat << endl;
    }
}

void search_street(Person people[]) {
    bool flag_found = false;
    string street_to_search = "";
    
    while (!flag_found) {
        cout << "введите название улицы для поиска: ";
        cin >> street_to_search;
        
        for (int i = 0; i < 3; i++) {
            if (people[i].address.street == street_to_search) {
                cout << people[i].fio << ", " << people[i].age << " лет, дом " 
                     << people[i].address.house << ", кв. " << people[i].address.flat << endl;
                flag_found = true;
            }
        }
        
        if (!flag_found) {
            cout << "никто не найден на этой улице" << endl;
        }
    }
}

void input_people_arrays(string fio[], int age[], string street[], int house[], int flat[]) {
    for (int i = 0; i < 3; i++) {
        cout << "введите данные для человека " << endl;
        cout << "ФИО: ";
        getline(cin, fio[i]);
        cout << "возраст: ";
        age[i] = get_number();
        cout << "улица: ";
        getline(cin, street[i]); 
        cout << "дом: ";
        house[i] = get_number();   
        cout << "квартира: ";
        flat[i] = get_number();  
    }
}

void print_people_arrays(string fio[], int age[], string street[], int house[], int flat[]) {
    cout << "список людей:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ". " << fio[i] << ", " << age[i] 
             << " лет   адрес: ул. " << street[i] << ", д. " << house[i] << ", кв. " << flat[i] << endl;
    }
}

void search_street_arrays(string fio[], int age[], string street[], int house[], int flat[]) {
    bool flag_found = false;
    string street_to_search = "";
    
    cout << "введите название улицы для поиска: ";
    cin >> street_to_search;
    
    for (int i = 0; i < 3; i++) {
        if (street[i] == street_to_search) {
            cout << fio[i] << ", " << age[i] << " лет, дом " 
                 << house[i] << ", кв. " << flat[i] << endl;
            flag_found = true;
        }
    }
    
    if (!flag_found) {
        cout << "никто не найден на этой улице" << endl;
    }
}

int main() {
    Person people[3];
    input_people(people);
    print_people(people);
    
    search_street(people);
   
    cout << "демонстрация:" << endl;
    cout << "человек: " << people[0].fio << endl;
    cout << "улица: " << people[0].address.street << endl; 
    cout << "дом: " << people[0].address.house << endl;  
    cout << "квартира: " << people[0].address.flat << endl; 

    
    string fio[3];
    int age[3];
    string street[3];
    int house[3];
    int flat[3];
    
    cin.ignore(10000, '\n');
    input_people_arrays(fio, age, street, house, flat);
    print_people_arrays(fio, age, street, house, flat);
    
    search_street_arrays(fio, age, street, house, flat);

    cout << "сравнение размера памяти:" << endl;
    cout << "размер структуры Person: " << sizeof(Person) << " байт" << endl;
    cout << "размер массива Person[3]: " << sizeof(people) << " байт" << endl;

    cout << "размер массива строк fio[3]: " << sizeof(fio) << " байт" << endl;
    cout << "размер массива int age[3]: " << sizeof(age) << " байт" << endl;
    cout << "размер массива строк street[3]: " << sizeof(street) << " байт" << endl;
    cout << "размер массива int house[3]: " << sizeof(house) << " байт" << endl;
    cout << "размер массива int flat[3]: " << sizeof(flat) << " байт" << endl;
    cout << "общий размер всех массивов: " << sizeof(fio) + sizeof(age) + sizeof(street) + sizeof(house) + sizeof(flat) << " байт" << endl;
    
    return 0;
}