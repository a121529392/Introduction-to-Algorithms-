#include<iostream>
#include<vector>
using namespace std;
struct node{
	vector<int> next;
	vector<int> len;
	int answer;
	bool f=false;
};
struct hold{
	vector<int> parent;
	vector<int> next;
	vector<int> len;
};
struct keep{
	int parent;
	int next;
	int len;
	int number;
};
int main(){
	int n;
	int edge;
	cin >> n;
	cin >> edge;
	node *num;
	num = new node[n];
	int a,b,c;
	for (int i = 0; i < edge; i++){
		cin >> a>>b>>c;
		num[a].next.push_back(b);
		num[a].len.push_back(c);

	}
	num[0].f = true;
	num[0].answer = 0;
	hold h;
	keep keep;
	for (int i = 0; i < num[0].len.size(); i++){
		h.parent.push_back(0);
		h.next.push_back(num[0].next[i]);
		h.len.push_back(num[0].len[i]);
	}
	bool t=true;
	while (t){
		int count=0;
		for (int i = 0; i < n; i++){
			if (num[i].f == true){
				count++;
			}
		}
		if (count == n){
			t = false;
		}
		keep.len = h.len[0];
		keep.next = h.next[0];
		keep.parent = h.parent[0];
		keep.number = 0;
		for (int i = 0; i < h.next.size(); i++){
			if (h.len[i] < keep.len){
				keep.len = h.len[i];
				keep.next = h.next[i];
				keep.parent = h.parent[i];
				keep.number = i;
			}
		}
		if (num[keep.next].f == false){
			num[keep.next].answer = keep.len + num[keep.parent].answer;
			num[keep.next].f = true;
		}
		h.len.erase(h.len.begin()+keep.number);
		h.next.erase(h.next.begin() + keep.number);
		h.parent.erase(h.parent.begin() + keep.number);
		for (int i = 0; i < num[keep.next].next.size(); i++){
			h.parent.push_back(keep.next);
			h.next.push_back(num[keep.next].next[i]);
			h.len.push_back(num[keep.next].len[i]);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++){
		if (num[i].answer>ans){
			ans = num[i].answer;
		}
	}

	cout << endl << ans;

	system("pause");
}