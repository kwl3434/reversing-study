NT Header - Optional Header

PE 헤더 구조체 중에서 가장 크기가 큰

IMAGE_OPTIONAL_HEADER32
\`
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
\`
 IMAGE_OPTIONAL_HEADER64


필수적인 멤버들

1. Magic

IMAGE_OPTIONAL_HEADER32인 경우에 10B

IMAGE_OPTIONAL_HEADER64인 경우에는 20B를 가짐

​

2. AddressOfEntryPoint

EP(Entry Point)의 RVA(Relative Virtual Address)값을 가지고 있음

프로그램에서 최초로 실행되는 코드의 시작 주소를 갖는다.

​

3. ImageBase

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

4. SectionAlignment, FileAlignment

파일에서 섹션의 최소단위를 나타내는 것이 FileAlignment

메모리에서 섹션의 최소단위를 나타내는 것이 SectionAlignment

파일/메모리의 섹션 크기는 반드시 각각 FileAlignment/SectionAlignment의 배수가 되어야 한다.

​

5. SizeOfImage

가상 메모리에서  PE Image가 차지하는 크기를 나타낸다.

​

6. SizeOfHeader

PE헤더의 전체 크기를 나타낸다.

FileAlignment의 배수여야 한다.

파일 시작에서 SizeOfHeader 옵셋만큼 떨어진 위치에 첫 번쩨 섹션이 위치

​

7. Subsystem

Subsystem의 값을 보고

*.sys인지 *.exe, *.dll 인지 구분할 수 있다.

값 1 Driver file 시스템 드라이버

값 2 GUI파일 창 기반 애플리케이션

값 3 CUI파일 콘솔 기반 애플리케이션

​

8. NumberOfRvaAndSizes

IMAGE_DATA_DIRECTORY 구조체 배열의 각 항목마다 정의된 값을 가진다.
\`
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
 \`
 
 \`
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
\`
 32비트와 64비트

IMAGE_OPTIONAL_HEADER차이가 없을거 같다고 생각해서

하나하나 비교해가며 대입해보니

무려 4byte가 남았다

그래서 

https://docs.microsoft.com/en-us/windows/desktop/api/winnt/ns-winnt-image_optional_header64



 
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
