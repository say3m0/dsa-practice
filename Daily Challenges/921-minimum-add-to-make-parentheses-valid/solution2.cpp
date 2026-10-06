#include <iostream>
#include <string>

using namespace std;

int minAddToMakeValid(string s) {
    int balance = 0;      // ওপেন ব্র্যাকেট কয়টা খোলা আছে
    int open_needed = 0;  // কয়টা ')' এর জোড়া পাওয়া যায়নি

    for (char c : s) {
        if (c == '(') {
            balance++;
        } else { // c == ')'
            if (balance > 0) {
                balance--; // আগের একটি '(' এর সাথে ম্যাচ হলো
            } else {
                open_needed++; // ম্যাচিং ছাড়া ')' পাওয়া গেছে
            }
        }
    }

    return open_needed + balance;
}