/*################################################################################################################################################
############					SAKARYA ÜNİVERSİTESİ - BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ - BİLGİSAYAR MÜHENDİSLİĞİ
############
############					PROGRAMLAMAYA GİRİŞ DERSİ - YAZ OKULU PROJE ÖDEVİ - ÇOKLU DOSYA YÖNETİMİ (İNŞAAT - AYLIK HAKKEDİŞ)
############
############					ÖĞRENCİ : B191210029  ŞEYMA GÖL  2.SINIF  (1.ÖĞRETİM)
############
##################################################################################################################################################*/


#include <iostream>
#include<fstream> //Dosyalama yapabilmek icin gerekli kutuphanedir.
#include<iomanip> //Setw() fonksiyonuyla menu yapabilmek icin eklenmistir.
#include <windows.h>
#include <stdio.h> //Projemize standart input output dosyalarini ekler.
#include <string>
using namespace std;

//Insaat malzemelerini tutmak icin degiskenleri tutan yapı :
struct UrunBilgi
{
	int UrunNo;
	string UrunAdi;
	string Birim;	 //kg,ton vb.
	int BirimFiyati;
	string Marka;
}urun; 


//Insaat malzemeleri icin metodlar :
bool UrunKontrol(int urunNo);	//Urunun halihazirda,urun dosyasinda olup olmadiginin kontrolunu saglar.
void UrunEkle();
void UrunSil(int urunNo);
void UrunAra(int urunNo);
void UrunRaporla();




//Projeler icin degiskenleri tutan yapı :
struct ProjeBilgi
{
	int ProjeNo;
	string ProjeAdi;
	string ProjeYurutucuFirma;
	string ProjeSorumlusu;
	string ProjeKontroloru;
}proje;



//Projeler icin metodlar :
bool ProjeKontrol(int projeNo);  //Projenin halihazirda,proje dosyasinda olup olmadiginin kontrolunu saglar.
void ProjeEkle();
void ProjeSil(int projeNo);      
void ProjeAra(int projeNo);
void ProjeRaporla();



//Aylik hakkedis degiskenlerini tutan yapi:
struct AylikHakkedis
{
	int ProjeNo;
	string HakkedisDonemi;
	string UrunAdi;
	int BirimFiyat;
	int ToplamTutar;
}hakkedis;




//Aylik hakkedis icin metodlar :
bool HakkedisUrunKontrol(string urunAdi);		//Hakkedis verilip verilmedigini kontrol eder.

bool HakkedisProjeKontrol(int projeNoo);		//Hakkedis verilip verilmedigini kontrol eder.

void KullanilanUrunSil();

void KullanilanUrunGuncelle();

void KullanilanUrunListele();

void KullanilanUrunAra(string urunAdi);

void ToplamHakkedisTutarHesapla();				//Tum projelerin toplam tutarini toplar.

void ProjeToplamTutarYazdir(int projeNoo);		//Secilen projenin toplam tutarini yazdirir.



//Menu icin degisken :
int secim1;
int secim2;


//Menu , ekrana secenekler icin cikarilacak listedir.
void Menu()
{
	//Urun.txt islemleri icin
	int urunNo;
	urunNo = urun.UrunNo;

	//Hakedis.txt islemleri icin
	string urunAdi;
	urunAdi = hakkedis.UrunAdi;

	//Proje.txt islemleri icin
	int projeNo;
	projeNo = proje.ProjeNo;

	//Hakedis.txt islemleri icin
	int projeNoo;
	projeNoo = hakkedis.ProjeNo;

	cout << "**********************************************************************************" << endl << endl;

	cout << " 1-) Urunler Dosyasi" << setw(15)
		<< " 2-) Projeler Dosyasi" << setw(15)
		<< " 3-) Hakkedis Dosyasi" << setw(15)
		<< " 4-) Cikis" << endl << endl;
	cout << "Seciminiz : ";
	cin >> secim1;
	cout << endl << endl;

	do
	{
		switch (secim1)
		{
			
		case 1:
			cout << "1-) Urun Ekle " << endl << "2-) Urun Sil" << endl << "3-) Urun Ara" << endl << "4-) Raporla" << endl<<"5-) Cikis"<<endl<<endl;
			cout << "Seciminiz  :" ;
			cin >> secim2;

			switch (secim2)
			{
				case 1:
					UrunEkle();
					break;

				case 2:
					UrunSil(urunNo);
					break;

				case 3:
					UrunAra(urunNo);
					break;

				case 4:
					UrunRaporla();
					break;


				case 5:
					break;

				default: cout << "Gecersiz numara girdiniz. \n";
					break;
			}
			break;
		
		case 2:
			cout << " 1-) Proje Ekle" << endl << " 2-) Proje Sil" << endl << " 3-) Proje Ara" << endl << " 4-) Raporla" << endl << " 5-)Cikis" << endl<<endl;
			cout << "Seciminiz  :" ;
			cin >> secim2;

			switch (secim2)
			{
				case 1:
						ProjeEkle();
						break;

				case 2:
						ProjeSil(projeNo);
						break;

				case 3:
						ProjeAra(projeNo);
						break;

				case 4:
						ProjeRaporla();
						break;

				case 5:														
					break;

				default: cout << "Gecersiz numara girdiniz. \n";
					break;
			}
			break;
			
		

		case 3:
			cout << " 1-) Kullanilan Urunleri Listele" << endl << " 2-) Kullanilan Urunlerde Ara" << endl << " 3-) Kullanilan Urunleri Sil" << endl << " 4-) Kullanilan Urunleri Guncelle" << endl<<" 5-) Toplam Hakkedis Tutari Hesapla "<<endl<<" 6-) Secilen Projenin Toplam Tutarini Yazdir "<<endl<<" 7-) Cikis "<<endl<<endl;
			cout << "Seciminiz  :" ;
			cin >> secim2;

			switch (secim2)
			{
				case 1:
					KullanilanUrunListele();
				    break;

				case 2:
					KullanilanUrunAra(urunAdi);
					break;

				case 3:
					KullanilanUrunSil();
					break;

				case 4:
					KullanilanUrunGuncelle();
					break;

				case 5:
					ToplamHakkedisTutarHesapla();
					break;

				case 6:
					ProjeToplamTutarYazdir(projeNoo);
					break;

				case 7:
					break;

				default: cout << "Gecersiz numara girdiniz. \n";
					break;

			}
			break;
			
		

		case 4:
			break;

		default: cout << "Gecersiz numara girdiniz. \n";
			break;
			
		}
		break;
		
	} while (secim1 != 0);
	cout << "**********************************************************************************";
}



bool UrunKontrol(int urunNo)
{
	//Urun no kayıtlı degilse 0 degeri dondurur.
	bool control = 0;
	ifstream dosyaOku;
	dosyaOku.open("Urun.txt");
	//Dosya sonuna dek islem gerceklesir.
	while (!dosyaOku.eof())
	{
		//Dosya okundu.
		dosyaOku >> urun.UrunNo >> urun.UrunAdi>> urun.Birim >> urun.BirimFiyati >> urun.Marka  ;
		//Istenen urun numarasiyla eslesen urun varsa 1 dondurdu.
		if (urun.UrunNo==urunNo)
		{
			control = 1;
			return true;
		}
	}
	return control;
}




void UrunEkle()
{
	int urunNo;
	ofstream dosyayaz;
	dosyayaz.open("Urun.txt",ios::app); //app modu dosya sonuna eklemeyi saglar.
	cout << "Kontrol yapilabilmesi icin eklemek istediginiz urun numarasini giriniz   :";
	cin >> urunNo;
	urun.UrunNo = urunNo;
	//Eklenmek istenen urun zaten varsa else icinden devam eder.
	if (UrunKontrol(urunNo)==1)
	{
		cout << "Bu urun halihazirda kayitlidir." << endl << endl;
	}
	else
	{
		
		cout << "Eklemek istediginiz urun numarasini giriniz   :";
		cin >> urun.UrunNo;

		cout << "Urun adi giriniz   :";
		cin >> urun.UrunAdi;

		cout << "Urunun degerlendirilecegi birimi giriniz  :";
		cin >> urun.Birim;

		cout << "Urunun birim basina fiyatini giriniz   :";
		cin >> urun.BirimFiyati;

		cout << "Urunun markasaini giriniz   :";
		cin >> urun.Marka;
		//Birer bosluk birakarak dosya sonuna yazdirma islemi.
		dosyayaz << urun.UrunNo <<"\t" << urun.UrunAdi << "\t" << urun.Birim << "\t" << urun.BirimFiyati << "\t" << urun.Marka<<endl;
		dosyayaz.close();
		cout << "Urun basariyla eklenmistir."<<endl<<endl;

	}

	
}



void UrunSil(int urunNo)
{

	cout << "Silmek istediginiz urunun numarasi   :";
	cin >> urunNo;
	cout << endl;

	//txt dosyasina sahip oldugumuzdan veri silme islemi icin ; gecici dosya("UrunSil.txt") ve var olan asil dosya("Urun.txt") olmak uzere iki dosya kullanilacak.

	ifstream dosyaOku;
	ofstream dosyaYaz;

	//Var olan dosyamiz okunmak uzere acildi.//in modu okumaya dosya basindan baslatti. 
	dosyaOku.open("Urun.txt", ios::in);	

	//Gecici dosya yazilmak uzere acildi//app modu sona ekleme isleviyle kullanilir.
	dosyaYaz.open("UrunSil.txt", ios::app);			

	bool flag = 0;
	
	//Bool fonksiyonumuzla,urunun varligi kontrol edildi.
	if (UrunKontrol(urunNo) == 1)
	{
		flag = 1;
		int deger = 0;
		
		while (!dosyaOku.eof())
		{
			dosyaOku >> urun.UrunNo >> urun.UrunAdi >> urun.Birim >> urun.BirimFiyati >> urun.Marka;

			
			if (deger != urun.UrunNo)
			{
				if (urun.UrunNo != urunNo)
				{
					dosyaYaz << urun.UrunNo << "\t" << urun.UrunAdi << "\t" << urun.Birim << "\t" << urun.BirimFiyati << "\t" << urun.Marka << endl;
					deger = urun.UrunNo;
				}

			}

		}

	}

	else
	{
		cout << "Girdiginiz numaraya sahip bir urun bulunamadi." << endl;
	}
	dosyaYaz.close();
	dosyaOku.close();

	//Urun listede varsa silinerek yeni dosyaya yazdirma islemi sonrasinda eski dosya silindi,yeni dosya ad degistirdi.
	if (flag == 1)
	{
		//Urun.txt dosyamiz kaldirildi.
		remove("Urun.txt");

		//("UrunSil.txt") dosyamizin adi ("Urun.txt") oldu.
		rename("UrunSil.txt", "Urun.txt");

		cout << "Kayit basariyla silinmistir." << endl;
	}
	else
	{
		//UrunSil.txt kaldirildi.
		remove("UrunSil.txt");
	}

}



void UrunAra(int urunNo)
{
	ifstream dosyaoku;
	
	cout << "Aramak istediginiz urunun numarasini giriniz   :";
	cin >> urunNo;
	cout << endl;
	
	//ios::in modu bastan okuma yapabilmek icin kullanildi.
	dosyaoku.open("Urun.txt",ios::in);	
	//Dosya acma islemi basariliysa if bloguna girildi.
	if (dosyaoku.is_open())
	{
			//Dosya sonuna dek islem gerceklesti.
			do
			{
				   //Okuma islemi gerceklestirildi.
				
					if (UrunKontrol(urunNo)==1)
					{
						urun.UrunNo = urunNo;
						
						//Konsolda yazdirildi.
						cout << "Urun numarasi   :" << urun.UrunNo << endl;

						cout << "Urun adi   :" << urun.UrunAdi << endl;

						cout << "Urun birimi   :" << urun.Birim << endl;

						cout << "Urunun birim fiyati   :" << urun.BirimFiyati << endl;

						cout << "Urunun markasi   :" << urun.Marka << endl << endl;
					}
					else
					{
						cout << "Urun bulunamadi." << endl;
					}
				
				//Tekrarli yazdirmayi onledi.
				break;	
			} while (!dosyaoku.eof());

	}
	else
	{
		cout <<"Dosya acilamadi..." << endl;
	}
	
	dosyaoku.close();
	
}



void UrunRaporla()
{
	ifstream dosyaoku;
	dosyaoku.open("Urun.txt", ios::in);

	cout << "Rapor............" << endl<<endl;

	if (dosyaoku.is_open())
	{
		do
		{
			//Dosya okuma...
			dosyaoku >> urun.UrunNo >> urun.UrunAdi >> urun.Birim >> urun.BirimFiyati >> urun.Marka;

			//Sonuncu urunu iki defa yazdirmamasi icin sonradan eklendi.
			if (dosyaoku.eof())
			{
				break;
			}
			
			cout << "Urun no   :" << urun.UrunNo << endl;

			
			cout << "Urun adi   :" << urun.UrunAdi << endl;

			
			cout << "Urun birimi   :" << urun.Birim << endl;

			
			cout << "Urun birim fiyati   :" << urun.BirimFiyati<<endl;

			
			cout << "Urunun markasi   :" << urun.Marka << endl<<endl<<endl;

			
			
		} while (!dosyaoku.eof());
		dosyaoku.close();
	}
    else
	{
		cout << "Dosya acilamadi...";
	}


}




bool ProjeKontrol(int projeNo)
{
	//Proje no kayıtlı degilse 0 degeri dondurur.
	bool control = 0;
	ifstream dosyaoku;
	dosyaoku.open("Proje.txt");

	//Dosya sonuna dek islem gerceklesir.
	while (!dosyaoku.eof())
	{
		dosyaoku >> proje.ProjeNo >> proje.ProjeAdi >> proje.ProjeYurutucuFirma >> proje.ProjeSorumlusu >> proje.ProjeKontroloru;
		//Proje no kayitli ise 1 dondurur.
		if (proje.ProjeNo == projeNo)
		{
			control = 1;
			return true;
		}
	}
	return control;
}






void ProjeEkle()
{
	int projeNo;
	ofstream dosyayaz;
	dosyayaz.open("Proje.txt", ios::app);	//app modu dosya sonuna eklemeyi saglar.
	cout << "Kontrol yapilabilmesi icin eklemek istediginiz proje numarasini giriniz   :";
	cin >> projeNo;
	proje.ProjeNo=projeNo;
	//Proje.txt icinde proje no ya ait proje varsa...
	if (ProjeKontrol(projeNo) == 1)
	{
		cout << "Bu proje halihazirda kayitlidir." << endl << endl;
	}
	else
	{

		cout << "Eklemek istediginiz proje numarasini giriniz   :";
		cin >> proje.ProjeNo;

		cout << "Proje adi giriniz   :";
		cin >> proje.ProjeAdi;

		cout << "Proje yurutucu firma adini giriniz  :";
		cin >> proje.ProjeYurutucuFirma;

		cout << "Proje sorumlusunun kodunu giriniz   :";
		cin >> proje.ProjeSorumlusu;

		cout << "Proje Kontrolorunun kodunu giriniz   :";
		cin >> proje.ProjeKontroloru;

		dosyayaz << proje.ProjeNo << "\t" << proje.ProjeAdi << "\t" << proje.ProjeYurutucuFirma << "\t" << proje.ProjeSorumlusu << "\t" << proje.ProjeKontroloru << endl;
		dosyayaz.close();
		cout << "Proje basariyla eklenmistir." << endl << endl;

	}
}




void ProjeSil(int projeNo)
{
	cout << "Silmek istediginiz projenin numarasini giriniz   :";
	cin >> projeNo;
	//Hakkedis verilmemisse silme islemi icin bloga girebilir.
	if (HakkedisProjeKontrol(projeNo)==0)
	{
		//txt dosyasina sahip oldugumuzdan veri silme islemi icin ; gecici dosya("ProjeSil.txt") ve var olan asil dosya("Proje.txt") olmak uzere iki dosya kullanilacak.

		ifstream dosyaOku;
		ofstream dosyaYaz;

		//Var olan dosyamiz okunmak uzere acildi.//in modu okumaya dosya basindan baslatti. 
		dosyaOku.open("Proje.txt", ios::in);	

		//Gecici dosya yazilmak uzere acildi//app modu sona ekleme isleviyle kullanilir.
		dosyaYaz.open("ProjeSil.txt", ios::app);			

		//Kontrol icin degiskene 0 atandi.
		bool flag = 0;
		
		//Bool fonksiyonumuzla,projenin varligi kontrol edildi.
		if (ProjeKontrol(projeNo) == 1)
		{
			flag = 1;
			int deger = 0;
			
			while (!dosyaOku.eof())
			{
				dosyaOku >> proje.ProjeNo >> proje.ProjeAdi >> proje.ProjeYurutucuFirma >> proje.ProjeSorumlusu >> proje.ProjeKontroloru;

				
				if (deger != proje.ProjeNo)
				{
					// Okunan txt dosyasinda silmek istedigimiz proje haricindeki tum projeler("ProjeSil.txt") icine yazdirildi.
					if (proje.ProjeNo != projeNo)
					{
						dosyaYaz << proje.ProjeNo << "\t" << proje.ProjeAdi << "\t" << proje.ProjeYurutucuFirma << "\t" << proje.ProjeSorumlusu << "\t" << proje.ProjeKontroloru << endl;
						deger = proje.ProjeNo;
					}

				}

			}

		}
		else
		{
			cout << "Girdiginiz numaraya sahip bir proje bulunamadi." << endl;
		}
		dosyaYaz.close();
		dosyaOku.close();

		//Proje listede varsa silinerek yeni dosyaya yazdirma islemi sonrasinda eski dosya silindi,yeni dosya ad degistirdi.
		if (flag == 1)
		{
			//Proje.txt dosyamiz kaldirildi.
			remove("Proje.txt");

			//("ProjeSil.txt") dosyamizin adi ("Proje.txt") oldu.
			rename("ProjeSil.txt", "Proje.txt");

			cout << "Kayit basariyla silinmistir." << endl;
		}
		else
		{
			//ProjeSil.txt kaldirildi.
			remove("ProjeSil.txt");
		}
	}
	else
	{
		cout << "Hakkedis almistir,silinemez."<<endl;
	}
	
}





void ProjeAra(int projeNo)
{
	ifstream dosyaOku;

	cout << "Aramak istediginiz projenin numarasini giriniz   :";
	cin >> projeNo;
	cout << endl;

	//ios::in modu bastan okuma yapabilmek icin kullanildi.
	dosyaOku.open("Proje.txt", ios::in);

	//Dosya acma islemi basariliysa if bloguna girildi.
	if (dosyaOku.is_open())
	{
		
			//Dosya sonuna dek islem gerceklesti.
			do
			{
				//Proje.txt dosyasinda projenin varligi bool fonksiyonla kontrol edildi.
				if (ProjeKontrol(projeNo) == 1)
				{
					proje.ProjeNo = projeNo;

					//Konsolda yazdirildi.
					cout << "Proje numarasi   :" << proje.ProjeNo << endl;

					cout << "Proje adi   :" << proje.ProjeAdi << endl;

					cout << "Proje yurutucu firmanin kodu   :" << proje.ProjeYurutucuFirma << endl;

					cout << "Proje sorumlusunun kodu   :" << proje.ProjeSorumlusu << endl;

					cout << "Proje kontrolorunun kodu   :" << proje.ProjeKontroloru << endl << endl;

				}
				else
				{
					cout << "Proje bulunamadi...";
				}
				//Tekrarli yazdirmayi onledi.
				break;
			} while (!dosyaOku.eof());


	}
	else
	{
		cout << "Dosya acilamadi..." << endl;
	}

	dosyaOku.close();

}





void ProjeRaporla()
{
	ifstream dosyaoku;
	dosyaoku.open("Proje.txt", ios::in);

	cout << "Rapor............" << endl << endl;

	if (dosyaoku.is_open())
	{
		do
		{
			//Dosya okuma...
			dosyaoku >> proje.ProjeNo>>proje.ProjeAdi>>proje.ProjeYurutucuFirma>>proje.ProjeSorumlusu>>proje.ProjeKontroloru;

			//Sonuncu projeyi iki defa yazdirmamasi icin sonradan eklendi.
			if (dosyaoku.eof())
			{
				break;
			}

			cout << "Proje no   :" << proje.ProjeNo << endl;


			cout << "Proje adi   :" << proje.ProjeAdi << endl;


			cout << "Proje yurutucu firma   :" << proje.ProjeYurutucuFirma << endl;


			cout << "Proje sorumlusu   :" << proje.ProjeSorumlusu << endl;


			cout << "Proje kontroloru   :" << proje.ProjeKontroloru << endl << endl;



		} while (!dosyaoku.eof());
		dosyaoku.close();
	}
	else
	{
		cout << "Dosya acilamadi...";
	}


}






bool HakkedisProjeKontrol(int projeNoo)
{
	//Proje no kayıtlı degilse 0 degeri dondurur.
	bool control = 0;
	ifstream dosyaoku;
	dosyaoku.open("Hakedis.txt");

	//Dosya sonuna dek islem gerceklesir.
	while (!dosyaoku.eof())
	{
		dosyaoku >> hakkedis.ProjeNo >> hakkedis.HakkedisDonemi >>hakkedis.UrunAdi >> hakkedis.BirimFiyat >> hakkedis.ToplamTutar;
		//Proje no kayitli ise 1 dondurur.
		if (hakkedis.ProjeNo == projeNoo)
		{
			control = 1;
			return true;
		}
	}
	return control;
}





bool HakkedisUrunKontrol(string urunAdi)
{
	//Urun adi kayıtlı degilse 0 degeri dondurur.
	bool control = 0;
	ifstream dosyaoku;
	dosyaoku.open("Hakedis.txt");

	//Dosya sonuna dek islem gerceklesir.
	while (!dosyaoku.eof())
	{
		dosyaoku >> hakkedis.ProjeNo >> hakkedis.HakkedisDonemi >> hakkedis.UrunAdi >>hakkedis.BirimFiyat >> hakkedis.ToplamTutar;
		//Urun adi kayitli ise 1 dondurur.
		if (hakkedis.UrunAdi==urunAdi)
		{
			control = 1;
			return true;
		}
	}
	return control;
}





void KullanilanUrunListele()
{
	ifstream dosyaOku;
	dosyaOku.open("Hakedis.txt", ios::in);

	//Dosya acilmissa if bloguna girilir.
	if (dosyaOku.is_open())
	{
		//Dosya sonuna dek islem gerceklesir.
		while (!dosyaOku.eof())
		{	
			//Okuma islemi yapıldı.
			dosyaOku >> hakkedis.ProjeNo >> hakkedis.HakkedisDonemi >> hakkedis.UrunAdi >> hakkedis.BirimFiyat >> hakkedis.ToplamTutar;
			//Sonuncu projeyi iki kez yazdirmamasi icin...
			if (dosyaOku.eof())
			{
				break;
			}
			cout << hakkedis.ProjeNo << " numarali projenizde kullanilan urun : " << hakkedis.UrunAdi << endl;
		}
		dosyaOku.close();
	}
	else
	{
		cout << "Dosya acilamadi";
	}
}





void KullanilanUrunAra(string urunAdi)
{
	cout << "Aratmak istediginiz urunun adini giriniz   : ";
	cin >> urunAdi;
	cout << endl;

	ifstream dosyaOku;

	dosyaOku.open("Hakedis.txt",ios::in);


	if (dosyaOku.is_open())
	{
		//Dosya sonuna dek islem gerceklesir.
		do
		{
				//Urun Hakedis.txt icinde bulunuyorsa if bloguna girilir.
				if (HakkedisUrunKontrol(urunAdi) == 1)
				{

					hakkedis.UrunAdi = urunAdi;

					//Konsolda yazdirildi.
					cout << "Adini girdiginiz urun  " << hakkedis.ProjeNo << " numarali projede bulunmaktadir . " << endl;

					cout << "Proje bilgileri    :" << endl << endl;

					cout << "Proje no   :" << hakkedis.ProjeNo << endl;

					cout << "Hakkedis donemi   :" << hakkedis.HakkedisDonemi << endl;

					cout << "Urun adi   :" << hakkedis.UrunAdi << endl;

					cout << "Birim fiyati   :" << hakkedis.BirimFiyat << endl;

					cout<< "Toplam tutar   :" << hakkedis.ToplamTutar << endl;

				}
				else
				{
					cout << "Urun bulunamadi." << endl;
				}
				
				break;
		} while (!dosyaOku.eof());
		
	}
	else
	{
		cout << "Dosya acilamadi..."<<endl;
	}
}





void KullanilanUrunSil()
{
	//Girilen urun adina degisken tanimladim.
	string g_Urun;
	system("cls"); //console ekranını temizledim.

	cout << "Silmek istediginiz urunun adini giriniz   :"; 
	cin >> g_Urun;

	ifstream DosyaOku("Hakedis.txt");
	//Kontrol degiskenine 0 atadim.
	int gcc = 0;

	while (!(DosyaOku.eof())) //DosyaOku da belirttiğim Hakedis.txt dosyasını sonuna kadar okuttum.
	{
		DosyaOku >> hakkedis.ProjeNo >> hakkedis.HakkedisDonemi >> hakkedis.UrunAdi >> hakkedis.BirimFiyat >> hakkedis.ToplamTutar;

		//Hakedis.txt icinde girilen urunle eslesen urun varsa
		if (hakkedis.UrunAdi == g_Urun)
		{
			//Urun bilgileri listelendi.
			cout << "=========== Urun Bilgileri ==========" << endl;
			cout << "Proje No: " << hakkedis.ProjeNo << endl;
			cout << "Hakedis Donemi: " << hakkedis.HakkedisDonemi << endl;
			cout << "Urun Adi : " << hakkedis.UrunAdi << endl;
			cout << "Birim Fiyati: " << hakkedis.BirimFiyat << endl;
			cout << "Toplam Tutar: " << hakkedis.ToplamTutar << "\n";
			DosyaOku.close();
			break;
		}
	}


	ifstream HakkedisDosyaOku("Hakedis.txt"); //dosyayı okuma amaçlı açtık.
	ofstream GeciciDosyaYaz("Template.tmp");	//gecici dosyaya yazdirma amacli actik.


	while (HakkedisDosyaOku >> hakkedis.ProjeNo >> hakkedis.HakkedisDonemi >> hakkedis.UrunAdi >> hakkedis.BirimFiyat >> hakkedis.ToplamTutar)
	{
		//Girilen urun haricindeki urunler aynen yazdirildi.
		if (g_Urun != hakkedis.UrunAdi)
			GeciciDosyaYaz << hakkedis.ProjeNo << " " << hakkedis.HakkedisDonemi << " " << hakkedis.UrunAdi << " " << hakkedis.BirimFiyat << " " << hakkedis.ToplamTutar << "\n";

		//Girilen urunun bulundugu satirdaki urun adi silindi
		if (g_Urun == hakkedis.UrunAdi)
		{
			GeciciDosyaYaz << hakkedis.ProjeNo << " " << hakkedis.HakkedisDonemi << " " << " " << " " << hakkedis.BirimFiyat << " " << hakkedis.ToplamTutar << "\n"; 
			gcc = 1;
		}
	}
	GeciciDosyaYaz.close();
	HakkedisDosyaOku.close();

	remove("Hakedis.txt"); //Hakedis.txt dosyasını sildim.
	rename("Template.tmp", "Hakedis.txt"); //Template.tmp dosyasını Hakedis.txt dosyasına kopyaladım.

	if (gcc == 0)
		cout << "Boyle Bir Urun Adi Bulunmamaktadir..." << endl;
	if (gcc == 1)
		cout << "Urun Adi Silindi..." << endl;
		
}





void KullanilanUrunGuncelle()
{
	//Girilen urunu tutan degisken tanimladim.
	string g_Urun;

	system("cls"); //console ekranını temizledim.

	cout << "Guncellemek istediginiz urunun adini giriniz   :";
	cin >> g_Urun;

	//Okuma amacli asil dosya acildi.
	ifstream DosyaOku("Hakedis.txt");
	//Kontrol degiskenine 0 atandi.
	int gcc = 0;

	
	while (!(DosyaOku.eof())) //DosyaOku da belirttiğim Hakedis.txt dosyasını sonuna kadar okuttum.
	{
		DosyaOku >> hakkedis.ProjeNo >> hakkedis.HakkedisDonemi >> hakkedis.UrunAdi >> hakkedis.BirimFiyat >> hakkedis.ToplamTutar;

		//dosyada urun adiyla eslesen urun varsa
		if (hakkedis.UrunAdi == g_Urun)
		{
			//Urun bilgileri ekrana yazdirildi
			cout << "=========== Urun Bilgileri ==========" << endl;
			cout << "Proje No: " << hakkedis.ProjeNo << endl;
			cout << "Hakedis Donemi: " << hakkedis.HakkedisDonemi << endl;
			cout << "Urun Adi : " << hakkedis.UrunAdi << endl;
			cout << "Birim Fiyati: " << hakkedis.BirimFiyat << endl;
			cout << "Toplam Tutar: " << hakkedis.ToplamTutar << "\n";
			DosyaOku.close();
			break;
		}
	}


	ifstream HakkedisDosyaOku("Hakedis.txt"); //dosyayı okuma amaçlı açtık.
	ofstream GeciciDosyaYaz("Template.tmp");

	while (HakkedisDosyaOku >> hakkedis.ProjeNo >> hakkedis.HakkedisDonemi >> hakkedis.UrunAdi >> hakkedis.BirimFiyat >> hakkedis.ToplamTutar)
	{
		//Girilen urun adiyla eslesmeyen satirlar aynen yazdirildi.
		if (g_Urun != hakkedis.UrunAdi)
			GeciciDosyaYaz << hakkedis.ProjeNo << " " << hakkedis.HakkedisDonemi << " " << hakkedis.UrunAdi << " " << hakkedis.BirimFiyat << " " << hakkedis.ToplamTutar << "\n";

		//Girilen urun adina sahip urun adi yeni urun adiyla degistirildi.
		if (g_Urun == hakkedis.UrunAdi)
		{
			cout << "\n Yeni Urun Bilgilerini Giriniz \n";
			cout << "\n Urun Adi :"; cin >> hakkedis.UrunAdi;

			GeciciDosyaYaz << hakkedis.ProjeNo << " " << hakkedis.HakkedisDonemi << " " << hakkedis.UrunAdi << " " << hakkedis.BirimFiyat << " " << hakkedis.ToplamTutar << "\n"; //girilen randevu bilgilerini dosyaya yazdırdım.
			gcc = 1;
		}
	}
	GeciciDosyaYaz.close();
	HakkedisDosyaOku.close();

	remove("Hakedis.txt"); //Hakedis.txt dosyasını sildim.
	rename("Template.tmp", "Hakedis.txt"); //Template.tmp dosyasını Hakedis.txt dosyasına kopyaladım.

	if (gcc == 0)
		cout << "Boyle Bir Urun Adi Bulunmamaktadir..." << endl;
	if (gcc == 1)
		cout << "Urun Adi Guncellendi..." << endl;
}






void ToplamHakkedisTutarHesapla()
{
	int toplam;
	toplam = 0;

	ifstream dosyaOku;

	

	dosyaOku.open("Hakedis.txt", ios::in);
	//Dosya acilmissa if bloguna girilir.
	if (dosyaOku.is_open())
	{
		//Dosya sonuna dek islem gerceklesir.
		while (!dosyaOku.eof())
		{
			
				for (int i = 0; i <= 4; i++)
				{
					//Okuma islemi yapıldı.
					dosyaOku >> hakkedis.ProjeNo >> hakkedis.HakkedisDonemi >> hakkedis.UrunAdi >> hakkedis.BirimFiyat >> hakkedis.ToplamTutar;
					toplam =toplam + hakkedis.ToplamTutar;
				}

				cout << "Toplam hakkedis tutari   : " << toplam;
				cout << endl;
			break;
		}
		dosyaOku.close();
	}
	else
	{
		cout << "Dosya acilamadi";
	}
}






void ProjeToplamTutarYazdir(int projeNoo)
{
	cout << "Hakkedis tutarini ogrenmek istediginiz proje numarasi   :";
	cin >> projeNoo;
	cout << endl;

	ifstream dosyaOku;

	//Dosyayi bastan okumak üzere acti.
	dosyaOku.open("Hakedis.txt", ios::in);

	//Dosya acilmissa if bloguna girilir.
	if (dosyaOku.is_open())
	{	
		
			//Dosya sonuna dek islem gerceklesti.
			do
			{	
				//Hakedis.txt dosyasinda proje teyidi yapildi.
				if (HakkedisProjeKontrol(projeNoo) == 1)
				{
					hakkedis.ProjeNo = projeNoo;

					//Konsolda yazdirildi.
					cout << hakkedis.ProjeNo << " numarali projenin toplam hakkedis tutari   : " << hakkedis.ToplamTutar << endl << endl;

				}
				else
				{
					cout << "Proje bulunamadi." << endl;
				}

				
				//Tekrarli yazdirmayi onledi.
				break;
			} while (!dosyaOku.eof());
		
		dosyaOku.close();
	}
	else
	{
		cout << "Dosya acilamadi"<<endl;
	}
}






int main()
{
	//Cikis yapilmadiğinda
	while (secim1 != 4)
	{
		//Ekrani temizler.
		system("cls");
		Menu();
		//Ekranin hemen kapanmasini onler.
		system("pause");
	}
	//Basa dondurur.
	return 0;
	
}
