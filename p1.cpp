#include <iostream>
#include <locale>
#include <string>
#include <sstream>

using namespace std;


const int X = 10;
const int Y = 10;

const int SN = 3;
const int SL = 1;
const int SR = 1;



const wchar_t CLT = U'\U0000256d';
const wchar_t CRT = U'\U0000256e';
const wchar_t CHH = U'\U00002500';
const wchar_t CVV = U'\U00002502';
const wchar_t CLB = U'\U00002514';
const wchar_t CRB = U'\U00002518';
const wchar_t CVR = U'\U0000251c';
const wchar_t CLV = U'\U00002524';
const wchar_t CHV = U'\U0000253c';


wstring spaces(int i) {
    wostringstream ss;
    while (i > 0) {
        ss << L" ";
        --i;
    }
    return ss.str();
}


wstring header() {
    wostringstream ss;
    ss << endl << CLT;
    for (int i = 1; i < X * (1 + SL + SN + SR); ++i)
        ss << CHH;
    ss << CRT << endl;
    return ss.str();
}

wstring footer() {
    wostringstream ss;
    ss << CLB;
    for (int i = 1; i < X * (1 + SL + SN + SR); ++i)
        ss << CHH;
    ss << CRB << endl;
    return ss.str();
}

wstring separator() {
    wostringstream ss;
    ss << CVR;
    for (int i = 1; i < X * (1 + SL + SN + SR); ++i)
        ss << CHH;
    ss << CLV << endl;
    return ss.str();
}


wstring number(int n) {
    wostringstream ss;
    ss << CVV << spaces(SL);
    if (n < 10)
        ss << spaces(SN - 1); 
    else if (n < 100)
        ss << spaces(SN - 2); 
    else
        ss << spaces(SN - 3); 
    ss << n << spaces(SR);
    return ss.str();
}


int main() {
    setlocale(LC_CTYPE,"he_IL.UTF-8");

    wcout << header();

    for (int i = 1; i <= Y; ++i) {
        for (int j = 1; j <= X; ++j)
            wcout << number(i * j);
        wcout << CVV << endl;

        if (i < Y)
            wcout << separator();
    }

    wcout << footer();
}

