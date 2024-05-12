// Permutation Difference between Two Strings
class Solution {
    public int findPermutationDifference(String s, String t) {
        int[] sPositions = new int[26];
        int[] tPositions = new int[26];
        for (int i = 0 ; i< s.length(); i++) {
            sPositions[s.charAt (i) - 'a'] = i;
            tPositions[t.charAt (i) - 'a'] = i;

        }
           int difference = 0;
        for (int i = 0; i < 26; i++) {
            difference += Math.abs (sPositions[i] - tPositions[i]);

        }
        return difference;

        
    }
}
