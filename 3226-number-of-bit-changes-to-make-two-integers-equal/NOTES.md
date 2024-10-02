class Solution {
public:
int minChanges(int n, int k) {
int c = 0;
for(int i=0;i<31;i++){
int bit_mask = (1<<i); // (1) (1 0) (1 0 0)....
int b1 = n & bit_mask;
int b2 = k & bit_mask;
if(b2 == 0 && b1 != 0){
n ^= bit_mask; // flip
c++;
}
}
return (n == k ? c:-1);
}
};