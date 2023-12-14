#include<stdio.h>
#include <string.h>
#include<conio.h>
#include<stdlib.h>

int d,m,y;
int d1,m1,y1;

void destination();
void Khagrasory();
void Bandarban();
void Rajshahi();
void Chittagong();
void Khulna();
void Rangamati();
void Bogura();
void print_details();
void print_ticket(int [],int);
void input(int,int );
int check(int);
void flights(int );
void hotels();
int menu();

struct info
{
	int age;
	int cost;
	int days;
	char hname[30];
	char destination[15];
	char name[30];
	char gender;
	float time;
	char fname[30];
	char shift[2];
} i;


void print_details()
{
	system("cls");
	int id,no,flag=0;
	printf("\n\t TRAVELLERS DETAILS :\n");
	printf(" \nENTER ID OF THE PERSON YOU ARE SEARCHING FOR :  ");
	scanf("%d", &id);
		FILE *f;
	while (!feof(f))
	{
			fscanf(f,"%d %s %d %c %d %s %s %f %s  %d %d %d %d %d %d %s",&no,&i.name,&i.age,&i.gender,&i.cost,&i.destination,&i.fname,&i.time,&i.shift,&d,&m,&y,&d1,&m1,&y1,&i.hname);

		if(id==no)
		{
		printf("\n\n\tID : %d",no);
		printf("\n\tNAME : %s\t\t HOTEL NAME : %s ", i.name,i.hname);
		printf("\n\tAGE : \t%d\t\t CHECKIN : %d/%d/%d ",i.age,d,m,y);
		printf("\n\tGENDER : %c\t \t CHECKOUT : %d/%d/%d", i.gender,d1,m1,y1);
        printf("\n\tDESTINATION : %s",i.destination);
        printf("\n\tFLIGHT NAME : %s",i.fname);
        printf("\n\tDEPARTURE TIME : %f %s",i.time,i.shift);
        printf("\nPress enter to continue .....");
	flag=1;
		}
     if(flag==1)
     break;
           }
	fclose(f);
	if(flag==0)
	{
		printf("\nNo bill exists.");
		printf("\nPress enter to continue .....");

	}
}


void print_ticket(int a[],int cnt)
{
	system("cls");
	int z,no,flag;
		FILE *f;
  		printf("\n\n\t YOUR TICKET:");
  for(z=0;z<cnt;++z)
  {   flag=0;
  f=fopen("info.txt", "r");
	while (!feof(f))
	{
		fscanf(f,"%d %s %d %c %d %s %s %f %s  %d %d %d %d %d %d %s",&no,&i.name,&i.age,&i.gender,&i.cost,&i.destination,&i.fname,&i.time,&i.shift,&d,&m,&y,&d1,&m1,&y1,&i.hname);
			if(a[z]==no)
		{
		printf("\n\n\tID : %d",no);
		printf("\n\tNAME : %s\t\t HOTEL NAME : %s ", i.name,i.hname);
		printf("\n\tAGE : \t%d\t\t CHECKIN : %d/%d/%d ",i.age,d,m,y);
		printf("\n\tGENDER : %c\t \t CHECKOUT : %d/%d/%d", i.gender,d1,m1,y1);
        printf("\n\tDESTINATION : %s",i.destination);
        printf("\n\tFLIGHT NAME : %s",i.fname);
        printf("\n\tDEPARTURE TIME : %f %s",i.time,i.shift);
       flag=1;
			}
     if(flag==1)
     break;
           }
  fclose(f);
  }
   printf("\n\n\t\tTOTAL COST : %ld",i.cost);
printf("\n\n\t\tBOOKING SUCCESSFULL");
   printf("\n\n\t\t   press enter to go to main menu .....");
     getchar();
menu();
}


int check(int id)
{
   int fi;
	 FILE *f1;

        f1=fopen("checkid.txt","w");

fclose(f1);

 FILE *f;
	f=fopen("checkid.txt","r+");
   while(!feof(f))
{
	fscanf(f,"%d",&fi);
	if(fi==id)
	{
	printf("\n\t ID ALDREADY EXISTS!) !\n\t CHOOSE ANOTHER ID :\n");
	return 1;
	}
}
fclose(f);
return 0;
}


void input(int cnt,int cno)
{
	int a[cnt];
	int pos=0,res;
	switch(cno)
	{
		case 1:strcpy(i.destination,     "Khagrasory");break;
		case 2:strcpy(i.destination,     "Bandarban");break;
		case 3:strcpy(i.destination,     "Rajshahi");break;
		case 4:strcpy(i.destination,    "Chittagong" );break;
		case 5:strcpy(i.destination,     "Khulna");break;
		case 6:strcpy(i.destination,     "Rangamati");break;
		case 7:strcpy(i.destination,    "Bogura" );break;
	}
	int x=0,id;
	while(x<cnt)
		{
		system("cls");
			printf("\n\t\t ENTER %d PERSON DETAILS",x+1);
		a:
		printf("\n\n\t TRAVEL ID (1-100) : ");
	scanf("%d",&id);
	res=check(id);
	if(res==1)
	goto a;
	printf("\n\t    ENTER  NAME , AGE , GENDER (M/F)  :\n\n");
	FILE *f;
	f=fopen("info.txt","a+");
	printf("\t    ");
	scanf("%s", &i.name);
	printf("\t    ");
	scanf("%d",&i.age);
	printf("\t    ");
	getchar();
    i.gender=getchar();
    printf("\n\n\t\t   press enter to continue .....");
     getchar();
	getchar();
	flights(id);
	hotels();
	fprintf(f,"%d %s %d %c %d %s %s %f %s ",id,i.name,i.age,i.gender,i.cost,i.destination,i.fname,i.time,i.shift);
	fprintf(f," %d %d %d %d %d %d %s\n",d,m,y,d1,m1,y1,i.hname);
      fclose(f);
      a[x]=id;
      ++x;
		}
	print_ticket(a,cnt);
}


void hotels()
{
	int n;

  system("cls");
	printf("\n\t\t HOTELS :");
	printf("\n\n\t1. PAN PACIFIC SONARGAON\t           PRICE : 20,000 TK PER DAY");
	printf("\n\n\t2. INTERCONTINENTAL DHAKA\t          PRICE : 19,500 TK PER DAY");
	printf("\n\n\t3. THE WESTIN DHAKA\t                PRICE : 17,000 TK PER DAY");
	printf("\n\n\t4. RADISSON BLU WARTE GARDEN HOTEL\t PRICE : 17,500 TK PER DAY");
	printf("\n\n\t5. LE MERIDIEN\t                     PRICE : 18,000 TK PER DAY");
	printf("\n\n\t6. HOTEL SARINA\t                    PRICE : 16,000 TK PER DAY");
    printf("\n\n\t7. SEAGULL HOTEL LIMITED\t           PRICE : 16,500 TK PER DAY");
	printf("\n\n\t8. SEA PEARL BEACH RESORT\t          PRICE : 15,000 TK PER DAY");
	printf("\n\n\t9. DOREEN HOTELS & RESORTS\t         PRICE : 15,500 TK PER DAY");
	printf("\n\n\t10. THE PALACE LUXURY RESORT\t       PRICE : 18,500 TK PER DAY");
	printf("\n\n\t ENTER CHOICE :  ");
	scanf("%d", &n);
	printf("\n\n\t ENTER NO OF DAYS : ");
	scanf("%d",&i.days);
		switch (n)
	{
case 1: i.cost+=i.days*20000;
strcpy(i.hname,"PAN PACIFIC SONARGAON");break;
case 2: i.cost+=i.days*19500;
strcpy(i.hname,"INTERCONTINENTAL DHAKA");break;
case 3: i.cost+=i.days*17000;
strcpy(i.hname,"THE WESTIN DHAKA");break;
case 4: i.cost+=i.days*17500;
strcpy(i.hname,"RADISSON BLU WARTE GARDEN HOTEL");break;
case 5: i.cost+=i.days*18000;
strcpy(i.hname,"LE MERIDIEN");break;
case 6: i.cost+=i.days*16000;
strcpy(i.hname,"HOTEL SARINA");break;
case 7: i.cost+=i.days*16500;
strcpy(i.hname,"SEAGULL HOTEL LIMITED");break;
case 8: i.cost+=i.days*15000;
strcpy(i.hname,"SEA PEARL BEACH RESORT");break;
case 9: i.cost+=i.days*15500;
strcpy(i.hname,"DOREEN HOTELS & RESORTS");break;
case 10: i.cost+=i.days*18500;
strcpy(i.hname,"THE PALACE LUXURY RESORT");break;
	}
	printf("\n\t ENTER DATE OF CHECKIN : ");
	scanf("%d",&d);
	printf("\n\t ENTER MONTH OF CHECKIN : ");
	scanf("%d",&m);
	printf("\n\t ENTER YEAR OF CHECKIN : ");
	scanf("%d",&y);

	d1=d+i.days;
	m1=m;
	y1=y;
	if(d1>31)
	{
		d1=d1-31;
		m1+=1;
		if(m1>12)
		{
			m1=m1-12;
			y1+=1;
		}
	}
printf("\n\n\t\t   press enter to continue .....");
	getchar();
	getchar();
}



void flights(int id)
	{
		int choice;
	printf("\n\n\t\t FLIGHTS AVAILABLE : ");
	printf("\n\n    1. BIMAN AI:        DEPARTURE : 6.00 AM  PRICE : 14,000 TK");
	printf("\n    2. US-BANGLA:       DEPARTURE : 9.00 AM  PRICE : 15,000 TK");
			printf("\n    3. QATAR AIRWAYS :  DEPARTURE : 1.00 PM  PRICE : 14,500 TK");
		printf("\n    4. NOVIAIR:         DEPARTURE : 5.00 PM  PRICE : 13,000 TK");
		printf("\n    5. SAUDIA :         DEPARTURE : 9.00 PM  PRICE : 13,500 TK");
		printf("\n\n\t ENTER CHOICE :  ");
		scanf("%d",&choice);
		switch(choice)
		{
case 1: i.cost+=14000;
i.time=6.00;
strcpy(i.shift,"AM");
strcpy(i.fname,"BIMAN AI");break;
case 2: i.cost+=15000;
i.time=9.00;
strcpy(i.shift,"AM");
strcpy(i.fname,"US-BANGLA");break;
case 3: i.cost+=14500;
i.time=1.00;
strcpy(i.shift,"PM");
strcpy(i.fname,"QATAR_AIRWAYS");break;
case 4: i.cost+=13000;
i.time=5.00;
strcpy(i.shift,"PM");
strcpy(i.fname,"NOVIAIR");break;
case 5: i.cost+=13500;
i.time=9.00;
strcpy(i.shift,"PM");
strcpy(i.fname,"SAUDIA");break;
}
	  FILE *p;
       p=fopen("checkid.txt","a+");      fprintf(p,"%d \n",id);
        fclose(p);
        printf("\n\n\t\t   press enter to continue .....");
	getchar();
	getchar();

}


void destination()
{
	system("cls");
	int n;
	printf("\n\t DESTINATION :");
	printf("\n\n\t 1. Khagrasory");
	printf("\n\n\t 2. Bandarban");
	printf("\n\n\t 3. Rajshahi");	printf("\n\n\t 4. Chittagong");
	printf("\n\n\t 5. Khulna");
	printf("\n\n\t 6. Rangamati");
	printf("\n\n\t 7. Bogura");
		printf("\n\n\t ENTER CHOICE :  ");
	scanf("%d", &n);
	switch (n)
	{
	case 1:Khagrasory();break;
	case 2:Bandarban();break;
	case 3:Rajshahi();break;
	case 4:Chittagong();break;
	case 5:Khulna();break;
	case 6:Rangamati();break;
	case 7:Bogura();break;
	}
}


void Khagrasory()
{
	int cnt;
	system("cls");
	printf("\n\t\t\t\t\t*****  WELCOME TO Khagrasory  *****\n");
printf("\n\t\t    ENTER NO. OF PEOPLE ");
    scanf("%d",&cnt);
	input(cnt,1);
}

void Bandarban()
{
	int  cnt;
	system("cls");
	printf("\n\t\t\t\t\t*****  WELCOME TO Bandarban  *****\n");
printf("\n\t\t    ENTER NO. OF PEOPLE ");
    scanf("%d",&cnt);
	input(cnt,2);
}

void Rajshahi()
{
	int  cnt;
	system("cls");
	printf("\n\t\t\t\t\t*****  WELCOME TO Rajshahi  *****\n");
printf("\n\t\t    ENTER NO. OF PEOPLE ");
    scanf("%d",&cnt);
	input(cnt,3);
}

void Chittagong()
{
	int  cnt;
	system("cls");
	printf("\n\t\t\t\t\t*****  WELCOME TO Chittagong  *****\n");
printf("\n\t\t    ENTER NO. OF PEOPLE ");
    scanf("%d",&cnt);
	input(cnt,4);
}

void Khulna()
{
	int  cnt;
	system("cls");
	printf("\n\t\t\t\t\t*****  WELCOME TO Khulna  *****\n");
printf("\n\t\t    ENTER NO. OF PEOPLE ");
    scanf("%d",&cnt);
	input(cnt,5);
}

void Rangamati()
{
	int  cnt;
system("cls");
	printf("\n\t\t\t\t\t*****  WELCOME TO Rangamati  *****\n");
printf("\n\t\t    ENTER NO. OF PEOPLE ");
    scanf("%d",&cnt);
	input(cnt,6);
}

void Bogura()
{
	int  cnt;
	system("cls");
	printf("\n\t\t\t\t\t*****  WELCOME TO Bogura  *****\n");
printf("\n\t\t    ENTER NO. OF PEOPLE ");
    scanf("%d",&cnt);
	input(cnt,7);
}


int menu()
{
	int n;
system("cls");
	printf("\n\tMENU :");
	printf("\n\n\t1. CHOOSE DESTINATION \n\n\t2. GENERATE BILL\n\n\t3. EXIT\n\n\tENTER CHOICE :  ");
	scanf("\n%d", &n);
	switch (n)
	{
	case 1:destination();break;
	case 2:print_details();break;
	case 3: return 0;
}
getch();
menu();
return 0;
}


int main()
{
		system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t*****************************************************\n");
    printf("\t\t\t\t\t\t*********                                  *********\n");
    printf("\t\t\t\t\t\t********   Welcome to the Travel Agency   ********\n");
    printf("\t\t\t\t\t\t*******                                  *******\n");
    printf("\t\t\t\t\t\t******  We are here to assist you       ******\n");
    printf("\t\t\t\t\t\t*****    with your travel plans.       *****\n");
    printf("\t\t\t\t\t\t****                                  ****\n");
    printf("\t\t\t\t\t\t***        Enjoy your journey!       ***\n");
    printf("\t\t\t\t\t\t**                                  **\n");
    printf("\t\t\t\t\t\t************************************\n");
    printf("\n\n\n\t\t\t\t\t\t      ** Please Enter to Continue.....**     \n");
	getchar();
	menu();
	return 0;
}
