//Taking Maximum Energy From the Mystic Dungeon
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int Max=INT_MIN;

        int n = energy.size();


        for(int i=n-1; i>=n-k; i--){
            int sum=0;
            for (int j = i; j>=0; j=j-k){
                sum+=energy[j];
                Max=max(Max,sum);
            }
        }
        return Max;
        
    }
};
