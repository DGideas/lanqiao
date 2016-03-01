#include <iostream>
#include <sstream>
#include <cctype>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int times = 0;

void dfs(int, int, int, int);

void dfs(int deepth, int wine, int shopCount, int flowerCount)
{
        if (wine <= 0)
        {
                return;
        }
        if (deepth == 14)
        {
                if (wine == 1)
                {
                        times++;
                }
                return;
        }
        else
        {
                bool shopStatus = true;
                bool flowerStatus = true;
                if (shopCount + 1 > 5)
                {
                        shopStatus = false;
                }
                if (flowerCount + 1 > 9)
                {
                        flowerStatus = false;
                }

                if (shopStatus == true)
                {
                        dfs(deepth+1, wine*2, shopCount+1, flowerCount);
                }
                if (flowerStatus == true)
                {
                        dfs(deepth+1, wine-1, shopCount, flowerCount+1);
                }
        }
}

int main(int argc, char* argv[])
{
        dfs(0, 2, 0, 0);
        cout<<times<<endl;
        return 0;
}
