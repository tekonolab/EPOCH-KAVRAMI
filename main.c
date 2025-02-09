#include <stdio.h>
#include <time.h>

// Tarih ve saat için struct
struct DateTime {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

// Tarih bilgileri ve epoch zamanýný saklamak için union
union DateOrEpoch {
    struct DateTime dt;  // Tarih ve saat bilgileri
    long long epoch;     // Epoch zamaný
};

// Epoch kavraminin detayli aciklamasi
void epoch_aciklama() {
    printf("\n------------------------------------------------\n");
    printf("Epoch Zamani (Unix Epoch Zamani):\n");
    printf("Epoch, bilgisayar sistemlerinde zaman olcumu icin baslangic noktasidir.\n");
    printf("Bu baslangic noktasi, genellikle 1970-01-01 00:00:00 UTC (Koordine Edilmis Evrensel Zaman) anidir.\n");
    printf("Bu tarihten itibaren gecen sureyi saniye cinsinden ifade ederiz.\n");
    printf("Epoch zamanini kullanmak, tarih ve saat farklarini karsilastirmayi ve hesaplamayi kolaylastirir.\n");
    printf("Epoch zamaninda her an, 1970 yilindan itibaren gecen saniye sayisi olarak ifade edilir.\n");
    printf("Ornegin:\n");
    printf("Epoch zamaninin baslangici: 1970-01-01 00:00:00 UTC = 0 saniye.\n");
    printf("2025-02-09 00:00:00 UTC icin epoch zamani: 1733740800 saniye.\n");
    printf("Bu sekilde, tarihleri karsilastirmak cok daha kolay hale gelir.\n");
    printf("------------------------------------------------\n");
}

// Tarih bilgisini epoch zamanina donusturen fonksiyon
long long epoch_zamani_getir(struct DateTime dt) {
    struct tm time_info = {0};

    time_info.tm_year = dt.year - 1900;  // Yil 1900'den baslar
    time_info.tm_mon = dt.month - 1;     // Ay 0'dan baslar
    time_info.tm_mday = dt.day;          // Gun
    time_info.tm_hour = dt.hour;         // Saat
    time_info.tm_min = dt.minute;        // Dakika
    time_info.tm_sec = dt.second;        // Saniye

    return mktime(&time_info);  // Tarihi epoch zamanina donusturur
}

// Iki tarih arasindaki farki saniye cinsinden hesaplama
void zaman_farki_hesapla(struct DateTime date1, struct DateTime date2) {
    union DateOrEpoch u1, u2;
    
    // Ilk tarih icin epoch zamani hesapla
    u1.dt = date1;
    u1.epoch = epoch_zamani_getir(date1);

    // Ikinci tarih icin epoch zamani hesapla
    u2.dt = date2;
    u2.epoch = epoch_zamani_getir(date2);

    // Zaman farkini hesapla
    long long fark = u2.epoch - u1.epoch;
    printf("Film suresi: %lld saniye\n", fark);
}

int main() {
    struct DateTime date1, date2;

    // Epoch aciklamasini yapiyoruz
    epoch_aciklama();

    // Kullanicidan film seansi baslangic tarihini alalim
    printf("Film seansi baslangic zamanini giriniz:\n");
    printf("Yil (orn: 2023): ");
    scanf("%d", &date1.year);
    printf("Ay (1-12): ");
    scanf("%d", &date1.month);
    printf("Gun (1-31): ");
    scanf("%d", &date1.day);
    printf("Saat (0-23): ");
    scanf("%d", &date1.hour);
    printf("Dakika (0-59): ");
    scanf("%d", &date1.minute);
    printf("Saniye (0-59): ");
    scanf("%d", &date1.second);

    // Kullanicidan film seansi bitis tarihini alalim
    printf("\nFilm seansi bitis zamanini giriniz:\n");
    printf("Yil (orn: 2023): ");
    scanf("%d", &date2.year);
    printf("Ay (1-12): ");
    scanf("%d", &date2.month);
    printf("Gun (1-31): ");
    scanf("%d", &date2.day);
    printf("Saat (0-23): ");
    scanf("%d", &date2.hour);
    printf("Dakika (0-59): ");
    scanf("%d", &date2.minute);
    printf("Saniye (0-59): ");
    scanf("%d", &date2.second);

    // Zaman farkini hesaplayalim
    zaman_farki_hesapla(date1, date2);

    return 0;
}

