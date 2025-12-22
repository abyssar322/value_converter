int search_first_non_zero(char arr[])
{
	int pos1 = 0;
	int i = 0;
	bool flag = false;
	while (flag == false)
	{

		if (arr[i] == '0' || arr[i] == '-')
		{
			i++;
			continue;
		}
		else {
			flag = true;
			pos1 = i;
			break;
		}
	}
	return pos1;
}