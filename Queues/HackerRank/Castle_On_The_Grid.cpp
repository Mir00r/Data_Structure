#include <bits/stdc++.h>

using namespace std;

#define LI long int
#define LLI long long int
#define LL __int64
#define ULL unsigned long long
#define LLU long long unsigned
#define row 105
#define col 105
#define MAX 1000000 + 5
#define jora pair <int, int>
#define memo(array, value) memset(array, value, sizeof(array))
#define pb push_back
#define NL puts ("")
#define inf (1 << 28)
#define eps 1e9
#define MOD 7477777
#define PI 3.1415926535897932384626433832795
#define PrimeRange 1500

int n , sr, sc, dr, dc;
char grid[ row ][ col ];
bool visited[ row ][ col ];
int Shortes_Path[ row ][ col ];

//int X_arr[] = {-1, 1, 0, 0};
//int Y_arr[] = {0, 0, -1, 1};

//int direction[][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool Corner_Check ( int r, int c ) {
    if ( r < 0 || r >= n || c < 0 || c >= n ) return false;
    return true;
}


void BFS ( int r, int c ) {
    int ans = 0, x, y, ax, ay, i, j;
    //queue < int > Q;
    //Q.push ( r );
   // Q.push ( c );

    queue < jora > Q;
    Q.push ( jora ( r, c ) );

//    memo ( Shortes_Path, -1 );
//    memo ( visited, false );

    Shortes_Path[ r ][ c ] = 0;

    while ( Q.empty() == false ) {
      //  x = Q.front (); Q.pop ();
       // y = Q.front (); Q.pop ();

        jora top = Q.front();
        x = top.first;
        y = top.second;
        Q.pop();
        visited[ x ][ y ] = true;

//        int direction[][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int X_arr[] = {-1, 1, 0, 0};
        int Y_arr[] = {0, 0, -1, 1};

        for ( i = 0; i < n; i++ ) {

            for ( j = 0; j < 4; j++ ) {

                ax = x + ( X_arr[ j ] * i );
                ay = y + ( Y_arr[ j ] * i );
//                ax = x + direction[ j ][ 0 ] * i;
//                ay = y + direction[ j ][ 1 ] * i;

                if ( Corner_Check ( ax, ay ) ) {

                    if ( grid[ ax ][ ay ] == 'X' ) {
                        X_arr[ j ] = 0;
                        Y_arr[ j ] = 0;
//                        direction[ j ][ 0 ] = 0;
//                        direction[ j ][ 1 ] = 0;
                        continue;
                    }

                    if ( visited[ ax ][ ay ] == false ) {

                        if ( Shortes_Path[ ax ][ ay ] == -1 ) {
                            Q.push ( jora ( ax, ay ) );
                            Shortes_Path[ ax ][ ay ] = Shortes_Path[ x ][ y ] + 1;
                        }

                        else if ( Shortes_Path[ ax ][ ay ] > Shortes_Path[ x ][ y ] + 1 )
                            Shortes_Path[ ax ][ ay ] = Shortes_Path[ x ][ y ] + 1;
                    }
                }
            }

        }

    }
}


int main() {
    int i, j, ans;

    memo ( Shortes_Path, -1 );
    memo ( visited, 0 );

    scanf ("%d", &n);
    for ( i = 0; i < n; i++ ) scanf ( "%s", grid[i] );
    scanf ("%d %d %d %d", &sr, &sc, &dr, &dc );

    BFS ( sr, sc );

    printf ("%d\n", Shortes_Path[ dr ][ dc ] );
    return 0;
}
