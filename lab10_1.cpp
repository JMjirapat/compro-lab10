#include<iostream>
#include<iomanip> //For using setw(), setprecision(), ...
using namespace std;

int main(){

	double loan, interest_rpy, pay_py;
	double prevBalance, interest, total, payment, newBalance;
	int num_year = 1;
	cout << "Enter initial loan: ";
	cin >> loan;
	cout << "Enter interest rate per year (%): ";
	cin >> interest_rpy;
	cout << "Enter amount you can pay per year: ";
	cin >> pay_py;

	//use 'setw' to set width of table and 'left' to set left-alignment
	//you can change input argument of 'setw()' to see the effect
	//Try to change from 'left' to 'right' and see the effect
	cout << setw(13) << left << "EndOfYear#"; 
	cout << setw(13) << left << "PrevBalance"; 
	cout << setw(13) << left << "Interest"; 
	cout << setw(13) << left << "Total";
	cout << setw(13) << left << "Payment";
	cout << setw(13) << left << "NewBalance";
	cout << "\n";
	
	//use 'fixed' and 'setprecision' to fix the number of decimal digits for displaying
	//you can change input argument of 'setprecision()' to see the effect
	while(true){

		prevBalance = loan;
		if(num_year != 1)
			prevBalance = newBalance;
		interest = prevBalance*interest_rpy/100;
		total = prevBalance + interest;
		payment = pay_py;
		if(total <= payment)
			payment = total;
		newBalance = total - payment;
		cout << fixed << setprecision(2);
		cout << setw(13) << left << num_year; 
		cout << setw(13) << left << prevBalance;
		cout << setw(13) << left << interest;
		cout << setw(13) << left << total;
		cout << setw(13) << left << payment;
		cout << setw(13) << left << newBalance;
		cout << "\n";
		if(newBalance == 0)
			break;
		num_year++;
	}	
	
	return 0;
}
