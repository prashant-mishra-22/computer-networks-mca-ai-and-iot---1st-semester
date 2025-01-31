
#include <iostream>
#include<string>

using namespace std ;
void encipher(string &str,int key=3){
    int n=str.size();
    key=key%26;
    for(int i=0;i<n;i++){
        int temp=int(str[i]);
        if( 65<=temp && temp<=90 )
        {
            temp=temp+key;
            if(temp>90)
            {
                temp=temp-26;
            }
            str[i]=char(temp);
        }
        else if(97<=temp && temp<=122)
        {
            temp=temp+key;
            if(temp>122)
            {
                temp=temp-26;
            }
            str[i]=char(temp);
        }
    }
}
int main() {
    int key;
    string pln_str;
    cout<<"enter the palne text to encipher : ";
    getline(cin,pln_str);
    
    cout<<"\nenter the key : ";
    cin>>key;
    
    cout<<"\nentered plain text : "<<pln_str;
    cout<<"\n\nentered key : "<<key;
    
    encipher(pln_str,key);
    
    cout<<"\n\nenciphered text : "<<pln_str;
    

    return 0;
}