/*
*PF Theory Assignment 
*Part B Question 1 
*Made by M.Uzair Nauman
*/
#include <stdio.h>
int main (){
	int price , quantity , discountp , taxp ;
	int subtotal ;
	float finalbill , discounta;
	printf("Enter quantity of Products ");
	scanf("%d" , &quantity);
	printf("Enter Price of Products ");
	scanf("%d" , &price);
	printf("Enter Discount Percentage ");
	scanf("%d" , &discountp);
	printf("Enter Tax Percentage ");
	scanf("%d" , &taxp);
	if (quantity <= 0 && price <= 0 && discountp < 0 && taxp < 0 )
	printf("Invalid Values are entered");
	else {
		subtotal = quantity * price;
		discounta = subtotal*(100 - discountp)/100;
		finalbill = discounta + (discounta * taxp/100);
		printf("Your Final Bil is %.1f" , finalbill);
		
	}
	
}
