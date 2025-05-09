#include <iostream>
using namespace std;

class MataKuliah {
public:
    string namaMatkul;
    int sks;

    void input() {
        cout << " ";
        getline(cin, namaMatkul);
        cout << "Jumlah SKS        : ";
        cin >> sks;
        cin.ignore();
    }

    void tampil() {
        cout << " - " << namaMatkul << " (" << sks << " SKS)" << endl;
    }
};

class Mahasiswa {
private:
    string nama;
    string nim;
    MataKuliah matkul[100];
    int jumlahMatkul;
    int totalSKS;
    int hargaPerSKS;
    float diskon;
    int biayaNormal;
    int potongan;
    int totalBayar;

public:
    void inisialisasi() {
        totalSKS = 0;
        hargaPerSKS = 125000;
        diskon = 0.15f;
        biayaNormal = 0;
        potongan = 0;
        totalBayar = 0;
    }

    void inputData() {
        inisialisasi();
        cout << "+============================================+\n";
        cout << "|        Program Hitung UKT Mahasiswa        |\n";
        cout << "+============================================+\n";
        cout << "|Masukkan Nama          : ";
        getline(cin, nama);
        cout << "|Masukkan NIM           : ";
        getline(cin, nim);
        cout << "|Masukkan jumlah matkul : ";
        cin >> jumlahMatkul;
        cin.ignore();
        cout << "+============================================+\n";

        if (jumlahMatkul > 100) {
            jumlahMatkul = 100;
            cout << "Jumlah mata kuliah dibatasi maksimal 100.\n";
        }

        for (int i = 0; i < jumlahMatkul; i++) {
        	
            cout << "\nNama Mata Kuliah ke-" << i + 1 << ": ";
            matkul[i].input();
            cout << "\nNama Mata Kuliah ke-" << i + 1 << ": ";
            matkul[i].input();
            totalSKS += matkul[i].sks;
        }
        

        hitungBiaya();
    }
    

    void hitungBiaya() {
        biayaNormal = totalSKS * hargaPerSKS;
        potongan = static_cast<int>(biayaNormal * diskon);
        totalBayar = biayaNormal - potongan;
    }
    
    

    void tampilkanData() {
        cout << "\n\n+--------------------------------------------+\n";
        cout << "Total SKS        : " << totalSKS << endl;
        cout << "Total Pembayaran : Rp " << totalBayar << endl;
        cout << "+============================================+\n";
    }
};

int main() {
    Mahasiswa mhs;
    mhs.inputData();
    mhs.tampilkanData();

    return 0;
}
