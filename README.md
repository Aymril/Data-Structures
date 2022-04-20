# Data Structures - (Veri Yapıları)

Türkçesi "Veri yapıları" olan, üniversitelerin genellikle 2. sınıflarında verilen bir derstir. Gerçekte ise bir dersten çok daha fazlasıdır, [vikipedi](https://en.wikipedia.org/wiki/Data_structure) tanımına bakarak daha iyi anlayabiliriz:

>In computer science, a data structure is a data organization, management, and storage format that enables efficient access and modification.[1][2][3] More precisely, a data structure is a collection of data values, the relationships among them, and the functions or operations that can be applied to the data,[4] i.e., it is an algebraic structure about data.

Türkçe çevirisi: Bilgisayar biliminde veri yapısı, **verimli erişim** ve **değişiklik** sağlayan bir veri organizasyonu, yönetimi ve depolama formatıdır.[1][2][3] Daha doğrusu, bir veri yapısı, veri değerleri, bunlar arasındaki ilişkiler ve verilere uygulanabilecek işlevler veya işlemler topluluğudur,[4] yani verilerle ilgili cebirsel bir yapıdır.

## What is data - (Veri Nedir)?

## What is Data Structures and why we need them - (Veri Yapıları nedir ve niye vardır)?

Bilgisayar programlarını, birer matematik fonksiyonları olarak düşünebilirsiniz. Fonksiyonlar, input (girdi) alır (program özelinde input, data'dır, yani veri) ve fonskiyonun algoritması sonunda bir çıktı (output) üretir. Matematikteki "Input - İşlem/Hesaplama - Çıktı" ardışıklığı, bilgisayar programlarında "Input - Algorithm - Output" olarak düşünülebilir. Input ve Output bir veri olduğundan ve algoritmalar da veri ile iş yaptıklarından, veriyi bir yerde tutma/saklama (store) ihtiyacı meydana çıkıyor. 

Basit algoritmalar yazarken **primitive data types** veya **array** kullanarak işlerimizi yerine getirebiliriz. İleri seviye algoritmalar geliştiriken, veriyi farklı şekilde saklama yollarına ihtiyacımız oluyor. Yapılacak işin özelliklerine uygun olan veri yapısı seçilir ve kullanılır.

Bir Veri yapısı ile aşağıdaki 4 şey bizi ilgilendiriyor:

1. Logical View (Abstract View or Abstract Data Type or ADT).
2. Operation defined on that data structure.
3. Cost of operations (Time/Space complexity considered, but mostly time complexity).
4. Implementeations (gerçekleştirme).

Bir veri yapısı birden fazla yolla gerçekleştirilebilir. Ben veri yapılarını gerçekleştirip, daha sonra da gruplaştırıp bu repo'da toplayacağım. Veri yapılarının *1*, *2* ve *3*'de bahsettiğim özelliklerini ayrı bir yazıda yazmayı düşünüyorum. Öyle olduğu durumda, yazı linklerini de buraya ekleyeceğim.
