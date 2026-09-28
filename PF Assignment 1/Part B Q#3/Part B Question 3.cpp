/*
*PF Theory Assignment 
*Part B Question 1 
*Made by M.Uzair Nauman
*/
#include <stdio.h>
int main (){
	int N ;
	int Marks ;
	int sum = 0 ;
	int Avg ;
	int i  ;
	int Pass = 1 ;
	printf("Enter Number of Students");
	scanf("%d" , &N);
	while (N > 0) {
		i=0;
		while (i < 5){
			printf("Enter Marks");
			scanf("%d" , &Marks);
			sum = sum + Marks;
			if (Marks < 33) Pass = 0;
			i = i +1;
		}
		
		Avg = sum/5;
		if (Pass == 1) {
			if (Avg >= 80) printf("Distinction");
			else if (Avg >= 60) printf("Pass");
			else printf("Fail");}
		else printf("Fail-Subject Deficiency");
		N = N-1;	
	}
	return 0 ;	


}
