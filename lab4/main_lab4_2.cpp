#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(){
    string sentence="The quick brown fox jumps over the lazy dog";
    cout<<"исходное предложение: "<<sentence<<endl;
    //первое вхождение подстроки «fox»
    size_t pos = sentence.find("fox");
    cout<<"позиция первого вхождения fox: "<<pos<<endl;
    // содержит ли строка слово «cat»
    string yes_or_no=sentence.find("cat")!=string::npos? "да":"нет";
    cout<<"есть ли слово cat в предложении: "<<yes_or_no<<endl;
    //заменить первое вхождение слова «quick» на «slow»
    string first_word="quick";
    string last_word="slow";
    size_t pos_first_word = sentence.find(first_word);
    sentence.replace(pos_first_word,first_word.length(),last_word);
    cout<<"вывод нового предложения: "<<sentence<<endl;
    //заменить все вхождения буквы «o» на «0»
    for(size_t i = 0; i < sentence.length(); i++){
        if(sentence[i] == 'o'){
            sentence[i] = '0';
        }
    }
    cout << "после замены o на 0: " << sentence << endl;
    //подстрока с 4-го по 8-й символ включительно
    string substring = sentence.substr(3, 5);
    cout << "подстрока с 4-го по 8-й символ: " << substring << endl;






    return 0;
}