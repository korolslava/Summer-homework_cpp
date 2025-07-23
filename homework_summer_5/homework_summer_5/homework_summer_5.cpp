#include "PostOffice.h"

int main()
{
	PostOffice postOffice("Central Post Office");
	Recipient recipient("John Doe", "Springfield", 123456789);
	Parcel parcel(1, 2.5, recipient);
	postOffice.setParcels(&parcel);
	cout << "Post Office Name: " << postOffice.getNameOfPostOffice() << endl;
	cout << "Parcel ID: " << postOffice.getParcels()->getID() << endl;
	cout << "Recipient Name: " << postOffice.getParcels()->getRecipient().getName() << endl;
	return 0;
}


