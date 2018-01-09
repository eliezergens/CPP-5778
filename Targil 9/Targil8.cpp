//	ID:  1234						
//   Name: Eliezer Gensburger       
//   Targil:                        
/************************************
*   DESCRIPTION:                    *
*   ------------                    *
*                                   *
*        EGGED                      *
*                                   *
*                                   *
*                                   *
*                                   *
*************************************/
#include <iostream>
using namespace std;


void addLine(int**&, int&, int, int, int);
void print(int**, int);
void deleteLine(int**& buses, int& numBuses, int line);

int main()
{
	int ** buses = nullptr;
	int numBuses = 0;
	int line;
	int stops;
	int durationOfRide;
	int choice;
	do {
		cout << "enter 0-7" << endl;
		cin >> choice;
		switch (choice){
		case 0: // add line
			cout << "enter the line to add" << endl;
			cin >> line;
			cout << "enter the number of stops" << endl;
			cin >> stops;
			cout << "enter the duration of the ride" << endl;
			cin >> durationOfRide;
			//numBuses++;
			//if (numBuses == 1)
			//	buses = new int *[1];
			addLine(buses, numBuses, line, stops, durationOfRide);
			print(buses, numBuses);
			break;

		case 1:	// delete line
			cout << "enter the line to delete" << endl;
			cin >> line;
			deleteLine(buses, numBuses, line);
			print(buses, numBuses);
			break;
		case 2: // print all lines
			print(buses, numBuses);
			break;
			//case 3: // search for a particular line
			//	cout << "enter the line to search for" << endl;
			//	cin >> line;
			//	cout << search(buses, numBuses, line) << endl;
			//	break;
			//case 4: // calculate average travel time of all buses
			//	cout << averageTravel(buses, numBuses) << endl;
			//	break;
			//case 5:  // calcuate average stops of all buses
			//	cout << averageStops(buses, numBuses) << endl;
			//	break;
			//case 6: // calculate the bus with the shortest travel time
			//	cout << shortest(buses, numBuses) << endl;
			//	break;
		case 7: break;   // exit the program

		default: cout << "ERROR" << endl;
		}// switch
	} while (choice != 7);

	for (int i = 0; i < numBuses; i++)
		delete[] buses[i];

	if (numBuses > 0)
		delete[] buses;

	system("pAuSe");
	return 0;
}

void addLine(int**& egged, int& kama, int kav, int stops, int duration)
{
	int* bus = new int[3];
	bus[0] = kav;
	bus[1] = stops;
	bus[2] = duration;
	++kama;

	if (egged == nullptr)	// if(kama == 0)
	{
		egged = new int *[kama];
		*egged = bus;
	}
	else
	{
		int** temp = new int*[kama];
		int i;
		i = 0;
		while (egged[i][0] < bus[0])
		{
			temp[i] = egged[i];
			++i;
		}
		temp[i] = bus;

		while (i < kama - 1)
		{
			temp[i + 1] = egged[i];
			++i;
		}

		delete[] egged;
		egged = temp;
	}
}

void  print(int** buses, int numbuses)
{
	for (size_t i = 0; i < numbuses; i++)	//size ==== unsigned int
	{
		cout << buses[i][0] << " " << buses[i][1] << " " << buses[i][2] << endl;
	}
	//int** p = buses;
	//int** end = buses + numbuses;
	//while(p < end)
	//{
	//	cout << *((*p)+0) << " " << *((*p)+1)<< " " << *((*p)+2) << endl;
	//}
}

void deleteLine(int**& buses, int& numBuses, int line)
{
	bool nimtza = false;
	int i = 0, j = 0;
	int badguy;
	if (buses != nullptr)	// if(kama == 0)
	{
		int** temp = new int*[numBuses - 1];
		while (j < numBuses)
		{
			if (buses[i][0] != line)
			{
				temp[j] = buses[i];
				++i;
				++j;
			}
			
			if (buses[i][0] == line)
			{
				badguy = i;
				++i;
				nimtza = true;
			}
		}
		if (nimtza)
		{
			delete buses[badguy];
			delete[] buses;
			buses = temp;
			--numBuses;
		}
	}
}

