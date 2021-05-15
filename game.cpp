//*Be Name Khoda*//
#include<iostream>
#include<conio.h>
#include<string>
#include<stdlib.h>  //_sleep()
using namespace std;

/////////////////////////////////////// Class
class bazi{
	private:
		char **p;        //zamin bazi
		int n,m;        //n=satr m=soton
		int xa,ya,xb,yb;   // A=(xa,ya) , B=(xb,yb)
		int s,scA,scB;   //scA=score A , scB=score B  , s=star ha
		int nb;    //nb=nobat bazikon
		string a,b;   //a=name player A , b=name player B
	public:
		bazi();
		~bazi() {cout<<"\n\nProgrammer:\n\t    Mehdi Dehqan;\n\t    Mahmood Parsa;";_sleep(2000);}
		void name();  //name player
		void wall();  //divar #
		void star();  //setareh *
		void show();  //namayesh
		void taw();   //mohreh A,B
		void up();    
		void down();
		void left();
		void right();
};
/////////////////////////////////////// Function
////
bazi::bazi()
{
	system("cls");
	name();
	cout<<"Enter the number of Rows: ";
	cin>>n;
	cout<<"Enter the number of Column: ";
	cin>>m;
	p=new char *[n];
	for(int i=1;i<=n;i++)
	{
		p[i]=new char[m];
		for(int j=1;j<=m;j++)
		{
			p[i][j]='-';
		}
	}
	system("cls"); show();
	wall();
	system("cls"); show();
    star();
    system("cls"); show();
    taw();
    system("cls"); show();
    
    scA=scB=0;
    nb=1;
    while((scA+scB)!=s)
    {
q:		cout<<"\nScore \'"<<a<<"\'(A)=("<<scA<<")"<<"\n\nScore \'"<<b<<"\'(B)=("<<scB<<")\n\n\n";
		cout<<"\t8"<<endl<<"     4     6"<<endl<<"\t2"<<endl;
		
    	if(nb%2 != 0)
		   cout<<"\nEnter Shift (A)=> ";
		else
		   cout<<"\nEnter Shift (B)=> ";
		      
        char hb = _getch();
        switch(hb)
        {
        	case '8':
				up();
				break;
			case '2':
				down();
				break;
			case '6':
				right();
				break;
			case '4':
				left();
				break;	
			default:
				system("cls");
				show();
				cout<<'\a'; goto q;
        }
        system("cls");
        show();
        nb++;
    }
    system("cls");
    
    if(scA>scB) {cout<<"*";_sleep(350);cout<<"**";_sleep(450);cout<<"*** ";_sleep(450);cout<<"Winner Player \'"<<a<<"\'(A) ";_sleep(350);cout<<"*";_sleep(350);cout<<"**";_sleep(450);cout<<"*** ";} 
    else if(scA<scB) {cout<<"*";_sleep(350);cout<<"**";_sleep(450);cout<<"*** ";_sleep(450);cout<<"Winner Player \'"<<b<<"\'(B) ";_sleep(350);cout<<"*";_sleep(350);cout<<"**";_sleep(450);cout<<"*** ";} 
    else {cout<<"Equal (A=B)";} 
    _sleep(1000);
}
////
/////////////
void bazi::name()
{
	cout<<"Enter Name player A: ";
	cin>>a;
	cout<<"Enter Name player B: ";
	cin>>b;
	system("cls");
}
/////////////
void bazi::show()
{
a:	cout<<"================";
	for(int i=1;i<=m;i++)
	{
		cout<<"====";
	}
b:	cout<<"=============\n";
	for(int i=1;i<=n;i++)
	{
		cout<<endl<<"  \t\t";
		for(int j=1;j<=m;j++)
		{
			cout<<p[i][j]<<"   ";
		}
		cout<<"\n\n";
	}
	cout<<"================";
	for(int i=1;i<=m;i++)
	{
		cout<<"====";
	}
	cout<<"=============\n";
}
///////////// #
void bazi::wall()
{
	int w,wx,wy;
	cout<<"\nEnter the Number of Wall: ";
	cin>>w;
	for(int i=1;i<=w;i++)
	{
		system("cls");
		show();
		cout<<"\nNumber of Wall ("<<i<<")";
		cout<<"\n------------------\n";
		cout<<"Enter x,y: ";
		cin>>wx;
		cout<<"\t   ";
		cin>>wy;
		p[wx][wy]='#';
	}
}
///////////// *
void bazi::star()
{
	int sx,sy;
	cout<<"\nEnter the Number of star: ";
	cin>>s;
	for(int i=1;i<=s;i++)
	{
		system("cls");
		show();
		cout<<"\nNumber of Star ("<<i<<")";
		cout<<"\n------------------\n";
		cout<<"Enter x,y: ";
		cin>>sx;
		cout<<"\t   ";
		cin>>sy;
		p[sx][sy]='*';
	}
}
///////////// A,B
void bazi::taw()
{
	cout<<"\n Taw \'"<<a<<"\'(A)\n-----";
	cout<<"\nEnter Xa: ";
	cin>>xa;
	cout<<"Enter Ya: ";
	cin>>ya;
	p[xa][ya]='A';
		
	cout<<"\n Taw \'"<<b<<"\'(B)\n-----";
	cout<<"\nEnter Xb: ";
	cin>>xb;
	cout<<"Enter Yb: ";
	cin>>yb;
	p[xb][yb]='B';
}
///////////// -> <- 
void bazi::up()
{
	if(nb%2 != 0) //Player A
	{
		for(int i=xa;i>=1;i--)
		{
			if(p[i][ya]=='*')
			{
				p[i][ya]='-';
				scA++;
			}
			
			if( (i==1) || (p[i-1][ya]=='#') || (p[i-2][ya]=='#'&&p[i-1][ya]=='B') || (p[1][ya]=='B'&&p[i-1][ya]=='B') )
			{
				p[xa][ya]='-';
				p[i][ya]='A';
				xa=i;
				break;
			}
		}
	}
	//**
	if(nb%2 == 0) //Player B
	{
		for(int i=xb;i>=1;i--)
		{
			if(p[i][yb]=='*')
			{
				p[i][yb]='-';
				scB++;
			}
			
			if( (i==1) || (p[i-1][yb]=='#') || (p[i-2][yb]=='#'&&p[i-1][yb]=='A') || (p[1][yb]=='A'&&p[i-1][yb]=='A') )
			{
				p[xb][yb]='-';
				p[i][yb]='B';
				xb=i;
				break;
			}
		}
	}
}
/////////////
void bazi::down()
{
	if(nb%2 != 0) //Player A
	{
		for(int i=xa;i<=n;i++)
		{
			if(p[i][ya]=='*') {p[i][ya]='-'; scA++;}
			//*
			if(p[i][ya]=='#')
			{
				if(p[i-1][ya]=='B')
				{
					p[xa][ya]='-';
					p[i-2][ya]='A';
					xa=i-2;
				}
				else
				{
					p[xa][ya]='-';
					p[i-1][ya]='A';
					xa=i-1;
				}
				break;
			}
			//*
			if(i==n || (p[n][ya]=='B'&&p[i+1][ya]=='B'))
			{
				p[xa][ya]='-';
				p[i][ya]='A';
				xa=i;
				break;
			}
		}
	}
	//**
	if(nb%2 == 0) //Player B
	{
		for(int i=xb;i<=n;i++)
		{
			if(p[i][yb]=='*') {p[i][yb]='-'; scB++;}
			//*
			if(p[i][yb]=='#')
			{
				if(p[i-1][yb]=='A')
				{
					p[xb][yb]='-';
					p[i-2][yb]='B';
					xb=i-2;
				}
				else
				{
					p[xb][yb]='-';
					p[i-1][yb]='B';
					xb=i-1;
				}
				break;
			}
			//*
			if(i==n || (p[n][yb]=='A'&&p[i+1][yb]=='A'))
			{
				p[xb][yb]='-';
				p[i][yb]='B';
				xb=i;
				break;
			}	
		}
	}
}
/////////////
void bazi::right()
{
	if(nb%2 != 0) //Player A
	{
		for(int i=ya;i<=m;i++)
		{
			if(p[xa][i]=='*')
			{
				p[xa][i]='-';
				scA++;
			}
			
			if( (i==m) || (p[xa][i+1]=='#') || (p[xa][i+2]=='#'&&p[xa][i+1]=='B') || (p[xa][m]=='B'&&p[xa][i+1]=='B') )
			{
				p[xa][ya]='-';
				p[xa][i]='A';
				ya=i;
				break;
			}
		}
	}
	//**
	if(nb%2 == 0) //Player B
	{
		for(int i=yb;i<=m;i++)
		{
			if(p[xb][i]=='*')
			{
				p[xb][i]='-';
				scB++;
			}
			
			if( (i==m) || (p[xb][i+1]=='#') || (p[xb][i+2]=='#'&&p[xb][i+1]=='A') || (p[xb][m]=='A'&&p[xb][i+1]=='A') )
			{
				p[xb][yb]='-';
				p[xb][i]='B';
				yb=i;
				break;
			}
		}
	}
}
/////////////
void bazi::left()
{
	if(nb%2 != 0) //Player A
	{
		for(int i=ya;i>=1;i--)
		{
			if(p[xa][i]=='*')
			{
				p[xa][i]='-';
				scA++;
			}
			
			if( (i==1) || (p[xa][i-1]=='#') || (p[xa][i-2]=='#'&&p[xa][i-1]=='B') || (p[xa][1]=='B'&&p[xa][i-1]=='B') )
			{
				p[xa][ya]='-';
				p[xa][i]='A';
				ya=i;
				break;
			}
		}
	}
	//**
	if(nb%2 == 0) //Player B
	{
		for(int i=yb;i>=1;i--)
		{
			if(p[xb][i]=='*')
			{
				p[xb][i]='-';
				scB++;
			}
			
			if( (i==1) || (p[xb][i-1]=='#') || (p[xb][i-2]=='#'&&p[xb][i-1]=='A') || (p[xb][1]=='A'&&p[xb][i-1]=='A') )
			{
				p[xb][yb]='-';
				p[xb][i]='B';
				yb=i;
				break;
			}
		}
	}
}

/////////////////////////////////////// Main
int main()
{
	cout <<"Press any key to play game . . .";
	char ch = _getch();
	
r:	system("cls");
	cout<<"###############\n#    Menu     #\n# ----------- #\n# 1.New Game  #\n# 2.Premise   #\n# 3.Help      #\n# 4.Exit      #\n###############\n";
	char cha=_getch();
	
	if(cha=='1') {bazi G;}
	else if(cha=='4') {system("cls"); cout<<"\'You are out of the game\' \nProgrammer:\n\t   Mehdi Dehqan;\n\t   Mahmood Parsa;";exit(0);}
	//else if(cha=='2')
	//else if(cha=='3')
	else {goto r;}
	
	goto r;
	
	getch();
}

//METI,meti
