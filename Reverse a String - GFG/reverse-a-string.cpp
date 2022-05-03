// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;


string reverseWord(string str);


int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}

// } Driver Code Ends


//User function Template for C++

string reverseWord(string str){
    int n =str.size();
    int st=0,en=n-1;
    while(st<en){
        char temp = str[st];
        str[st]=str[en];
        str[en]=temp;
        
        st++;
        en--;
    }
    return str;
  //Your code here
}