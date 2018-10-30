#include "Header.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//bigint operations 

void bigint::add(bigint num, bigint athernum)
{
	realnum = "";
	for (int i = num.number.size() - 1; i > -1; i--)
	{
		number.push_back(num.number[i] + athernum.number[i]);
	}
	if (num.sign == '-'&&athernum.sign == '-')
	{
		for (int i = number.size() - 1; i > -1; i--)
		{
			if (number[i] < -9 && 0 > number[i])
			{
				int a = number[i];
				number[i] = a % 10;
				a -= number[i];
				number[i - 1] += a / 10;
				
			}
		}realnum = '-';
		for (int i = 0; i < number.size(); i++)
		{
			realnum += to_string(-(number[i]));
		}
	}
	else
	{
		for (int i = number.size() - 1; i > -1; i--)
		{
			if (0 < number[i] && number[i] > 9)
			{
				int a = number[i];
				number[i] = a % 10;
				a -= number[i];
				number[i - 1] += a / 10;
				
			}
		}realnum = "";
		for (int i = 0; i < number.size(); i++)
		{
			realnum += to_string((number[i]));
		}
	}




	
	

}

void bigint ::subtract(bigint num, bigint athernum)
{

	bool a = num.graterthan(athernum) || num.equal(athernum);	
	if (a)
	{
		for (int i = 0; i < num.number.size(); i++)
		{

			if (num.number[i] <  athernum.number[i])
			{
				number.push_back(num.number[i] + 10 - athernum.number[i]);
				athernum.number[i + 1] += 1;
			}
			else
			{

				number.push_back(num.number[i] - athernum.number[i]);
			}
		}
		
		realnum = "";
		for (int i = number.size() - 1; i >-1; i--)
		{
			realnum += to_string(number[i]);
		}
	}
	else
	{
		
		for (int i = 0; i < athernum.number.size(); i++)
		{

			if (athernum.number[i] <  num.number[i])
			{
				number.push_back(-(athernum.number[i] + 10 - num.number[i]));
				num.number[i + 1] += 1;

			}
			else
			{

				number.push_back(-(athernum.number[i] - num.number[i]));
			}
		}

		realnum = "-";
		for (int i = number.size() - 1; i >-1; i--)
		{
			realnum += to_string(-number[i]);
		}
	
	}
}


	void bigint:: setnumber(string x,char s, int maxsize)
	{
		realnum = x;
		if (s == '-')
		{
			sign = '-';
			for (int i = x.size() - 1; i >-1; i--)
			{
				char s = x[i];
				number.push_back(-((int)s - '0'));
			}
			if (x.size() < maxsize)
			{
				for (int i = 0; i < maxsize - x.size(); i++)
				{
					number.push_back(0);
					realnum = '0' + realnum;
				}
			}
			realnum = '-'+realnum;
		}
		else
		{
			for (int i = x.size() - 1; i >-1; i--)
			{
				char s = x[i];
				number.push_back((int)s - '0');
			}
			if (x.size() < maxsize)
			{
				for (int i = 0; i < maxsize - x.size(); i++)
				{
					number.push_back(0);
					realnum = '0' + realnum;
				}
			}
		}
	}

	bool bigint::equal(bigint num)
	{
		if (realnum == num.realnum)
		{
			return true;
		}
		else
		{
			return false;
		}

	}


	bool bigint::notequal(bigint num)
	{
		if (realnum != num.realnum)
		{
			return true;
		}
		else
		{
			return false;
		}

	}


	bool bigint::graterthan(bigint num)
	{
		if (number.size() > num.number.size())
		{
			return true;
		}
		else if (number.size() < num.number.size())
		{
			return false;
		}
		else if (number.size() == num.number.size())
		{
			if (sign == '-'&&num.sign == '-')
			{
				for (int i = number.size() - 1; i > -1; i--)
				{

					if (number[i] > num.number[i])
					{

						return true;

					}
					else if (number[i] < num.number[i])
					{
						return false;

					}
				}
			}
			else if (sign != '-'&&num.sign == '-')
			{
				return true;
			}
			else if (sign == '-'&&num.sign != '-')
			{
				return false;
			}
			else if (sign != '-'&&num.sign != '-')
			{
				for (int i = number.size() - 1; i > -1; i--)
				{

					if (number[i] > num.number[i])
					{

						return true;

					}
					else if (number[i] < num.number[i])
					{
						return false;

					}
				}
			}

		}

	}


	bool bigint::smallerthan(bigint num)
	{
		if (number.size() < num.number.size())
		{
			return true;
		}
		else if (number.size() > num.number.size())
		{
			return false;
		}
		else if (number.size() == num.number.size())
		{
			if (sign == '-'&&num.sign == '-')
			{
				for (int i = number.size() - 1; i > -1; i--)
				{

					if (number[i] < num.number[i])
					{

						return true;

					}
					else if (number[i] > num.number[i])
					{
						return false;

					}
				}
			}
			else if (sign != '-'&&num.sign == '-')
			{
				return false;
			}
			else if (sign == '-'&&num.sign != '-')
			{
				return true;
			}
			else if (sign != '-'&&num.sign != '-')
			{
				for (int i = number.size() - 1; i > -1; i--)
				{

					if (number[i] < num.number[i])
					{

						return true;

					}
					else if (number[i] > num.number[i])
					{
						return false;

					}
				}
			}

		}

	}


	bigint bigint:: operator+(bigint athernum)
	{
		bigint num,sum;
		num.number = number;
		num.sign = sign;
		if (num.sign == '-'&&athernum.sign != '-')
		{
			for (int i = 0; i < num.number.size(); i++)
			{
				num.number[i] = (-num.number[i]);
			}
			num.sign = '+';
			sum.subtract(athernum, num);
		}
		else if (num.sign != '-'&&athernum.sign == '-')
		{

			for (int i = 0; i < athernum.number.size(); i++)
			{
				athernum.number[i] = (-athernum.number[i]);
			}
			athernum.sign = '+';
			sum.subtract(num, athernum);
		}
		else
		{
			sum.add( num,  athernum);
		}
		return sum;
	}

	bigint bigint::operator-(bigint athernum)
	{ 
		bigint num, mul;
		num.number = number;
		num.sign = sign;

		if (num.sign == '-'&&athernum.sign != '-')
		{
			for (int i = 0; i < athernum.number.size(); i++)
			{
				athernum.number[i] = (-athernum.number[i]);
			}
			athernum.sign = '-';
			mul.add(num, athernum);
		}
		else if (num.sign != '-'&&athernum.sign == '-')
		{

			for (int i = 0; i < athernum.number.size(); i++)
			{
				athernum.number[i] = (-athernum.number[i]);
			}
			athernum.sign = '+';
			mul.add(num, athernum);
		}
		else
		{
			mul.subtract(num, athernum);
		}

		return mul;
	}
	 
	//int operations

	void bigint::add_int(int num)
	{
		vector<int> tamp;
		int i = 0;
		while (true)
		{
			tamp.push_back(num % 10);
			//cout << tamp[i]<<endl;
			num = num / 10;
			if (num == 0)
			{
				break;
			}
			i++;
		}
		for (int i = 0; i < tamp.size(); i++)
		{
			number[i] += tamp[i];
		}

		for (int i = 0; i < tamp.size(); i++)
		{
			if (number[i] > 9)
			{
				number[i] -= 10;
				number[i + 1]++;
			}
		}

	}

	void bigint::subtract_int(int num)
	{
		vector<int> tamp;
		int i = 0;
		while (true)
		{
			tamp.push_back(num % 10);
			num = num / 10;
			if (num == 0)
			{
				break;
			}
			i++;
		}
		for (int i = 0; i < tamp.size() - 1; i++)
		{
			if (tamp[i] > number[i])
			{
				number[i] = number[i] + 10 - tamp[i];
				tamp[i + 1] += 1;
			}
			else
			{
				number[i] -= tamp[i];
			}
		}
		if (tamp[tamp.size() - 1] > number[tamp.size() - 1])
		{
			int i = tamp.size();
			while (true)
			{
				if (number[i] > 0)
				{
					break;
				}
				i++;
			}
			number[i] -= 1;
			number[tamp.size() - 1] = number[tamp.size() - 1] + 10 - tamp[tamp.size() - 1];

			for (int j = tamp.size(); j < i; j++)
			{
				number[j] += 9;
			}
		}
		else
		{
			number[tamp.size() - 1] -= tamp[tamp.size() - 1];

		}

	}

	void bigint::addintnum(int num)
	{
		if (sign == '-')
		{
			for (int i = 0; i < number.size(); i++)
			{
				number[i] = -number[i];
			}
			subtract_int(num);
			realnum = "-";
			for (int i = 0; i < number.size(); i++)
			{
				number[i] = -number[i];
			}
			for (int i = number.size() - 1; i > -1; i--)
			{
				realnum += to_string(-number[i]);
			}
		}
		else
		{
			add_int(num);
			realnum = "";
			for (int i = number.size() - 1; i > -1; i--)
			{
				realnum += to_string(number[i]);
			}
		}

	}

	void bigint::Subtractintnumbers(int num)
	{
		if (sign == '-')
		{
			for (int i = 0; i < number.size(); i++)
			{
				number[i] = -number[i];
			}
			add_int(num);
			realnum = "-";
			for (int i = 0; i < number.size(); i++)
			{
				number[i] = -number[i];
			}
			for (int i = number.size() - 1; i > -1; i--)
			{
				realnum += to_string(-number[i]);
			}
		}
		else
		{
			subtract_int(num);
			realnum = "";
			for (int i = number.size() - 1; i > -1; i--)
			{
				realnum += to_string(number[i]);
			}
		}
	}
	
	

