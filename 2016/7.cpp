#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Sq
{
        public:
                Sq(int, int);
                void change(vector<int>);
                void resize(int, int);
                int get(int, int);
                vector<int> get_nb(int, int);
        private:
                int length;
                int height;
                vector<int> a;
};

Sq::Sq(int length, int height)
{
        this->resize(length, height);
}

void Sq::change(vector<int> changed_vector)
{
        this->a = changed_vector;
        return;
}

void Sq::resize(int length, int height)
{
        this->length = length;
        this->height = height;
        return;
}

int Sq::get(int height, int length)
{
        if (height >= 0 &&
                height < this->height &&
                length >= 0 &&
                length < this->length)
        {
                int index = height*this->length + length;
                return this->a[index];
        }
}

vector<int> Sq::get_nb(int height, int length)
{
        vector<int> res;
        if (height > 0 && length >= 0)
        {
                res.push_back(this->get(height, length-1));
        }
        if (height >= 0 && length > 0)
        {
                res.push_back(this->get(height-1, length));
        }
        if (height >= 0 && length < this->length-1)
        {
                res.push_back(this->get(height, length+1));
        }
        if (height < this->height-1 && length >= 0)
        {
                res.push_back(this->get(height+1, length));
        }
        return res;
}

class history
{
        public:
                history();
                bool compare(vector<int>);
                void init(vector<int>);
        private:
                vector<int> history_element;
};

history::history()
{
        for (int i=0; i<5; i++)
        {
                this->history_element.push_back(0);
        }
}

void history::init(vector<int> inited_vector)
{
        this->history_element = inited_vector;
}

bool history::compare(vector<int> cmp)
{
        if (cmp.size() != this->history_element.size())
        {
                return false;
        }
        for (int i=0; i<cmp.size(); i++)
        {
                if (cmp[i] != history_element[i])
                {
                        return false;
                }
        }
        return true;
}

vector<int> numbers;
vector<history> mem;
int times = 0;

void dfs(vector<int>);
bool test(vector<int>);

void dfs(vector<int> num)
{
        int num_size = num.size();
        if (num_size >= 5)
        {
                for (int i=0; i<num.size(); i++)
                {
                        cout<<num[i]<<" ";
                }
                cout<<endl;
                if (test(num))
                {
                        times++;
                }
                return;
        }
        else
        {
                vector<int> possible_num;
                for (int i=0; i<numbers.size(); i++)
                {
                        if (find(num.begin(), num.end(), numbers[i]) == num.end())
                        {
                                possible_num.push_back(numbers[i]);
                        }
                }
                for (int i=0; i<possible_num.size(); i++)
                {
                        num.push_back(possible_num[i]);
                        dfs(num);
                        num.pop_back();
                }
                return;
        }
}

bool test(vector<int> ans)
{
        sort(ans.begin(), ans.end());
        bool find_status = true;
        for (vector<history>::iterator i = mem.begin();
                i < mem.end();
                i++)
        {
                if (i->compare(ans))
                {
                        find_status = false;
                        break;
                }
        }
        if (find_status == false)
        {
                return false;
        }

}

int main(int argc, char* argv[])
{
        vector<int> a;
        for (int i=1; i<=12; i++)
        {
                a.push_back(i);
                numbers.push_back(i);
        }
        vector<int> numbers_alloc;
        dfs(numbers_alloc);
        cout<<"times: "<<times<<endl;
        return 0;
}
