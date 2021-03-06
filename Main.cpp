/**
    KELAS     :
    KELOMPOK  :
    NAMA(NIM) : [nama][nim] , [nama][nim] , [nama][nim] , [nama][nim]
**/

#include <iostream>
#include "buku.h"
#include "tanggal.h"
//#include "aplikasi.h"

using namespace std;

buku daftar_buku[50];
int jumlah_buku = 0;

void main_menu();
void menu_create_buku();
void menu_pinjam();
void menu_kembali();
void menu_tampil();


int main()
{

    /**
    * fungsi main hanya memanggil main_menu
    * clean coding
    **/

    main_menu();


    return 0;
}


void main_menu()
{
    /**
    * fungsi untuk menampilkan main menu
    * dan menerima input pilihan menu dari user
    **/
    int pil;
    do
    {
        cout<<"Menu"<<endl;
        cout<<" "<<endl;
        cout<<"1. Masukkan Buku"<<endl;
        cout<<"2. Tampil Buku"<<endl;
        cout<<"3. Pinjam Buku"<<endl;
        cout<<"4. Kembalikan Buku"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<" "<<endl;
        cout<<"Masukkan pilihan anda: "<<endl;
        cin>>pil;
        switch(pil)
        {
        case 1:
            menu_create_buku();
            break;
        case 2:
            menu_tampil();
            break;
        case 3:
            menu_pinjam();
            break;
        case 4:
            menu_kembali();
            break;
        case 0:
            break;
        default:
            break;
        }
    }
    while (pil!=0);
}

void menu_create_buku()
{
    /**
    * fungsi meminta input judul dan pengarang dari user
    * fungsi membuat buku baru dan menyimpannya ke dalam array daftar_buku
    **/
    string judul,pengarang;
    cout << "\nMasukkan judul buku : "<<endl;
    cin>>judul;
    cout<<" "<<endl;
    cout << "Masukkan pengarang buku : "<<endl;
    cin>>pengarang;
    daftar_buku[jumlah_buku++] = create_buku(judul, pengarang);
    cout<<" "<<endl;
}

void menu_pinjam()
{
    /**
    * fungsi meminta input tanggal, bulan, tahun dari user
    * fungsi meminta input id buku berdasar urutan buku pada array daftar_buku
    * fungsi memanggil fungsi pinjam_buku
    **/
    int tgl,bln,thn;
    int id_buku;


    cout << "\nMasukkan Tanggal : "<<endl;
    cin>>tgl;
    cout << "\nMasukkan Bulan : "<<endl;
    cin>>bln;
    cout << "\nMasukkan Tahun : "<<endl;
    cin>>thn;
    cout << "\nMasukkan ID Buku : "<<endl;
    cin>>id_buku;
    pinjam_buku(daftar_buku[id_buku],tgl,bln,thn);
    cout<<" "<<endl;
}

void menu_kembali()
{
    /**
    * fungsi meminta input tanggal, bulan, tahun dari user
    * fungsi meminta input id buku berdasar urutan buku pada array daftar_buku
    * fungsi memanggil fungsi kembalikan_buku dan menyimpan selisih hari
    * fungsi menampilkan selisih hari pinjaman
    **/

    int tgl,bln,thn;
    int id_buku;
    int selisih;

    cout << "\nMasukkan Tanggal : "<<endl;
    cin>>tgl;
    cout << "\nMasukkan Bulan : "<<endl;
    cin>>bln;
    cout << "\nMasukkan Tahun : "<<endl;
    cin>>thn;
    cout << "\nMasukkan ID Buku : "<<endl;
    cin>>id_buku;
    selisih = kembalikan_buku(daftar_buku[id_buku],tgl,bln,thn);
    cout << "\n Durasi meminjam " << selisih << " Hari" << endl;
    cout<<" "<<endl;
}

void menu_tampil()
{
    /**
    * fungsi menampilkan daftar buku yang ada di dalam array daftar_buku
    **/
    buku b;
    for(int i=0; i<jumlah_buku; i++)
    {
        cout<<"\nID Buku : " << i << endl;
        b = daftar_buku[i];
        tampil_buku(b);
        cout<<endl;
    }
    cout<<" "<<endl;
}
