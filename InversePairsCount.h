#ifndef __INVERSEPAIRSCOUNT_H__
#define __INVERSEPAIRSCOUNT_H__

//第一次写  -->
int InversePairs(int* data,int* copy,int begin,int end)
{
	//归并排序出口，当开始等于结束时就返回
	if (begin == end)
		return 0;

	int mid = (end - begin) / 2;
	int left = InversePairs(data, copy, begin, begin+mid);		//递归左递归右，一直到只有一个为止
	int right = InversePairs(data, copy, begin+mid + 1, end);//2 3

	int end1 = begin+mid;
	int end2 = end;

	int index = end;
	int count = 0;
	while (end1 >= begin && end2 >= mid + 1)
	{
		if (data[end1] > data[end2])
		{
			copy[index--] = data[end1--];
			count += end2 -begin-mid;
		}
		else
		{
			copy[index--] = data[end2--];
		}
	}

	for (; end1 >= begin; --end1)
	{
		copy[index--] = data[end1];
	}

	for (; end2 >= mid + 1; --end2)
	{
		copy[index--] = data[end2];
	}

	int endindex = end;//把排序好的值拷贝回原数组
	for (; endindex >= begin; --endindex)
	{
		data[endindex] = copy[endindex];
	}

	return left + right + count;
}


int InversePairsCount(int* data,int size)
{
	if (data == NULL || size < 0)
		return 0;

	int* copy = new int[size];
	for (int i = 0; i < size; i++)
	{
		copy[i] = 0;
	}

	int count = InversePairs(data, copy, 0, size - 1);
	delete[] copy;
	return count;
}


//第二次写  -->
int InverseCount(int* data,int* copy,int begin,int end)
{
	if (begin == end)//递归出口
		return 0;

	int mid = (end - begin) / 2;
	int left = InverseCount(data, copy, begin, begin + mid);	//先递归左，一直到只有一个
	int right = InverseCount(data, copy, begin + mid + 1, end);//再递归右，一直到只有一个

	//怎么归并，并且将count计数
	int count = 0;
	int end1 = begin + mid;
	int end2 = end;
	int index = end;

	while (end1 >= begin && end2 >= begin + mid + 1)
	{
		if (data[end1] > data[end2])
		{
			copy[index--] = data[end1--];//把大的值拷贝到大的空间里
			count += end2 - begin - mid;//存在这种情况时的逆序对
		}
		else
		{
			copy[index--] = data[end2--];
		}
	}
	//将没有拷贝的值，全部拷贝到大的copy数组
	for (; end1 >= begin; --end1)
	{
		copy[index--] = data[end1];
	}
	for (; end2 >= begin+mid+1; --end2)
	{
		copy[index--] = data[end2];
	}

	int endindex = end;//把排序好的值拷贝回原数组
	for (; endindex >= begin; --endindex)
	{
		data[endindex] = copy[endindex];
	}

	return left + right + count;
}

int Inverse(int* a,int size)
{
	if (a == NULL || size < 0)
		return 0;

	int* copy = new int[size];
	for (int i = 0; i < size; i++)
	{
		copy[i] = 0;
	}

	int count = InverseCount(a, copy, 0, size - 1);
	delete[] copy;
	return count;
}

void TestInverse()
{
	int a[4] = { 7, 5, 6, 4 };
	/*cout << InversePairsCount(a, 4) << endl;*/
	cout << Inverse(a, 4) << endl;

}


#endif //__INVERSEPAIRSCOUNT_H__