# Section Header

```c

typedef struct _IMAGE_SECTION_HEADER {  //IMAGE_SECTION_HEADER 구조체
  BYTE  Name[IMAGE_SIZEOF_SHORT_NAME];
  union {
    DWORD PhysicalAddress;
    DWORD VirtualSize;
  } Misc;
  DWORD VirtualAddress;
  DWORD SizeOfRawData;
  DWORD PointerToRawData;
  DWORD PointerToRelocations;
  DWORD PointerToLinenumbers;
  WORD  NumberOfRelocations;
  WORD  NumberOfLinenumbers;
  DWORD Characteristics;
} IMAGE_SECTION_HEADER, *PIMAGE_SECTION_HEADER; 

```

출처 : https://docs.microsoft.com/en-us/windows/desktop/api/winnt/ns-winnt-image_section_headerIMAGE_SECTION_HEADERRepresents the image section header format.docs.microsoft.com

```c

#define IMAGE_SCN_CNT_CODE                0x00000020 //Section contains code.
#define IMAGE_SCN_CNT_INITTALIZED_DATA    0x00000040 //Section contains initalized data.
#define IMAGE_SCN_CNT_UNINITIALIZED_DATA  0x00000080 //Section contains uninitialized data.
#define IMAGE_SCN_MEM_EXECUTE             0x20000000 //Section is executable.
#define IMAGE_SCN_MEM_READ                0x40000000 //Section is readable.
#define IMAGE_SCN_MEM_WRITE               0x80000000 //Section is writable.

```
Name[~]항목은어떤한 값이와도 상관 없다..code섹션에 .data라는 이름을 줄 수 있다.
즉 참고용 (주석같은 역할)
이제 직접 notepad.exe의 섹션 헤더 배열을봐보자.

<div>
<img src="https://postfiles.pstatic.net/MjAxOTAxMjdfMTEz/MDAxNTQ4NTE4NTYwMzQ1.TfGU8OuLvYAa-ZH0zpvSxUeo9c8O9tdy2JFw2xJVTOMg.hPfXPesrqHIgo1BJ90fx-yNvNpW0ve9LOx6dd-yzZ7Eg.PNG.kwleepuppy/image.png?type=w773" width="90%"></img>
</div>

섹션은 6개로 나눠져 있는 것으로 확인.

<div>
<img src="https://postfiles.pstatic.net/MjAxOTAxMjdfMTAx/MDAxNTQ4NTE4NDgwNDI3.5O3VdxNVmNRnK0lj5r0ow6lABX3HIodD5VZoom1CjXog.hw5Pav36wEbLWojfqDjxVvf-ZHW0rfcPdUPGhBkfMVYg.PNG.kwleepuppy/image.png?type=w773" width="90%"></img>
</div>

첫 사진 오른쪽에 아스키코드를 참고해보면
.text.rdata.data.pdata.rsrc.reloc이렇게 6개의 섹션이름이 보인다.
그럼 지금부터 하나하나 따라가보겠다.

```c 

//IMAGE_SECTION_HEADER

0x2E74657874000000 (ASCII) .text
0x00018D6E virtual size
0x00001000 RVA
0x00018E00 size of raw data
0x00000400 offset to raw data
0x00000000 offset to raw data
0x00000000 offset to relocations
0x00000000 offset to line numbers
0x0000 number of relocations
0x0000 nmber of line numbers
0x60000020 characteristics (IMAGE_SCT_CODE, IMAGE_SCN_MEM_EXECUTE, IMAGE_SCN_MEM_READE)

```

```c 

0x2E72646174610000 (ASCII) .rdata
0x00007560 virtual size
0x0010A000 RVA
0x00007600 size of raw data
0x00109200 offset to raw data
0x00000000 offset to relocations
0x00000000 offset to line numbers
0x0000 number of relocations
0x0000 number of line numbers
0x40000040 characterlistics

0x2E64617461000000 (ASCII) .data
0x00002D14 virtual size
0x00022000 RVA
0x00000C00 size of raw data
0x00020800 offset to raw data
0x00000000 offset to relocations
0x00000000 offset to line numbers
0x0000 number of relocations
0x0000 number of line numbers
0xC0000040 characterlistics

0x2E70646174610000 (ASCII) .pdata
0x000008B8 virtual size
0x00025000 RVA
0x00000A00 size of raw data
0x00021400 offset to raw data
0x00000000 offset to relocations
0x00000000 offset to line numbers
0x0000 number of relocations
0x0000 number of line numbers
0x40000040 characterlistics

0x2E72737263000000 (ASCII) .rsrc
0x00019CE0 virtual size
0x00026000 RVA
0x00019E00 size of raw data
0x00021E00 offset to raw data
0x00000000 offset to relocations
0x00000000 offset to line numbers
0x0000 number of relocations
0x0000 number of line numbers
0x40000040 characterlistics

0x2E72656C6F630000 (ASCII) .reloc
0x00000218 virtual size
0x00040000 RVA
0x00000400 size of raw data
0x0003BC00 offset to raw data
0x00000000 offset to relocations
0x00000000 offset to line numbers
0x0000 number of relocations
0x0000 number of line numbers
0x42000040 characterlistics

```

SectionHeaderEND
