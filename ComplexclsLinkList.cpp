//
//  main.cpp
//  ComplexLinkList
//
//  Created by ardavan on 4/26/18.
//  Copyright © 2018 Apple Inc. All rights reserved.
//

#include <iostream>
using namespace std;
class complexCls {
public:
    double img;
    double re;
    complexCls (double forRe=0,double forImg=0) {
        this->img=forImg;
        this->re=forRe;
    }
    complexCls operator+ (complexCls a){
        complexCls b;
        b.img=this->img+a.img;
        b.re=this->re+a.re;
        return b;
    }
    complexCls operator- (complexCls a){
        complexCls b;
        b.img=this->img-a.img;
        b.re=this->re-a.re;
        return b;
    }
    complexCls operator* (complexCls a){
        complexCls b;
        b.img=this->re*a.img+this->img*a.re;
        b.re=this->re*a.re-this->img*a.img;
        return b;
    }
};
class node {
public:
    complexCls data;
    node *link;
};
class list {
public:
    node *head;
    list () {
        head=0;
    }
    void AddToFirst(void){
        node *pn=head;
        head=new node;
        head->link=pn;
        cout<<"Enter your number for add to first : \n";
        cout<<"Enter the re part : ";
        cin>>head->data.re;
        cout<<"Enter the img part : ";
        cin>>head->data.img;
    }
    void append(void){
        node *pn=head,*pv=head;
        int i;
        for(i=0;pv;pv=pv->link,i++);
        if(i==0){
            head=new node;
            head->link=pn;
            cout<<"Enter your number for add to first : \n";
            cout<<"Enter the re part : ";
            cin>>head->data.re;
            cout<<"Enter the img part : ";
            cin>>head->data.img;
        }
        else{
            for(i=0;pn->link;pn=pn->link,i++);
            pn->link=new node;
            pn->link->link=0;
            cout<<"Enter your number for add to end \n";
            cout<<"Enter the re part : ";
            cin>>pn->link->data.re;
            cout<<"Enter the img part : ";
            cin>>pn->link->data.img;
        }
    }
    void insert(int a){
        node *pn=head;
        int i;
        for(i=0;i<a&&pn->link;pn=pn->link,i++);
        if(a==i){
            cout<<"Enter your insert number in part "<<a<<" : \n";
            cout<<"Enter the re part : ";
            cin>>pn->data.re;
            cout<<"Enter the img part : ";
            cin>>pn->data.img;
        }
        else{
            cout<<"There is no such a data!"<<endl;
        }
    }
    void printLinkList (void){
        node *pn;
        pn=head;
        for(int i=0;pn;pn=pn->link,i++){
            cout<<"a["<<i<<"] : "<<pn->data.re<<"+"<<pn->data.img<<"i"<<endl;
        }
    }
    void removeLinkList(int a){
        node *pn=head,*pv=head->link;
        int i;
        if (a==0){
            for(i=0;pn->link;pn=pn->link,i++);
            if(i==1){
                head=0;
            }
            else{
                head=head->link;
            }
        }
        else{
            a=a-1;
            for(i=0;i<a&&pv&&pn;pv=pv->link,pn=pn->link,i++);
            if(a==i){
                pn->link=pv->link;
                delete pv;
            }
            else{
                cout<<"There is no such a data!"<<endl;
            }
        }
    }
};
int main() {
    list l1;
    l1.append();
    l1.printLinkList();
    l1.AddToFirst();
    l1.printLinkList();
    l1.append();
    l1.printLinkList();
    l1.AddToFirst();
    l1.printLinkList();
    l1.append();
    l1.printLinkList();
    l1.append();
    l1.printLinkList();
    l1.append();
    l1.printLinkList();
    l1.append();
    l1.printLinkList();
    int a;
    cout<<"Enter the number of part for insert function :";
    cin>>a;
    l1.insert(a);
    l1.printLinkList();
    cout<<"Do you want to REMOVE something? ";
    cin>>a;
    l1.removeLinkList(a);
    l1.printLinkList();
    cout<<"Do you want to REMOVE something? ";
    l1.removeLinkList(a);
    l1.printLinkList();
    return 0;
}
