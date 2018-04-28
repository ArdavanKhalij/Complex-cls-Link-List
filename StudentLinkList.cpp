//
//  main.cpp
//  StudentLinkList
//
//  Created by ardavan on 4/26/18.
//  Copyright © 2018 Apple Inc. All rights reserved.
//

#include <iostream>
using namespace std;
class student {
public:
    string firstName;
    string midleName;
    string familyName;
    string studentNumber;
    string studentPhoneNumber;
    string studentEmail;
    string field;
    double age;
    student (string a="",string b="",string c="",string d="",string e="",string f= "",string g="",double h=0){
        string firstName=a;
        string midleName=b;
        string familyName=c;
        string studentNumber=d;
        string studentPhoneNumber=e;
        string studentEmail=f;
        string field=g;
        double age=h;
    }
};
class node {
public:
    student data;
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
        cout<<"Enter the first name part : ";
        cin>>head->data.firstName;
        cout<<"Enter the midle name part : ";
        cin>>head->data.midleName;
        cout<<"Enter the family name part : ";
        cin>>head->data.familyName;
        cout<<"Enter the student number part : ";
        cin>>head->data.studentNumber;
        cout<<"Enter the student phone number : ";
        cin>>head->data.studentPhoneNumber;
        cout<<"Enter the student E-mail part : ";
        cin>>head->data.studentEmail;
        cout<<"Enter the field part : ";
        cin>>head->data.field;
        cout<<"Enter the age part : ";
        cin>>head->data.age;
    }
    void append(void){
        node *pn=head,*pv=head;
        int i;
        for(i=0;pv;pv=pv->link,i++);
        if(i==0){
            head=new node;
            head->link=pn;
            cout<<"Enter your number for add to first : \n";
            cout<<"Enter the first name part : ";
            cin>>head->data.firstName;
            cout<<"Enter the midle name part : ";
            cin>>head->data.midleName;
            cout<<"Enter the family name part : ";
            cin>>head->data.familyName;
            cout<<"Enter the student number part : ";
            cin>>head->data.studentNumber;
            cout<<"Enter the student phone number : ";
            cin>>head->data.studentPhoneNumber;
            cout<<"Enter the student E-mail part : ";
            cin>>head->data.studentEmail;
            cout<<"Enter the field part : ";
            cin>>head->data.field;
            cout<<"Enter the age part : ";
            cin>>head->data.age;
        }
        else{
            for(i=0;pn->link;pn=pn->link,i++);
            pn->link=new node;
            pn->link->link=0;
            cout<<"Enter your number for add to end \n";
            cout<<"Enter the first name part : ";
            cin>>pn->link->data.firstName;
            cout<<"Enter the midle name part : ";
            cin>>pn->link->data.midleName;
            cout<<"Enter the family name part : ";
            cin>>pn->link->data.familyName;
            cout<<"Enter the student number part : ";
            cin>>pn->link->data.studentNumber;
            cout<<"Enter the student phone number : ";
            cin>>pn->link->data.studentPhoneNumber;
            cout<<"Enter the student E-mail part : ";
            cin>>pn->link->data.studentEmail;
            cout<<"Enter the field part : ";
            cin>>pn->link->data.field;
            cout<<"Enter the age part : ";
            cin>>pn->link->data.age;
        }
    }
    void insert(int a){
        node *pn=head;
        int i;
        for(i=0;i<a&&pn->link;pn=pn->link,i++);
        if(a==i){
            cout<<"Enter your insert number in part "<<a<<" : \n";
            cout<<"Enter the first name part : ";
            cin>>pn->data.firstName;
            cout<<"Enter the midle name part : ";
            cin>>pn->data.midleName;
            cout<<"Enter the family name part : ";
            cin>>pn->data.familyName;
            cout<<"Enter the student number part : ";
            cin>>pn->data.studentNumber;
            cout<<"Enter the student phone number : ";
            cin>>pn->data.studentPhoneNumber;
            cout<<"Enter the student E-mail part : ";
            cin>>pn->data.studentEmail;
            cout<<"Enter the field part : ";
            cin>>pn->data.field;
            cout<<"Enter the age part : ";
            cin>>pn->data.age;
        }
        else{
            cout<<"There is no such a data!"<<endl;
        }
    }
    void printLinkList (void){
        node *pn;
        pn=head;
        for(int i=0;pn;pn=pn->link,i++){
            cout<<"a["<<i<<"] : \n First Name : "<<pn->data.firstName<<endl;
            cout<<"Midle Name : "<<pn->data.midleName<<endl;
            cout<<"Family Name : "<<pn->data.familyName<<endl;
            cout<<"Student Number : "<<pn->data.studentNumber<<endl;
            cout<<"Student Phone Number : "<<pn->data.studentPhoneNumber<<endl;
            cout<<"Student E-mail : "<<pn->data.studentEmail;
            cout<<"Student Field : "<<pn->data.field<<endl;
            cout<<"Student Age : "<<pn->data.age<<endl;
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
