#include <iostream>
#include <cstdio>

#define rt2 rt * 2

using namespace std;

const int N = 1e5;

struct node{
	int note, val;
}tree[4 * N + 5];

int n, m;

int b[N + 5];

void build(int rt, int l, int r){
	if(l == r){
		tree[rt].val = b[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(rt2 + 0,		 l, mid);
	build(rt2 + 1, mid + 1,   r);
	tree[rt].val = tree[rt2 + 0].val
				 + tree[rt2 + 1].val;
	return;
}

void sink(int rt, int l, int r){
	if(tree[rt].note == 0) return;
	int mid = (l + r) >> 1;
	tree[rt2 + 0].note += tree[rt].note;
	tree[rt2 + 1].note += tree[rt].note; 
	tree[rt2 + 0].val  += (mid - l + 1) * tree[rt].note;
	tree[rt2 + 1].val  += (r - mid + 0) * tree[rt].note;
	tree[rt].note = 0;
	return;
}

void change(int rt, int l, int r, int p, int q, int d){
	if(l == p && r == q){
		tree[rt].note += d;
		tree[rt].val  += (r - l + 1) * d;
		return;
	}
	sink(rt, l, r);
	int mid = (l + r) >> 1;
	if(q <= mid) 	 change(rt2 + 0,       l, mid,       p,   q, d);
	else if(p > mid) change(rt2 + 1, mid + 1,   r,       p,   q, d);
	else 			 change(rt2 + 0,       l, mid,       p, mid, d),
					 change(rt2 + 1, mid + 1,   r, mid + 1,   q, d); 
	tree[rt].val = tree[rt2 + 0].val
				 + tree[rt2 + 1].val;
	return;
}

int search(int rt, int l, int r, int p, int q){
	if(l >= p && r <= q) return tree[rt].val;
	sink(rt, l, r);
	int mid = (l + r) >> 1;
	if(q <= mid) 	 return search(rt2 + 0,       l, mid, 		p,   q);
	else if(p > mid) return search(rt2 + 1, mid + 1,   r, 		p,   q);
	else 			 return search(rt2 + 0,       l, mid, 		p, mid)
					 	  + search(rt2 + 1, mid + 1,   r, mid + 1,   q); 
}

int main(){
	scanf("%d %d", &n, &m);
	int u, v = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d", &u);
		b[i] = u - v;
		v = u;
	}
	build(1, 1, n);
	int type;
	int l, r, k, d;
	for(int i = 1; i <= m; i++){
		scanf("%d", &type);
		if(type == 1){
			scanf("%d %d %d %d", &l, &r, &k, &d);
						   change(1, 1, n,     l,     l, k);
			if(l + 1 <= r) change(1, 1, n, l + 1,     r, d);
			if(r < n)      change(1, 1, n, r + 1, r + 1, -(k + (r - l) * d)); 
		}
		if(type == 2){
			scanf("%d", &l);
			printf("%d\n", search(1, 1, n, 1, l));
		}
	}
	return 0;
}
