#include <iostream>
#include <stdio.h>
#include <bitset>  
using namespace std;

int		main(){
    unsigned short short1 = 4;  
    float short2 = 2646376.812;    
    bitset<32> bitset1{short2};   // the bitset representation of 4  
    cout << bitset1 << endl;  // 0000000000000100  l;

	return(0);
}