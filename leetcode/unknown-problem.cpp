/*
 * Unknown Problem
 * Difficulty: Unknown Difficulty
 * 
 * Unknown Description
 */

class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            int currOpNeeded =0;
            for (int i=0;i<k;i++){
                if (blocks[i]=='W'){
                    currOpNeeded++;
                }
            }
            int minAns = currOpNeeded;
            for (int i=k;i<blocks.size();i++){
                // cout<<(blocks[i]!=blocks[i-k])<<endl;
                if (blocks[i]!=blocks[i-k]){
                    if (blocks[i]=='B')
                    currOpNeeded--;
                else {
                    currOpNeeded++;}