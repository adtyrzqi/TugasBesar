#include <iostream>
#include <string.h>
#include <algorithm>


using namespace std;



struct  keluhan{
        int jum_antri;
        char nama[80];
        char keluh[80];
        void print_info(){
            cout<<"\t\t "<<nama<<"    \t "<<keluh<<endl;
        };
        void print_inf(){
            cout<<nama<<"    \t "<<keluh<<endl;
        };
        keluhan *next;
};


keluhan *atas, *bawah;


void create_queue(){

      atas = new keluhan();
      atas->jum_antri = 0;

}

bool queueIsEMpety(){
    return (atas->jum_antri == 0);
    };

void enqueue(keluhan *data){

    if(queueIsEMpety()){
            atas -> next = bawah = data;

    }else{
        bawah->next = data;
        bawah = data;
    }

    atas->jum_antri++;
}


keluhan *update(int posisi){

        keluhan *tolong = atas;
        while(posisi--) tolong = tolong->next;
        return tolong;

};



keluhan * deque(){
        keluhan *hasil = atas;
        atas = atas->next;
        atas->jum_antri--;
        return hasil;
}


void read(){
        keluhan *tolong = atas ->next;
        int i = 0;
       while(tolong != NULL){
         cout<< ++i << ". ";tolong->print_info();
        tolong = tolong->next;
       }
}



void  pengurutan(){


    //pengurutan
    int jumlahData = atas->jum_antri;
    keluhan *data[jumlahData];
    keluhan *tolong = atas;
    for(int i = 0; i<jumlahData; i++ ){
        data[i] = tolong->next;
        tolong = tolong->next;
    }




    //bubble

    for(int i  = 0 ; i< jumlahData; i++){
        for(int j = 0 ; j < jumlahData -1 ; j++){

            if(strcmp(data[j]->nama,data[j+1]->nama)> 0 )
                swap(data[j],data[j+1]);
        }
    }


    //cetak


    for(int i = 0; i<jumlahData; i++ ){
        cout<< i +1 <<". ";data[i]->print_info();
    }





}

void cari(char target[30]){

	//cari data
    keluhan *tolong = atas;
    bool found;
    while((tolong= tolong->next) != NULL)
        if(strcmp(target,tolong->nama)==0){
                    found = true;
                    break;
        }


    if(found)
        tolong->print_inf();
    else
        cout<<target<<" tidak ada dalam antrian"<<endl;





}


void masukan(){
		//input
        int num;
        keluhan *tmp = new keluhan();
        cout<<"Nama Pasien : ";cin>>tmp->nama;
        cout<<"Jenis Keluhan : ";cin>>tmp->keluh;
        enqueue(tmp);

}



void update(){
	//edit data
    int num;
    cout<<"Masukan Nomor Antrian : ";cin>>num;
    keluhan *tolong = atas;
    if(num < atas->jum_antri || num > atas->jum_antri){
                cout<<"Nomor antrian salah \n"<<endl;
    }
    else{
    while(num--)
        tolong = tolong->next;

    cout<<"Data Antrian : "<<endl;
    tolong->print_info();
    cout<<"Masukan Ulang Nama : ";cin>>tolong->nama;
    cout<<"Masukan Ulang Keluhan : ";cin>>tolong->keluh;
    }
}



int main(){
    create_queue();
    int menu;
    char yn = 'y';
    cout<<"\t\t===================================================\n";
    cout<<"\t\t=======PROGRAM ANTRIAN KONSULTASI PSIKOLOGI========\n";
	cout<<"\t\t==================MENU KONSULTASI==================\n";
    cout<<"\t\t===================================================\n";
    do{
    cout<<"\tPILIH: "<<endl;
    cout<<"\t1. Masukan Nama Pasien/Jenis Keluhan "<<endl;
    cout<<"\t2. Layani Pasien Ke-1 "<<endl;
    cout<<"\t3. Lihat Antrian "<<endl;
    cout<<"\t4. Cari Pasien [NAMA] "<<endl;
    cout<<"\t5. Urutkan [NAMA]"<<endl;
    cout<<"\t6. Edit Data Pasien [NOMOR] "<<endl;
    cout<<"\t7. Hapus Data Pasien"<<endl;
    cout<<"\tMasukan pilihan : ";cin>>menu;
    cout<<endl;

    switch(menu){
    case 1  :
        masukan();
        cout<<"Kembali Ke Menu ? <Y/N>";cin>>yn;
        cout<<endl;
    break;
    case 2 :
        cout<<"Pasien Sukses di Layani "<<endl;
        deque()->print_info();
        cout<<"Kembali Ke Menu ? <Y/N>";cin>>yn;
    	cout<<endl;
	break;
    case 3:
    	cout<<"|NO URUT|\t |NAMA PASIEN|\t |KELUHAN| "<<endl<<endl;
        if(!queueIsEMpety()) read(); else cout<<"Antrian Kosong "<<endl;
        cout<<"Kembali Ke Menu ? <Y/N>";cin>>yn;
        cout<<endl;
    break;
    case 4:
        char nama[30];
        cout<<"Masukan Nama Yang dicari :";cin>>nama;
    	cout<<"|NAMA PASIEN|\t |KELUHAN| "<<endl<<endl;
        cari(nama);
        cout<<"Kembali Ke Menu ? <Y/N>";cin>>yn;
        cout<<endl;
    break;
    case 5:
    	cout<<"|NO URUT|\t |NAMA PASIEN|\t |KELUHAN| "<<endl<<endl;
        pengurutan();
        cout<<"Kembali Ke Menu ? <Y/N>";cin>>yn;
        cout<<endl;
    break;
    case 6:
        int nomor;
        cout<<"Masukan Nomor Antrian : ";cin>>nomor;
        update(nomor)->print_info();
        if(nomor > 0 && nomor <=atas->jum_antri){
            cout<<"Masukan Ulang Nama : ";cin>>update(nomor)->nama;
            cout<<"Masukan Ulang Keluhan : ";cin>>update(nomor)->keluh;
            cout<<"Data Pasien Diperbaharui !"<<endl;
        }else{
            cout<<"Nomor Antrian Salah";
        }
        cout<<"Kembali Ke Menu ? <Y/N>";cin>>yn;
        cout<<endl;
    break;
    case 7:
        create_queue();
        cout<<"SUKSES HAPUS DATA SEMUA\n";
        cout<<"Kembali Ke Menu Utama ? <y/n>";cin>>yn;
    break;
    case 8:
        update();
        cout<<"Kembali Ke Menu Utama ? <y/n>";cin>>yn;
        cout<<endl;
    break;

    }
    }while(yn == 'y');



}
