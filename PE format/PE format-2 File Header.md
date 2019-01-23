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

잘못된 정보는 지적(댓글) 감사합니다.
