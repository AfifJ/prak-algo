// dengan kepala dan ekor
#include "conio.h"
#include "iostream"
#include "malloc.h"

using namespace std;

typedef struct node *ptr;
struct node {
  char data;
  ptr next;
};
ptr kepala, ekor;

void CreateList() {

  kepala = (ptr)malloc(sizeof(ptr));
  ekor = (ptr)malloc(sizeof(ptr));

  kepala->data = 64;
  ekor->data = 91;

  kepala->next = ekor;
  ekor->next = NULL;
}

char Conversion(char input) {
  if (input > 64 && input < 91)
    input = input;
  else if (input > 96 && input < 123)
    input = input - 32;
  else {
    cout << "Input harus huruf a-z" << endl;
    input = -1;
  }
  return input;
}

void InputNode() {
  char input = -1;
  do {

    cout << "Masukkan inputan A - Z" << endl;
    cin >> input;
    input = Conversion(input);
  } while (input == -1);

  ptr bantu, NB;
  NB = (ptr)malloc(sizeof(ptr));
  NB->data = input;
  NB->next = NULL;
  bantu = kepala;

  while (input > bantu->next->data)
    bantu = bantu->next;

  NB->next = bantu->next;
  bantu->next = NB;

  cout << input << " telah ditambahkan" << endl << endl;
}

void RemoveNode() {
  char input = -1;
  bool found = 0;

  cout << "Yang ingin dihapus: ";
  cin >> input;
  input = Conversion(input);
  ptr bantu = kepala->next;
  while (bantu->next != NULL) {
    if (input == bantu->data)
      found = 1;
    bantu = bantu->next;
  }
  if (found == 0) {
    cout << "Data tidak ditemukan" << endl;
    return;
  } else {
    cout << "Ditemukan" << endl << "DIHAPUS : " << input << endl;
  }

  ptr remove;
  bantu = kepala;

  while (bantu->next->data != input) {
    bantu = bantu->next;
  }

  remove = bantu->next;
  bantu->next = remove->next;
  free(remove);
}

void PrintList() {
  ptr bantu = kepala->next;
  while (bantu->next != NULL) {
    cout << char(bantu->data) << " ";
    bantu = bantu->next;
  }
  cout << endl;
}

void ReverseList() {
  ptr belakang, bantu;
  belakang = kepala;

  kepala = ekor;

  while (ekor != belakang) {
    bantu = belakang;
    while (bantu->next != ekor)
      bantu = bantu->next;
    bantu->next->next = bantu;
    ekor = bantu;
  }
  ekor->next = NULL;
}

int fmenu() {
  cout << "Menu" << endl
       << "1. Input Node" << endl
       << "2. Hapus Node" << endl
       << "3. Baca Maju" << endl
       << "4. Baca Mundur" << endl
       << "5. Keluar" << endl
       << "Pilihan : ";
  int pil;
  cin >> pil;
  if (!cin) {
    cout << "Masukkan hanya angka 1 - 5" << endl;
    cin.clear();
    cin.ignore();
    getch();
  }
  return pil;
}

bool Kosong() {
  if (kepala->next == ekor) {
    cout << "Link kosong, silahkan input node dahulu" << endl;
    getch();
    return 1;
  } else
    return 0;
}















// ganda

/* 
typedef struct node *ptrnode;

struct node {
  char info;
  ptrnode prev;
  ptrnode next;
};

ptrnode awal, akhir;

void buatNode() {
  awal = (node *)malloc(sizeof(node));
  akhir = (node *)malloc(sizeof(node));

  awal = NULL;
  akhir = NULL;
}

bool kosong() {
  if (awal == NULL) {
    cout << "Linked list kosong" << endl;
    return 1;
  } else
    return 0;
}

void sisipNode() {
  int n;
  cout << "Banyak sisip node : ";
  cin >> n;

  ptrnode bantu;

  bantu = awal;
  for (int i = 0; i < n; i++) {
    // sisip node
    char IB;
    do {
      cout << "Silahkan masukkan node : ";
      cin >> IB;
      if (IB >= 65 && IB <= 90 || IB >= 97 && IB <= 122)
        break;
      else
        cout << "Input harus A - Z" << endl;
    } while (true);

    if (IB >= 97 && IB <= 122)
      IB = IB - 32;

    ptrnode NB;
    NB = (node *)malloc(sizeof(node));
    NB->info = IB;
    NB->next = NULL;
    NB->prev = NULL;

    if (awal == NULL) {
      awal = NB;
      akhir = NB;
    } else if (IB <= awal->info) {
      awal->prev = NB;
      NB->next = awal;
      awal = NB;

    } else if (IB >= akhir->info) {
      akhir->next = NB;
      NB->prev = akhir;

      akhir = NB;

    } else if (IB > awal->info && IB < akhir->info) {
      bantu = awal;
      while (IB > bantu->next->info)
        bantu = bantu->next;

      NB->prev = bantu;
      NB->next = bantu->next;
      bantu->next->prev = NB;
      bantu->next = NB;
    }
    cout << "Sukses menambahkan " << IB << endl;
  }
}

void hapusNode() {
  if (kosong())
    return;

  int hitung = 0;
  ptrnode bantu;
  bantu = awal;
  while (bantu != NULL) {
    bantu = bantu->next;
    hitung++;
  }

  int n;
  do {
    cout << "Jumlah node yang ingin dihapus : ";
    cin >> n;
    if (n >= 0 && n <= hitung)
      break;
    else
      cout << "Jumlah node saat ini : " << hitung << endl;
  } while (true);

  char IH;
  for (int i = 0; i < n; i++) {
    cout << "Node yang ingin dihapus : ";
    cin >> IH;

    if (IH >= 97 && IH <= 122)
      IH = IH - 32;
    cout << endl << IH << endl;

    bantu = awal;
    bool found = false;

    while (bantu != NULL) {
      if (bantu->info == IH) {
        found = true;
        break;
      }
      bantu = bantu->next;
    }

    if (!found) {
      cout << "Tidak ditemukan " << IH << " dalam Linked List" << endl;
      return;
    }

    ptrnode hapus;
    bantu = awal;

    if (awal == akhir) {
      hapus = awal;
      awal = NULL;
      akhir = NULL;
      free(hapus);
    } else if (IH == awal->info) {
      hapus = awal;
      awal = awal->next;
      hapus->next = NULL;
      awal->prev = NULL;
      free(hapus);
    } else if (IH == akhir->info) {
      hapus = akhir;
      akhir = akhir->prev;
      hapus->prev = NULL;
      akhir->next = NULL;
      free(hapus);
    } else if (IH > awal->info && IH < akhir->info) {
      bantu = awal;
      while (bantu->next->info != IH)
        bantu = bantu->next;
      hapus = bantu->next;
      bantu->next = hapus->next;
      bantu->next->prev = bantu;
      free(hapus);
    }

    cout << "Node " << IH << " berhasil dihapus" << endl;
  }
}

void bacaMaju() {
  if (kosong())
    return;

  ptrnode bantu;
  cout << "Cetak Maju" << endl;
  bantu = awal;
  while (bantu != NULL) {
    cout << bantu->info << " ";
    bantu = bantu->next;
  }
  cout << endl << endl;
}

void bacaMundur() {
  if (kosong())
    return;

  ptrnode bantu;
  cout << "Cetak Mundur" << endl;
  bantu = akhir;
  while (bantu != NULL) {
    cout << bantu->info << " ";
    bantu = bantu->prev;
  }
  cout << endl << endl;
}
 */