#include <stdio.h>
#include <assert.h>
#include "console.h"
#include "MainModule.h"

int InitSuite()
{
	return 0;
} 

int EndSuite()
{
	return 0;
}

int Test_Is_Equal(int a, int b, int real)
{
	int result;

	result = cal_num(a, b);
	if(result == real)
	{
		return 1;
	}
	return 0;
}

int Test_Is_Not_Equal(int a, int b, int real)
{
	int result;

	result = cal_num(a, b);
	if(result != real)
	{
		return 1;
	}
	return 0;
}

void Test1()
{
	CU_ASSERT(Test_Is_Equal(3, 4, 7));
}

void Test2()
{
	CU_ASSERT(Test_Is_Not_Equal(4, 5, 10));
}

/*0 ��ʾ�ɹ���1��ʾʧ��*/
int AddTestMainModule()
{
    printf("start\n");
	CU_pSuite pSuite = NULL;

	/***************
	* 1. CU_add_suite ����һ��Suite 
	* 2. Suite���� : testSuite
	* 3. InitSuite EndSuite���ֱ��ǲ��Ե�Ԫ��ʼ���ͷź������粻��Ҫ��NULL����
	****************/
	pSuite = CU_add_suite("testSuite", InitSuite, EndSuite);  

	//���ע��Suite���
	if(NULL == pSuite)
	{
		//return 1;
	}
	
	/***************
	* 1. ע�ᵱǰSuite�µĲ���������
	* 2. pSuite������ָ��
	* 3. "Test1"�� ���Ե�Ԫ���� 
	* 4. Test1�����Ժ���
	***************/
	if( NULL == CU_add_test(pSuite, "Test1", Test1) ||
		NULL == CU_add_test(pSuite, "Test2", Test2))
	{
		return 1;
	}
	
	/***����һ�ֲ��Է�ʽ***************/
	/*
	CU_TestInfo testcases[] = {
        {"Test1:", Test1},
        {"Test2:", Test2},
        CU_TEST_INFO_NULL
	};

	CU_SuiteInfo suites[] = {
		{"Testing the function cal_num:", InitSuite, EndSuite, testcases},
        CU_SUITE_INFO_NULL
	};

	if(CUE_SUCCESS != CU_register_suites(suites))
	{
		return 1;
	}
	*/
	/************************************/

	return 0;
}
