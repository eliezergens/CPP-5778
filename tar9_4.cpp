
//AUTHOR:	Plony Almony	&	Shutaf Iski
//IDs:		667868768			89675765765
//KVUTZA:   150005.01.5770.22
//TITTLE:	Targil xx Seif yy
//SUBJECT:	
/****************************************
*										*
*	DESCRIPTION:						*
*	bla bla bla							*
*	bla bla bla	bla bla bla				*
*	bla bla bla	bla bla bla				*
*	bla bla bla	bla bla bla				*
*										*
*										*
*****************************************/
/******************************************
-	newStr קליטת מילה חדשה מהמשתמש (אורך מקס' 15).
-	delStr מחיקת מילה (הפונקציה מקבלת מילה ומוחקת אותה מהמערך אם היתה בו ,אחרת לא מבצעת  דבר, יש לעדכן את מיקום שאר המחרוזות כך שיהיו ברצף).
-	searchStr חיפוש מילה (קלט מילה מהמשתמש, והחזרת NULL או מצביע למילה שנמצאה).
-	printChar הדפסת כל המילים המתחילות באות מסוימת.
-	printAll הדפסת כל המילים במאגר -בעצם הדפסת כל אברי המערך הדו ממדי.
*******************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
#define INCR 1
#define WORDLENGTH 15

void insertWord(char*,char**&,int&,int&);
void deleteWord(char**& milon,int makom,int &i,int &size);
void increment(char**& dict,int & size);
void insertionSortWord( char* temp,char ** dictionnary,int &used);
void decrement(char**& dict,int &size);
int binarySearch(char** vec,char* what, int used);
int dicBinarySearch ( char* arr[],int low,int high, char* what) ;
void shiftOneRight(char* vec[], int begin, int end);
void shiftOneLeft(char* vec[], int begin, int end);
/***********/
int tafrit_rashi();
void newStr(char** &milon,int& used,int& size);
void deleteStr(char** &milon,int& used,int& size);
bool searchStr(char** milon,int used);
void printAll(char** milon,int used);
void printChar(char** milon,int used);

int main()
{
	char **milonit = NULL;
	int used = 0;
	int size = 0;
	bool found;

	int choice;
	do
	{
		choice = tafrit_rashi();
		switch(choice)
		{
		case 5:
			if(milonit)
			{
				for(int i = 0 ; i < used; ++i)
				{
					delete milonit[i];
				}
			}
			delete[] milonit;
			break;
		case 0:
			newStr(milonit,used,size);
			printAll(milonit,used);
			break;
		case 1:
			deleteStr(milonit,used,size);
			printAll(milonit,used);
			break;
		case 2:
			found = searchStr(milonit,used);
			if (found)
			{
				cout<<"found"<<endl;
			}
			else
			{
				cout<<"not found"<<endl;
			}
			break;
		case 3:
			printChar(milonit,used);
			break;
		case 4:
			printAll(milonit,used);
			break;
		default:
			cout<<"ERROR"<<endl;
		}
	}
	while(choice != 5);
	//system("pause");
	return 0;
}

bool searchStr(char** milon,int used)
{
	char what[WORDLENGTH+1];
	cout<<"enter the word to search for:"<<endl;
	cin>> what;
	if(used > 0)
	{
		if (dicBinarySearch(milon,0,(used - 1),what) != -1)
		{
			return true;
		}
	}
	return false;
}

void newStr(char** &milonit,int& used,int& size)
{
	char temp[WORDLENGTH+1];

	cout<<"enter the word:"<<endl;
	cin>>temp;
	if (used == 0)
	{
		insertWord(temp,milonit,used,size);
	}
	else
	{
		//no kfulot
		if (dicBinarySearch(milonit,0,(used - 1),temp) == -1)
		{
			insertWord(temp,milonit,used,size);
		}
	}
}

void deleteStr(char** &milon,int& used,int& size)
{
	char what[WORDLENGTH+1];
	int makom;

	cout<<"enter the word to delete:"<<endl;
	cin>>what;
	if (used > 0)
	{
		makom = binarySearch(milon,what,used);
		if(makom != used)
		{
			if (strcmp(what,milon[makom]) == 0)
			{
				deleteWord(milon,makom,used,size);
			}
		}
	}
}

void printAll(char** milon,int used)
{
	int i;
	if (milon)
	{
		for(i = 0 ; i < (used-1); ++i)
		{
			cout<<milon[i]<<' ';
		}
		cout<<milon[i]<<endl;
	}
}

void printChar(char** milon,int used)
{
	char a_char;
	int i;
	bool flag = false;
	
	cout<<"enter the char:"<<endl;
	cin>> a_char;
	if(milon)
	{
		for(i = 0; i < used; ++i)
		{
			if (*(milon[i]) == a_char)
			{
				if (flag)
				{
					cout<<' ';
				}
				cout<< milon[i];
				flag = true;
			}
		}
		cout<<endl;
	}

}

void insertWord(char* mila,char**& milon,int &used,int &size)
{

	if (used == size)
	{
		increment(milon,size);
	}
	if (used == 0)
	{
		char* aWord = new char[strlen(mila)+1];
		strcpy(aWord,mila);
		milon[used] = aWord;
		++used;	
	}
	else
	{
		insertionSortWord(mila,milon,used);
	}
}

void deleteWord(char**& milon,int makom,int &last,int &size)
{
//	for(int i = makom; i < last-1; ++i)
//	{
//		milon[i] = milon[i+1];
//	}
	shiftOneLeft(milon,makom,last);
	last --;
	if (size == (last - INCR))
	{
		decrement(milon,size);
	}
}

void decrement(char**& dict,int &size)
{
	size -= INCR;

	char** temp = new char*[size];
	memcpy(temp,dict,size * sizeof(char*));
	if (dict)
	{
		delete[] dict;
	}
	dict = temp;
}

void increment(char**& dict,int &size)
{
	char** temp = new char*[size + INCR];
	for( int i = 0; i < INCR; ++i)
	{
		temp[size+i] = NULL;
	}
	if (size)
	{
		memcpy(temp,dict,size * sizeof(char*));
	}

	size+=INCR;
	if (dict)
	{
		delete[] dict;
	}
	dict = temp;
}

void insertionSortWord( char* temp,char ** dictionnary,int &used)
{
	if (strcmp(temp,dictionnary[used-1])< 0)
	{
		int mid = binarySearch(dictionnary,temp,used);
		shiftOneRight(dictionnary,mid,used);

		dictionnary[mid] = new char[strlen(temp)+1];
		strcpy(dictionnary[mid],temp);
	}
	else
	{	//then add it to the end of the dictionnary
		dictionnary[used] = new char[strlen(temp)+1];
		strcpy(dictionnary[used],temp);
	}
	++used;
}

void shiftOneRight(char* vec[], int begin, int end)
{
	for ( int i = end; i > begin; --i)
	{
		vec[i] = vec [i -1];
	}
}
void shiftOneLeft(char* vec[], int begin, int end)
{
	for ( int i = begin; i < end -1; ++i)
	{
		vec[i] = vec [i + 1];
	}
}

//search for the right place to insert the word in the dictionnary
int binarySearch(char** vec,char* what, int used)
{
	int low = 0,
		up = used -1,
		mid ;

	while (low <= up)
	{
		mid = (low +up) /2;

		if (low == up)
		{
			//if ( what > vec[mid])
			if (strcmp(what,vec[mid])>0)
			{
				return mid+1;
			}
			else
			{
				return mid;
			}
		}
		//if ( what > vec[mid])
		if (strcmp(what,vec[mid])>0)
		{
			low = mid +1 ;	
		}
		//else if (what < vec[mid])
		else if (strcmp(what,vec[mid])<0)
		{
			up = mid-1;	
		}
		//else if (strcmp(what,vec[mid])==0)
		else	//what == vec[mid]
		{
			return mid;
		}
	}
	return mid;
}

//search existing word in the dictionnary
int dicBinarySearch ( char* arr[],	// the array				//adapted from Meir Komar
						 int low,	// the lower boundary
						 int high,  // the upper boundary
						 char* what)  // what we are looking for
{
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;

		if ( strcmp(what ,arr[mid])== 0)
		{
			return mid;  // found it
		}      
		else if ( strcmp(what,arr[mid])> 0)
		{  
			low = mid + 1; 
		} 
		else  //if (what > arr[mid])
		{
			high = mid - 1;
		}  
	} // end while

	return -1;       // not found
} // end of binary search

int tafrit_rashi()
{
	int choice;
	do
	{
		cout<<"enter 0-5:"<<endl;
		cin>>choice;
		if (choice < 0 || choice > 5)
		{
			cout<<"ERROR"<<endl;
			cin >> choice;
		}

	}
	while(choice < 0 || choice > 5);
	return choice;
}
