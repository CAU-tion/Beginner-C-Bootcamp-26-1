Challenge-1

함수 사용 이유
    1. 코드 재사용성 (Reusability): encode 함수를 만들어놓으면, 굳이 똑같은 코드를 여러 번 복사/붙여넣기 할 필요 없이 필요할 때 이 함수를 호출하면 됨

    2. 가독성 (Readability): main 함수 안에 복잡한 코드를 지우고 print_banner();, shift = get_shift(); 처럼 함수 이름을 적어놓으면 프로그램의 흐름을 한눈에 파악 하기 좋음

    3. 유지보수 (Maintenance): 추후 암호화 로직 수정 시, 수정이 필요한 함수 내부로 찾아가면 되기에 유지보수 용이

Challenge-2

1. 정의

    - 스택 프레임이란 함수가 호출될 때, 해당 함수의 실행에 필요한 정보들을 저장하기 위해 스택(Stack) 영역에 할당되는
      메모리 블록으로 함수가 종료되면 공간 자동 해제

2. 구조

    - 함수가 실행되는 동안 필요한 식별자 역할로 아래 항목들이 순서대로 저장

        - 매개변수 (Parameters): 호출한 함수가 전달한 인자 값
        - 복귀 주소 (Return Address): 함수 종료 후 돌아가서 실행할 다음 명령어의 위치
        - 이전 프레임 포인터 (Saved RBP): 나를 호출한 이전 함수의 기준점(RBP) 주소
        - 지역 변수 (Local Variables): 함수 내부에서 선언된 변수들

3. 핵심 레지스터 (x86-64)

    - RBP (Base Pointer): 스택 프레임의 최하단(시작점)을 가리키며, 함수 내부 변수나 인자에 접근할 때 기준점이 됨

    - RSP (Stack Pointer): 스택 프레임의 최상단(끝점)을 가리키며, 데이터가 들어오고 나갈 때마다 수시로 변화

4. 함수 호출 시 process

    - 함수 호출 (Prologue):
        1. push rbp: 이전 함수 기준점 스택에 백업

        2. mov rbp, rsp: 현재 RSP를 새로운 RBP로 설정하여 새로운 스택 프레임 시작

    - 함수 종료 (Epilogue):
        1. leave: RSP를 RBP로 옮기고, 백업했던 이전 RBP 복원

        2. ret: 스택에 저장된 복귀 주소(Return Address)를 꺼내 원래 실행 흐름으로 복귀

5. 보안 및 디버깅 관점

    - Buffer Overflow: 지역 변수 공간을 넘치게 해 복귀 주소를 조작하여 공격자가 원하는 코드를 실행하게 만드는 공격

    - Call Stack 확인: 에러 발생 시 프로그램이 어떤 경로를 거쳐 현재 함수에 도달했는지 추적하는 근거

- GDB 디버깅 후 함수 호출 전후 비교

    함수 진입 후 프롤로그 과정을 통해 rbp를 스택에 보관하고, rbp 값을 rsp로 갱신하면서 encode 함수만의 스택 프레임이 형성되는 것 확인 
    
    이 지점을 기준으로 함수 내 지역 변수와 연산이 rbp를 중심으로 하는 상대적 주소로 관리

- 관찰 결과
    1. main 함수 진입 및 초기 상태

        main 함수 시작점에 브레이크포인트를 걸고 실행했을 때 상태

        RBP: 0x7fffffffe100 (함수 기준 주소)
        RSP: 0x7fffffffe080 (스택 최상단 주소)

        main 함수가 실행 중이며, 아직 함수 호출 전 독자적인 스택 프레임을 유지

    2. encode 함수 호출 및 스택 프레임 생성

        main에서 encode 함수를 호출하고, 함수의 프롤로그 과정이 완료된 직후 상태

        RBP: 0x7fffffffe070 (갱신됨)
        RSP: 0x7fffffffe070 (갱신됨)

        Return Address: call 명령어가 실행되며 main으로 돌아갈 주소가 스택에 push -> RSP 주소 감소 확인

        Saved RBP: encode 진입 직후 push rbp를 통해 이전 함수인 main의 RBP 값을 스택에 백업

        Frame Pointer 이동: mov rbp, rsp를 통해 RBP가 현재 RSP 위치로 이동하며 encode 함수의 새로운 스택 프레임 기준점 설정

    3. finish 실행 후 스택 프레임 복원

        finish 명령어를 사용하여 encode 함수를 종료하고 leave와 ret 명령어를 거쳐 main으로 복귀한 상태

        RBP: 0x7fffffffe100 (복원 완료)
        RSP: 0x7fffffffe080 (복원 완료)

        leave: 현재 프레임을 해제하고 스택에 저장되어 있던 이전 RBP 값을 꺼내 레지스터에 복원

        ret: 스택에 있던 Return Address를 꺼내 RIP에 입력해 main 함수의 다음 실행 지점으로 점프