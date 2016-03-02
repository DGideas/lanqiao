#include <iostream>
#include <sstream>
#include <cctype>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

bool RESULT_FIND_FLAG = false;
const int star_element_count = 12;

void dfs(vector<int>, vector<int>);

void dfs(vector<int> star, vector<int> answers)
{
        if (RESULT_FIND_FLAG == true)
        {
                return;
        }
        int star_element_count = 0;

        for (vector<int>::iterator star_iterator =
                        star.begin();
                star_iterator < star.end();
                star_iterator++)
        {
                if (*star_iterator != 0)
                {
                        star_element_count++;
                }
        }

        if (star_element_count < 12)
        {
                int blank_location = 0;
                for (vector<int>::iterator first_blank_in_star = star.begin();
                        first_blank_in_star < star.end();
                        first_blank_in_star++)
                {
                        if (*first_blank_in_star == 0)
                        {
                                break;
                        }
                        blank_location++;
                }

                for (vector<int>::iterator answer_dfs = answers.begin();
                        answer_dfs < answers.end();
                        answer_dfs++)
                {
                        vector<int> new_answer;
                        for (vector<int>::iterator answer_iterator = answers.begin();
                                answer_iterator < answers.end();
                                answer_iterator++)
                        {
                                if (answer_iterator != answer_dfs)
                                {
                                        new_answer.push_back(*answer_iterator);
                                }
                        }

                        star[blank_location] = *answer_dfs;
                        dfs(star, new_answer);
                }
        }
        else
        {
                int calc1 = star[0] + star[2] + star[5] + star[7];
                int calc2 = star[0] + star[3] + star[6] + star[10];
                int calc3 = star[7] + star[8] + star[9] + star[10];
                int calc4 = star[1] + star[2] + star[3] + star[4];
                int calc5 = star[1] + star[5] + star[8] + star[11];
                int calc6 = star[4] + star[6] + star[9] + star[11];
                if (calc1 == calc2 &&
                        calc1 == calc3 &&
                        calc1 == calc4 &&
                        calc1 == calc5 &&
                        calc1 == calc6)
                {
                        cout<<star[5]<<endl;
                        RESULT_FIND_FLAG = true;
                }
                return;
        }
}

int main(int argc, char* argv[])
{
        vector<int> star;
        for (int i=0; i<star_element_count; i++)
        {
                star.push_back(0);
        }

        star[0] = 1;
        star[1] = 8;
        star[11] = 3;

        vector<int> answers;
        for (int i=0; i<star_element_count; i++)
        {
                switch(i)
                {
                        case 0:
                        case 2:
                        case 7:
                                continue;
                }
                answers.push_back(i+1);
        }

        dfs(star, answers);

        return 0;
}
