/**********************************************************************************************************************************************
***********************************************************************************************************************************************
***********************************************************************************************************************************************
*****************************************  ��RENC� ADI: Mustafa Melih T�FEKC�O�LU                    ******************************************
*****************************************  ��RENC� NUMARASI: B191210004                              ******************************************
*****************************************  DERS GRUBU : B                                            ******************************************
***********************************************************************************************************************************************
***********************************************************************************************************************************************
***********************************************************************************************************************************************/
#include<iostream>
#include<Windows.h>
#include<time.h>

using namespace std;
struct Sahne                                         //Sahne yap�s�..
{
    int yukseklik;
	int genislik;
	char sinirSembolu;
}sahne1;                                            //Sahne yap�s�n�n nesnesi..
struct Lsekil                                     //L �ekli yap�s�..
{
	int Lboyut;
	char Lsekil;
	int Lkoordinat;
	int y;
}Lsekil1;                                          //L �ekil yap�s�n�n nesnesi..

void gotoxy(int, int);                             //Fonksiyonlar�n prototipleri..
void sahneOlustur();                               //
void sahneCiz();                                   //
void LsekilOlustur();                              //
void Lciz();                                       //
void AssagiInd�r();                                //

int main()                                        
{
	sahneOlustur();
	LsekilOlustur();
	while (1)
	{
		system("cls");
		sahneCiz();
		Lciz();
		AssagiInd�r();
		if(sahne1.yukseklik<=(2*Lsekil1.Lboyut)+(Lsekil1.y))                              //L �eklinin sahnenin d���na ��kmamas�n� sa�lar..
			LsekilOlustur();
		
		Sleep(100);
	}

	cin.get();

}
void gotoxy(int x, int y)                                                                 //Kurs�r�n istedi�imiz yere kaymas�n� sa�layan fonksiyon.. 
{
	COORD koordinat;
	koordinat.X = x;
	koordinat.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), koordinat);
}                      
void sahneOlustur()                                                                      //Sahne olu�turmaya yarayan fonksiyon..
{
	int randGenislik;
    srand(time(NULL));                                                                   // Random atama yapma �zelli�ini aktifle�timek i�in kulland�k..
	int y[] = { 30,40,50 };
    randGenislik= rand() % 3;
	sahne1.genislik = y[randGenislik];                                                  //Random atad���m�z geni�li�i yap�ya aktarma kodu..
	char randKarakter;
	char x[] = { '*','#','$','+','@' };
    randKarakter =rand() % 5;
	sahne1.sinirSembolu = x[randKarakter];                                              //Random atad���m�z sembol� yap�ya aktarma kodu..
	sahne1.yukseklik = rand() % 11 + 20;                                                //Random olarak y�kseklik atama kodu..
}
void sahneCiz()                                                                         //Sahne  �izme fonksiyonu..
{
     for (int i = 0; i < sahne1.genislik; i++)                                          //Sahnenin �st k�sm�n� yazan kod ..
	 {
		 cout << sahne1.sinirSembolu;	
	 }
	 for (int i = 0; i <sahne1. yukseklik; i++)                                         //Sahnenin sa� yan taraf�n� yazan kod..
	 {
		 gotoxy(sahne1.genislik - 1, i);
		 cout << sahne1.sinirSembolu;	 
	 }
	 for (int i = 0; i < sahne1.genislik; i++)                                         //Sahnenin alt k�sm�n� yazan kod..
	 {
		 gotoxy(sahne1.genislik - i - 1,sahne1. yukseklik - 1);
		 cout << sahne1.sinirSembolu;	 
	 }
	 for (int i = 0; i <sahne1. yukseklik; i++)                                        //Sahnenin sol yan taraf�n� yazan kod..
	 {
		 gotoxy(0, sahne1.yukseklik - 1 - i);
		 cout << sahne1.sinirSembolu;
	 }		
}
void LsekilOlustur()                                                                //L �ekli olu�turmaya yarayan fonksiyon..
{
	int RastLBoyut;
	srand(time(0));
	int x[] = { 2,3,4,5,6,7 };
	RastLBoyut = rand() % 6;
	Lsekil1.Lboyut = x[RastLBoyut];                                                 //L nin boyutunu rastgele bulup bunu yap�ya aktaran kod..
	char RastLKarakter;
	char y[] = { '*','#','$','+','@' };
	RastLKarakter = rand() % 5;
	Lsekil1.Lsekil = y[RastLKarakter];                                              //L nin s�n�r sembol�n� atayan kod.. 
	int RastLkonum;
	int z[] = { 5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25 };
	RastLkonum = rand() % 21;
	Lsekil1.Lkoordinat = z[RastLkonum];                                             //L nin koordinat�n� rastgele atayan kod..
	Lsekil1.y = 3;
}
void Lciz()                                                                         //L �izmeye yarayan kod..
{
	int i, j, k, m, n, p, o;
	for (i = 0; i < Lsekil1.Lboyut; i++)                                            //L �ekliniin  sol �st geni�li�ini �iz..
	{
		gotoxy(Lsekil1.Lkoordinat + i, Lsekil1.y);
		cout << Lsekil1.Lsekil;
	}
	for (j = 0; j < Lsekil1.Lboyut; j++)                                           //L �eklinin orta y�ksekli�ini �izer..
	{
		gotoxy(Lsekil1.Lkoordinat + i, Lsekil1.y+ j);
		cout << Lsekil1.Lsekil;
	}
	for (k = 0; k < Lsekil1.Lboyut; k++)                                           //L �eklinin sa� �st geni�li�ini �izer..
	{
		gotoxy(Lsekil1.Lkoordinat + i + k, Lsekil1.y + j);
		cout << Lsekil1.Lsekil;
	}
	for (m = 0; m < Lsekil1.Lboyut; m++)                                          //L �eklinin sol y�ksekli�ini �izer..
	{
		gotoxy(Lsekil1.Lkoordinat + i + k, Lsekil1.y + j + m);
		cout << Lsekil1.Lsekil;
	}
	for (n = 0; n < Lsekil1.Lboyut; n++)                                        //L �eklinin taban�n� �izer..
	{
		gotoxy(Lsekil1.Lkoordinat + n + n, Lsekil1.y + j + m - 1);
		cout << Lsekil1.Lsekil;
	}
	for (p = 0; p < Lsekil1.Lboyut; p++)                                         // Bu iki d�ng�ng� l �eklinin sa� y�ksekli�ini �izer..
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
void AssagiInd�r()                                                         //L �eklini a�a�� kayd�ran fonksiyon..
{
	Lsekil1.y = Lsekil1.y + 1;
}