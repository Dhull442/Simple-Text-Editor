#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class editor{
    stack<char> s;
    // string y;
    int lastappendnumbers;
public:
    void append(string x)
    {   
    	for(int i =0;i<x.size();i++)
    	{
        	s.push(x[i]);
    	}
    	// lastappendnumbers=x.size();
    }
    string del(int k)
    {
        string y="";
        for(int i =0;i<k && s.size()!=0;i++)
        {  
        	y = s.top() + y;
            s.pop();
        }
        // cout<<s.top()<<endl;
        return y;
    }
    void print(int k)
    {	
        if(k <= s.size())
        {
            stack<char> tmp;
            while(k<s.size())
            {
                tmp.push(s.top());
                s.pop();
            }
            cout<<s.top()<<endl;
            while(tmp.size()!=0)
            {
                s.push(tmp.top());
                tmp.pop();
            }
        }
    }
    void undo(int lastaction,string y,int last)
    {	//cout<< lastaction<<" ";

        if(lastaction==1)
        {
        	// cout<<last<<endl;
            this->del(last);    
        }
        else if(lastaction==2)
        {
        	// cout<<y<<endl;
            this->append(y);
        }
    }
    void printwhole()
    {
    	while(s.size()>0)
    	{
    		cout<<s.top()<<" ";
    		s.pop();
    	}
    	cout<<endl;
    }
};
int main()
{
    int n;
    cin >> n;
    editor test;
    stack<int> requests;
    stack<string> deletes;
    stack<int> added;
    int action, lastaction=0;
    while(n>0)
    {
        
        cin>> action;
        if(action == 1)
        {	requests.push(action);
            string x;
            cin >> x;
            test.append(x);
            added.push(x.size());
        }
        if(action == 2)
        {
            int k;
            cin>> k;
            requests.push(action);
            deletes.push(test.del(k));
        }
        if(action == 3)
        {
            int k;
            cin >> k;
            test.print(k);
        }
        if(action == 4)
        {	int dothis = requests.top();
            
            requests.pop();
            if(dothis==1)
            {
            	test.undo(dothis,"",added.top());
            	added.pop();
            }
            if(dothis==2)
            {
            	test.undo(dothis,deletes.top(),1);
            	deletes.pop();

            }
        }
        if(action == 5)
        {
        	test.printwhole();
        }
        lastaction = action;
        n--;
    }
}

