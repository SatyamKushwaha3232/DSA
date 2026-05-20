#include <iostream>
using namespace std;
void pattern1(int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
void pattern2(int n){
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
void pattern3(int n){
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}
void pattern4(int n){
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            cout<<j<<" " ;
        }
        cout<<endl;
    }
}
void pattern5(int n){
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n-i+1;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
void pattern6(int n){
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n-i+1;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
void pattern7(int n){
    int i,j;
    for(i=1;i<=n;i++){
        //space
         for(j=1;j<=n-i;j++){
            cout<<" ";
        }
         //star
         for(j=1;j<=(i*2)-1;j++){
            cout<<"*";

        }
         //space
         for(j=1;j<=n-i;j++){
            cout<<" ";
        }
         cout<<endl;
    }
}
void pattern8(int n){
    int i,j;
    for(i=0;i<n;i++){
        //space
         for(j=0;j<i;j++){
            cout<<" ";
        }
         //star
         for(j=0;j<(n*2)-(i*2)-1;j++){
            cout<<"*";

        }
         //space
         for(j=0;j<i;j++){
            cout<<" ";
        }
         cout<<endl;
    }
}
void pattern9(int n){
    pattern7(n);
    pattern8(n);
}
void pattern10(int n){
    int i,j;
    for(i=1;i<=(n*2)-1;i++){
        int stars = i;
        if(i>n)stars = 2*n-i;
         for(j=1;j<=stars;j++){
            cout<<"*";
            }
             cout<<endl;
        }
       
    }
void pattern11(int n){
    int i,j;
    int start=1;
    for(i=0;i<n;i++){
        if(i%2 == 0)
        start=1;
        else 
        start=0;
        for(j=0;j<=i;j++){
            cout<<start;
            start=1-start;
        }
        cout<<endl;

    }
}
void pattern12(int n){
    int i,j;
    for(i=1;i<=n;i++){
        //number
        for(j=1;j<=i;j++)
        cout<<j;
        //space
        for(j=1;j<=(n*2)-2*i;j++)
        cout<<" ";
        //number
        for(j=i;j>=1;j--)
        cout<<j;
        cout<<endl;
    }
    
}
void pattern13(int n){
    int i,j;
    int num=1;
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            cout<<num<<" ";
            num=num+1;
        }
        cout<<endl;
    }
}
void pattern14(int n){
    int i;
    for(i=0;i<n;i++){
        for(char ch='A';ch<='A'+i;ch++){
            cout<<ch<<" ";
        }
        cout<<endl;

    }
}
void pattern15(int n){
    int i;
    for(i=1;i<=n;i++){
        for(char ch='A';ch<='A'+(n-i);ch++){
            cout<< ch <<" ";
        }
        cout<<endl;

    }
}
void pattern16(int n){
    int i;
    
    for(i=0;i<n;i++){
        char ch='A'+i;
        for(int j=0;j<=i;j++){
            
            cout<< ch<<" ";
           
        }
        cout<<endl;

    }
}
void pattern17(int n){
    for(int i = 0; i < n; i++){
        // spaces
        for(int j = 0; j < n - i - 1; j++){
            cout << " ";
        }
        // increasing characters
        char ch = 'A';
        for(int j = 0; j <= i; j++){
            cout << ch;
            ch++;
        }
        // decreasing characters
        ch =ch- 2;
        for(int j = 0; j < i; j++){
            cout << ch;
            ch--;
        }
        cout << endl;
    }
}
void pattern18(int n) {
    char end = 'A' + n - 1; // This will always be 'E' for n=5
    for (int i = 0; i < n; i++) {
        // Start from 'A' + (n - i - 1)
        char start = 'A' + (n - i - 1);
        for (char ch = start; ch <= end; ch++) {
            cout << ch;
        }
        cout << endl;
    }
}
void pattern19_1(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++)
        cout<<"*";
        for(int j=0;j<2*i;j++)
        cout<<" ";
        for(int j=0;j<n-i;j++)
        cout<<"*";
        cout<<endl;
    }
}
void pattern19_2(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++)
        cout<<"*";
        for(int j=0;j<2*(n-i-1);j++)
        cout<<" ";
        for(int j=0;j<=i;j++)
        cout<<"*";
        cout<<endl;
    }
}
void pattern19(int n){
    pattern19_1(n);
    pattern19_2(n);
}
void pattern20(int n){
    int i,j;
    for(i=1;i<=(n*2)-1;i++){
        int stars = i;
        if(i>n)
        stars = 2*n-i;
        //stars
         for(j=1;j<=stars;j++){
            cout<<"*";
            }
        //space
        for(j=1;j<=2*(n-stars);j++){
           cout<<" "; 
        }
        //stars
        for(j=1;j<=stars;j++){
            cout<<"*";
            }
             cout<<endl;
        }
       
    }
void pattern21(int n){
    int i,j;
    for(i=1;i<=n;i++){
        int star=i;
        for(j=1;j<=n;j++){
            int stars=j;
            if(star==1||stars==1||star==n||stars==n){
                cout<<"*";
            }
            else
            cout<<" ";
        }cout<<endl;
    }
}
void pattern22(int n){
    for(int i=0;i<(2*n)-1;i++){
        for(int j=0;j<(2*n)-1;j++){
            int top=i;
            int left=j;
            int right=(2*n-2)-j;
            int bottom=(2*n-2)-i;
            cout<<(n- min(min(top,bottom),min(left,right)));

        }
        cout<<endl;
    }
}
int main() {
    int x;
    cin >> x;
    for(int i=0;i<x;i++){
       int y;
    cin>>y;
    
    pattern22(y);
    }
    return 0;
   
}