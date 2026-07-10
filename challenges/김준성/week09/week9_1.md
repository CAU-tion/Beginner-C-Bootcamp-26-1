## 1. offset 계산

gdb를 이용하여 `buf`의 시작 주소와 return address가 저장된 위치를 확인했다.

```gdb
(gdb) p &buf
$2 = (char (*)[16]) 0x7fffffffdfe0

(gdb) info frame
...
rip at 0x7fffffffdff8
```

`buf`의 시작 주소는 `0x7fffffffdfe0`, return address가 저장된 위치는 `0x7fffffffdff8`이다.

따라서 offset은 다음과 같이 계산했다.

```text
0x7fffffffdff8 - 0x7fffffffdfe0
= 0x18
= 24 bytes
```

즉, return address를 덮어쓰기 위해서는 24바이트를 먼저 채워야 한다.

---

## 2. secret() 주소 확인

gdb에서 다음 명령어를 사용하여 `secret()` 함수의 주소를 확인했다.

```gdb
(gdb) p secret
$3 = {void ()} 0x401156 <secret>
```

확인 결과 `secret()` 함수의 주소는 `0x401156`이다. 이 주소를 return address 위치에 덮어써서 함수가 종료된 후 `secret()` 함수가 실행되도록 함.

---

## 3. Little Endian이란?

Little Endian은 데이터를 저장할 때 가장 낮은 바이트(LSB)를 먼저 저장하는 방식이다.

예를 들어 `secret()` 함수의 주소가 `0x401156`이라면 사람이 읽는 순서는 `40 11 56`이지만, 메모리에는 `56 11 40` 순서로 저장된다.

따라서 return address를 덮어쓸 때 주소를 그대로 입력하는 것이 아니라 Little Endian 형식으로 바이트 순서를 뒤집어서 입력해야 한다. 주소를 뒤집지 않으면 CPU가 전혀 다른 주소로 해석하므로 원하는 함수로 실행 흐름을 변경할 수 없다.

