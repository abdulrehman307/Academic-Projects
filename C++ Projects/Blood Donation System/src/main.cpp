#include<iostream>
#include<fstream>
#include<vector>
#include<iomanip>
#include<string>
using namespace std;
// Septate structure for all entities 
struct Donor{
	int donorid;
	string name;
	string bloodgroup;
	string contact;
};
struct Recipient{
	int recipientid;
	string name;
	string bloodgroup;
	string contact;
	
};
struct Donation{
	int donationid;
	string donorname;
	string recipientname;
	string blooddonated;
	string donationdate;
	
};
struct BloodAvailable{
	string bloodtype;
	string bloodquantity;
	string bloodexpirationdate;
};
//Function for add donors
void Add_Donors(){
	Donor donor;
	cout<<"Enter Donor id :";
	cin>>donor.donorid;
	cin.ignore();
	cout<<"Enter Donor Name :";
	getline(cin,donor.name);
	
	cout<<"Enter Donor Blood Group :";
	getline(cin, donor.bloodgroup);
	cout<<"Enter Donor Contact Number :";
	getline(cin, donor.contact);
	//donors.push_back(donor);
	ofstream outfile;
	outfile.open("donor.txt", ios::app);
	if(outfile.is_open())
	{
		
		outfile<<donor.donorid<<setw(15)<<donor.name<<setw(8)<<donor.bloodgroup<<setw(15)<<donor.contact<<"\t"<<endl;
		outfile.close();
		cout<<"Donor Added Successfully......."<<endl;
		
	}
	else
	{
		cout<<"Unable to open file "<<endl;
		
	}
}
//Function for searching donors by their ids
void Search_Donor_By_ID()
{
	int donorid;
	cout<<"Enter Donor Id To Search :";
	cin>>donorid;
	Donor donor;
	ifstream infile("donor.txt");
	if(infile.is_open())
	{
		while(infile>>donor.donorid>>donor.name>>donor.bloodgroup>>donor.contact)
	//	for(Donor donor : donors)
		{
			if(donor.donorid==donorid)
			{
				cout<<"Donor id	 :"<<donor.donorid<<endl;
				cout<<"Donor Name :"<<donor.name<<endl;
				cout<<"Donor Blood Group :"<<donor.bloodgroup<<endl;
				cout<<"Donor Contact :"<<donor.contact<<endl;
			}
		}
	}
	else
	
	{
		cout<<"Unable To Open File!....."<<endl;
	}
}
//Function for displaying donor list 
void Display_Donors_List()
{
	
	Donor donor;
	string line;
	cout<<"The list of all donors is as follows :"<<endl;
	ifstream infile("donor.txt");
	cout<<"id"<<"\t"<<" "<<"Name"<<"\t"<<" "<<"Blood Group"<<"\t"<<" "<<"contact"<<endl;

	while(getline(infile,line))
	{
		cout<<line<<endl;
	}
	infile.close();
}
//Function for adding recipients of blood
void Add_Recipients(){
	Recipient recipient;
	cout<<"Enter Recipient id :";
	cin>>recipient.recipientid;
	cin.ignore();
	cout<<"Enter Recipient Name :";
	getline(cin, recipient.name);
	cout<<"Enter Recipient Blood Group :";
	getline (cin, recipient.bloodgroup);
	cout<<"Enter Recipient Contact :";
	getline (cin, recipient.contact);
	
	//recipients.push_back(recipient);
	ofstream outfile("recipient.txt", ios::app);
	if(outfile.is_open())
	{
		outfile<<recipient.recipientid<<setw(15)<<recipient.name<<setw(8)<<recipient.bloodgroup<<setw(15)<<recipient.contact<<endl;
		outfile.close();
		cout<<"Recipient Added Successfully!....."<<endl;
		
	}
	else
	{
		cout<<"Unable to open file!....."<<endl;
		
	}
	
}
//funcion for searching recipient data
void Search_Recipient_By_Id()
{
	int recipientid;
	cout<<"Enter Recipient ID For Search :";
	cin>>recipientid;
	Recipient recipient;
	ifstream infile("recipient.txt");
	if(infile.is_open())
	{
		while(infile>>recipient.recipientid>>recipient.name>>recipient.bloodgroup>>recipient.contact)
		//for(Recipient recipient : recipients)
		{
			if(recipient.recipientid==recipientid)
			{
				cout<<"Recipient Id			 :"<<recipient.recipientid<<endl;
				cout<<"Recipient Name		 :"<<recipient.name<<endl;
				cout<<"Recipient Blood Group :"<<recipient.bloodgroup<<endl;
				cout<<"Recipient Contact	 :"<<recipient.contact<<endl;

			}
		}
	}
	else
	{
		cout<<"Unable To Open File!....."<<endl;
	}
	
}
//function for dislaying the recipients list
void Display_Recipients_List()
{
	string line;
	Recipient recipient;
	ifstream infile("recipient.txt");
	while(getline(infile, line))
	{
		cout<<line<<endl;
	}
}
//Fucntion for the seaching the donors for the required blood group
void Search_BloodGroup(){
	string reqbloodgroup;
	cout<<"Enter Required Blood Group :";
	cin>>reqbloodgroup;
	
	ifstream infile;
	infile.open("donor.txt");
		Donor donor;
		bool found= false;
		
		while(infile>>donor.donorid>>donor.name>>donor.bloodgroup>>donor.contact)
		{
			if(donor.bloodgroup == reqbloodgroup){
				cout<<endl;
				cout<<"Donors with Blood Group "<<reqbloodgroup <<":"<<endl;

				cout<<"Donor Id : "<<donor.donorid<<"\n";
				cout<<"Donor Name : "<<donor.name<<"\n";
				cout<<"Donor Blood Group : "<<donor.bloodgroup<<"\n";
				cout<<"Donor Contact : "<<donor.contact<<"\n";
				

			}
		found=true;

		}
		
		infile.close();
		if(!found){
			cout<<"No Donors found for the Blood Group "<<reqbloodgroup<<"...."<<endl;
			
		}
	}
//Fucniton for adding donation
void Add_Donations(){
	Donation donation;
	cout<<"Enter Donation ID :";
	cin>>donation.donationid;
	cin.ignore();
	cout<<"Enter Donor Name :";
	getline(cin,donation.donorname);
	cout<<"Enter Recipient Name :";
	getline(cin,donation.recipientname);
	cout<<"Enter Blood Donated :";
	getline(cin,donation.blooddonated);
	cout<<"Enter the Date of Blood Donation :";
	getline(cin,donation.donationdate);
	//donations.push_back(donation);
	ofstream outfile("donations.txt",ios ::app);
	if(outfile.is_open())
	{
		outfile<<donation.donationid<<setw(15)<<donation.donorname<<setw(15)<<donation.recipientname<<setw(8)<<donation.blooddonated<<setw(15)<<donation.donationdate<<endl;
		outfile.close();
		cout<<"Donation Added Successfully!....."<<endl;
		
	}
	else
	{
		cout<<"Unable To Open File!....."<<endl;
	}
	}
	//function for searching the donation made
void Search_Donation_By_Id()
{
	int donationId;
	cout<<"Enter Donation ID For Search :";
	cin>>donationId;
	ifstream infile("Donations.txt");
	Donation donation;
	bool found = false;
	if(infile.is_open()){
		while(infile>>donation.donationid>>donation.donorname>>donation.recipientname>>donation.blooddonated>>donation.donationdate)
	
	//for(Donation donation : donations)
		{
			if(donation.donationid==donationId)
		{
			cout<<"Donation id        "<<"\t"<<":"<<donation.donationid<<endl;
			cout<<"Donor Name         "<<"\t"<<":"<<donation.donorname<<endl;
			cout<<"Recipient Name     "<<"\t"<<":"<<donation.recipientname<<endl;
			cout<<"Blood Group Donated"<<"\t"<<":"<<donation.blooddonated<<endl;
			cout<<"Donation Date      "<<"\t"<<":"<<donation.donationdate<<endl;

		}
		found=true;
	}
	if(!found)
	{
		cout<<"No Donation Found for this Donation id"<<endl;
	}
	
}
else
{
	cout<<"Unable To open file!.....";
}
}
//function for dislaying the donations
void Display_Donations()
{
	Donation donation;
	string lines;
	ifstream infile("donations.txt");
	cout<<"id"<<"\t"<<"Donor Name  "<<"Recipient Name  "<<"Blood Donated  "<<"Donation Date  "<<endl;
	while(getline(infile ,lines))
	{
		cout<<lines<<endl;
	}
	infile.close();
	}
void Add_BloodAvailable()
{
	BloodAvailable bloodavailable;
	cout<<"Enter Blood Type :";
	cin>>bloodavailable.bloodtype;
	cout<<"Enter the Quantity of Blood in Pints (1 pint = 473ml) :";
	cin>>bloodavailable.bloodquantity;
	cout<<"Enter Expiry Date of Blood(DD/MM/YYYY) :";
	cin>>bloodavailable.bloodexpirationdate;
	//bloodavailabilities.push_back(bloodavailable);
	
	ofstream outfile("bloodavailable.txt", ios::app);
	if(outfile.is_open())
	{
		outfile<<bloodavailable.bloodtype<<setw(6)<<bloodavailable.bloodquantity<<"pints"<<setw(15)<<bloodavailable.bloodexpirationdate<<endl;
		outfile.close();
		cout<<"Blood Availability added Successfully.";
	}
		                                                                                                                 
	else
	{
		cout<<"Unable To Open File!....."<<endl;
	}
	
}
// function for searching the blood group availbilty
void Check_BloodAvailability_Bysearch()
{
	string bloodavailability;
	cout<<"Enter Blood Group To check Blood Quantity :";
	cin>>bloodavailability;
	ifstream infile("bloodavailable.txt");
	BloodAvailable bloodavailable;
	bool found = false;
	if(infile.is_open())
	{
		while(infile>>bloodavailable.bloodtype>>bloodavailable.bloodquantity>>bloodavailable.bloodexpirationdate)
	
//	for(BloodAvailable bloodavailable : bloodavailabilities)
	{
		if(bloodavailable.bloodtype==bloodavailability){
			cout<<"Blood Type      :"<<bloodavailable.bloodtype<<endl;
			cout<<"Blood Quantity  :"<<bloodavailable.bloodquantity<<endl;
			cout<<"Expiration Date :"<<bloodavailable.bloodexpirationdate<<endl;
			infile.close();
			found= true;

		}
	}
	if(!found)
	{
		cout<<"Blood Group "<<bloodavailability<<" is not available yet. "<<endl;
		
	}
}
else
{
	cout<<"Unable to open file";
}
}
//funcitonn for displaying the list of bloodgroups available
void Display_BloodAvailability_List()
{
	BloodAvailable bloodavailable;
	string line;
	cout<<"Blood Type"<<"\t"<<"Blood Quantity "<<"\t"<<"Blood Expiration Date"<<endl;
	ifstream infile("bloodavailable.txt");
	while(getline(infile, line))
	{
		cout<<line<<endl;
	}
	infile.close();
}

//Function for mainmenu
void main_menu()
{
	string choice;
	cout<<"====== Blood Donation System ======"<<endl;
	cout<<"1.	Manage Donors"<<endl;
	cout<<"2.	Manage Recipients "<<endl;
	cout<<"3.	Manage Donations"<<endl;
	cout<<"4.	Manage Blood Availability"<<endl;
	cout<<"5.	Search Donors For Required Blood Group"<<endl;
	cout<<"6.	Exit";
	cout<<endl;
	cout<<"Enter Your Choice: ";
	cin>>choice;
	if(choice=="1"){
		cout<<"------ Manage Donors ------"<<endl;
		cout<<"1.	Add Donor"<<endl;
		cout<<"2.	Search Donor By ID"<<endl;
		cout<<"3.	Display Donors List"<<endl;
		cout<<"4.	Back To Main Menu"<<endl;
		cout<<endl;
		int choice;
		cout<<"Enter your Choice :";
		cin>>choice;
		switch(choice)
		{
			case 1:
				Add_Donors();
				break;
			case 2:
				Search_Donor_By_ID();
				break;
			case 3:
				Display_Donors_List();
				break;
			case 4:
				main_menu();
				break;
		
		default :
		cout<<"Invalid Input!.....Please Try Again";
		main_menu();
	}
	}
	else if(choice=="2")
	{
		cout<<"------ Manage Recipients ------"<<endl;
		cout<<"1.	Add Recipient"<<endl;
		cout<<"2.	Seach Recipient By ID"<<endl;
		cout<<"3.	Display Recipient"<<endl;
		cout<<"4.	Back To MainMenu"<<endl;
		cout<<endl;
		int choice;
		cout<<"Enter Your Choice :";
		cin>>choice;
		switch(choice)
		{
			case 1:
				Add_Recipients();
				break;
			case 2:
				Search_Recipient_By_Id();
				break;
			case 3:
				Display_Recipients_List();
				break;
			case 4:
				main_menu();
				break;
			default :
			cout<<"Invalid Input!.... please Try again"<<endl;
			main_menu();
		}

	}
	else if(choice=="3"){
		
		cout<<"------ Manage Donations ------"<<endl;
		cout<<"1.	Add Donation"<<endl;
		cout<<"2	Search Donation By ID "<<endl;
		cout<<"3	Display Donations List "<<endl;
		cout<<"4.	Back To Main Menu "<<endl;
		cout<<endl;
		int choice;
		cout<<"Enter Your Choice :";
		cin>>choice;
		switch(choice)
		{
			case 1:
				Add_Donations();
				break;
			case 2:
				Search_Donation_By_Id();
				break;
			case 3:
				Display_Donations();
				break;
			case 4:
				main_menu();
			default :
			cout<<"Invalid Input!..... Plese Try Again"<<endl;
			main_menu();
		}
		
		
	}
	else if(choice=="4"){
		cout<<"------ Manage Blood Availability ------"<<endl;
		cout<<"1.	Add Blood Availablity"<<endl;
		cout<<"2.	Check Blood Avaiability By Search"<<endl;
		cout<<"3.	Display  Blood Availability List"<<endl;
		cout<<"4.	Back To Main Menu"<<endl;
		cout<<endl;
		int choice;
		cout<<"Enter Your Choice :";
		cin>>choice;
		switch(choice)
		{
			case 1:
				Add_BloodAvailable();
				break;
			case 2:
				Check_BloodAvailability_Bysearch();
				break;
			case 3:
				Display_BloodAvailability_List();
				break;
			case 4:
				main_menu();
				break;
			default :
			cout<<"Invalid Input!..... please Try Again"<<endl;
			main_menu();
		}
	}
		else if( choice=="5")
		{
			cout<<"------ Search Donors For Required Blood Group ------"<<endl;
			Search_BloodGroup();
			
		}


	
	else if(choice=="6"){
		cout<<"Exited!"<<endl;
		exit(0);
	}else{
		cout<<"Invalid! Input! .... please Try Again"<<endl;
		cout<<endl;
		main_menu();
	}
}

int main()
{
main_menu();
}
