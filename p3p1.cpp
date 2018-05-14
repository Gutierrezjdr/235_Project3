/*
Name:Jessica Gutierrez
Date:05/13/2018
Class: CSCI 235: Software Analysis
Desc: Imagine a robot sitting on the upper left corner of grid
 with r rows and c columns. The robot can only move in two 
 directions, right and down, but certain cells are "limits" such 
 that the robot cannot step on them. This algorithm finds
 a path for the robot from the top left to the bottom right using 
 dynamic programming;

*/



#include<iostream>
#include<stdlib.h>
#include<string>

using namespace std;

//void Print(int Board[0],int c, int r);
//typedef int* IntPtr;

void Print(int c,int r,int board[][1000]);	//Prints board
string Path(int board[][1000],int c,int r);	//Path puts out coordinates
void Fill(int c, int r, int board[][1000]); //Fills board first with 1's and "limits"

int main(){
	int r=0;
	int c=0;
	
	cout<<"Input the number of columns: ";	
	cin>>c;
	
	cout<<"Input the number of rows: ";
	cin>>r;
	
	//IntPtr array;
	int board[r][1000];
	
	Fill(c,r,board);		//fills board
	Print(c,r,board);		//Prints board
	string total=Path(board,c,r); //string that holds path
	cout<<total;					//Prints path
	
}

string Path(int array[][1000],int c,int r){
  string all;
  string store;
  if(c>0&&r>0){
	 // cout<<"C: "<<c<<" R: "<<r<<endl;
	int up=array[r-2][c-1];		//stores value of array above current array
	int left=array[r-1][c-2];	//stores value of array left to current array
	  //following makes string out of int variables for columns and rows
	  store=to_string(c);
	  all+='(';
	  all+=store;
	  store=to_string(r);
	  all+=',';
	  all+=store;
	  //cout<<all;
	  all+=')';
	  all+=' ';
	  //cout<<all<<endl;
	  store="";
	  
	  if(up==1&&left==1){		//if both left and right are 1
		int choose=rand()%2;	//pick random number since it can go both ways
		if(choose==1 && r>=0){	//if 1 and row is more than or equal to 0
			store=Path(array,c,r-1);	//Recursion for this path going up
			all+=store;					//stores string form path		
			return all;					//returns string to main
		}else if(choose==0&&c>=0) {		//if 0 and column is more than 0		
			store=Path(array,c-1,r);	//Recursion for this path going left
			all+=store;
			return all;
		}
	  }else if (up!=1&&left==1){		//if spot above current position is not 1 but left is 1
		  store=Path(array,c-1,r);	   //Recursion to find this path going up
		  all+=store;
		  return all;   
	  }else if(up==1&&left!=1){		//If left spot is not 1 but top is 1
		  store=Path(array,c,r-1);	//Recursion to find this path going left
		  all+=store;
		  return all;
	  }
	  
	  }
	
}
void Fill(int c,int r, int array[][1000]){		//Fills array
	//stores entire array with 1's
	for (int i=0;i<r;i++){
	  for (int j=0;j<c;j++){
		 array[i][j]=1;
	  }
	}
	//randomly places "limits" in board
	for (int i=0;i<r;i++){
	  for (int j=0;j<c;j++){
		
		if((i>0||j>0)&&(i<r-1||j<c-1)){		//if more than top left and less than last position
		  if(array[i+1][j]!=0&&array[i][j+1]!=0 &&array[i-1][j+1]!=0 ) //these locations stop path from being found
			array[i][j]=rand()%2;
		  else array[i][j]=1;
		
		}else{
			array[i][j]=1;
		}
		//cout<<array[i][j]<<" ";
		//cout<<"C:"<<c<<" R:"<<r;
	  }
	  //cout<<endl;
	}	
}
void Print(int c,int r,int array[][1000]){		//Prints board
	
	for (int i=0;i<r;i++){
	  for (int j=0;j<c;j++){
		cout<<array[i][j]<<" ";
		//cout<<"C:"<<c<<" R:"<<r;
	  }
	  cout<<endl;
	}
	
}