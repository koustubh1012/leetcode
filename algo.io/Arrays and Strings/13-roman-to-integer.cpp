#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        int romanToInt(string s) {
            int num = 0;
            for(int i=0; i < s.size(); i++){
                if (i < s.size()-1){
                    if (s[i] == 'I' && s[i+1] == 'V'){
                        num += 4;
                        i += 1;
                        continue;
                    }
                    if (s[i] == 'I' && s[i+1] == 'X'){
                        num += 9;
                        i += 1;
                        continue;
                    }
                    if (s[i] == 'X' && s[i+1] == 'L'){
                        num += 40;
                        i +=1;
                        continue;
                    }
                    if (s[i] == 'X' && s[i+1] == 'C'){
                        num += 90;
                        i += 1;
                        continue;
                    }
                    if (s[i] == 'C' && s[i+1] == 'D'){
                        num += 400;
                        i += 1;
                        continue;
                    }
                    if (s[i] == 'C' && s[i+1] == 'M'){
                        num += 900;
                        i += 1;
                        continue;
                    }    
                }
                    switch(s[i]){
                    case 'I': num += 1; break;
                    case 'V': num += 5; break;
                    case 'X': num += 10; break;
                    case 'L': num += 50; break;
                    case 'C': num += 100; break;
                    case 'D': num += 500; break;
                    case 'M': num += 1000; break;
                }
            }
            return num;
        }
    };


// class Solution {
// public:
//     int romanToInt(string s) {
//         int num = 0;
//         for (int i = 0; i < s.size(); ) {
//             if (i < s.size() - 1) {
//                 if (s[i] == 'I' && s[i+1] == 'V') {
//                     num += 4; i += 2;
//                     cout << "Added 4 -> " << num << endl;
//                     continue;
//                 }
//                 if (s[i] == 'I' && s[i+1] == 'X') {
//                     num += 9; i += 2;
//                     cout << "Added 9 -> " << num << endl;
//                     continue;
//                 }
//                 if (s[i] == 'X' && s[i+1] == 'L') {
//                     num += 40; i += 2;
//                     cout << "Added 40 -> " << num << endl;
//                     continue;
//                 }
//                 if (s[i] == 'X' && s[i+1] == 'C') {
//                     num += 90; i += 2;
//                     cout << "Added 90 -> " << num << endl;
//                     continue;
//                 }
//                 if (s[i] == 'C' && s[i+1] == 'D') {
//                     num += 400; i += 2;
//                     cout << "Added 400 -> " << num << endl;
//                     continue;
//                 }
//                 if (s[i] == 'C' && s[i+1] == 'M') {
//                     num += 900; i += 2;
//                     cout << "Added 900 -> " << num << endl;
//                     continue;
//                 }
//             }

//             // Single characters
//             switch(s[i]) {
//                 case 'I': num += 1; cout << "Added 1 -> " << num << endl; break;
//                 case 'V': num += 5; cout << "Added 5 -> " << num << endl; break;
//                 case 'X': num += 10; cout << "Added 10 -> " << num << endl; break;
//                 case 'L': num += 50; cout << "Added 50 -> " << num << endl; break;
//                 case 'C': num += 100; cout << "Added 100 -> " << num << endl; break;
//                 case 'D': num += 500; cout << "Added 500 -> " << num << endl; break;
//                 case 'M': num += 1000; cout << "Added 1000 -> " << num << endl; break;
//             }
//             i++;
//         }
//         return num;
//     }
// };

int main() {
    Solution solution;
    string s = "MCMXCIV";
    int result = solution.romanToInt(s);
    cout << "The integer value of " << s << " is: " << result << endl;
    return 0;
}
