1. RVA가 속해 있는 섹션 찾기

2. 비례식을 사용하여 RAW 계산하기

​

RAW - PointerToRawData = RVA - VirtualAddress

RAW = RVA - VirtualAddress + PointerToRawData

​
<div>
<img src="https://postfiles.pstatic.net/MjAxOTAxMjlfNDMg/MDAxNTQ4NzcyOTY2NTUz.eoy-ZiQeuqlMsiKS0NhMJJDy4YAci2RRRjXiuzoY84og.fGyFeLx_LS7wSE8Sg3QrHF40suVC7klqPLBaD81aPzUg.PNG.kwleepuppy/%EC%BA%A1%EC%B2%981.PNG?type=w773" width="90%"></img>
</div>

그림에서 메모리부분을 보면 0x01000000부터 시작하는데

​

ImageBase라고 생각하면 된다. ImageBase = 0x01000000

​

RAW = 0x12345일 때 File Offset = ?

​

0x12345가 .rsrc섹션에 속해 있을때

VA(메모리에 올라가는 .rsrc섹션 시작주소)를 0xB000 이라고 가정

PointerToRawData(파일에 들어있는 .rsrc섹션 시작주소) 0x8400이라고 가정하면

​

RAW = 0x12345 - 0xB000(VA) + 0x8400(PointerToRawData)

RAW = 0xF745

​

즉 파일에 들어있는 .rsrc섹션중 0xF645부분에 있다 라고 계산할 수 있다.
