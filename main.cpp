#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;
int n,m;
int v[100][100];
int v2[100][100];
int viz[100];
int grad[100];
int exc_min=99999999;
int exc[100];
int d[100];
vector< pair<int,int> >muchii;
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
int get_min(int *d)
{
	int dmin=999,imin;
	for(int i=1;i<=n;i++)
		if(dmin>d[i]&&d[i]>0)
		{
			dmin=d[i];
			imin=i;
		}
	return imin;

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
		{
			d[i]=grad[i];
			cout<<grad[i]<<" ";
		}
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
		cout<<endl;
		for(int i=1;i<=n;i++)
			cout<<d[i]<<" ";
		cout<<endl;
		for(int i=0;i<k;i++)
		{
			int x=get_min(d);
			muchii.push_back(make_pair(x,codif[i]));
			d[codif[i]]--;
			d[x]--;
			for(int i=1;i<=n;i++)
			cout<<d[i]<<" ";
		cout<<endl;
		}
		for(int i=0;i<muchii.size();i++)
			cout<<muchii[i].first<<" "<<muchii[i].second<<endl;
		cout<<endl;
    }
    else
    {
        cout<<"Creaza un fisier cu graful tau";
    }
	system("pause");
    return 0;
}
