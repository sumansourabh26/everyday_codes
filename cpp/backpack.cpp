#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*remaining[][0]=>weight
*remaining[][1]=>value
**remaining[][2]=>attachment of(this)
*/




int backpack(int weight, int remaining[][3], int start, int& ending, bool sold[]){
    if(weight == 0){
        return 0;
    }
    if(remaining[start][2] != 0){
        int if_left = backpack(weight, remaining, start+1, ending, sold);
        int if_buy = remaining[start][1] + backpack(weight-remaining[start][0], remaining, start+1,ending));
        if(if_buy >= if_left) sold[start] = true;
        return max(if_buy, if_left);
    }
    else{

    }

}

int main(){


}
