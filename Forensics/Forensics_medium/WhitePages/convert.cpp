#include <bits/stdc++.h>
using namespace std;

int main() {
    // UTF-8の文字列をUTF-32に変換
    wstring_convert<codecvt_utf8<char32_t>, char32_t> conv;
    u32string u32 = conv.from_bytes("                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                "); // 長い文字列

    for (char32_t c : u32) {
        if (c == U' ') {           // 半角スペース (U+0020)
            cout << 1;
        } else if (c == U'\u2003') { // エムスペース (U+2003)
            cout << 0;
        } else {
            cout << "?"; // 他の文字が混じっていたら確認用
        }
    }

    return 0;
}
