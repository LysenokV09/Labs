class Vector
{
public:
	Vector(int s);
	int give(int index);
	int givesize();
	void cross();
	void end();
	void del(int i);
	void print();
private:
	int size;
	int* data;
	int* data1;
};
