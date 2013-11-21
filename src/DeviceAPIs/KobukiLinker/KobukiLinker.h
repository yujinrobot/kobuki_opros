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


// 다음 ifdef 블록은 DLL에서 내보내기하는 작업을 쉽게 해 주는 매크로를 만드는 
// 표준 방식입니다. 이 DLL에 들어 있는 파일은 모두 명령줄에 정의된 _EXPORTS 기호로
// 컴파일되며, 다른 프로젝트에서는 이 기호를 정의할 수 없습니다.
// 이렇게 하면 소스 파일에 이 파일이 들어 있는 다른 모든 프로젝트에서는 
// KOBUKILINKER_API 함수를 DLL에서 가져오는 것으로 보고, 이 DLL은
// 이 DLL은 해당 매크로로 정의된 기호가 내보내지는 것으로 봅니다.
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
/*// 이 클래스는 KobukiLinker.dll에서 내보낸 것입니다.
class KOBUKILINKER_API CKobukiLinker {
public:
	CKobukiLinker(void);
	// TODO: 여기에 메서드를 추가합니다.
};

extern KOBUKILINKER_API int nKobukiLinker;

KOBUKILINKER_API int fnKobukiLinker(void);
*/
