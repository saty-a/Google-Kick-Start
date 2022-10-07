#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,e;
    cin>>t;
    e=t;
    while(t--){
        cout<<"Case #"<<(e-t)<<": ";      //  This is to print the case number.
        int n;
        cin>>n;
        string str;
        cin>>str;
        int a=0,b=0,c=0,d=0;
        for(int i=0;i<str.length();i++){
            if(str[i]>=48 && str[i]<=57){
                a++;                            // checking the number of digits in string.
            }else if(str[i]>=65 && str[i]<=90){
                b++;                            // checking the number of Capital Alphabets in string.    
            }else if(str[i]>=97 && str[i]<=122){
                c++;                            // checking the number of small alphabets in string.
            }else{
                d++;                            // checking the number of special characters in string.
            }
        }
        cout<<str;
        int k=0;
        if(a==0){
            cout<<"1";                          // if no digit is present.
            k++;
        }
        if(b==0){
            cout<<"A";                          // if no Capital Alphabet is present.
            k++;
        }
        if(c==0){
            cout<<"a";                          // if no small alphabet is present.
            k++;
        }
        if(d==0){
            cout<<"@";                          // if no special character is present.
            k++;
        }
        if((str.length()+k)<7){                 
            for(int i=1;i<=(7-k-str.length());i++){         // loop runs according to value of k.
                cout<<"a";
            }
        }
        cout<<endl;
    }
	return 0;
}
