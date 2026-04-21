#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm> 
using namespace std;

int main(){
    string sentence;
    cout << "введите строку из слов, разделенных запятыми: ";
    getline(cin, sentence);
    string word = "";
    vector<string> words;
    //разбить слова по запятым
    for(size_t i = 0; i < sentence.length(); i++){
        if(sentence[i] != ','){
            word += sentence[i];
        }
        else if(sentence[i] == ',' && word.length() > 0){
            words.push_back(word);
            word = "";
        }
    }
    if(word.length() > 0){
        words.push_back(word);
    }
    //вывод количества элементов
    cout << "количество элементов: " << words.size() << endl;
    //вывод всех слов
    for(size_t i = 0; i < words.size(); i++){
        cout << i + 1 << ". " << words[i] << endl;
    }
    //поиск самого длинного слова
    auto it = max_element(words.begin(), words.end(), [](string& word1, string& word2) {
        return word1.length() < word2.length();
    });
    cout << "самое длинное слово: " << *it << endl;
    //объединение слов в одно предложение 
    string result = "";
    for(size_t i = 0; i < words.size(); i++){
        result += words[i];
        if(i != words.size() - 1){
            result += " | ";
        }
    }
    cout << "объединенная строка: " << result << endl;
    
    return 0;
}