#include <iostream>
#include <string>
#include <exception>
using namespace std;

namespace phonetic{
        string toLower (string s){
        string ans = "";
        for (auto c:s){
            if (c >= 'A' && c <= 'Z')ans = ans + (char)(c + 'a' - 'A');
            else ans = ans + c;
        }
        return ans;
    }

    string find(string text, string word){
        string temp = "";
       for (auto x:word){
           if (x != ' ') temp = temp + x;
        }
        
        if (word == "" || text == "") throw string("The word you enterd is an empty word");
        text = text + " ";
        int LetterInWorde = 0;
        for (auto c:word){
            LetterInWorde++;
        }
        string ans;
        string tempWorde = "";
        int counter = 0;
        for (auto x:text){
            if (x == ' '){
                if (LetterInWorde == counter){
                    ans = tempWorde;
                    tempWorde = toLower(tempWorde);
                    word = toLower(word);
                    for (int i = 0; i <= LetterInWorde; i++){
                        if (i == LetterInWorde) return ans;
                        if(tempWorde[i] == word[i]) continue;
                        if(tempWorde[i] == 'v' || tempWorde[i] == 'w'){
                            if(word[i] == 'v' || word[i] == 'w') continue;
                        }
                        if(tempWorde[i] == 'b' || tempWorde[i] == 'f' || tempWorde[i] == 'p'){
                            if(word[i] == 'b' || word[i] == 'f' || word[i] == 'p') continue;
                        }
                        if(tempWorde[i] == 'g' || tempWorde[i] == 'j'){
                            if(word[i] == 'g' || word[i] == 'j') continue;
                        }
                        if(tempWorde[i] == 'c' || tempWorde[i] == 'k' || tempWorde[i] == 'q'){
                            if(word[i] == 'c' || word[i] == 'k' || word[i] == 'q') continue;
                        }
                        if(tempWorde[i] == 's' || tempWorde[i] == 'z'){
                            if(word[i] == 's' || word[i] == 'z') continue;
                        }
                        if(tempWorde[i] == 'd' || tempWorde[i] == 't'){
                            if(word[i] == 'd' || word[i] == 't') continue;
                        }
                        if(tempWorde[i] == 'o' || tempWorde[i] == 'u'){
                            if(word[i] == 'o' || word[i] == 'u') continue;
                        }
                        if(tempWorde[i] == 'i' || tempWorde[i] == 'y'){
                            if(word[i] == 'i' || word[i] == 'y') continue;
                        }
                        break;                  
                    }
                }
                counter = 0;
                tempWorde = "";
            }
            else{
              tempWorde = tempWorde + x;
              counter++;
            }
        }
        throw string("The text does not contain the requested word");
    }

}