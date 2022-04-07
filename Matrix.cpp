#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll min(ll a,ll b)
{
    if(a<b){
        return a;
    }
    return b;
}


int main() 
{
    ll t;
    cin>>t;
    while(t-- != 0)
    {
        ll n,m,k;
        //#
        cin>>n>>m>>k;

        double Mat[n+1][m+1];     // worthy matrix 
        ll i, j;
        for(i=0; i<=n; i++)
        {
            for(j=0; j<=m; j++)
            {
                if(i==0 || j==0) {Mat[i][j] = 0;}
                     else   {cin>>Mat[i][j];}
            }
        }
        for(ll i=0; i<=n; i++)
        {
            double bac=0;

            for(ll j=0; j<=m; j++)          // ## //
            {
                Mat[i][j] += bac;
                bac = Mat[i][j];
            }
        }
        for(ll j=0; j<=m; j++)
        {   //#
            double bac = 0;
            //#
            for(ll i=0; i<=n; i++)
            {
                Mat[i][j] += bac;
                bac = Mat[i][j];
            }
        }
        ll z = min (n,m);
        ll res = 0;
        for(ll size=1; size<=z; size++)
        {
            for(ll i=size; i<=n; i++)
            {
                for(ll j=size; j<=m; j++)
                {
                    if((Mat[i][j] + Mat[i-size][j-size] - Mat[i][j-size] - Mat[i-size][j]) / (size*size)>=k) 
                    {
                        res++;
                    }
                }
            }
            
        }
        cout<<res<<endl;
    }
}
