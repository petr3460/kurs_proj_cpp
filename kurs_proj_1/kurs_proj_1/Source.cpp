#include "Date.h"
#include <iostream>
#include <string>
using namespace std;


int main() {
	/*cout << "enter date: ";
	string dada;
	Date fd;
	cin >> dada;
	fd.init(dada);
	cout << " days in date: " << fd.days << endl;
	Date sd;
	cout << "enter days skolko proshlo: "; cin >> sd.days;
	sd.days_to_string();
	cout << "\ndate to string: " << sd.date_string;
	Date res = fd + sd;
	cout << "new data days: " << res.days << " new data string: " << res.date_string << endl;*/
	Date dat1;
	cin >> dat1;
	cout << dat1;
	Date dat2;
	cin >> dat2;
	Date dat3;
	dat3 = dat1 + dat2;
	cout << "dat 3 is : " << dat3 << endl;


}