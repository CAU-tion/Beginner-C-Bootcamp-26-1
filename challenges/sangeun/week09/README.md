# 9주차 버퍼 오버플로우 실습 보고서

### Challenge 1 정리
1. offset을 어떻게 계산했는지: gdb에서 disassemble vuln 실행 후 [rbp-0x10]을 확인하여 buf(16바이트) + SFP(8바이트) = 24바이트로 계산했습니다.
2. secret() 주소를 어떻게 확인했는지: gdb에서 p secret 명령어로 0x401156 주소를 확인했습니다.
3. little endian이 무엇인지: 숫자의 하위 바이트부터 거꾸로 저장하는 방식으로, 주소가 제대로 인식되게 하려면 바이트 순서를 뒤집어서 입력해야 합니다.

### Challenge 2 정리
- 기본 컴파일(vuln_protected)을 하면 Stack Canary와 PIE 보호 기법이 켜지지만, 옵션을 주면(vuln) 보호 기법들이 꺼져서 오버플로우 공격이 가능해집니다.# 9주차 버퍼 오버플로우 실습 보고서

