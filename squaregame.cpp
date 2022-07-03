#include<iostream>
#include "gameplan.h"
using namespace std;

int main()
{
	int n= 25;
	int a[n];
	//the path of each player wrt array a indexes
	int pathA[] =  {2,1,0,5,10,15,20,21,22,23,24,19,14,9,4,3,8,13,18,17,16,11,6,7,12};
	int pathB[] = {22,23,24,19,14,9,4,3,2,1,0,5,10,15,20,21,16,11,6,7,8,13,18,17,12};
	//pointer to the path 
	int startA = 0;
	int startB = 0;
	// starting position of players in array a 
	int posA = pathA[startA];//2
	int posB = pathB[startB];//22
	//symbols of players
	int plA = 1;
	int plB = 2;
	
	int dice;
	reset(a,n);
	//placing players in their start positions in the array  a 
	a[posA]=plA;
	a[posB]=plB;
	
	int moves = 1;
	
	display(a,n);
	
	while(1)
	{
		if(startA==24)
		{
				cout<<"\n Player 1 wins \n";
				break;
				
		}
		
		if(startB==24)
		{
				cout<<"\n Player2 wins \n";
				break;
				
		}
		
		if(moves%2==1)
		{
			do
			{
				cout<<"\nPlayer A :Enter valid dice val (1-4)= ";
				cin>>dice;
			}while(dice<1 || dice>4);
			
			if(startA==23 && dice>1)
				cout<<"\n Cannot move \n";
			else if(startA==22 && dice>2)
				cout<<"\n Cannot move \n";
			else if(startA==21 && dice>3)
				cout<<"\n Cannot move \n";
			else
			{
				if(a[posA]==12)
					a[posA]=plB; //curr pos = 12 then make it 2 before moving
				else
					a[posA]=0;
				startA += dice; //0+3=3
				posA = pathA[startA]; // pathA[3] = 5

				if(a[posA]!=0 && (posA==10 || posA==14)) //  save pos already 2 is existing
				{
					a[posA]=12;   // filled with 12
				}
				else if((a[posA]!=0 && posA!=14) ) //when already 2 and not safe u can kill
				{
					startB=0;           //opp=0
					posB=pathB[startB];  
					a[posB]=plB;          
					a[posA]=plA;        //current pos after killing should be filled with 1
				}
				else if((a[posA]!=0 && posA!=10) )
				{
					startB=0;
					posB=pathB[startB];
					a[posB]=plB;
					a[posA]=plA;
				}
				else 
					a[posA]=plA;	
			}
			
		}
		else
		{
			do
			{
				cout<<"\nPlayer B :Enter valid dice val (1-4)= ";
				cin>>dice;
			}while(dice<1 || dice>4);
		
			if(startB==23 && dice>1)
				cout<<"\n Cannot move \n";
			else if(startB==22 && dice>2)
				cout<<"\n Cannot move \n";
			else if(startB==21 && dice>3)
				cout<<"\n Cannot move \n";
			else
			{
			
				if(a[posB]==12)
					a[posB]=plA; // safe mode if already 12 a[14] || a[12] = 1
				else
					a[posB]=0;  // filled with 0
				startB += dice; //0+3=3
				posB = pathB[startB]; // pathA[3] = 5
				
				if(a[posB]!=0 && (posB==10 || posB==14))
				{
					a[posB]=12;
				}
				else if(a[posB]!=0 && posB!=14)
				{
					startA=0;
					posA=pathA[startA];
					a[posA]=plA;
					a[posB]=plB;
				}
				else if(a[posB]!=0 && posB!=10)
				{
					startA=0;
					posA=pathA[startA];
					a[posA]=plA;
					a[posB]=plB;
				}
				else
					a[posB]=plB;
			}
		}	
			
		moves++;	
		display(a,n);
	}

	
	
	
	
	
	
	
	return 0;
}
