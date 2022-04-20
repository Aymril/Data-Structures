void deleteDuplicates2(Node* list) {
        if(!list)
            return;
        
        if(list->link == nullptr)
            return;
    
        if(list->data == list->link->data){
            Node* temp = list->link;
            list->link = temp->link;
            delete temp;
            deleteDuplicates2(list);
        }else{
            deleteDuplicates2(list->link);
        }
}
