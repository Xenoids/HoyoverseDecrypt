#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* 
Penjelasan Tentang Caesar Cipher 

Caesar Cipher adalah algoritma enkripsi simpel yang dibuat oleh Julius Caesar untuk mengirimkan pesan secara rahasia.

Algoritma Simpel dari Caesar Cipher : 

Enkripsi :

En(x) = (x + n) mod 26 <- dijumlahin

Dekripsi :

En(x) = (x - n) mod 26 <- dikurangi

x -> alphabet yang mau dienkrip/dekrip
n -> jumlah seberapa jauh shift/pergeseran alphabetnya

mod 26 -> dalam alphabet memiliki 26 huruf yang memiliki urutan nilai sequential sesuai dengan alphabetnya 

contoh :
A = 0
B = 1
C = 2
...
Z = 25

*/

/*
Soal Kasus dari kegabutan gim hoyo melalui twitter / X

Aku udah tryhard hitung semua kemungkinan shiftnya dan menemukan bahwa untuk memecahkan ini diketahui shiftnya terdiri dari :

1. Dari Genshin Impact
"fjhiupofojof QBSJT OZD UPLZP UBJQFJ"
Shift : 1

2. Dari Zenless Zone Zero
"Dof uva qbza zhf pa Whptvu?"
Shift : 19

3. Dari Honkai Impact 3
"Ukhgrt ebdx, B pbee ftdx bm bgmh fr ztfx"
Shift : 7

Selamat Mencoba :)
*/

void title()
{
    puts("");
    printf("==============================================\n");
    printf("|Program Pemecahan Masalah Kegabutan Hoyopers|\n");
    printf("==============================================\n");
    puts("Created By : Xenoids Penyefong Gim Hoyopers :)");
    puts("");
}

void Encrypt(char* alphabet, int push)
{
    char encrypt_alpha[100] = "";

    for(int i=0;i<strlen(alphabet);i++)
    {
        // Cek Bukan Special Character & Spasi
        if(isalnum(alphabet[i]) == 0)
            encrypt_alpha[i] = alphabet[i];
    
        else
        {
            // Uppercase
            if(alphabet[i] >= 'A' && alphabet[i] <= 'Z')
                encrypt_alpha[i] = encrypt_alpha[i] + char(int(alphabet[i] + push - 'A') % 26 + 'A');
            

            // Lowercase
            else if(alphabet[i] >= 'a' && alphabet[i] <= 'z')
                encrypt_alpha[i] = encrypt_alpha[i] + char(int(alphabet[i] + push - 'a') % 26 + 'a');
            

        }  
        
    }
    
    printf("Hasil Encrypt : %s\n",encrypt_alpha);
}

void Decrypt(char* alphabet, int push)
{
    char decrypt_alpha[100] = "";

    for(int i=0;i<strlen(alphabet);i++)
    {
        // Cek Bukan Special Character & Spasi
        if(isalnum(alphabet[i]) == 0)
            decrypt_alpha[i] = alphabet[i];
        
        else
            // Uppercase
            if(alphabet[i] >= 'A' && alphabet[i] <= 'Z')
                decrypt_alpha[i] = decrypt_alpha[i] + char(int(alphabet[i] - push - 'A') % 26 + 'A');
            

            // Lowercase
            else if(alphabet[i] >= 'a' && alphabet[i] <= 'z')
                decrypt_alpha[i] = decrypt_alpha[i] + char(int(alphabet[i] - push - 'a') % 26 + 'a');
        

    }  

    printf("Hasil Decrypt : %s\n",decrypt_alpha);       
}
    
int main()
{
    // ini function buat judul doang :)
    title();

    // Variable yang dibutuhkan
    char text[100];  // Text yang mau dienkrip
    int shift; // banyaknya pergeserakan alphabet
    int input_count; // mau ulang input berapa kali?

    printf("Mau input berapa kali? : ");
    scanf("%d",&input_count);
    getchar();

    for(int i=0;i<input_count;i++)
    {
        printf("Input Textnya : ");
        scanf("%[^\n]",text);

        printf("Input Shiftnya : ");
        scanf("%d",&shift);
        getchar();

        // Function Encrypt & Decrypt
        Encrypt(text, shift);
        Decrypt(text, shift);

        puts("");
    }

    return 0;
}