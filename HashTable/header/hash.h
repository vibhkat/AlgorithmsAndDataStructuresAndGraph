#ifndef HASH_H_
#define HASH_H_
#include<iostream>
#include<string>
class hash
{
public:
        hash();
        int Hash(const std::string&);
        int NumberofItemsInIndex(const int& );
        void PrintTable();
        void PrintInIndex(const int& );
        void AddItem(const std::string& , const std::string&);
        void findDrink(const std::string& );
        void remove(const std::string& );

private:
        static const int tablesize=10;
        struct item
        {
            std::string name;
            std::string drink;
            item* next;
        };
        item* HashTable[tablesize] ;// NOTE: cannot put NULL over here. we will have to intitalise it using constructor

};




hash::hash()
{
    for(int i=0; i!=tablesize; ++i)
    {
        HashTable[i]= new item;
        HashTable[i]->name="empty";
        HashTable[i]->drink="empty";
        HashTable[i]->next=NULL;
    }

}

int hash::Hash(const std::string& key)
{
    int hash=0;
    for(int i=0; i!=(int)key.size(); ++i)
    {
        hash=hash+(int)key[i];
    }

    return (hash%tablesize);

}



int hash::NumberofItemsInIndex(const int& index)
{
    int count=0;
    if(HashTable[index]->name=="empty")
    {
        return count;
    }
    else
    {
        ++count;
        item *ptr=HashTable[index];
        while(ptr->next != NULL)
        {
            ++count;
            ptr=ptr->next;
        }
        return count;
    }
}

void hash::PrintTable()
{
    for(int i=0; i!=tablesize; ++i)
    {
        PrintInIndex(i);
        /*
           int number=NumberofItemsInIndex(i);
           std::cout<<"----------------\n";
           std::cout<<"index ="<<i<<std::endl;
           std::cout<<HashTable[i]->name<<std::endl;
           std::cout<<HashTable[i]->drink<<std::endl;
           std::cout<<"# of items  = "<<number<<std::endl<<"-----------------"<<std::endl;
           */
    }
}

void hash::PrintInIndex(const int& index)
{
    item* ptr=HashTable[index];
    if(ptr->name=="empty")
    {
        std::cout<<"INDEX ="<<index<< " IS EMPTY"<<std::endl<<"------------------------------"<<std::endl;
    }
    else
    {
        std::cout<<"-------------------------"<<std::endl<<"index ="<<index<<std::endl;
        while(ptr!= NULL)
        {
            std::cout<<ptr->name<<std::endl;
            std::cout<<ptr->drink<<std::endl;
            ptr=ptr->next;
        }
        std::cout<<"---------------------------------"<<std::endl;
    }
}


void hash::AddItem(const std::string& name, const std::string & drink)
{
    int index=Hash(name);
    item* temp=new item;
    temp->name=name;
    temp->drink=drink;
    temp->next=NULL;
    if(HashTable[index]->name=="empty")
    {
        HashTable[index]=temp;
    }
    else
    {
        item* ptr=HashTable[index];
        while(ptr->next != NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
}


void hash::findDrink(const std::string& name)
{
    int index=Hash(name);
    bool findName=false;
    item* ptr=HashTable[index];
    while(ptr!=NULL)
    {
        if(ptr->name == name)
        {
            findName=true;
            std::cout<<ptr->drink<<std::endl;
break;
        }
        ptr=ptr->next;
    }

    if(findName) std::cout<<"FOUND"<<std::endl;
    else std::cout<<"NOT FOUND"<<std::endl;
}


void hash::remove(const std::string& name)
{
    int index=Hash(name);

    //Case 0: bucket is empty

    if(HashTable[index]->name=="empty" && HashTable[index]->drink=="empty")
    {
        std::cout<<"was not found\n";
    }

    //Case 1:Match first item and only item at that index
    else if(HashTable[index]->next==NULL && HashTable[index]->name==name)
    {
        HashTable[index]->name="empty";
        HashTable[index]->drink="empty";
    }

    //Case 2: Match first item and there are items at that index
    else if(HashTable[index]->next!=NULL && HashTable[index]->name==name)
    {
        item* delptr=HashTable[index];
        HashTable[index]=HashTable[index]->next;
        delete delptr;
        std::cout<<name<<" was removed "<<std::endl;
    }

    //Case 3: items at that index but first is not that item
    else
    {
        item* p1=HashTable[index]->next;
        item* p2=HashTable[index];
        while(p1!=NULL && p1->name!=name)     //searching for that item which matches the name
        {
            p2=p1;
            p1=p1->next;
        }

        if(p1==NULL) std::cout<<"NOT found"<<std::endl;
        else
        {
            item* delptr=p1;
            p1=p1->next;
            p2->next=p1;
            delete delptr;
        }
    }
}




#endif /* HASH_H_ */
