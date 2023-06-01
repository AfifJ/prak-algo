#include "iostream"
using namespace std;

// Ubah fungsi ini sehingga menggunakan konsep pointer
void convertSpaceToUnderscore(string &s) {
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == ' ') {
      s[i] = '_';
    }
  }
}

/* 	// Urutkan data menaik berdasarkan nama dari file (Pilih : Bubble Sort
   atau Quick Sort)
        // Isi source code dibawah ini
        for (int i = 0; i < banyakData-1; i++) {
                for (int j = 0; j < banyakData-1-i; j++) {
                        if (temp[j].nama > temp[j+1].nama) {
                                swap(temp[j],temp[j+1]);
                        }
                }
        } */