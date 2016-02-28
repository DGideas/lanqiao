//一根高筋拉面，中间切一刀，可以得到2根面条
#include <iostream>
#include <cctype>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
        int L1 = 1;
        int L2 = 0;
        int R = 1;
        int n;
        cin>>n;
        if (n == 0)
        {
                cout<<"2"<<endl;
                return 0;
        }
        for (int i=0; i<n; i++)
        {
                L1 += L2;
                L2 = R;
                R = pow(2, i);
        }
        cout<<L1 + L2 + R<<endl;
        return 0;
}
