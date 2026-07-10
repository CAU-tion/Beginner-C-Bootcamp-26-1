# [Week07] 동적 할당과 메모리 취약점 보고서

## Challenge 1. malloc / free 기초 실습
- **Heap 영역 확인:** 출력된 주소값이 스택 영역(0x7ffffff...)에 비해 확연히 낮은 주소대(0x55... 등)에 위치함을 확인하여 힙 영역임을 검증함.
- **malloc() 실패 시 처리:** 메모리 고갈 시 `NULL`이 반환되며, 이를 검증하지 않고 참조하면 Null Pointer Dereference 취약점으로 인해 크래시(Segmentation Fault)가 발생함.
- **Memory Leak의 위험성:** `free()`를 누락하면 프로세스가 종료될 때까지 메모리가 반환되지 않고 낭비됨. 장시간 실행되는 프로세스에서 누적이 발생하면 시스템이 프로세스를 강제 종료(OOM Killer)하는 치명적인 문제가 발생함.

## Challenge 2. Dangling Pointer 실험
- **실행 결과 관찰:** `free()` 이후에도 포인터가 기존 주소를 가리키고 있어(Dangling Pointer), 크래시 없이 값이 정상적으로 읽히고 수정되는 현상을 관찰함.
- **위험성 및 UAF 연결 고리:** 시스템은 해제된 메모리를 다른 `malloc` 요청 시 재할당할 수 있음. 이때 Dangling Pointer가 남아있으면 새로 할당된 다른 중요 구조체나 함수 포인터의 데이터를 조작할 수 있게 되어 치명적인 **Use After Free(UAF)** 취약점으로 이어짐.

## Challenge 3. Double Free Bug 실험
- **실행 결과 관찰:** 연달아 두 번 `free()`를 호출했을 때, `double free detected` 에러와 함께 프로그램이 강제 종료됨. 이는 현대 glibc의 tcache hardening 보호 기법에 의해 탐지된 결과임.
- **보안 취약점 연결 원리:** 보호 기법이 없거나 우회될 경우, 동일한 청크 주소가 빈 청크 리스트(Bin)에 중복 등록되어 순환 참조(`A -> A -> A`)가 발생함. 이후 `malloc`을 통해 해당 영역을 할당받을 때 다음 프리 청크 포인터(fd)를 공격자가 원하는 임의의 주소로 변조할 수 있으며, 최종적으로 **Arbitrary Write(임의 주소 쓰기)**가 가능해져 프로그램 흐름을 장악할 수 있음.
