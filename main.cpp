#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <iomanip>
#include <locale.h>
#include <algorithm>

using namespace std;

int main()
{
    string buf;
    getline(cin, buf);
    bool space = false;
    string res;

    string::iterator ibuf = buf.begin();
    int size = buf.length();
    for (int i = 0;i<size; i++){
        if (*ibuf == ' ' && space == true) {
            // уже встретили пробел, больше не нужно
            ibuf++;
            continue;
        }
        if (*ibuf == ' ' && space == false){
            // не встречали пробел добавляем его в результат
            res.push_back(*ibuf);
            space = true;
            ibuf++;
        }
        else {
            // если символ не пробел – добавляем его
            res.push_back(*ibuf);
            space = false;
            ibuf++;
        }
    }

    buf = res;
    size = buf.length();
    if (buf[0] == ' ')
        buf.erase(0, 1); // если в начале строки остался пробел, удаляем его
    if (buf[size-1] == ' ')
        buf.erase(size-1, 1); // если в конце строки остался пробел, удаляем его
    if ((buf[size-2] == '.') && (buf[size-3] == ' '))
        buf.erase(size-3, 1); // обрабатываем точку
    cout << "строка без лишних пробелов = " << buf << "\n\n";
    res.clear(); // очищаем результат
    size = buf.length();

    // вписываем в res последнее слово (идем с конца)
    for (int i = size - 1; i > 0; i--) {
        if (buf[i] == '.')
            continue;
        if (buf[i] != ' ')
            res += buf[i];
        else
            break;
    }
    reverse(res.begin(), res.end()); // тк записывали в обратном порядке – реверсируем
    cout << "последнее слово = " << res << "\n\n";

    string word, lastletter, lastword;
    int sizer;
    size = buf.length();
    for (int i = 0; i < size; i++) {
        if (buf[i] != ' ')
            word += buf[i]; // записываем пока не встретили пробел символы в word
        else if (word != res) { // если встретили и слово не совпадает с последним
            lastword += word; // записываем в результат (без последнего слова) текущее слово
            sizer = word.length();
            if (sizer != 0)
                word.erase(sizer-1, 1);
            lastletter += word;
            lastletter += ' ';
            lastword += ' ';
            word.clear(); // очищаем слово
        }
        else
            word.clear();

    }
    cout << "без последнего слово = " << lastword << "\n\n";
    cout << "без последней буквы = " << lastletter;
    return 0;
}
