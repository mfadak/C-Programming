#ifndef KODLAMA_HPP
#define KODLAMA_HPP

#include <iostream>
#include <sstream>
#include <fstream>
#include <string> 
#include <cstdlib>
using namespace std;

class Kodlama{
private:
    unsigned char* c;
    int kaydirmaSayisi;
    string bitKatari;
	
    void bitleriYaz(ofstream&);	
	string BytetoBit(unsigned char);
public:

    Kodlama(string bitKatari);
    string bitOlarakOku(ifstream&);
    int bitleriDosyayaYaz(ofstream&);  
    ~Kodlama();
};

#endif
