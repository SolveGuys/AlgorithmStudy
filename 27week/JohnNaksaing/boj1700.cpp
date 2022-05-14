#include <iostream>
#include <vector>
#include <algorithm>

class c_multitap 
{
private:
	using item_id = int;
	std::vector<item_id> m_plugs;

	int m_unplugged, n;
	bool bPlugged;
	//const int Empty = -1;

public:
	c_multitap(int n) : m_plugs(std::vector<item_id>(n)), m_unplugged(0), n(n), bPlugged(false) {}

	void plug(item_id num, const int idx, const std::vector<int>& orders) 
	{
		//1. 있으면 : 건너 뛴다
		if (std::find(m_plugs.begin(), m_plugs.end(), num) != m_plugs.end())
		{
			return;
		}
		
		//2. 없으면 : 빈자리 있으면 : 꼽는다
		/*
		std::vector<item_id>::iterator empty_plug = std::find(m_plugs.begin(), m_plugs.end(), Empty);
		if (empty_plug != m_plugs.end())
		{
			*empty_plug = num;
			return;
		}
		*/
		for (int i = 0; i < n; i++) 
		{
			if (!m_plugs[i])
			{
				m_plugs[i] = num;
				return;
			}
		}

		//3. 없으면 : 빈자리 없으면 : '꼽혀 있는 놈들 중에' 안 나타나는 놈 있으면 그놈을, 없으면 맨 마지막에 꼽"을"놈을 뽑는다
		item_id byebye;
		int byebye_order = -1;

		for (int i = 0; i < n; i++) 
		{
			item_id device = m_plugs[i];
			int device_order = 0;

			for (int j = idx + 1; j < orders.size(); j++) 
			{
				if (orders[j] == device)
					break;

				device_order++;
			}
			if (device_order > byebye_order) 
			{		
				byebye = device;
				byebye_order = device_order;
			}
		}
		
		for (int i = 0; i < n; i++) 
		{
			if (m_plugs[i] == byebye) 
			{
				m_plugs[i] = num;
				m_unplugged++;
				break;
			}
		}
	}

	const int get_answer() const { return m_unplugged; };
};


int main(void) 
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int n, k;
	std::cin >> n >> k;

	c_multitap multitap(n);
	std::vector<int> orders(k);

	for (int i = 0; i < k; i++) 
		std::cin >> orders[i];

	for (int i = 0; i < k; i++) 
		multitap.plug(orders[i], i, orders);

	std::cout << multitap.get_answer();

	return 0;
}
