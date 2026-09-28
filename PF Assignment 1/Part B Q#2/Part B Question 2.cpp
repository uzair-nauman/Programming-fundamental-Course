/*
*PF Theory Assignment 
*Part B Question 1 
*Made by M.Uzair Nauman
*/
#include <stdio.h>
int main (){
	int N ;
	int Cfloor = 0;
	int Floor ;
	printf("Enter Number of Requests");
	scanf("%d" , &N);
	while (N > 0) {
		printf("Enter floor Number") ;
		scanf("%d" , &Floor);
		if (Floor > Cfloor) printf("Moving up\n");
		else if (Floor < Cfloor) printf("Moving Down\n");
		else printf("Opening Doors\n");
		Cfloor = Floor; 
		N = N - 1;
	
	}
	return 0;


}
