#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<conio.h>
using namespace std;

class Librarian {
    public :
        char bookname[100], authorname[50], sc[20], sc1[50];
        int q, B, p;

        Librarian(){
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
        void modify();
        void getdata();
        int branch();
        void issue();
        void fine(int d, int m, int y, int dd, int mm, int yy);
        void der(char st[], int b, int x);
};

//PROGRAM TO HOME PAGE OF LIBRARIAN
void Librarian::open(){
     int i;

    cout << "\n\t**********WELCOME LIBRARIAN**********";
    cout << "\n\t\t L M S using C++\n";
    cout << "\n\t1.View Booklist\n";
    cout << "\n\t2.Search For Book\n";
    cout << "\n\t3.Modify/Add Book in Booklist\n";
    cout << "\n\t4.Issue Book\n";
    cout << "\n\t5.Close Aplication\n";

    cout << "\n\n\tEnter your choice: ";

    cin >> i;

    //After choosing the number go to the chosen window
    
    //View booklist window
    if (i==1){
        system("cls");
        booklist();
    }

    //Search booklist window
    else if (i==2){
        system ("cls");
        search();
    }

    //Modify booklist window
    else if (i==3){
        system("cls");
        modify();
    }

    //Issue the book, view the issue book, reissue book, return book.
    else if (i==4){
        system("cls");
        issue();
    }
    //Force close
    else if (i==5){
        exit(0);
    }

    else {
        cout << "Please enter correct option :(";
        getch();
        system("cls");
        open();
    }
}

//PROGRAM TO SHOW ALL OF THE BOOKLIST
void Librarian::booklist(){
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
void Librarian::search(){
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
    cout << "\n\n\t1.Search By Book Name \n\n\t2.Search By Book's ID";
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
void Librarian::show() {
    cout << "\n\t\tBook's Name : " << bookname <<endl;
    cout << "\n\t\tBook's Author Name : " << authorname <<endl;
    cout << "\n\t\tBook's ID : " << sc <<endl;
    cout << "\n\t\tBook's Publication : " << sc1 << endl;
    cout << "\n\t\tBook's Price : " << p <<endl;
    cout << "\n\t\tBook's Quantity : " << q <<endl;
}

//PROGRAM TO MODIFY/ADD/DELETE THE BOOK
void Librarian::modify(){

    char ch, st1[100];
    int i=0, b, cont=0;
    system("cls");

    cout << "\n\t\tPlease choose the option!\n";
    cout << "\n\t1. Modification the Current Book";
    cout << "\n\t2. Add New Book";
    cout << "\n\t3. Delete a Book";
    cout << "\n\t4. Go Back to Home Page";

    cout << "\n\n\t\tEnter your choice : ";
    cin >> i;
    
    //Program to modify the book
    if(i==1) {
        system("cls");
        b=branch();
        ifstream intf1("Booksdata.txt", ios::binary);
        if(!intf1){
            cout << "\n\t\tFile Not Found";
            cout << "\n\n\t\tPress any key to continue";
            getch();
            system("cls");
            open();
        }
        
        intf1.close();
        system("cls");

        //This program is searching for the book that we want to modify
        //Using searching and compare with recursion funtion
        cout << "\n\t\tPlease Choose One Option";
        cout << "\n\n\t1.Search By Book Name \n\n\t2.Search By Book's ID";
        cout << "\n\n\n\t\tEnter your choice: ";
        cin >> i;
        fflush(stdin);

        //Searching the book using book name / book title
        if(i==1) {
            system("cls");
            cout<<"\n\tEnter Book Name : ";
            cin.getline(st1, 100);
            system("cls");
            fstream intf("Bookdata.txt", ios::in|ios::out|ios::ate|ios::binary);
            intf.seekg(0);
            intf.read((char*)this, sizeof(*this));
            while(!intf.eof()){
                for(i=0; b==B && bookname[i]!='\0' && (st1[i] == bookname[i]||st1[i]==bookname[i]+32); i++) {
                    if(bookname[i]=='\0' && st1[i]=='\0') {
                        cont++;
                        getdata(); //-> Go to the add book function if the bookname is found inside the file.
                        int u = intf.tellp();
                        intf.seekp(u - sizeof(*this));
                        intf.write((char*)this, sizeof(*this));
                        break;
                    }
                    intf.read((char*)this, sizeof(*this));
                }
            }
            intf.close();
        }

        //Searching the book with Book's ID
        if(i==2) {
            system("cls");
            cout<<"\n\tEnter Book's ID : ";
            cin.getline(st1, 100);
            system("cls");
            fstream intf("Bookdata.txt", ios::in|ios::out|ios::ate|ios::binary);
            intf.seekg(0);
            intf.read((char*)this, sizeof(*this));
            while(!intf.eof()){
                for(i=0; b==B && sc[i]!='\0' && st1[i] != '\0' && st1[i]==sc[i]; i++) {
                    if(sc[i]=='\0' && st1[i]=='\0') {
                        cont++;
                        getdata();//-> Go to the add book function if the bookname is found inside the file.
                        int u = intf.tellp();
                        intf.seekp(u - sizeof(*this));
                        intf.write((char*)this, sizeof(*this));
                        break;
                    }
                    intf.read((char*)this, sizeof(*this));
                }
            }
            intf.close();
        }


        // If you type the wrong choice to search
        else {
            cout << "\n\n\t\tYou type the wrong choice...";
            cout << "\n\nPress any key to continue...";
            getch();
            system("cls");
            modify();
        }

        //If the book not found or you type the id or the name wrong.
        if (cont==0) {
            cout << "\n\n\t\tBook Not Found";
            cout << "\n\nPress any key to continue...";
            getch();
            system("cls");
            modify();
        }

        //Success in changing the data
        else {
        cout<<"\n\n\t\tUpdate Successfully";
        }
    }

    else if(i==2){
        system("cls");
        B=branch();
        system("cls");
        getdata(); //-> go to page add book
        ofstream outf("Bookdata.txt", ios::app|ios::binary);
        outf.write((char*)this,sizeof(*this));
        outf.close();
        cout << "\n\n\t\tYou successfully add new book";
    }

    else if(i==3){
        system("cls");
        b=branch();
        ifstream intf1("Bookdata.txt", ios::binary);
        if(!intf1){
            cout << "\n\t\tFile Not Found";
            cout << "\n\n\t\tPress any key to continue";
            getch();
            system("cls");
            open();
        }
        
        intf1.close();
        system("cls");

        //This program is searching for the book that we want to delete
        //Using searching and compare with recursion funtion
        cout << "\n\t\tPlease Choose One Option for Deletion";
        cout << "\n\n\t 1.By Book Name \n\n\t2. By Book's ID";
        cout << "\n\n\n\t\tEnter your choice: ";
        cin >> i;
        fflush(stdin);

        //Deleting the book using book name / book title
        if(i==1) {
            system("cls");
            cout<<"\n\t\tEnter Book Name : ";
            cin.getline(st1,100);
            ofstream outf("temp.txt",ios::app|ios::binary);
            ifstream intf("Bookdata.txt",ios::binary);
            intf.read((char*)this,sizeof(*this));
            while(!intf.eof()) {
                for(i=0;b==B&&bookname[i]!='\0'&&st1[i]!='\0'&&(st1[i]==bookname[i]||st1[i]==bookname[i]+32);i++);
					if(bookname[i]=='\0'&&st1[i]=='\0') {
                    	cont++;
                        intf.read((char*)this,sizeof(*this));
					}
                    
					else {
                        outf.write((char*)this,sizeof(*this));
                        intf.read((char*)this,sizeof(*this));
                    }
        	}
            intf.close();
            outf.close();

            //After moving the data from bookdata to temp
            //We delete the bookdata and rename temp to bookdata (new bookdata)
            remove("Bookdata.txt");
            rename("temp.txt", "Bookdata.txt");
        }

        //Repeat the same process for deleting with Book's ID
        else if(i==2) {
            cout<<"\n\t\tEnter Book's ID : ";
            cin.getline(st1,100);
            ofstream outf("temp.txt",ios::app|ios::binary);
            ifstream intf("Bookdata.txt",ios::binary);
            intf.read((char*)this,sizeof(*this));
            while(!intf.eof()) {
                for(i=0;b==B&&sc[i]!='\0'&&st1[i]!='\0'&&st1[i]==sc[i];i++);
                    if(sc[i]=='\0'&&st1[i]=='\0') {
                        cont++;
                        intf.read((char*)this,sizeof(*this));
					}
                    
					else {
                        outf.write((char*)this,sizeof(*this));
                        intf.read((char*)this,sizeof(*this));
                    }
            }
            
            intf.close();
            outf.close();
            remove("Bookdata.txt");
            rename("temp.txt", "Bookdata.txt");
        }

        // If you type the wrong choice to search
        else {
            cout << "\n\n\t\tYou type the wrong choice...";
            cout << "\n\nPress any key to continue...";
            getch();
            system("cls");
            modify();
        }

        //If the book not found or you type the id or the name wrong.
        if (cont==0) {
            cout << "\n\n\t\tBook Not Found";
            cout << "\n\nPress any key to continue...";
            getch();
            system("cls");
            modify();
        }

        //Success in deleting the data
        else {
        cout<<"\n\n\t\tDelete Successfully";
        }
    }

    else if (i==4) {
        system("cls");
        open();
    }

    else
    {
        cout << "\n\n\t\tPlease enter correct option...";
        cout << "\n\n\t\tPress any key to continue...";
        getch();
        system("cls");
        modify();
    }
    
    cout<<"\n\t\tPress any key to continue.....";
    getch();
    system("cls");
    open();
}

//To add the data of the book
void Librarian::getdata(){
    int i;
    fflush(stdin);
    cout << "\n\t\tEnter the Book's details";
    cout << "\n\n\t\tEnter Book's name / title : ";
    cin.getline(bookname, 100);
    //change the title to binary so we can input it to the file
    //why using binary, because in the program, we open the file with open binary
    for(i=0; bookname[i]!='\0'; i++) {
        if(bookname[i]>='a' && bookname[i]<='z') {
            bookname[i]-=32;
        }
    }

    cout << "\n\t\tEnter Author's name : ";
    cin.getline(authorname, 50);

    cout << "\n\t\tEnter Publication name : ";
    cin.getline(sc1, 50);

    cout << "\n\t\tEnter Book's ID : ";
    cin.getline(sc,20);

    cout << "\n\t\tEnter Book's Price : ";
    cin >> p;

    cout << "\n\t\tEnter Book's Quantity : ";
    cin >> q; 
}

//PROGRAM TO ISSUE THE BOOK
void Librarian::issue() {
    char st[50], st1[20]; //student ID and book ID variable (for reissue)
    int b,i,j;
    int d,m,y, dd,mm,yy; //For date
    int cont=0;

    system("cls");
    cout << "\n\t\tPlease Choose One Option\n";
    cout << "\n\n\t\t1. Issue Book";
    cout << "\n\n\t\t2. View Issue Book";
    cout << "\n\n\t\t3. Reissue Book";
    cout << "\n\n\t\t4. Return Book";
    cout << "\n\n\t\t5. Go Back to Home Page";

    cout << "\n\n\n\t\tEnter your choice : ";
    cin >> i;

    fflush(stdin);

    //Issue Book (Student Borrowing Book)
    if (i==1) {
        system("cls");
        b = branch();
        system("cls");
        fflush(stdin);
        cout << "\n\n\t\t->Please Enter the Detail<-";

        cout << "\n\n\t\tEnter Bookname : ";
        cin.getline(bookname,100);

        cout << "\n\n\t\tEnter Book's ID : ";
        cin.getline(sc,20);
        der(sc, b, 1);

        cout << "\n\n\t\tEnter Student's Name : ";
        cin.getline(authorname, 100); //using authorname variable more efficient than making new variable studentname

        cout << "\n\n\t\tEnter Student's ID : ";
        cin.getline(sc1, 20); //using sc1 (book's id variable) to efficiency

        cout << "\n\n\t\tEnter date (dd mm yy) : ";
        cin >> q >> B >> p; //more efficient using exist variable

        ofstream outf("student.txt", ios::binary|ios::app);
        outf.write((char*)this,sizeof(*this));
        outf.close();
        cout << "\n\n\n\t\t\tIssue Successfully";
    }

    //Listing the detail issue Book
    if (i==2) {
        ifstream intf("student.txt", ios::binary|ios::app);
        system("cls");
        cout << "\n\n\t\t->Issue Detail<-";
        intf.read((char*)this,sizeof(*this));
        i = 0;
        while(!intf.eof()) {
            i++;
            cout << "\n\t\t********** " << i << "**********\n";
            cout << "\n\t\tStudent Name : " << authorname;
            cout << "\n\t\tStudent's ID : " << sc1;
            cout << "\n\t\tBook Name/Title : " << bookname;
            cout << "\n\t\tBook's ID : " << sc;
            cout << "\n\t\tDate : " << q << "/" << B << "/" << p << endl;
            intf.read((char*)this,sizeof(*this));
        }
        intf.close();
    }

    //Reiissue the book, if late there is a fine to pay
    else if (i == 3) {
        system ("cls");
        fflush(stdin);

        cout << "\n\n\t\t->Please Enter the Detail<-";

        cout << "\n\n\t\tEnter Student's ID : ";
        cin.getline(st, 50);

        cout << "\n\n\t\tEnter Book's ID : ";
        cin.getline(st1, 20);

        fstream intf("student.txt", ios::in|ios::out|ios::ate|ios::binary);
        intf.seekg(0);
        intf.read((char*)this,sizeof(*this));
        while(!intf.eof()){
            for(i=0; sc[i]!='\0' && st1[i]!='\0' && st1[i]==sc[i]; i++);
                for(j=0; sc1[j]!='\0' && st[j]!='\0' && st[j]==sc1[j]; j++);
                    if(sc[i]=='\0' && sc1[j]=='\0' && st[j]=='\0' && st1[i]=='\0') {
                        d=q;
                        m=B;
                        y=p;
                        cout<<"\n\t\tEnter New Date : ";
                        cin>>q>>B>>p;
                        fine(d,m,y,q,B,p); //fn1
                        int u = intf.tellp();
                        intf.seekp(u - sizeof(*this)); //fn3
                        intf.write((char*)this,sizeof(*this)); //fn5
                        cout<<"\n\n\t\tReissue successfully."; //fn3
                        break;
                }
            intf.read((char*)this,sizeof(*this));
        }
        intf.close();
    }

    //
    else if (i==4) {
        system("cls");
        b=branch();
        system("cls");
        fflush(stdin);

        cout << "\n\n\t\t->Please Enter the Detail<-";

        cout << "\n\n\t\tEnter Book's ID : ";
        cin.getline(st1, 20);
        der(st1, b, 2);

        cout << "\n\n\t\tEnter Student's ID : ";
        cin.getline(st, 50);

        cout << "\n\n\t\tEnter Present Date : ";
        cin >> d >> m >> y;

        ofstream outf("temp.txt", ios::app|ios::binary);
        ifstream intf("student.txt", ios::binary);
        intf.read((char*)this,sizeof(*this));
        while(!intf.eof()){
            for(i=0; sc[i]!='\0' && st1[i]!='\0' && st1[i]==sc[i]; i++);
                for(j=0; sc1[j]!='\0' && st[j]!='\0' && st[j]==sc1[j]; j++);
                    if(sc[i]=='\0' && sc1[j]=='\0' && st[j]=='\0' && st1[i]=='\0' && cont==0) {
                        cont++;
                        intf.read((char*)this,sizeof(*this));
                        fine(q,B,p,d,m,y);
                        cout<<"\n\t\tReturned successfully.";
                    }

                    else {
                        outf.write((char*)this,sizeof(*this));
                        intf.read((char*)this,sizeof(*this));
                    }
        }

        intf.close();
        outf.close();
        getch();
        remove("student.txt");
        rename("temp.txt","student.txt");
    }

    else if(i==5) {
        system("cls");
        open();
    }

    else {
        cout << "\n\t\tWrong Input...";
    }

    cout << "\n\n\t\tPress any key to continue...";
    getch();
    system("cls");
    open(); 
}

// To calculate the fine (fine is for reissue or return late)
void Librarian::fine(int d, int m, int y, int dd, int mm, int yy){
    long int n1, n2;
    int difference;
    int years, l, i;
    const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    //count for how many days
    n1 = y*365 + d;
    for (i=0; i < m-1; i++) {
        n1 += monthDays[i]; //fn1353
    }
    years = y;

    //leap year
    if(m <= 2) {
        years--;
    }
    l = years / 4 - years / 100 + years / 400;

    n1 += l;        //days

    //count days for the new date
    n2 = yy*365 + dd;
    for (i=0; i<mm-1; i++) {
        n2 += monthDays[i];
    }
    years == yy;

    if (m<=2){
        years = yy;
    }
    l = years / 4 - years / 100 + years / 400;

    n2 += l;        //days

    n1 = n2-n1;     //the differences of days

    //fine
    n2 = n1-15;

    if (n2>0) {
        cout << "\n\t\tTotal Fine is : " << n2;
    }
}

//To Decrease the quantity the book
void Librarian::der(char st[], int b, int x){
    int i,cont=0;

    fstream intf("Bookdata.txt",ios::in|ios::out|ios::ate|ios::binary);
    intf.seekg(0);
    intf.read((char*)this,sizeof(*this));

    while(!intf.eof()) {
        for(i=0;b==B&&sc[i]!='\0'&&st[i]!='\0'&&st[i]==sc[i];i++);
            if(sc[i]=='\0'&&st[i]=='\0') {
                cont++;
                if(x==1) {
                    q--;
                }
                else {
                    q++;
                }
            int u = intf.tellp();
            intf.seekp(u - sizeof(*this));
            intf.write((char*)this,sizeof(*this));
            break;
            }
        intf.read((char*)this,sizeof(*this));
    }
    if (cont==0) {
        cout << "\n\t\t Book not Found\n";
        cout << "\n\n\t\tPress any key to continue...";
        getch();
        system("cls");
        issue();
    }
    intf.close();
}


// To open category of the book
int Librarian::branch()
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
    Librarian lib;

    lib.open();
    getch();
    return 0;
}
