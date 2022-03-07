/**********************************************************************************************************************************************
***********************************************************************************************************************************************
***********************************************************************************************************************************************
*****************************************  ÖÐRENCÝ ADI: Mustafa Melih TÜFEKCÝOÐLU                    ******************************************
*****************************************  ÖÐRENCÝ NUMARASI: B191210004                              ******************************************
*****************************************  DERS GRUBU : B                                            ******************************************
***********************************************************************************************************************************************
***********************************************************************************************************************************************
***********************************************************************************************************************************************/
#include<iostream>
#include<Windows.h>
#include<time.h>

using namespace std;
struct Sahne                                         //Sahne yapýsý..
{
    int yukseklik;
	int genislik;
	char sinirSembolu;
}sahne1;                                            //Sahne yapýsýnýn nesnesi..
struct Lsekil                                     //L þekli yapýsý..
{
	int Lboyut;
	char Lsekil;
	int Lkoordinat;
	int y;
}Lsekil1;                                          //L þekil yapýsýnýn nesnesi..

void gotoxy(int, int);                             //Fonksiyonlarýn prototipleri..
void sahneOlustur();                               //
void sahneCiz();                                   //
void LsekilOlustur();                              //
void Lciz();                                       //
void AssagiIndýr();                                //

int main()                                        
{
	sahneOlustur();
	LsekilOlustur();
	while (1)
	{
		system("cls");
		sahneCiz();
		Lciz();
		AssagiIndýr();
		if(sahne1.yukseklik<=(2*Lsekil1.Lboyut)+(Lsekil1.y))                              //L þeklinin sahnenin dýþýna çýkmamasýný saðlar..
			LsekilOlustur();
		
		Sleep(100);
	}

	cin.get();

}
void gotoxy(int x, int y)                                                                 //Kursörün istediðimiz yere kaymasýný saðlayan fonksiyon.. 
{
	COORD koordinat;
	koordinat.X = x;
	koordinat.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), koordinat);
}                      
void sahneOlustur()                                                                      //Sahne oluþturmaya yarayan fonksiyon..
{
	int randGenislik;
    srand(time(NULL));                                                                   // Random atama yapma özelliðini aktifleþtimek için kullandýk..
	int y[] = { 30,40,50 };
    randGenislik= rand() % 3;
	sahne1.genislik = y[randGenislik];                                                  //Random atadýðýmýz geniþliði yapýya aktarma kodu..
	char randKarakter;
	char x[] = { '*','#','$','+','@' };
    randKarakter =rand() % 5;
	sahne1.sinirSembolu = x[randKarakter];                                              //Random atadýðýmýz sembolü yapýya aktarma kodu..
	sahne1.yukseklik = rand() % 11 + 20;                                                //Random olarak yükseklik atama kodu..
}
void sahneCiz()                                                                         //Sahne  çizme fonksiyonu..
{
     for (int i = 0; i < sahne1.genislik; i++)                                          //Sahnenin üst kýsmýný yazan kod ..
	 {
		 cout << sahne1.sinirSembolu;	
	 }
	 for (int i = 0; i <sahne1. yukseklik; i++)                                         //Sahnenin sað yan tarafýný yazan kod..
	 {
		 gotoxy(sahne1.genislik - 1, i);
		 cout << sahne1.sinirSembolu;	 
	 }
	 for (int i = 0; i < sahne1.genislik; i++)                                         //Sahnenin alt kýsmýný yazan kod..
	 {
		 gotoxy(sahne1.genislik - i - 1,sahne1. yukseklik - 1);
		 cout << sahne1.sinirSembolu;	 
	 }
	 for (int i = 0; i <sahne1. yukseklik; i++)                                        //Sahnenin sol yan tarafýný yazan kod..
	 {
		 gotoxy(0, sahne1.yukseklik - 1 - i);
		 cout << sahne1.sinirSembolu;
	 }		
}
void LsekilOlustur()                                                                //L þekli oluþturmaya yarayan fonksiyon..
{
	int RastLBoyut;
	srand(time(0));
	int x[] = { 2,3,4,5,6,7 };
	RastLBoyut = rand() % 6;
	Lsekil1.Lboyut = x[RastLBoyut];                                                 //L nin boyutunu rastgele bulup bunu yapýya aktaran kod..
	char RastLKarakter;
	char y[] = { '*','#','$','+','@' };
	RastLKarakter = rand() % 5;
	Lsekil1.Lsekil = y[RastLKarakter];                                              //L nin sýnýr sembolünü atayan kod.. 
	int RastLkonum;
	int z[] = { 5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25 };
	RastLkonum = rand() % 21;
	Lsekil1.Lkoordinat = z[RastLkonum];                                             //L nin koordinatýný rastgele atayan kod..
	Lsekil1.y = 3;
}
void Lciz()                                                                         //L çizmeye yarayan kod..
{
	int i, j, k, m, n, p, o;
	for (i = 0; i < Lsekil1.Lboyut; i++)                                            //L þekliniin  sol üst geniþliðini çiz..
	{
		gotoxy(Lsekil1.Lkoordinat + i, Lsekil1.y);
		cout << Lsekil1.Lsekil;
	}
	for (j = 0; j < Lsekil1.Lboyut; j++)                                           //L þeklinin orta yüksekliðini çizer..
	{
		gotoxy(Lsekil1.Lkoordinat + i, Lsekil1.y+ j);
		cout << Lsekil1.Lsekil;
	}
	for (k = 0; k < Lsekil1.Lboyut; k++)                                           //L þeklinin sað üst geniþliðini çizer..
	{
		gotoxy(Lsekil1.Lkoordinat + i + k, Lsekil1.y + j);
		cout << Lsekil1.Lsekil;
	}
	for (m = 0; m < Lsekil1.Lboyut; m++)                                          //L þeklinin sol yüksekliðini çizer..
	{
		gotoxy(Lsekil1.Lkoordinat + i + k, Lsekil1.y + j + m);
		cout << Lsekil1.Lsekil;
	}
	for (n = 0; n < Lsekil1.Lboyut; n++)                                        //L þeklinin tabanýný çizer..
	{
		gotoxy(Lsekil1.Lkoordinat + n + n, Lsekil1.y + j + m - 1);
		cout << Lsekil1.Lsekil;
	}
	for (p = 0; p < Lsekil1.Lboyut; p++)                                         // Bu iki döngüngü l þeklinin sað yüksekliðini çizer..
	{
		gotoxy(Lsekil1.Lkoordinat, Lsekil1.y + p + 1);
		cout << Lsekil1.Lsekil;
	}
	for (o = 0; o < Lsekil1.Lboyut; o++)
	{
		gotoxy(Lsekil1.Lkoordinat, Lsekil1.y + p + o);
		cout << Lsekil1.Lsekil;
	}
}
void AssagiIndýr()                                                         //L þeklini aþaðý kaydýran fonksiyon..
{
	Lsekil1.y = Lsekil1.y + 1;
}