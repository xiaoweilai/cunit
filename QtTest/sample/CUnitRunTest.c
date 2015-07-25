#include <stdio.h>
#include <assert.h>
#include "console.h"

extern int AddTestMainModule();

int main()
{
    printf("start\n");
    fprintf(stdout,"comehere\n");
	//CU_initialize_registry ע�ắ��ע��һ����������CUE_ϵ���쳣ֵ
	if( CUE_SUCCESS != CU_initialize_registry())
	{
		return CU_get_error();
	}

	//CU_get_registry ����ע�ᵽ����ָ�� 
	assert(NULL != CU_get_registry());
	
	//����Ƿ���ִ�� 
	assert(!CU_is_test_running()); 

	//���ò���ģ����ɲ�������
	if (0 != AddTestMainModule())
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	//ʹ��console���ƽ�������ĺ������ 
	CU_console_run_tests();

	/***ʹ���Զ�����XML�ļ���ģʽ********
	CU_set_output_filename("TestMax");
    CU_list_tests_to_file();
	CU_automated_run_tests();
	***********************************/
	
	//����������ע����Ϣ 
	CU_cleanup_registry();
	
	return 0;
}
