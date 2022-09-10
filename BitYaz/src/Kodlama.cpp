#include "Kodlama.hpp"

	void Kodlama::bitleriYaz(ofstream& dosya)
    {
        dosya << *c;
    }
	
	string Kodlama::BytetoBit(unsigned char C)
    {
        stringstream ss;
        for(unsigned s = 7; s > 0 ; s--)
        {
            ss << ((C >> s) & 1);
        }

        ss << (C&1) ;
        return ss.str();
    }

    Kodlama::Kodlama(string bitKatari)
    {
        kaydirmaSayisi = 0;
        c = (unsigned char*)malloc(sizeof(char));
		this->bitKatari = bitKatari;
    }

    string Kodlama::bitOlarakOku(ifstream& dosya)
    {
        string s ="";
        char buffer[1];
        while (dosya.read (buffer, 1))
        {
            s += BytetoBit(*buffer);
        }
        return s;
    }

    int Kodlama::bitleriDosyayaYaz(ofstream& dosya)
    {
        int toplam = 0;

        while(bitKatari.length())
        {
            if(bitKatari[0] == '1')
                *c |= 1; //1 ile OR işlemi c'nin son biti sıfır ise 1 olur. 
            // c sol shift yapılıyor
			*c <<= 1;
            ++kaydirmaSayisi;
            ++toplam;
            bitKatari.erase(0, 1);

            if(kaydirmaSayisi == 7 )
            {
                if(bitKatari.size()>0)
                {
                    if(bitKatari[0] == '1')
                        *c |= 1;
                    ++toplam;
                    bitKatari.erase(0, 1);
                }

                bitleriYaz(dosya);
                kaydirmaSayisi = 0;
                delete c;
                c = (unsigned char*)malloc(sizeof(char));
            }
        }

        if(kaydirmaSayisi > 0)
        {
            *c <<= (7 - kaydirmaSayisi);
            bitleriYaz(dosya);
            delete c;
            c = (unsigned char*)malloc(sizeof(char));
        }
        dosya.close();
        return toplam;
    }    

    Kodlama::~Kodlama()
    {
        if(c)
            delete c;
    }
