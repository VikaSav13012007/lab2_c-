#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm> 
using namespace std;

int main(){
    
    string sentence = "Programming is fun. C++ is powerful. Programming requires practice.";
    cout<<"исходное предложение: "<<sentence<<endl;
    //int cnt_spaces=count(sentence.begin(),sentence.end(),' ');
    //int cnt_sentence=count(sentence.begin(),sentence.end(),'.');
    //int number_of_words=cnt_spaces+1;
    //int number_of_symbols=sentence.length()-cnt_spaces;
    int number_of_symbols=0;
    int number_of_words=0;
    int cnt_sentence=0;
    bool flag_word=false;
    bool flag_sentence=false;
    for (size_t i=0;i<sentence.length();i++){
        if (sentence[i]!=' '){
            number_of_symbols++;
            flag_word=true;
        }
        else{
            if (flag_word){number_of_words++;}
            flag_word=false;
        } 
        if(sentence[i]!='.'){flag_sentence=true;}
        else{
            if (flag_sentence){flag_sentence=false; cnt_sentence++;}
        }
    
    }
    if(flag_word){
    number_of_words++;
    }
    if (flag_sentence){cnt_sentence++;}
    cout<<"общее количество символов: "<<number_of_symbols <<endl;
    cout<<"общее количество слов: "<< number_of_words<<endl;
    cout<<"общее количество предложений: "<<cnt_sentence <<endl;
    string word_to_find="is";
    size_t pos=0;
    int number_word_find=0;
    while((pos = sentence.find(word_to_find, pos)) != string::npos){
        number_word_find++;
        pos += word_to_find.length();
    }
    cout<<"количество вхождений слова "<<word_to_find<<": "<<number_word_find<<endl;
    transform(sentence.begin(),sentence.end(), sentence.begin(),::toupper);
    cout<<"вывод первых 20 символов после изменения регистра: ";
    int number_symbols_print=20;
    for(size_t i = 0; i < number_symbols_print && i < sentence.length(); i++){
        cout << sentence[i];
    }
    cout << endl;
    string new_sentence=sentence;

    pos = 0;
    while((pos = new_sentence.find('.', pos)) != string::npos){
        new_sentence.replace(pos, 1, "!");
        pos++;
    }
    cout << "новая строка с ! вместо точек: " << new_sentence << endl;
    
    








}