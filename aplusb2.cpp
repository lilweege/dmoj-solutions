#include <bits/stdc++.h>
using namespace std;


// itoa is non standard
// https://www.geeksforgeeks.org/implement-itoa/
char* itoa(int num, char* str, int base) {
    int i = 0;
    bool isNegative = false;
    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
    if (num < 0 && base == 10) {
		isNegative = true;
		num = -num;
    }
    while (num != 0) {
		int rem = num % base;
		str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
		num = num/base;
    }
	if (isNegative)
		str[i++] = '-';
	str[i] = '\0';
	int start = 0; 
    int end = i - 1; 
    while (start < end) {
        swap(*(str+start), *(str+end));
        start++;
        end--;
    }
	return str;
}





string sub(string a, string b) {
	char buff[10];
	string res = "";
	int lenA = a.length();
	int lenB = b.length();
	int lenDiff = lenA - lenB;
	int carry = 0;
	
	for (int i = lenB-1; i >= 0; i--) {
		int diff = (a[i + lenDiff] - '0') - (b[i] - '0') - carry;
		if (diff < 0) {
			diff += 10;
			carry = 1;
		}
		else {
			carry = 0;
		}
		itoa(diff, buff, 10);
		res += buff;
	}
	
	for (int i = lenDiff-1; i >= 0; i--) {
		if (a[i] == '0' && carry > 0) {
			res += "9";
			continue;
		}
		int diff = a[i] - '0' - carry;
		if (i > 0 || diff > 0) {
			itoa(diff, buff, 10);
			res += buff;
		}
		carry = 0;
	}
	return string(res.rbegin(), res.rend());
}

string add(string a, string b) {
	string res = "";
	int lenA = a.length();
	int lenB = b.length();
	if (lenA > lenB) {
		swap(a, b);
		swap(lenA, lenB);
	}
	
	int lenDiff = lenB - lenA;
	int carry = 0;
	for (int i = lenA- 1; i >= 0; i--) {
		int sum = (a[i] - '0') + (b[i + lenDiff] - '0') + carry;
		res += (char)(sum % 10 + '0');
		carry = sum / 10;
	}
	
	for (int i = lenDiff-1; i >= 0; i--) {
		int sum = b[i] - '0' + carry;
		res += (char)(sum % 10 + '0');
		carry = sum / 10;
	}
	
	if (carry > 0) {
		res += (char)(carry + '0');
	}
	
	return string(res.rbegin(), res.rend());
}

string trimZeros(string str) {
	int i = 0;
	while (i < str.size() && str[i] == '0')
		++i;
	return str.substr(i);
}

int isSmaller(string a, string b) {
	int lenA = a.length();
	int lenB = b.length();
	
	if (lenA < lenB)
		return 1;
	
	if (lenA > lenB)
		return -1;
	
	for (int i = 0; i < lenA; i++) {
		if (a[i] < b[i])
			return 1;
		if (a[i] > b[i])
			return -1;
	}
	
	return 0;
}

string apb(string a, string b) {
	string res = "";
	bool aIsNeg = a[0] == '-';
	bool bIsNeg = b[0] == '-';
	if (aIsNeg == bIsNeg)
		if (aIsNeg)
			res = "-" + trimZeros(add(a.substr(1), b.substr(1)));
		else
			res = trimZeros(add(a, b));
	
	else
		if (aIsNeg) {
			a = a.substr(1);
			int smaller = isSmaller(b, a);
			if (smaller > 0) {
				res = "-" + trimZeros(sub(a, b));
			}
			else if (smaller < 0) {
				res = trimZeros(sub(b, a));
			}
			else {
				return "0";
			}
		}
		else {
			b = b.substr(1);
			int smaller = isSmaller(b, a);
			if (smaller > 0) {
				res = trimZeros(sub(a, b));
			}
			else if (smaller < 0) {
				res = "-" + trimZeros(sub(b, a));
			}
			else {
				return "0";
			}
		}
	
	return res;
}

int main() {
	int n;
	cin >> n;
	do {
		string a, b;
		cin >> a >> b;
		cout << apb(a, b) << endl;
	} while (--n);
}