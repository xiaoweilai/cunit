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

/*0 表示成功，1表示失败*/
int AddTestMainModule()
{
    printf("start\n");
	CU_pSuite pSuite = NULL;

	/***************
	* 1. CU_add_suite 增加一个Suite 
	* 2. Suite名字 : testSuite
	* 3. InitSuite EndSuite：分别是测试单元初始和释放函数，如不需要则NULL传递
	****************/
	pSuite = CU_add_suite("testSuite", InitSuite, EndSuite);  

	//检测注册Suite情况
	if(NULL == pSuite)
	{
		//return 1;
	}
	
	/***************
	* 1. 注册当前Suite下的测试用例　
	* 2. pSuite：用例指针
	* 3. "Test1"： 测试单元名称 
	* 4. Test1：测试函数
	***************/
	if( NULL == CU_add_test(pSuite, "Test1", Test1) ||
		NULL == CU_add_test(pSuite, "Test2", Test2))
	{
		return 1;
	}
	
	/***另外一种测试方式***************/
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
