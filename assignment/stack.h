#include "iostream"
#include "string.h"
using namespace std;

struct nodeStack {
  char data;
  nodeStack *next;
};

nodeStack *start, *top;

void StackInit() {
  start = NULL;
  top = NULL;
}

void StackPush(char ND) {
  nodeStack *NH;
  NH = (nodeStack *)malloc(sizeof(nodeStack));
  NH->data = ND;
  NH->next = NULL;

  if (start == NULL) {
    start = NH;
    top = NH;
  } else {
    top->next = NH;
  }

  top = NH;
  top->next = NULL;
}

void StackPop() {
  if (start == NULL) {
    cout << "Data masih kosong" << endl;
    return;
  }

  nodeStack *NH, *remover;
  remover = top;
  NH = start;
  if (remover == start) {
    start = NULL;
  } else {
    while (NH->next != top)
      NH = NH->next;
    top = NH;
    top->next = NULL;
  }
  delete remover;
}

void StackPrint() {
  if (start == NULL) {
    cout << "Stack masih kosong" << endl;
    return;
  }
  nodeStack *NH;
  NH = start;

  cout << "Bottom -> ";
  while (NH != NULL) {
    cout << NH->data << " ";
    NH = NH->next;
  }
  cout << "<- Top " << endl;
}

int StackJumlah() {
  nodeStack *NH;
  int i = 0;
  NH = start;
  while (NH != NULL) {
    i++;
    NH = NH->next;
  }
  return i;
}

bool StackTooMuch(int banyak, int total) {
  cout << "Banyak input melebihi jumlah isi stack" << endl;
  return banyak > total;
}



/* 
int main() {
  char kembali = 'n';
  do {
    system("cls");
    int total = StackJumlah();
    cout << "Total stack : " << total << endl;

    cout << "Program stack" << endl;
    cout << "Menu" << endl
         << "1. Push to stack" << endl
         << "2. Pop from stack" << endl
         << "3. Print stack" << endl
         << "4. Keluar" << endl
         << "Pilihan : ";
    int menu = 5;
    cin >> menu;

    int i = 0, banyak = 0;
    switch (menu) {
    case 1:
      cout << "Push" << endl << "Banyak data : ";
      cin >> banyak;
      for (i = 0; i < banyak; i++) {
        char newdata = 0;
        bool con = 0;
        do {
          cout << "Masukkan data ke-" << i + 1 << " : ";
          cin >> newdata;
          if (int(toupper(newdata)) < 65 || int(toupper(newdata)) > 90) {
            cout << "Data harus berupa huruf A-Z" << endl;
          } else {
            StackPush(char(toupper(newdata)));
            cout << char(toupper(newdata)) << " berhasil di push" << endl;
            con = 1;
          }
        } while (con == 0);
      }
      cout << "Berhasil melakukan push sebanyak " << i << endl;
      break;
    case 2:
      if (start == NULL) {
        cout << "Stack masih kosong" << endl;
        break;
      }
      cout << "Pop" << endl << "Jumlah data : ";
      cin >> banyak;
      if (banyak > total) {
        cout << "Jumlah pop melebih data yang ada" << endl;
        break;
      }
      for (i = 0; i < banyak; i++) {
        StackPop();
      }
      cout << "Berhasil melakukan pop sebanyak " << i << endl;
      break;
    case 3:
      if (start == NULL) {
        cout << "Stack masih kosong" << endl;
        break;
      }
      cout << "Mencetak stack" << endl;
      StackPrint();
      break;
    case 4:
      break;
    default:
      cout << "Hanya ada pilhan 1-4" << endl;
      break;
    }
    cout << "Kembali ke menu? (y/n) : ";
    cin >> kembali;
  } while (toupper(kembali) == 'Y');
  cout << "Keluar dari program" << endl;
  cin.get();
  return 0;
} */