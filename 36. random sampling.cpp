/*
after the kth input, for the ith one, we keep it with p = k/i
and randomly replace it with one in k selected item

Prove that the probability for each item to stay selected is k/i:
for i = k + 1:
	for the ith item to stay is p = k/i
	for the prev item to stay is p = 1 - (k/i) * (1/k) = (i-1)/i = k/i
for i = j + 1, j > k;
	assume that p(each item to stay when i = j) = k/j
	then for the j+1 item to stay is k/(j+1)
	for prev any item to stay is:
		p(already stayed) * p(not replaced)
	  = k/j * (1 - k/(j+1) * 1/k) = (k/j）* (j/j+1) = k/(j+1) = k/i
*/

class Solution{
public:
	int k, i;
	vector<int> memory;

	Solution(int k){
		this->k = k;
		i = 0;
	}

	void input(int n){
		i++;
		if (memory.size() < k) memory.push_back(n);
		else{
			if ((rand() % i + 1) > k) return;
			int pos = rand() % k;
			memory[pos] = n;
		}
	}

	void show(){
		
	}
};