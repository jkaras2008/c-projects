#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

int last_octet(string ip) {
    string help;
    int i = ip.length();
    while (ip[i - 1] != char(46)) {
        help += ip[i - 1];
        i -= 1;
    }
    reverse(help.begin(), help.end());
    int n = stoi(help);
    return n;
}

string no_last_octet(string ip) {
    int i = ip.length();
    while (ip[i - 1] != char(46)) {
        ip[i - 1] = char(0);
        i -= 1;
    }
    return ip;
}

int square(int podsieci) {
    int help = 2, square = 0, i = 1, ded = 0, rem;
    string conv;
    while (square < podsieci) {
        square = pow(help, i);
        i++;
    }
    help = 9 - i;
    for (int j = 0; j < help; j++) {
        conv += char(49);
    }
    i = 0;
    int n = stoi(conv);
    while (n != 0) {
        rem = n % 10;
        n /= 10;
        ded += rem * pow(2, i);
        ++i;
    }
    return ded + 1;
}

void print(string ip, int hosty, int podsieci, int octet) {
    int help = 0;
    for (int i = 1; i <= podsieci; i++) {
        cout << i << ".  " << ip << help+octet << endl;
        help += hosty;
    }
}

int main() {
    string ip;
    int prefiks, podsieci, hosty, octet;
    cout << "type in ip v4: ";
    cin >> ip;
    cout << "prefix is 24"<<endl;
    cout << "type wanted amount of subnets: ";
    cin >> podsieci;
    octet = last_octet(ip);
    ip = no_last_octet(ip);
    hosty = square(podsieci);
    print(ip, hosty, podsieci, octet);
}
