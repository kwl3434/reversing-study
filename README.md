# reversing-study

리버싱 핵심원리 책 & visual studio 2017 & ollydbg를 이용한 리버싱 공부
1. ollydbg설치하기
2. IA-32 레지스터 분석
3. ESP EBP 개념 정리
3. 스택프레임 따라가기
4. PE 분석
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
