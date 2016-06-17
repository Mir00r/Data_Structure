#include <bits/stdc++.h>

using namespace std;

#define LI long int
#define LLI long long int
#define LL __int64
#define ULL unsigned long long
#define LLU long long unsigned
#define row 5
#define col 5
#define MAX 100000
#define jora pair <int, int>
#define memo(array, value) memset(array, value, sizeof(array))
#define pb push_back
#define NL puts ("")
#define inf (1 << 28)
#define eps 1e9
#define MOD 7477777
#define PI 3.1415926535897932384626433832795
#define PrimeRange 1000000
#define CharRange 255



int Hanoi ( int disk, int src, int des, int aux ) {
    if ( disk == 0 )
        printf ("Move Diske -> %d from -> %d peg to -> %d peg\n\n", disk, src, des );
    else{
        Hanoi( disk - 1, src, aux, des );

        //Move the remaining disk to the destination peg.
        printf ("Move Diske %d from %d peg to %d peg\n\n", disk, src, des );

        //Move the disks we just moved to the spare back over to the dest peg.
        Hanoi( disk - 1, aux, des, src );
    }

}

int main () {

    int disk, src, des, aux;

    printf ("Enter number of disk: "); scanf ("%d", &disk);
    printf ("Enter Source: "); scanf ("%d", &src );
    printf ("Enter Destination: "); scanf ("%d", &des);
    printf ("Enter Auxilary tower: "); scanf ("%d", &aux);

    Hanoi ( disk, src, des, aux );
    return 0;
}
