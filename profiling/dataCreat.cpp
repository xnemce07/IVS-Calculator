#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include <fstream>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        cout << "ERR\n";
        return 1;
    }
    
    int count = atoi(argv[1]);
    FILE *fp;
    srand (time(NULL));

    ofstream outfile;
    outfile.open("data.txt",ios::trunc);

    double val;
    val=rand() % 100000000000;
    val=val/1000;
    outfile << setprecision(13) << val;

    for (int i = 1; i < count; i++)
    {
        val=rand() % 100000000000;
    val=val/10000;
    outfile << " " << setprecision(13) << val;
    }
    outfile.close();

    return 0;
}