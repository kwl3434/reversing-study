# reversing-study

리버싱 핵심원리 책 & visual studio 2017 & ollydbg를 이용한 리버싱 공부
1. ollydbg설치하기
2. IA-32 레지스터 분석
3. ESP EBP 개념 정리
4. 스택프레임 따라가기
5. 함수 호출 규약
6. PE 분석
.
.
.
추가예정

# window7환경에서 OllyDbg 설치하기 32bit

윈도우 10에서 ollydbg를 쓰는건 너무 빡세요..

만약 자기가 주로쓰는 컴퓨터 즉 vmware환경이 아닌 환경에서

깔았다가는 띵.띵.띵.띠.ㅇ.... 소리를 들으실 수 있습니다.

http://www.ollydbg.de/

위 사이트에 들어가면
<div>
<img src="https://postfiles.pstatic.net/MjAxOTAxMTNfMjE4/MDAxNTQ3MzA2MDgyMTA1.b38mMVPvKv68zVipVqx_fIZH3bCsS5LW30H0xQWAQQkg.sodyDSb5BDbMMTi5pduWywS1CA-Gez6C82Ooha96Xj8g.PNG.kwleepuppy/image.png?type=w773" width="90%"></img>
</div>

이런 화면을 나옵니다!.

쭈욱 밑으로 내리면
<div>
<img src="https://postfiles.pstatic.net/MjAxOTAxMTNfMjk4/MDAxNTQ3MzA2MTI5OTU4.M2QGnwgEkzd_RoJXBvPXDmAQKh_ozvZsIBGhU4uCXAcg._c4nNysuTqLe5rtsRXLrcBYiDpkz-hRQlbxwBaAbfdgg.PNG.kwleepuppy/image.png?type=w773" width="90%"></img>
</div>

굵은 글짜의 Download 바로 밑

Download OllyDbg 1.10(final version)

클릭하시면 다운로드가 진행되고

압축해제하신다음!

<div>
<img src="https://postfiles.pstatic.net/MjAxOTAxMTNfODcg/MDAxNTQ3MzA2MjE3OTA5.MNZtwHyTyiylv0TPbcsEbFwxLa9qUF6H3Gmxn3VblrEg.8aQSPl9dRBMUhCnn34AIQuognrsLyyycTWA68yXiUkMg.PNG.kwleepuppy/image.png?type=w773" width="90%"></img>
</div>

관리자 권한으로 시작하시면

<div>
<img src="https://postfiles.pstatic.net/MjAxOTAxMTNfMjM5/MDAxNTQ3MzA2MjczOTM3.VnA_hbaLhMhYBSNVsmURkT-TzvgKZWp9DG19cussTxkg.N95IXACSPCrbrvW3o4hW2OE5_TgEIcjnt-HBGUuzJe4g.PNG.kwleepuppy/image.png?type=w773" width="90%"></img>
</div>
요렇게 실행된 모습이 나옵니다.
<div>
<img src="https://postfiles.pstatic.net/MjAxOTAxMTNfMjM3/MDAxNTQ3MzA2NjA4NjA2.A-SsUW3HD43nM4w2qt5XS-OVYasODFixRdZeXWW_Q24g.n-SDqNAS3LXu701KHjclR9gIInAwnZQJORGwvmOS-Jog.PNG.kwleepuppy/image.png?type=w773" width="90%"></img>
</div>

<div>
<img src="https://postfiles.pstatic.net/MjAxOTAxMTNfNTUg/MDAxNTQ3MzA5MTY1MjA2.V-q88Jz1rfMN2i1hj1aG36MwSJUaMfD4PjFVjjv4Vjgg.iROoDcH3RdmNmME1DpjYxUU8C4C6aZeFNQpmUSEUJt4g.PNG.kwleepuppy/sf2.PNG?type=w773" width="90%"></img>
</div>
window7환경에서

vcruntime140d.dll이랑

ucrtbased.dll이 없어서 실행못한다고 나오네요..
<div>
<img src="https://postfiles.pstatic.net/MjAxOTAxMTNfMjg2/MDAxNTQ3MzA5MTYxOTMx.yAhOAfFa5bR1Ded3HOBb_8CxH-vR_kzfv0vs77A9hU8g.n4DWXEQCuvfUjoxjDcDgJXeBBU2R8AAKiqWs9_EKXX4g.PNG.kwleepuppy/sf1.PNG?type=w773" width="90%"></img>
<img src="https://postfiles.pstatic.net/MjAxOTAxMTNfNSAg/MDAxNTQ3MzA5MTg2MDE1.1yvyTNbrsT3efpk2j0WolekhLGjVIx38NA8f-P5cHq8g.Ff_2oXcje-5rBuAQVlCMSzha0XFMBEJ8gdSCcV5hYqkg.PNG.kwleepuppy/sf3.PNG?type=w773" width="90%"></img>
</div>
Visual c++깔아도 안되서

직접 vcruntime140d.dll

ucrtbased.dll 찾아서

C://Program File/System32/  이경로에 넣어줬습니다.
<div>
<img src="https://postfiles.pstatic.net/MjAxOTAxMTNfNSAg/MDAxNTQ3MzA5MTg2MDE1.1yvyTNbrsT3efpk2j0WolekhLGjVIx38NA8f-P5cHq8g.Ff_2oXcje-5rBuAQVlCMSzha0XFMBEJ8gdSCcV5hYqkg.PNG.kwleepuppy/sf3.PNG?type=w773" width="90%"></img>
</div>

실행된 모습!

# Process Explorer 설치하기

64비트버전과 32비트 버전이 존재한다.

https://docs.microsoft.com/en-us/sysinternals/downloads/process-explorer

 위 사이트에 들어가면
 
Process Explorer - Windows Sysinternals
Find out what files, registry keys and other objects processes have open, which DLLs they have loaded, and more.

docs.microsoft.com
<div>
<img src="https://postfiles.pstatic.net/MjAxOTAxMTJfMjc2/MDAxNTQ3MzAzMDM1Mjcz.JKgb_MBYT-WLcgLoW6Le6Lu2CA-AeEqBM-kHWVfl_7Eg.aVPSA3GziVU5kAsD38761_TQamQjv3RrWCg__mtB5c0g.PNG.kwleepuppy/image.png?type=w773" width="90%"></img>
</div>

이렇게 나오는데

Download Process Explorer을 클릭하면 설치가된다.

압축해제후

자신의 컴퓨터에 맞는 비트실행파일을 실행하면

<div>
<img src="https://postfiles.pstatic.net/MjAxOTAxMTJfMjA3/MDAxNTQ3MzAzMTQwODUz.XU5SkgTxcVGNLo80xr-Urx3UyCqSEWsJAmso74it4Qog.hsX6cl2kfKhjGr9MovwIW-eHc5bUJKHiuGTWdfshnO0g.PNG.kwleepuppy/image.png?type=w773" width="90%"></img>
</div>
이렇게 작업관리자와는 비교할 수 없는 뛰어난 화면 구성을 보여준다.

Process Explorer의 장점

1. 부모/자식 프로세스 트리 구조
2. 프로세스 실행/종료 시 각각의 색으로 표시
3. 프로세스 Suspend/Resume 기능
4. 프로세스 종료 기능
5. DLL/Handle 검색

앞으로 리버싱공부할때 켜놓고 보면 유용할듯!

# 스택 프레임 실습

실습 준비물

리버싱 핵심 원리 //인사이트 이승원 지음

컴퓨터, vmware workstation10

vmware에 깔린 window7

window7에 깔린 ollydbg

Visual studio 2017

인내심, 호기심

​

우선 visual studio에서

하던 방식대로 아무런 옵션을 주지 않고 컴파일했습니다.
<div>
<img src="https://postfiles.pstatic.net/MjAxOTAxMTVfNDcg/MDAxNTQ3NTY0MzUxNzg0.3d3TE3gZwQ7UiI2D0BjRW5Cfu_NtaviohLNS9PwNsrYg.nAE7vCr_753fEdZPi-FbTR2pF9wMWWgO0iD6Rx6PEVsg.PNG.kwleepuppy/sf16.PNG?type=w773" width="100%"></img>
</div>

그 후 실행파일을

Ollydbg가 있는 window7환경으로 옮겨준 후

Ollydbg에서 실행!

<div>
<img src="https://postfiles.pstatic.net/MjAxOTAxMTZfNTAg/MDAxNTQ3NTY0NDAyOTY3.4VNKoPShspN5vAE_xU5T1rFuxPM0hOYj30dwmJznS60g.BduUUdT8eLKtu-vaolYue10lHWp7u2scj62Bk2psy9Ig.PNG.kwleepuppy/sf10.PNG?type=w773" width="100%"></img>
</div>

잉?

<div>
<img src="https://postfiles.pstatic.net/MjAxOTAxMTZfMTUg/MDAxNTQ3NTY0NDE4NDE2.Wg36sV9WfYWH5RRzRrz5pRefRoQ2TbS4pOoMUxII7csg.tx7NhfCFeaEsFv66s8G4yTtymgCypCDvm3Kf8MlXLOwg.PNG.kwleepuppy/sf11.PNG?type=w773" width="100%"></img>
</div>

제가 원하던 모습이 아니었어요..

그렇게 2일간 main을 찾는 작업이 진행되었지만

이건 아닌 거 같아서

구글링을 했더니

빌드 할 때 두 가지 버전이 있다는 사실을 알게 되었습니다.

​

출처 : http://jiny2097.blog.me/30043517038

첫 번째. Debug mode build

- 실행파일에 디버깅 정보를 삽입하여 언제든지 디버깅을 할 수 있도록 하며 Debug 서브 폴더에 실행파일을 만들어줍니다.

- 디버깅 정보가 들어가 있기 때문에 실행파일 상태를 확인할 수 있습니다.

- 디버그에 필요한 정보들을 실행 시 계속 체크함으로써 속도가 느립니다.

- 디버그 빌드와 릴리스 빌드에서 서로 실행 결과가 다른 경우?

   특히 디버그 빌드에서는 괜찮은데 릴리스 빌드에서만 오류가 발생하여 프로그램이 죽는 경우가 있는데 

   이런 경우는 대부분 메모리가 깨진 경우에 발생합니다. 두 모드에서 동적으로 메모리를 할당하면 힙 영역에 요청한 크기만큼 메모리를 할당받게 되는데 그 초기값이 다릅니다.

- 릴리스 모드와 디버깅 모드의 차이점은?

   디버깅 정보를 실행 코드 안에 넣느냐 안 넣느냐가 차이점이 되겠지요.

   즉, 디버거 모드로 컴파일하게 되면 실행상태에서 추적할 수 있는 정보가 실행파일 안에 들어가게 되므로

   용량이 커지고, 릴리스 모드의 경우 디버깅 정보 없이 순수한 소스코드 자체의 기능만 컴파일되어 실행파일로 만들어집니다.

​

두 번째. Release mode build

- 초기화하지 않습니다.

- 같은 문자열 상수라도 서로 다른 공간에 할당됩니다.

- 디버깅 정보를 삽입하지 않고 코드를 최적화하여 실행 파일 크기를 최대한 줄여줍니다.

- 속도나 크기 면에서 월등히 유리합니다. (메모리 점유율로 낮아지고 실행도 빨라짐)

- 더 이상 현재 버전에서 내 결함성이나 문제점들을 발견할 수 없었을 때 빌드 하여 주는 모드입니다.

​

디버깅 모드로 하면. text 부분에 빈값만 저장되어 정보가 가려졌습니다..

​

그래서 Release mode로 build 하여

재실행 결과

<div>
<img src="https://postfiles.pstatic.net/MjAxOTAxMTZfNTgg/MDAxNTQ3NTY0ODQ0OTc1.7nZPxjgL7KSXokO5i-j4AxQSfQCJjdP-Il9uHssFvXgg.aEOycNwwuwkXtXztHtSTPinoEdpKO8xIJf485THqvsYg.PNG.kwleepuppy/sf6.PNG?type=w773" width="100%"></img>
</div>

비교적 쉽게 메인을 찾아갈 수 있었습니다.

​

이제 '스택 프레임' 실습을 진행할 준비가 되었습니다.

​

스택 프레임이란?

-ESP(스택 포인터)가 아닌 

 EBP(베이스 포인터) 레지스터를 사용하여 스택 내의 로컬 변수, 파라미터, 복귀 주소에 접근하는 기법
 
<div>
<img src="https://postfiles.pstatic.net/MjAxOTAxMTZfMTgw/MDAxNTQ3NTY1MDUzMzcz.bNU3OWiUx183dM6jW3M8KR0meTBP8ZwAzBAuBP2ClCgg.IS0fHikZ1iTaMBWeGFb6R7z1DZ3UAE66KAkpn7OYJrgg.PNG.kwleepuppy/sf12.PNG?type=w773" width="100%"></img>
</div>
​


메인 함수를 호출합니다.
<div>
<img src="https://postfiles.pstatic.net/MjAxOTAxMTZfMjc2/MDAxNTQ3NTY1MDY0MTgw.xWjmI3gJuuXB8ND5TiiHLFKrcQa9WfhkfBVNNDJ1qREg.F7O3-yi0CxVeDxYarMIUN17Dd05D4jw1qwPzT9XEKQYg.PNG.kwleepuppy/sf13.PNG?type=w773" width="100%"></img>
</div>

여기서부터 EBP(베이스 포인터)를 사용하는 모습이 보입니다.

main 함수에 들어온 후 EBP에 현재 스택 포인터 값을 넣어줍니다.
<div>
<img src="https://postfiles.pstatic.net/MjAxOTAxMTZfMTUg/MDAxNTQ3NTY1MDY0MjQw.OcviTzDAtMTumzpR3VWNu47pmPPNYTJD_ZSNnbAEXgog.pNScUuwavJ_4D8VojlVKCv2Kp2f_RROtdKEwZ-BjiXkg.PNG.kwleepuppy/sf14.PNG?type=w773" width="100%"></img>
</div>

스택 부분에서 Relative to EBP를 설정하면

스택 창에서 EBP의 위치를 확인할 수 있습니다.

​

로컬 변수 세팅

ESP 값에서 변숫값만큼의 크기를 빼줍니다.

char[20]에 char b, c 면 이론상 22byte를 할당

인데 18만 빼주네요.

ex) 최적화가 되어 char a[20] = "Hello Hello Hello";

널문자까지 총 18byte만 할당되었다고 생각됩니다.

<div>
<img src="https://postfiles.pstatic.net/MjAxOTAxMTZfNDIg/MDAxNTQ3NTY1MDY0MTg4.K7cwWvJpkvUcX_TgqRubdHzlHH7NqOAi4HZ9OWuSQBog.EPx8SqH8Z3yquYneLZpv--AJE2oFw0p95SUXmr4CXgEg.PNG.kwleepuppy/sf15.PNG?type=w773" width="100%"></img>
<img src="https://postfiles.pstatic.net/MjAxOTAxMTZfMjQw/MDAxNTQ3NTY1MDc0NzE0.OupFTCVth4qvWWamhhsOQl--4KOiLcaAKnXUQYFvH0gg.YjV3y3ewFisD095tT3-3ZYqDdtMy25bLctUiF4zm7fog.PNG.kwleepuppy/sf17.PNG?type=w773" width="100%"></img>
</div>
그렇게 Hello Hello Hello가 저장되고

<div>
<img src="https://postfiles.pstatic.net/MjAxOTAxMTZfODUg/MDAxNTQ3NTY1MDc0NzQ2.plHaihK_OXSz0E49BIiY5V7CDdKbHbpuENaGPofWWEIg.U88LTXueKiZWOKTpGgGWCzsJJk_-UdWYe0TixWysJGQg.PNG.kwleepuppy/sf18.PNG?type=w773" width="100%"></img>
</div>

printf 함수를 호출하기 위해 포맷 형식과 문자열이 있는 주소를 넣고 printf 함수를 호출하는 모습

호출하면 다시

<div>
<img src="https://postfiles.pstatic.net/MjAxOTAxMTZfMTU3/MDAxNTQ3NTY1MDc0NzU0.aYrKmuMkIGBJrOoHF80dLe_LwF7Cdzp4Ax5fO1UnO-cg.40eMqdHZvLkTYVg6Ddpz-OlzSgFLpDENjSg4yvPj7fIg.PNG.kwleepuppy/sf19.PNG?type=w773" width="100%"></img>
</div>

EBP에 현재 스택 포인터를 넣어주는 모습

그렇게 printf 함수가 실행되고 종료될 때는

printf 함수의 스택 프레임 해제와 함수 종료(리턴)을

진행하야 합니다.

<div>
<img src="https://postfiles.pstatic.net/MjAxOTAxMTZfMjUg/MDAxNTQ3NTY1MDc0Nzkz.1g0Tbw-tmI8PXkUitDZVkx-e3ko02jZe2ntMwhaChDkg.Dty-d5I5I_WnZ5tN7GHVL_lbqzAivTn3GBZn2xky4Ccg.PNG.kwleepuppy/sf20.PNG?type=w773" width="100%"></img>
</div>

이때 printf 함수 부분에서 EBP 부분을 POP 해주는 모습이 보이고

ADD ESP, 8로 printf 함수 호출 후 스택을 정리하는 모습이 보이며

그 후 main 함수 마지막 부분에서 

MOV ESP, EBP 해주고

POP EBP를 해주며

main 함수를 호출하기 전의 스택 상태로 완벽하게 돌아가는 모습을 볼 수 있습니다.

프로그램은 이런 식으로 스택을 관리한다는 것을 알 수 있었습니다.

​

수시로 변경되는 ESP 대신 EBP 레지스터를 사용하여 로컬 변수, 파라미터, 복귀 주소 등을 관리하는 방법을 직접 실습해 보았는데  눈이 살짝 아팠지만ㅎ 리버싱 초심자로써 많은 도움이 되었다 생각합니다.

debug 모드에서 build 한 실행파일에 빠져서 허둥 되며 리버싱을 막기 위해서 여러 방식으로 막아놨구나를 벌써 알게 되어서 좋은 경험(삽질)이 되었습니다.

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

# PE format-1
PE(Portable Executable)?

윈도우 운영체제에서 사용되는 실행 파일 형식.

PE32라고 불리며 64비트는 PE+ 또는 PE32+라고 불린다.

​

PE 파일의 종류

실행 계열 : EXE, SCR

라이브러리 계열 : DLL, OCX, CPL, DRV

드라이버 계열 : SYS, VXD

오브젝트 파일 계열 : OBJ

이중에서 봤던 확장자는 

윈도우에서 흔히 사용하는 EXE

동적 라이브러리인 DLL

드라이버 계열 SYS 정도만 봤던거 같다.

​

이제 헥스 에디터인 HxD를 이용하여 

C:\WINDOWS\system32\notepad.exe

경로에 있는 메모장을 열어보았다.
<div>
<img src="https://postfiles.pstatic.net/MjAxOTAxMjJfMjM1/MDAxNTQ4MTY0NDMyODQ1.Lfvm3-sbdKnQv4-LTpVXL7a8l8CKmRgi760Uq4IQb1gg.1yPcuQG8fjidVve_z6lA-2U3oKWeiWRbbd2TpW3oqVMg.PNG.kwleepuppy/image.png?type=w773" width="90%"></img>
</div>

메모장 파일의 시작 부분이고 PE파일의 헤더 부분이다.

PE헤더에는 notepad.exe 파일이 실행되기 위해 필요한 모든 정보가 들어있다.

메모리 적재 방법, 어디서부터 실행하는지, 실행에 필요한 DLL들, 필요한 스택/힙 메모리의 크기 선언

등등 구조체 형시으로 저장되어 있다.

 
pe format - Gumus.northeastfitness.co
Pe Format pe portable executable на странных берегах хабр . windows how to determine the size of an pe executable file from . 64 bit pe 101 a windows executable walkthough computer science file . portable executable wikipedia . pe format . stanislav slusny . malware researcher s handbook demystifyin...

gumus.northeastfitness.co

 출처 : http://gumus.northeastfitness.co/pe-format/

<div>
<img src="https://postfiles.pstatic.net/MjAxOTAxMjJfOSAg/MDAxNTQ4MTY0ODY0NTA5.TXRPZ1J27hebanYnYxMlFaOWV_owD15PYdfDpcWP9iYg.mnXYTnzPQuVG3hYytIINNuDiA5s8GC5XEf3eObfWppMg.PNG.kwleepuppy/image.png?type=w773" width="90%"></img>
</div>
섹션 헤더에 각 Section에 대한 파일/메모리에서의 크기, 위치, 속성 등이 정의 되어 있다.

PE헤더의 끝부분과 각 섹션의 끝에는 NULL padding이라고 불리는 영역 존재

이유는

파일/메모리에서 섹션의 시작 위치는 각 파일/메모리의 최소 기본 단위의 배수에 해당하는 위치여야 한다.

즉 남은 빈 공간은 NULL로 채움.

​

VA & RVA

VA(Virtual Address)는 프로세스 가상 메모리의 절대주소

RVA(Relative Virtual Address)는 기준 위치(ImageBase)에서부터의 상대주소.

​

RVA + ImageBase = VA

​

PE헤더 내의 정보는 RVA로 된것이 많다.

Relocation이 발생해도 기준위치에 대한 상대주소가 변하지 않기 때문이다.

​

DOS Header

DOS 파일에 대한 하위 호환성을 고려하여 만든 것

//IMAGE_DOS_HEADER 구조체 크기 40 *e_magic과 e_lfanew가 핵심!

typedef struct _IMAGE_DOS_HEADER{

    WORD e_magic;  //DOS signature : 4D5A ("MZ") 아스키값으로 MZ
    WORD e_cblp; 
    WORD e_cp;
    WORD e_crlc;
    WORD e_cparhdr;
    WORD e_minalloc;
    WORD e_maxalloc;  
    WORD e_ss; 
    WORD e_sp;
    WORD e_csum;
    WORD e_ip;
    WORD e_cs;
    WORD e_lfarlc;
    WORD e_ovno;
    WORD e_res[4];
    WORD e_oemid;
    WORD e_res2[10];
    LONG e_lfanew;  //offset to NT header 파일에 따라 가변적인 값을 가짐
    
}

 위에 에디터로 본 notepad.exe에서

첫 부분에 4D 5A가 쓰여있고 아스키로 MZ로  보여진다.
<div>
<img src="https://postfiles.pstatic.net/MjAxOTAxMjJfMTI1/MDAxNTQ4MTY2ODYxODUx.upb-jEu_lcF2gVFEeQG4OX7B2sk6TaW89E8c941SVPcg.Q-19qLa44PhkxMcKdYI_ebgrQW3U7FzmZA5wMF4-YbEg.PNG.kwleepuppy/image.png?type=w773" width="90%"></img>
</div>

e_lfanew의 값은 000000E8 (리틀 엔디언 표기법)

​<div>
<img src="https://postfiles.pstatic.net/MjAxOTAxMjJfMjQ1/MDAxNTQ4MTY3MDc3NjE4.lFbRteYBQYT8LbEdJGmgKMYEQ7XjiTxy9cEu36NdIdEg.o0eBK9JM_PcBGh-2uL9IIdl4iThx2W99Z3-C8UJnxckg.PNG.kwleepuppy/image.png?type=w773" width="90%"></img>
</div>


윈도우 10 home 에서 e_magic부분인 MZ중 Z를 Y로 바꾸려고

시도해봤지만 파일을 쓰기 접근을 위해 열수 없다고 나온다.

​

책에서는 XP환경이라 수정할 수 있었다.

​

DOS Stub

DOS Header 밑에는 DOS Stub이 존재한다.

존재 여부는 옵션

크기 일정하지 않음

없어도 실행에 문제 없음

코드와 데이터의 혼합으로 이루어져 있다.

<div>
<img src="https://postfiles.pstatic.net/MjAxOTAxMjJfMTA1/MDAxNTQ4MTY3Mzg1Mjk1.IHjoO6x28gxP0XeQ8JP4qJc3yzU-ABWFzNIcDb7AfgMg.Ts0f_NCIAtOchwPS731Lz4QEfGUh1XOyPgqZsjUPqMkg.PNG.kwleepuppy/image.png?type=w773" width="90%"></img>
</div>
DOS Stub 부분

XP환경에서만 DOS용 디버거를 이용해서 실행하면 코드로 실행가능함

명령

debug C:\Windows\notepad.exe

개발 도구에서 지원해줘야 함

(VB, VC++, Delphi 등은 DOS Stub을 기본 지원)

# PE format-2 File Header
NT Header

NT Header 구조체 IMAGE_NT_HEADERS

typedef struct _IMAGE_NT_HEADERS {

    DWORD Signature;                  // PE Signaure : 50450000 ascii("PE"00)
    
    IMAGE_FILE_HEADER FileHeader;
    
    IMAGE_OPTIONAL_HEADER32 OptionalHeader;
    
} IMAGE_NT_HEADERS32, *PIMAGE_NT_HEADERS32;

 3개의 멤버로 되어 있고

제일 첫 멤버는 

Signature로 50450000("PE"00)  의 값을 갖는다.
<div>
<img src="https://postfiles.pstatic.net/MjAxOTAxMjRfMjcw/MDAxNTQ4MjU1ODQ5MDMw.HwUWvvaQ5Xw2erEoLvfx_1-QyxL6UMFQo_ua9H4qQVAg.LKOxd2c-MXfXu-WeOHbDNCttvjUPz6i8nQ9grl5EGzgg.PNG.kwleepuppy/image.png?type=w773" width="90%"></img>
</div>

IMAGE_NT_HEADERS의 내용을 hex editor로 봤을때의 모습

​

NT Header - File Header

파일의 개략적인 속성을 나타내는

IMAGE_FILE_HEADER 구조체이다.

typedef struct _IMAGE_FILE_HEADER {

    WORD Machine;
    
    WORD NumberOfSections;
    
    DWORD TimeDateStamp;
    
    DWORD PointerToSymbolTable;
    
    DWORD NumberOfSymbols;
    
    WORD SizeOfOptionalHeader;
    
    WORD Characteristics;
    
} IMAGE_FILE_HEADER, *PIMAGE_FILE_HEADER

 1. Machine

CPU별로 고유한 값

​

2. NumberOfSections

섹션의 개수 0보다 커야함

​

3. SizeOfOptionalHeader

IMAGE_NT_HEADERS 구조체의 마지막 멤버

구조체의 크기를 나타낸다.

(IMAGE_OPTIONAL_HEADER32)구조체의 크기

​

4. Characteristics

파일의 속성을 나타내는 값

실해잉 가능한지 DLL파일인지

정보들이 bit OR 형식으로 조합된다.

예를들면

#define IMAGE_FILE_EXECUTABLE_IMAGE 0x0002

#define IMAGE_FILE_DLL 0x2000

으로 정의 되어 있는데

PE파일 중에 Characteristics 값에 0002값이 없는 경우

(not executable)

*.obj파일과 resource DLL 같은 파일이 있다.

​

5. TimeDateStamp

실행에 영향을 미치지 않는 값

해당 파일의 빌드 시간을 나타낸 값이다.

​
<div>
<img src="https://postfiles.pstatic.net/MjAxOTAxMjRfNDAg/MDAxNTQ4MjU3ODYxMTkw.ivo9QjmdBt45r3CjdRThyic1mxqzWaSKJL0qBfe4YEcg.4gai2pgb7FYTqf7sR5ho3c4VQ1oixdErnv5LBGQTBiwg.PNG.kwleepuppy/image.png?type=w773" width="90%"></img>
</div>

이제 Hex Editer 에서 notepad.exe의 IMAGE_FILE_HEADER구조체를 확인해보면

​

0x8664 machine

0x0006 number of sections

section이 책에는 3개인데 win10환경에서는 6개네요

0x840F275E time date stamp

0x00000000 offset to symbol table

0x00000000 number of sybols

0x00F0 size of optional header

0x0022 characteristics

IMAGE_FILEEXECUTABLE_IMAGE(0x0002) 

(or연산)

 IMAGE_FILE_LARGE_ADDRESS_AWARE(0x0020)

을 하면 0x0022가 나옵니다!.

​

하나하나 따라가다보니까

금방금방 할 것 같습니다.

​
# PE File Format-3 NT Header - Optional Header

PE 헤더 구조체 중에서 가장 크기가 큰

IMAGE_OPTIONAL_HEADER32
```
typedef struct _IMAGE_DATA_DIRECTORY {

    DWORD VirutualAddress;
    DWORD Size;

} IMAGE_DATA_DIRECTORY, *PIMAGE_DATA_DIRECTORY;

#define IMAGE_NUMBEROF_DIRECTORY_ENTRIES 16

typedef struct _IMAGE_OPTIONAL_HEADER {

  WORD                 Magic;
  BYTE                 MajorLinkerVersion;
  BYTE                 MinorLinkerVersion;
  DWORD                SizeOfCode;
  DWORD                SizeOfInitializedData;
  DWORD                SizeOfUninitializedData;
  DWORD                AddressOfEntryPoint;
  DWORD                BaseOfCode;
  DWORD                BaseOfData;
  DWORD                ImageBase;
  DWORD                SectionAlignment;
  DWORD                FileAlignment;
  WORD                 MajorOperatingSystemVersion;
  WORD                 MinorOperatingSystemVersion;
  WORD                 MajorImageVersion;
  WORD                 MinorImageVersion;
  WORD                 MajorSubsystemVersion;
  WORD                 MinorSubsystemVersion;
  DWORD                Win32VersionValue;
  DWORD                SizeOfImage;
  DWORD                SizeOfHeaders;
  DWORD                CheckSum;
  WORD                 Subsystem;
  WORD                 DllCharacteristics;
  DWORD                SizeOfStackReserve;
  DWORD                SizeOfStackCommit;
  DWORD                SizeOfHeapReserve;
  DWORD                SizeOfHeapCommit;
  DWORD                LoaderFlags;
  DWORD                NumberOfRvaAndSizes;
  IMAGE_DATA_DIRECTORY DataDirectory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];

} IMAGE_OPTIONAL_HEADER32, *PIMAGE_OPTIONAL_HEADER32;
```
<div>
<img src="https://postfiles.pstatic.net/MjAxOTAxMjVfMTk4/MDAxNTQ4MzQ3MDQyMjgz.YVFM4luJrma-GZ2usp-uEGWT8Syh9FZo9OiFItB_gRcg.EROjMlN__q0IzjCzhQkPyqxMY9DF5UdYs8CNOa6EqCUg.PNG.kwleepuppy/image.png?type=w773" width="90%"></img>
</div>
 IMAGE_OPTIONAL_HEADER64


필수적인 멤버들

## 1. Magic

IMAGE_OPTIONAL_HEADER32인 경우에 10B

IMAGE_OPTIONAL_HEADER64인 경우에는 20B를 가짐

​

## 2. AddressOfEntryPoint

EP(Entry Point)의 RVA(Relative Virtual Address)값을 가지고 있음

프로그램에서 최초로 실행되는 코드의 시작 주소를 갖는다.

​

## 3. ImageBase

32비트 컴퓨터 프로세스의 가상 메모리는 0~FFFFFFFF 범위를 갖는다.

EXE,DLL 파일은 user memory 영역

0~7FFFFFFF범위에 로딩

SYS 파일은 kernel memory 영역인

80000000~FFFFFFFF 범위에 로딩

일반적인 개발 도구(VB/VC++/Delphi)들이

만들어내는 EXE 파일의 Image base 값은 04000000

DLL 파일의 Image base 값은 10000000

(디폴트값)

PE로더는 PE파일을 실행시키기 위해 프로세스를 생성하고

파일을 메모리에 로딩한 후 EIP 레지스터 값을

ImageBase + AddressOfEntryPoint 값으로 세팅한다.

​

## 4. SectionAlignment, FileAlignment

파일에서 섹션의 최소단위를 나타내는 것이 FileAlignment

메모리에서 섹션의 최소단위를 나타내는 것이 SectionAlignment

파일/메모리의 섹션 크기는 반드시 각각 FileAlignment/SectionAlignment의 배수가 되어야 한다.

​

## 5. SizeOfImage

가상 메모리에서  PE Image가 차지하는 크기를 나타낸다.

​

## 6. SizeOfHeader

PE헤더의 전체 크기를 나타낸다.

FileAlignment의 배수여야 한다.

파일 시작에서 SizeOfHeader 옵셋만큼 떨어진 위치에 첫 번쩨 섹션이 위치

​

## 7. Subsystem

Subsystem의 값을 보고

*.sys인지 *.exe, *.dll 인지 구분할 수 있다.

값 1 Driver file 시스템 드라이버

값 2 GUI파일 창 기반 애플리케이션

값 3 CUI파일 콘솔 기반 애플리케이션

​

## 8. NumberOfRvaAndSizes

IMAGE_DATA_DIRECTORY 구조체 배열의 각 항목마다 정의된 값을 가진다.
```c
DataDirectory[0] = EXPORT Directory
DataDirectory[1] = IMPORT Directory
DataDirectory[2] = RESOURCE Directory
DataDirectory[3] = EXCEPTION Directory
DataDirectory[4] = SECURITY Directory
DataDirectory[5] = BASERELOC Directory
DataDirectory[6] = DEBUG Directory
DataDirectory[7] = COPYRIGHT Directory
DataDirectory[8] = GLOBALPTR Direcotry
DataDirectory[9] = TLS Direcotry
DataDirectory[A] = LOAD_CONFIG Directory
DataDirectory[B] = BOUND_IMPORT Directory
DataDirectory[C] = IAT Directory
DataDirectory[D] = DELAY_IMPORT Directory
DataDirectory[E] = COM_DESCRIPTOR Directory
DataDirectory[F] = Reserved Directory
 ```
 <div>
<img src="https://postfiles.pstatic.net/MjAxOTAxMjVfNDUg/MDAxNTQ4MzQyNTM0MjA0.X8A5QORSrvLQip06Pr_f7gwViWsDntJCeuj4xWIu-K0g.fLZR4U9yWYCx45-vOxRJEGbLjmxkxnYMs6i0YcyBohYg.PNG.kwleepuppy/image.png?type=w773" width="90%"></img>
</div>

 ```c
//IMAGE_OPTIONAL_HEADER  notepad.exe

value    desciprtion
020B     magic // 64비트라는 것을 알 수 있다.
0E       major linker version
0C       miner linker version
00108E00 size of code
00025000 size of initialized data
00000000 size of uninitialized data
00019180 address of entry point
00001000 base of code
// base of data 64비트에서는 삭제
4000000000000001 image base   //64bit 에서는 ULONGLONG
00001000 section alignment
00000200 file alignment
000A     major OS version
0000     minor OS version
000A     major image version
0000     minor image version
000A     major subsystem version
0000     minor subsystem version
00000000 win32 version value
00041000 size of image
00000400 size of headers
00041603 Checksum
0002     subsystem
C160     DLL characteristics
0000000000080000 size of stack reserve    //64bit 에서는 ULONGLONG
0000000000011000 size of stack commit    //64bit 에서는 ULONGLONG
0000000000100000 size of heap reserve    //64bit 에서는 ULONGLONG
0000000000001000 size of heap commit    //64bit 에서는 ULONGLONG
00000000 loader flags
00000010 number of directories
00000000 RVA of EXPORT Directory
00000000 size of EXPORT Directory
0010F448 RVA of IMPORT Directory
00000244 size of IMPORT Directory
00026000 RVA of RESOURCE Directory
00019CE0 size of RESOURCE Directory
00025000 RVA of EXCEPTION Directory
000008B8 size of EXCEPTION Directory
00000000 RVA of SECURITY Directory
00000000 size of SECURITY Directory
00040000 RVA of BASERELOC Directory
00000218 size of BASERELOC Directory
0001E310 RVA of DEBUG Directory
00000054 size of DEBUG Directory
00000000 RVA of COPYRIGHT Directory
00000000 size of COPYRIGHT Directory
00000000 RVA of GLOBALPTR Directory
00000000 size of GLOBALPTR Directory
00000000 RVA of TLS Directory
00000000 size of TLS Directory
0001A550 RVA of LOAD_CONFIG Directory
00000100 size of LOAD_CONFIG Directory
00000000 RVA of BOUND_IMPORT Directory
00000000 size of BOUND_IMPORT Directory 
0001A650 RVA of IAT Directory
00000970 size of IAT Directory
00000000 RVA of DELAY_IMPORT Directory
00000000 size of DELAY_IMPORT Directory
00000000 RVA of COM_DESCRPTOR Directory
00000000 size of COM_DESCRPTOR Directory
00000000 RVA of Reserved Directory
00000000 size of Reserved Directory
```
 32비트와 64비트

IMAGE_OPTIONAL_HEADER차이가 없을거 같다고 생각해서

하나하나 비교해가며 대입해보니

무려 4byte가 남았다

그래서 

ms(https://docs.microsoft.com/en-us/windows/desktop/api/winnt/ns-winnt-image_optional_header64)



 
IMAGE_OPTIONAL_HEADER64
Represents the optional header format.

docs.microsoft.com

 다른 점을 찾아보니

imagebase, size of stack reserve, 

size of stack commit , 

size of heap reserve,

size of heap commit

요 녀석들이 ULONGLONG으로 확장되었고

base of data부분이 제거 되었다.

​

시력이 좋아진거 같다.


잘못된 정보는 지적(댓글) 감사합니다.

