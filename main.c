#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1
#define M 2

// Yapý tanýmlamalarý
struct urun
{
    char reference_kodu[20];
    float fiyat;
};

struct isci
{
    char isim[20];
    char soyisim[20];
    int yas;
};

struct magaza
{
    char isim[10];
    char sokak_ismi[20];
    char mahalle[15];
    char telefon[15];
    float satis;
    struct isci e1;
    struct isci e2;
    struct isci e3;
    struct urun p[M];
};

// Fonksiyon prototipleri
void urunu_olustur(struct urun *pr);
void isciyi_olustur(struct isci *em);
void magazayi_olustur(struct magaza *m);
void magazayi_bas(struct magaza m);
void isciyi_bas(struct isci e);
void urunu_bas(struct urun f);
void en_yasli(struct magaza m);
void ortalama_fiyat(struct magaza m[N]);
void bulundugu_mahalle(struct magaza m[N], char q[12]);

int main()
{
    int i;
    struct magaza m[N];

    printf("Magaza %d :\n", N);
    magazayi_olustur(&m[N]);
    printf("Magaza %d :\n", N);
    magazayi_bas(m[N]);
    en_yasli(m[N]);
    ortalama_fiyat(m);
    bulundugu_mahalle(m, "sisli");

    return 0;
}

// Diðer fonksiyonlarýn tanýmlamalarý ve düzeltmeleri

void urunu_olustur(struct urun *pr)
{
    printf("Referans kodu girin.\n");
    scanf("%s", pr->reference_kodu);
    printf("Lutfen fiyati giriniz.\n");
    scanf("%f", &pr->fiyat);
}

void isciyi_olustur(struct isci *em)
{
    printf("Iscinin adini giriniz.\n");
    scanf("%s", em->isim);
    printf("Iscinin soyadini giriniz.\n");
    scanf("%s", em->soyisim);
    printf("Iscinin yasini giriniz.\n");
    scanf("%d", &em->yas);
}

void magazayi_olustur(struct magaza *m)
{
    int i;
    printf("Lutfen magazanin ismini giriniz.\n");
    scanf("%s", m->isim);
    printf("Lutfen magazanin bulundugu sokak ismini giriniz.\n");
    scanf("%s", m->sokak_ismi);
    printf("Lutfen magazanin bulundugu mahalle ismini giriniz.\n");
    scanf("%s", m->mahalle);
    printf("Lutfen magazanin telefonu olup olmadigini giriniz.\n");
    scanf("%s", m->telefon);
    printf("Satis rakamini girin.\n");
    scanf("%f", &m->satis);
    printf("Isci 1 :\n");
    isciyi_olustur(&m->e1);
    printf("Isci 2 :\n");
    isciyi_olustur(&m->e2);
    printf("Isci 3 :\n");
    isciyi_olustur(&m->e3);
    for (i = 0; i < M; i++)
    {
        printf("Urunlerinizi giriniz %d: \n", i);
        urunu_olustur(&m->p[i]);
    }
}

void magazayi_bas(struct magaza m)
{
    int i;
    printf("Magazanin ismi : %s\n", m.isim);
    printf("Magazanin bulundugu sokak : %s\n", m.sokak_ismi);
    printf("Magazanin bulundugu mahalle : %s\n", m.mahalle);
    printf("Magazanin telefon numarasi : %s\n", m.telefon);
    printf("Satis Rakami : %f\n", m.satis);
    printf("Isci 1: \n");
    isciyi_bas(m.e1);
    printf("Isci 2: \n");
    isciyi_bas(m.e2);
    printf("Isci 3: \n");
    isciyi_bas(m.e3);
    for (i = 0; i < M; i++)
    {
        printf("Urun: %d\n", i);
        urunu_bas(m.p[i]);
    }
}

void isciyi_bas(struct isci e)
{
    printf("Isim : %s\n", e.isim);
    printf("Soyisim : %s\n", e.soyisim);
    printf("Yas: %d\n", e.yas);
}

void urunu_bas(struct urun f)
{
    printf("Referans kodu : %s\n", f.reference_kodu);
    printf("Fiyat : %f\n", f.fiyat);
}

void en_yasli(struct magaza m)
{
    struct isci yasli = m.e1;
    if (m.e2.yas > yasli.yas)
    {
        yasli = m.e2;
    }
    if (m.e3.yas > yasli.yas)
    {
        yasli = m.e3;
    }
    printf("En yasli isci :\n");
    isciyi_bas(yasli);
}

void ortalama_fiyat(struct magaza m[N])
{
    int i, j;
    float s = 0;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            s = s + m[i].p[j].fiyat;
        }
        printf("%s magazasinda yer alan urunlerin ortalama fiyati : %.2f\n", m[i].isim, s / M);
    }
}

void bulundugu_mahalle(struct magaza m[N], char q[12])
{
    int i;
    for (i = 0; i < N; i++)
    {
        if (strcmp(m[i].mahalle, q) == 0)
        {
            printf("%s mahallesinde %s magazasi bulunur.\n", m[i].mahalle, m[i].isim);
        }
    }
}
