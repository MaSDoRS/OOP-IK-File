#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

class Robot {
private:
    double v;     // Kecepatan linear
    double omega; // Kecepatan angular
    double v1;    // Kecepatan roda kiri
    double v2;    // Kecepatan roda kanan
    double r;     // Jari-jari robot
    double jarakTempuh; // Jarak yang ingin ditempuh
    double t;     // Waktu tempuh
    double sudut; // Sudut arah robot dalam derajat

public:
    // Constructor
    Robot(double jarak, double waktuTempuh, double derajat) {
        jarakTempuh = jarak;
        t = waktuTempuh;
        sudut = derajat;
        r = 5.0; // Tetapan jari-jari roda robot 5 cm

        hitungKecepatan();
        hitungKecepatanRoda();
    }

    // Fungsi untuk menghitung kecepatan linear dan angular
    void hitungKecepatan() {
        v = jarakTempuh / t; // Kecepatan linear
        omega = (sudut * M_PI / 180) / t; // Kecepatan angular dalam rad/s
    }

    // Fungsi untuk menghitung kecepatan tiap roda
    void hitungKecepatanRoda() {
        v1 = v - (omega * r); // Kecepatan roda kiri
        v2 = v + (omega * r); // Kecepatan roda kanan
    }

    // Fungsi untuk menampilkan hasil
    void tampilkanHasil() {
        cout << "Kecepatan Linear (v): " << v << " cm/s" << endl;
        cout << "Kecepatan Angular (omega): " << omega << " rad/s" << endl;
        cout << "Kecepatan Roda Kiri (v1): " << v1 << " cm/s" << endl;
        cout << "Kecepatan Roda Kanan (v2): " << v2 << " cm/s" << endl;
    }

    // Fungsi untuk menyimpan hasil ke file
    void simpanKeFile() {
        ofstream file("datakecepatan.txt", ios::out | ios::app); // Membuka file dalam mode append
        if (file.is_open()) {
            file << "Bila robot ingin menempuh " << jarakTempuh << " cm dalam " << t << " detik dan arahnya " << sudut << "° derajat dari sumbu X+" << endl;
            file << "maka nanti kecepatannya akan seperti ini :"<< endl;
            file << "Kecepatan Linear (v): " << v << " cm/s" << endl;
            file << "Kecepatan Angular (omega): " << omega << " rad/s" << endl;
            file << "Kecepatan Roda Kiri (v1): " << v1 << " cm/s" << endl;
            file << "Kecepatan Roda Kanan (v2): " << v2 << " cm/s" << endl;
            file << "-----------------------------" << endl; // Memisahkan setiap entri
            file.close();
            cout << "Hasil disimpan di datakecepatan.txt" << endl;
        } else {
            cout << "Gagal membuka file." << endl;
        }
    }
};

int main() {
    double jarakTempuh, waktuTempuh, sudut;
    
    cout << "Masukkan jarak tempuh dalam cm: ";
    cin >> jarakTempuh;
    cout << "Masukkan waktu tempuh dalam detik: ";
    cin >> waktuTempuh;
    cout << "Masukkan sudut arah robot (dalam derajat): ";
    cin >> sudut;

    Robot drive(jarakTempuh, waktuTempuh, sudut);
    drive.tampilkanHasil();
    drive.simpanKeFile();

    return 0;
}
