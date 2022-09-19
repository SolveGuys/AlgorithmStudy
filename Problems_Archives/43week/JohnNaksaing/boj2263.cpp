#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

/*
7
1 2 4 7 6 3 5
1 4 2 6 5 3 7

expected : 7 2 1 4 3 6 5
*/

std::vector<int> in_order;
std::vector<int> post_order;
std::vector<int> index;

void pre_order(int in_left, int in_right, int post_left, int post_right)
{
	if (in_left > in_right || post_left > post_right)
		return;


	int root = post_order[post_right];
	std::cout << root << ' ';

	int mid = std::find( in_order.begin() + in_left, in_order.begin() + in_right, root) - in_order.begin();

	int left = mid - in_left;
	int right = in_right - mid;

	pre_order( in_left, mid - 1, post_left, post_left + left - 1);
	pre_order( mid + 1, in_right, post_left + left, post_right - 1);
}

using iter = std::vector<int>::iterator;
std::vector<int> preOrder;
void pre_order_iter(const iter& in_left, const iter& in_right, const iter& post_left, const iter& post_right) 
{
	iter root = post_right - 1;
	//std::cout << *root << ' ';
	preOrder.push_back(*root);

	//iter mid = std::find(in_left, in_right, *root);

	iter mid = in_order.begin() + index[*root];

	int left = mid - in_left;
	int right = in_right - mid -1;
	
	/*
	std::cout << "root:" << root - post_order.begin() << " == mid:" << mid - in_order.begin() << ", value : "<< *root << "=" << *mid << '\n';
	std::cout 
		<< "left " << left
			<< ", 1st: "  << in_left				 - in_order.begin() 
			<< ", 2nd: " << mid					 - in_order.begin() 
			<< ", 3rd: " << post_left			 - post_order.begin()
			<< ", 4th: " << post_left + left	 - post_order.begin() << '\n';
	std::cout 
		<< "right " << right
		    << ", 1st: " << mid + 1				 - in_order.begin() 
			<< ", 2nd: " << in_right			 - in_order.begin()
			<< ", 3rd: " << post_left + left	 - post_order.begin() 
			<< ", 4th: " << post_right -1		 - post_order.begin() << '\n';
	std::cout << '\n';

	if (in_left > in_right || post_left > post_right)
		return;
	*/

	if(left != 0)
		pre_order_iter(in_left, mid, post_left, post_left + left);
	
	if(right != 0)
		pre_order_iter(mid + 1, in_right, post_left + left, post_right - 1);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n;
	std::cin >> n;

	
	in_order.resize(n);
	post_order.resize(n);
	index.resize(n+1);

	for (int i = 0; i < n; i++)
	{
		std::cin >> in_order[i];
		index[in_order[i]] = i;
	}
	for (int i = 0; i < n; i++)
	{
		std::cin >> post_order[i];
	}

	//pre_order(0, n-1, 0, n - 1);
	pre_order_iter(in_order.begin(),in_order.end(), post_order.begin(),post_order.end());

	for (int a : preOrder) 
	{
		std::cout << a << ' ';
	}

	return 0;
}