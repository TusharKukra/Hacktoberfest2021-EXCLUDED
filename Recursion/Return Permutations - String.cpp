#include <string>
using namespace std;

int returnPermutations(string input, string output[]){
   	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    if(input.size()==0){
        output[0]="";
        return 1;
    }
    string input1;
    input1=input[0];
    string result[10000];
    int size= returnPermutations(input.substr(1),result);
    int c=0;
    for(int i=0;i<size;i++){
        for(int j=0;j<=result[i].size();j++){
            string s="";
            if(j!=0){
                s= result[i].substr(0,j);
            }
            s+=input1;
            s+=result[i].substr(j);
            output[c]=s;
            c++;
        }
    }
    return c;
}
