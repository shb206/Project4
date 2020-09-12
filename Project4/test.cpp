#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string solution(string new_id)
{
	string answer = "";
	string buffer;
	char ch[] = { '~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '=', '+', '[', '{', ']', '}', ':', '?', '<', '>' };
	// 1�ܰ� �ҹ��� ��ȯ
	transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);
	
	// 2�ܰ� Ư������ ����
	for(int i = 0; i < sizeof(ch); i++)
		new_id.erase(remove(new_id.begin(), new_id.end(), ch[i]), new_id.end());

	for (int i = 0; i < new_id.length(); i++)
	{
		if ((new_id[i] >= '0' && new_id[i] <= '9')
			|| (new_id[i] >= 'A' && new_id[i] <= 'z')
				|| (new_id[i] == '.') || (new_id[i] == '_') || (new_id[i] == '-'))
		{
			buffer = buffer + new_id[i];
		}
	}
	new_id = buffer;
	buffer = "";

	// 3�ܰ� ��ħǥ�� ���ӵǸ� �ϳ��� ġȯ
	for (int i = 0; i < new_id.length(); i++)
	{
		if (new_id[i] != new_id[i + 1])
		{
			buffer = buffer + new_id[i];
		}
	}
	new_id = buffer;
	buffer = "";

	if ((new_id.length() != 0) && (new_id[0] == '.'))
		new_id = new_id.substr(1);
	if ((new_id.length() != 0) && (new_id[new_id.length()] == '.'))
		new_id = new_id.substr(0, new_id.length() - 1);

	if (new_id.length() == 0)
	{
		new_id = "a";
	}

	if (new_id.length() > 15)
		new_id = new_id.substr(0, 15);
	
	if (new_id[new_id.length()-1] == '.')
		new_id = new_id.substr(0, new_id.length() - 1);

	if (new_id.length() < 3)
	{
		char a = (new_id.length()) == 1 ? new_id[0] : new_id[1];
		buffer = new_id;
		
		for (int i = new_id.length(); i < 3; i++)
			buffer = buffer + a;

		new_id = buffer;
	}

	
	
	answer = new_id;
	return answer;
}

int main()
{
	string test = "z-+.^.";

	test = solution(test);

	cout << test;

	return 0;
}

