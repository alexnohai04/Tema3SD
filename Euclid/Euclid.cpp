#include <fstream>

using namespace std;
ifstream f("euclid.in");
ofstream g("euclid.out");
int dp[401][401];
int cmmdc(int a, int b)
{
    int r;
    while(b>0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    int rows,cols,width,height,i,j,logHeight,logWidth,maxi,cop,k,subgridTop,subgridLeft,x,y;
    f>>y;
    for(x=1;x<=y;x++)
    {
        f>>rows>>cols>>height>>width;
        cop=height;
        logHeight=0;
        while(cop>0)
        {
            cop>>=1;
            logHeight++;
        }
        logHeight--;
        cop=width;
        logWidth=0;
        while(cop>0)
        {
            cop>>=1;
            logWidth++;
        }
        logWidth--;
        for(i=1;i<=rows;i++)
            for(j=1;j<=cols;j++)
                f>>dp[i][j];
        for(k=1;k<=logWidth;k++)
            for(i=1;i<=rows;i++)
                for(j=1;j+(1<<k)-1<=cols&&j<=cols;j++)
                    dp[i][j]=cmmdc(dp[i][j],dp[i][j+(1<<(k-1))]);
        for(k=1;k<=logHeight;k++)
            for(i=1;i+(1<<k)-1<=rows&&i<=rows;i++)
                for(j=1;j+(1<<logWidth)-1<=cols&&j<=cols;j++)
                    dp[i][j]=cmmdc(dp[i][j],dp[i+(1<<(k-1))][j]);
        maxi=1;
        subgridTop=1<<logHeight;
        subgridTop=height-subgridTop;
        subgridLeft=1<<logWidth;
        subgridLeft=width-subgridLeft;
        for(i=1;i+height-1<=rows;i++)
            for(j=1;j+width-1<=cols;j++)
                maxi=max(maxi,cmmdc(cmmdc(cmmdc(dp[i][j],dp[i+subgridTop][j]),dp[i][j+subgridLeft]),dp[i+subgridTop][j+subgridLeft]));
        g<<"Case #"<<x<<": ";
        g<<maxi<<'\n';
    }
    return 0;
}