/****************************************************************************
		**							   SAKARYA ÜNÝVERSÝTESÝ
		**			         BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
		**						  BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
		**							PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
		**
		**				ÖDEV NUMARASI		:1
		**				ÖÐRENCÝ ADI			:Elif Ranagül Akyol
		**				ÖÐRENCÝ NUMARASI    :b231210092
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
		double yýlIciNotu;
		double gecmeNotu;

	};

	int main() {


		setlocale(LC_ALL, "Turkish"); //türkçe karakterleri kullanmamýzý saðlar.
		srand(time(0)); // program her baþlatýldýðýnda random sayýnýn farklý çýkmasýný saðlar.

		

		ogrenciBilgisi ogrenci;
		ogrenciBilgisi bilgiler[200];
		int mevcut;
		

		do {
			  
			cout << "Lütfen sýnýf mevcudunu giriniz (Lütfen 200 veya 200'den küçük ve 0 dan farklý bir deðer giriniz. ): "<<endl;
			cin >> mevcut;

		} while (mevcut == 0 and mevcut > 200);		//programýn hata vermemesi için 0 veya 200 den büyük sayý girilemez

		
		int kisaSinavAgirlik, vizeAgirlik, odevAgirlik, yýlIciAgirlik;
		


		
			cout << "Lütfen yýliçindeki her bir notun aðýrlýðýný giriniz."<<endl << "Kýsa Sýnav:";
			cin >> kisaSinavAgirlik;
			cout << endl;
			cout << "Vize:";
			cin >> vizeAgirlik;
			cout << endl;
			
			odevAgirlik = 100 - (kisaSinavAgirlik + vizeAgirlik);			//iki notun aðýrlýðý girildikten sonra 100den geriye kalan olan aðýrlýk ödeve aittir.


	
		


		
		do{
			cout << "Yýliçi aðýrlýðý(100'den küçük giriniz): ";
			cin >> yýlIciAgirlik;

		} while (yýlIciAgirlik > 100);


		string isimListesi[] = { "Cüneyt ", "Elif ", "Rana ", "Uður ", "Ozan ", "Derya ", "Fazlý ", "Beyza ", "Mert ", "Eren ", "Yýldýz ", "Mete ", "Dila ", "Behzat ", "Damla " };
		string soyIsimListesi[] = { "Bayýlmýþ", "Akyol", "Þengel", "Kaya", "Çiçek", "Akkuþ", "Karakurt", "Doðan", "Baþtürk", "Çevik", "Baþgan", "Köksal", "Bayram", "Baþer", "Þenyer" };

		cout << endl;
		for (int i = 0; i < mevcut; i++)
		{
			bilgiler[i].isim = isimListesi[rand() % 15];
			bilgiler[i].soyIsim = soyIsimListesi[rand() % 15];					//bilgiler dizisinin her bir indeksine isim ve soyisim atýyoruz


			if (i < 10)
			{
				//cout << "kkkkkk" << endl;
				bilgiler[i].vizeNotu = rand() % 21 + 80  ;            //her bir not için belli aralýklarda random sayýlar atanýr.
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
		finalAgirlik = 100 - yýlIciAgirlik; //100den yýliçi aðýrlýðýný çýkararak final aðýrlýðýný elde ediyoruz

		
		for (int i = 0; i < mevcut; i++)
		{
			double yýlIciSonuc;
			yýlIciSonuc= (bilgiler[i].vizeNotu * vizeAgirlik  + bilgiler[i].kisaSinavNotu1 * kisaSinavAgirlik /2 + bilgiler[i].kisaSinavNotu2 * kisaSinavAgirlik /2 + bilgiler[i].odevNotu1 * odevAgirlik * 0.02 + bilgiler[i].odevNotu2 * odevAgirlik /2) / 100;
			bilgiler[i].yýlIciNotu = yýlIciSonuc;
			// yukarýda iki tane olan notlarý "2"ye böldük çünkü iki nota verilen aðýrlýðý yarý yarýya paylaþtýrýyoruz.
			double gecmeSonuc;
			gecmeSonuc = (bilgiler[i].yýlIciNotu * yýlIciAgirlik  + bilgiler[i].finalNotu * finalAgirlik)*0.01;
			bilgiler[i].gecmeNotu = gecmeSonuc;

			
			//burada tüm notlarý aðýrlýklarýna baðlý hesaplayarak topladýk ve geçme notunu bulduk. yine geçme notuyla da final notunu aðýrlýklarýna baðlý olarak topladýk ve geçme notunu elde ettik

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

			else if (bilgiler[i].gecmeNotu < 80 and bilgiler[i].gecmeNotu >= 75)						//burada her bir nota karþýlk gelen harf notunu eþleþtirdik.
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

				else if (bilgiler[i].harfNotu == "DD")				//burada harf notlarýný sayýlarýný koþula baðlý arttýrarak bulduk.
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
			ffYuzdesi = ffSayisi / mevcut * 100;				//burada harf notlarýný mevcuda bölerek yüzdelerini blduk

			cout << "**************SINIF BÝLGÝLERÝ****************" << endl;

			for (int i = 0; i < mevcut; i++)
			{	
				cout << bilgiler[i].isim << bilgiler[i].soyIsim << " :" << bilgiler[i].harfNotu<< bilgiler[i].gecmeNotu <<endl; //artýk her bir indekse atanan bilgileri ekrana yazýyoruz
				cout << endl;
			}
			double ortalama;
			double toplam;
			for (int i = 0; i < mevcut; i++)
			{
				bilgiler[i].gecmeNotu += bilgiler[i].gecmeNotu;					//burada tüm notlarýn toplamýný buluyoruz
				toplam = bilgiler[i].gecmeNotu;

			}
			ortalama = toplam / mevcut*100;											//bulduðumuz toplamý mevcuda bölerek ortalamayý buluyoruz
			cout << "Sýnýf Ortalamasý: " << ortalama << endl;
			cout << "AA not sayýsý ve yüzdesi: " << aaSayisi << ", " << aaYuzdesi << endl;
			cout << "BA not sayýsý ve yüzdesi: " << baSayisi << ", " << baYuzdesi << endl;
			cout << "BB not sayýsý ve yüzdesi: " << bbSayisi << ", " << bbYuzdesi << endl;
			cout << "CB not sayýsý ve yüzdesi: " << cbSayisi << ", " << cbYuzdesi << endl;
			cout << "CC not sayýsý ve yüzdesi: " << ccSayisi << ", " << ccYuzdesi << endl;
			cout << "DC not sayýsý ve yüzdesi: " << dcSayisi << ", " << dcYuzdesi << endl;
			cout << "DD not sayýsý ve yüzdesi: " << ddSayisi << ", " << ddYuzdesi << endl;
			cout << "FF not sayýsý ve yüzdesi: " << ffSayisi << ", " << ffYuzdesi << endl;


			double enBuyukNot=0;
			double enKucukNot=100;


			for (int i = 0; i < mevcut; i++)
			{
				if (bilgiler[i].gecmeNotu > enBuyukNot)	
				{	
					enBuyukNot = bilgiler[i].gecmeNotu;				//burada en büyük notu bulmak için dizideki tüm notlarý karþýlaþtýrýyoruz
				}
			
				if (bilgiler[i].gecmeNotu < enKucukNot)
				{ 
					enKucukNot = bilgiler[i].gecmeNotu;              //aynýný en küçük sayý için yapýcaz
				}
			}
			cout << "En Büyük Not: " << enBuyukNot << endl;
			cout << "En Küçük Not: " << enKucukNot;
			
			return 0;
	}
	