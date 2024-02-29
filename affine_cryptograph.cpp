#include <iostream>

const int keyList[12] = {1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25};
const int keyListInverted[12] = {1, 9, 21, 15, 3, 19, 7, 23, 11, 5, 17, 25};

using namespace std;

bool check(int x){
    for (int i=0; i<12; i++) 
    if (x==keyList[i]) return true;
    return false;
}

void encode() {
    string P,C;
    int a,b;
    cin.ignore();
    cout << "Enter plain text (in uppercase): ";
    std::getline(std::cin, P);
    cout << "Enter key a (a must be co-prime with and smaller than 26): ";
    cin >> a;
    while (!check(a)) {
        cout << "Invalid key, re-enter: ";
        cin >> a;
    }
    cout << "Enter key b (b must be co-prime with and smaller than 26): ";
    cin >> b;
    while (!check(b)) {
        cout << "Invalid key, re-enter: " << endl;
        cin >> b;
    }
    for (int i=0; i<P.length(); i++) {
        if (P[i]==32) C+=' ';
        else if (P[i]>=65&&P[i]<=90) C+=((((int)P[i]-65)*a+b)%26)+65;
        else if (P[i]>=97&&P[i]<=122) C+=((((int)P[i]-97)*a+b)%26)+97;
        else C+=P[i];
    }
    cout << "Cipher text: " << C << endl;
}

void decode(){
    string P,C;
    int a,b;
    cin.ignore();
    cout << "Enter cipher text (in uppercase): ";
    std::getline(std::cin, C);
    cout << "Enter key a (a must be co-prime with and smaller than 26): ";
    cin >> a;
    while (!check(a)) {
        cout << "Invalid key, re-enter: ";
        cin >> a;
    }
    a=check(a);
    cout << "Enter key b (b must be co-prime with and smaller than 26): ";
    cin >> b;
    while (!check(b)) {
        cout << "Invalid key, re-enter: " << endl;
        cin >> b;
    }
    for (int i=0; i<C.length(); i++) {
        if (C[i]==32) P+=' ';
        else if (C[i]>=65&&C[i]<=90) P+=(a*((int)C[i]-65-b)%26)+65;
        else if (C[i]>=97&&C[i]<=122) P+=(a*((int)C[i]-97-b)%26)+97;
        else P+=C[i];
    }
    cout << "Plain text: " << P << endl;
}

int main() {
    int mode;
    cout << "Choose mode (0 for encode, 1 for decode): ";
    cin >> mode;
    if (mode==0) encode();
    if (mode==1) decode();
    return 0;
}