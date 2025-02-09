Tarih ve Saat Farkı Hesaplama Programı
Proje Açıklaması
Bu C programı, kullanıcının girdiği iki farklı tarih ve saat için zaman farkını hesaplar ve bu farkı epoch zamanı üzerinden gösterir. Program, struct ve union veri yapıları kullanarak tarih hesaplamalarını yapmaktadır. Ayrıca, epoch zamanı kavramını da detaylı bir şekilde açıklar.

Epoch zamanı, 1970 yılı 1 Ocak 00:00:00 UTC'nin başlangıç (referans) zamanı olarak kabul edilen bir zaman sistemidir. Bu referansa göre, her geçen saniye bir değerle ifade edilir. Bu programda, kullanıcıdan alınan tarih ve saat bilgilerini epoch zamanına dönüştürüp, iki tarih arasındaki farkı saniye, gün, saat, dakika ve saniye cinsinden hesaplar.Epoch Zamanı Nedir?
Epoch zamanı, genellikle bilgisayar bilimlerinde kullanılan ve "Unix zaman damgası" olarak da bilinen bir zaman ölçü birimidir. Epoch zamanı, 1970 yılının 1 Ocak günü saat 00:00:00 UTC (Koordinatlı Evrensel Zaman) başlangıç noktası olarak kabul edilir. Bu tarihten itibaren geçen saniyelerin sayısını ifade eder.

Örnek olarak:

1 Ocak 1970, 00:00:00 UTC, epoch zamanının 0 saniye olduğu andır.
2 Ocak 1970, 00:00:00 UTC, epoch zamanının 86400 saniye olduğu andır (Çünkü bir gün, 86400 saniyedir).
Epoch zamanı, tarih ve saat hesaplamalarını daha basit hale getirmek için kullanılır ve çok sayıda bilgisayar sistemi, zaman bilgisini bu şekilde işler.Epoch Zamanının Kullanımı:
Standartlaştırılmış Zaman: Farklı zaman dilimlerinde olan makineler arasında zaman karşılaştırmasını kolaylaştırır.
Bellek ve Depolama Verimliliği: Tarih ve saat bilgilerini sayısal bir değerle temsil etmek, bellekte daha verimli bir şekilde saklanmasına yardımcı olur.
Zaman Hesaplamaları: İki tarih arasındaki farkları hesaplamak için yaygın olarak epoch zamanı kullanılır.Program Özellikleri
Bu program aşağıdaki adımları takip eder:

Kullanıcıdan iki tarih ve saat bilgisi alınır.
Tarihler epoch zamanı olarak dönüştürülür.
İki tarih arasındaki fark saniye olarak hesaplanır.
Zaman farkı, gün, saat, dakika ve saniye cinsinden ekrana yazdırılır.Kullanım
Programın Çalışma Adımları:
Kullanıcıdan iki tarih ve saat bilgisi alınır:
Yıl, ay, gün, saat, dakika, saniye şeklinde.
Bu tarih bilgileri epoch zamanına dönüştürülür.
Ardından, epoch zamanı farkı hesaplanır.
Zaman farkı, gün, saat, dakika, saniye olarak gösterilir.Örnek Girdi ve Çıktı
Girdi:

java
Kopyala
Düzenle
Ilk tarih ve saat bilgilerini girin (YYYY MM DD HH MM SS): 2025 02 10 14 30 00
Ikinci tarih ve saat bilgilerini girin (YYYY MM DD HH MM SS): 2025 02 12 10 00 00Çıktı:

yaml
Kopyala
Düzenle
Ilk tarih epoch zamani: 1739176200
Ikinci tarih epoch zamani: 1739353200
Zaman farki: 1 gun, 19 saat, 30 dakika, 0 saniyeKodun Detayları
struct DateTime: Kullanıcıdan alınan tarih ve saat bilgilerini tutmak için struct veri yapısı kullanılmıştır. Yapının her üyesi, sırasıyla yıl, ay, gün, saat, dakika ve saniye bilgilerini tutar.

union TimeDifference: Tarihler arasındaki farkı tutmak için union veri yapısı kullanılmıştır. union, aynı bellek alanını paylaşan birden fazla veri türünü saklamak için kullanılır. Burada, zaman farkını hem toplam saniye olarak hem de gün, saat, dakika ve saniye cinsinden saklamamıza olanak tanır.

Epoch Zamanı Hesaplama: mktime() fonksiyonu kullanılarak tarih bilgileri epoch zamanına dönüştürülür. Bu fonksiyon, struct tm yapısındaki tarih bilgisini alır ve bu tarihi UTC zamanına göre epoch zamanına dönüştürür.Kullanılan Bileşenler
C Dilinde Struct ve Union: Tarih ve saat hesaplamalarında ve zaman farkı işlemlerinde struct ve union veri yapıları kullanılmıştır.
mktime(): Tarih bilgisini epoch zamanına dönüştüren standart C kütüphanesi fonksiyonudur.
Geliştirme ve Katkı
Bu proje, tarih ve saat hesaplamalarını daha verimli ve esnek hale getirmek için struct ve union veri yapılarını kullanmayı amaçlamaktadır.
Epoch zamanını anlamak ve kullanmak, zaman dilimi farklarını göz önünde bulundurarak global zaman hesaplamaları yapabilmeyi sağlar.
Lisans
Bu proje, MIT Lisansı altında lisanslanmıştır.
