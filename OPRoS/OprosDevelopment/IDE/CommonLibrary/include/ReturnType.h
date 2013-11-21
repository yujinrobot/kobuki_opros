/*
 *  OPRoS Component Engine (OCE)
 *  Copyright (c) 2008 ETRI. http://www.etri.re.kr.
 *  Distributed under the OPRoS License, Version 1.0.
 *
 *  @Created : 2009. 2. 19
 *  @Author  : sby (sby@etri.re.kr)
 *
 *  @File    : ReturnType.h
 *
 *
 */

#ifndef RETURNTYPE_H_
#define RETURNTYPE_H_

enum ReturnType {
	OPROS_ERROR = 302,
	OPROS_VALID_DATA = 300,
	OPROS_INVALID_DATA = 301,
	// Common
	OPROS_SUCCESS=200,
	UNKNOWN_ERROR = 210,
	// OPRoS Engine
	OPROS_SUCCESS_SYNC=202,
	OPROS_CALLER_ERROR=400,
	OPROS_BAD_INPUT_PARAMETER=401,
	OPROS_INPUT_OUT_OF_RANGE=402,
	OPROS_INPUT_NULL=403,
	OPROS_UNAUTHORIZED=404,
	OPROS_PRECONDITION_NOT_MET=405,
	OPROS_CALLEE_ERROR=500,
	OPROS_UNSUPPORTED_METHOD=501,
	OPROS_INTERNAL_FAULT=502,
	OPROS_OUT_OF_RESOURCES=408,
	OPROS_VERSION_MISMATCH=505,
	// Device API
	OPROS_DESTORY_ERROR				= 0x10000000,	//	������ �� ���� ����
	OPROS_FIND_DLL_ERROR			= 0x10000001,	//	DLL ������ ã�� �� ���� ���
	OPROS_LOAD_DLL_ERROR			= 0x10000002,	//	DLL���� �����ϴ� �������̽��� �ε��� �� ���� ���
	OPROS_FIND_PROPERTY_ERROR		= 0x10000003,	//	������Ʈ���� �ʿ�� �ϴ� �Ķ���͸� ã�� �� ���� ���
	
	OPROS_INITIALIZE_API_ERROR		= 0x10000100,	//	API�� �ʱ�ȭ ��Ű�� ���� ������ �߻��� ���
	OPROS_FINALIZE_API_ERROR		= 0x10000101,	//	API�� ���� ��Ű�� ���� ������ �߻��� ���
	OPROS_RESET_API_ERROR			= 0x10000102,	//	API�� ��⵿ ��Ű�� ���� ������ �߻��� ���
	OPROS_RECOVER_API_ERROR			= 0x10000103,	//	API�� ������Ű�� ���� ������ �߻��� ���
	
	OPROS_RECOVER_ERROR				= 0x20000000,	//	������ �� �ִ� ����
	OPROS_ENABLE_API_ERROR			= 0x20000100,	//	API�� Ȱ��ȭ ��Ű�� ���� ������ �߻��� ���
	OPROS_DISABLE_API_ERROR			= 0x20000101,	//	API�� ��Ȱ��ȭ ��Ű�� ���� ������ �߻��� ���
	OPROS_CALL_API_ERROR			= 0x20000102,	//	API�� �������̽��� ȣ���ϴ� ���� ������ �߻��� ���
	OPROS_API_NOT_SUPPORTED_ERROR	= 0x20000103,	//	API���� �������̽��� �������� �ʴ� ���
	OPROS_API_EXECUTING				= 0x20000104,	//	���� API�� �������� ���, ������� �Ӵ�ǽ�����Ͱ� �ʱ� ��ġ�� �̵� ���� ���
};

#endif /* RETURNTYPE_H_ */
