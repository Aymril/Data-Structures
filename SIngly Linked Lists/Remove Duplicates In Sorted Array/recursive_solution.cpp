void deleteDuplicates(Node* list) {
        if(!list)
            return;
        
        if(list->link == nullptr)
            return;
    
        if(list->data == list->link->data){
            Node* temp = list->link;
            list->link = temp->link;
            delete temp;
            deleteDuplicates(list);
        }else{
            deleteDuplicates(list->link);
        }
}
