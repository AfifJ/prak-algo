#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct klinik {
    string nama, keluhan;
    int umur, noantri, obat;
};

struct mqueue {
  klinik info;
  mqueue *next;
} *depan, *belakang, *historydepan, *historybelakang;

void buathistory() { 
  historydepan = (mqueue *)malloc(sizeof(mqueue));
  historydepan = NULL;
  historybelakang = historydepan;

 }

void buatQ() {
}

void enQ(klinik IB) {
  mqueue *NB;
  NB = (mqueue *)malloc(sizeof(mqueue));
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

void enQhistory(klinik IB) {
  mqueue *NB;
  NB = (mqueue *)malloc(sizeof(mqueue));
  NB->info = IB;
  NB->next = NULL;

  if (historydepan == NULL) {
    historydepan = NB;
    historybelakang = NB;
  } else {
    historybelakang->next = NB;
    historybelakang = NB;
  }
}

// void cetakQ() {
//   if (historydepan == NULL) {
//     cout << "List masih kosong" << endl;
//     return;
//   }
//   queue *bantu;
//   bantu = historydepan;
//   while (bantu != NULL) {
//     cout << bantu->info << " ";
//     bantu = bantu->next;
//   }
//   cout << "Selesai mencetak" << endl;
// }

void deQ() {
  if (depan == NULL) {
    return;
  }
  mqueue *hapus;
  hapus = depan;
  depan = hapus->next;
  hapus->next = NULL;
  free(hapus);
}

int jumlahQ() {
  if (depan == NULL) {
    return 0;
  }
  mqueue *bantu;
  bantu = depan;
  int jumlah = 0;
  while (bantu != NULL) {
    jumlah++;
    bantu = bantu->next;
  }
  return jumlah;
}


struct nodeStack {
  int data;
  nodeStack *next;
} *start, *top;

void StackInit() {
  start = NULL;
  top = NULL;
}

void StackPush(int ND) {
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

queue<klinik> antrianpasien;
stack<int> obat;

void ambilantrian() {
    klinik pasien;

    cout << "Masukkan Nama: ";
    getline(cin >> ws, pasien.nama);
    cout << "Masukkan Keluhan: ";
    getline(cin >> ws, pasien.keluhan);
    cout << "Masukkan Umur: ";
    cin >> pasien.umur;
    // antrianpasien.push(pasien);
    pasien.noantri = int(jumlahQ()) + 1;
    cout << "Nomor Antrean Anda: " << pasien.noantri << endl;
    enQ(pasien);
}

void panggilnomorantri() {
    if (depan == NULL) {
        cout << "Tidak ada pasien dalam antrean." << endl;
        return;
    }

    if (jumlahQ() > 0) {
        cout << "Pasien dengan no " << depan->info.noantri << " di panggil " << endl; 
        StackPush(depan->info.noantri);
        deQ();
    }

}

void ambilobat() {
    if (StackJumlah() < 1) {
        cout << "Tidak ada obat yang tersedia untuk diambil." << endl;
        return;
    }
    // if (obat.empty()) {
    //     cout << "Tidak ada obat yang tersedia untuk diambil." << endl;
    //     return;
    // }

    int idobat;
    cout << "Masukkan ID Obat: ";
    cin >> idobat;
    if (idobat == start->data) {
        StackPop();
        cout << "Obat berhasil diambil." << endl;
    } else {
        cout << "Tunggu dulu." << endl;
    }

}

void historyObat() {
    if (obat.empty()) {
        cout << "Belum ada obat yang tersedia untuk diambil." << endl;
        return;
    }

    stack<int> helper = obat;
    cout << "Histori ambil obat:" << endl;
    while (!helper.empty()) {
        cout << "ID Obat: " << helper.top();
        if (helper.top() == obat.top()) {
            cout << " (Sedang Diproses)";
        } else {
            cout << " (Sudah Diambil)";
        }
        cout << endl;
        helper.pop();
    }
}
int menu()
{
  cout << "Klinik Umum Veteran" << endl
       << "1. Ambil Nomor Antrean" << endl
       << "2. Pemanggilan Nomor Antrean" << endl
       << "3. Pengambilan Obat" << endl
       << "4. Histori Pengambilan obat" << endl
       << "5. Exit" << endl
       << "Pilihan : ";
  int pilih = 0;
  cin >> pilih;
  return pilih;
}
int main() {
    buatQ();
    buathistory();
    StackInit();
    char kemenu = 'n';
    do {
      kemenu = 'n';
      system("clear");
        switch (menu()) {
            case 1:
                ambilantrian();
                break;
            case 2:
                panggilnomorantri();
                break;
            case 3:
                ambilobat();
                break;
            case 4:
                historyObat();
                break;
            case 5:
                cout << "Terima Kasih" << endl;
                break;
            default:
                cout << "Menu tidak valid." << endl;
        }

        cout << "kembali ke menu? : y/n" << endl;
        cin >> kemenu;
    } while (toupper(kemenu) == 'Y');

    cout << "Keluar dari program, terimakasih" << endl;
    return 0;
}