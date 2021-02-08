#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main()
{
    ///All You Have To Change is Values of Tax Bracket
    /// AND Tax Rate (Marginal Tax Rate) Enjoy :)
    ll TaxBracket[] = {0,8500,34500,83600,174400,379150},idx = 0;
    ld TaxRate[] = {0.10,0.15,0.25,0.28,0.33,0.35}, Amount = 0 , TaxBase , Percentage;
    ll sz = sizeof(TaxBracket)/sizeof(TaxBracket[0]);
    vector<ll> TaxBracketPrefix;
    for(ll i=1;i<sz;i++) TaxBracketPrefix.push_back((TaxBracket[i]-TaxBracket[i-1]));
    printf("Please Enter Your Income:\n");
    scanf("%Lf",&TaxBase);
    Percentage = TaxBase;
while(true)
{
    if(TaxBase <= 0) break;
    if(idx>= (ll)TaxBracketPrefix.size())
    {
        Amount += (1.0 * TaxBase * TaxRate[idx]);
        TaxBase -= TaxBase;
        break;
    }
    else if(TaxBase < TaxBracketPrefix[idx] )
    {
        Amount += (1.0 * TaxBase * TaxRate[idx]);
        TaxBase -= TaxBase;
        break;
    }
    else if(TaxBase >= TaxBracketPrefix[idx])
    {
        Amount += (1.0 * TaxBracketPrefix[idx] * TaxRate[idx]);
        TaxBase -= TaxBracketPrefix[idx];
        idx++;
    }
}
    Percentage = Amount/Percentage * 100 ;
    cout<<fixed<<setprecision(3);
    cout <<"Amount Of Tax That Will Be Paid: $"<<Amount<<"\n";
    cout<<"Which Represents "<<Percentage<<" % of Your Income";
    return 0;
}
