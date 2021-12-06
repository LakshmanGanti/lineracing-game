#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;

struct nodel
{
    char data;
    struct nodel *next;

}*p=NULL,*start=NULL;

 struct node1
{
    char data1;
    struct node1 *next1;

}*p1=NULL,*start1=NULL;

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void inserte(char x)
{
    struct nodel* ptr = (struct nodel*)malloc(sizeof(struct nodel));
     ptr->data=x;
    if(p==NULL)
    {
        p=ptr;
        p->next=NULL;

    }
    else {
        start=p;// Start is used to keep the track of first pointer, after ending of this part we will point p to start
        while(p->next!=NULL)
        {

            p=p->next;

        }
        p->next=ptr;
        ptr->next=NULL;
        p=start;
    }
}
void inserte1(char x)
{
   struct node1* ptr1 = (struct node1*)malloc(sizeof(struct node1));

    ptr1->data1=x;
    if(p1==NULL)
    {
        p1=ptr1;
        p1->next1=NULL;

    }
    else {
            start1=p1;// Start is used to keep the track of first pointer, after ending of this part we will point p to start
        while(p1->next1!=NULL)
        {

            p1=p1->next1;

        }
        p1->next1=ptr1;
        ptr1->next1=NULL;
        p1=start1;
    }
}

void display()
{

    start=p;// Start is used to keep the track of first pointer, after ending of this part we will point p to start
    cout<<"\t";
    while(p!=NULL)
    {
        printf("%c ",p->data);
        p=p->next;
    
    }
    p=start;
    printf("\n");

}
void display1()
{
    start1=p1;// Start is used to keep the track of first pointer, after ending of this part we will point p to start
    cout<<"\t";
    while(p1!=NULL)
    {
        printf("%c ",p1->data1);
        p1=p1->next1;

    }
    p1=start1;
    printf("\n");     

}

void SetColor(int ForgC)
 {
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

                  //We use csbi for the wAttributes word.
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                 //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
 }
 


int main(){

    system("cls");
    SetColor(4);
    cout<<"\n\t\t\t#            ###########    #       #     ########            ######         #      #########   #######   ###########  #        #    #####";
    cout<<"\n\t\t\t#                 #         ##      #     #                   #      #      # #     #           #              #       ##       #   #     #";
    cout<<"\n\t\t\t#                 #         #  #    #     #                   #      #     #   #    #           #              #       #  #     #   #      ";
    cout<<"\n\t\t\t#                 #         #    #  #     #####               #######     #     #   #           #####          #       #    #   #   #  ####";
    cout<<"\n\t\t\t#                 #         #     # #     #                   #    #      #######   #           #              #       #      # #   #      #";
    cout<<"\n\t\t\t#                 #         #      ##     #                   #      #    #     #   #           #              #       #       ##   #      #";
    cout<<"\n\t\t\t##########   ###########    #       #     ########            #       #   #     #   #########   ########  ###########  #        #    ######";
    cout<< "\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t ";
    SetColor(2);
    string q = "=== WELCOME TO LINE RACING ===";
    for(int i=0;i<q.size();i++){
        cout<<q[i];
        delay(120);
    }
    cout<<endl<<endl;
    char z;
    SetColor(5);
    cout<<"\t\t\t\t\t->  This is the 2 Player racing game based on luck,i.e throw of a dice.\n\t\t\t\t\t->  Each player is given a chance to roll the dice, and accordingly character is advanced in line.\n\t\t\t\t\t->  The player whose character reaches the end 1st, is declared as winner. "<<endl<<endl;
    SetColor(6);
    cout<<"\t\t\t\tPress any letter to continue : ";
    cin>>z;
    system("cls");
    for(int i=0;i<30;i++)
    {   
        if(i==0)
        {
            inserte('|');
        }
       else 
       {
           inserte('_');
       }
    }
    for(int i=0;i<30;i++){
        if(i==0)
        {
            inserte1('|');
        }
       else
       {
           inserte1('_');
       }
    }

    int count =0;
    string s;
    string s1;
    SetColor(4);
    cout<<"\n\t\tEnter name for player 1 : ";
    SetColor(1);
    getline(cin>>ws,s);
    SetColor(4);
    cout<<"\n\t\tEnter name for player 2 : ";
    SetColor(1);
    getline(cin>>ws,s1);
    system("cls");

    while(1)
    {
        string s3 = "......";
        if((count%2)==0)
        {   char ch;
            int flag=0;
            cout<<"\n\t";
            cout<<s<<" , Your turn"<<endl;
            do
            {cout<<"\n\tPress 'y' to roll your dice, Press 'n' to pass : ";
            cin>>ch;
            }while(ch!='n'&&ch!='y');
            if(ch=='n')
                cout<<"\n\tYour turn is passed!!"<<endl;
            if(ch=='y')
            {

                srand (time(NULL));  //Random number generator
                int x = rand()%6;
                x = x+1;
                
                cout<<"\tYour Dice Number ";
                for(int i=0;i<6;i++)
                {
                    delay(200);    //Time gap function between printing each character
                    cout<<s3[i];
                }
                cout<<" : "<<x<<endl;
                Beep(850, 800);  //Function that generates sound and parameters are frequency and time(sec)
                start= p;
                int count1=1,flag1=0,c,flag2=0;
                while(p->next!=NULL)
                {   count1++;
                    if(p->data=='|')
                        {p->data='_';
                         c = count1;
                   flag2=1; }
                    else {

                        if(((x+c)==count1)&&flag2==1)
                        {
                            p->data='|';
                            flag1=1;
                            break;
                        }
                    }
                    p=p->next;

                }

                p=start;
                cout<<"\n\tStatus of "<<s<<"'s line : "<<endl;
                SetColor(6);
                display();
                SetColor(1);
                cout<<endl;
                cout<<"\n\tStatus of "<<s1<<"'s line : "<<endl;
                SetColor(3);
                display1();
                SetColor(1);

                if(flag1==0)
                {
                    cout<<"!!GAME OVER!!"<<endl;
                    cout<<s<<" WON!!"<<endl;
                    delay(3000);
                    break;
                }
                cout<<endl;
                delay(3000);
            }
          system("cls");
        }

     else
        {
         char ch;
            int flag=0;
            cout<<"\n\t";
            cout<<s1<<" , Your turn"<<endl;
            do
            {
                cout<<"\n\tPress 'y' to roll your dice, Press 'n' to pass : ";
                cin>>ch;
            
            }while(ch!='n'&&ch!='y');
            if(ch=='n'){
                cout<<"\n\tYour turn is passed!!"<<endl;
            }
            if(ch=='y')
            {

                srand (time(NULL));
                int x = rand()%6;
                x = x+1;
                cout<<"\tYour Dice Number ";
                for(int i=0;i<6;i++)
                {
                    delay(200);
                    cout<<s3[i];
                }
                cout<<" : "<<x<<endl;
                Beep(850, 800);
                start1= p1;
                int count1=1,flag1=0,c,flag2=0;
                while(p1->next1!=NULL)
                {   count1++;
                    if(p1->data1=='|')
                        {p1->data1='_';
                         c = count1;
                   flag2=1; }
                    else {

                        if(((x+c)==count1)&&flag2==1)
                        {
                            p1->data1='|';
                            flag1=1;
                            break;
                        }
                    }
                    
                    p1=p1->next1;

                }

                p1=start1;
                cout<<"\n\tStatus of "<<s<<"'s line : "<<endl;
                SetColor(6);
                display();
                SetColor(1);
                cout<<endl;
                cout<<"\n\tStatus of "<<s1<<"'s line : "<<endl;
                SetColor(2);
                display1();
                SetColor(1);
                if(flag1==0)
                {   cout<<endl;
                    cout<<"!!GAME OVER!!"<<endl;
                    cout<<s1<<" WON!!"<<endl;
                    delay(3000);
                    break;
                }
                cout<<endl;
                delay(3000);
            }
           system("cls");
        }
     count++;
    }   

    return 0;
}