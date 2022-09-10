#include "Kodlama.hpp"
int main(int argc, char* argv[]){	
	if(argc != 3) 
	{
		cout<<"Hatali parametre kullanimi!"<<endl;
		cout<<"Örnek Kullanim: BitYaz 1001010011101001 Sample.dat"<<endl;
	}
	else{
		// Dosyaya bit olarak yazma
		ofstream dosya(argv[2]);
		Kodlama *kodlama = new Kodlama(argv[1]);
		kodlama->bitleriDosyayaYaz(dosya);
		dosya.close();
		cout<<argv[2]<<" isimli dosya basariyla olusturuldu."<<endl;
		// Yazılan dosyadan bit olarak okuma
		ifstream oku(argv[2]);
		cout<<"Dosyaya Yazilan Bit Bilgisi: "<<kodlama->bitOlarakOku(oku);cout<<endl;
		oku.close();
		delete kodlama;	
	}
	cout<<"Programi kapatmak icin bir tusa basin."<<endl;
	cin.get();	
	return 0;
}
