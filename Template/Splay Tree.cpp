#include <iostream>
#include <cstdlib>
using namespace std;
template <class type, class comp = less<type> >
struct splay_tree
{
	struct node
	{
		node* left;
		node* right;
		node* par;
		type val;
		node()
		{
			left = NULL;
			right = NULL;
			par = NULL;
		}
	};
	node* root;
	unsigned int _size;
	unsigned int size()
	{
		return _size;
	}
	bool empty()
	{
		return (size() > 0);
	}
	splay_tree()
	{
		root = NULL;
		_size = 0;
	}
	void rotate_left(node* x)
	{
		node* y = x->right;
		if (y == NULL)
			return;
		x->right = y->left;
		if (y->left != NULL)
			y->left->par = x;
		y->par = x->par;
		if (x->par != NULL && x == x->par->left)
			x->par->left = y;
		if (x->par != NULL && x == x->par->right)
			x->par->right = y;
		y->left = x;
		x->par = y;
	}
	void rotate_right(node* y)
	{
		node* x = y->left;
		if (y == NULL)
			return;
		y->left = x->right;
		if (x->right != NULL)
			x->right->par = y;
		x->par = y->par;
		if (y->par != NULL && y == y->par->left)
			y->par->left = x;
		if (y->par != NULL && y == y->par->right)
			y->par->right = x;
		x->right = y;
		y->par = x;
	}
	void zig(node* p)
	{
		if (p == p->par->right)
			rotate_left(p->par);
		else
			rotate_right(p->par);
	}
	void zig_zig(node* p)
	{
		if (p == p->par->right)
		{
			rotate_left(p->par->par);
			rotate_left(p->par);
		}
		else
		{
			rotate_right(p->par->par);
			rotate_right(p->par);
		}
	}
	void zig_zag(node* p)
	{
		if (p == p->par->right)
		{
			rotate_left(p->par);
			rotate_right(p->par);
		}
		else
		{
			rotate_right(p->par);
			rotate_left(p->par);
		}
	}
	void splay(node* it)
	{
		while (true)
		{
			if (it->par == NULL)
			{
				root = it;
				break;
			}
			if (it->par->par == NULL)
			{
				zig(it);
				continue;
			}
			if (it->par->left == it)
			{
				if (it->par->par->left == it->par)
					zig_zig(it);
				else
					zig_zag(it);
			}
			else
			{
				if (it->par->par->right == it->par)
					zig_zig(it);
				else
					zig_zag(it);
			}
		}
	}
	node* get_min()
	{
		node* it = root;
		while (it->left != NULL)
			it = it->left;
		return it;
	}
	node* find(type val)
	{
		node* it = root;
		while (true)
		{
			if (comp()(val, it->val) == comp()(it->val, val))
				return it;
			if (comp()(val, it->val))
			{
				if (it->left == NULL)
					return it;
				else
					it = it->left;
			}
			else
			{
				if (it->right == NULL)
					return it;
				else
					it = it->right;
			}
		}
	}
	node* insert(type val)
	{
		if (root == NULL)
		{
			node* p = new node;
			p->val = val;
			root = p;
			_size++;
			return p;
		}
		node* it = find(val);
		splay(it); 
		if (comp()(it->val, val) == comp()(val, it->val))
			return it;
		node* p = new node;
		p->val = val;
		if (comp()(it->val, p->val))
		{
			p->left = it;
			it->par = p;
			p->right = it->right;
			if (it->right != NULL)
				it->right->par = p;
			it->right = NULL;
		}
		else
		{
			p->right = it;
			it->par = p;
			p->left = it->left;
			if (it->left != NULL)
				it->left->par = p;
			it->left = NULL;
		}
		_size++;
		root = p;
		return p;
	}
	void erase(type val)
	{
		if (root == NULL)
			return;
		node* it = find(val);
		splay(it);
		if (comp()(it->val, val) != comp()(val, it->val))
			return;
		if (_size == 1)
		{
			node* it = root;
			root = NULL;
			free(it);
			_size--;
			return;
		}
		node* tmp = root;
		if (it->right == NULL)
		{
			it->left->par = NULL;
			root = it->left;
			free(tmp);
			_size--;
			return;
		}
		root = it->right;
		it->right->par = NULL;
		node* left = it->left;
		if (left == NULL)
		{
			free(tmp);
			_size--;
			return;
		}
		it->left->par = NULL;
		free(tmp);
		_size--;
		it = get_min();
		splay(it);
		it->left = left;
		left->par = it;
	}
};
int main()
{
	ios::sync_with_stdio(false);
	return 0;
}
