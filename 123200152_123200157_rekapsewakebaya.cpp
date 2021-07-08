#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cstdlib>
#include <string.h>

using namespace std;
typedef struct{
	int ktp;
	string nama;
	char alamat[30];
	string jenis;
	int harga,lama,harga_total,jumbaju;
	}Datasewa;
	Datasewa Sewa[1000],rtl[1000];
FILE *Arsipsewa;
void data();
void input();
void output();
void searching();
void sequential_nama();
void sequential_ktp();
void sorting ();
void select_sortnama(Datasewa rtl[],int jumlah);
void select_sortktp(Datasewa rtl[],int jumlah);
void binary_ktp();
void binary_nama();
void bubble_ktp(Datasewa rtl[],int jumlah);
void bubble_nama(Datasewa rtl[],int jumlah);
int pilih,banyak,i,cari;
char jawab,namafile[30],cek,filesorting[50];
string s;
int jumlah;

int main()
{	do{
		cout<<"\n";
		cout<<"||\t\t REKAP SEWA KEBAYA \t\t||\n";
		cout<<"||-------------------- MENU --------------------||\n";
		cout<<"1. DATA CUSTOMER\n";
		cout<<"2. SEARCHING\n";
		cout<<"3. SORTING\n";
		cout<<"4. EXIT\n";
		cout<<"Silahkan Pilih Angka: ";
		cin>>pilih;
		if (pilih==1)
		{
			system("cls");
			data();
			}
		else if (pilih==2)
		{
			system("cls");
			searching();
		}
		else if (pilih==3)
		{
			system("cls");
			sorting();
		}
		else if (pilih==4)
		{
			system("cls");
			cout<<"Terima Kasih\n";
		}
		cout<<"\nKembali ke Menu (y/n)?:"; cin>>jawab;
		system("cls");
	} while (jawab=='Y'||jawab=='y');
	return (0);
}

void data(){
	int pilih;
	cout<< "MENU DATA CUSTOMER " << endl;
	cout<< "1. INPUT \n2. OUTPUT \n3. BACK TO MENU \n" ;
	cout<< "pilih : "; cin>> pilih;
	
	switch(pilih){
		case 1:
			system("cls");
			input();
			break;
		case 2:
			system("cls");
			output();
			break;
		case 3:
			system("cls");
			main();
			break;
		default :
			cout<< "Salah Input" <<endl <<endl;
			main();
	}
}

void input()
{ 
	cout<<"================== INPUT DATA ==================\n";
	cout<<"Silahkan Input Nama File: "; cin>>namafile;
	Arsipsewa = fopen(namafile,"r");
	if(Arsipsewa)
	{	cout << "File tersebut sudah dibuat\n";
        cout << "Tetap gunakan nama file tsb(y/n)? "; cin>>cek;
        system("cls");
		}
	Arsipsewa = fopen(namafile,"w");	
	cout<<"\n";
	cout<<"Masukkan Banyak Data Sewa: "; cin>>banyak;
	fwrite(&banyak,sizeof(banyak),1,Arsipsewa);
	for(int i=0;i<banyak;i++){
		cout<<"----------------------------------\n";
		cout<<"Data Sewa ke-"<<i+1<<endl;
		cout<<"Nama Pelanggan	: "; cin>>Sewa[i].nama;
		cout<<"Nomor KTP 	: "; cin>>Sewa[i].ktp;
		cout<<"Alamat		: "; cin.ignore(); cin.getline(Sewa[i].alamat,sizeof(Sewa[i].alamat));
		cout<<"Jenis Baju	: "; cin>>Sewa[i].jenis;
		cout<<"Jumlah Baju	: "; cin>>Sewa[i].jumbaju;
		cout<<"Lama Sewa	: "; cin>>Sewa[i].lama;
		cout<<"Harga		: "; cin>>Sewa[i].harga;
		Sewa[i].harga_total=Sewa[i].jumbaju*Sewa[i].lama*Sewa[i].harga;
		cout<<"----------------------------------\n";
		cout<<"\n";
		fwrite(&Sewa[i],sizeof(Sewa[i]),1,Arsipsewa);
		}	fclose(Arsipsewa);
			
	
}	

void output()
{	
	cout<<"================== OUTPUT DATA ==================\n";
	cout<<"Silahkan masukkan nama file yang akan ditampilkan datanya: "; cin>>namafile;
	Arsipsewa = fopen(namafile,"r");
	if ((Arsipsewa = fopen(namafile,"r"))==NULL){
		cout<<"File tidak dapat dibuka!\n";
		exit(1);
		}
	fread(&banyak,sizeof(banyak),1,Arsipsewa);
	if (banyak==0){
		cout<<"File kosong";
	}
	else if(!Arsipsewa){
		cout<<"File tidak ditemukan";
	}
	else{
		system("cls");
	cout<<"---------------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n No | \t Nama\t|      No KTP\t|  Alamat\t|  Jenis Baju\t|   Jumlah Baju\t| Lama Sewa\t| Harga Satuan\t| Harga Total\t|"<<endl;
	cout<<"---------------------------------------------------------------------------------------------------------------------------------";
	for (int i=0;i<banyak;i++){
		fread(&Sewa[i],sizeof(Sewa[i]),1,Arsipsewa);
		cout<<"\n "<<i+1<<"  |  \t"<<Sewa[i].nama<<"\t|\t"<<Sewa[i].ktp<<"\t|   "<<Sewa[i].alamat<<"\t|   "<<Sewa[i].jenis<<"\t|\t"<<Sewa[i].jumbaju<<"\t|\t"<<Sewa[i].lama<<"\t|\t"<<Sewa[i].harga<<"\t|\t"<<Sewa[i].harga_total<<"\t|"<<endl;
		cout<<"---------------------------------------------------------------------------------------------------------------------------------";
		} 
	 }fclose(Arsipsewa);

}

void searching()
{	char ulang;
	do{
		cout<<"================ MENU SEARCHING ================\n";
		cout<<"\n";
		cout<<"1.Sequential Searching\n";
        cout<<"2.Binary Search\n";
        cout<<"3.Kembali ke Menu Utama\n";
        cout<<"Silahkan Pilih Angka: "; cin>>pilih;
        if (pilih==1){
			int in;
			system("cls");
			cout<<"---------------------------------\n";
			cout<<" \tSequential Search\t\n";
			cout<<"---------------------------------\n";
			cout<<"1. Nama Customer\n";
			cout<<"2. No KTP Customer\n";
			cout<<"3. Kembali Ke Menu Utama\n"; 
			cout<<"Masukkan Pilihan Angka: "; cin>>in;
			if (in==1){
				sequential_nama();
			}
			else if (in==2){
				sequential_ktp();
			}
			cout<<"\nUlangi searching(y/n)?"; cin>>ulang;
			system("cls");
		}
		else if (pilih==2){
			 system("cls");
			 cout<<"Masukkan nama file : ";cin>>namafile;
             Arsipsewa=fopen(namafile,"r");
             fread(&banyak,sizeof(banyak),1,Arsipsewa);
			 jumlah=banyak;/*ngonversi banyak supaya ga ngubah data jadi jumlah sbg
			 size dr arraynya utk sort*/
             if(!Arsipsewa){
                 cout<<"File tidak ada di dalam direktori";
			}else if(banyak==0){
                 cout<<"File kosong";
			 }else{
				 int in;
					cout<<"---------------------------------\n";
					cout<<" \tBinary Search\t\n";
					cout<<"---------------------------------\n";
					cout<<"1. Nama Customer\n";
					cout<<"2. No KTP Customer\n";
					cout<<"3. Kembali Ke Menu Utama\n";
					cout<<"Silahkan Input Nomor: "; cin>>in;
					if (in==1){
					system("cls");
					fread(&Sewa,sizeof(Sewa),1,Arsipsewa);
					for(int j=0;j<banyak;j++){
							rtl[j]=Sewa[j];
                    }
                    fclose(Arsipsewa);
					system("cls");
					bubble_nama(rtl,jumlah);
					binary_nama();
					}
					else if (in==2){
					system("cls");
					fread(&Sewa,sizeof(Sewa),1,Arsipsewa);
					for(int j=0;j<banyak;j++){
							rtl[j]=Sewa[j];
                    }
                    fclose(Arsipsewa);
					system("cls");
					bubble_ktp(rtl,jumlah);
					binary_ktp();
				}
					cout<<"\nUlangi searching(y/n)?"; cin>>ulang;
					system("cls");
			}
		}
		else if (pilih==3){
			system("cls");
			main();
		}
	}while (ulang=='y'||ulang=='Y');

}

void sequential_nama()
{	
	system("cls");
	string cari;
	cout<<"\n";
	cout<<"Masukkan nama file : ";cin>>namafile;
    Arsipsewa=fopen(namafile,"r");
    fread(&banyak,sizeof(banyak),1,Arsipsewa);
    if(!Arsipsewa){
        cout<<"File tidak ada di direktori";
    }else if(banyak==0){
        cout<<"File kosong";
    }else{
        Datasewa isi[banyak];/*supaya tidak ngubah data yang ada di banyak*/
        fread(&Sewa[i],sizeof(Sewa[i]),1,Arsipsewa);
        for(int x=0; x<banyak; x++ ){
            isi[x]=Sewa[x];
        }
        fclose(Arsipsewa);
		cout<<"Input Nama yang dicari: "; cin>>cari;
        int found = 0;
        for(int i=0;i<banyak;i++){
            if(cari==isi[i].nama){
                cout<<"---------------------------------------------------------------------------------------------------------------------------------";
				cout<<"\n No | \t Nama\t|      No KTP\t|  Alamat\t|  Jenis Baju\t|   Jumlah Baju\t| Lama Sewa\t| Harga Satuan\t| Harga Total\t|"<<endl;
				cout<<"---------------------------------------------------------------------------------------------------------------------------------";
				cout<<"\n "<<i+1<<"  |  \t"<<Sewa[i].nama<<"\t|\t"<<Sewa[i].ktp<<"\t|   "<<Sewa[i].alamat<<"\t|   "<<Sewa[i].jenis<<"\t|\t"<<Sewa[i].jumbaju<<"\t|\t"<<Sewa[i].lama<<"\t|\t"<<Sewa[i].harga<<"\t|\t"<<Sewa[i].harga_total<<"\t|"<<endl;
				cout<<"---------------------------------------------------------------------------------------------------------------------------------";
                found++;
            }
        }
        if(found==0){
            cout << "data yang anda cari tidak ada" << endl;
        }
	}
}

void sequential_ktp()
{	
	system("cls");
	int cari;
	cout<<"\n";
	cout<<"Masukkan nama file : ";cin>>namafile;
    Arsipsewa=fopen(namafile,"r");
    fread(&banyak,sizeof(banyak),1,Arsipsewa);
    if(!Arsipsewa){
        cout<<"File tidak ada di direktori";
    }else if(banyak==0){
        cout<<"File kosong";
    }else{
        Datasewa isi[banyak];/*supaya ga ngubah data yang ada di banyak*/
        fread(&Sewa[i],sizeof(Sewa[i]),1,Arsipsewa);
        for(int x=0; x<banyak; x++ ){
            isi[x]=Sewa[x];
        }
        fclose(Arsipsewa);
		cout<<"Input No KTP yang dicari: "; cin>>cari;
        int found = 0;
        for(int i=0;i<banyak;i++){
            if(cari==isi[i].ktp){
                cout<<"---------------------------------------------------------------------------------------------------------------------------------";
				cout<<"\n No | \t Nama\t|      No KTP\t|  Alamat\t|  Jenis Baju\t|   Jumlah Baju\t| Lama Sewa\t| Harga Satuan\t| Harga Total\t|"<<endl;
				cout<<"---------------------------------------------------------------------------------------------------------------------------------";
				cout<<"\n "<<i+1<<"  |  \t"<<Sewa[i].nama<<"\t|\t"<<Sewa[i].ktp<<"\t|   "<<Sewa[i].alamat<<"\t|   "<<Sewa[i].jenis<<"\t|\t"<<Sewa[i].jumbaju<<"\t|\t"<<Sewa[i].lama<<"\t|\t"<<Sewa[i].harga<<"\t|\t"<<Sewa[i].harga_total<<"\t|"<<endl;
				cout<<"---------------------------------------------------------------------------------------------------------------------------------";
                found++;
            }
        }
        if(found==0){
            cout << "data yang anda cari tidak ada" << endl;
        }
	}
}

void binary_nama()
{	
	string find;
	system("cls");
    int mid, first=banyak, last=0, bebas[banyak]={0};
    cout<<"\nMasukkan Nama yang Anda cari : ";cin>>find;
    while (last<=first){
       mid=(first+last)/2;
        if(rtl[mid].nama==find){
            bebas[mid]=1;
            break;
        }else{
            if(rtl[mid].nama<find){
                last=mid+1;
            }else{
                first=mid-1;
            }
        }
    }

	 cout<<"---------------------------------------------------------------------------------------------------------------------------------";
	 cout<<"\n No | \t Nama\t|      No KTP\t|  Alamat\t|  Jenis Baju\t|   Jumlah Baju\t| Lama Sewa\t| Harga Satuan\t| Harga Total\t|"<<endl;
	 cout<<"---------------------------------------------------------------------------------------------------------------------------------";
	 for (int i=0;i<banyak;i++){
		if (bebas[i]==1){
		cout<<"\n "<<i+1<<"  |  \t"<<Sewa[i].nama<<"\t|\t"<<Sewa[i].ktp<<"\t|   "<<Sewa[i].alamat<<"\t|   "<<Sewa[i].jenis<<"\t|\t"<<Sewa[i].jumbaju<<"\t|\t"<<Sewa[i].lama<<"\t|\t"<<Sewa[i].harga<<"\t|\t"<<Sewa[i].harga_total<<"\t|"<<endl;
		cout<<"---------------------------------------------------------------------------------------------------------------------------------";
       }
	}
	fclose(Arsipsewa); 
}

void binary_ktp()
{	
	int target;
	system("cls");
    int mid, first=banyak, last=0, bebas[banyak]={0};
    cout<<"\nMasukkan KTP yang Anda cari : ";cin>>target;
    while (last<=first){
       mid=(first+last)/2;
        if(rtl[mid].ktp==target){
            bebas[mid]=1;
            break;
        }else{
            if(rtl[mid].ktp<target){
                last=mid+1;
            }else{
                first=mid-1;
            }
        }
    }

	 cout<<"---------------------------------------------------------------------------------------------------------------------------------";
	 cout<<"\n No | \t Nama\t|      No KTP\t|  Alamat\t|  Jenis Baju\t|   Jumlah Baju\t| Lama Sewa\t| Harga Satuan\t| Harga Total\t|"<<endl;
	 cout<<"---------------------------------------------------------------------------------------------------------------------------------";
	 for (int i=0;i<banyak;i++){
		if (bebas[i]==1){
		cout<<"\n "<<i+1<<"  |  \t"<<Sewa[i].nama<<"\t|\t"<<Sewa[i].ktp<<"\t|   "<<Sewa[i].alamat<<"\t|   "<<Sewa[i].jenis<<"\t|\t"<<Sewa[i].jumbaju<<"\t|\t"<<Sewa[i].lama<<"\t|\t"<<Sewa[i].harga<<"\t|\t"<<Sewa[i].harga_total<<"\t|"<<endl;
		cout<<"---------------------------------------------------------------------------------------------------------------------------------";
       }
	}
	fclose(Arsipsewa); 
}

void bubble_nama(Datasewa rtl[],int jumlah)
{
	Datasewa temp;/*nyimpen angka dlm for*/
    for(int i=0; i<banyak-1; i++){
        for(int j=0; j<banyak-i-1; j++){
            if (rtl[j].nama>rtl[j+1].nama)/*j angka array ke 0*/
            {
            temp=rtl[j];
            rtl[j]=rtl[j+1];
            rtl[j+1]=temp;
            /*misal 3 array ke 0 (j) terus j+1 itu 2 berati 
            tiketbbl isinya jadi 3; terus tikets[j] isinya jadi 2; terus tiket[j+1] jadi
            3*/
            }
        }
    }
        for(i=0; i<jumlah; i++){
            Sewa[i]=rtl[i];
        }
		fwrite(&Sewa,sizeof(Sewa),1,Arsipsewa);
		fclose(Arsipsewa);
       
}

void bubble_ktp(Datasewa rtl[],int jumlah)
{
	Datasewa temp;/*nyimpen angka dlm for*/
    for(int i=0; i<banyak-1; i++){
        for(int j=0; j<banyak-i-1; j++){
            if (rtl[j].ktp>rtl[j+1].ktp)/*j angka array ke 0*/
            {
            temp=rtl[j];
            rtl[j]=rtl[j+1];
            rtl[j+1]=temp;
            /*misal 3 array ke 0 (j) terus j+1 itu 2 berati 
            tiketbbl isinya jadi 3; terus tikets[j] isinya jadi 2; terus tiket[j+1] jadi
            3*/
            }
        }
    }
        for(i=0; i<jumlah; i++){
            Sewa[i]=rtl[i];
        }
		fwrite(&Sewa,sizeof(Sewa),1,Arsipsewa);
		fclose(Arsipsewa);
        
}

void sorting (){
	int in;
	char back;
	do{
	cout<<"---------------------------------\n";
	cout<<" Sorting Metode Selection Sort\t\n";
	cout<<"---------------------------------\n";
	cout<<"1. Nama Customer\n";
	cout<<"2. No KTP Customer\n";
	cout<<"3. Kembali Ke Menu Utama\n";
	cout<<"Silahkan Input Nomor: "; cin>>in;
	if (in==1){
		cout<<"Masukkan nama file : ";cin>>namafile;
             Arsipsewa=fopen(namafile,"r");
             fread(&banyak,sizeof(banyak),1,Arsipsewa);
			 jumlah=banyak;/*ngonversi banyak supaya ga ngubah data jadi jumlah sbg
			 size dr arraynya utk sort*/
             if(!Arsipsewa){
                 cout<<"File tidak ada di dalam direktori";
			}else if(banyak==0){
                 cout<<"File kosong";
			 }else{
					system("cls");
					fread(&Sewa,sizeof(Sewa),1,Arsipsewa);
					for(int j=0;j<banyak;j++){
							rtl[j]=Sewa[j];
                   }
			   }
                   fclose(Arsipsewa);
		system("cls");
		cout<<"\n";
		cout<<"\t\t Berdasarkan Nama Customer \t\t";
		cout<<"\n";
		select_sortnama(rtl,jumlah);
		}
	else if (in==2){
		cout<<"Masukkan nama file : ";cin>>namafile;
             Arsipsewa=fopen(namafile,"r");
             fread(&banyak,sizeof(banyak),1,Arsipsewa);
			 jumlah=banyak;/*ngonversi banyak supaya ga ngubah data jadi jumlah sbg
			 size dr arraynya utk sort*/
             if(!Arsipsewa){
                 cout<<"File tidak ada di dalam direktori";
			}else if(banyak==0){
                 cout<<"File kosong";
			 }else{
					system("cls");
					fread(&Sewa,sizeof(Sewa),1,Arsipsewa);
					for(int j=0;j<banyak;j++){
							rtl[j]=Sewa[j];
                   }
			   }
                   fclose(Arsipsewa);
		system("cls");
		cout<<"\n";
		cout<<"\t\t Berdasarkan KTP Customer \t\t";
		select_sortktp(rtl,jumlah);
		
		}
		else if(in==3){
			system("cls");
			main();
		}
		 cout<<"\nKembali ke menu sorting?(y/n): "; cin>>back;
		system("cls");
	}while(back=='Y' || back=='y');
}

void select_sortnama(Datasewa rtl[], int jumlah){
	int j;
	Datasewa temp;
	int flow;
	
	cout<<"\n";
	cout<<"Silahkan Input Nama File Hasil Sorting: "; cin>>filesorting;
    Arsipsewa=fopen(filesorting,"w");
    fwrite(&banyak,sizeof(banyak),1,Arsipsewa);
	for(flow=0; flow<banyak; flow++)/*flow itu representasi dr penggeseran*/{
		for(j=flow+1; j<banyak; j++)/*proses pencarian */{
			if(rtl[flow].nama>rtl[j].nama){
				/*jadi dibwh ini blok penukaran*/
				temp=rtl[flow];
				rtl[flow]=rtl[j];
				rtl[j]=temp;
				/*flow indeks 0 j indeks 1*/
			}
		}
	}
	
 	
	for(i=0; i<jumlah; i++){ 
 		Sewa[i]=rtl[i]; 
 	} 
 	
 	fclose(Arsipsewa);
 	fwrite(&Sewa,sizeof(Sewa),1,Arsipsewa);
 	
    Arsipsewa = fopen(filesorting,"r"); 
    fread(&jumlah, sizeof(jumlah),1,Arsipsewa); 
    fread(&Sewa, sizeof(Sewa),1,Arsipsewa);
    
	cout<<"\nHasil sorting :"<<endl;
	cout<<"---------------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n No | \t Nama\t|      No KTP\t|  Alamat\t|  Jenis Baju\t|   Jumlah Baju\t| Lama Sewa\t| Harga Satuan\t| Harga Total\t|"<<endl;
	cout<<"---------------------------------------------------------------------------------------------------------------------------------";
    for(j=0;j<jumlah;j++){
        rtl[j]=Sewa[j];
		cout<<"\n "<<j+1<<"  |  \t"<<Sewa[j].nama<<"\t|\t"<<Sewa[j].ktp<<"\t|   "<<Sewa[j].alamat<<"\t|   "<<Sewa[j].jenis<<"\t|\t"<<Sewa[j].jumbaju<<"\t|\t"<<Sewa[j].lama<<"\t|\t"<<Sewa[j].harga<<"\t|\t"<<Sewa[j].harga_total<<"\t|"<<endl;
		cout<<"---------------------------------------------------------------------------------------------------------------------------------";
    }
}

void select_sortktp (Datasewa rtl[], int jumlah){
	int j;
	Datasewa temp;
	int flow;
	cout<<"\n";
	cout<<"\n";
	cout<<"Silahkan Input Nama File Hasil Sorting: "; cin>>filesorting;
    Arsipsewa=fopen(filesorting,"w");
    fwrite(&banyak,sizeof(banyak),1,Arsipsewa);
	for(flow=0; flow<banyak; flow++)/*flow itu representasi dr penggeseran*/{
		for(j=flow+1; j<banyak; j++)/*proses pencarian */{
			if(rtl[flow].ktp > rtl[j].ktp){
				/*jadi dibwh ini blok penukaran*/
				temp=rtl[flow];
				rtl[flow]=rtl[j];
				rtl[j]=temp;
				/*flow indeks 0 j indeks 1*/
			}
		}
	}
	
	for(i=0; i<jumlah; i++){ 
 		Sewa[i]=rtl[i]; 
 	} 
 	
 	fclose(Arsipsewa);
 	fwrite(&Sewa,sizeof(Sewa),1,Arsipsewa);
    Arsipsewa = fopen(filesorting,"r"); 
    fread(&jumlah, sizeof(jumlah),1,Arsipsewa); 
    fread(&Sewa, sizeof(Sewa),1,Arsipsewa);
    
	cout<<"\nHasil sorting :"<<endl;
    cout<<"---------------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n No | \t Nama\t|      No KTP\t|  Alamat\t|  Jenis Baju\t|   Jumlah Baju\t| Lama Sewa\t| Harga Satuan\t| Harga Total\t|"<<endl;
	cout<<"---------------------------------------------------------------------------------------------------------------------------------";
    for(j=0;j<jumlah;j++){
        rtl[j]=Sewa[j];
		cout<<"\n "<<j+1<<"  |  \t"<<Sewa[j].nama<<"\t|\t"<<Sewa[j].ktp<<"\t|   "<<Sewa[j].alamat<<"\t|   "<<Sewa[j].jenis<<"\t|\t"<<Sewa[j].jumbaju<<"\t|\t"<<Sewa[j].lama<<"\t|\t"<<Sewa[j].harga<<"\t|\t"<<Sewa[j].harga_total<<"\t|"<<endl;
		cout<<"---------------------------------------------------------------------------------------------------------------------------------";
    }
   
}
