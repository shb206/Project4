#include <iostream>

using namespace std;

int main()
{	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int count, max, num;

	cin >> count >> max;

	while (count != 0)
	{
		cin >> num;
		if (num < max)
			cout << num << " ";
		count--;
	}

	return 0;
}