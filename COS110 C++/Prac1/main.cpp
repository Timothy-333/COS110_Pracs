#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

/*
	stringToInt is a helper function that will 
	take a string called line and return the integer value
*/
int stringToInt(string line)
{
	stringstream s1(line);
	int temp = 0;
	s1 >> temp;
	return temp;
}

int main() 
{
	ifstream inData;
	inData.open("building.data");
	if(!inData)
	{
		cout << "Error opening file" << endl;
		return 1;
	}

	int maxFloors = -10;
	string floorOrder;
	getline(inData, floorOrder);
	string floorOrder2 = floorOrder;
	istringstream iss(floorOrder);
	while(getline(iss, floorOrder, ','))
	{
		int currentFloor = stringToInt(floorOrder);
		if(currentFloor > maxFloors)
		{
			maxFloors = currentFloor;
		}
	}
	int* peopleCount = new int[maxFloors+1];
	string** floorArray = new string*[maxFloors];
	while(!inData.eof())
	{
		string floor;
		getline(inData, floor);
		floor = floor.substr(floor.find(":") + 1, floor.length()-1);
		int floornumber = stringToInt(floor);
		
		int numPeople = 1;
		string people;
		getline(inData, people);
		
		for (int i = 0; i < people.length(); i++)
		{
			if(people[i] == ',')
			{
				numPeople++;
			}
		}

		peopleCount[floornumber] = numPeople;
		int personCounter = 0;
		floorArray[floornumber] = new string[numPeople];
		istringstream iss(people);
		while(getline(iss, people, ','))
		{
			floorArray[floornumber][personCounter] = people;
			personCounter++;
		}
	}
	istringstream iss2(floorOrder2);
	while(getline(iss2, floorOrder2, ','))
	{
		int currentFloor = stringToInt(floorOrder2);
		for (int i = peopleCount[currentFloor]-1; i >= 0 ; i--)
		{
			cout << floorArray[currentFloor][i];
			if(i != 0)
			{
				cout << ",";
			}
		}
		cout << endl;
	}
	for (size_t i = 0; i < maxFloors+1; i++)
	{
		delete[] floorArray[i];
	}
	
	inData.close();
	delete floorArray;
	delete peopleCount;
	peopleCount = NULL;
	floorArray = NULL;
	return 0;
}

/*
Expected output with the given building.txt:

Sunil,Alok,Kamilah,Pratik
Tamera,Zanetta,Keyundra,Alexzander,Nickalaus,Nathania,Annamaria,Ransen,Thuy,Yousef       
Jeffry,Shira,Sereena
Janna,Shaleen,Josi,Ndidi,Indalecio,Charlotta
Kejuan,Matricia,Takiya,Karalyn,Charls
Rebbecca
Kailyn,Kenda
Katheryne,Coury,Timithy,Melisssa,Clara,Lucus,Brittony,Makoto,Latona,Rudolph
*/

