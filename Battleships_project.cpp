#include <iostream>
#include <stdlib.h>
#include <time.h>  
using namespace std;                                             //made by farhad and akhil


int ship_p=0,col=9,rowint,colint;												//global var declarationXD
char row='Z';

int  p_ship3[6],p_ship2[4][2],p_ship1[2][2];                    //player ships position
int p_grid[8][8],c_grid[8][8];                                 //game grids
int c_ship3[6],c_ship2[4][2],c_ship1[2][2];                    //computer ship position



class start
{
public:
int direction;													//0 is up, 1 is right, 2 is down , 3 is left
 	 start()
	 {
		for(int i=0;i<8;i++)                                         //sets p_grid and c_grid 5o blank(0) 
		for(int j=0;j<8;j++)
		{p_grid[i][j]=0;
		c_grid[i][j]=0;
	 }    
	 {
			system("cls");cout<<"\n\n\n";
              for(int i=0;i<8;i++)                                //prints grid 
            	{if(i==0){cout<<" ";
     }
				cout<<"  "<<i+1;}                                 //prints grid
              for(int i=0;i<8;i++)
              {
				  cout<<"\n"<<char('A'+i);
			  }
                 ship_place();										//remove comment later
				 ai_ship();
		}
	 }
            
      
	  void ship_place()
	  {
        				cout<<"\n\n\nYou have: 2 ships of size 2\t 1 ship of size 3\t 2 ships of size 1\n\n\n";//A is 65?(ASCII)
			
			
			                                 //Ship3 
			                                 for(int place=0;place<6;place=place+2){
						if(place==0)					 
							cout<<"\nEnter the position of one end of the size 3 boat(In CAPS , eg: 'F 7')  ";
						else  	cout<<"\n              Enter the next position of the size 3 boat ";
			 			cin>>row;cin>>col;//cin.clear();                                    //cin.clear seems necessary, dont screw with it
				check:	rowint=(int)row-65;													//converst char to int equivalent(A->0,B->1,etc)
						colint=col-1;											      		//converst col to start from 1 instead of 0
			 			 if(row>'H'||row<'A'||col<1||col>8)
				 			{
							 cout<<"\nPlease enter a valid POSITION(In CAPS , eg: 'F 7') :";
							 cin.clear();cin>>row;cin>>col;
							 goto check;
						 }
				 	
					 	else if(place==2)
						{											//CHECK THIS TOMORROW....Condn for placement
					 		if(((p_ship3[0]==rowint+1)&&(p_ship3[1]==colint))||((p_ship3[0]==rowint-1)&&(p_ship3[1]==colint))||((p_ship3[0]==rowint)&&(p_ship3[1]==colint+1))||((p_ship3[0]==rowint)&&(p_ship3[1]==colint-1)))
					 			{
								if((p_ship3[0]==rowint+1)&&(p_ship3[1]==colint))
					 				direction=0;
					 				else if((p_ship3[0]==rowint-1)&&(p_ship3[1]==colint))
					 					direction=2;
					 					else if((p_ship3[0]==rowint)&&(p_ship3[1]==colint+1))
					 						direction=3;
					 						else if((p_ship3[0]==rowint)&&(p_ship3[1]==colint-1))
					 							direction=1;
					  	
					  			if((p_ship3[1]>5&&direction==1)||(p_ship3[1]<2 &&direction==3)||(p_ship3[0]<2 &&direction==0)||(p_ship3[0]>5 &&direction==2))
									{cout<<"\nYou cannot place it in this direction, please place again : ";cin.clear();cin>>row;cin>>col;goto check;	
									}
					 			}
					 
								 else{cout<<"\nPlease enter a correct POSITION(one which is adjacent to the first position) :";
					 				cin.clear();cin>>row;cin>>col;goto check;
						 }
										}
					 
					 if(place==4)
					 { 
					 	if(((p_ship3[2]==rowint+1)&&(p_ship3[3]==colint)&&direction==0)||((p_ship3[2]==rowint-1)&&(p_ship3[3]==colint)&&direction==2)||((p_ship3[2]==rowint)&&(p_ship3[3]==colint+1)&&direction==3)||((p_ship3[2]==rowint)&&(p_ship3[3]==colint-1)&&direction==1))
					 		cout<<"ok\n";
						else {cout<<"\nPlease enter a correct POSITION(one which is ahead of the second position) :";cin.clear();cin>>row;cin>>col;goto check;}
					 }
					
					system("cls");cout<<"\n\n\n";
					p_grid[rowint][colint]=3;                                              //Sets ship position to 1
					cout<<direction<<endl;
					p_ship3[place]=rowint;                             	    //filling ship3 matrix           36.24?32?48.         ????
					p_ship3[place+1]=colint;
				for(int i=0;i<8;i++)                              	  //prints grid 
            	{if(i==0)	{cout<<" ";}
				cout<<"  "<<i+1;}                                 //prints grid
              for(int i=0;i<8;i++)
             	 {cout<<"\n"<<char('A'+i);
			  	for(int j=0;j<8;j++)
			  		{if(p_grid[i][j]==0)
			  		cout<<"  ~";
			  		else if(p_grid[i][j]==4)
			  		cout<<"  0";
			  		else if(p_grid[i][j]==5)
			  		cout<<"  +";
			  		else if(p_grid[i][j]==6)
			  		cout<<"  X";
					else  cout<<"  "<<p_grid[i][j];}}
             
			 
			 }                                                  
			 
			 
			                                           		 //ship2
			 for(int turn=0;turn<2;turn++)
			 for(int place=0;place<4;place=place+2){
						if(place==0)					 
							cout<<"\nEnter the position of one end of the size 2 boat(In CAPS , eg: 'F 7')  ";
						else  	cout<<"\nEnter the next position of the size 2 boat ";
			 			cin>>row;cin>>col;//cin.clear();
				check2:	rowint=(int)row-65;													//converst char to int equivalent(A->0,B->1,etc)
						colint=col-1;											      		//converst col to start from 1 instead of 0
			 			 if(row>'H'||row<'A'||col<1||col>8)
				 			{cout<<"\nPlease enter a valid POSITION(In CAPS , eg: 'F 7') :";
							 cin.clear();cin>>row;cin>>col;goto check2;}
				 		if(p_grid[rowint][colint]!=0)
					 	{cout<<"\nThere is already a ship at this position";
							 cin.clear();cin>>row;cin>>col;goto check2;}
							if(place==2)			
					if(((p_ship2[0][turn]==rowint+1)&&(p_ship2[1][turn]==colint))||((p_ship2[0][turn]==rowint-1)&&(p_ship2[1][turn]==colint))||((p_ship2[0][turn]==rowint)&&(p_ship2[1][turn]==colint+1))||((p_ship2[0][turn]==rowint)&&(p_ship2[1][turn]==colint-1)))
					cout<<"";
					else {cout<<"Enter the new position adjacent to the first\n\n";cin.clear();cin>>row;cin>>col;goto check2;}
					
					
					
					system("cls");cout<<"\n\n\n";
					p_grid[rowint][colint]=2;                                              //Sets ship position to 1
					cout<<direction<<endl;
					p_ship2[place][turn]=rowint;                             	    //filling ship3 matrix           24
					p_ship2[place+1][turn]=colint;
		   	 
			for(int i=0;i<8;i++)                              	  //prints grid 
            	{if(i==0)	{cout<<" ";}
				cout<<"  "<<i+1;}                                 //prints grid
              for(int i=0;i<8;i++)
             	 {cout<<"\n"<<char('A'+i);
			  	for(int j=0;j<8;j++)
			  		{if(p_grid[i][j]==0)
			  		cout<<"  ~";
			  		else if(p_grid[i][j]==4)
			  		cout<<"  0";
			  		else if(p_grid[i][j]==5)
			  		cout<<"  +";
			  		else if(p_grid[i][j]==6)
			  		cout<<"  X";
					else  cout<<"  "<<p_grid[i][j];}}
			}
                
                
                
                
                                                                    //SHIP1 DONT MESS WITH SHIP PLACE FUNCTION CALL( CAUSES BUGS)
				
				
				for(int turn=0;turn<2;turn++){
											 
							cout<<"\n\n                          Enter the position of the size 1 boat(In CAPS , eg: 'F 7')  ";
						
			 			cin>>row;cin>>col;//cin.clear();
				check1:	rowint=(int)row-65;													//converst char to int equivalent(A->0,B->1,etc)
						colint=col-1;											      		//converst col to start from 1 instead of 0
			 			 if(row>'H'||row<'A'||col<1||col>8)
				 			{cout<<"\nPlease enter a valid POSITION(In CAPS , eg: 'F 7') :";
							 cin.clear();cin>>row;cin>>col;goto check1;}
				 		if(p_grid[rowint][colint]!=0)
					 	{cout<<"\nThere is already a ship at this position";
							 cin.clear();cin>>row;cin>>col;goto check1;}
										
					
					
					system("cls");cout<<"\n\n\n";
					p_grid[rowint][colint]=1;                                              //Sets ship position to 1
					cout<<direction<<endl;
					p_ship2[0][turn]=rowint;                             	    //filling ship3 matrix           24
					p_ship2[1][turn]=colint;
		   	 
				for(int i=0;i<8;i++)                              	  //prints grid 
            	{if(i==0)	{cout<<" ";}
				cout<<"  "<<i+1;}                                 //prints grid
              for(int i=0;i<8;i++)
             	 {cout<<"\n"<<char('A'+i);
			  	for(int j=0;j<8;j++)
			  		{if(p_grid[i][j]==0)
			  		cout<<"  ~";
			  		else if(p_grid[i][j]==4)
			  		cout<<"  0";
			  		else if(p_grid[i][j]==5)
			  		cout<<"  +";
			  		else if(p_grid[i][j]==6)
			  		cout<<"  X";
					else  cout<<"  "<<p_grid[i][j];}}
			}
			    //ai_ship();      //Calls ai_ship function to place ai ships in c_grid
				
		}
				
				       //////////////////////////////////////////////AI SHIP////////////////////////////////////
				     
					 
			                                 		 
					 
					 
					 
	void ai_ship(){ 
			              //for ship3
			  
			int batman,robin,joker;                      //batman row, robin col, joker directiion
			srand (time(NULL));
			batman = rand() % 8+0;
			 robin = rand() % 8+0;
				       
			 if(batman>=2&&batman<=5&&robin>=2&&robin<=5)
				joker = rand() % 4+0;
				    	
				else if(batman<2&&robin>=2&&robin<=5)
				   	while(joker==0)
					joker = rand() % 4+0;
				else if(batman>5&&robin>=2&&robin<=5)
				    while(joker==2)
				  	joker = rand() % 4+0;
				else if(robin>5&&batman>=2&&batman<=5)
				    while(joker==1)
				    joker = rand() % 4+0;
				else if(robin<2&&batman>=2&&batman<=5)
				    while(joker==3)
				    joker = rand() % 4+0;
				    			               													//0 is up, 1 is right, 2 is down , 3 is left
				
					else if(batman<2&&robin<2)
				    	while(joker==0||joker==3)
				    	joker = rand() % 4+0;
				    else if(batman<2&&robin>5)                                   
				    	while(joker==0||joker==1)
				    	joker = rand() % 4+0;
				    else if(batman>5&&robin<2)
				    	while(joker==2||joker==3)
				    	joker = rand() % 4+0;
				   	else if(batman>5&&robin>5)
				    	while(joker==2||joker==1)
				    	joker = rand() % 4+0;
				    	
			c_grid[batman][robin]=3;c_ship3[0]=batman;c_ship3[1]=robin;
			//cout<<batman<<" "<<robin<<" "<<joker;
			if(joker==0)
				{c_grid[batman-1][robin]=3; c_grid[batman-2][robin]=3;    c_ship3[2]=batman-1; c_ship3[3]=robin; c_ship3[4]=batman-2; c_ship3[5]=robin;}
			if(joker==1)
				{c_grid[batman][robin+1]=3; c_grid[batman][robin+2]=3;    c_ship3[2]=batman; c_ship3[3]=robin+1; c_ship3[4]=batman; c_ship3[5]=robin+2;}	
			if(joker==2)
				{c_grid[batman+1][robin]=3; c_grid[batman+2][robin]=3;	  c_ship3[2]=batman+1; c_ship3[3]=robin; c_ship3[4]=batman+2; c_ship3[5]=robin;}
			if(joker==3)
				{c_grid[batman][robin-1]=3; c_grid[batman][robin-2]=3;    c_ship3[2]=batman; c_ship3[3]=robin-1; c_ship3[4]=batman; c_ship3[5]=robin-2;}		
						
			
				
				
		
		 ////////////////////////for ship2
			
			for(int num=0;num<2;num++){
			
		arrear:	while(c_grid[batman][robin]!=0)
		    	{batman = rand() % 8+0;
			     robin = rand() % 8+0;
				 }
		 	
		 	
			if(batman>=1&&batman<=6&&robin>=1&&robin<=6)
				joker = rand() % 4+0;
				    	
				else if(batman<1&&robin>=1&&robin<=6)
				   	while(joker==0)
					joker = rand() % 4+0;
				else if(batman>6&&robin>=1&&robin<=6)
				    while(joker==2)
				  	joker = rand() % 4+0;
				else if(robin>6&&batman>=1&&batman<=6)
				    while(joker==1)
				    joker = rand() % 4+0;
				else if(robin<1&&batman>=1&&batman<=6)
				    while(joker==3)
				    joker = rand() % 4+0;
				    			               													//0 is up, 1 is right, 2 is down , 3 is left
				
					else if(batman<1&&robin<1)
				    	while(joker==0||joker==3)
				    	joker = rand() % 4+0;
				    else if(batman<1&&robin>6)                                   
				    	while(joker==0||joker==1)
				    	joker = rand() % 4+0;
				    else if(batman>6&&robin<1)
				    	while(joker==2||joker==3)
				    	joker = rand() % 4+0;
				   	else if(batman>6&&robin>6)
				    	while(joker==2||joker==1)
				    	joker = rand() % 4+0;
		
			c_ship2[0][num]=batman;
			c_ship2[1][num]=robin;
			if(joker==0)
				{if(c_grid[batman-1][robin]!=0)
			 		goto arrear;
				else {c_grid[batman][robin]=2; c_grid[batman-1][robin]=2; 		c_ship2[2][num]=batman-1; c_ship2[3][num]=robin;}}	
			if(joker==1)
				{if(c_grid[batman][robin+1]!=0)
			 		goto arrear;
				else {c_grid[batman][robin]=2; c_grid[batman][robin+1]=2;		c_ship2[2][num]=batman; c_ship2[3][num]=robin+1;}}		
			if(joker==2)
				{if(c_grid[batman+1][robin]!=0)
			 		goto arrear;
				else {c_grid[batman][robin]=2; c_grid[batman+1][robin]=2; 		c_ship2[2][num]=batman+1; c_ship2[3][num]=robin;}}	
			if(joker==3)
				{if(c_grid[batman][robin-1]!=0)
			 		goto arrear;
				else {c_grid[batman][robin]=2; c_grid[batman][robin-1]=2; 		c_ship2[2][num]=batman; c_ship2[3][num]=robin-1;}}			 
				}
				

				
				
				
				
				
			//?///////////////For ship1	
			
			for(int num=0;num<2;num++){
			
			while(c_grid[batman][robin]!=0)
		    	{batman = rand() % 8+0;
			     robin = rand() % 8+0;
				 }
		 	c_ship1[0][num]=batman;
		 	c_ship1[1][num]=robin;
		 	c_grid[batman][robin]=1;}
			
		}
            
            
    };










class game{public:  
			int callr,callc,c,shotx,shoty;
			char r;
	
	int check(){if(p_ship3[0]==9&&p_ship2[0][0]==9&&p_ship2[0][1]==9&&p_ship1[0][1]==9&&p_ship1[0][0]==9)
					return 1;
				else if(c_ship3[0]==9&&c_ship2[0][0]==9&&c_ship2[0][1]==9&&c_ship1[0][1]==9&&c_ship1[0][0]==9)
					return 2;
				else return 0;}
				


	void hit(int x,int y){
			if(c_grid[x][y]==0){
			cout<<"\n   YOU MISSED";c_grid[x][y]=6;}
			
			
			if(c_grid[x][y]==1){
				cout<<"\n YOU SUNK A SIZE 1 SHIP";c_grid[x][y]=5;
				if(c_ship1[0][0]==x&&c_ship1[1][0]==y)									//9 is sunk
				{c_ship1[0][0]=9;c_ship2[1][0]=9;}
				else {c_ship1[0][1]=9;c_ship2[1][1]=9;}}
			
			
			if(c_grid[x][y]==2){
				c_grid[x][y]=4;
				if(c_ship2[0][0]==x&&c_ship2[1][0]==y)
					{if(c_grid[c_ship2[2][0]][c_ship2[3][0]]==4){
				 		c_ship2[0][0]=9;c_ship2[1][0]=9;c_ship2[3][0]=9;c_ship2[4][0]==9;	c_grid[x][y]=5;c_grid[c_ship2[2][0]][c_ship2[3][0]]=5;cout<<"\n YOU SUNK A SIZE 2 SHIP";}
				 		else cout<<"\n  IT'S A HIT!";	}
			
				else if(c_ship2[0][1]==x&&c_ship2[1][1]==y)
					{if(c_grid[c_ship2[2][1]][c_ship2[3][1]]==4){
				 		c_ship2[0][1]=9;c_ship2[1][1]=9;c_ship2[3][1]=9;c_ship2[4][1]==9;	c_grid[x][y]=5;c_grid[c_ship2[2][1]][c_ship2[3][1]]=5;cout<<"\n YOU SUNK A SIZE 2 SHIP";}
				 		else cout<<"\n  IT'S A HIT!";	}
			
				else if(c_ship2[2][0]==x&&c_ship2[3][0]==y)
					{if(c_grid[c_ship2[0][0]][c_ship2[1][0]]==4){
				 		c_ship2[0][0]=9;c_ship2[1][0]=9;c_ship2[3][0]=9;c_ship2[4][0]==9;	c_grid[x][y]=5;c_grid[c_ship2[0][0]][c_ship2[1][0]]=5;cout<<"\n YOU SUNK A SIZE 2 SHIP";}
				 		else cout<<"\n  IT'S A HIT!";	}
			
				else if(c_ship2[2][1]==x&&c_ship2[3][1]==y)
					{if(c_grid[c_ship2[0][1]][c_ship2[1][1]]==4){
				 		c_ship2[0][1]=9;c_ship2[1][1]=9;c_ship2[3][1]=9;c_ship2[4][1]==9;	c_grid[x][y]=5;c_grid[c_ship2[0][1]][c_ship2[1][1]]=5;cout<<"\n YOU SUNK A SIZE 2 SHIP";}
				 		else cout<<"\n  IT'S A HIT!";	}
			
		}
		
			if(c_grid[x][y]==3){
				c_grid[x][y]=4;
				if(c_grid[c_ship3[0]][c_ship3[1]]==4&&c_grid[c_ship3[2]][c_ship3[3]]==4&&c_grid[c_ship3[4]][c_ship3[5]]==4)
				{	cout<<"YOU HAVE SUNK THE SIZE 3 SHIP";c_grid[c_ship3[0]][c_ship3[1]]=5;c_grid[c_ship3[2]][c_ship3[3]]=5;c_grid[c_ship3[4]][c_ship3[5]]=5;}
				else cout<<"IT'S A HIT";
					}
		
	}			
	
	
	void hit1(int x, int y, int z){	if(p_grid[x][y]==0){
			cout<<"\n   COMPUTER MISSED";p_grid[x][y]=6;}
			
			
			if(p_grid[x][y]==1){
				cout<<"\n COMPUTER SUNK A SIZE 1 SHIP";p_grid[x][y]=5;
				if(p_ship1[0][0]==x&&p_ship1[1][0]==y)									//9 is sunk
				{p_ship1[0][0]=9;p_ship2[1][0]=9;}
				else {p_ship1[0][1]=9;p_ship2[1][1]=9;}}
			
			
			if(p_grid[x][y]==2){
				p_grid[x][y]=4;
				if(p_ship2[0][0]==x&&p_ship2[1][0]==y)
					{if(p_grid[p_ship2[2][0]][p_ship2[3][0]]==4){
				 		p_ship2[0][0]=9;p_ship2[1][0]=9;p_ship2[3][0]=9;p_ship2[4][0]==9;	p_grid[x][y]=5;p_grid[p_ship2[2][0]][p_ship2[3][0]]=5;cout<<"\n COMPUTER SUNK A SIZE 2 SHIP";}
				 		else cout<<"\n  COMPUTER HIT!";	}
			
				else if(p_ship2[0][1]==x&&p_ship2[1][1]==y)
					{if(p_grid[p_ship2[2][1]][p_ship2[3][1]]==4){
				 		p_ship2[0][1]=9;p_ship2[1][1]=9;p_ship2[3][1]=9;p_ship2[4][1]==9;	p_grid[x][y]=5;p_grid[p_ship2[2][1]][p_ship2[3][1]]=5;cout<<"\n COMPUTER SUNK A SIZE 2 SHIP";}
				 		else cout<<"\n  COMPUTER HIT!";	}
			
				else if(p_ship2[2][0]==x&&p_ship2[3][0]==y)
					{if(p_grid[p_ship2[0][0]][p_ship2[1][0]]==4){
				 		p_ship2[0][0]=9;p_ship2[1][0]=9;p_ship2[3][0]=9;p_ship2[4][0]==9;	p_grid[x][y]=5;p_grid[p_ship2[0][0]][p_ship2[1][0]]=5;cout<<"\n COMPUTER SUNK A SIZE 2 SHIP";}
				 		else cout<<"\n  COMPUTER HIT!";	}
			
				else if(p_ship2[2][1]==x&&p_ship2[3][1]==y)
					{if(p_grid[p_ship2[0][1]][p_ship2[1][1]]==4){
				 		p_ship2[0][1]=9;p_ship2[1][1]=9;p_ship2[3][1]=9;p_ship2[4][1]==9;	p_grid[x][y]=5;p_grid[p_ship2[0][1]][p_ship2[1][1]]=5;cout<<"\n COMPUTER SUNK A SIZE 2 SHIP";}
				 		else cout<<"\n  COMPUTER HIT!";	}
			
		}
		
			if(p_grid[x][y]==3){
				p_grid[x][y]=4;
				if(p_grid[p_ship3[0]][p_ship3[1]]==4&&p_grid[p_ship3[2]][p_ship3[3]]==4&&p_grid[p_ship3[4]][p_ship3[5]]==4)
				{	cout<<"\nCOMPUTER SUNK THE SIZE 3 SHIP";p_grid[p_ship3[0]][p_ship3[1]]=5;p_grid[p_ship3[2]][p_ship3[3]]=5;p_grid[p_ship3[4]][p_ship3[5]]=5;}
				else cout<<"\nCOMPUTER HIT";
					}
					
					char n;cout<<"\nEnter any key to continue";cin>>n;
}
	
				
	game(){int flag=0;
			while(flag==0){
				
				system("cls");
				cout<<"The game symbols are:\n\t\t\tX->Miss\n\t\t\tO->Hit\n\t\t\t+->Sunk\n";
				flag =check();
				
				for(int i=0;i<8;i++)                              	  //prints grid 
            	{if(i==0)	{cout<<" ";}
				cout<<"  "<<i+1;}                                 //prints grid
              for(int i=0;i<8;i++)
             	 {cout<<"\n"<<char('A'+i);
			  	for(int j=0;j<8;j++)
			  		{if(p_grid[i][j]==0)
			  		cout<<"  ~";
			  		else if(p_grid[i][j]==4)
			  		cout<<"  0";
			  		else if(p_grid[i][j]==5)
			  		cout<<"  +";
			  		else if(p_grid[i][j]==6)
			  		cout<<"  X";
					else  cout<<"  "<<p_grid[i][j];}}
				cout<<"\n      YOUR TERRITORY\n\n\n";
				
				for(int i=0;i<8;i++)                              	  //prints grid 
            	{if(i==0)	{cout<<" ";}
				cout<<"  "<<i+1;}                                 //prints grid
              for(int i=0;i<8;i++)
             	 {cout<<"\n"<<char('A'+i);
			  	for(int j=0;j<8;j++)
			  		{if(c_grid[i][j]==4)
			  		cout<<"  0";
			  		else if(c_grid[i][j]==5)
			  		cout<<"  +";
			  		else if(c_grid[i][j]==6)
			  		cout<<"  X";
					else  cout<<"  ~";}}
					cout<<"\n      ENEMY TERRITORY\n\nCall your shot:";
				cin>>r>>c;
				
				
				/*
				
				
					for(int i=0;i<8;i++)                              	  //prints grid 
            	{if(i==0)	{cout<<" ";}
				cout<<"  "<<i+1;}                                 //prints grid
              for(int i=0;i<8;i++)
             	 {cout<<"\n"<<char('A'+i);
			  	for(int j=0;j<8;j++)
			  		{  cout<<"  "<<c_grid[i][j];}}
				
				
				*/
				
				
				
				callr=(int)r-65;													//converst char to int equivalent(A->0,B->1,etc)
				callc=c-1;											      		//converst col to start from 1 instead of 0
				check:	callr=(int)r-65;													//converst char to int equivalent(A->0,B->1,etc)
						callc=c-1;											      		//converst col to start from 1 instead of 0
			 			 if(row>'H'||row<'A'||col<1||col>8)
				 			{cout<<"\nPlease enter a valid POSITION(In CAPS , eg: 'F 7') :";
							 cin.clear();cin>>r;cin>>c;goto check;}
						if(c_grid[callr][callc]==4||c_grid[callr][callc]==5||c_grid[callr][callc]==6)
							{cout<<"\nYou have already shot here, Enter new target:";
							 cin.clear();cin>>r;cin>>c;goto check;}
							
							
				
						while(p_grid[shotx][shoty]==4||p_grid[shotx][shoty]==5||p_grid[shotx][shoty]==6)
		    			{shotx = rand() % 8+0;
			    		 shoty = rand() % 8+0;
						 }	hit(callr,callc);
							hit1(shotx,shoty,1);
		}

	if(flag==2)
		{	system("cls");cout<<"\n\n\n                          CONGRATULATIONS!\n";
				        cout<<"                               YOU WON";}
	else{	system("cls");cout<<"\n\n\n                          COMPUTER WON\n";
				            cout<<"                       BETTER LUCK NEXT TIME";}				        }

};



int main()
{cout<<"Welcome to battleships\nEnter 1 to start\n";
 			int a;cin>>a;
  if(a==1)
start s1;
game g;
	return 0;
}
