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


struct Product{
    int code;
    char title[50];
    double price;
    int quantity;
};

void reading_products_file(){
    cout<<"чтение всех данных из файла:"<<endl;
    ifstream fin("products.bin", ios::binary);
    if (!fin.is_open()){
        cout<<"Failed opening file for reading!"<<endl;
        return;
    }
    Product product;
        while(fin.read((char*)&product, sizeof(product))){
            cout<<"код: "<<product.code<<", название: "<<product.title<<", цена: "<<product.price<<", количество: "<<product.quantity<<endl;
        }
        fin.close();
}
 
void writing_product_in_file(Product& product){
    ofstream fout("products.bin", ios::binary | ios::app);
    if (!fout.is_open()){
        cout<<"Failed opening file! "<<endl;
        return;
    }
    fout.write((char*)&product, sizeof(product));
    fout.close();
    cout << "товар успешно записан в файл" << endl;
}

void search_product(int& code){
    cout<<"поиска товара по коду: "<<endl;
    ifstream fin("products.bin", ios::binary);
    if (!fin.is_open()){
        cout<<"Failed opening file for reading!"<<endl;
        return;
    }
    Product product;
    bool found_flag=false;
    while(fin.read((char*)&product, sizeof(product))){
        if (code==product.code){
            cout<<"код: "<<product.code<<", название: "<<product.title<<", цена: "<<product.price<<", количество: "<<product.quantity<<endl;
            found_flag=true;
        }
    }
    if (!found_flag){cout<<"товар с этим кодом не найден"<<endl;}
    fin.close();
}

void summ_price_products(){
    ifstream fin("products.bin", ios::binary);
    if (!fin.is_open()){
        cout<<"Failed opening file for reading!"<<endl;
        return;
    }
    Product product;
    double summa=0;
    while(fin.read((char*)&product, sizeof(product))){
        summa+=product.price*product.quantity;
    }
    cout<<"стоимость всех товаров на складе: "<< summa<<endl;
    fin.close();
}

int main(){
    Product product;
    cout<<"введите данные для товара"<<endl;
    cout<<"код товара: ";
    product.code=inputNumber<int>();
    cout<<"название: ";
    cin>>product.title;
    cout<<"цена: ";
    product.price=inputNumber<double>();
    cout<<"количество: ";
    product.quantity=inputNumber<int>();
   
    writing_product_in_file(product);
    reading_products_file();

    cout<<"введите код для поиска товара: ";
    int search_code=inputNumber<int>();
    search_product(search_code);

    summ_price_products();
    
    
    return 0;
}