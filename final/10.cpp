#include<iostream>
using namespace std;

class Rectangle{
	protected:
		int length,width;
		Rectangle(int _w,int _l):length(_l),width(_w){};
		int area(){return length*width;}
};

class Box:private Rectangle{
	int depth;
	public:
		Box(int _w,int _l,int _d):Rectangle(_w,_l),depth(_d){};
		int volume(){return Rectangle::area()*depth;}
		//override
		int area(){return 2*(length*width+width*depth+depth*length);}
};


int main(){
	int a,b,c;
	cin >> a >> b >> c;
	Box box(a,b,c);
	cout << box.volume()<<" "<<box.area();
	return 0;
}

