#include <iostream>
using namespace std;

#if 0
class Link
{
public:
	friend void reverse(Link& link);
	friend int countdownKeyVal(Link& link, int key);
	friend void MergeLink(Link& link1, Link& link2);
public:
	Link(int size = 0) : size_(size)
	{
		head_ = new Node();
	}
	~Link()
	{
		Node* p = head_;
		while (p != nullptr)
		{
			Node* node = p->next_;
			delete p;
			p = node; 
		}
	}

public:
	void insertTail(int val)
	{
		Node* p = head_;
		while (p->next_ != nullptr)
		{
			p=p->next_;
		}
		Node* node = new Node(val);
		p->next_ = node;
		size_++;
	}

	void insertHead(int val)
	{
		Node* node = new Node(val);
		node->next_ = head_->next_;
		head_->next_ = node;
		size_++;
	}
		
	void insertPos(int pos, int val)
	{
		if (pos < 0 || pos > size_)
		{
			throw "invalid pos";
		}
		Node* p = head_;
		for (int i = 0; i < pos; i++)
		{
			p = p->next_;
		}
		Node* node = new Node(val);
		node->next_ = p->next_;
		p->next_ = node;
		size_++;
	}

	void removeAll(int val)
	{
		Node* p = head_->next_;
		Node* q = head_;
		while (p != nullptr)
		{
			if (p->data_ == val)
			{
				q->next_ = p->next_;
				delete p;
				size_--;
				p = q->next_;
			}
			else
			{
				p = p->next_;
				q = q->next_;
			}
		}
	}

	bool find(int val)
	{
		Node* p = head_->next_;
		while (p != nullptr)
		{
			if (p->data_ == val)
			{
				return true;
			}
			p = p->next_;
		}
		return false;
	}

	void show()
	{
		Node* p = head_->next_;
		while (p != nullptr)
		{
			cout << p->data_ << " ";
			p = p->next_;
		}
		cout << endl;
	}
private:
	struct Node
	{
		Node(int data = 0)
			:data_(data)
			,next_(nullptr){ }
		int data_;
		Node* next_;
	};
	Node* head_;
	int size_;
	
};

//单链表逆序

void reverse(Link& link)
{
	Link::Node* head = link.head_;
	Link::Node* p = head->next_;
	head->next_ = nullptr;
	while (p != nullptr)
	{
		Link::Node* q = p->next_;
		p->next_ = head->next_;
		head->next_ = p;
		p = q;
	}
	link.show();
}


//求倒数第k个节点的值
int countdownKeyVal(Link& link, int key)
{
	if (key <= 0 || key > link.size_)
	{
		return -1;
	}
	Link::Node* head = link.head_;
	Link::Node* p = head;
	Link::Node* q = head;
	for (int i = 0; i < key; i++)
	{
		p = p->next_;
	}
	while (p != nullptr)
	{
		p = p->next_;
		q = q->next_;
	}
	return q->data_;
}

//合并2个有序单链表
void MergeLink(Link& link1, Link& link2)
{
	Link::Node* p = link1.head_->next_;
	Link::Node* q = link2.head_->next_;
	Link::Node* last = link1.head_;
	link2.head_->next_ = nullptr;

	while (p != nullptr && q != nullptr)
	{
		if (p->data_ < q->data_)
		{
			last->next_ = p;
			p = p->next_;
			last = last->next_;
		}
		else
		{
			last->next_ = q;
			q = q->next_;
			last = last->next_;
		}
	}
	if (p != nullptr)
	{
		last->next_ = p;
	}
	else
	{
		last->next_ = q;
	}
}

#endif


#if 0
int main()
{
	Link link;
	for (int i = 0; i < 10; i++)
	{
		link.insertTail(i);
	}
	reverse(link);
}
#endif


#if 0
int main()
{
	Link link;
	for (int i = 0; i < 10; i++)
	{
		link.insertTail(i);
	}
	cout << countdownKeyVal(link,1);
}
#endif



//判断单链表是否存在环，若存在返回环的入口节点
struct Node
{
	int data_;
	Node* next_;
};

bool isLinkHasCircle(Node* head, int &val)
{
	Node* fast = head;
	Node* slow = head;
	while (fast != nullptr && fast->next_ != nullptr)
	{
		fast = fast->next_->next_;
		slow = slow->next_;

		if (fast == slow)
		{
			fast = head;
			while (fast != slow)
			{
				fast = fast->next_;
				slow = slow->next_;
			}
			val = slow->data_;
			return true;
		}
	}
	return false;
}

//判断2个单链表是否相交
bool isLinkHasMerge(Node* head1, Node* head2, int& val)
{
	int cnt1 = 0, cnt2 = 0;
	Node* p = head1->next_;
	Node* q = head2->next_;

	while (p != nullptr)
	{
		cnt1++;
		p = p->next_;
	}

	while (q != nullptr)
	{
		cnt2++;
		q = q->next_;
	}

	p = head1;
	q = head2;
	if (cnt1 > cnt2)
	{
		int offset = cnt1 - cnt2;
		while (offset-- > 0)
		{
			p = p->next_;
		}
	}
	else
	{
		int offset = cnt2 - cnt1;
		while (offset-- > 0)
		{
			q = q->next_;
		}
	}
	while (p != nullptr && q != nullptr)
	{
		if (p == q)
		{
			val = p->data_;
			return true;
		}
		p = p->next_;
		q = q->next_;
	}
	return false;
}

