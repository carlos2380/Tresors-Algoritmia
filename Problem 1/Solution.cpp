#include <iostream>
#include <vector>
using namespace std;


bool comprovar(int f, int c, int n, int m) {
	if(f < 0 or c < 0 or c > m or f > n) return false;
	else return true;
}

int buscar_profundidad(int f, int c, const vector<vector<char> > &v, vector<vector<bool> > &x, int n, int m, bool &trobat) 
{
	if(not trobat){
		if(comprovar(f, c, n, m)) {
			if (v[f][c] != 'X' and x[f][c] == false)
			{	
				x[f][c] = true;
				if (v[f][c] == 't') return 1;
				int res = 0;
				res = buscar_profundidad(f, c-1, v, x, n, m, trobat);
				if (res == 1) {trobat = true; return 1;}
				res = buscar_profundidad(f-1, c, v, x, n, m, trobat);
				if (res == 1) {trobat = true; return 1;}
				res = buscar_profundidad(f+1, c, v, x, n, m, trobat);
				if (res == 1) {trobat = true; return 1;}
				res = buscar_profundidad(f, c+1, v, x, n, m, trobat);
				if (res == 1) {trobat = true; return 1;}
			}
		}
	}
	return 0;
}

int main()
{
	int n , m;
	cin >> n >> m;

	vector<vector<char> > v(n, vector<char> (m));
	vector<vector<bool> > x(n, vector<bool> (m, false));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> v[i][j]; 

	/*for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) { 
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	*/

	int f,c;
	cin >> f >> c;
	bool trobat = false;
	int result  = buscar_profundidad(f-1, c-1, v, x, n-1, m-1, trobat);

	if (result > 0) cout << "yes" << endl;
	else cout << "no" << endl;
}