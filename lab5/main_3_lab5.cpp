#include <fstream>
#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include <vector>

using namespace std;

struct Sale{
    string date;
    int buyer;
    double sum;
    string category;
};

void reading_sales_file(vector<Sale>& sales){
    
    ifstream fin("sales.csv");
    if (!fin.is_open()){
        cout<<"Failed opening file for reading!"<<endl;
        return;
    }
    else{cout<<"чтение всех данных из файла выполнено"<<endl;}
    
    string line;
    bool first_line = true;
    while(getline(fin, line)){
        if (first_line){
            first_line = false;
            continue;
        }
        
        stringstream stroka(line);
        Sale sale;
        getline(stroka, sale.date, ',');
        stroka >> sale.buyer;
        stroka.ignore();
        stroka >> sale.sum;
        stroka.ignore();
        getline(stroka, sale.category);
        sales.push_back(sale);
    }
    fin.close();
}

double sum_all_sales(vector<Sale>& sales){
    double summa = 0;
    for (size_t i = 0; i < sales.size(); i++){
        summa += sales[i].sum;
    }
    return summa;
}

void filter_by_date(vector<Sale>& sales, string& search_date){
    ofstream fout("filtered_sales.csv");
    if (!fout.is_open()){
        cout<<"Failed opening file for writing!"<<endl;
        return;
    }
    
    fout << "date,buyer,sum,category" << endl;
    cout<<"продажи по дате "<<search_date<<endl;
    bool flag_found=false;
    for (size_t i = 0; i < sales.size(); i++){
        if (sales[i].date == search_date){
            flag_found=true;
            fout << sales[i].date << ","<< sales[i].buyer << "," << sales[i].sum << "," << sales[i].category << endl;
            cout << sales[i].date << ","<< sales[i].buyer << "," << sales[i].sum << "," << sales[i].category << endl;
        }
    }
    
    fout.close();
    
    if (!flag_found){
        cout << "продажи по такой дате не найдены" << endl;
    } else {
        cout << "результат сохранён в файл filtered_sales.csv" << endl;
    }
}

void print_all_sales(vector<Sale>& sales){
    cout << "список всех продаж: " << endl;
    for (size_t i = 0; i < sales.size(); i++){
        cout << sales[i].date << ", " << sales[i].buyer << ", " << sales[i].sum << ", " << sales[i].category << endl;
    }

}

int main(){
    vector<Sale> sales;
    
    reading_sales_file(sales);
    print_all_sales(sales);
    double all_sum = sum_all_sales(sales);
    cout << "общая сумма всех продаж: " << all_sum << endl;
    
    string date;
    cout << "введите дату для фильтрации: ";
    cin >> date;
    filter_by_date(sales, date);
    
    return 0;
}