class Solution{
public:
	int sameLetter(string s, int k){
		return max(helper(s, 'A', 'B', k), helper(s, 'B', 'A', k));
	}

	//replace b with a
	int helper(string s, char a, char b, int k){
		int i = 0, j = 0, longest = 0;
		while (j <= s.size()){
			if (s[j++] == b){
				k--;
				if (k < 0){
					while (s[i] == a) i++;
					i++;
				}
			}
			longest = max(longest, j - i);
		}
		return longest;
	}
};