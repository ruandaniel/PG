struct Node{
	int index;
	char c;
	Node *parent;

	Node(int i = -1, char a = '#', Node *p = NULL) : index(i), c(a), parent(p) {}
};

class MString{
public:
	char *s;
	int index;
	int len;
	Node *cur;

	MString(char* a, int i, int l, Node *v) : s(a), index(i), len(l), cur(v) {}

	char charAt(int x){
		return *(s + x);
	}

	MString subString(int start, int end){
		return *(new MString(s, start, end - start, cur));
	}

	void setCharAt(int i, char c){
		Node *n = new Node(i, c, cur);
		cur = n;
	}

	void print(){
		string str = "";
		for (int i = index; i < index + len; i++)
			str += s[i];
		vector<bool> done(len, false);
		auto p = cur;
		while (p->parent != NULL){
			if (!done[p->index]){
				done[p->index] = true;
				str[p->index] = p->c;
			}
			p = p->parent;
		}
		cout << str << endl;
	}
};

void main(){
	char addr[] = "goodsss";
	Node *root = new Node();
	MString A = *(new MString(addr, 0, 7, root));
	MString C = A.subString(0, 5);
	A.print();
	C.print();
	A.setCharAt(4, 'd');
	A.print();
	C.print();
	MString D = A.subString(0, 5);
	D.print();
	MString E = C.subString(0, 3);
	E.print();
	system("pause");
}