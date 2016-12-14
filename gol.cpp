//sample setup to start the game of life - startlife.cpp

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int SIZE = 20;

//initial function prototypes
void initGrid(bool [][SIZE], bool [][SIZE]);
void readGrid(bool [][SIZE], bool [][SIZE]);
void printGrid2(bool [][SIZE]);

int findNeighbors(bool [][SIZE], int, int);

void determineNextGen(bool [][SIZE], bool [][SIZE]);

int main()
{
     bool life[SIZE][SIZE];
     bool templife[SIZE][SIZE];


     //initGrid(life, templife);


     readGrid(life, templife);
     int neighbors;
     for (int count=0; count< 5; count++)
     {
         determineNextGen(life, templife);
         printGrid2(templife);
     }


    return 0;
}




void readGrid(bool life[][SIZE], bool templife[][SIZE])
{
    int row, col;
    string filename;
    //cout<<"Enter filename: ";
    //cin>>filename;

    ifstream infile("bacteria.txt");
    initGrid(life, templife);
    //ifstream infile(filename.c_str());

    infile >> row >> col;
    while (infile){
        life[row][col] = true;
        infile >> row >> col;
    }
    infile.close();
}


void initGrid(bool life[][SIZE], bool templife[][SIZE])
{
    for (int row = 0; row < SIZE; row++){
        for (int col = 0; col < SIZE; col++){
            life[row][col] = false;
        }
    }

    for (int row = 0; row < SIZE; row++){
        for (int col = 0; col < SIZE; col++){
            templife[row][col] = false;
        }
    }
}




void printGrid2(bool life[][SIZE])
{
    cout << "  01234567890123456789" << endl;
    for (int row = 0; row < SIZE; row++)
    {
        cout << setw(2) << row;
        for (int col = 0; col < SIZE; col++)
        {
            if (life[row][col])
            {
                cout << "*";
            } else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}





int findNeighbors(bool life[][SIZE], int row, int col)
{

    int neighbors=0;



          if(/*life[row][col]== true  &&*/ life[row][col-1]==true && col-1>=0)
          {
          neighbors++;

          }
          if(/*life[row][col]== true  &&*/ life[row+1][col-1]==true && row+1<SIZE && col-1>=0)
          {
          neighbors++;
          }
           if(/*life[row][col]== true  &&*/ life[row+1][col]==true & row+1<SIZE)
          {
          neighbors++;
          }
          if(/*life[row][col]== true  &&*/ life[row][col+1]==true && col+1<SIZE)
          {
          neighbors++;
          }

         if(/*life[row][col]== true  &&*/ life[row-1][col-1]==true && row-1>=0 && col-1>=0 )
          {
          neighbors++;
          }
          if(/*life[row][col]== true  &&*/ life[row+1][col+1]==true && row+1<SIZE && col+1<SIZE)
          {
          neighbors++;
          }
          if(/*life[row][col]== true  &&*/ life[row-1][col]==true && row-1>=0)
          {
          neighbors++;
          }
          if(/*life[row][col]== true  &&*/ life[row-1][col+1]==true && row-1>=0 && col+1<SIZE)
          {
          neighbors++;
          }


  //cout<<"Neighbors: "<<neighbors<<endl;
  //cin.get();

   return neighbors;
}

void determineNextGen(bool life[][SIZE], bool templife[][SIZE])
{
     int neighbors=0;
    //templife[SIZE][SIZE];

 for(int row=0;row<SIZE;row++)
    {
     for(int col=0;col<SIZE;col++)
       {
           neighbors=findNeighbors(life,row,col);
    if (life[row][col]==false)
         {
        if (neighbors==3)
           templife[row][col]=true;
         }
       }
    }

for(int row=0;row<SIZE;row++)
   {
    for(int col=0;col<SIZE;col++)
       {
        neighbors=findNeighbors(life,row,col);
    if (life[row][col]==true)
        {
        if (neighbors<=1)
            {
            templife[row][col]=false;
            }
        if (neighbors>=4)
            {
            templife[row][col]=false;
            }
        if (neighbors==2 || neighbors==3)
            {
            templife[row][col]=true;
            }
        }

      }
   }


}



