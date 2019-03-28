---
title: index.md
author: Wootaik Lee (wootaik@gmail.com)  
date: 2019-01-30
---

## Purpose & Scope

Infineon Aurix를 사용하여 중급 수준의 마이크로콘트롤러 활용 방법을 안내하고자 합니다.

*   중급 수준의 마이크로컨트롤러 개발 환경에 대한 소개
*   Infineon AURIX의 중요 서브 시스템에 대한 설명

Software Platform를 분석하면 자연스럽게 Infineon AURIX를 이해할 수 있도록 하고,
마이크로컨트롤러 전공자로서 성장해 나갈 수 있는 첫 걸음이 될 수 있도록 구성하였습니다.

### Links

* [AurixRacer Source Code](https://github.com/realsosy/AurixRacer)
* [AurixRacer Documentation](http://aurixracer.readthedocs.io/ko/latest/) 
* [AurixTutorial Source Code](https://github.com/realsosy/AurixTutorial)
* [AurixTutorial Documentation](http://aurixtutorial.readthedocs.io/ko/latest/) 
* [InfineonRacer Source Code](https://github.com/realsosy/InfineonRacer)
* [InfineonRacer Documentation](http://infineonracer.readthedocs.io/ko/latest/) 

**[NOTE]**

* /src 에 있는 프로젝트들은 다운로드 받으셔서 사용하셔도 됩니다.  사소한 오류는 있을 것으로 예상됩니다만 참고용으로 사용할 수 있을 수준의 코드입니다.
* /docs 와 /references 에 있는 파일들은 인터넷을 사용하여 접근하시기 바랍니다. 수시로 지속적인 변경이 발생할 수 있으므로 다운로드 받지 마시고 browser나 git 을 통해서 접근하시기를 바랍니다.
* [ReadTheDocs](http://aurixtutorial.readthedocs.io/ko/latest/)에서 좀 더 편하게 보실 수 있습니다.



### Definitions, Terminology and Abbreviations

| Abbreviations | Descriptions                                                 |
| ------------- | ------------------------------------------------------------ |
| iLLD          | Infineon Low-Level Driver                                    |
| BIFACES       | Build and Integration Framework for Automotive Controller Embedded Software |

## What we need
* [ShieldBuddy_TC275](http://www.hitex.co.uk/embedded-technology/hardware/boards-modules/embedded-modules-by-processor/hitex-shieldbuddy-tc275/) 또는  [ApplicationKit TC237](https://www.infineon.com/cms/en/product/evaluation-boards/kit_aurix_tc237_tft/): 조건부 컴파일로 활용 가능
* [DC Motor Control Shield with IFX007T](https://www.infineon.com/cms/en/product/evaluation-boards/bldc-shield_ifx007t/) 또는 **DC Motor Control Kit**(Infineon Released)
- [**HighTec Free TriCore™ Entry Tool Chain V4.9.1.0-infineon-2.0 (later)**](https://free-entry-toolchain.hightec-edv.com/index.php): Compiler & Debugger
- [**BIFACES_V1_0_2_Win32.exe**](https://drive.google.com/open?id=120INrMwqaR8812rFyFHspgbCLmoi7d-T) or [**BIFACES_V1_0_2_Win64.exe**](https://drive.google.com/open?id=1z80W66QcE_DNJBaRRdcr3tfRu9EoZ8Oz); Build and Integration Framework for Automotive Controller Embedded Software
- [**BaseProjects_AURIX1G_V1_0_1_7_0.exe**](https://drive.google.com/open?id=1r6FEn1KDHO1Owxte6-Np0ksMG87OZAOt); BIFACES Base Template Project
- [**iLLD_1_0_1_8_0_TC2xx_Drivers_And_Demos_Release.zip**](https://drive.google.com/open?id=1btQpCUwkJ2LFz2qOAHtoQZcMouD3Hd4C); iLLD source and iLLD examples



## ToC

### Dive into AURIX world 

* AURIX, 마이크로컨트롤러를 심도있게 공부해 보고 싶으시다면 이 부분을 단계별로 학습하시기 바랍니다.
* **How to stduy AURIX** 부터 **Twinkle twinkle little start** 까지는 순서대로 보셔야 합니다.  그 이후는 독립적으로 구성되어 있어서 순서에 관계없이 관심있는 챕터를 보시면 됩니다.

1.  [How to study AURIX?](./HowToStudyAurix.md) MCU 학습 방법 제안
3.  [What is iLLD?](./WhatIsIlld.md) PORT
4.  [Do ma a favor?](./DoMeAFavor.md) Config, Init, ISR in iLLD
5.  [Twinkle twinkle little star](./TwinkleTwinkleLittleStar.md)  STM
6.  [Multiple infinite loops](./MultipleInfiniteLoops.md) Static Cyclic Scheduler
7.  [Hello world](./HelloWorld.md)  ASC & Terminal
8.  [My own terminal](./MyOwnTerminal.md) Shell
9.  [Multi channel voltmeter](./MultiChannelVoltmeter.md)  Vadc Background Scan
10.  [My own cheap oscilloscope](./MyOwnCheapOscilloscope.md)  Vadc Auto Scan + Serial Plot
11.  [Line Scan Camera](./LineScanCamera.md) TSL1401
12.  [Chronos ruler](./ChronosRuler.md) GtmTomTimer + Beeper, Servo
13.  [Synchronized PWM](./SynchronizedPwm.md) GtmTomPwmHl + H-Bridge
14.  [Where are you?](./WhereAreYou.md) Gpt12 + Encoder
15.  [TFT as modern Man-Machine Interface(AK_TC23A Only)](./TftAsModernMmi.md)



### etc

* [References](./References.md)
* [Source code list](./src/README.md)

