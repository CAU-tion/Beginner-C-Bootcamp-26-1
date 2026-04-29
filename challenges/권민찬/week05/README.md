Challenge-1

info proc mappings 명령어를 통해 확인한 memory map과 printf를 통해 출력한 걍 memory layout 별 변수들의 저장 주소를 보면,
Datam, BSS, Stack, Heap, Text 영역 범위 사이에 값 변수들의 주소 값이 올바르게 들어가있는 것을 확인할 수 있다.

Challenge-2

16byte를 초과하지 않는 정상 입력이 들어오면 문제 없이 실행이 종료된다.
그러나 16byte를 초과하는 입력값이 들어올 시 Stack Canary가 적용되어있는 경우 stack smashing detected라는 출력과 함께 실행이 종료되고,
Stack Canary 적용을 해제한 후 다시 실행 시 Segmentation tault가 발생하게 된다.

이 후 buf와 ret address의 위치를 확인 후 ret address를 실제로 확인하게 되면, 
16byte를 초과했던 입력값으로 ret addressd의 값이 덮어씌어져 있는 것을 확인할 수 있다.

gets() 이외에도 scanf(), strcpy(), strcat() 등 다양한 함수에서 버퍼오버플로우 문제가 발생할 수 있다.
따라서 현재에는 버퍼오버플로우를 막기위해 길이를 검사하는 n이 포함된 안전한 함수(strncpy, snprintf 등)의 사용을 권장하고 있다.