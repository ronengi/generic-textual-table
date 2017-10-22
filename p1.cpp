#include <iostream>
#include <locale>
#include <string>
#include <sstream>

using namespace std;


const int X = 14;
const int Y = 16;

const int SN = 3;
const int SL = 1;
const int SR = 1;
const int S0 = 8;


const wchar_t SPC = U'\U00000020';

const wchar_t CLT = U'\U0000256d';
const wchar_t CRT = U'\U0000256e';
const wchar_t CHH = U'\U00002500';
const wchar_t CVV = U'\U00002502';
const wchar_t CLB = U'\U00002514';
const wchar_t CRB = U'\U00002518';
const wchar_t CTR = U'\U0000251c';
const wchar_t CTL = U'\U00002524';
const wchar_t CHV = U'\U0000253c';
const wchar_t CTD = U'\U0000252c';
const wchar_t CTU = U'\U00002534';


wstring spaces(int i) {
    wostringstream ss;
    while (i > 0) {
        ss << SPC;
        --i;
    }
    return ss.str();
}


wstring repeated(wchar_t c, int i) {
    wostringstream ss;
    while (i > 0) {
        ss << c;
        --i;
    }
    return ss.str();
}


wstring header() {
    wostringstream ss;
    ss << CLT << repeated(CHH, SL + SN + SR);
    for (int i = 1; i < X; ++i)
        ss << CTD << repeated(CHH, SL + SN + SR);
    ss << CRT << endl;
    return ss.str();
}


wstring footer() {
    wostringstream ss;
    ss << CLB << repeated(CHH, SL + SN + SR);
    for (int i = 1; i < X; ++i)
        ss << CTU << repeated(CHH, SL + SN + SR);
    ss << CRB;
    return ss.str();
}


wstring separator() {
    wostringstream ss;
    ss << CTR << repeated(CHH, SL + SN + SR);
    for (int i = 1; i < X; ++i)
        ss << CHV << repeated(CHH, SL + SN + SR);
    ss << CTL;
    return ss.str();
}


int n_length(int n) {
    wostringstream ss;
    ss << n;
    return ss.str().length();
}


wstring number(int n) {
    wostringstream ss;
    int l = SN - n_length(n);
    l = (l < 0) ? 0 : l;
    ss << CVV << repeated(SPC, SL) << repeated(SPC, l) << n << repeated(SPC, SR);
    return ss.str();
}


int main() {
    setlocale(LC_CTYPE,"he_IL.UTF-8");

    wcout << endl << repeated(SPC, S0) << header();
    for (int i = 1; i <= Y; ++i) {
    wcout << repeated(SPC, S0);
        for (int j = 1; j <= X; ++j)
            wcout << number(i * j);
        wcout << CVV << endl;
        if (i < Y)
            wcout << repeated(SPC, S0) << separator() << endl;
    }
    wcout << repeated(SPC, S0) << footer() << endl << endl;
}

