/*
*PF Theory Assignment 
*Part B Question 6 
*Made by M.Uzair Nauman
*/
#include <stdio.h>
#include <string.h>
	int main (){
	int Vtype ;
	int battery_level ; 
	int required_level ;
	int duration ;
	int time ; 
	int membership ;
	int disable ;
	int station_available ;
	int discount = 0 ;
	int required_charging = 0 ;
	int charging_fees = 0 ;
	int parking_fees = 0 ;
	int final_fees = 0 ;
	char prior[50] = ""  ;
	printf("Enter Vehicle type : 1 for Hybrid and 0 for Ev ");
	scanf("%d" , &Vtype);
	printf("Enter Battery charging level ");
	scanf("%d" , &battery_level);
	printf("Enter Required charging level ");
	scanf("%d" , &required_level);
	printf("Enter Duration");
	scanf("%d" , &duration);
	printf("Enter current Time");
	scanf("%d" , &time);
	printf("If you are a member enter 1 else enter 0");
	scanf("%d" , &membership);
	printf("If you are disable enter 1 else enter 0");
	scanf("%d" , &disable);
	printf("Enter 1 if Charging Station is available else enter 0");
	scanf("%d" , &station_available);
	if (station_available == 0) {
		if (Vtype == 1) printf("Charging Unavailable Parking Only");
		else printf("No Charging slot available");}
	else{
		if ((Vtype == 1) && (battery_level > 40)) printf("Vechicle ntot qualified for EV Charging");
		else {
			required_charging = required_level - battery_level;
			if (required_charging <= battery_level) printf("No charging required");
			else {
				// Setting priority
				if (battery_level <= 15 && required_level >= 80) strcpy(prior , "Emergeny priority charging");
				else if (membership == 1 && battery_level <= 30) strcpy(prior , "Priority charging") ;
				else strcpy(prior , "Normal charging");
				if (time >= 1700 && time <= 2200) {
					printf("Peak time");
					charging_fees = 50*duration; 
					if (membership == 1) {
						discount = 10;
						charging_fees = charging_fees * 0.9	;
					} }
				else {
					charging_fees = 35*duration;
					if (membership == 1){
						discount = 20 ;
						charging_fees = charging_fees * 0.8;
					}
				}
				if (duration <= 2) parking_fees = 200;
				else if (duration >= 2 && duration <= 5) parking_fees = 500;
				else parking_fees = 700;
				if (membership == 1) parking_fees = parking_fees*0.8;
				if (disable == 1) parking_fees = 0;
				if (duration > 8) printf("Please Relocate your vehicle after charging");	
				else printf("Standard parking duration");
					
				}
		}
	}
	final_fees = parking_fees + charging_fees;
	if (Vtype == 1) printf("Wehicle type is Hybrid\n");
	else if (Vtype == 0) printf("Vehicle type is Electric\n");
	printf("Current battery level is %d \n Required charging percentage is %d \n charging priority is %s \n charging cost is %d \n Parking cost is %d \n Discount is %d \n Final payable amount is %d" , battery_level , required_charging , prior , charging_fees , parking_fees , final_fees);
	return 0;	
	}
	



