//program demonstracyjny, kompilowany w Dev C++,
//na pocz¹tku programu za³¹czamy biblioteki i pliki naglowkowe ze zdefiniowanymi funkcjami
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include<algorithm>
#include <math.h>
#include <sstream>

#include <windows.h>
#include <iostream>
#include <cstdlib>

//Pliki z rozszerzeniem .h zawieraja tylko prototypy funkcji, kody znajduja
//sie w plikach o tych samych nazwach lecz z rozszerzeniem .cpp
#include "matrix.h"

//deklarujemy u¿ywanie przestrzeni nazw std, zawieraj¹cej wiele przydatnych komend,
//je¿eli nie zdeklarowalibyœmy przestrzeni nazw std, przed komendami tej przestrzeni nale¿a³oby u¿yæ zapisu std::
// np. std::cout<<"tekst";         
using namespace std;

//w funkcji main mamy nasz g³ówny program,
int main (void) {
cout<<"Program pomocniczy do cw1\n";

//definiujemy nazwe pliku, musi istnieæ w katalogu programu
string nazwap="paragon-system.txt";

//korzystamy z funkcji umieszczonych w pliku matrix.h
// w celu znalezienia rozmiaru wczytywanego pliku,
//plik powinien byc w formacie
//6 2 5 6 1
//5 8 9 2 0
int wym2=num_rows_file(nazwap.c_str());
int wym1=num_cols_file(nazwap.c_str());

//teraz deklarujemy dynamicznie tablice do, której wczytamy nasz plik,
int rows = wym2+1;
std::string **G;
G = new std::string*[rows];
while(rows--) G[rows] = new std::string[wym1+1];

////wczytujemy tablice w postaci string, czyli jej elementy traktujemy jako stringi(ci¹gi znaków)
//wym2 to liczba wierszy
//wym1 to liczba kolumn
//G nasza tablica stringów
//nazwap.c_str() podajemy nazwe wczytywanego pliku w odpowiednim formacie do funkcji.
cout<<"\n\nNacisnij ENTER aby wczytac tablice o nazwie "<< nazwap;
getchar();
wczytywanie(wym2,wym1,G,nazwap.c_str());
//wypisujemy wczytan¹ tablicê na ekran
cout<<"\nWypisujemy na ekran wczytana tablice\n\n";
for(int i=1;i<wym2+1;i++){
  for(int j=1;j<wym1+1;j++){
    cout<<" "<<G[i][j];
  }
  cout<<"\n";
} 


//******************************************************
//MIEJSCE NA ROZWIAZANIE 
int sizeF1=1;
string F1[wym1*wym2];
F1[0]=G[1][1];
bool flaga;
HANDLE hOut;
hOut = GetStdHandle( STD_OUTPUT_HANDLE );
int licznik;
int n=1;
int s=1;
int nk=1;
for (int i=1;i<=wym2;i++)
	for (int j=1;j<=wym1;j++){
		flaga=false;
		for (int k=i+1;k<=wym2;k++)
			for (int l=0;l<=wym1;l++){
				if (G[i][j]==G[k][l]){
					flaga=true;
				}
			}
			if (flaga){
				for (int k=0;k<sizeF1;k++)
				{
					if(F1[k]==G[i][j])
					flaga=false;
				}
			}
			if(flaga){
				F1[sizeF1]=G[i][j];
				sizeF1++;
			}
	}
cout<<"\n\nF1={";
for (int k=0;k<sizeF1;k++)
{
	cout<<F1[k]<<", ";
}
cout<<"}\n\n";
for(int i=sizeF1;i>1;i--)
		n*=i; 
for(int i=sizeF1-2;i>1;i--)
		nk*=i; 
s=n/(2*nk);
string C2[s][2];
string C[10][s][10];
int a=0;
for (int k=0;k<sizeF1;k++)
{
	for (int j=k+1;j<sizeF1;j++)
	{
		C[0][a][0]=F1[k];
		C[0][a][1]=F1[j];
		a++;
	}
}
cout<<"\n\nC2={";
for (int i=0;i<a;i++)
 	cout<<"{"<<C[0][i][0]<<", "<<	C[0][i][1]<<"},\n";
cout<<"}\n\n";
int krok=1;
int b=0;
string temps[6];
bool flagakom;
bool fc[6];
int n1=3;
int liczrowne;
int iletakischsamych;
int tx=0;
int ts=0;
int ty;
int ta[6];
string tem[6];
bool fl1,fl2;
int licz;
string F[6][s][6];
a=0;
for (int k=0;k<s;k++){
	licz=0;
 	for(int i=1;i<wym2+1;i++){
 		fl1=false;
 		fl2=false;
 		for(int j=1;j<wym1+1;j++){
    		if(G[i][j]==C[0][k][0])
    			fl1=true;
     		if(G[i][j]==C[0][k][1])
    			fl2=true;
  		}
 		if(fl1&&fl2){
  			licz++;
  		}
 	}
  	if (licz>=2){
  		F[0][a][0]=C[0][k][0];
    	F[0][a][1]=C[0][k][1];
    	sort(F[0][a],F[0][a]+2);
    	a++;
	} 
}
cout<<"\n\nF2={";
ta[0]=a;
for (int i=0;i<a;i++)
 	cout<<"{"<<F[0][i][0]<<", "<<	F[0][i][1]<<"},\n";
cout<<"}\n\n";
do{
 	for (int i=0;i<a;i++){
 		for(int j=0;j<n1-1;j++)
		{
			for(int k=i+1;k<a;k++)
			{
				for(int l=0;l<n1-1;l++)
				{	
					if(F[krok-1][i][j]==F[krok-1][k][l])
					{	
						liczrowne=0;
						for(int x=0;x<n1-1;x++)
						{
							for(int y=0;y<n1-1;y++)
							{
								if(F[krok-1][i][x]==F[krok-1][k][y])	
								{	
									temps[liczrowne]=F[krok-1][i][x];
									liczrowne++;	
								}
							}
						}
						if(liczrowne==n1-2){
							for(int x=0;x<n1-1;x++)
							{
								flagakom=true;
								for(int y=0;y<liczrowne;y++)
								{	
									if(F[krok-1][i][x]==temps[y])	
									{	
										flagakom=false;
									}
								}
								if(flagakom)
								{
										temps[liczrowne]=F[krok-1][i][x];
								}
								flagakom=true;
								for(int y=0;y<liczrowne;y++)
								{	
									if(F[krok-1][k][x]==temps[y])	
									{
										flagakom=false;
									}
								}
								if(flagakom)
								{			
									temps[liczrowne+1]=F[krok-1][k][x];
								}
							}
							sort(temps, temps+n1);
							flagakom=true;
							for(int x=0;x<b;x++){
								iletakischsamych=0;
								for(int y=0;y<n1;y++){
									if(C[krok][x][y]==temps[y])
									{
							 			iletakischsamych++;
									}
								}
								if(iletakischsamych==n1)
									flagakom=false;
							}
							if(flagakom){	
								ts=0;
								for(int y=0;y<n1;y++)
								{ 
									tx=0;
									for(int x=0;x<n1;x++)
									{
										if(y!=x){
											tem[tx]=temps[x];
											tx++;
										}
									}
									sort(tem,tem+tx);
									flagakom=false;
									for(int x=0; x<a;x++){
										ty=0;
										for(int z=0;z<n1-1;z++){
											if(F[krok-1][x][z]==tem[z])
											{
												ty++;	
											}
										}
										if(ty==2)
											flagakom=true;
									}
									if(flagakom)
									{
										ts++;	
									}
								}
								if(ts==n1){
									for(int y=0;y<n1;y++){
										C[krok][b][y]=temps[y];
									}
									b++;
								}
							}
						}

					}
				}
			}
		}
 	}
  	cout<<"\n\nC"<<krok+2<<"={";
 	for (int i=0;i<b;i++){
 		cout<<"{";
 		for(int j=0;j<n1;j++){
 			cout<<C[krok][i][j]<<",";
		}
  		cout<<"}\n";
  	}
 	cout<<"}\n\n";
 	a=0;
	for(int x=0;x<b;x++){
 		tx=0;
  		for(int i=1;i<wym2+1;i++){
 			ts=0;
  			for(int j=1;j<wym1+1;j++){
  				for (int y=0;y<n1;y++){
  					if(C[krok][x][y]==G[i][j])
  						ts++;	
				}
			}
			if(ts==n1)
				tx++;
		}
		if(tx>=2){
			for(int y=0;y<n1;y++){
				F[krok][a][y]=C[krok][x][y];
			}
			a++;
		}
	}
 	cout<<"\n\nF"<<krok+2<<"={";
 	ta[krok]=a;
 	for (int i=0;i<a;i++){
 		cout<<"{";
 		for(int j=0;j<n1;j++){
 			cout<<F[krok][i][j]<<",";
		}
  		cout<<"}\n";
	}
 	cout<<"}\n\n";
 	b=0;
 	krok++;
 	n1++;
}while(a>1);
string nast;
string poprz[6];
bool nas;
int lp;
int lpn;
double progjakosci=(double)(1)/3;
string jakosc[s*s];
int ileja=0;
double wsp;
double ufn;
string swsp;
string sw;
string sufn;
ostringstream owsp;
ostringstream oufn;
ostringstream ow;

for(int i=0;i<krok;i++)
{
 	cout<<endl<<endl<<"F"<<i+2<<" "<<endl;
 	for(int j=0;j<ta[i];j++)
	{
	 	for(int k=0;k<i+2;k++)
	 	{
		 	tx=0;
	 		for(int l=0;l<i+2;l++)
	 		{
				if(k!=l){			
					poprz[tx]=F[i][j][l];
					tx++;
				}
				else
					nast=F[i][j][l];
			}
			lp=0;
			lpn=0;
			for (int m=0;m<wym2+1;m++){
				tx=0;	
				nas=false;	
				for (int n=0;n<wym1+1;n++){	
					for(int l=0;l<i+1;l++)
	 				{
			 			if(G[m][n]==poprz[l])
			 				tx++;
					}
					if(G[m][n]==nast)	
						nas=true;
				}
				if(tx==i+1)
				{
					lp++;
					if(nas)
						lpn++;
				}
			}
			for(int l=0;l<i;l++)
	 		{
			 	cout<<poprz[l]<<"^";
			}
			wsp=(double)(lpn)/wym2;
			ufn=(double)(lpn)/lp;
			cout<<poprz[i]<<"=>"<<nast<<" wsp = "<<wsp<<"; ufn = "<<ufn<<"; wsp * ufn = "<<wsp*ufn<<endl;
			for(int dd=1;dd<5;dd++){
			
			if(wsp*ufn>=(double)(dd)/10)
			{
				SetConsoleTextAttribute( hOut, BACKGROUND_GREEN );
				cout<<"  "<<(double)(dd)/10<<" : TAK	|";
				SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
				
			}
			else{
				SetConsoleTextAttribute( hOut, BACKGROUND_RED );
				cout<<"  "<<(double)(dd)/10<<" : NIE	|";
				SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
			}
			
			}
			cout<<endl;
			if(wsp*ufn>=progjakosci)
			{
			 	cout<<ileja<<endl;
			 	jakosc[ileja]="";
			 	owsp<<wsp;
			 	oufn<<ufn;
			 	ow<<wsp*ufn;
			 	swsp=owsp.str();
			 	sufn=oufn.str();
			 	sw=ow.str();
			 	for(int l=0;l<i;l++)
	 			{
			 		jakosc[ileja]+=poprz[l];
					jakosc[ileja]+="^";
			 	}
			 	jakosc[ileja]+=poprz[i];
				jakosc[ileja]+="=>";
				jakosc[ileja]+=nast;
				jakosc[ileja]+=" wsp = ";
				jakosc[ileja]+=swsp;
				jakosc[ileja]+="; ufn = ";
				jakosc[ileja]+=sufn;
				jakosc[ileja]+="; wsp * ufn = ";
				jakosc[ileja]+=sw;
			 	ileja++;
			}
			 
		}
	 }
 }
 cout<<endl<<"warunki czestosci 2 i progu jakosci 1/3 spelnia"<<endl;
 	for(int l=0;l<ileja;l++){
 		cout<<jakosc[l]<<endl;
	 }
//KONIEC MIEJSCA NA ROZWIAZANIE  
//******************************************************

//funkcja zapisuje tablice stringów do pliku, podajemy
string nazwap2="plik_do zapisu.txt";
cout<<"\n\nNacisnij ENTER aby wykonac demonstracyjny zapis pliku o nazwie "<<nazwap2;
getchar();
zapis(wym2,wym1,G,nazwap2.c_str());

//na koniec czyœcimy pamiêæ po naszej tablicy
for(int i=0;i<wym2+1;i++)
{delete[] G[i];}//czyscimy wiersze
delete[] G;//zwalniamy tablice wskaznikow do wierszy

cout<<"\n\nNacisnij ENTER aby zakonczyc";
getchar();

//na koniec nasza funkcja zwraca wartoœæ 0 i program siê koñczy
return 0;
}
