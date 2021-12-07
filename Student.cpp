#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<conio.h>
using namespace std;

class LibraryS {
    public :
        char bookname[100], authorname[50], sc[20], sc1[50];
        int q, B, p;

        LibraryS(){
            strcpy(bookname, "No Title Book");
            strcpy(authorname, "No Author Name");
            strcpy(sc,"No Book ID");
            strcpy(sc1, "No Book ID");
            q=0;
            B=0;
            p=0;
        }

        void show();
        void open(); // To open the home page
        void booklist();
        void search();
        int branch();
};

// TO OPEN THE HOME PAGE OF STUDENT
void LibraryS::open(){
    int i;

    cout << "\n\t**********WELCOME STUDENT**********";
    cout << "\n\t\t L M S using C++\n";
    cout << "\n\t1.View Booklist \n\t2.Search For Book \n\t3.Close Aplication\n";
    cout << "\n\n\tEnter your choice: ";

    cin >> i;
    //After choosing the number, go to the next window
    if (i == 1) //Booklist window
    {
        booklist();
    }

    else if (i == 2) //Search book Window
    {
        search();
    }
    else if (i == 3) //exit the application
    {
        exit(0);
    }
    else
    {
        cout << "Please enter correct option :(";
        getch();
        system("cls");
        open();
    }

}

//PROGRAM TO SHOW ALL OF THE BOOKLIST
void LibraryS::booklist(){
    int b,r=0;
    system("cls");
    b=branch();
    system("cls");

    ifstream intf("Bookdata.txt", ios::binary);
    if(!intf) {
        cout << "\n\tFile Not Found";
    }

    else {
        cout << "\n\t**********Booklist********** \n\n";
        intf.read((char*)this, sizeof(*this));

        while(!intf.eof()){
            if(b==B)
            {
                r++;
                cout<<"\n\t\t**********" << r << ". ********** \n";
                show();
            }
            intf.read((char*)this, sizeof(*this));
        }
    }

    cout << "\nPress any key to continue.... ";
    getch();
    system("cls");
    open();
}

//PROGRAM TO SEARCH THE BOOK
void LibraryS::search(){
    int i,b, cont=0;
    char ch[100];
    system("cls");
    b=branch();
    ifstream intf("Bookdata.txt", ios::binary);
    if(!intf){
        cout << "\n\t\tFile Not Found";
        cout << "\n\n\t\tPress any key to continue";
        getch();
        system("cls");
        open();
    }

    system("cls");

    //This program is searching for the book that we want to show
    //Using searching and compare with recursion funtion
    cout << "\n\t\tPlease Choose One Option";
    cout << "\n\n\t 1.Search By Book Name \n\n\t2.Search By Book's ID";
    cout << "\n\n\n\t\tEnter your choice: ";
    cin >> i;
    fflush(stdin);
    intf.read((char*)this,sizeof(*this));

    if(i==1) {
		cout<<"\n\t\tEnter Book's Name : ";
        cin.getline(ch,100);
        system("cls");
        while(!intf.eof()) {
			for(i=0;b==B&&q!=0&&bookname[i]!='\0'&&ch[i]!='\0'&&(ch[i]==bookname[i]||ch[i]==bookname[i]+32);i++);
	            if(bookname[i]=='\0'&&ch[i]=='\0') {
	                    cout<<"\n\t\tBook Found :-\n";
	                    show();
	                    cont++;
	                    break;
	            }
            intf.read((char*)this,sizeof(*this));
		}
	}
	
    else if(i==2) {
        cout<<"\n\t\tEnter Book's ID : ";
        cin.getline(ch,100);
        system("cls");
        while(!intf.eof()) {
            for(i=0;b==B&&q!=0&&sc[i]!='\0'&&ch[i]!='\0'&&ch[i]==sc[i];i++);
            	if(sc[i]=='\0'&&ch[i]=='\0') {
                	cout<<"\n\t\tBook Found :-\n";
                    show();
                    cont++;
                    break;
                }
            intf.read((char*)this,sizeof(*this));
        }
	}

    else {
    	cont++;
        cout << "\n\n\t\tYou type the wrong choice...";
        cout << "\n\nPress any key to continue...";
        getch();
        system("cls");
        search();
    }

    intf.close();
    if(cont==0) {
        cout << "\n\n\t\tThis Book is not available or you input the wrong name/id :(";
    }

    cout << "\n\n\t\tPress any key to continue...";
    getch();
    system("cls");
    open();
}

//To show the book data
void LibraryS::show() {
    cout << "\n\t\tBook's Name : " << bookname <<endl;
    cout << "\n\t\tBook's Author Name : " << authorname <<endl;
    cout << "\n\t\tBook's ID : " << sc <<endl;
    cout << "\n\t\tBook's Publication : " << sc1 << endl;
    cout << "\n\t\tBook's Price : " << p <<endl;
    cout << "\n\t\tBook's Quantity : " << q <<endl;
}

// To know what category the student want
int LibraryS::branch()
{
    int i;
    cout << "\n\t\tPlease Choose one Branch : -\n";
    cout << "\n\t\t1. Calculus";
    cout << "\n\t\t2. Geography";
    cout << "\n\t\t3. Biology";
    cout << "\n\t\t4. Chemistry";
    cout << "\n\t\t5. Statistic";
    cout << "\n\t\t6. Accounting";
    cout << "\n\t\t7. Dictionary";
    cout << "\n\t\t8. Programming";
    cout << "\n\t\t9. Back to Main Page";

    cout << "\n\n\n\t\tEnter Your Choice :";

    cin >> i;

    switch(i) {
        case 1: return 1; break;
        case 2: return 2; break;
        case 3: return 3; break;
        case 4: return 4; break;
        case 5: return 5; break;
        case 6: return 6; break;
        case 7: return 7; break;
        case 8: return 8; break;
        case 9: 
            system("cls");
            open();
        default :
            cout<<"\n\t\tPlease enter correct option :(";
            getch();
            system("cls");
            branch();
    }
}


int main(){
    LibraryS lib;

    lib.open();
    getch();
    return 0;
}
