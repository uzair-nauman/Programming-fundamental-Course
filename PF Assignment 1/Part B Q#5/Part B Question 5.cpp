/*
*PF Theory Assignment 
*Part B Question 5
*Made by M.Uzair Nauman
*/
#include <stdio.h>
int main (){
	int Vtype ; 
	int User ;
	int Permit ;
	int Emergency ;
	int accepted = 0  ;
	int rejected = 0 ;
	int bike = 0 ;
	int car = 0 ;
	int van = 0 ;
	int zonea = 20 ;
	int zoneb = 40 ;
	int zonec = 15 ;
	int details ;
	int N ;
	int Processed ;
	printf("Enter Number of Vehicles");
	scanf("%d" , &N);
	Processed = N;
	while (N > 0) {
		details = 0;
		while (details == 0) {	
			printf("Enter Vehicle type : for Bike enter 1 , for car enter 2 , for van enter 3 ");
			scanf("%d" , &Vtype);
			printf("Enter User Category : for Faculty enter 1 , for Student enter 2 for Visitor enter 3 ");
			scanf("%d" , &User);
			printf("if permit is available enter 1 if not enter 0 ");
			scanf("%d" , &Permit);
			printf("if emergency enter 1 if not enter 0 ");
			scanf("%d" , &Emergency);
			if ((Vtype >= 1 && Vtype <= 3) && (User >= 1 && User <= 3) && (Permit == 0 || Permit == 1) && (Emergency == 0 || Emergency == 1))
			details = 1;
			else printf("Wrong Details are entered");}
		if (Permit == 1 || Emergency == 1){	
			switch (Vtype) {
				case 1 :
					switch(User){
						case 1 :
							if (zonea > 0) { 
							bike = bike + 1;
							accepted = accepted + 1;
							zonea = zonea - 1;
							}
							else rejected = rejected + 1;
							break ;
						case 2 :
							if (zoneb > 0) {
							bike = bike + 1;
							accepted = accepted + 1;
							zoneb = zoneb - 1;
							}
							else rejected = rejected - 1;
							break ;			
						case 3 :
							if (zonec > 0) {
							bike = bike + 1;
							accepted = accepted + 1;
							zonec = zonec - 1;
							}
							else rejected = rejected + 1;
							break ; }
					break ;
				case 2 :
					switch(User){
						case 1 :
							if (zonea > 0) {
							car = car + 1;
							accepted = accepted + 1;
							zonea = zonea - 1;
							}
							else rejected = rejected + 1;
							break ;
						case 2 :
							if (zoneb > 0) {
							car = car + 1;
							accepted = accepted + 1;
							zoneb = zoneb - 1;
							}
							else rejected = rejected + 1;
							break ;
						case 3 :
							if (zonec > 0) {
							car = car + 1;
							accepted = accepted + 1;
							zonec = zonec - 1;
							}
							else rejected = rejected + 1;
							break ;}
					break ;
				case 3 :
					switch(User){
						case 1 :
							if (zonea > 0) {
							van = van + 1;
							accepted = accepted + 1;
							zonea = zonea - 2;
							}
							else rejected = rejected + 1;
							break ;
						case 2 :
							if (zonec > 0) {
							van = van + 1;
							accepted = accepted + 1;
							zonec = zonec - 2;
							}
							else rejected = rejected + 1;
							break ;
						case 3 :
							if (zonec > 0) {
							van = van + 1;
							accepted = accepted + 1;
							zonec = zonec - 2;
							}
							else rejected = rejected + 1;
							break ;
					break ;											
					}
			}
		}
		else rejected = rejected + 1;	
		N = N - 1;
	}
	printf("Zone A : %d \n Zone B : %d \n Zone C : %d \n Bikes : %d \n Cars : %d \n Vans : %d \n Accepted : %d \n Rejected : %d \n Processed : %d" , zonea , zoneb , zonec , bike , car , van , accepted , rejected , Processed);
	return 0 ;
}
