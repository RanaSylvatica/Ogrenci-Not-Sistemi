/****************************************************************************
		**							   SAKARYA �N�VERS�TES�
		**			         B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
		**						  B�LG�SAYAR M�HEND�SL��� B�L�M�
		**							PROGRAMLAMAYA G�R��� DERS�
		**
		**				�DEV NUMARASI		:1
		**				��RENC� ADI			:Elif Ranag�l Akyol
		**				��RENC� NUMARASI    :b231210092
		**				DERS GRUBU			:B
		****************************************************************************/
#include <iostream>


using namespace std;  
	struct ogrenciBilgisi {

		string isim;
		string soyIsim;
		double vizeNotu;
		double odevNotu1, odevNotu2;
		double kisaSinavNotu1, kisaSinavNotu2;
		double finalNotu;
		string harfNotu;
		double y�lIciNotu;
		double gecmeNotu;

	};

	int main() {


		setlocale(LC_ALL, "Turkish"); //t�rk�e karakterleri kullanmam�z� sa�lar.
		srand(time(0)); // program her ba�lat�ld���nda random say�n�n farkl� ��kmas�n� sa�lar.

		

		ogrenciBilgisi ogrenci;
		ogrenciBilgisi bilgiler[200];
		int mevcut;
		

		do {
			  
			cout << "L�tfen s�n�f mevcudunu giriniz (L�tfen 200 veya 200'den k���k ve 0 dan farkl� bir de�er giriniz. ): "<<endl;
			cin >> mevcut;

		} while (mevcut == 0 and mevcut > 200);		//program�n hata vermemesi i�in 0 veya 200 den b�y�k say� girilemez

		
		int kisaSinavAgirlik, vizeAgirlik, odevAgirlik, y�lIciAgirlik;
		


		
			cout << "L�tfen y�li�indeki her bir notun a��rl���n� giriniz."<<endl << "K�sa S�nav:";
			cin >> kisaSinavAgirlik;
			cout << endl;
			cout << "Vize:";
			cin >> vizeAgirlik;
			cout << endl;
			
			odevAgirlik = 100 - (kisaSinavAgirlik + vizeAgirlik);			//iki notun a��rl��� girildikten sonra 100den geriye kalan olan a��rl�k �deve aittir.


	
		


		
		do{
			cout << "Y�li�i a��rl���(100'den k���k giriniz): ";
			cin >> y�lIciAgirlik;

		} while (y�lIciAgirlik > 100);


		string isimListesi[] = { "C�neyt ", "Elif ", "Rana ", "U�ur ", "Ozan ", "Derya ", "Fazl� ", "Beyza ", "Mert ", "Eren ", "Y�ld�z ", "Mete ", "Dila ", "Behzat ", "Damla " };
		string soyIsimListesi[] = { "Bay�lm��", "Akyol", "�engel", "Kaya", "�i�ek", "Akku�", "Karakurt", "Do�an", "Ba�t�rk", "�evik", "Ba�gan", "K�ksal", "Bayram", "Ba�er", "�enyer" };

		cout << endl;
		for (int i = 0; i < mevcut; i++)
		{
			bilgiler[i].isim = isimListesi[rand() % 15];
			bilgiler[i].soyIsim = soyIsimListesi[rand() % 15];					//bilgiler dizisinin her bir indeksine isim ve soyisim at�yoruz


			if (i < 10)
			{
				//cout << "kkkkkk" << endl;
				bilgiler[i].vizeNotu = rand() % 21 + 80  ;            //her bir not i�in belli aral�klarda random say�lar atan�r.
				bilgiler[i].odevNotu1 = rand() % 21 + 80 ;
				bilgiler[i].kisaSinavNotu1 = rand() % 21+ 80 ;
				bilgiler[i].odevNotu2 = rand() % 21 + 80;
				bilgiler[i].kisaSinavNotu2 = rand() % 21 + 80;
				bilgiler[i].finalNotu = rand() %  21+80 ;
			}
			else if (i >= mevcut /5 and i < mevcut/2 + mevcut / 5)
			{
				//cout << "kkkkkk" << endl;

				bilgiler[i].vizeNotu = rand() % 50;
				bilgiler[i].odevNotu1 = rand() % 50;
				bilgiler[i].kisaSinavNotu1= rand() % 50;
				bilgiler[i].odevNotu2 = rand() % 50;
				bilgiler[i].kisaSinavNotu2 = rand() % 50;
				bilgiler[i].finalNotu = rand() % 50;
			}
			else
			{
				//cout << "kkkkkk" << endl;

				bilgiler[i].vizeNotu = rand() % 31 +50 ;
				bilgiler[i].odevNotu1 = rand() %31 + 50 ;
				bilgiler[i].kisaSinavNotu1 = rand() %31 + 50 ;
				bilgiler[i].odevNotu2 = rand() % 31 + 50;
				bilgiler[i].kisaSinavNotu2 = rand() % 31 + 50;
				bilgiler[i].finalNotu = rand() % 31+ 50 ;
			}
		}
		int finalAgirlik=0;
		finalAgirlik = 100 - y�lIciAgirlik; //100den y�li�i a��rl���n� ��kararak final a��rl���n� elde ediyoruz

		
		for (int i = 0; i < mevcut; i++)
		{
			double y�lIciSonuc;
			y�lIciSonuc= (bilgiler[i].vizeNotu * vizeAgirlik  + bilgiler[i].kisaSinavNotu1 * kisaSinavAgirlik /2 + bilgiler[i].kisaSinavNotu2 * kisaSinavAgirlik /2 + bilgiler[i].odevNotu1 * odevAgirlik * 0.02 + bilgiler[i].odevNotu2 * odevAgirlik /2) / 100;
			bilgiler[i].y�lIciNotu = y�lIciSonuc;
			// yukar�da iki tane olan notlar� "2"ye b�ld�k ��nk� iki nota verilen a��rl��� yar� yar�ya payla�t�r�yoruz.
			double gecmeSonuc;
			gecmeSonuc = (bilgiler[i].y�lIciNotu * y�lIciAgirlik  + bilgiler[i].finalNotu * finalAgirlik)*0.01;
			bilgiler[i].gecmeNotu = gecmeSonuc;

			
			//burada t�m notlar� a��rl�klar�na ba�l� hesaplayarak toplad�k ve ge�me notunu bulduk. yine ge�me notuyla da final notunu a��rl�klar�na ba�l� olarak toplad�k ve ge�me notunu elde ettik

			if (bilgiler[i].gecmeNotu >= 90)
			{
				bilgiler[i].harfNotu = "AA";
			}

			else if (bilgiler[i].gecmeNotu < 90 and bilgiler[i].gecmeNotu >= 85)
			{
				bilgiler[i].harfNotu = "BA";
			}

			else if (bilgiler[i].gecmeNotu < 85 and bilgiler[i].gecmeNotu >= 80)
			{
				bilgiler[i].harfNotu = "BB";
			}

			else if (bilgiler[i].gecmeNotu < 80 and bilgiler[i].gecmeNotu >= 75)						//burada her bir nota kar��lk gelen harf notunu e�le�tirdik.
			{
				bilgiler[i].harfNotu = "CB";
			}

			else if (bilgiler[i].gecmeNotu < 75 and bilgiler[i].gecmeNotu >= 70)
			{
				bilgiler[i].harfNotu = "CC";
			}

			else if (bilgiler[i].gecmeNotu < 70 and bilgiler[i].gecmeNotu >= 58)
			{
				bilgiler[i].harfNotu = "DC";
			}

			else if (bilgiler[i].gecmeNotu < 58 and bilgiler[i].gecmeNotu >= 50)
			{
				bilgiler[i].harfNotu = "DD";
			}

			else
			{
				bilgiler[i].harfNotu = "FF";
			}
		}
			double aaSayisi = 0, bbSayisi = 0, baSayisi = 0, cbSayisi = 0, ccSayisi = 0, dcSayisi = 0, ddSayisi = 0, ffSayisi = 0;

			for (int i = 0; i < mevcut; i++)
			{
				if (bilgiler[i].harfNotu == "AA")
					aaSayisi++;

				else if (bilgiler[i].harfNotu == "BB")
					bbSayisi++;

				else if (bilgiler[i].harfNotu == "BA")
					baSayisi++;

				else if (bilgiler[i].harfNotu == "CB")
					cbSayisi++;

				else if (bilgiler[i].harfNotu == "CC")
					ccSayisi++;

				else if (bilgiler[i].harfNotu == "DC")
					dcSayisi++;

				else if (bilgiler[i].harfNotu == "DD")				//burada harf notlar�n� say�lar�n� ko�ula ba�l� artt�rarak bulduk.
					ddSayisi++;

				else
					ffSayisi++;
			}

			double aaYuzdesi=0, baYuzdesi=0, bbYuzdesi=0, cbYuzdesi=0, ccYuzdesi=0, dcYuzdesi=0, ddYuzdesi=0, ffYuzdesi=0;

			aaYuzdesi = aaSayisi / mevcut * 100;
			baYuzdesi = baSayisi / mevcut * 100;
			bbYuzdesi = bbSayisi / mevcut * 100;
			cbYuzdesi = cbSayisi / mevcut * 100;
			ccYuzdesi = ccSayisi / mevcut * 100;
			dcYuzdesi = dcSayisi / mevcut * 100;
			ddYuzdesi = ddSayisi / mevcut * 100;
			ffYuzdesi = ffSayisi / mevcut * 100;				//burada harf notlar�n� mevcuda b�lerek y�zdelerini blduk

			cout << "**************SINIF B�LG�LER�****************" << endl;

			for (int i = 0; i < mevcut; i++)
			{	
				cout << bilgiler[i].isim << bilgiler[i].soyIsim << " :" << bilgiler[i].harfNotu<< bilgiler[i].gecmeNotu <<endl; //art�k her bir indekse atanan bilgileri ekrana yaz�yoruz
				cout << endl;
			}
			double ortalama;
			double toplam;
			for (int i = 0; i < mevcut; i++)
			{
				bilgiler[i].gecmeNotu += bilgiler[i].gecmeNotu;					//burada t�m notlar�n toplam�n� buluyoruz
				toplam = bilgiler[i].gecmeNotu;

			}
			ortalama = toplam / mevcut*100;											//buldu�umuz toplam� mevcuda b�lerek ortalamay� buluyoruz
			cout << "S�n�f Ortalamas�: " << ortalama << endl;
			cout << "AA not say�s� ve y�zdesi: " << aaSayisi << ", " << aaYuzdesi << endl;
			cout << "BA not say�s� ve y�zdesi: " << baSayisi << ", " << baYuzdesi << endl;
			cout << "BB not say�s� ve y�zdesi: " << bbSayisi << ", " << bbYuzdesi << endl;
			cout << "CB not say�s� ve y�zdesi: " << cbSayisi << ", " << cbYuzdesi << endl;
			cout << "CC not say�s� ve y�zdesi: " << ccSayisi << ", " << ccYuzdesi << endl;
			cout << "DC not say�s� ve y�zdesi: " << dcSayisi << ", " << dcYuzdesi << endl;
			cout << "DD not say�s� ve y�zdesi: " << ddSayisi << ", " << ddYuzdesi << endl;
			cout << "FF not say�s� ve y�zdesi: " << ffSayisi << ", " << ffYuzdesi << endl;


			double enBuyukNot=0;
			double enKucukNot=100;


			for (int i = 0; i < mevcut; i++)
			{
				if (bilgiler[i].gecmeNotu > enBuyukNot)	
				{	
					enBuyukNot = bilgiler[i].gecmeNotu;				//burada en b�y�k notu bulmak i�in dizideki t�m notlar� kar��la�t�r�yoruz
				}
			
				if (bilgiler[i].gecmeNotu < enKucukNot)
				{ 
					enKucukNot = bilgiler[i].gecmeNotu;              //ayn�n� en k���k say� i�in yap�caz
				}
			}
			cout << "En B�y�k Not: " << enBuyukNot << endl;
			cout << "En K���k Not: " << enKucukNot;
			
			return 0;
	}
	