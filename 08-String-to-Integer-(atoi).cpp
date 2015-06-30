int myAtoi(string str) {
        
    	if (str.length() == 0)
	{
		return 0;
	}
	size_t start = str.find_first_not_of(' ');
	str = (str.find_first_not_of(' ') < str.length()) ? str.substr(str.find_first_not_of(' ')) : "";
	if (str.length() == 0 || !(str[0] == '-' || str[0] == '+' || (str[0] >= '0' && str[0] <= '9')))
	{
		return 0;
	}

	bool minorFlag = (str[0] == '-');
	bool symbolFlag = (str[0] == '+');
	bool startFlag = false;
	long long absValue = 0;
	for (size_t i = minorFlag || symbolFlag ? 1 : 0; i < str.length(); i++)
	{
		if (str[i] > '9' || str[i] < '0')
		{
			return minorFlag ? -absValue : absValue;
		}
		
		absValue *= 10;
		absValue += str[i] - '0';
		
		if ((absValue > 2147483647 && !minorFlag) || (absValue > 2147483648 && minorFlag))
		{
			return minorFlag ? -2147483648 : 2147483647;
		}
	}
	return minorFlag ? -absValue : absValue;
        
    }