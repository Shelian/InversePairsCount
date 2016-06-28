#ifndef __INVERSEPAIRSCOUNT_H__
#define __INVERSEPAIRSCOUNT_H__

//��һ��д  -->
int InversePairs(int* data,int* copy,int begin,int end)
{
	//�鲢������ڣ�����ʼ���ڽ���ʱ�ͷ���
	if (begin == end)
		return 0;

	int mid = (end - begin) / 2;
	int left = InversePairs(data, copy, begin, begin+mid);		//�ݹ���ݹ��ң�һֱ��ֻ��һ��Ϊֹ
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

	int endindex = end;//������õ�ֵ������ԭ����
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


//�ڶ���д  -->
int InverseCount(int* data,int* copy,int begin,int end)
{
	if (begin == end)//�ݹ����
		return 0;

	int mid = (end - begin) / 2;
	int left = InverseCount(data, copy, begin, begin + mid);	//�ȵݹ���һֱ��ֻ��һ��
	int right = InverseCount(data, copy, begin + mid + 1, end);//�ٵݹ��ң�һֱ��ֻ��һ��

	//��ô�鲢�����ҽ�count����
	int count = 0;
	int end1 = begin + mid;
	int end2 = end;
	int index = end;

	while (end1 >= begin && end2 >= begin + mid + 1)
	{
		if (data[end1] > data[end2])
		{
			copy[index--] = data[end1--];//�Ѵ��ֵ��������Ŀռ���
			count += end2 - begin - mid;//�����������ʱ�������
		}
		else
		{
			copy[index--] = data[end2--];
		}
	}
	//��û�п�����ֵ��ȫ�����������copy����
	for (; end1 >= begin; --end1)
	{
		copy[index--] = data[end1];
	}
	for (; end2 >= begin+mid+1; --end2)
	{
		copy[index--] = data[end2];
	}

	int endindex = end;//������õ�ֵ������ԭ����
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