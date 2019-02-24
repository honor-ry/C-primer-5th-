#include <iostream> 
using namespace std; 
class stack
{
	float *pstack;
	int nmax;
	int point;
	public:                 //初始化 
		void init(int n=100)
		{
			pstack =new float[n];
			nmax =n;
			point =0;
		}
	float addstack(float);
	float feach(void);
	void copystack(stack &);
	void print(void)
	{
		cout<<"栈中的数据个数: "<<point<<'\n';
		cout<<"当前栈表中的数据为（自栈顶向栈底）：\n";
		for(int i=point -1;i>=0;i--)
		cout<<pstack[i]<<'\t';
		cout<<'\n';
	}
	void freespace(void)
	{
		if(nmax) delete[]pstack;
	}
};
float stack::addstack(float x)
{
	if(point>nmax)
	  pstack[point++]=x;
	else
	  {
	  	float *temp;
	  	temp =new float[nmax+10];
	  	for(int i=0;i<point;i++)
	  	temp[i] =pstack[i];
	  	delete [] pstack;
	  	pstack =temp;
	  	nmax+=10;
	  	pstack[point ++]=x;
	  }
	  return x;
}
float stack::feach()
{
	if(point>0) return pstack[--point];
	else return -1;
}
void stack::copystack(stack &a)
{
	if(&a!=this)
	{
		if(nmax) delete[] pstack;
		pstack =new float[a.nmax];
		nmax=a.nmax;
		point =a.point;
		for(int i=0;i<a.point;i++)
		pstack[i] =a.pstack[i];
	}
}	
int main()
{
	stack s1,s2;
	s1.init();
	s2.init(25);
	for(int i=100;i<=105;i++) s1.addstack(i*25.5);
	for(int i =200;i<=205;i++) s2.addstack(i+50.5);
	s1.print();
	s2.print();
	s2.addstack(560.5);
	s2.print();
	s1.copystack(s2);
	s1.print();
	s2.print();
	s1.freespace();;
	s2.freespace(); 
 } 
