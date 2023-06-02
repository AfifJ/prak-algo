#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Pasien {
    string nama;
    string keluhan;
    int umur;
    int nomorAntrean;
};

queue<Pasien> antrianPasien;
stack<Pasien> obatPasien;
stack<Pasien> historiPengambilanObat;

void ambilNomorAntrean() {
    string nama, keluhan;
    int umur;

    cout << "Masukkan nama lengkap: ";
    cin.ignore();
    getline(cin, nama);
    cout << "Masukkan keluhan: ";
    getline(cin, keluhan);
    cout << "Masukkan umur: ";
    cin >> umur;

    int nomorAntrean = antrianPasien.size() + 1;
    Pasien pasien = {nama, keluhan, umur, nomorAntrean};
    antrianPasien.push(pasien);

    cout << "Nomor antrean Anda: " << nomorAntrean << endl;
}

void pemanggilanNomorAntrean() {
    if (antrianPasien.empty()) {
        cout << "Belum ada pasien yang mengantri." << endl;
        return;
    }

    Pasien pasien;

    while (!antrianPasien.empty()) {
        pasien = antrianPasien.front();
        antrianPasien.pop();

        if (pasien.umur > 60) {
            break;
        } else {
            obatPasien.push(pasien);
        }
    }

    if (pasien.umur > 60) {
        cout << "Memanggil nomor antrean pasien lansia: " << pasien.nomorAntrean << endl;
        obatPasien.push(pasien);
    } else {
        cout << "Tidak ada pasien lansia yang dapat dipanggil saat ini." << endl;
    }
}

void pengambilanObat() {
    if (obatPasien.empty()) {
        cout << "Belum ada obat yang dapat diambil." << endl;
        return;
    }

    int idObat;
    cout << "Masukkan ID obat: ";
    cin >> idObat;

    Pasien pasien = obatPasien.top();
    if (idObat == pasien.nomorAntrean) {
        obatPasien.pop();
        historiPengambilanObat.push(pasien);
        cout << "Pengambilan obat berhasil." << endl;
    } else {
        cout << "ID obat tidak ditemukan." << endl;
    }
}

void historiPengambilanObat() {
    if (historiPengambilanObat.empty()) {
        cout << "Belum ada histori pengambilan obat." << endl;
        return;
    }

    stack<Pasien> tempStack = historiPengambilanObat;

    while (!tempStack.empty()) {
        Pasien pasien = tempStack.top();
        tempStack.pop();
        cout << "ID obat: " << pasien.nomorAntrean << endl;
        cout << "Status: " << (pasien.umur > 60 ? "Sudah Diambil" : "Belum Diambil") << endl;
        cout << endl;
    }
}

int main() {
    while (true) {
        cout << "Menu Utama" << endl;
        cout << "1. Ambil Nomor Antrean" << endl;
        cout << "2. Pemanggilan Nomor Antrean" << endl;
        cout << "3. Pengambilan Obat" << endl;
        cout << "4. Histori Pengambilan Obat" << endl;
        cout << "5. Exit" << endl;

        int pilihan;
        cout << "Masukkan pilihan menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                ambilNomorAntrean();
                break;
            case 2:
                pemanggilanNomorAntrean();
                break;
            case 3:
                pengambilanObat();
                break;
            case 4:
                historiPengambilanObat();
                break;
            case 5:
                cout << "Terima Kasih." << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid." << endl;
        }

        cout << endl;
    }

    return 0;
}