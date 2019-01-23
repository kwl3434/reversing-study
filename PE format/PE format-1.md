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


