# CodeEngn Basic 1

https://www.codeengn.com/

<div>
<img src="https://postfiles.pstatic.net/MjAxOTAyMTBfMTE4/MDAxNTQ5NzI5NTU0Nzky.UhTNokozsk0OHe1q6IRLsCZH1E9U3WJXfdIuI49FnsIg.OjqloI2ASkwKxVbjjveUu1xMNuirStRYP_Xu9ZDj6oUg.PNG.kwleepuppy/image.png?type=w773" width="90%"></img>
</div>
GetDriveTypeA라는 

윈도우 함수를 알아야 풀 수 있는 문제!
출처 : https://docs.microsoft.com/en-us/windows/desktop/api/fileapi/nf-fileapi-getdrivetypea
<div>
<img src="https://postfiles.pstatic.net/MjAxOTAyMTBfMjc5/MDAxNTQ5NzI5NDU4Njc3.c24b4JZ0MEyQDYXCgacLgsIURDzgS_Va460onSJl8vQg.Y2hRcRhmwBvR9CeuRia35lw-lU95_ddD5cwAWkQDvuwg.PNG.kwleepuppy/%EC%BA%A1%EC%B2%988.PNG?type=w773" width="90%"></img>
</div>
GetDriveTypeA의 리턴값

​

디버거는

x64 이용.
<div>
<img src="https://postfiles.pstatic.net/MjAxOTAyMTBfMTEx/MDAxNTQ5NzI5NDQ0MDQ1.C8P_yLFw_o5H1J7PqJt8DAxQP-Hw3nd8SsYxddvn6ncg.PET24mR--c4i5ukxAlcLoCnlJBssFLNujC8mqcP5kRYg.PNG.kwleepuppy/%EC%BA%A1%EC%B2%98.PNG?type=w773" width="90%"></img>
</div>
<div>
<img src="https://postfiles.pstatic.net/MjAxOTAyMTBfMjY4/MDAxNTQ5NzI5NDQ0MjQ2.XzJgyFphd9apGabg_clMyGJeb9aiXwWUZemkjZiRfkYg.VZEAxWr1EIUeo6XAVJsWBGx9pBKtYPrcciqExEAmc_wg.PNG.kwleepuppy/%EC%BA%A1%EC%B2%981.PNG?type=w773" width="90%"></img>
</div>
<div>
<img src="https://postfiles.pstatic.net/MjAxOTAyMTBfMTgy/MDAxNTQ5NzI5NDQ0NDYw.s4WDUFZwKfVsPhCjvpXhtXbWli6nbffCw_zwSZ-JnGUg.VOhPr307BUM-nsbdUlIgy9RXRbnRIonuMkGx0W8JDHIg.PNG.kwleepuppy/%EC%BA%A1%EC%B2%982.PNG?type=w773" width="90%"></img>
</div>
먼저 1.exe의 .code 섹션으로 들어갑니다.
<div>
<img src="https://postfiles.pstatic.net/MjAxOTAyMTBfMjQ4/MDAxNTQ5NzI5NDQ0MzI2.wPt4FMyN7k01Yj3ILJpEey6tcAvbaAZJsK6mREm9x7Eg.xGoEXmpDMNnotKHY6yV0XolV1JAsCeAPpJSSVXksAKIg.PNG.kwleepuppy/%EC%BA%A1%EC%B2%983.PNG?type=w773" width="90%"></img>
</div>
비교부분에 breakpoint를 걸어두고

실행
<div>
<img src="https://postfiles.pstatic.net/MjAxOTAyMTBfMjkw/MDAxNTQ5NzI5NDQ0NDkx.26zRS6perobWzAaEzB--xDw8GbDo_dRD5z-N6ZwxKksg.Xb57TRDg5s8W1tKkTUkAKeF_0CB-dVJ3Rjw4tB3fcK0g.PNG.kwleepuppy/%EC%BA%A1%EC%B2%984.PNG?type=w773" width="90%"></img>
</div>
비교부분만 살짝 바꿔주는 형태로

패치하여
<div>
<img src="https://postfiles.pstatic.net/MjAxOTAyMTBfMTMy/MDAxNTQ5NzI5NDQ0NTIy.UwYAryJRSzOEjwxeZvpNZv8833wN27Vi6KzyxYVownog.Y2a_jU5GQqRmqZLCs2-3McHty3MqBxka_rZILGisFFkg.PNG.kwleepuppy/%EC%BA%A1%EC%B2%985.PNG?type=w773" width="90%"></img>
</div>
<div>
<img src="https://postfiles.pstatic.net/MjAxOTAyMTBfMTk1/MDAxNTQ5NzI5NDQ0ODE2.QonlEysARGWNeKJOVabixJe5coE1I81KPDDVxHYibH4g.H1Yp880LnAJe58BsiUm0qhCczFV_8apUH2Z7gWp2VL8g.PNG.kwleepuppy/%EC%BA%A1%EC%B2%986.PNG?type=w773" width="90%"></img>
</div>
<div>
<img src="https://postfiles.pstatic.net/MjAxOTAyMTBfMjcg/MDAxNTQ5NzI5ODc5NDcw.t5D5amQeZtL6KaIOpIHLdg0N1PZ76vm-04DhcX4dgL0g.1yhyA6GodhgjtNUsE6H7-oAZL5wVJ9yeG1endYyYddog.PNG.kwleepuppy/image.png?type=w773" width="90%"></img>
</div>
처음에 뭘 답으로 입력해야하나 헤매었다.

문제를 다시읽어보니 답이..

