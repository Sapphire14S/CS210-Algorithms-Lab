#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string removeLeadingZeros(const string& str) {
    int i = 0;

    while (i < (int)str.size() - 1 && str[i] == '0') {
        i++;
    }

    return str.substr(i);
}

string addStrings(const string& a, const string& b) {
    string result = "";

    int carry = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;

        if (i >= 0) {
            sum += a[i--] - '0';
        }

        if (j >= 0) {
            sum += b[j--] - '0';
        }

        result.push_back((sum % 10) + '0');

        carry = sum / 10;
    }

    reverse(result.begin(), result.end());

    return removeLeadingZeros(result);
}

string subtractStrings(const string& a, const string& b) {
    string result = "";

    int borrow = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;

    while (i >= 0) {
        int diff = (a[i] - '0') - borrow;

        if (j >= 0) {
            diff -= (b[j] - '0');
        }

        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result.push_back(diff + '0');

        i--;
        j--;
    }

    reverse(result.begin(), result.end());

    return removeLeadingZeros(result);
}

string shiftLeft(const string& str, int zeros) {
    if (str == "0") {
        return "0";
    }

    return str + string(zeros, '0');
}

string karatsuba(string x, string y) {
    x = removeLeadingZeros(x);
    y = removeLeadingZeros(y);

    if (x.size() == 1 && y.size() == 1) {
        return to_string((x[0] - '0') * (y[0] - '0'));
    }

    int n = max(x.size(), y.size());

    if (n % 2 != 0) {
        n++;
    }

    while ((int)x.size() < n) {
        x = "0" + x;
    }

    while ((int)y.size() < n) {
        y = "0" + y;
    }

    int half = n / 2;

    string a = x.substr(0, half);
    string b = x.substr(half);

    string c = y.substr(0, half);
    string d = y.substr(half);

    string ac = karatsuba(a, c);
    string bd = karatsuba(b, d);

    string ab_cd = karatsuba(
        addStrings(a, b),
        addStrings(c, d)
    );

    string middle = subtractStrings(
        subtractStrings(ab_cd, ac),
        bd
    );

    string result = addStrings(addStrings(shiftLeft(ac, 2 * (n - half)), shiftLeft(middle, n - half)), bd );

    return removeLeadingZeros(result);
}

int main() {
    string x, y;

    cin >> x >> y;

    cout << karatsuba(x, y) << endl;

    return 0;
}