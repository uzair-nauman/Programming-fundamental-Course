/*
*PF Theory Assignment 
*Part B Question 1 
*Made by M.Uzair Nauman
*/
#include <stdio.h>
#include <string.h>
int main (){
	int i = 0;
	int Revenue = 0 ;
	int Price ;
	int Rate ;
	int N ;
	int Nights ;
	char Season[20] ; 
	char Roomtype[20] ; 
	printf("Enter number of Bookings");
	scanf("%d" , &N);
	while (i < N ){
		Rate = 0;
		Price = 0;
		printf("Enter Season");
		scanf("%19s" , Season);
		printf("Enter Room type");
		scanf("%19s" , Roomtype);
		printf("Enter Number of Nights");
		scanf("%d" , &Nights);
		if (strcmp(Season , "Peak") ==0 ){
			if (strcmp(Roomtype , "Standard") ==0 ) Rate = 5000;
			else if (strcmp(Roomtype , "Deluxe") ==0 ) Rate = 8000;
			else if (strcmp(Roomtype , "Suite") ==0 ) Rate = 12000;
			else printf("Wrong Roomtype");}
			
		else if (strcmp(Season , "OffPeak") ==0 )	{
			if (strcmp(Roomtype , "Standard") ==0 ) Rate = 3000;
			else if (strcmp(Roomtype , "Deluxe") ==0 ) Rate = 5000;
			else if (strcmp(Roomtype , "Suite") ==0 ) Rate = 8000;	
			else printf("Wrong Roomtype");}
		Price = Rate*Nights;
		if (Nights > 7) Price = Price*0.85;
		printf("Price of this booking is %d\n" , Price);
		Revenue = Revenue + Price;
		i=i+1;
	}
	printf("\nTotal Revenue is %d\n" ,  Revenue);
	return 0;
}
	



