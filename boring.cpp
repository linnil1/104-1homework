
// why can't use std::swap(a,b) QQ
template <class c>
void swap(c &a,c &b){
	c tmp=a;a=b;b=tmp;
}
// why can't use std::sort() ?? QQ
#define left(x) (2*x+1)
#define right(x) (2*x+2)
template <class c>
void heapsort(c *st,c *en,bool comp(c,c)){
	int n = en -st ;
	c *arr = st;
	//build heap
	for(int i=1;i<n;++i){
		int now=i;
		while(now && comp(arr[now>>1],arr[now])){
			swap(arr[now>>1],arr[now]);	
			now>>=1;
		}
	}
	// find max and put it to back
	for(int i=n-1;i>=0;--i){
		swap(arr[0],arr[i]);
		int now=0;
		while(left(now)<i){
			c *child;
			if( right(now)<i && comp(arr[left(now)],arr[right(now)]) )//find the max
				child = arr + right(now);
			else
				child = arr + left(now);
			if( comp(arr[now],*child) ){// change to child
				swap(arr[now],*child);
				now = child - st ;
			}
			else
				break;
		}
					
	}
}
