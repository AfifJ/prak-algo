/*
Buatlah program Queue dengan ketentuan berikut ini :

Tipe info berupa char : huruf besar (A-Z)

Jika user menginputkan huruf kecil (a-z), maka handling agar menjadi huruf besar

Menu :

1. Enqueue : Input secara dinamis, banyak node yang ditambahkan dalam antrian
sesuai keinginan user

2. Dequeue : Input secara dinamis, banyak node yang dihapus dari antrian sesuai
keinginan user. *Inputan hanya berupa banyak node yang ingin dihapus saja.

3. Cetak

4. Keluar
*/

#include "iostream"
using namespace std;

struct queue {
  char info;
  queue *next;
};

/* struct kosong jika (depan == NULL) */
queue *depan, *belakang;

bool charValid(char input) {
  if (int(input) < 64 || int(input) > 90) {
    cout << "Data harus huruf A-Z" << endl;
    return false;
  }
  return true;
}

void buatQ() {
  depan = (queue *)malloc(sizeof(queue));
  depan = NULL;
  belakang = depan;
}

void enQ(char IB) {
  queue *NB;
  NB = (queue *)malloc(sizeof(queue));
  NB->info = IB;
  NB->next = NULL;

  if (depan == NULL) {
    depan = NB;
    belakang = NB;
  } else {
    belakang->next = NB;
    belakang = NB;
  }
}

void deQ() {
  if (depan == NULL) {
    cout << "List masih kosong" << endl;
    return;
  }
  queue *hapus;
  hapus = depan;
  depan = hapus->next;
  hapus->next = NULL;
  free(hapus);
}

int jumlahQ() {
  if (depan == NULL) {
    cout << "List masih kosong" << endl;
    return 0;
  }
  queue *bantu;
  bantu = depan;
  int jumlah = 0;
  while (bantu != NULL) {
    jumlah++;
    bantu = bantu->next;
  }
  return jumlah;
}

void cetakQ() {
  if (depan == NULL) {
    cout << "List masih kosong" << endl;
    return;
  }
  queue *bantu;
  bantu = depan;
  while (bantu != NULL) {
    cout << bantu->info << " ";
    bantu = bantu->next;
  }
  cout << "Selesai mencetak" << endl;
}

/* IGNORE THE MAIN FUNC */

/*
int main() {

  char inputKeMenu = 'n';
  // membuat queue
  buatQ();
  do {
    system("cls");
    cout << "Queue : " << endl
         << "Jumlah queue : " << jumlahQ() << endl
         << "Queue depan = kiri" << endl
         << "Queue belakang = kanan" << endl
         << endl;

    cout << "Menu" << endl
         << "1. Enqueue" << endl
         << "2. Dequeue" << endl
         << "3. Cetak" << endl
         << "4. Keluar" << endl
         << "Pilihan : ";
    int inputPilihan = 0;
    cin >> inputPilihan;

    int jml = 0;
    switch (inputPilihan) {
    case 1:
      cout << "Banyak data input : ";
      cin >> jml;
      for (int i = 0; i < jml; i++) {
        char tambah = 'a';
        do {
          cout << "Tambah : ";
          cin >> tambah;
          tambah = toupper(tambah);
        } while (!charValid(tambah));
        enQ(tambah);
      }
      break;
    case 2:
      if (depan == NULL) {
        cout << "Data masih kosong" << endl;
        break;
      }
      cout << "Banyak data dihapus : ";
      cin >> jml;
      for (int i = 0; i < jml; i++)
        deQ();
      cout << jml << " data berhasil dihapus" << endl;
      break;
    case 3:
      if (depan == NULL) {
        cout << "Data masih kosong" << endl;
        break;
      }
      cout << "Cetak data : " << endl;
      cetakQ();
      break;
    case 4:
      cout << "Keluar program" << endl;
      return 0;
      break;
    default:
      cout << "Hanya ada pilihan 1-4" << endl;
      break;
    }
    cout << "Kembali ke menu? (y/n) : ";
    cin >> inputKeMenu;
    if (toupper(inputKeMenu) == 'N')
      break;
  } while (toupper(inputKeMenu) == 'Y');

  cout << "Keluar program" << endl;
  return 0;
}
 */
