# Challenge 2. checksec으로 보호 기법 확인

## 1. checksec 결과 비교

### week9_1 (-fno-stack-protector)

```text
RELRO           STACK CANARY      NX            PIE             RPATH      RUNPATH      Symbols         FORTIFY Fortified       Fortifiable     FILE
Partial RELRO   No canary found   NX enabled    No PIE          No RPATH   No RUNPATH   37 Symbols        No    0               1               ./week9_1
```

### week9_1_canary (-fstack-protector)

```text
RELRO           STACK CANARY      NX            PIE             RPATH      RUNPATH      Symbols         FORTIFY Fortified       Fortifiable     FILE
Partial RELRO   Canary found      NX enabled    No PIE          No RPATH   No RUNPATH   38 Symbols        No    0               1               ./week9_1_canary
```

`-fstack-protector` 옵션을 사용한 경우 Stack Canary가 활성화된 것을 확인할 수 있다. 반면 `-fno-stack-protector`를 사용한 경우에는 Canary가 존재하지 않았다.

---

## 2. Stack Canary 비교

Stack Canary는 버퍼 오버플로우 공격을 탐지하기 위한 보호 기법이다. 함수가 실행될 때 return address 앞에 특별한 값을 저장해 두고, 함수가 종료될 때 해당 값이 변경되었는지 검사한다.

`-fno-stack-protector`를 사용한 경우에는 Canary가 존재하지 않아 버퍼 오버플로우를 통해 return address를 덮어쓸 수 있다.

반면 `-fstack-protector`를 사용한 경우에는 Canary가 활성화되어 버퍼 오버플로우 발생 시 프로그램이 종료되므로 공격을 방지할 수 있다.

---

## 3. checksec으로 확인할 수 있는 정보

* **RELRO** : GOT 영역 보호 여부
* **STACK CANARY** : 스택 버퍼 오버플로우 탐지 기능
* **NX (Non-Executable)** : 스택 영역에서 코드 실행 방지
* **PIE (Position Independent Executable)** : 실행 시마다 프로그램 주소 변경 여부
* **RPATH / RUNPATH** : 라이브러리 탐색 경로 정보
* **FORTIFY** : 위험한 함수 사용 시 추가 보안 검사 여부

checksec을 이용하면 프로그램에 적용된 주요 보안 보호 기법을 한 번에 확인할 수 있다.

