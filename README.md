# AurixTutorial

## Purpose & Scope

지능형 모형차 대회에 사용할 수 있는 Software Platform 을 제공하는 것을 목적으로 합니다.

특히 다음 사항을 고려하였습니다.

- Infineon AURIX 활용 방법 소개
- 학부생 수준에서 이해하고 활용할 수 있는 코드
- 특별한 하드웨어와 소프트웨어 도구를 사용하지 않음

Software Platform을 분석하면서 자연스럽게 Infineon AURIX를 이해하고,
마이크로컨트롤러 개발자로 성장할 수 있는 첫 걸음이 되도록 구성하였습니다.

## Links

- [Github](https://github.com/realsosy/InfineonRacer): 문서와 프로그램 소스
- [ReadTheDocs](http://infineonracer.readthedocs.io/ko/latest/) : 메뉴얼 스타일로 열람

**[NOTE]**

- /src에 있는 프로젝트들은 다운로드 받으셔서 사용하셔도 됩니다. 사소한 오류는 있을 것으로 예상됩니다만 참고용으로 사용할 수 있을 수준의 코드입니다.
- /docs와 /references에 있는 파일들은 인터넷을 사용하여 접근하시기 바랍니다. 
- 각 문서들은 상태에 따라서 (작성중), (수정중) 이라는 표시를 하여 참고하시는 분들의 불편을 최소화하도록 하겠습니다.
- (작성중) 표시가 없는 챕터들은 [ReadTheDocs](http://infineonracer.readthedocs.io/ko/latest/)에서 좀 더 편하게 보실 수 있습니다.



### Definitions, Terminology and Abbreviations

| Abbreviations | Descriptions                                                 |
| ------------- | ------------------------------------------------------------ |
| iLLD          | Infineon Low-Level Driver                                    |
| BIFACES       | Build and Integration Framework for Automotive Controller Embedded Software |

## What we need

- **Application Kit TC2X7 V1.0**; Evaluation board
- **DC Motor Control Kit**; Infineon Released
- [**HighTec Free TriCore™ Entry Tool Chain V4.9.1.0-infineon-1.1 (later)**](https://free-entry-toolchain.hightec-edv.com/index.php): Compiler & Debugger
- [**BIFACES_V1_0_0_Win32.zip**](https://drive.google.com/open?id=1tYg7DDeB-HNf8ZCV7toeD5UtMwiLin4A); Build and Integration Framework for Automotive Controller Embedded Software
- [**BaseProjects_AURIX1G_V1_0_1_2_0.zip**](https://drive.google.com/open?id=1Lz3eHBS7BILysJJKFyYaDNGYYkTbJ7jg); BIFACES Base Template Project
- [**iLLD_1_0_1_4_0_TC2xx_Release.zip**](https://drive.google.com/open?id=1c_0dBZk6qQFeWFwpmISwJcjg9llLFcN8); iLLD source and doc
- [**iLLD_Demos_1_0_1_4_0_TC2xx.zip**](https://drive.google.com/file/d/143MTFcHteeId-dcKe6ITDmq456WDAMXF/view?usp=sharing); iLLD examples



## ToC

### Dive into AURIX world using InfineonRacer

- AURIX, 마이크로컨트롤러를 심도있게 공부해 보고 싶으시다면 이 부분을 단계별로 학습하시기 바랍니다.
- **How to stduy AURIX** 부터 **Twinkle twinkle little start** 까지는 순서대로 보셔야 합니다.  그 이후는 독립적으로 구성되어 있어서 순서에 관계없이 관심있는 챕터를 보시면 됩니다.

1. [How to study AURIX?](./docs/HowToStudyAurix.md) MCU 학습 방법 제안
2. [How to use BIFACES? (작성중)](./docs/HowToUseBIFACES.md)  eclipse, make, doxygen, graphviz
3. [What is iLLD?](./docs/WhatIsIlld.md) PORT
4. [Do ma a favor?](./docs/DoMeAFavor.md) Config, Init, ISR in iLLD
5. [Twinkle twinkle little star](./docs/TwinkleTwinkleLittleStar.md)  STM
6. [Multiple infinite loops](./docs/MultipleInfiniteLoops.md) Static Cyclic Scheduler
7. [Hello world](./docs/HelloWorld.md)  ASC & Terminal
8. [My own terminal](./docs/MyOwnTerminal.md) Shell
9. [Multi channel voltmeter](./docs/MultiChannelVoltmeter.md)  Vadc Background Scan
10. [My own cheap oscilloscope](./docs/MyOwnCheapOscilloscope.md)  Vadc Auto Scan + Serial Plot
11. [Line Scan Camera](./docs/LineScanCamera.md) TSL1401
12. [Chronos ruler(수정중)](./docs/ChronosRuler.md) GtmTomTimer + Beeper, Servo
13. [Synchronized PWM(수정중)](./docs/SynchronizedPwm.md) GtmTomPwmHl + H-Bridge
14. [Where are you?(수정중)](./docs/WhereAreYou.md) Gpt12 + Encoder
15. [TFT as modern Man-Machine Interface(작성중)](./docs/TftAsModernMmi.md)
16. [Simulink as a programming language](./docs/SimulinkAsAProgrammingLanguage.md)

### etc

- [References](./docs/References.md)
- [Source code list](./src/README.md)

## Target Board 

- ApplicationKit_TC237
- ShieldBuddy_TC275D

