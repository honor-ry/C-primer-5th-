#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

istream& func(istream& is)
{
string buf;
while (is >> buf) 
    std::cout << buf << std::endl;
is.clear();
return is;
}

int main(int argc, char**argv)
{
/*两种文件流皆有open和close函数，之后视情况打开读或者写模式*/
string infile = "1.txt";//代表文件名
vector<string> vec;//声明一个vector
ifstream in(infile);//ifstream定义了一个输入流in(文件流)，它被初始化从文件中读取数据
istringstream iss("hello");
func(iss);


return 0;
}
