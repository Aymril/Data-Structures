/* linus torvalds tedX konusmasinda "good taste" meselesini anlatmak icin linked list uzerinden bir ornek verdi. ozetle dedigi su sekildeydi: insertion/deletion vb benzer islemler icin corner case (kose durumlari) olabilir. bu gibi durumlarda isleme tabi tutulacak node'un evvelindeki node'un adresini tutmamiz gerekiyor. local reference kullanarak corner case'ler icin ayri ayri kod yazmaktan kurtulabiliriz. her case'i kapsayan bir kod yaziliyor local reference ile: ornegin, 

Node* mergeLists(Node* h1, Node* h2) {
    Node** result = &h1, *temp;
    
    while(h2) {
        temp = h2;
        h2 = h2->next;
        while(*result && (*result)->data < temp->data) {
            result = &(*result)->next;
        }
        temp->next = *result;
        *result = temp;
    }
    return h1;
}

koduna bakin ve bu dosya icerisinde yazilmis ayni problemin iki farkli cozumu ile karsilastirin. farki goreceksinizdir.
