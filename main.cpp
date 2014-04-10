#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
int n,m;
int v[100][100];
int v2[100][100];
int viz[100];
int grad[100];
int exc_min=99999999;
int exc[100];
queue<int> que;
int codif[100];
int nodMinim(int &leg)
{
	for(int i=1;i<=n;i++)
		if(grad[i]==1)
		{
			for(int j=1;j<=n;j++)
				if(v[i][j])
					leg=j;
			return i;
		}
}

int main()
{

    ifstream f("graf.txt");
	ofstream g("graf.out");
    if(f!=NULL)
    {
        f>>n>>m;
        int a,b;
        for(int i=1; i<=m; i++)
        {
            f>>a>>b;
            v[a][b]=v[b][a]=1;
			grad[a]++;
			grad[b]++;
        }
		for(int i=1;i<=n;i++)
			cout<<grad[i]<<" ";
		cout<<endl;
		int k=0,j,leg;
		while(k<n-2)
		{
			j=nodMinim(leg);
			codif[k++]=leg;
			grad[leg]--;
			grad[j]--;
		}
        for(int i=0;i<k;i++)
		{
			cout<<codif[i]<<" ";
			g<<codif[i]<<" ";
		}
		for(int i=0;i<k;i++)
		{

		}
    }
    else
    {
        cout<<"Creaza un fisier cu graful tau";
    }
	system("pause");
    return 0;
}
