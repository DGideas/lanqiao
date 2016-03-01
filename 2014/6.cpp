#include <iostream>
#include <sstream>
#include <cctype>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
        vector<double> calcElement;
        stringstream strstream;
        int times = 0;
        for (int i=0; i<4; i++)
        {
                calcElement.push_back(1);
        }

        int number = 1111;

        while (true)
        {
                if (number > 9999)
                {
                        break;
                }

                string strnumber;
                strstream<<number;
                strstream>>strnumber;
                strstream.clear();

                calcElement[0] = strnumber[3] - 48;
                calcElement[1] = strnumber[2] - 48;
                calcElement[2] = strnumber[1] - 48;
                calcElement[3] = strnumber[0] - 48;

                if (calcElement[0] == 0 ||
                        calcElement[1] == 0 ||
                        calcElement[2] == 0 ||
                        calcElement[3] == 0)
                {
                        number++;
                        continue;
                }

                if (calcElement[0] != calcElement[1] &&
                        calcElement[2] != calcElement[3]) //[0]/[1] * [2]/[3]
                {
                        double A1, A2;
                        double res1, res2;
                        A1 = calcElement[0] / calcElement[1];
                        A2 = calcElement[2] / calcElement[3];
                        res1 = A1 * A2;
                        res2 = (calcElement[0]*10.0+calcElement[2])/
                                (calcElement[1]*10.0+calcElement[3]);
                        //cout<<res1<<" @ "<<res2<<endl;
                        if (float(res1) == float(res2))
                        {
                                times++;
                        }
                }

                number++;
        }
        cout<<times<<endl;
        return 0;
}
