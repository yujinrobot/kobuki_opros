/*
 *
 * Copyright (c) 2013, Yujin Robot Co., Ltd.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the Yujin Robot Co., Ltd.  The name of the
 * Yujin Robot Co., Ltd. may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ''AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 */


// ���� ifdef ����� DLL���� ���������ϴ� �۾��� ���� �� �ִ� ��ũ�θ� ����� 
// ǥ�� ����Դϴ�. �� DLL�� ��� �ִ� ������ ��� ����ٿ� ���ǵ� _EXPORTS ��ȣ��
// �����ϵǸ�, �ٸ� ������Ʈ������ �� ��ȣ�� ������ �� �����ϴ�.
// �̷��� �ϸ� �ҽ� ���Ͽ� �� ������ ��� �ִ� �ٸ� ��� ������Ʈ������ 
// KOBUKILINKER_API �Լ��� DLL���� �������� ������ ����, �� DLL��
// �� DLL�� �ش� ��ũ�η� ���ǵ� ��ȣ�� ���������� ������ ���ϴ�.
#ifdef KOBUKILINKER_EXPORTS
#define KOBUKILINKER_API __declspec(dllexport)
#else
#define KOBUKILINKER_API __declspec(dllimport)
#endif
extern "C"
{
KOBUKILINKER_API void* GetKobukiInstance();
KOBUKILINKER_API void ReleaseKobukiInstance(kobuki::Kobuki* pkobuki);
KOBUKILINKER_API void GetOdometry(double &x, double &y, double &theta);
KOBUKILINKER_API void GetGyroData(double &yaw);
KOBUKILINKER_API void GetCoresensorData(kobuki::CoreSensors::Data &coresenData);
}
/*// �� Ŭ������ KobukiLinker.dll���� ������ ���Դϴ�.
class KOBUKILINKER_API CKobukiLinker {
public:
	CKobukiLinker(void);
	// TODO: ���⿡ �޼��带 �߰��մϴ�.
};

extern KOBUKILINKER_API int nKobukiLinker;

KOBUKILINKER_API int fnKobukiLinker(void);
*/
