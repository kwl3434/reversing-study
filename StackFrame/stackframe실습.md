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
