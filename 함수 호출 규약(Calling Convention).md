# 함수 호출 규약(Calling Convention)

함수 호출 규약이란?

함수 호출 후에 ESP(스택 포인터)를 어떻게 정리하는지 약속

​

cdecl

C언어에서 사용하는 방식이며, Caller에서 스택을 정리하는 특성을 가지고있다.

​

stdcall

Win32 API에서 사용되며, Callee에서 스택을 정리하는 것이 특징

stdcall방식으로 컴파일하고 싶을 때는 _stdcall 키워드를 붙이면 된다.

예)

int _stdcall add(int a, int b){}

​

fastcall

fastcall방식은 기본적으로 stdcall방식과 같지만, 함수에 전달하는 파라미터일부(2개까지)를 스택 메모리가 아닌 레지스터를 이용하여 전달한다는 것이 특징.

좀 더 빠른 함수 호출 가능
