#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;


int cnt_correct_numbers=0;

void format_number(string& number){
    cnt_correct_numbers++;
    string digits="";
    for (size_t i = 0; i < number.length(); i++)  
        if(isdigit(number[i])) {
            digits += number[i]; 

        }
    if (digits.length()==10){
       digits.insert(0,"7");

    }
    // if (digits[0] == '8') {
    //     digits[0] = '7';
    // }
    digits.insert(0,"+");
    digits.insert(2," (");
    digits.insert(7,") ");
    digits.insert(12,"-");
    digits.insert(15,"-");
    cout<<"номер телефона по унифицированному формату: "<<digits<<endl;

}

void validn_number(string& number){
    if(isdigit(number[0]) || number[0]=='+'){
        cout<<"номер "<<number<<" валидный"<<endl;
        format_number(number);

    }
    else{
        cout<<"номер "<<number<<" не валидный"<<endl;
        cout<<"в начале номера что-то не то"<<endl;
    }
}

void enough_number(string& number){
    int size_numb=count_if(number.begin(),number.end(),::isdigit);
    if (size_numb==10 || size_numb==11){
        validn_number(number);
    }
    else if (size_numb<10){
        cout<<"номер "<<number <<" невалидный"<<endl;
        cout<<"недостаточно цифр в номере: "<<size_numb<<endl;
        
    }
    else{
        cout<<"номер "<<number <<" невалидный"<<endl;
        cout<<"слишком много цифр в номере: "<<size_numb<<endl;
    }

}

int main(){
    vector<string> numbers = {
        "+7 (999) 123-45-67",
        "8-999-123-45-67",
        "+1 212 456-7890",
        "999-123-45-67",
        "+7999123456789",
        "123456789"
    };
   
    for (size_t i=0;i<numbers.size();i++){
        enough_number(numbers[i]);
        cout<<endl;
    }
    cout<<"количество валидных номеров: "<<cnt_correct_numbers<<endl;
    cout<<"количество невалидных номеров: "<<numbers.size()- cnt_correct_numbers<<endl;


    
}