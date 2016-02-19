// Ref : http://www.geeksforgeeks.org/largest-rectangle-under-histogram
#include <bits/stdc++.h>

using namespace std;

#define LI long int
#define LLI long long int
#define LL __int64
#define ULL unsigned long long
#define LLU long long unsigned
#define row 205
#define col 205
#define MAX 1000002
#define jora pair <int, int>
#define memo(array, value) memset(array, value, sizeof(array))
#define pb push_back
#define NL puts ("")
#define inf (1 << 28)
#define eps 1e9
#define mod 7477777
#define PI 3.1415926535897932384626433832795


int Call_Max_Area ( int h[], int n) {
	int i = 0, Top;
	int max_area = 0;
	int area_with_top ;
	
	stack <int> st;
	
	while ( i < n ){
		// If this bar is higher than the bar on top stack, push it to stack
		if ( st.empty() || h[ st.top() ] <= h[i] )
			st.push ( i++ );
		
		// If this bar is lower than top of stack, then calculate area of rectangle 
        // with stack top as the smallest (or minimum height) bar. 'i' is 
        // 'right index' for the top and element before top in stack is 'left index'
		else{
			Top = st.top();
			//printf ("Top_Value =%d\n", Top);
			st.pop();
			
			 // Calculate the area with h[Top] stack as smallest bar
			
			if ( st.empty () )
				area_with_top = h[ Top ] * i;
			else
				area_with_top = h[ Top ] * ( i - st.top() - 1 );
			
			// Update Maximum Area 
			if ( max_area < area_with_top)
				max_area = area_with_top;
		}	
	}
	
	// Now pop the remaining bars from stack and calculate area with every
    // popped bar as the smallest bar
	while ( st.empty () == false ){
		Top = st.top();
		st.pop();
		
		
		// Calculate the area with h[Top] stack as smallest bar
		if ( st.empty() )
			area_with_top = h[ Top ] * i;
		else
			area_with_top = h[ Top ] * ( i - st.top() - 1 );
		
		// Update Maximum Area 
		if ( max_area < area_with_top)
			max_area = area_with_top;
	}
	return max_area;
}


int main (){
	int n, height[MAX], i;
	
	scanf("%d", &n);
	for ( i = 0; i < n; i++)
		scanf ("%d", &height[i] );
	
	printf ("%d\n", Call_Max_Area ( height, n ) );
	return 0;
}
