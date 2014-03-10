#include <stdio.h>

struct node {
    int parent;
    char ch;
};
int flag[20005];
int n;
int Q[20005];
struct node nodes[20005];

void getNumber(int &end) {
    if(end==-1) return;
    getNumber(nodes[end].parent);
    putchar(nodes[end].ch);
}

int main() {
    int t, i, l;
    int qh, qt, first, second, curr;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        if(n==1) {
            puts("1");
        }else{
            for(i=0; i<n; i++) flag[i] = 0;
            qh = qt = 0;
            Q[qt++] = 1;
            flag[1] = 1;
            nodes[1].parent = -1;
            nodes[1].ch = '1';
            while(1) {
                curr = Q[qh++];
                first = (curr * (10 % n)) %  n;
                second = (first+1) % n;
                if(!flag[first]) {
                        nodes[first].parent = curr;
                        nodes[first].ch = '0';
                        if(!first) break;
                        flag[first] = 1;
                        Q[qt++] = first;
                }
                if(!flag[second]) {
                        nodes[second].parent = curr;
                        nodes[second].ch = '1';
                        if(!second) break;
                        flag[second] = 1;
                        Q[qt++] = second;
                }
            }
            int z = 0;
            getNumber(z);
        }
        putchar('\n');
    }
    return 0;
}
