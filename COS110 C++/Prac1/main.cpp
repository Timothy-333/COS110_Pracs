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
int stringToInt(string line){
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
	string floorOrder;
	getline(inData, floorOrder);
	//int** floorArray = new int*[numFloors];
	int maxFloors = -10;
	cout << floorOrder << endl;
	while(!inData.eof())
	{
		string floor;
		getline(inData, floor);
		floor = floor.substr(floor.find(":") + 1, floor.length()-1);
		int floornumber = stringToInt(floor);
		if(floornumber > maxFloors)
		{
			maxFloors = floornumber;
		}
		string people;
		getline(inData, people);

		cout << floornumber << endl;
		cout << people << endl;
	}
	inData.clear();
	inData.seekg(0);

	inData.close();

	//delete[] floorArray;
	//floorArray = NULL;
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

