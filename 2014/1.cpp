#include <iostream>
#include <cctype>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
        float beer = 2.3;
        float drink = 1.9;
        float total = 82.3;
        for (int beerNum=0; beerNum<1000; beerNum++)
        {
                for (int drinkNum=0; drinkNum<1000; drinkNum++)
                {
                        if (beerNum < drinkNum)
                        {
                                if ((beerNum * beer + drinkNum * drink) == total)
                                {
                                        cout<<"beer: "<<beerNum<<endl;
                                        cout<<"drink: "<<drinkNum<<endl;
                                }
                        }
                }
        }
        return 0;
}
