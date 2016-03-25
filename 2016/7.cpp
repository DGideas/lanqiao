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
vector<int> tested_tree;
int times = 0;

void dfs(vector<int>);
bool test(vector<int>);
vector<int> test_dfs(vector<int>, vector<int>);
void test_tree_append(int);
vector<int> locate(int);

void dfs(vector<int> num)
{
        int num_size = num.size();
        if (num_size >= 5)
        {
                for (int i=0; i<5; i++)
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
        bool find_status = false;
        for (vector<history>::iterator i = mem.begin();
                i < mem.end();
                i++)
        {
                if (i->compare(ans))
                {
                        find_status = true;
                        break;
                }
        }
        if (find_status == true)
        {
                return false;
        }
        vector<int> tested_node_alloc;
        test_dfs(ans, tested_node_alloc);
        vector<int> tested_tree_alloc;
        if (tested_tree.size() == ans.size())
        {
                tested_tree = tested_tree_alloc;
                sort(tested_tree.begin(), tested_tree.end());
                history tmp_history;
                tmp_history.init(tested_tree);
                mem.push_back(tmp_history);
                return true;
        }
        else
        {
                tested_tree = tested_tree_alloc;
                return false;
        }
}

vector<int> test_dfs(vector<int> ans, vector<int> tested_node)
{
        vector<int> field;
        for (int i=1; i<=12; i++)
        {
                field.push_back(i);
        }
        Sq sq_field(4, 3);
        sq_field.change(field);
        if (tested_node.size() == 0)
        {
                tested_node.push_back(ans[0]);
                test_tree_append(ans[0]);
        }
        vector<int> lc = locate(tested_node.back());
        vector<int> nb = sq_field.get_nb(lc[0], lc[1]);
        for (vector<int>::iterator i = nb.begin();
                i < nb.end();
                i++)
        {
                if (find(ans.begin(), ans.end(), *i) != ans.end())
                {
                        if (find(tested_node.begin(), tested_node.end(), *i) ==
                                tested_node.end())
                        {
                                tested_node.push_back(*i);
                                test_tree_append(*i);
                                test_dfs(ans, tested_node);
                                tested_node.pop_back();
                        }
                }
        }
        return ans;
}

void test_tree_append(int appended_int)
{
        if (find(tested_tree.begin(), tested_tree.end(), appended_int) ==
                tested_tree.end())
        {
                tested_tree.push_back(appended_int);
        }
}

vector<int> locate(int located_num)
{
        vector<int> res;
        for (int i=0; i<2; i++)
        {
                res.push_back(0);
        }
        res[1] = (located_num % 4) - 1;
        res[0] = (located_num - 1) / 4;
        return res;
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
        cout<<mem.size()<<endl;
        return 0;
}
